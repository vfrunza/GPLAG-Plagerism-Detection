#include <iostream>
#include <tuple>
#include <string>
#include <stdexcept>
#include <ctime>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <memory>

/*      Date class       */
class Datum {
private:
	std::tuple<int, int, int> datum;
	/// additional Date functions
	bool static isLeap(const int& g) { return ((g % 4 == 0) && (g % 100 != 0)) || (g % 400 == 0); }
	int static const daysInMonth(const int& m, const int &g) {
		const int broj_dana[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return broj_dana[m - 1] + (isLeap(g) && m == 2 ? 1 : 0);
	}
	void static validDate(const int& d, const int& m, const int& g) {
		if (g < 1 || d < 1 || m < 1 || m > 12 || d > daysInMonth(m, g)) throw std::domain_error("Neispravan datum");
	}
public:
	/// ctor and mutators
	Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
	void Postavi(int dan, int mjesec, int godina) { validDate(dan, mjesec, godina), Datum::datum = std::make_tuple(dan, mjesec, godina); };
	/// inspectors
	std::tuple<int, int, int> Ocitaj() const { return this->datum; };
	void Ispisi() const;
	/// additional function
	void incrementDate(bool increase = true);
	static bool dolaziPrijeDatum(const Datum& d1, const Datum& d2);
	static bool istiDatumi(const Datum& d1, const Datum& d2);
};

/*      Time class       */
class Vrijeme {
private:
	std::pair<int, int> vrijeme;
	/// additional Time functions
	void static validTime(const int& h, const int& m) {
		if (!(h >= 0 && h < 24) || !(m >= 0 && m < 60)) throw std::domain_error("Neispravno vrijeme");
	}
	void static printTime(const int& t) { std::cout << (t < 10 ? "0" : "") << t; }
public:
	/// ctor and mutators
	Vrijeme(int sati, int minute) { Postavi(sati, minute); };
	void Postavi(int sati, int minute) { validTime(sati, minute), Vrijeme::vrijeme = std::make_pair(sati, minute); }
	/// inspectors
	std::pair<int, int> Ocitaj() const { return this->vrijeme; };
	void Ispisi() const;
	/// additional functions
	static bool dolaziPrijeVrijeme(const Vrijeme& t1, const Vrijeme& t2);
};

/*      Pregled class       */
class Pregled {
	using PokNaPregled = std::shared_ptr<Pregled>;
private:
	std::string ime_pacijenta;
	Datum datum_pregleda;
	Vrijeme vrijeme_pregleda;
public:
	/// ctors
	Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
	Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
		int godina_pregleda, int sati_pregleda, int minute_pregleda);
	// mutators
	void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta = ime_pacijenta; }
	void PromijeniDatum(const Datum &novi_datum) { Pregled::datum_pregleda = novi_datum; }
	void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { Pregled::vrijeme_pregleda = novo_vrijeme; }
	void PomjeriDanUnaprijed() { this->datum_pregleda.incrementDate(true); }
	void PomjeriDanUnazad() { this->datum_pregleda.incrementDate(false); }
	/// inspectors
	std::string DajImePacijenta() const { return this->ime_pacijenta; };
	Datum DajDatumPregleda() const { return this->datum_pregleda; };
	Vrijeme DajVrijemePregleda() const { return this->vrijeme_pregleda; };
	void Ispisi() const;
	/// additional funuctions
	static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
	static bool DolaziPrijePointer(const PokNaPregled& p1, const PokNaPregled& p2);
};

/*      Pregledi class       */
class Pregledi {
	using PokNaPregled = std::shared_ptr<Pregled>;
private:
	std::vector<PokNaPregled> pregledi;
	
	void checkIfEmpty() { if (pregledi.empty()) throw std::range_error("Prazna kolekcija"); }
	void checkRegisteredPregled() const { if (pregledi.empty()) throw std::domain_error("Nema registriranih pregleda"); }
	void deleteMember(const int& index) {
		if (pregledi.size() > index && index >= 0) pregledi.erase(pregledi.begin() + index);
	}
public:
	/// ctors and destructors
	explicit Pregledi();
	Pregledi(std::initializer_list<Pregled> spisak_pregleda);
	~Pregledi();
	Pregledi(const Pregledi &pregledi);
	Pregledi(Pregledi &&pregledi);
	Pregledi &operator =(const Pregledi &pregledi);
	Pregledi &operator =(Pregledi &&pregledi);

	void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
	void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
	void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
	/// mutators
	void IsprazniKolekciju();
	void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
	void ObrisiNajranijiPregled();
	/// inspectors
	int DajBrojPregleda() const;
	int DajBrojPregledaNaDatum(const Datum &datum) const;
	Pregled &DajNajranijiPregled();
	Pregled DajNajranijiPregled() const;
	void IspisiPregledeNaDatum(const Datum &datum) const;
	void IspisiSvePreglede() const;
};

