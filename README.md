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
<h2>Programos naudojimas</h2>
<p>Paleista programa jūsų paklausia ar norite skaityti studentus iš failo "kursiokai.txt", ar įvesti juos ranka. Pasirinkimą nurodykite raidėmis "Y" arba "N".</p>
    <p>Pasirinkus "Y" - pradedamas skaitymas bei išvestis.</p>
    <p>Pasirinkus "N" - leidžiama jums pradėti įvestį ranka. Įvesčių kiekis nėra ribojamas, naudotis šia funkcija naudokitės programos nurodymais.</p>
<h2>Pagrindinės funkcijos </h2>
    <p>Skaityti() - nuskaito studentų duomenis iš failo "kursiokai.txt".</p>
    <p>Ivestis() - leidžia vartotojui įvesti studentų duomenis ranka.</p>
    <p>Vidurkis() - skaičiuoja studentų vidurkius.</p>
    <p>Mediana() - skaičiuoja studentų medianas.</p>
    <p>Spausdinti() - spausdina studentų duomenis ir jų vidurkius bei medianas.</p>
    <p>lygintiVardus() - pagalba funkcija, kuri lygina studentų vardus.</p>
<h2>Programos naudojimo pavyzdys:</h2>
![Screenshot 2023-03-02 230310](https://user-images.githubusercontent.com/116721418/222552259-efc0cdad-27cc-4254-8c72-980c4e69798b.png =500x300)
<img src="https://user-images.githubusercontent.com/116721418/222552259-efc0cdad-27cc-4254-8c72-980c4e69798b.png" width="100" height="100">

