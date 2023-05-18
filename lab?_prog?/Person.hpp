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
    std::string name;
    std::string surname;
    std::string pesel;
    std::string type;
    std::string id;
    int age;

    int checkPesel(std::string pesel);

    void setAge(std::string pesel);

public:

    std::string getName();

    std::string getSurname();

    std::string getPesel();

    int getAge();

    void setName(std::string name);

    void setSurname(std::string surname);

    int setPesel(std::string pesel);

   virtual std::string getType();

    virtual std::string getId();

    virtual std::string toString();
};
#endif