///////////////////////////////////////// PREGLEDI IMPLEMENTATION
/// implementation of Pregledi function (CTORS AND DESTRUCTORS)
Pregledi::Pregledi() : pregledi(std::vector<PokNaPregled>()) {  }
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
	for(auto it(spisak_pregleda.begin()); it != spisak_pregleda.end(); ++it) 
		pregledi.push_back(PokNaPregled(new Pregled(*it))); 
}
Pregledi::~Pregledi() { }
Pregledi::Pregledi(const Pregledi &pregledi) {
	for (int i(0); i < pregledi.pregledi.size(); ++i)
		Pregledi::pregledi.push_back(PokNaPregled(new Pregled(*pregledi.pregledi[i])));
}
Pregledi::Pregledi(Pregledi &&pregledi) : pregledi(pregledi.pregledi) {
	pregledi.pregledi.clear();
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
	/// check max size
	int initialSize(Pregledi::pregledi.size());
	if (initialSize < pregledi.pregledi.size()) {
		try {
			for (int i(initialSize); i < pregledi.pregledi.size(); ++i)
				Pregledi::pregledi.push_back(PokNaPregled(new Pregled(*pregledi.pregledi[i])));
		}
		catch (...) {
			Pregledi::pregledi.resize(initialSize);
			throw;
		}
	}
	else {
		Pregledi::pregledi.resize(pregledi.pregledi.size());
	}
	/// copy other data
	int _upperBound(std::min(initialSize, int(pregledi.pregledi.size())));
	for (int i(0); i < _upperBound; ++i) 
			*Pregledi::pregledi[i] = *pregledi.pregledi[i];
	return *this;
}
Pregledi& Pregledi::operator =(Pregledi &&pregledi) {
	std::swap(Pregledi::pregledi, pregledi.pregledi);
	pregledi.pregledi.clear();
	return *this;
}
/// implementation of additional functions for registering
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
	Pregled _pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
	Pregledi::pregledi.push_back(PokNaPregled(new Pregled(_pregled)));
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
	Pregled _pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
	pregledi.push_back(PokNaPregled(new Pregled(_pregled)));
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
	pregledi.push_back(pregled);
}
/// REMOVE DATA FROM Pregledi
void Pregledi::IsprazniKolekciju() {
	pregledi.clear();
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
	for (int i(0); i < pregledi.size(); ++i) 
		if (pregledi[i]->DajImePacijenta() == ime_pacijenta) 
			this->deleteMember(i), --i;
}
void Pregledi::ObrisiNajranijiPregled() {
	this->checkIfEmpty();
	int _min(0);
	for(int i(0); i < pregledi.size(); ++i)
		if(Pregled::DolaziPrijePointer(pregledi[i], pregledi[_min]))
			_min = i;
	this->deleteMember(_min);
}
/// INSPECTOR FUNCTIONS PREGLEDI
int Pregledi::DajBrojPregleda() const {
	return pregledi.size();
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
	return std::count_if(pregledi.begin(), pregledi.end(), [&datum](const PokNaPregled& p1) {
		return Datum::istiDatumi(p1->DajDatumPregleda(), datum);
	});
}
Pregled& Pregledi::DajNajranijiPregled() {
	this->checkRegisteredPregled();
	PokNaPregled& _min = *std::min_element(pregledi.begin(), pregledi.end(), Pregled::DolaziPrijePointer);
	return *_min;
}
Pregled Pregledi::DajNajranijiPregled() const {
	this->checkRegisteredPregled();
	const PokNaPregled& _min = *std::min_element(pregledi.begin(), pregledi.end(), Pregled::DolaziPrijePointer);
	return *_min;
}

