#include "Header.h"

struct Studentas {
    string vardas, pavarde;
    int* pazymiai = nullptr;
    int pazymiu_kiekis = 0;
    int surinktas_kiekis = 0;
    int egzamino_balas = 0;
    double vidurkis = 0;
    double mediana = 0;
};

void Ivestis(Studentas*& grupe, int& n);
string arRandom(string testi);
string arTesti(string testi);
void Vidurkis(Studentas*& grupe, int n);
void Mediana(Studentas*& grupe, int n);
void Spausdinti(Studentas*& grupe, int n);

int main()
{
    int n = 1;
    Studentas* grupe = new Studentas[n];
    srand(time(NULL));
    Ivestis(grupe, n);
    Vidurkis(grupe, n);
    Mediana(grupe, n);
    Spausdinti(grupe, n);
    for (int i = 0; i < n; i++) {
        delete[] grupe[i].pazymiai;
    }
    delete[] grupe;
    cout << "Programos pabaiga.";
    return 0;
}

void Ivestis(Studentas*& grupe, int& n) {
    string testi = "";
    string pazymiu_kiekis;
    cout << "Iveskite studento varda bei pavarde: ";
    cin >> grupe[0].vardas >> grupe[0].pavarde;

    testi = arRandom(testi);
 
    if (testi == "y") {
        while (true) {
            try {
                cout << "Iveskite studento pazymiu kieki: ";
                cin >> pazymiu_kiekis;
                grupe[0].pazymiu_kiekis = stoi(pazymiu_kiekis);
                if (grupe[0].pazymiu_kiekis <= 0) {
                    cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                    continue;
                }
                break;
            }
            catch (exception& e) {
                cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
            }
        }
        grupe[0].pazymiai = new int[grupe[0].pazymiu_kiekis];

        for (int i = 0; i < grupe[0].pazymiu_kiekis; i++) {
            grupe[0].pazymiai[i] = rand() % 10 + 1;
        }
        grupe[0].egzamino_balas = rand() % 10 + 1;
        cout << "Sugeneravome pazymius bei egzamino bala." << endl;
    }
    else {
        while (true) {
            try {
                cout << "Iveskite studento pazymiu kieki: ";
                cin >> pazymiu_kiekis;
                grupe[0].pazymiu_kiekis = stoi(pazymiu_kiekis);
                if (grupe[0].pazymiu_kiekis <= 0) {
                    cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                    continue;
                }
                break;
            }
            catch (exception& e) {
                cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
            }
        }

        grupe[0].pazymiai = new int[grupe[0].pazymiu_kiekis];
        for (int i = 0; i < grupe[0].pazymiu_kiekis; i++) {
            try {
                string pazymys;
                cout << "Iveskite " << i + 1 << "-aji pazymi (jeigu norite stabdyti vedima, rasykite -1): ";
                cin >> pazymys;
                int tikrinti = stoi(pazymys);
                if ((tikrinti <= 0 || tikrinti > 10) && tikrinti != -1) {
                    cout << "Skaicius turi buti intervale nuo 1 iki 10. Bandykite dar karta!" << endl;
                    i--;
                }
                else if (tikrinti == -1) {
                    for (int j = grupe[0].surinktas_kiekis++; j < grupe[0].pazymiu_kiekis; j++) {
                        grupe[0].pazymiai[j] = 1;
                        grupe[0].surinktas_kiekis++;
                    }
                    break;
                }
                else {
                    grupe[0].pazymiai[i] = tikrinti;
                    grupe[0].surinktas_kiekis++;
                }
            }
            catch (exception& e) {
                cout << "Klaida! Pazymys turi buti sveikasis skaicius." << endl;
                i--;
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
                    grupe[0].egzamino_balas = kintamasis;
                    break;
                }
            }
            catch (exception& e) {
                cout << "Klaida! Egzamino balas turi buti sveikasis skaicius." << endl;
            }
        }
    }

    do {
        testi = arTesti(testi);
    } while (testi != "y" && testi != "n");

    while (testi == "y") {

        Studentas* tmp = new Studentas[n + 1];
        copy(grupe, grupe + n, tmp);
        delete[] grupe;

        cout << "Iveskite studento varda bei pavarde: ";
        cin >> tmp[n].vardas >> tmp[n].pavarde;

        testi = arRandom(testi);

        if (testi == "y") {
            while (true) {
                try {
                    cout << "Iveskite studento pazymiu kieki: ";
                    cin >> pazymiu_kiekis;
                    tmp[n].pazymiu_kiekis = stoi(pazymiu_kiekis);
                    if (tmp[n].pazymiu_kiekis <= 0) {
                        cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                        continue;
                    }
                    break;
                }
                catch (exception& e) {
                    cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
                }
            }
            tmp[n].pazymiai = new int[tmp[n].pazymiu_kiekis];

            for (int i = 0; i < tmp[n].pazymiu_kiekis; i++) {
                tmp[n].pazymiai[i] = rand() % 10 + 1;
            }
            tmp[n].egzamino_balas = rand() % 10 + 1;
            cout << "Sugeneravome pazymius bei egzamino bala." << endl;
        }
        else {
            while (true) {
                try {
                    cout << "Iveskite studento pazymiu kieki: ";
                    cin >> pazymiu_kiekis;
                    tmp[n].pazymiu_kiekis = stoi(pazymiu_kiekis);
                    if (tmp[n].pazymiu_kiekis <= 0) {
                        cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                        continue;
                    }
                    break;
                }
                catch (exception& e) {
                    cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
                }
            }

            tmp[n].pazymiai = new int[tmp[n].pazymiu_kiekis];

            for (int i = 0; i < tmp[n].pazymiu_kiekis; i++) {
                try {
                    string pazymys;
                    cout << "Iveskite " << i + 1 << "-aji pazymi (jeigu norite stabdyti vedima, rasykite -1): ";
                    cin >> pazymys;
                    int tikrinti = stoi(pazymys);
                    if ((tikrinti <= 0 || tikrinti > 10) && tikrinti != -1) {
                        cout << "Skaicius turi buti intervale nuo 1 iki 10. Bandykite dar karta!" << endl;
                        i--;
                    }
                    else if (tikrinti == -1) {
                        for (int j = tmp[n].surinktas_kiekis++; j < tmp[n].pazymiu_kiekis; j++) {
                            tmp[n].pazymiai[j] = 1;
                            tmp[n].surinktas_kiekis++;
                        }
                        break;
                    }
                    else {
                        tmp[n].pazymiai[i] = tikrinti;
                        tmp[n].surinktas_kiekis++;
                    }
                }
                catch (exception& e) {
                    cout << "Klaida! Pazymys turi buti sveikasis skaicius." << endl;
                    i--;
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
                        tmp[n].egzamino_balas = kintamasis;
                        break;
                    }
                }
                catch (exception& e) {
                    cout << "Klaida! Egzamino balas turi buti sveikasis skaicius." << endl;
                }
            }
        }

        n++;

        grupe = new Studentas[n];
        copy(tmp, tmp + n, grupe);
        delete[] tmp;

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

