<h3>Objektinis programavimas V0_4</h3>
<p><b><i>V0_4 versijos ypatumas: failų rūšiavimas bei laiko matavimas.</i></b></p>
<h2>Kodo pavyzdys:</h2>
<code>void Rusiuoti(vector<Studentas>& grupe) {                                                                          
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
}                                                                                                                                                           </code>
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
<img src="https://user-images.githubusercontent.com/116721418/225136264-a91244b4-cfee-4a61-bd5f-0bdd5a597343.png" width="700" height="400">