/// OUTPUT FUNCTIONS PREGLEDI
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
	auto compFunction = [this](const int& a, const int& b) -> bool {
		return (a < this->pregledi.size() && a >= 0) && (b < this->pregledi.size() && b >= 0) &&
			Pregled::DolaziPrijePointer(this->pregledi[a], this->pregledi[b]);
	};
	std::multiset<int, decltype(compFunction)> sorted (compFunction); /// ints in set to save space
	for(int i(0); i < this->pregledi.size(); ++i) 
		if(this->pregledi[i] != nullptr && Datum::istiDatumi(this->pregledi[i]->DajDatumPregleda(), datum)) 
			sorted.insert(i);
			
	for(auto it(sorted.begin()); it != sorted.end(); ++it)
		if(this->pregledi[*it] != nullptr)
			this->pregledi[*it]->Ispisi();
}
void Pregledi::IspisiSvePreglede() const {
	auto compFunction = [this](const int& a, const int& b) -> bool {
		return (a < this->pregledi.size() && a >= 0) && (b < this->pregledi.size() && b >= 0) &&
			Pregled::DolaziPrijePointer(this->pregledi[a], this->pregledi[b]);
	};
	std::multiset<int, decltype(compFunction)> sorted (compFunction);
	for(int i(0); i < pregledi.size(); ++i) sorted.insert(i);
	for(auto it(sorted.begin()); it != sorted.end(); ++it)
		if(this->pregledi[*it] != nullptr)
			this->pregledi[*it]->Ispisi();
}
///////////////////////////////////////// DATE IMPLEMENTATION
/// implementation of Date function
bool Datum::dolaziPrijeDatum(const Datum& d1, const Datum& d2) {
	return (std::get<2>(d1.Ocitaj()) < std::get<2>(d2.Ocitaj()) ||
		(std::get<2>(d1.Ocitaj()) == std::get<2>(d2.Ocitaj()) && std::get<1>(d1.Ocitaj()) < std::get<1>(d2.Ocitaj())) ||
		(std::get<2>(d1.Ocitaj()) == std::get<2>(d2.Ocitaj()) && std::get<1>(d1.Ocitaj()) == std::get<1>(d2.Ocitaj()) && std::get<0>(d1.Ocitaj()) < std::get<0>(d2.Ocitaj())));
}
bool Datum::istiDatumi(const Datum& d1, const Datum& d2) {
	return 	std::get<2>(d1.Ocitaj()) == std::get<2>(d2.Ocitaj()) && 
			std::get<1>(d1.Ocitaj()) == std::get<1>(d2.Ocitaj()) && std::get<0>(d1.Ocitaj()) == std::get<0>(d2.Ocitaj());
}

