#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Identifiable.hpp"

using namespace std;

class Person
{
private:
    string name;
    string surname;
    string pesel;
    string type;
    int age;

    int checkPesel(string pesel);

    void setAge(string pesel);

public:

    string getName();

    string getSurname();

    string getPesel();

    int getAge();

    void setName(string name);

    void setSurname(string surname);

    int setPesel(string pesel);

    virtual std::string getType();

    virtual string toString();
};
#endif