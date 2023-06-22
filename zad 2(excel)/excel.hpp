#ifndef EXCEL_HPP
#define EXCEL_HPP

#include <iostream>
#include <vector>
#include <string>

enum direction { x = 1, y = 1, lev = 0 }; // Wyliczenie kierunków (x, y, lev)

class Komorka 
{
public:
    std::string zawartosc; // Zawartość komórki
    Komorka() { zawartosc = ""; }; // Konstruktor domyślny
    virtual ~Komorka() {}; // Destruktor wirtualny
};

class Excel 
{
private:
    using db = std::vector<std::vector<Komorka*>>;

    db excelVector; // Wektor przechowujący komórki

public:
    void expand(int x, int y); // Metoda rozszerzająca arkusz o podane wymiary
    std::string show_cell(int x, int y); // Metoda zwracająca zawartość komórki o podanych koordynatach
    void set_cell(int x, int y, std::string to_set); // Metoda ustawiająca zawartość komórki o podanych koordynatach
    void clear_cell(int x, int y); // Metoda czyszcząca zawartość komórki o podanych koordynatach
    void destroy(); // Metoda usuwająca wszystkie komórki z arkusza
    int sum_komorki(direction d, int t, int s, int f); // Metoda sumująca wartości komórek w podanym zakresie
    Excel(int x, int y); // Konstruktor arkusza o podanych wymiarach
};

std::istream& operator>>(std::istream& is, direction& d); // Przeciążenie operatora >> dla wyliczenia direction

#endif
