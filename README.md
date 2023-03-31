<h3>Objektinis programavimas V0_5</h3>
<p><b><i>V0_5 versijos ypatumas: testavimas su list ir deque konteineriais.</i></b></p>
<h3>Testavimo rezultatai su vector:</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000.txt</td>
        <td>0.003 s</td>
        <td>0 s</td>
        <td>0 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.032 s</td>
        <td>0.002 s</td>
        <td>0.004 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>0.238 s</td>
        <td>0.012 s</td>
        <td>0.022 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.226 s</td>
        <td>0.136 s</td>
        <td>0.268 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>21.107 s</td> 
        <td>1.409 s</td>
        <td>2.886 s</td>
    </tr>
</table>
<h3>Testavimo rezultatai su list:</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000.txt</td>
        <td>0.002 s</td>
        <td>0 s</td>
        <td>0 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.031 s</td>
        <td>0.001 s</td>
        <td>0.003 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>0.238 s</td>
        <td>0.03 s</td>
        <td>0.064 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.303 s</td>
        <td>0.604 s</td>
        <td>0.664 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>20.237 s</td>
        <td>7.463 s</td>
        <td>5.561 s</td>
    </tr>
</table>
<h3>Testavimo rezultatai su deque:</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000.txt</td>
        <td>0.002 s</td>
        <td>0 s</td>
        <td>0 s</td>
    </tr>
    <tr>        
        <td>Studentai10000.txt</td>
        <td>0.02 s</td>
        <td>0.001 s</td>
        <td>0.001 s</td>
    </tr>
    <tr>
        <td>Studentai100000.txt</td>
        <td>0.192 s</td>
        <td>0.017 s</td>
        <td>0.017 s</td>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>1.939 s</td>
        <td>0.234 s</td>
        <td>0.205 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>19.317 s</td>
        <td>2.663 s</td>
        <td>2.155 s</td>
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
