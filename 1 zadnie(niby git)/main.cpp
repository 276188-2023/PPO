#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Employee.hpp"
#include "Vector.hpp"

using namespace std;

PersonVector people;

void StudentMenu()  // Wyświetlenie menu dla studenta
{
    cout << endl << "_STUDENT MENU_" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Get number of students" << endl;
}

void EmployeeMenu()    // Wyświetlenie menu dla pracownika
{
    cout << endl << "_EMPLOYEE MENU_" << endl;
    cout << "1. Add employee" << endl;
    cout << "2. Get number of employees" << endl;
}

Person* addStudent()
{
    Student* s = new Student();
    cout << "Name: ";
    string name;
    cin >> name;
    s->setName(name);
    cout << "Surname: ";
    string surname;
    cin >> surname;
    s->setSurname(surname);
    cout << "Pesel: ";
    string pesel;
    cin >> pesel;
    int err = s->setPesel(pesel); //Тут також якась срака, поправ!!!
    if (err == 1)
    {
        return s;
    }
    else if (err == 2)
    {
        cout << "Pesel already exists" << endl;
        return s;
    }
    cout << "Index: ";
    string index;
    cin >> index;
    s->setIndex(index);
    return s;
}

Person* addEmployee()
{
    Employee* e = new Employee();
    cout << "Name: ";
    string name;
    cin >> name;
    e->setName(name);
    cout << "Surname: ";
    string surname;
    cin >> surname;
    e->setSurname(surname);
    cout << "Pesel: ";
    string pesel;
    cin >> pesel;
    int temp = e->setPesel(pesel);
    if (temp == 1)
    {
        return e;
    }
    else if (temp == 2)
    {
        cout << "Pesel already exists" << endl;
        return e;
    }
    cout << "Card number: ";
    string cardNumber;
    cin >> cardNumber;
    e->setCardNumber(cardNumber);
    return e;
}

int main()
{
    bool exit = false;
    while (!exit)
    {
        cout << endl << "_MENU_" << endl;       // Wyświetlenie głównego menu
        cout << "1. Students" << endl;
        cout << "2. Employees" << endl;
        cout << "3. Save to file" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        Person* p;
        switch (choice)
        {
            case 1:
                StudentMenu();
                cout << "Choice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                    {
                        p = addStudent();
                        people.addPerson(p);
                        people.printAll();
                        break;
                    }
                    case 2:
                    {
                        cout << "Number of students: " << people.getStudentCount() << endl;
                        /*серий глян чому воно записує все і зроби щоб записувалося тік норм резултати*/
                        people.printAll();
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice" << endl;
                        break;
                    }
                }
                break;
            case 2:
                EmployeeMenu();
                cout << "Choice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                    {
                        p = addEmployee();
                        people.addPerson(p);
                        people.printAll();
                        break;
                    }
                    case 2:
                    {
                        cout << "Number of employees: " << people.getEmployeeCount() << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice" << endl;
                        break;
                    }
                }
                break;
            case 3:
                people.saveToFile();
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
