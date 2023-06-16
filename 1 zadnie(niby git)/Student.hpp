#include "Person.hpp"

class Student : public Person, public Identifiable
{
private:
    std::string index;
    std::string type = "Student";
    std::string id = index;

public:
    std::string getIndex();

    void setIndex(std::string index);

    std::string getType() override;

    std::string toString();
};