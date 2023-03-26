<h3>Objektinis programavimas V0_5</h3>
<p><b><i>V0_5 versijos ypatumas: testavimas su <b>list</b> ir <b>deque</b> konteineriais.</i></b></p>
<h2>Kodo pavyzdys:</h2>
<code>auto startF1000 = std::chrono::high_resolution_clock::now();
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
    cout << "-------------------------------------------------------" << endl;</code>
<h2>Testavimo rezultatai</h2>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Generavimo trukmė</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
        <th>Surasymas i failus</th>
    </tr>
    <tr>
        <td>Studentai1000.txt</td>
        <td>0.008 s</td>
        <td>0.005 s</td>
        <td>0 s</td>
        <td>0 s</td>
        <td>0 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.057 s</td>
        <td>0.029 s</td>
        <td>0.001 s</td>
        <td>0.001 s</td>
        <td>0.001 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>0.965 s</td>
        <td>0.246 s</td>
        <td>0.011 s</td>
        <td>0.021 s</td>
        <td>0.021 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>3.768 s</td>
        <td>4.207 s</td>
        <td>0.133 s</td>
        <td>0.246 s</td>
        <td>0.246 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>35.741 s</td>
        <td>26.139 s</td>
        <td>1.367 s</td>
        <td>2.533 s</td>
        <td>2.533 s</td>
    </tr>
</table>
<h2>Programos naudojimas</h2>
    <p>Programos pradžioje suteikta galimybė sugeneruoti studentų failus.</p>
    <p>Toliau programa jūsų paklausia ar norite skaityti studentus iš failo, ar įvesti juos ranka. Pasirinkimą nurodykite raidėmis <b>"T"</b> arba <b>"N"</b>.</p>
    <p>Pasirinkus <b>"T"</b> - duodami failų pasirinkimai, įrašius pavadinimą, apdorojamas failas.</p>
    <p>Pasirinkus <b>"N"</b> - leidžiama jums pradėti įvestį ranka. Įvesčių kiekis nėra ribojamas, naudotis šia funkcija naudokitės programos nurodymais.</p>
<h2>Pagrindinės funkcijos </h2>
    <p><b>Skaityti()</b> - nuskaito studentų duomenis iš failo</p>
    <p><b>Ivestis()</b> - leidžia vartotojui įvesti studentų duomenis ranka.</p>
    <p><b>Vidurkis()</b> - skaičiuoja studentų vidurkius.</p>
    <p><b>Mediana()</b> - skaičiuoja studentų medianas.</p>
    <p><b>Spausdinti()</b> - spausdina studentų duomenis ir jų vidurkius bei medianas.</p>
    <p><b>lygintiVardus()</b> - pagalbinė funkcija, kuri lygina studentų vardus ir padeda juos surikiuoti tinkama tvarka.</p>
<h2>Programos naudojimo pavyzdys:</h2>
<img src="https://user-images.githubusercontent.com/116721418/225136264-a91244b4-cfee-4a61-bd5f-0bdd5a597343.png" width="900" height="500">
