#pragma once
#ifndef SOURCE_H
#define SOURCE_H
const vector<string> Vardai = { "Tomas", "Lukas", "Jonas", "Maksas", "Adomas", "Matas", "Augustas", "Benas", "Donatas", "Andrius", "Arturas", "Darius", "Edgaras", "Ernestas", "Giedrius", "Ignas", "Juozas", "Kestas", "Laurynas", "Marius", "Mindaugas", "Povilas", "Rokas", "Saulius", "Tadas", "Agne", "Austeja", "Birute", "Dovile", "Egle", "Elze", "Gintare", "Ieva", "Inga", "Jolanta", "Jurate", "Justina", "Kamile", "Kornelija", "Laima", "Lina", "Loreta", "Marija", "Neringa", "Ona", "Ramune", "Rasa", "Ruta", "Simona", "Zivile" };
const vector<string> Vyriskos_pavardes = { "Kavaliauskas", "Petrauskas", "Jankauskas", "Vaitkus", "Rimkus", "Brazauskas", "Vilkelis", "Mikalauskas", "Kazlauskas", "Navickas", "Adomaitis", "Ramanauskas", "Paulauskas", "Kazokas", "Kairys", "Jonauskas", "Stankevicius", "Urbonas", "Gudaitis", "Gricius", "Zalys", "Venclovas", "Maciulis", "Kriauciunas", "Lukosius", "Gavenciakas" };
const vector<string> Moteriskos_pavardes = { "Vaitkute", "Kazlauskaite", "Jankauskaite", "Petrauskaite", "Dambrauskaite", "Balciunaite", "Janaviciute", "Zilinskaite", "Paulauskaite", "Matulaite", "Simkusaite", "Kavaliauskaite", "Laurinaite", "Bagdonaite", "Bartkeviciute", "Adomaitiene", "Stankeviciute", "Marcinkeviciute", "Klimaviciute", "Jureviciute", "Pociute", "Kairyte", "Apanaviciute", "Sileikaite" };
const vector<string> Failai = { "Studentai1000.txt", "Studentai10000.txt", "Studentai100000.txt", "Studentai1000000.txt", "Studentai10000000.txt"};
struct Studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int pazymiu_kiekis = 0;
    int egzamino_balas = 0;
    double vidurkis = 0;
    double mediana = 0;
};

bool lygintiVardus(const Studentas& a, const Studentas& b);
void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute, bool& ar);
void Ivestis(vector<Studentas>& grupe);
string arRandom(string testi);
string arTesti(string testi);
void Vidurkis(vector<Studentas>& grupe);
void Mediana(vector<Studentas>& grupe);
void Spausdinti(vector<Studentas>& grupe);
void Generuoti();
void Rusiuoti(vector<Studentas>& grupe);
void arGeneruoti(string& skaityti);
void arSkaityti(string& skaityti);
void SkaitymoCiklas(vector<Studentas>& grupe, vector<string>& pirmaEilute, string& skaityti);
#endif