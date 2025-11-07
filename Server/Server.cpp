#include <utility>
#include <fstream>
#include <vector>
#include <sstream>

#include "../Time/timeLib.h"

#include "../Person/Student.h"
#include "../Person/Teacher.h"
#include "../Person/Doctor.h"
#include "../Person/CleanupStaff.h"
#include "../Person/Staff.h"

#include "../Badge/Badge.h"

#include "../Reader/RoomReader.h"
#include "../Reader/TeacherReader.h"
#include "../Reader/LabReader.h"
#include "../Reader/CleanupReader.h"
#include "../Reader/StaffReader.h"

#include "Server.h"

Server::Server(): Server("Default") {
}

Server::Server(std::string n): name(std::move(n)), running(false), errorId(badge::SERVER_QUERY_ERROR::ERR_NONE), bufferId{-1, -1} {
}

Server::~Server() {
    stop();
}

bool Server::queryAccess(const unsigned int badgeID, const unsigned int readerID) {
    bufferId[0] = badgeID;
    bufferId[1] = readerID;

    if (badges.find(badgeID) == badges.end()) {
        errorId = badge::SERVER_QUERY_ERROR::ERR_UNK_BADGE;
        return false;
    }

    if (readers.find(readerID) == readers.end()) {
        errorId = badge::SERVER_QUERY_ERROR::ERR_UNK_READER;
        return false;
    }

    std::shared_ptr<IBadge> badge = badges.at(badgeID);
    std::shared_ptr<IReader> reader = readers.at(readerID);
    std::shared_ptr<IPerson> person = badge->getOwner();

    if (!reader->isEnabled()) {
        errorId = badge::SERVER_QUERY_ERROR::ERR_READER_DISABLED;
        return false;
    }

    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();

    if (currentTime >= badge->getDate()) {
        errorId = badge::SERVER_QUERY_ERROR::ERR_EXPIRED_DATE;
        return false;
    }

    if (person->getType() < reader->getType() && !badge->hasPermission(readerID)) {
        errorId = badge::SERVER_QUERY_ERROR::ERR_CLEARANCE;
        return false;
    }

    // The following is commented out for this uses Real Time,
    // and so it would always return false if this program is ran
    // during the night for instance.

    /*TimeSlot& readerTime = reader->getAccessTimeSlot();

    if (!readerTime.contains(currentTime)) {
        errorId = badge::ERR_READER_TIME;
        return false;
    }*/

    return true;
}

bool Server::queryAccess(const IBadge &badge, const IReader &reader) {
    return queryAccess(badge.getId(), reader.getId());
}

const std::string& Server::getName() const {
    return name;
}

bool Server::isRunning() const {
    return running;
}

badge::SERVER_QUERY_ERROR Server::getErrorId() const {
    return errorId;
}

std::map<unsigned int, std::shared_ptr<IReader>>& Server::getReaders() {
    return readers;
}

std::map<unsigned int, std::shared_ptr<IBadge>>& Server::getBadges() {
    return badges;
}

void Server::start() {
    std::ifstream configFile;
    configFile.open("s_" + name + ".txt");

    if (!configFile.is_open()) {
        throw std::runtime_error("Could not open file s_" + name + ".txt");
    }

    bool con = false;
    std::string line;

    while (std::getline(configFile, line)) {
        if (line == ";") {
            con = true;
            continue;
        }

        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> tokens;

        while (std::getline(ss, word, ';')) {
            tokens.push_back(word);
        }

        if (con) { // Set the readers up
            if (tokens.size() != 6) {
                throw std::runtime_error("Wrong config file");
            }

            std::string readerName = tokens.at(0);
            auto readerLevel = static_cast<badge::CLEARANCE_LEVEL>(std::stol(tokens.at(1)));
            unsigned int readerId = std::stoul(tokens.at(2));
            bool readerEnabled = std::stol(tokens.at(3));
            std::string readerStart = tokens.at(4);
            std::string readerEnd = tokens.at(5);

            std::shared_ptr<IReader> reader;
            switch (readerLevel) {
                case badge::CLEARANCE_LEVEL::STUDENT:
                    reader = std::make_shared<RoomReader>(readerId, readerName, readerStart, readerEnd);
                    break;
                case badge::CLEARANCE_LEVEL::TEACHER:
                    reader = std::make_shared<TeacherReader>(readerId, readerName, readerStart, readerEnd);
                    break;
                case badge::CLEARANCE_LEVEL::DOCTOR:
                    reader = std::make_shared<LabReader>(readerId, readerName, readerStart, readerEnd);
                    break;
                case badge::CLEARANCE_LEVEL::CLEANUP:
                    reader = std::make_shared<CleanupReader>(readerId, readerName, readerStart, readerEnd);
                    break;
                case badge::CLEARANCE_LEVEL::STAFF:
                    reader = std::make_shared<StaffReader>(readerId, readerName, readerStart, readerEnd);
                    break;
                default:
                    throw std::out_of_range("Unknown reader type!");
            }

            if (readerEnabled) {
                reader->enable();
            }

            readers.insert({readerId, reader});
        } else { // Set the badges up
            if (tokens.size() < 4) {
                throw std::runtime_error("Wrong config file");
            }

            std::string personName = tokens.at(0);
            auto personLevel = static_cast<badge::CLEARANCE_LEVEL>(std::stol(tokens.at(1)));
            unsigned int badgeId = std::stoul(tokens.at(2));
            std::chrono::system_clock::time_point badgeDate = parseDateTime(tokens.at(3));

            std::shared_ptr<IPerson> person;
            switch (personLevel) {
                case badge::CLEARANCE_LEVEL::STUDENT:
                    person = std::make_shared<Student>(personName);
                    break;
                case badge::CLEARANCE_LEVEL::TEACHER:
                    person = std::make_shared<Teacher>(personName);
                    break;
                case badge::CLEARANCE_LEVEL::DOCTOR:
                    person = std::make_shared<Doctor>(personName);
                    break;
                case badge::CLEARANCE_LEVEL::CLEANUP:
                    person = std::make_shared<CleanupStaff>(personName);
                    break;
                case badge::CLEARANCE_LEVEL::STAFF:
                    person = std::make_shared<Staff>(personName);
                    break;
                default:
                    throw std::out_of_range("Unknown badge type!");
            }

            auto badge = std::make_shared<Badge>(badgeId, person);
            badge->setDate(badgeDate);

            for (auto it = tokens.begin() + 4; it != tokens.end(); ++it) {
                unsigned int permId = std::stoul(*it);
                badge->addPermission(permId);
            }

            badges.insert({badgeId, badge});
        }
    }
    configFile.close();

    // Check here if badges and readers are empty, if one is raise an error
    if (badges.empty() || readers.empty()) {
        throw std::runtime_error("Wrong config file!");
    }

    running = true;
}

void Server::stop() {
    readers.clear();
    badges.clear();
    clearError();

    running = false;
}

void Server::clearError(){
    bufferId[0] = -1;
    bufferId[1] = -1;
    errorId = badge::SERVER_QUERY_ERROR::ERR_NONE;
}
