<h3>Objektinis programavimas V0_3</h3>
<p><b><i>V0_3 versijos ypatumas: V0_2 versijos reorganizavimas bei išimčių valdymas.</i></b></p>
<h2>Kodo pavyzdys:</h2>
<code>if (testi == "y") {
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
else {
  cout << "Klaida, failo nuskaityti nepavyko!" << endl;
  cout << "Programa galite testi ivesdami studentus ranka." << endl;
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
    <p><b>lygintiVardus()</b> - pagalbinė funkcija, kuri lygina studentų vardus.</p>
<h2>Programos naudojimo pavyzdys:</h2>
<img src="https://user-images.githubusercontent.com/116721418/222552259-efc0cdad-27cc-4254-8c72-980c4e69798b.png" width="700" height="400">
