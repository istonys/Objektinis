<h3>Objektinis programavimas</h3>
<h4>Laboratorinis darbas: vektoriaus realizacija.</h4>

<p>Ši lentelė parodo spartos testavimo rezultatus (DEBUG mode).</p>
<table>
  <tr>
    <th>Size dydis</th>
    <th>manoVector</th>
    <th>std::vector</th>
  </tr>
  <tr>
    <td>100000</td>
    <td>0 s</td>
    <td>0.008 s</td>
  </tr>
  <tr>
    <td>1000000</td>
    <td>0.006 s</td>
    <td>0.052 s</td>
  </tr>
  <tr>
    <td>10000000</td>
    <td>0.096 s</td>
    <td>0.789 s</td>
  </tr>
  <tr>
    <td>100000000</td>
    <td>0.75 s</td>
    <td>6.047 s</td>
  </tr>
</table>

<p>Ši lentelė parodo spartos testavimo rezultatus (RELEASE mode).</p>
<table>
  <tr>
    <th>Size dydis</th>
    <th>manoVector</th>
    <th>std::vector</th>
  </tr>
  <tr>
    <td>100000</td>
    <td>0 s</td>
    <td>0 s</td>
  </tr>
  <tr>
    <td>1000000</td>
    <td>0.002 s</td>
    <td>0.002 s</td>
  </tr>
  <tr>
    <td>10000000</td>
    <td>0.019 s</td>
    <td>0.027 s</td>
  </tr>
  <tr>
    <td>100000000</td>
    <td>0.449 s</td>
    <td>0.374 s</td>
  </tr>
</table>
