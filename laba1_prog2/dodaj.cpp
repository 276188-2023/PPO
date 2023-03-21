#include<iostream>
#include<vector>
#include"struct.hpp"
using namespace std;


void wypis(vector<student> studenci)
{
    for (int i = 0; i < studenci.size(); i++)
    {
        cout << studenci[i].imie << " " << studenci[i].nazwisko << " " << studenci[i].indeks << endl;
    }
}

void dodaj(vector<student> &studenci)
{
    student student_t;
    for(int i=0; i<4; i++)
    {
        cout << i+1 << "." <<"Podaj imie: ";
        cin >> student_t.imie;
        cout << i+1 << "." "Podaj nazwisko: ";
        cin >> student_t.nazwisko;
        cout << i+1 << "." "Podaj nr. indeksu: ";
        cin >> student_t.indeks;
        // system(clear); // для вінди "CLS"
        studenci.push_back(student_t);
    }
}
