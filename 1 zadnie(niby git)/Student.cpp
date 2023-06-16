#include <iostream>
#include "Student.hpp"

std::string Student::getIndex()
{
    return index;
}

void Student::setIndex(std::string index)
{
    this-> index = index;
}

std::string Student::getType()
{
    return "Student";
}

std::string Student::toString()
{
    return "Student: Name=" + getName() + ",Surname=" + getSurname() + ",Pesel=" + getPesel()  + ",Age=" + std::to_string(getAge())  + ",Index=" + getIndex();
}