<h3>Objektinis programavimas V1_2</h3>
<p><b><i>V1_2 versijos ypatumas: Rule of Five ir papildomų operatorių realizacija</i></b></p>
<p>Kodo pavyzdys:</p>
<code>public:
	//constructor
	Studentas() {
		Vardas = "Vardenis";
		Pavarde = "Pavardenis";
		Egzamino_balas = 0;
		Vidurkis = 0;
		Mediana = 0;
	}
	//copy constructor
	Studentas(const Studentas& other) {
		Vardas = other.Vardas;
		Pavarde = other.Pavarde;
		Egzamino_balas = other.Egzamino_balas;
		Vidurkis = other.Vidurkis;
		Mediana = other.Mediana;
		Pazymiai = other.Pazymiai;
	}
	//copy assignment operator
	Studentas& operator=(const Studentas& other) {
		if (this != &other) {
			Vardas = other.Vardas;
			Pavarde = other.Pavarde;
			Egzamino_balas = other.Egzamino_balas;
			Vidurkis = other.Vidurkis;
			Mediana = other.Mediana;
			Pazymiai = other.Pazymiai;
		}
		return *this;
	}
	//move constructor
	Studentas(Studentas&& other) noexcept {
		Vardas = std::move(other.Vardas);
		Pavarde = std::move(other.Pavarde);
		Pazymiai = std::move(other.Pazymiai);
		Egzamino_balas = std::move(other.Egzamino_balas);
		Vidurkis = std::move(other.Vidurkis);
		Mediana = std::move(other.Mediana);
	}
	//move assignment operator
	Studentas& operator=(Studentas&& other) noexcept {
		if (this != &other) {
			Vardas = std::move(other.Vardas);
			Pavarde = std::move(other.Pavarde);
			Pazymiai = std::move(other.Pazymiai);
			Egzamino_balas = other.Egzamino_balas;
			Vidurkis = other.Vidurkis;
			Mediana = other.Mediana;
		}
		return *this;
	}
	//output operator
	friend ostream& operator<<(ostream& out, const Studentas& student) {
		out << left << setw(15) << student.Vardas << setw(15) << student.Pavarde << setw(18) << fixed << setprecision(2) << student.Vidurkis << setw(17) << fixed << setprecision(2) << student.Mediana << endl;
		return out;
	}
</code>
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
