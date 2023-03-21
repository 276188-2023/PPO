#include<iostream>
#include<vector>
#include"struct.hpp"
using namespace std;

vector <string> Indeks()
{
    string tablica[4]={"023465", "276199", "756499", "437601"};
    string tablica1[2]={"000000", "111111"};
    vector <string> indeks;
    int j = 0;
    for(int i=0; i<6; i++)
    {
        if(i<4)
        {
            indeks.push_back(tablica[i]);
        }
        else 
        {
            indeks.push_back(tablica[j]);
            j++;
        }
    }
    return indeks;
}

void wypis(vector<student> studenci)
{
    vector <string> indeks = Indeks();
    for (int i = 0; i < studenci.size(); i++)
    {
        cout << studenci[i].imie << " " << studenci[i].nazwisko << " " << indeks[i] << endl;
    }
}

void dodaj(vector<student> &studenci)
{
    student student_t;
    for(int i=0; i<6; i++)
    {
        cout << i+1 << "." <<"Podaj imie: ";
        cin >> student_t.imie;
        cout << i+1 << "." "Podaj nazwisko: ";
        cin >> student_t.nazwisko;
        // system(clear); // для вінди "CLS"
        studenci.push_back(student_t);
    }
}
