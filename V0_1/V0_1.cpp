#include "mylib.h"

struct studentas {
    string vardas = "", pavarde = "";
    int* pazymiai = nullptr;
    int egz = 0;
    int pazymiuSkaicius = 0;
};

void Pildymas(studentas& temp);
void Spausdinti(studentas& temp);
double Vidurkis(studentas& temp);
double Mediana(studentas& temp);

int main()
{
    studentas* grupe;
    int n = 1;
    string x;
    grupe = new studentas[n];
    Pildymas(grupe[0]);
    cout << "Ar norite testi pildyma? Y / N: ";
    do {
        cin >> x;
        if (x == "Y" || x == "y") {
            studentas* temp = new studentas[n];
            copy(grupe, grupe + n, temp);
            delete[] grupe;

            grupe = new studentas[n + 1];
            copy(temp, temp + n, grupe);
            delete[] temp;

            n++;

            Pildymas(grupe[n - 1]);
            cout << "Ar norite testi pildyma? Y / N: ";
        }
    } while (x == "Y" || x == "y");
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(45) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        Spausdinti(grupe[i]);
    }
    delete[] grupe;
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
                    int* A = new int[temp.pazymiuSkaicius];
                    for (int i = 0; i < temp.pazymiuSkaicius; i++) {
                        A[i] = rand() % 10 + 1;
                    }
                    temp.pazymiai = new int[temp.pazymiuSkaicius];
                    copy(A, A + temp.pazymiuSkaicius, temp.pazymiai);
                    delete[] A;
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
        int* A = new int[1];
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
                    A[temp.pazymiuSkaicius] = pazymys;
                    temp.pazymiuSkaicius++;
                    int* B = new int[temp.pazymiuSkaicius + 1];
                    copy(A, A + temp.pazymiuSkaicius, B);
                    delete[] A;

                    A = new int[temp.pazymiuSkaicius + 1];
                    copy(B, B + temp.pazymiuSkaicius, A);
                    delete[] B;
                }
            }
            catch (const std::invalid_argument& e) {
                cout << "Klaida! Pazymys turi buti skaicius. Bandykite vesti is naujo: ";
            }
        }
        temp.pazymiai = A;
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
    for (int i = 0; i < temp.pazymiuSkaicius; i++) {
        suma += temp.pazymiai[i];
    }
    return 0.4 * (suma / temp.pazymiuSkaicius) + (0.6 * temp.egz);
}
double Mediana(studentas& temp) {
    double mediana = 0;
    sort(temp.pazymiai, temp.pazymiai + temp.pazymiuSkaicius);
    if (temp.pazymiuSkaicius % 2 == 0) {
        mediana = (temp.pazymiai[(temp.pazymiuSkaicius / 2) - 1] + temp.pazymiai[temp.pazymiuSkaicius / 2]) / 2.0;
    }
    else
    {
        mediana = temp.pazymiai[temp.pazymiuSkaicius / 2];
    }
    return 0.4 * mediana + (0.6 * temp.egz);
}
void Spausdinti(studentas& temp) {
    cout << setw(15) << temp.vardas << setw(15) << temp.pavarde;
    if (temp.pazymiuSkaicius == 0) {
        cout << setw(36) << "Studentas pazymiu neturi! ";
    }
    else {
        cout << setw(18) << fixed << setprecision(2) << Vidurkis(temp);
        cout << setw(20) << fixed << setprecision(2) << Mediana(temp) << endl;
    }
    delete[] temp.pazymiai;
}