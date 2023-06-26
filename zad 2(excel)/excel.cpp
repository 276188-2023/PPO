#include "excel.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void Excel::expand(int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        vector<Komorka*> v;
        for (int j = 0; j <= y; j++)
        {
            v.push_back(new KomorkaTekstowa);
        }
        excelVector.push_back(v);
    }
}

string Excel::show_cell(int x, int y)
{
    return excelVector[x][y]->getZawartosc();
}

void Excel::set_cell(int x, int y, const string& to_set)
{
    excelVector[x][y]->setZawartosc(to_set);
}

void Excel::clear_cell(int x, int y)
{
    excelVector[x][y]->setZawartosc("");
}

void Excel::destroy()
{
    for (vector<Komorka*> v : excelVector)
    {
        for (Komorka* k : v)
        {
            delete k;
        }
    }
}

int Excel::sum_komorki(direction d, int t, int s, int f)
{
    int sum = 0;
    if (d == direction::x)
    {
        for (; s <= f; s++)
        {
            Komorka* k = excelVector[t][s];
            string zawartosc = k->getZawartosc();
            if (zawartosc.find_first_not_of("0123456789") == string::npos)
            {
                try {
                    int int_k_zawartosc = stoi(zawartosc);
                    sum += int_k_zawartosc;
                } catch (const invalid_argument& e)
                {
                    cout << "Nieprawidłowy argument: " << e.what() << endl;
                } catch (const out_of_range& e)
                {
                    cout << "Poza zakresem: " << e.what() << endl;
                }
            }
            else
            {
                cout << "Nieprawidłowa zawartość: " << zawartosc << endl;
            }
        }
    }
    return sum;
}

Excel::Excel(int x, int y)
{
    expand(x, y);
}

Excel::~Excel()
{
    destroy();
}

istream& operator>>(istream& is, direction& d)
{
    char t;
    is >> t;
    if (t == 'x')
    {
        d = direction::x;
    } else if (t == 'y')
    {
        d = direction::y;
    }
    else
    {
        d = direction::lev;
    }
    return is;
}

void Excel::save_to_file(const string& filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (vector<Komorka*> v : excelVector)
        {
            for (Komorka* k : v)
            {
                file << k->getZawartosc() << ",";
            }
            file << endl;
        }
        file.close();
        cout << "Arkusz zapisany do pliku: " << filename << endl;
    }
    else
    {
        cout << "Nie można otworzyć pliku do zapisu: " << filename << endl;
    }
}

void Excel::load_from_file(const string& filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        destroy();
        string line;
        while (getline(file, line))
        {
            vector<Komorka*> row;
            size_t start = 0;
            size_t end = line.find(',', start);
            while (end != string::npos)
            {
                string zawartosc = line.substr(start, end - start);
                KomorkaTekstowa* cell = new KomorkaTekstowa();
                cell->setZawartosc(zawartosc);
                row.push_back(cell);
                start = end + 1;
                end = line.find(',', start);
            }
            excelVector.push_back(row);
        }
        file.close();
        cout << "Arkusz został wczytany z pliku: " << filename << endl;
    }
    else
    {
        cout << "Nie można otworzyć pliku do odczytu: " << filename << endl;
    }
}


int main()
{
    Excel excel = Excel(10, 5);
    bool temp = true;
    while (temp)
    {
        cout << "Co chcesz zrobic?\n 1.Nadpisac komorke\n 2.Zsumowac zawartosci komorek\n 3.Usunac zawartosc komorek\n 4.Wyswietlenie zawartosci\n 5.Zapisz do pliku\n 6.Wczytaj z pliku\n 7.Wyjscie\n";
        int opcja = 0;
        cin >> opcja;
        switch (opcja)
        {
            case 1:
            {
                int x, y;
                string content;
                cin >> x >> y >> content;
                excel.set_cell(x, y, content);
                break;
            }
            case 2:
            {
                direction XY = direction::lev;
                while (XY == direction::lev)
                {
                    cout << "Podaj os do sumowania X albo Y\n";
                    cin >> XY;
                    if (XY == direction::lev)
                    {
                        cout << "Nie tak\n";
                    }
                }
                cout << "Podaj wartos startowa\n";
                int start;
                cin >> start;
                cout << "Podaj wartosc koncowa\n";
                int final;
                cin >> final;
                int level;
                cout << "Podaj poziom\n";
                cin >> level;
                cout << excel.sum_komorki(XY, level, start, final) << endl;
                break;
            }
            case 3:
            {
                cout << "Podaj komorke, ktorej zawartosc chcesz usunac. Podaj jej X i Y\n";
                int X, Y;
                cin >> X >> Y;
                excel.clear_cell(X, Y);
                break;
            }
            case 4:
            {
                cout << "Zawartosc ktorej komorki ciebie interesuje? Podaj jej X i Y\n";
                int X, Y;
                cin >> X >> Y;
                cout << excel.show_cell(X, Y) << endl;
                break;
            }
            case 5:
            {
                string filename;
                cout << "Podaj nazwę pliku do zapisu: ";
                cin >> filename;
                excel.save_to_file(filename);
                break;
            }
            case 6:
            {
                string filename;
                cout << "Podaj nazwę pliku do wczytania: ";
                cin >> filename;
                excel.load_from_file(filename);
                break;
            }
            case 7:
                temp = false;
                break;
            default:
                cout << "Nieprawidlowa opcja\n";
                break;
        }
    }
    return 0;
}
