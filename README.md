<h3>Objektinis programavimas V0_2</h3>
<p><b><i>V0_2 versijos ypatumas: skaitymas iš failo.</i></b></p>
<code>void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute) {
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
  } </code>
<h2>Naudojimas</h2>
<p>Paleista programa jūsų paklausia ar norite skaityti studentus iš failo "kursiokai.txt", ar įvesti juos ranka. Pasirinkimą nurodykite raidėmis "Y" arba "N".</p>


