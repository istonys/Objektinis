<h3>Objektinis programavimas V0_5</h3>
<p><b><i>V0_5 versijos ypatumas: testavimas su list ir deque konteineriais.</i></b></p>
<h3>Testavimo rezultatai su vector:</h3>
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
<h3>Testavimo rezultatai su list:</h3>
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
        <td>0.019 s</td>
        <td>0.027 s</td>
        <td>0 s</td>
        <td>0.002 s</td>
        <td>0.002 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.105 s</td>
        <td>0.19 s</td>
        <td>0.008 s</td>
        <td>0.038 s</td>
        <td>0.038 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>1.141 s</td>
        <td>1.883 s</td>
        <td>0.137 s</td>
        <td>0.275 s</td>
        <td>0.275 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>10.835 s</td>
        <td>18.972 s</td>
        <td>1.507 s</td>
        <td>3.342 s</td>
        <td>3.342 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>118.128 s</td>
        <td>250.356 s</td>
        <td>30.397 s</td>
        <td>49.258 s</td>
        <td>49.258 s</td>
    </tr>
</table>
<h3>Testavimo rezultatai su deque:</h3>
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
        <td>0.013 s</td>
        <td>0.02 s</td>
        <td>0.005 s</td>
        <td>0.001 s</td>
        <td>0.001 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.108 s</td>
        <td>0.186 s</td>
        <td>0.074 s</td>
        <td>0.015 s</td>
        <td>0.015 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>1.592 s</td>
        <td>1.864 s</td>
        <td>0.569 s</td>
        <td>0.157 s</td>
        <td>0.157 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>13.882 s</td>
        <td>19.264 s</td>
        <td>6.94 s</td>
        <td>2.755 s</td>
        <td>2.755 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>124.323 s</td>
        <td>241.711 s</td>
        <td>97.052 s</td>
        <td>31.377 s</td>
        <td>31.377 s</td>
    </tr>
</table>
<h2>Trumpa išvada: vector ryškiai pranašesnis už list ir deque.</h2>
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
