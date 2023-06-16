#ifndef IDENTIFIABLE_HPP
#define IDENTIFIABLE_HPP
#include <string>

class Identifiable {
    virtual std::string getType() = 0;  // Wirtualna metoda zwracająca typ obiektu
};
#endif