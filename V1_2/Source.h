#pragma once
#ifndef SOURCE_H
#define SOURCE_H
const vector<string> Vardai = { "Tomas", "Lukas", "Jonas", "Maksas", "Adomas", "Matas", "Augustas", "Benas", "Donatas", "Andrius", "Arturas", "Darius", "Edgaras", "Ernestas", "Giedrius", "Ignas", "Juozas", "Kestas", "Laurynas", "Marius", "Mindaugas", "Povilas", "Rokas", "Saulius", "Tadas", "Agne", "Austeja", "Birute", "Dovile", "Egle", "Elze", "Gintare", "Ieva", "Inga", "Jolanta", "Jurate", "Justina", "Kamile", "Kornelija", "Laima", "Lina", "Loreta", "Marija", "Neringa", "Ona", "Ramune", "Rasa", "Ruta", "Simona", "Zivile" };
const vector<string> Vyriskos_pavardes = { "Kavaliauskas", "Petrauskas", "Jankauskas", "Vaitkus", "Rimkus", "Brazauskas", "Vilkelis", "Mikalauskas", "Kazlauskas", "Navickas", "Adomaitis", "Ramanauskas", "Paulauskas", "Kazokas", "Kairys", "Jonauskas", "Stankevicius", "Urbonas", "Gudaitis", "Gricius", "Zalys", "Venclovas", "Maciulis", "Kriauciunas", "Lukosius", "Gavenciakas" };
const vector<string> Moteriskos_pavardes = { "Vaitkute", "Kazlauskaite", "Jankauskaite", "Petrauskaite", "Dambrauskaite", "Balciunaite", "Janaviciute", "Zilinskaite", "Paulauskaite", "Matulaite", "Simkusaite", "Kavaliauskaite", "Laurinaite", "Bagdonaite", "Bartkeviciute", "Adomaitiene", "Stankeviciute", "Marcinkeviciute", "Klimaviciute", "Jureviciute", "Pociute", "Kairyte", "Apanaviciute", "Sileikaite" };
const vector<string> Failai = { "Studentai1000.txt", "Studentai10000.txt", "Studentai100000.txt", "Studentai1000000.txt", "Studentai10000000.txt" };
class Studentas {
private:
	string Vardas;
	string Pavarde;
	vector<int> Pazymiai;
	int Egzamino_balas;
	double Vidurkis;
	double Mediana;
public:
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
	// getter'iai
	string vardas() { return Vardas; }
	string pavarde() { return Pavarde; }
	double gauti_vidurki() { return Vidurkis; }
	double gauti_mediana() { return Mediana; }
	int gauti_egzamino_bala() { return Egzamino_balas; }
	vector<int>& gauti_pazymius() {
		return Pazymiai;
	}
	// setter'iai
	void vardas(string vardas) { Vardas = vardas; }
	void pavarde(string pavarde) { Pavarde = pavarde; }
	void prideti_pazymi(int pazymys) { Pazymiai.push_back(pazymys); }
	void nustatyti_egzamino_bala(int balas) { Egzamino_balas = balas; }
	//metodai
	void istrinti_pazymius() { Pazymiai.clear(); }
	void skaiciuoti_vidurki() {
		int suma = 0;
		for (int i = 0; i < Pazymiai.size(); i++) {
			suma += Pazymiai[i];
		}
		Vidurkis = double(0.4 * (suma / Pazymiai.size()) + 0.6 * Egzamino_balas);
	}
	void skaiciuoti_mediana() {
		sort(Pazymiai.begin(), Pazymiai.end());
		int vidurys = Pazymiai.size() / 2;
		if (Pazymiai.size() % 2 == 0) {
			Mediana = 0.4 * ((Pazymiai[vidurys - 1] + Pazymiai[vidurys]) / 2.0) + 0.6 * Egzamino_balas;
		}
		else {
			Mediana = 0.4 * Pazymiai[vidurys] + 0.6 * Egzamino_balas;
		}
	}
	bool arVargsiukas() const {
		return Vidurkis >= 5;
	}
	bool arGalvocius() const {
		return Vidurkis < 5;
	}
	bool operator<(const Studentas& other) const {
		return Vardas < other.Vardas || (Vardas == other.Vardas && Pavarde < other.Pavarde);
	}
	// destruktorius
	~Studentas() { Pazymiai.clear(); }
};
bool lygintiVardus(const Studentas& a, const Studentas& b);
void Skaityti(vector<Studentas>& grupe, vector<string>& pirmaEilute, bool& ar);
void Ivestis(vector<Studentas>& grupe);
string arRandom(string testi);
string arTesti(string testi);
void Spausdinti(vector<Studentas>& grupe);
void Generuoti();
void Rusiuoti(vector<Studentas>& grupe);
void arGeneruoti(string& skaityti);
void arSkaityti(string& skaityti);
void SkaitymoCiklas(vector<Studentas>& grupe, vector<string>& pirmaEilute, string& skaityti);
#endif