void Datum::incrementDate(bool increase) {
	if (increase) {
		if (1 + std::get<0>(datum) > daysInMonth(std::get<1>(datum), std::get<2>(datum))) {
			std::get<0>(datum) = 1;
			if (std::get<1>(datum) == 12) {
				std::get<1>(datum) = 0, std::get<2>(datum)++;
			} std::get<1>(datum)++;
		} else std::get<0>(datum)++;
	}
	else {
		if ((1 == std::get<0>(datum))) {
			if (std::get<1>(datum) == 1) {
				std::get<1>(datum) = 12, std::get<2>(datum)--;
			} else std::get<1>(datum)--;
			std::get<0>(datum) = daysInMonth(std::get<1>(datum), std::get<2>(datum));
		}
		else std::get<0>(datum)--;
		try { validDate(std::get<0>(datum), std::get<1>(datum), std::get<2>(datum)); }
		catch (...) { this->incrementDate(true); /*throw;*/ }
	}
}
void Datum::Ispisi() const {
	std::cout << std::get<0>(this->datum) << "/" << std::get<1>(this->datum) << "/" << std::get<2>(this->datum);
}
///////////////////////////////////////// TIME IMPLEMENTATION
/// implementation of Time function
bool Vrijeme::dolaziPrijeVrijeme(const Vrijeme& t1, const Vrijeme& t2) {
	return  (std::get<0>(t1.Ocitaj()) < std::get<0>(t2.Ocitaj()) || (
		(std::get<0>(t1.Ocitaj()) == std::get<0>(t2.Ocitaj())) &&
		(std::get<1>(t1.Ocitaj()) < std::get<1>(t2.Ocitaj()))));
}
void Vrijeme::Ispisi() const {
	printTime(std::get<0>(this->vrijeme)); std::cout << ":"; printTime(std::get<1>(this->vrijeme));
}
///////////////////////////////////////// PREGLED IMPLEMENTATION
/// implementation of Pregled function
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) :
	ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda)
{ }
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
	int godina_pregleda, int sati_pregleda, int minute_pregleda) :
	ime_pacijenta(ime_pacijenta),
	datum_pregleda(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
	vrijeme_pregleda(Vrijeme(sati_pregleda, minute_pregleda))
{ }
void Pregled::Ispisi() const {
	std::cout << std::setw(30) << std::left << this->DajImePacijenta().substr(0, 30);
	this->DajDatumPregleda().Ispisi(); std::cout << " "; this->DajVrijemePregleda().Ispisi(); std::cout << std::endl;
}
bool Pregled::DolaziPrijePointer(const PokNaPregled& p1, const PokNaPregled& p2) {
	return (p1 != nullptr && p2 != nullptr && Pregled::DolaziPrije(*p1, *p2));
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
	return Datum::dolaziPrijeDatum(p1.DajDatumPregleda(), p2.DajDatumPregleda()) || 
		(Datum::istiDatumi(p1.DajDatumPregleda(), p2.DajDatumPregleda()) && 
			Vrijeme::dolaziPrijeVrijeme(p1.DajVrijemePregleda(), p2.DajVrijemePregleda()));
}

/////////////////////////////// IMPLEMENTATION OF MAIN RW LOGIC
/// OPTION FUNCTIONS
/// clear Cin
void ResetujUlaz(std::string errorMessage = "") {
	if(errorMessage != "") std::cout << errorMessage << std::endl;
	if (!std::cin) std::cin.clear(); 
	std::cin.ignore(10000, '\n');
}

void BrojPregledaNaDatum(Pregledi& pregledi, bool numbers = false) {
	static int d, m, g;
	std::cout << "Unesite dan mjesec i godinu : ";
	for(;;) {
		std::cin >> d >> m >> g;
		try { 
			if (!std::cin) { ResetujUlaz("Pogresan unos, unesite ponovo!"); continue; }
			Datum dat(d, m, g); 
			if(!numbers) 
				std::cout << "Broj pregleda na datum " << d << ' ' << m << ' ' << g << " je: " << pregledi.DajBrojPregledaNaDatum(dat);
			else {
				std::cout << "Pregledi na datum " << d << ' ' << m << ' ' << g << " su:\n";
				pregledi.IspisiPregledeNaDatum(dat);
			} std::cout << std::endl;
			break;
		} 
		catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
}

void option(Pregledi& pregledi, bool show_text = true) {
	static int choose;
	if(show_text) std::cout << "\nOdaberite jednu od sljedecih opcija\n\
1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n\
5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n"; 
	std::cin >> choose;
	if (!std::cin || choose < 1 || choose > 7) {
		ResetujUlaz("Unos nije validan, unesite ponovo!"); option(pregledi, false);
	}
	switch(choose) {
		case 1: { 
			BrojPregledaNaDatum(pregledi); 
			option(pregledi); break; 
		}
		case 2: { 
			try { std::cout << "Najraniji pregled je: \n"; pregledi.DajNajranijiPregled().Ispisi(); }
			catch(std::domain_error& e) { std::cout << e.what() << std::endl; }
			option(pregledi); break; 
		}
		case 3: { 
			std::string ime; 
			int broj_pregleda(pregledi.DajBrojPregleda());
			std::cin.ignore(10000, '\n');
			std::cout << "Unesite ime pacijenta: "; std::getline(std::cin, ime); 
			pregledi.ObrisiPregledePacijenta(ime); 
			std::cout << "Uspjesno obrisano "<< broj_pregleda - pregledi.DajBrojPregleda() << " pregleda\n"; 
			option(pregledi); break; 
		}
		case 4: { 
			try { pregledi.ObrisiNajranijiPregled(); std::cout << "Najraniji pregled uspjesno obrisan\n"; }
			catch(std::range_error& e) { std::cout << e.what() << std::endl; }
			option(pregledi); break; 	
		}
		case 5: {
			BrojPregledaNaDatum(pregledi, true); 
			option(pregledi); break; 
		}
		case 6: {
			pregledi.IspisiSvePreglede();
			option(pregledi); break; 
		}
		default: return;
	}
}

/// main program logic
int main() {
	try {
		Pregledi pregledi;
		int d, m, g, sati, minuti; 
		std::string ime, check;
		for(;;) {
			check = ime = "";
			std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: "; std::getline(std::cin, ime);
			std::copy_if(ime.begin(), ime.end(), std::back_inserter(check), [](const char& _c) { return _c != ' '; });
			if(check == "kraj") break;
			std::cout << "Unesite dan mjesec i godinu pregleda: "; 
			for(;;) {
				std::cin >> d >> m >> g;
				try { 
					if (!std::cin) { ResetujUlaz("Pogresan unos, unesite ponovo!"); continue; }
					Datum dat(d, m, g); break; 
				} 
				catch (std::domain_error& e) { std::cout << e.what() << std::endl; }
			}
			std::cout << "Unesite sate i minute pregleda: "; 
			for(;;) {
				std::cin >> sati >> minuti;
				try { 
					if (!std::cin) { ResetujUlaz("Pogresan unos, unesite ponovo!"); continue; }
					Vrijeme t(sati, minuti); break; 
				} 
				catch (std::domain_error& e) { std::cout << e.what() << std::endl; }
			}
			std::cin.ignore(10000, '\n');
			pregledi.RegistrirajPregled(ime, {d, m, g}, {sati, minuti});
		}
		std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
		pregledi.IspisiSvePreglede();
		
		option(pregledi);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}