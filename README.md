<h3>Objektinis programavimas V0_2</h3>
<p><b><i>V0_2 versijos ypatumas: skaitymas iš failo.</i></b></p>
<h2>Kodo pavyzdys:</h2>
<code>void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute) {
    string failas;
    cout << "Galimi tekstinio failo pavadinimai:" << endl;
    system("dir /b | findstr \\.txt$");
    cout << "Iveskite failo pavadinima, kuri norite nuskaityti: ";
    cin >> failas;
    ifstream fd(failas);
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
<h2>Programos naudojimas</h2>
    <p>Paleista programa jūsų paklausia ar norite skaityti studentus iš failo <i>"kursiokai.txt"</i>, ar įvesti juos ranka. Pasirinkimą nurodykite raidėmis <b>"Y"</b> arba <b>"N"</b>.</p>
    <p>Pasirinkus <b>"Y"</b> - pradedamas skaitymas bei išvestis.</p>
    <p>Pasirinkus <b>"N"</b> - leidžiama jums pradėti įvestį ranka. Įvesčių kiekis nėra ribojamas, naudotis šia funkcija naudokitės programos nurodymais.</p>
<h2>Pagrindinės funkcijos </h2>
    <p><b>Skaityti()</b> - nuskaito studentų duomenis iš failo <i>"kursiokai.txt"</i>.</p>
    <p><b>Ivestis()</b> - leidžia vartotojui įvesti studentų duomenis ranka.</p>
    <p><b>Vidurkis()</b> - skaičiuoja studentų vidurkius.</p>
    <p><b>Mediana()</b> - skaičiuoja studentų medianas.</p>
    <p><b>Spausdinti()</b> - spausdina studentų duomenis ir jų vidurkius bei medianas.</p>
    <p><b>lygintiVardus()</b> - pagalbinė funkcija, kuri lygina studentų vardus ir padeda juos surikiuoti tinkama tvarka.</p>
<h2>Programos naudojimo pavyzdys:</h2>
<img src="https://user-images.githubusercontent.com/116721418/222552259-efc0cdad-27cc-4254-8c72-980c4e69798b.png" width="700" height="400">

