#include <iostream>
#include <tuple>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <set>
#include <ctime>

/*      Date class       */
class Datum {
private:
	std::tuple<int, int, int> datum;
	bool static isLeap(const int& g) { return ((g % 4 == 0) && (g % 100 != 0)) || (g % 400 == 0); }
	int static const daysInMonth(const int& m, const int &g) {
		const int broj_dana[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return broj_dana[m - 1] + (isLeap(g) && m == 2 ? 1 : 0);
	}
	void static validDate(const int& d, const int& m, const int& g) {
		if (g < 1 || d < 1 || m < 1 || m > 12 || d > daysInMonth(m, g)) throw std::domain_error("Neispravan datum");
	}
public:
	Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
	void Postavi(int dan, int mjesec, int godina) { validDate(dan, mjesec, godina), Datum::datum = std::make_tuple(dan, mjesec, godina); };
	std::tuple<int, int, int> Ocitaj() const { return this->datum; };
	void Ispisi() const;
	void incrementDate(bool increase = true);
	static bool dolaziPrijeDatum(const Datum& d1, const Datum& d2);
	static bool istiDatumi(const Datum& d1, const Datum& d2);
};

/*      Time class       */
class Vrijeme {
private:
	std::pair<int, int> vrijeme;
	void static validTime(const int& h, const int& m) {
		if (!(h >= 0 && h < 24) || !(m >= 0 && m < 60)) throw std::domain_error("Neispravno vrijeme");
	}
	void static printTime(const int& t) { std::cout << (t < 10 ? "0" : "") << t; }
public:
	Vrijeme(int sati, int minute) { Postavi(sati, minute); };
	void Postavi(int sati, int minute) { validTime(sati, minute), Vrijeme::vrijeme = std::make_pair(sati, minute); }
	std::pair<int, int> Ocitaj() const { return this->vrijeme; };
	void Ispisi() const;
	static bool dolaziPrijeVrijeme(const Vrijeme& t1, const Vrijeme& t2);
};

/*      Pregled class       */
class Pregled {
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
	static bool DolaziPrijePointer(const Pregled *p1, const Pregled *p2);
};

/*      Pregledi class       */
class Pregledi {
private:
	int size;
	int broj_evidentiranih;
	Pregled** pregledi;
	void checkSize() { if (broj_evidentiranih >= size) throw std::range_error("Dostignut maksimalni broj pregleda"); }
	void checkIfEmpty() { if (broj_evidentiranih == 0) throw std::range_error("Prazna kolekcija"); }
	void checkRegisteredPregled() const { if (broj_evidentiranih == 0) throw std::domain_error("Nema registriranih pregleda"); }
	Pregled* oldestDocument() const {
		return *std::min_element(pregledi, pregledi + broj_evidentiranih, Pregled::DolaziPrijePointer);
	}
	void deleteMember(const int& index) {
		if (size > index && index >= 0) delete pregledi[index], pregledi[index] = nullptr;
	}
	void rearrangeArray() {
		int _pos(0);
		for (int i(0); i < size; ++i) 
			if (pregledi[i] != nullptr) 
				pregledi[_pos++] = pregledi[i];
		
		while (_pos < size)
			pregledi[_pos++] = nullptr;
	}
	void ObrisiPodatke();
public:
	/// ctors and destructors
	explicit Pregledi(int max_broj_pregleda);
	Pregledi(std::initializer_list<Pregled> spisak_pregleda);
	~Pregledi();
	Pregledi(const Pregledi &pregledi);
	Pregledi(Pregledi &&pregledi);
	Pregledi &operator =(const Pregledi &pregledi);
	Pregledi &operator =(Pregledi &&pregledi);

