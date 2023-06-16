#include <iostream>
#include "Person.hpp"

int Person::checkPesel(std::string pesel)
{
    if (pesel.length() != 11)
        return 1;   // nieprawidłowa długość numeru PESEL
    for (int i = 0; i < 11; i++)
    {
        if (pesel[i] < '0' || pesel[i] > '9')
            return 2;   // numer PESEL zawiera niedozwolone znaki
    }
    return 0;   //PESEL jest git
};

void Person::setAge(std::string pesel)      // Ustawienie wieku na podstawie numeru PESEL
{
    std::string rokStr = pesel.substr(0, 2);
    int rok = stoi(rokStr);
    int wiek = 0;
    int pierwszaCyfra = pesel[2] - '0';
    if (pierwszaCyfra >= 0 && pierwszaCyfra <= 1) {
        wiek = 1900 + rok;
    } else {
        wiek = 2000 + rok;
    }
    wiek = 2023-wiek;
    this->age = wiek;
}

std::string Person::getName()
{
    return name;
}

std::string Person::getSurname()
{
    return surname;
}

std::string Person::getPesel()
{
    return pesel;
}

int Person::getAge()
{
    return age;
}

void Person::setName(std::string name)
{
    this->name = name;
}

void Person::setSurname(std::string surname)
{
    this->surname = surname;
}

int Person::setPesel(std::string pesel)
{
    int check = checkPesel(pesel);
    if (check == 0)
    {
        this->pesel = pesel;    // Ustawia numer PESEL osoby
        setAge(pesel);
    } 
    else
    {
        std::cout << "Wrong pesel" << std::endl;    //nieprawidłowy numer PESEL
    }
    return check;   // Zwraca wynik sprawdzania numeru PESEL
}

std::string Person::getType()
{
    return type;
}

std::string Person::toString()
{
    return "Person: Name=" + name + ",Surname=" + surname + ",Pesel=" + pesel + ",Age=" + std::to_string(age);
}