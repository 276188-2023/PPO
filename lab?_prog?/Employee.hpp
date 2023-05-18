#include "Person.hpp"

class Employee : public Person, public Identifiable
{
private:
    std ::string cardNumber;
    std::string position;   
    std::string type = "Employee";
    std::string id = cardNumber;

public:

    std::string getCardNumber();

    void setCardNumber(std::string cardNumber);

    std::string getPosition();

    void setPosition(std::string position);

    std::string getType();

    std::string toString();
};