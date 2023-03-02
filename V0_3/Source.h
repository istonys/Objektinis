#pragma once
#ifndef SOURCE_H
#define SOURCE_H

struct Studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int pazymiu_kiekis = 0;
    int egzamino_balas = 0;
    double vidurkis = 0;
    double mediana = 0;
};

bool lygintiVardus(const Studentas& a, const Studentas& b);
void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute);
void Ivestis(vector<Studentas>& grupe);
string arRandom(string testi);
string arTesti(string testi);
void Vidurkis(vector<Studentas>& grupe);
void Mediana(vector<Studentas>& grupe);
void Spausdinti(vector<Studentas>& grupe);
#endif