<h3>Objektinis programavimas</h3>
<h4>Laboratorinis darbas: vektoriaus realizacija.</h4>

<h3>Tikrintas funkcionalumas:</h3>
<li>Push_back()</li>
<li>Pop_back()</li>
<li>Front()</li>
<li>Back()</li>
<li>Resize()</li>
<li>Clear()</li>
<li>Visu operatoriu testavimas</li>
<p></p>
<p>Naudotas kodas:</p>
<code>


	int main() {

	std::vector<int> v1;
	manoVector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	std::cout << "std::vector elementai po push_back(): ";
	for (int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "manoVector elementai po push_back(): ";
	for (int i = 0; i < v2.getSize(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl << std::endl;
	v1.pop_back();
	v2.pop_back();

	std::cout << "std::vector elementai po pop_back(): ";
	for (int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "manoVector elementai po pop_back(): ";
	for (int i = 0; i < v2.getSize(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "std::vector front(): " << v1.front() << std::endl;
	std::cout << "manoVector front(): " << v2.front() << std::endl << std::endl;

	std::cout << "std::vector back(): " << v1.back() << std::endl;
	std::cout << "manoVector back(): " << v2.back() << std::endl << std::endl;


	std::cout << "std::vector size ir capacity pries resize(50): " << v1.size() << " " << v1.capacity() << std::endl;
	v1.resize(50);
	std::cout << "std::vector size ir capacity po resize(50): " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << "manoVector size ir capacity pries resize(50): " << v2.getSize() << " " << v2.getCapacity() << std::endl;
	v2.resize(50);
	std::cout << "manoVector size ir capacity po resize(50): " << v2.getSize() << " " << v2.getCapacity() << std::endl << std::endl;

	v1.clear();
	std::cout << "std::vector size ir capacity po clear(): " << v1.size() << " " << v1.capacity() << std::endl;

	v2.clear();
	std::cout << "manoVector size ir capacity po clear(): " << v2.getSize() << " " << v2.getCapacity() << std::endl;

	manoVector<int> alice;
	alice.push_back(1);
	alice.push_back(2);
	alice.push_back(3);

	manoVector<int> bob;
	bob.push_back(7);
	bob.push_back(8);
	bob.push_back(9);
	bob.push_back(10);

	manoVector<int> eve;
	eve.push_back(1);
	eve.push_back(2);
	eve.push_back(3);

	std::cout << std::boolalpha << std::endl;
	std::cout << "Operatoriu testavimas:" << std::endl << std::endl;
	// Compare non equal containers
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

	std::cout << '\n';

	// Compare equal containers
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

	return 0;
}
<h2>Rezultatai:</h2>
<img src="https://github.com/istonys/Objektinis/assets/116721418/9dfd13bf-a313-44a6-be2d-eeb041488b02">
<p></p>
<h3>Ši lentelė parodo spartos testavimo rezultatus (DEBUG mode).</h3>
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

<h3>Ši lentelė parodo spartos testavimo rezultatus (RELEASE mode).</h3>
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
<h3>Ši lentelė parodo kiek perskirstymų įvykdyta su Studentai10000000.txt</h3>
<table>
<tr>
<th></th>
<th>Perskirstymų kiekis</th>
</tr>
<tr>
<td>std::vector</td>
<td>41</td>
</tr>
<tr>
<td>manoVector</td>
<td>21</td>
</tr>
</table>
<h3>Ši lentelė parodo kiek trunka programos vykdymas su manoVector ir std::vector naudojant Studentai10000000.txt</h3>
<table>
	<tr>
		<th></th>
		<th>Nuskaitymas iš failo</th>
		<th>Sort()</th>
		<th>Suskirstymas</th>
	</tr>
	<tr>
		<td>manoVector</th>
		<th>24.845 s</th>
		<th>6.371 s</th>
		<th>2.927 s</th>
	</tr>
	<tr>
		<td>std::vector</th>
		<th>21.107 s</th>
		<th>1.409 s</th>
		<th>1.603 s</th>
	</tr>
</table
