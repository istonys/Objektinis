#include "Header.h"
#include "Source.h"

bool lygintiVardus(const Studentas& a, const Studentas& b) {
    return b.vardas > a.vardas;
}
void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute, bool& ar) {
    string failas;
    cout << "Galimi tekstinio failo pavadinimai:" << endl;
    system("dir /b Studentai1000.txt Studentai10000.txt Studentai100000.txt Studentai1000000.txt Studentai10000000.txt");
    cout << "Iveskite failo pavadinima, kuri norite nuskaityti: ";
    cin >> failas;
    ifstream fd(failas);
    if (!fd.fail()) {
        auto start = std::chrono::high_resolution_clock::now();
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
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        cout << "Nuskaitymas is failo uztruko: " << duration.count() / 1000.0 << " s" << endl;
    }
    else {
        cout << "Klaida, failo nuskaityti nepavyko!" << endl;
        ar = false;
        fd.close();
    }
}
void Ivestis(vector<Studentas>& grupe) {
    string testi = "";
    string pazymiu_kiekis;

    cout << "Ar norite pradeti vedima ranka? T / N: ";
    do {
        cin >> testi;
        transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
        if (testi != "t" && testi != "n") {
            cout << "Netinkama ivestis. Iveskite T arba N." << endl;
        }
    } while (testi != "t" && testi != "n");

    while (testi == "t") {
        Studentas tmp;

        cout << "Iveskite studento varda bei pavarde: ";
        cin >> tmp.vardas >> tmp.pavarde;

        testi = arRandom(testi);

        if (testi == "t") {
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
    cout << "Ar norite, kad pazymius bei egzamino bala sugeneruotume atsitiktinai? T / N: ";
    do {
        cin >> testi;
        transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
        if (testi != "t" && testi != "n") {
            cout << "Netinkama ivestis. Iveskite T arba N." << endl;
        }
    } while (testi != "t" && testi != "n");
    return testi;
}
string arTesti(string testi) {
    cout << "Ar norite testi ivesti? T / N: ";
    cin >> testi;
    transform(testi.begin(), testi.end(), testi.begin(), ::tolower);
    if (testi != "t" && testi != "n") {
        cout << "Netinkama ivestis. Iveskite T arba N." << endl;
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
void Generuoti() {
    string vardas;
    string pavarde;
    int pazymiuskc;
    cout << "Kiek pazymiu sugeneruoti kiekvienam studentui? Nuo 1 - 10. Iveskite: ";
    while (true) {
        try {
            string tikrinti;
            cin >> tikrinti;
            pazymiuskc = stoi(tikrinti);
            if ((pazymiuskc <= 0 || pazymiuskc > 10) && pazymiuskc != -1) {
                cout << "Skaicius turi buti intervale nuo 1 iki 10. Bandykite dar karta!" << endl;
            }
            break;
        }
        catch (const invalid_argument& ia) {
            cout << "Klaida! Pazymys turi buti sveikasis skaicius." << endl;
        }
    }
    cout << "Prasome palaukti, generavimas pradetas." << endl;
    cout << "-------------------------------------------------------" << endl;
    //1000
    auto startF1000 = std::chrono::high_resolution_clock::now();
    ofstream failas1000("Studentai1000.txt");
    failas1000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < pazymiuskc; i++) {
        failas1000 << setw(7) << "ND" << i + 1 << " ";
    }
    failas1000 << setw(7) << "EGZ." << endl;
    for (int i = 0; i < 1000; i++) {
        vardas = Vardai[rand() % 49];
        if (vardas.back() == 's') {
            pavarde = Vyriskos_pavardes[rand() % 24];
        }
        else {
            pavarde = Moteriskos_pavardes[rand() % 24];
        }
        failas1000 << setw(25) << vardas << setw(25) << pavarde;
        for (int j = 0; j < pazymiuskc; j++) {
            failas1000 << setw(8) << rand() % 10 + 1 << " ";
        }
        failas1000 << setw(7) << rand() % 10 + 1 << endl;
    }
    cout << "Studentai1000.txt failas sugeneruotas" << endl;
    failas1000.close();
    auto stopF1000 = std::chrono::high_resolution_clock::now();
    auto durationF1000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF1000 - startF1000);
    cout << "Sugeneruoti faila Studentai1000.txt uztruko: " << durationF1000.count() / 1000.0 << " s" << endl;
    cout << "-------------------------------------------------------" << endl;
    //10000
    auto startF10000 = std::chrono::high_resolution_clock::now();
    ofstream failas10000("Studentai10000.txt");
    failas10000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < pazymiuskc; i++) {
        failas10000 << setw(7) << "ND" << i + 1 << " ";
    }
    failas10000 << setw(7) << "EGZ." << endl;
    for (int i = 0; i < 10000; i++) {
        vardas = Vardai[rand() % 49];
        if (vardas.back() == 's') {
            pavarde = Vyriskos_pavardes[rand() % 24];
        }
        else {
            pavarde = Moteriskos_pavardes[rand() % 24];
        }
        failas10000 << setw(25) << vardas << setw(25) << pavarde;
        for (int j = 0; j < pazymiuskc; j++) {
            failas10000 << setw(8) << rand() % 10 + 1 << " ";
        }
        failas10000 << setw(7) << rand() % 10 + 1 << endl;
    }
    cout << "Studentai10000.txt failas sugeneruotas" << endl;
    failas10000.close();
    auto stopF10000 = std::chrono::high_resolution_clock::now();
    auto durationF10000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF10000 - startF10000);
    cout << "Sugeneruoti faila Studentai10000.txt uztruko: " << durationF10000.count() / 1000.0 << " s" << endl;
    cout << "-------------------------------------------------------" << endl;

    //100000
    auto startF100000 = std::chrono::high_resolution_clock::now();
    ofstream failas100000("Studentai100000.txt");
    failas100000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < pazymiuskc; i++) {
        failas100000 << setw(7) << "ND" << i + 1 << " ";
    }
    failas100000 << setw(7) << "EGZ." << endl;
    for (int i = 0; i < 100000; i++) {
        vardas = Vardai[rand() % 49];
        if (vardas.back() == 's') {
            pavarde = Vyriskos_pavardes[rand() % 24];
        }
        else {
            pavarde = Moteriskos_pavardes[rand() % 24];
        }
        failas100000 << setw(25) << vardas << setw(25) << pavarde;
        for (int j = 0; j < pazymiuskc; j++) {
            failas100000 << setw(8) << rand() % 10 + 1 << " ";
        }
        failas100000 << setw(7) << rand() % 10 + 1 << endl;
    }
    cout << "Studentai100000.txt failas sugeneruotas" << endl;
    failas100000.close();
    auto stopF100000 = std::chrono::high_resolution_clock::now();
    auto durationF100000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF100000 - startF100000);
    cout << "Sugeneruoti faila Studentai100000.txt uztruko: " << durationF100000.count() / 1000.0 << " s" << endl;
    cout << "-------------------------------------------------------" << endl;
    //1000000
    auto startF1000000 = std::chrono::high_resolution_clock::now();
    ofstream failas1000000("Studentai1000000.txt");
    failas1000000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < pazymiuskc; i++) {
        failas1000000 << setw(7) << "ND" << i + 1 << " ";
    }
    failas1000000 << setw(7) << "EGZ." << endl;
    for (int i = 0; i < 1000000; i++) {
        vardas = Vardai[rand() % 49];
        if (vardas.back() == 's') {
            pavarde = Vyriskos_pavardes[rand() % 24];
        }
        else {
            pavarde = Moteriskos_pavardes[rand() % 24];
        }
        failas1000000 << setw(25) << vardas << setw(25) << pavarde;
        for (int j = 0; j < pazymiuskc; j++) {
            failas1000000 << setw(8) << rand() % 10 + 1 << " ";
        }
        failas1000000 << setw(7) << rand() % 10 + 1 << endl;
    }
    cout << "Studentai1000000.txt failas sugeneruotas" << endl;
    failas1000000.close();
    auto stopF1000000 = std::chrono::high_resolution_clock::now();
    auto durationF1000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF1000000 - startF1000000);
    cout << "Sugeneruoti faila Studentai1000000.txt uztruko: " << durationF1000000.count() / 1000.0 << " s" << endl;
    cout << "-------------------------------------------------------" << endl;
    ////10000000
    // auto startF10000000 = std::chrono::high_resolution_clock::now();
    //ofstream failas10000000("Studentai10000000.txt");
    //failas10000000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    //for (int i = 0; i < pazymiuskc; i++) {
    //    failas10000000 << setw(7) << "ND" << i + 1 << " ";
    //}
    //failas10000000 << setw(7) << "EGZ." << endl;
    //for (int i = 0; i < 10000000; i++) {
    //    vardas = Vardai[rand() % 49];
    //    if (vardas.back() == 's') {
    //        pavarde = Vyriskos_pavardes[rand() % 24];
    //    }
    //    else {
    //        pavarde = Moteriskos_pavardes[rand() % 24];
    //    }
    //    failas10000000 << setw(25) << vardas << setw(25) << pavarde;
    //    for (int j = 0; j < pazymiuskc; j++) {
    //        failas10000000 << setw(8) << rand() % 10 + 1 << " ";
    //    }
    //    failas10000000 << setw(7) << rand() % 10 + 1 << endl;
    //}
    //cout << "Studentai10000000.txt failas sugeneruotas" << endl;
    //failas10000000.close();
    //auto stopF10000000 = std::chrono::high_resolution_clock::now();
    //auto durationF10000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF10000000 - startF10000000);
    //cout << "Sugeneruoti faila Studentai10000000.txt uztruko: " << durationF10000000.count() / 1000.0 << " s" << endl;
    //cout << "-------------------------------------------------------" << endl;
}
void Rusiuoti(vector<Studentas>& grupe) {
    auto start = std::chrono::high_resolution_clock::now();
    ofstream vargsiukai("vargsiukai.txt");
    vargsiukai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
    vargsiukai << "--------------------------------------------------------------------------------" << endl;

    ofstream galvociai("galvociai.txt");
    galvociai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
    galvociai << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        if (grupe[i].vidurkis >= 5) {
            galvociai << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(18) << fixed << setprecision(2) << grupe[i].vidurkis << setw(17) << grupe[i].mediana << endl;
        }
        else {
            vargsiukai << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(18) << fixed << setprecision(2) << grupe[i].vidurkis << setw(17) << grupe[i].mediana << endl;
        }
    }
    vargsiukai.close();
    galvociai.close();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Rusiavimas uztruko: " << duration.count() / 1000.0 << " s" << endl;
}
void arGeneruoti(string& skaityti) {
    cout << "Sveiki! Yra galimybe sugeneruoti 5 failus, kuriu dydziai yra:" << endl;
    cout << "1000, 10000, 100000, 1000000, 10000000 (studentu)" << endl;
    cout << "Ar norite sugeneruoti siuos failus (Generavimas gali uztrukti)? T / N: ";
    do {
        cin >> skaityti;
        transform(skaityti.begin(), skaityti.end(), skaityti.begin(), ::tolower);
        if (skaityti != "t" && skaityti != "n") {
            cout << "Netinkama ivestis. Iveskite T arba N." << endl;
        }
    } while (skaityti != "t" && skaityti != "n");
    if (skaityti == "t") {
        auto start = std::chrono::high_resolution_clock::now();
        Generuoti();
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        cout << "Visas generavimo procesas uztruko: " << duration.count() / 1000.0 << " s" << endl;
    }
}
void arSkaityti(string& skaityti) {
    cout << "Ar norite duomenis skaityti is failo? Jei ne, irasysite ranka. T / N: ";
    do {
        cin >> skaityti;
        transform(skaityti.begin(), skaityti.end(), skaityti.begin(), ::tolower);
        if (skaityti != "t" && skaityti != "n") {
            cout << "Netinkama ivestis. Iveskite T arba N." << endl;
        }
    } while (skaityti != "t" && skaityti != "n");
}
void SkaitymoCiklas(vector<Studentas>& grupe, vector<string>& pirmaEilute, string& skaityti) {
    do {
        bool ar = true;
        Skaityti(grupe, pirmaEilute, ar);
        if (ar) {
            sort(grupe.begin(), grupe.end(), lygintiVardus);
            Vidurkis(grupe);
            Mediana(grupe);
            Rusiuoti(grupe);
            cout << "Ar norite skaityti dar karta, is kito failo? T / N: ";
            do {
                cin >> skaityti;
                transform(skaityti.begin(), skaityti.end(), skaityti.begin(), ::tolower);
                if (skaityti != "t" && skaityti != "n") {
                    cout << "Netinkama ivestis. Iveskite T arba N." << endl;
                }
            } while (skaityti != "t" && skaityti != "n");
        }
        else {
            cout << "Ar norite bandyti skaityti dar karta? T / N: ";
            do {
                cin >> skaityti;
                transform(skaityti.begin(), skaityti.end(), skaityti.begin(), ::tolower);
                if (skaityti != "t" && skaityti != "n") {
                    cout << "Netinkama ivestis. Iveskite T arba N." << endl;
                }
            } while (skaityti != "t" && skaityti != "n");
        }
    } while (skaityti == "t");
}