	void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
	void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
		int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
	void RegistrirajPregled(Pregled* pregled);
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
Pregledi::Pregledi(int max_broj_pregleda) :
	size(max_broj_pregleda), broj_evidentiranih(0), pregledi(new Pregled*[max_broj_pregleda] {})
{ }
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) :
	size(spisak_pregleda.size()), broj_evidentiranih(0)
{
	try {
		pregledi = new Pregled*[spisak_pregleda.size()] {};
		for(auto it(spisak_pregleda.begin()); it != spisak_pregleda.end(); ++broj_evidentiranih, ++it) 
			pregledi[broj_evidentiranih] = new Pregled(*it); 
	} catch (...) {
		for(int i(0); i < broj_evidentiranih; ++i) delete pregledi[i], pregledi[i] = nullptr;
		delete [] pregledi; pregledi = nullptr;
		throw;
	}
}
Pregledi::~Pregledi() { this->ObrisiPodatke(); }
Pregledi::Pregledi(const Pregledi &pregledi) : size(pregledi.size), broj_evidentiranih(pregledi.broj_evidentiranih),
pregledi(new Pregled*[pregledi.broj_evidentiranih]{}) {
	try {
		for (int i(0); i < broj_evidentiranih; ++i)
			Pregledi::pregledi[i] = new Pregled(*pregledi.pregledi[i]);
	}
	catch (...) {
		this->ObrisiPodatke();
		throw;
	}
}
Pregledi::Pregledi(Pregledi &&pregledi) : size(pregledi.size), broj_evidentiranih(pregledi.broj_evidentiranih),
pregledi(pregledi.pregledi) {
	pregledi.pregledi = nullptr; pregledi.broj_evidentiranih = 0;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
	/// check max size
	Pregled** _newPregledi (nullptr);
	if (Pregledi::size != pregledi.size || Pregledi::broj_evidentiranih == 0) {
		try { _newPregledi = new Pregled*[pregledi.broj_evidentiranih]{}; }
		catch (...) { delete [] _newPregledi; _newPregledi = nullptr; throw; }
	}
	/// start copying
	if (broj_evidentiranih < pregledi.broj_evidentiranih) {
		try {
			for (int i(broj_evidentiranih); i < pregledi.broj_evidentiranih; ++i)
				_newPregledi[i] = new Pregled(*pregledi.pregledi[i]);
		}
		catch (...) {
			for (int i(broj_evidentiranih); i < pregledi.broj_evidentiranih; ++i) 
				delete _newPregledi[i], _newPregledi[i] = nullptr;
			throw;
		}
	}
	else {
		for (int i(pregledi.broj_evidentiranih); i < broj_evidentiranih; ++i) this->deleteMember(i);
	}
	/// copy other data
	int _upperBound(std::min(broj_evidentiranih, pregledi.broj_evidentiranih));
	for (int i(0); i < _upperBound; ++i) 
			*_newPregledi[i] = *pregledi.pregledi[i];
			
	this->ObrisiPodatke();
	std::swap(Pregledi::pregledi, _newPregledi); 
	Pregledi::broj_evidentiranih = pregledi.broj_evidentiranih;
	Pregledi::size = pregledi.size;
	return *this;
}
Pregledi& Pregledi::operator =(Pregledi &&pregledi) {
	this->ObrisiPodatke(); 
	std::swap(Pregledi::size, pregledi.size);
	std::swap(Pregledi::broj_evidentiranih, pregledi.broj_evidentiranih);
	std::swap(Pregledi::pregledi, pregledi.pregledi);
	pregledi.broj_evidentiranih = 0; pregledi.size = 0;
	return *this;
}
/// implementation of additional functions for registering
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
	this->checkSize(); /// check size
	try {
		pregledi[broj_evidentiranih] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
		++broj_evidentiranih;
	}
	catch (...) { this->deleteMember(broj_evidentiranih); }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
	int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
	this->checkSize(); /// check size
	try {
		pregledi[broj_evidentiranih] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
		++broj_evidentiranih;
	}
	catch (...) { this->deleteMember(broj_evidentiranih); }
}
void Pregledi::RegistrirajPregled(Pregled* pregled) {
	this->checkSize(); /// check size
	pregledi[broj_evidentiranih++] = pregled;
}
/// REMOVE DATA FROM Pregledi
void Pregledi::ObrisiPodatke() {
	for (int i(0); i < broj_evidentiranih; ++i) this->deleteMember(i);
	delete[] pregledi; pregledi = nullptr;
}
void Pregledi::IsprazniKolekciju() {
	for (int i(0); i < broj_evidentiranih; ++i) this->deleteMember(i);
	Pregledi::broj_evidentiranih = 0;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
	int _less(0);
	for (int i(0); i < broj_evidentiranih; ++i) {
		if (pregledi[i]->DajImePacijenta() == ime_pacijenta) {
			this->deleteMember(i);
			++_less;
		}
	}
	broj_evidentiranih -= _less;
	this->rearrangeArray();
}
void Pregledi::ObrisiNajranijiPregled() {
	this->checkIfEmpty();
	int _min(0);
	for(int i(0); i < broj_evidentiranih; ++i)
		if(Pregled::DolaziPrijePointer(pregledi[i], pregledi[_min]))
			_min = i;
	this->deleteMember(_min);
	broj_evidentiranih--;
	this->rearrangeArray();
}
/// INSPECTOR FUNCTIONS PREGLEDI
int Pregledi::DajBrojPregleda() const {
	return broj_evidentiranih;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
	return std::count_if(pregledi, pregledi + broj_evidentiranih, [&datum](const Pregled* p1) {
		return Datum::istiDatumi(p1->DajDatumPregleda(), datum);
	});
}
Pregled& Pregledi::DajNajranijiPregled() {
	this->checkRegisteredPregled();
	return *this->oldestDocument();
}
Pregled Pregledi::DajNajranijiPregled() const {
	this->checkRegisteredPregled();
	return *this->oldestDocument();
}

