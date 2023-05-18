#include <iostream>
#include "Person.hpp"
#include "Identifiable.hpp"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PersonVector
{
    private:
        vector<Person*> personVector;
    public:

        void addPerson(Person* person);

        int getPersonCount();

        int getStudentCount();

        int getEmployeeCount();

        void saveToFile();

        void printAll();


};