void Vidurkis(Studentas*& grupe, int n) {
    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = 0; j < grupe[i].pazymiu_kiekis; j++) {
            suma += grupe[i].pazymiai[j];
        }
        grupe[i].vidurkis = double(0.4 * (suma / grupe[i].pazymiu_kiekis) + 0.6 * grupe[i].egzamino_balas);
    }
}

void Mediana(Studentas*& grupe, int n) {
    for (int i = 0; i < n; i++) {
        sort(grupe[i].pazymiai, grupe[i].pazymiai + grupe[i].pazymiu_kiekis);
        int vidurys = grupe[i].pazymiu_kiekis / 2;
        if (grupe[i].pazymiu_kiekis % 2 == 0) {
            grupe[i].mediana = 0.4 * ((grupe[i].pazymiai[vidurys - 1] + grupe[i].pazymiai[vidurys]) / 2.0) + 0.6 * grupe[i].egzamino_balas;
        }
        else {
            grupe[i].mediana = 0.4 * grupe[i].pazymiai[vidurys] + 0.6 * grupe[i].egzamino_balas;
        }
    }
}

void Spausdinti(Studentas*& grupe, int n) {
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(18) << fixed << setprecision(2) << grupe[i].vidurkis << setw(17) << grupe[i].mediana << endl;
    }
}