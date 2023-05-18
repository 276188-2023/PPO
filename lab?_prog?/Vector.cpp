#include "Vector.hpp"

void PersonVector::addPerson(Person* person)
{
    personVector.push_back(person);
}

int PersonVector::getPersonCount()
{
    return personVector.size();
}

int PersonVector::getStudentCount()
{
    int studentCount = 0;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getType() == "Student")
        {
            studentCount++;
        }
    }
    return studentCount;
}

int PersonVector::getEmployeeCount()
{
    int employeeCount = 0;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getType() == "Employee")
        {
            employeeCount++;
        }
    }
    return employeeCount;
}



void PersonVector::printAll()
{
    for (int i = 0; i < personVector.size(); i++)
    {
        std::cout << personVector[i]->toString() << std::endl;
    }
}

void PersonVector::saveToFile()
{
    std::ofstream file;
    file.open("persons.txt");
    for (int i = 0; i < personVector.size(); i++)
    {
        file << personVector[i]->toString() << std::endl;
    }
    file.close();
}
