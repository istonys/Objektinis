<h1>Objektinis programavimas</h1>
<h4><i>Ši papildoma užduotis atlikta vietoje egzamino praktinės užduoties</i></h4>

<h2>Šios programos ypatumas: skaityti iš failo, išrinkti žodžius bei esamus URLs</h2>
<p>Vykdant programą naudotasi tekstiniu failu pavadinimu "tekstas.txt", kurį galite surasti esančiame folderyje.</p>
<p>Failo tekstas išrinktas iš: https://lt.wikipedia.org/wiki/Europos_S%C4%85junga</p>
<h3>Ši lentelė parodys top5 dažniausiai pasikartojančius žodžius bei esančius URLs tekstiniame faile.</h3>
<table>
  <tr>
    <th>Žodis / URL</th>
    <th>Pasikartojimų sk. (URL netaikoma)</th>
  </tr>
  <tr>
    <td>Ir</td>
    <td>68</td>
  </tr>
  <tr>
    <td>Europa</td>
    <td>50</td>
  </tr>
  <tr>
    <td>ES</td>
    <td>35</td>
  </tr>
  <tr>
    <td>Sąjungos</td>
    <td>20</td>
  </tr>
  <tr>
    <td>Buvo</td>
    <td>11</td>
  </tr>
  <tr>
    <td>https://www.youtube.com</td>
    <td>-</td>
  </tr>
  <tr>
    <td>https://www.facebook.com</td>
    <td>-</td>
  </tr>
   <tr>
    <td>https://vu.lt</td>
    <td>-</td>
  </tr>
</table>
<h2>IŠSAMIAU</h2>
<p>Šis kodas yra skirtas rasti unikalias nuorodas tekste ir suskaičiuoti kiek kartų pasikartoja kiekvienas žodis, išskyrus skaičius. Rezultatas išsaugomas naujame faile "output.txt".</p>
<p>Kodas yra rašytas C++ kalba ir naudoja keletą bibliotekų: iostream, fstream, regex, map, stringstream, string, algorithm, set.</p>
