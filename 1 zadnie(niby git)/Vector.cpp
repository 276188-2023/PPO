#include "Vector.hpp"

void PersonVector::addPerson(Person* person)
{
    personVector.push_back(person);
}

int PersonVector::getPersonCount()
{
    return personVector.size();
}

int PersonVector::getStudentCount()     //Jeśli typ osoby to "Student" to zwiększa liczbe studentów
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

int PersonVector::getEmployeeCount()    //Jeśli typ osoby to "Employee" to zwiększa liczbe studentów
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



void PersonVector::printAll()   // Wyświetla informacje o osobie
{
    for (int i = 0; i < personVector.size(); i++)
    {
        std::cout << personVector[i]->toString() << std::endl;
    }
}

void PersonVector::saveToFile()     // Zapisywanie informacji o osobie do pliku
{
    std::ofstream file;
    file.open("persons.txt");
    for (int i = 0; i < personVector.size(); i++)
    {
        file << personVector[i]->toString() << std::endl;
    }
    file.close();
}
