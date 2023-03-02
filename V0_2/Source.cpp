#include "Header.h"
#include "Source.h"

bool lygintiVardus(const Studentas& a, const Studentas& b) {
    return b.vardas > a.vardas;
}
void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute) {
    ifstream fd("kursiokai.txt");
    if (!fd.fail()) {
        string eilute;
        getline(fd, eilute);
        pirmaEilute.push_back(eilute);
        while (getline(fd, eilute)) {
            Studentas tmp;
            int a;
            istringstream iss(eilute);
            iss >> tmp.vardas >> tmp.pavarde;
            tmp.pazymiai.clear();
            while (iss >> a) {
                tmp.pazymiai.push_back(a);
            }
            tmp.egzamino_balas = tmp.pazymiai.back();
            tmp.pazymiai.pop_back();
            grupe.push_back(tmp);
        }
        fd.close();
    }
    else {
        cout << "Klaida, failo nuskaityti nepavyko!" << endl;
        cout << "Programa galite testi ivesdami studentus ranka." << endl;
        fd.close();
        Ivestis(grupe);
    }
}
void Ivestis(vector<Studentas>& grupe) {
    string testi = "";
    string pazymiu_kiekis;

    cout << "Ar norite pradeti vedima? Y / N: ";
    do {
        cin >> testi;
        transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
        if (testi != "y" && testi != "n") {
            cout << "Netinkama ivestis. Iveskite Y arba N." << endl;
        }
    } while (testi != "y" && testi != "n");

    while (testi == "y") {
        Studentas tmp;

        cout << "Iveskite studento varda bei pavarde: ";
        cin >> tmp.vardas >> tmp.pavarde;

        testi = arRandom(testi);

        if (testi == "y") {
            while (true) {
                try {
                    cout << "Iveskite studento pazymiu kieki: ";
                    cin >> pazymiu_kiekis;
                    tmp.pazymiu_kiekis = stoi(pazymiu_kiekis);
                    if (tmp.pazymiu_kiekis <= 0) {
                        cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                        continue;
                    }
                    break;
                }
                catch (const invalid_argument& ia) {
                    cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
                }
            }

            for (int i = 0; i < tmp.pazymiu_kiekis; i++) {
                tmp.pazymiai.push_back(rand() % 10 + 1);
            }
            tmp.egzamino_balas = rand() % 10 + 1;
            cout << "Sugeneravome pazymius bei egzamino bala." << endl;
        }
        else {
            int count = 0;
            while (true) {
                try {
                    string pazymys;
                    cout << "Iveskite " << count + 1 << "-aji pazymi (jeigu norite stabdyti vedima, rasykite -1): ";
                    cin >> pazymys;
                    int tikrinti = stoi(pazymys);
                    if ((tikrinti <= 0 || tikrinti > 10) && tikrinti != -1) {
                        cout << "Skaicius turi buti intervale nuo 1 iki 10. Bandykite dar karta!" << endl;
                    }
                    else if (tikrinti == -1) {
                        if (count == 0) {
                            cout << "Studentas turi tureti bent 1 pazymi." << endl;
                            continue;
                        }
                        break;
                    }
                    else {
                        tmp.pazymiai.push_back(tikrinti);
                        count++;
                    }
                }
                catch (const invalid_argument& ia) {
                    cout << "Klaida! Pazymys turi buti sveikasis skaicius." << endl;
                }
            }

            while (true) {
                try {
                    string egzamino_balas;
                    int kintamasis;
                    cout << "Iveskite studento egzamino bala: ";
                    cin >> egzamino_balas;
                    kintamasis = stoi(egzamino_balas);
                    if (kintamasis <= 0 || kintamasis > 10) {
                        cout << "Klaida! Egzamino balas turi buti intervale nuo 1 iki 10." << endl;
                    }
                    else {
                        tmp.egzamino_balas = kintamasis;
                        break;
                    }
                }
                catch (const invalid_argument& ia) {
                    cout << "Klaida! Egzamino balas turi buti sveikasis skaicius." << endl;
                }
            }
        }

        grupe.push_back(tmp);

        testi = arTesti(testi);
    }
}
string arRandom(string testi) {
    cout << "Ar norite, kad pazymius bei egzamino bala sugeneruotume atsitiktinai? Y / N: ";
    do {
        cin >> testi;
        transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
        if (testi != "y" && testi != "n") {
            cout << "Netinkama ivestis. Iveskite Y arba N." << endl;
        }
    } while (testi != "y" && testi != "n");
    return testi;
}
string arTesti(string testi) {
    cout << "Ar norite testi ivesti? Y / N: ";
    cin >> testi;
    transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
    if (testi != "y" && testi != "n") {
        cout << "Netinkama ivestis. Iveskite Y arba N." << endl;
    }
    return testi;
}

void Vidurkis(vector<Studentas>& grupe) {
    for (int i = 0; i < grupe.size(); i++) {
        int suma = 0;
        for (int j = 0; j < grupe[i].pazymiai.size(); j++) {
            suma += grupe[i].pazymiai[j];
        }
        grupe[i].vidurkis = double(0.4 * (suma / grupe[i].pazymiai.size()) + 0.6 * grupe[i].egzamino_balas);
    }
}

void Mediana(vector<Studentas>& grupe) {
    for (int i = 0; i < grupe.size(); i++) {
        sort(grupe[i].pazymiai.begin(), grupe[i].pazymiai.end());
        int vidurys = grupe[i].pazymiai.size() / 2;
        if (grupe[i].pazymiai.size() % 2 == 0) {
            grupe[i].mediana = 0.4 * ((grupe[i].pazymiai[vidurys - 1] + grupe[i].pazymiai[vidurys]) / 2.0) + 0.6 * grupe[i].egzamino_balas;
        }
        else {
            grupe[i].mediana = 0.4 * grupe[i].pazymiai[vidurys] + 0.6 * grupe[i].egzamino_balas;
        }
    }
}

void Spausdinti(vector<Studentas>& grupe) {
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(18) << fixed << setprecision(2) << grupe[i].vidurkis << setw(17) << grupe[i].mediana << endl;
    }
}