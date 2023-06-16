#include "Person.hpp"

class Employee : public Person, public Identifiable
{
private:
    std ::string cardNumber;    // Numer karty pracownika 
    std::string type = "Employee";  // Typ obiektu jako "Employee"

public:

    std::string getCardNumber();    // Metoda zwracająca numer karty pracownika

    void setCardNumber(std::string cardNumber);      // Metoda ustawiająca numer karty pracownika

    std::string getType() override;     // Metoda zwracająca typ obiektu 

    std::string toString();     // Metoda zwracająca reprezentację obiektu Employee jako string
};