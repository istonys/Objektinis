#include "Header.h"
#include "Source.h"

bool lygintiVardus(Studentas& a, Studentas& b) {
    return b.vardas() > a.vardas();
}
bool arVargsiukas(Studentas& c) {
    return c.gauti_vidurki() >= 5;
}
bool arGalvocius(Studentas& c) {
    return c.gauti_vidurki() < 5;
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
            string vardas;
            string pavarde;
            int a;
            istringstream iss(eilute);
            iss >> vardas >> pavarde;
            tmp.vardas(vardas);
            tmp.pavarde(pavarde);
            tmp.istrinti_pazymius();
            while (iss >> a) {
                tmp.prideti_pazymi(a);
            }
            tmp.nustatyti_egzamino_bala(tmp.gauti_pazymius().back());
            tmp.gauti_pazymius().pop_back();
            tmp.skaiciuoti_mediana();
            tmp.skaiciuoti_vidurki();
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
        string vardas, pavarde;
        cout << "Iveskite studento varda bei pavarde: ";
        cin >> vardas >> pavarde;
        tmp.vardas(vardas);
        tmp.pavarde(pavarde);
        testi = arRandom(testi);

        if (testi == "t") {
            int kiekis;
            while (true) {
                try {
                    cout << "Iveskite studento pazymiu kieki: ";
                    cin >> pazymiu_kiekis;
                    kiekis = stoi(pazymiu_kiekis);
                    if (kiekis <= 0) {
                        cout << "Klaida! Studentas turi tureti bent 1 pazymi." << endl;
                        continue;
                    }
                    break;
                }
                catch (const invalid_argument& ia) {
                    cout << "Klaida! Pazymiu kiekis turi buti sveikasis skaicius." << endl;
                }
            }

            for (int i = 0; i < kiekis; i++) {
                tmp.prideti_pazymi(rand() % 10 + 1);
            }
            tmp.nustatyti_egzamino_bala(rand() % 10 + 1);
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
                        tmp.prideti_pazymi(tikrinti);
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
                        tmp.nustatyti_egzamino_bala(kintamasis);
                        break;
                    }
                }
                catch (const invalid_argument& ia) {
                    cout << "Klaida! Egzamino balas turi buti sveikasis skaicius." << endl;
                }
            }
        }
        tmp.skaiciuoti_mediana();
        tmp.skaiciuoti_vidurki();
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
void Spausdinti(vector<Studentas>& grupe) {
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << setw(15) << grupe[i].vardas() << setw(15) << grupe[i].pavarde() << setw(18) << fixed << setprecision(2) << grupe[i].gauti_vidurki() << setw(17) << grupe[i].gauti_mediana() << endl;
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
    //10000000
    auto startF10000000 = std::chrono::high_resolution_clock::now();
    ofstream failas10000000("Studentai10000000.txt");
    failas10000000 << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < pazymiuskc; i++) {
        failas10000000 << setw(7) << "ND" << i + 1 << " ";
    }
    failas10000000 << setw(7) << "EGZ." << endl;
    for (int i = 0; i < 10000000; i++) {
        vardas = Vardai[rand() % 49];
        if (vardas.back() == 's') {
            pavarde = Vyriskos_pavardes[rand() % 24];
        }
        else {
            pavarde = Moteriskos_pavardes[rand() % 24];
        }
        failas10000000 << setw(25) << vardas << setw(25) << pavarde;
        for (int j = 0; j < pazymiuskc; j++) {
            failas10000000 << setw(8) << rand() % 10 + 1 << " ";
        }
        failas10000000 << setw(7) << rand() % 10 + 1 << endl;
    }
    cout << "Studentai10000000.txt failas sugeneruotas" << endl;
    failas10000000.close();
    auto stopF10000000 = std::chrono::high_resolution_clock::now();
    auto durationF10000000 = std::chrono::duration_cast<std::chrono::milliseconds>(stopF10000000 - startF10000000);
    cout << "Sugeneruoti faila Studentai10000000.txt uztruko: " << durationF10000000.count() / 1000.0 << " s" << endl;
    cout << "-------------------------------------------------------" << endl;
}
void Rusiuoti(vector<Studentas>& grupe) {
    string pasirinkimas;
    cout << "Kaip norite rusiuoti? Galimos strategijos:" << endl;
    cout << "1 - Rusiavimas i du naujus to paties tipo konteinerius (1 strategija)" << endl;
    cout << "2 - Rusiavimas panaudojant tik viena nauja konteineri (2 strategija)" << endl;
    cout << "Noredami pasirinkti parasykite skaiciuka: ";
    while (true) {
        cin >> pasirinkimas;
        int tikrinti = stoi(pasirinkimas);
        if (tikrinti == 1) {
            //1 strategija
            vector<Studentas> V_galvociai;
            vector<Studentas> V_vargsiukai;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < grupe.size(); i++) {
                if (grupe[i].gauti_vidurki() >= 5) {
                    V_galvociai.push_back(grupe[i]);
                }
                else V_vargsiukai.push_back(grupe[i]);
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << "Suskirstymas i galvocius ir vargsiukus uztruko: " << duration.count() / 1000.0 << " s" << endl;

            auto startRasyti = std::chrono::high_resolution_clock::now();

            ofstream vargsiukai("vargsiukai.txt");
            vargsiukai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
            vargsiukai << "--------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < V_vargsiukai.size(); i++) {
                vargsiukai << setw(15) << V_vargsiukai[i].vardas() << setw(15) << V_vargsiukai[i].pavarde() << setw(18) << fixed << setprecision(2) << V_vargsiukai[i].gauti_vidurki() << setw(17) << V_vargsiukai[i].gauti_mediana() << endl;
            }
            vargsiukai.close();
            ofstream galvociai("galvociai.txt");
            galvociai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
            galvociai << "--------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < V_galvociai.size(); i++) {
                galvociai << setw(15) << V_galvociai[i].vardas() << setw(15) << V_galvociai[i].pavarde() << setw(18) << fixed << setprecision(2) << V_galvociai[i].gauti_vidurki() << setw(17) << V_galvociai[i].gauti_mediana() << endl;
            }
            galvociai.close();
            auto stopRasyti = std::chrono::high_resolution_clock::now();
            auto durationRasyti = std::chrono::duration_cast<std::chrono::milliseconds>(stopRasyti - startRasyti);
            cout << "Surasymas i skirtingus failus uztruko: " << durationRasyti.count() / 1000.0 << " s" << endl;
            V_vargsiukai.clear();
            V_galvociai.clear();
            break;
        }
        else if (tikrinti == 2) {
            //2 strategija
            auto start = std::chrono::high_resolution_clock::now();
            vector<Studentas> Vargsiukai;
            Vargsiukai.resize(1);

            std::remove_copy_if(grupe.begin(), grupe.end(), std::back_inserter(Vargsiukai), arVargsiukas);
            grupe.erase(std::remove_if(grupe.begin(), grupe.end(), arGalvocius), grupe.end());

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << "Suskirstymas i galvocius ir vargsiukus uztruko: " << duration.count() / 1000.0 << " s" << endl;

            auto startRasyti = std::chrono::high_resolution_clock::now();

            ofstream vargsiukai("vargsiukai.txt");
            vargsiukai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
            vargsiukai << "--------------------------------------------------------------------------------" << endl;
            for (int i = 1; i < Vargsiukai.size(); i++) {
                vargsiukai << setw(15) << Vargsiukai[i].vardas() << setw(15) << Vargsiukai[i].pavarde() << setw(18) << fixed << setprecision(2) << Vargsiukai[i].gauti_vidurki() << setw(17) << Vargsiukai[i].gauti_mediana() << endl;
            }
            vargsiukai.close();
            ofstream galvociai("galvociai.txt");
            galvociai << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(35) << "Galutinis vid. / Galutinis med." << endl;
            galvociai << "--------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < grupe.size(); i++) {
                galvociai << setw(15) << grupe[i].vardas() << setw(15) << grupe[i].pavarde() << setw(18) << fixed << setprecision(2) << grupe[i].gauti_vidurki() << setw(17) << grupe[i].gauti_mediana() << endl;
            }
            galvociai.close();
            auto stopRasyti = std::chrono::high_resolution_clock::now();
            auto durationRasyti = std::chrono::duration_cast<std::chrono::milliseconds>(stopRasyti - startRasyti);
            cout << "Surasymas i skirtingus failus uztruko: " << durationRasyti.count() / 1000.0 << " s" << endl;
            Vargsiukai.clear();
            grupe.clear();
            break;
        }
        else {
            cout << "Klaida! Bandykite dar karta: ";
        }
    }
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
        Generuoti();
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
        grupe.clear();
        bool ar = true;
        Skaityti(grupe, pirmaEilute, ar);
        if (ar) {
            auto start = std::chrono::high_resolution_clock::now();
            sort(grupe.begin(), grupe.end());
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << "Sort() uztruko: " << duration.count() / 1000.0 << " s" << endl;
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