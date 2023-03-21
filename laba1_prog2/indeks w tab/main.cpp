#include<iostream>
#include<vector>
#include"dodaj.hpp"
using namespace std;

vector<student> studenci;

int main()
{
    dodaj(studenci);
    wypis(studenci);
    return 0;
}