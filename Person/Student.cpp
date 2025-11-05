#include "Student.h"

Student::Student(std::string name) : name(std::move(name)) {}

badge::PERSON_TYPE Student::getType() const {
    return badge::PERSON_TYPE::STUDENT;
}

std::string_view Student::getName() const {
    return name;
}
