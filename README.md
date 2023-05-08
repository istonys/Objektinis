<h3>Objektinis programavimas</h3>
<h4>Laboratorinis darbas: vektoriaus realizacija.</h4>

<h3>Tikrintas funkcionalumas:</h3>
<li>Push_back()</li>
<li>Pop_back()</li>
<li>Front()</li>
<li>Back()</li>
<li>Resize()</li>
<li>Clear()</li>
<p></p>
<p>Naudotas kodas:</p>
<code>std::vector<int> v1;
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
	std::cout << "manoVector size ir capacity po clear(): " << v2.getSize() << " " << v2.getCapacity() << std::endl;</code>
  
<h2>Rezultatai:</h2>
<img src="https://user-images.githubusercontent.com/116721418/236911697-93bba52f-7a14-4fef-8f94-d0321300eebc.png">

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
