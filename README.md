<h3>Objektinis programavimas V1_1</h3>
<p><b><i>V1_1 versijos ypatumas: programos perrašymas iš struct naudojimo į class; struct vs. class testavimas</i></b></p>
<p>Testavimas atliktas pasinaudojus sparčiausia (2) strategija.</p>
<h3>Struct:</h3>
<h3>Main.exe: 409KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.226 s</td>
        <td>0.136 s</td>
        <td>0.146 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>21.107 s</td> 
        <td>1.409 s</td>
        <td>1.603 s</td>
    </tr>
</table>
<h3>Struct -O1:</h3>
<h3>Main.exe: 234KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>1.904 s</td>
        <td>0.108 s</td>
        <td>0.138 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>19.237 s</td> 
        <td>1.182 s</td>
        <td>1.575 s</td>
    </tr>
</table>
<h3>Struct -O2:</h3>
<h3>Main.exe: 223KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>1.908 s</td>
        <td>0.106 s</td>
        <td>0.138 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>19.524 s</td> 
        <td>1.369 s</td>
        <td>1.538 s</td>
    </tr>
</table>
<h3>Struct -O3:</h3>
<h3>Main.exe: 230KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>1.888 s</td>
        <td>0.108 s</td>
        <td>0.139 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>19.201 s</td> 
        <td>1.185 s</td>
        <td>1.578 s</td>
    </tr>
</table>
<h3>Class:</h3>
<h3>Main.exe: 413KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.157 s</td>
        <td>0.632 s</td>
        <td>0.139 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>21.208 s</td> 
        <td>6.739 s</td>
        <td>1.552 s</td>
    </tr>
</table>
<h3>Class -O1:</h3>
<h3>Main.exe: 237KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.052 s</td>
        <td>0.567 s</td>
        <td>0.132 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>21.297 s</td> 
        <td>6.255 s</td>
        <td>1.355 s</td>
    </tr>
</table>
<h3>Class -O2:</h3>
<h3>Main.exe: 226KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.118 s</td>
        <td>0.587 s</td>
        <td>0.129 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>20.929 s</td> 
        <td>6.337 s</td>
        <td>1.365 s</td>
    </tr>
</table>
<h3>Class -O3:</h3>
<h3>Main.exe: 239KB</h3>
<table>
    <tr>
        <th>Failo pav.</th>
        <th>Nuskaitymas</th>
        <th>Sort() trukmė</th>
        <th>Suskirstymo trukmė</th>
    </tr>
    <tr>
        <td>Studentai1000000.txt</td>
        <td>2.153 s</td>
        <td>0.583 s</td>
        <td>0.127 s</td>
    </tr>
    <tr>
        <td>Studentai10000000.txt</td>
        <td>21.915 s</td> 
        <td>6.256 s</td>
        <td>1.396 s</td>
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
    <p><b>Spausdinti()</b> - spausdina studentų duomenis ir jų vidurkius bei medianas.</p>
    <p><b>lygintiVardus()</b> - pagalbinė funkcija, kuri lygina studentų vardus ir padeda juos surikiuoti tinkama tvarka.</p>
<h2>Programos naudojimo pavyzdys:</h2>
<img src="https://user-images.githubusercontent.com/116721418/231956298-83a3cdd9-d920-4c71-a0e3-f2fad57bfc14.png" width="900" height="500">
