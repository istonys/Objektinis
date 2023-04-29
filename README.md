<h3>Objektinis programavimas V1_5</h3>
<p><b><i>V1_5 versijos ypatumas: abstrakti "Zmogus" klasė ir derived Studentas.</i></b></p>
<p>Kodo pavyzdys:</p>
<code>class Zmogus {
protected:
	string Vardas;
	string Pavarde;
	int Vidurkis;
public:
	Zmogus() {
		Vardas = "Vardenis";
		Pavarde = "Pavardenis";
		Vidurkis = 0;
	}
	string vardas() const { return Vardas; }
	void vardas(const string& vardas) { Vardas = vardas; }

	string pavarde() const { return Pavarde; }
	void pavarde(const string& pavarde) { Pavarde = pavarde; }

	int vidurkis() const { return Vidurkis; }
	void vidurkis(int vidurkis) { Vidurkis = vidurkis; }

	virtual void trumpaiApieStudenta() = 0;

	virtual ~Zmogus() {};
};
class Studentas:public Zmogus { ... };
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
