#include "mylib.h"

struct studentas {
    string vardas = "", pavarde = "";
    vector<int> pazymiai;
    int egz = 0;
    int pazymiuSkaicius = 0;
};

void Pildymas(studentas& temp);
void Spausdinti(studentas& temp);
double Vidurkis(studentas& temp);
double Mediana(studentas& temp);

int main()
{
    vector<studentas> grupe;
    studentas laikinas;
    string x;

    do {
        Pildymas(laikinas);
        grupe.push_back(laikinas);
        laikinas.pazymiai.clear();
        cout << "Ar norite testi pildyma? Y / N: ";
        cin >> x;
    } while (x == "Y" || x == "y");

    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(45) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        Spausdinti(grupe[i]);
    }
}

void Pildymas(studentas& temp) {
    string atsitiktinai;
    string pazymys_string, egzamino_string;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    cout << "Ar norite, kad pazymius bei egzamino bala sugeneruotume atsitiktine tvarka? Y / N: ";
    cin >> atsitiktinai;
    if (atsitiktinai == "Y" || atsitiktinai == "y") {
        srand(time(NULL));
        cout << "Koki kieki pazymiu sugeneruoti? ";
        while (true) {
            try {
                string a;
                cin >> a;
                temp.pazymiuSkaicius = stoi(a);
                if (temp.pazymiuSkaicius > 0) {
                    for (int i = 0; i < temp.pazymiuSkaicius; i++) {
                        temp.pazymiai.push_back(rand() % 10 + 1);
                    }
                    temp.egz = rand() % 10 + 1;
                    break;
                }
                else {
                    cout << "Klaida! Studentas turi tureti bent 1 pazymi, kad butu imanoma generuoti. Bandykite is naujo! " << endl;
                    cout << "Koki kieki pazymiu sugeneruoti? ";
                    continue;
                }
            }
            catch (const std::invalid_argument& e) {
                cout << "Klaida! Iveskite skaiciu! ";
            }
        }
    }
    else {
        cout << "Iveskite pazymius nuo 1 iki 10. Kai noresite sustoti, iveskite 0.: ";
        while (true) {
            cin >> pazymys_string;
            try {
                int pazymys = stoi(pazymys_string);
                if (pazymys < 0 || pazymys > 10) {
                    cout << "Klaida! Pazymiai turi buti intervale nuo 1 iki 10! Bandykite vesti is naujo: ";
                }
                else if (pazymys == 0) {
                    break;
                }
                else {
                    temp.pazymiai.push_back(pazymys);
                }
            }
            catch (const std::invalid_argument& e) {
                cout << "Klaida! Pazymys turi buti skaicius. Bandykite vesti is naujo: ";
            }
        }
        cout << "Iveskite egzamino paz. : ";
        while (true) {
            try {
                cin >> egzamino_string;
                temp.egz = stoi(egzamino_string);
                if (temp.egz <= 0 || temp.egz > 10) {
                    cout << "Klaida! Egzamino pazymys turi buti intervale nuo 1 iki 10! Bandykite vesti is naujo: ";
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
                cout << "Klaida! Egzamino pazymys turi buti skaicius. Bandykite vesti is naujo: ";
            }
        }
    }
    cout << "Duomenys irasyti." << endl;
}
double Vidurkis(studentas& temp) {
    double suma = 0;
    for (int i = 0; i < temp.pazymiai.size(); i++) {
        suma += temp.pazymiai[i];
    }
    return 0.4 * (suma / temp.pazymiai.size()) + (0.6 * temp.egz);
}
double Mediana(studentas& temp) {
    double mediana = 0;
    sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (temp.pazymiai.size() % 2 == 0) {
        mediana = (temp.pazymiai[(temp.pazymiai.size() / 2) - 1] + temp.pazymiai[temp.pazymiai.size() / 2]) / 2.0;
    }
    else
    {
        mediana = temp.pazymiai[temp.pazymiai.size() / 2];
    }
    return 0.4 * mediana + (0.6 * temp.egz);
}
void Spausdinti(studentas& temp) {
    cout << setw(15) << temp.vardas << setw(15) << temp.pavarde;
    if (temp.pazymiai.size() == 0) {
        cout << setw(35) << "Studentas pazymiu neturi!" << endl;
    }
    else {
        cout << setw(18) << fixed << setprecision(2) << Vidurkis(temp);
        cout << setw(20) << fixed << setprecision(2) << Mediana(temp) << endl;
    }
}