/// OUTPUT FUNCTIONS PREGLEDI
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
	auto compFunction = [this](const int& a, const int& b) -> bool {
		return (a < this->broj_evidentiranih && a >= 0) && (b < this->broj_evidentiranih && b >= 0) &&
			Pregled::DolaziPrijePointer(this->pregledi[a], this->pregledi[b]);
	};
	std::multiset<int, decltype(compFunction)> sorted (compFunction); /// ints in set to save space
	for(int i(0); i < broj_evidentiranih; ++i) 
		if(this->pregledi[i] != nullptr && Datum::istiDatumi(this->pregledi[i]->DajDatumPregleda(), datum)) 
			sorted.insert(i);
			
	for(auto it(sorted.begin()); it != sorted.end(); ++it)
		this->pregledi[*it]->Ispisi();
}
void Pregledi::IspisiSvePreglede() const {
	auto compFunction = [this](const int& a, const int& b) -> bool {
		return (a < this->broj_evidentiranih && a >= 0) && (b < this->broj_evidentiranih && b >= 0) &&
			Pregled::DolaziPrijePointer(this->pregledi[a], this->pregledi[b]);
	};
	std::multiset<int, decltype(compFunction)> sorted (compFunction);
	for(int i(0); i < broj_evidentiranih; ++i) sorted.insert(i);
	for(auto it(sorted.begin()); it != sorted.end(); ++it)
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
bool Pregled::DolaziPrijePointer(const Pregled *p1, const Pregled *p2) {
	return (p1 != nullptr && p2 != nullptr && Pregled::DolaziPrije(*p1, *p2));
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
	return Datum::dolaziPrijeDatum(p1.DajDatumPregleda(), p2.DajDatumPregleda()) || 
		(Datum::istiDatumi(p1.DajDatumPregleda(), p2.DajDatumPregleda()) && 
			Vrijeme::dolaziPrijeVrijeme(p1.DajVrijemePregleda(), p2.DajVrijemePregleda()));
}

/////////////////////////////// IMPLEMENTATION OF MAIN RW LOGIC
/// OPTION FUNCTIONS
void BrojPregledaNaDatum(Pregledi& pregledi, bool numbers = false) {
	static int d, m, g;
	for(;;) {
		std::cout << "Unesite dan mjesec i godinu : "; std::cin >> d >> m >> g;
		try { 
			Datum dat(d, m, g); 
			if(!numbers) 
				std::cout << "Broj pregleda na datum " << d << ' ' << m << ' ' << g << " je: " << pregledi.DajBrojPregledaNaDatum(dat);
			else {
				std::cout << "Pregledi na datum " << d << ' ' << m << ' ' << g << " su:\n";
				pregledi.IspisiPregledeNaDatum(dat);
			} std::cout << std::endl;
			break;
		} 
		catch (std::exception& e) { 
			if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
			std::cout << e.what() << std::endl; 
		}
	}
}

void option(Pregledi& pregledi, bool show_text = true) {
	static int choose;
	if(show_text) std::cout << "\nOdaberite jednu od sljedecih opcija\n\
1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n\
5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n"; 
	std::cin >> choose;
	if(!std::cin || choose < 1 || choose > 7) { 
		if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
		std::cout << "Greska: Unos nije validan!"; option(pregledi, false); 
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

/// create pregledi
Pregledi kreirajPreglede() {
	int max, d, m, g, sati, minuti; 
	std::cout << "Unesite maksimalan broj pregleda: "; std::cin >> max;
	
	Pregledi pregledi(max);
	std::string ime, check;
	for(int i(0); i < max; ++i) {
		check = ime = "";
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: "; std::getline(std::cin, ime);
		std::copy_if(ime.begin(), ime.end(), std::back_inserter(check), [](const char& _c) { return _c != ' '; });
		if(check == "kraj") break;
		for(;;) {
			std::cout << "Unesite dan mjesec i godinu pregleda: "; std::cin >> d >> m >> g;
			try { Datum dat(d, m, g); break; } 
			catch (std::domain_error& e) { 
				if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
				std::cout << e.what() << std::endl; 
			}
		}
		for(;;) {
			std::cout << "Unesite sate i minute pregleda: "; std::cin >> sati >> minuti;
			try { Vrijeme t(sati, minuti); break; } 
			catch (std::domain_error& e) { 
				if(!std::cin) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
				std::cout << e.what() << std::endl; 
			}
		}
		pregledi.RegistrirajPregled(ime, {d, m, g}, {sati, minuti});
	}
	std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
	pregledi.IspisiSvePreglede();
	
	return pregledi;
}

/// main program logic
int main() {
	try {
		Pregledi pregledi(kreirajPreglede());
		option(pregledi);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}