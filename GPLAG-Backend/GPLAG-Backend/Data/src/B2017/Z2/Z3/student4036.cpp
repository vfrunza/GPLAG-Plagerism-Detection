/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
/*#include <iostream>
#include <vector>


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: " ;
	std::cin >> n;
	try{
		std::vector<int> v(n);
		for(int i=0; i<n; i++){
			int broj;
			std::cin >> broj;
			v.push_back(broj);
		}
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}*/


/*#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]) : broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0),
		broj_datih(0), broj_primljenih(0), broj_poena(0) {
		if (std::strlen(ime)>19) throw std::range_error("Predugacko ime tima");
		std::strcpy(ime_tima,ime);
	}
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const {
		return ime_tima;
	}
	int DajBrojPoena() const {
		return broj_poena;
	}
	int DajGolRazliku() const {
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke() const;
};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
	if (broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
	broj_odigranih++;
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenih+=broj_primljenih;
	if (broj_datih>broj_primljenih) {
		broj_pobjeda++;
		broj_poena+=3;
	} else if (broj_datih==broj_primljenih) {
		broj_nerijesenih++;
		broj_poena+=1;
	} else broj_poraza++;
}

void Tim::IspisiPodatke() const
{
	std::cout << std::setw(20) << std::left << ime_tima << std::setw(4) << std::right << broj_odigranih << std::setw(4) << std::right << broj_pobjeda
	          << std::setw(4) << std::right << broj_nerijesenih << std::setw(4) << std::right << broj_poraza << std::setw(4) << std::right << broj_datih
	          << std::setw(4) << std::right << broj_primljenih << std::setw(4) << std::right << broj_poena << std::endl;
}

class Liga
{
	int broj_timova;
	const int max_br_timova;
	Tim **timovi;
public:
	explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[max_br_timova] {}) {}
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	Liga &operator=(const Liga &l);
	Liga &operator=(Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};

Liga::Liga(std::initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(lista_timova.size()),
	timovi(new Tim*[lista_timova.size()] {})
{
	int i=0;
	for (auto it=lista_timova.begin(); it!=lista_timova.end(); it++) {
		try {
			timovi[i]=new Tim(*it);
			i++;
		} catch(std::bad_alloc) {
			for (int i=0; i<lista_timova.size(); i++) {
				delete timovi[i];
				timovi[i]=nullptr;
			}
			throw;
		}
	}
}

Liga::~Liga()
{
	for (int i=0; i<max_br_timova; i++) delete timovi[i];
	delete[] timovi;
}

Liga::Liga(const Liga &l): broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova] {})
{
	try {
		for (int i=0; i<l.broj_timova; i++)
			timovi[i]=new Tim(*l.timovi[i]);
	} catch(...) {
		for (int i=0; i<l.broj_timova; i++) delete timovi[i];
		delete[] timovi;
		throw;
	}
}

Liga::Liga(Liga &&l): broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(l.timovi)
{
	l.timovi=nullptr;
	l.broj_timova=0;
}

Liga &Liga::operator =(const Liga &l)
{
	if (l.max_br_timova!=max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
	if (l.broj_timova>broj_timova) {
		try {
			for (int i=broj_timova; i<l.broj_timova; i++)
				timovi[i]=new Tim(*l.timovi[i]);
		} catch(...) {
			for (int i=broj_timova; i<l.broj_timova; i++) {
				delete timovi[i];
				timovi[i]=nullptr;
			}
			throw;
		}
	} else {
		for (int i=l.broj_timova; i<broj_timova; i++) {
			delete timovi[i];
			timovi[i]=nullptr;
		}
	}
	broj_timova=l.broj_timova;
	for (int i=0; i<broj_timova; i++) *timovi[i]=*l.timovi[i];
	return *this;
}

Liga &Liga::operator=(Liga &&l)
{
	if (l.max_br_timova!=max_br_timova)
		throw std::logic_error("Nesaglasni kapaciteti liga");
	std::swap(broj_timova,l.broj_timova);
	std::swap(timovi,l.timovi);
	return *this;
}

void Liga::DodajNoviTim(const char ime_tima[])
{
	if (std::strlen(ime_tima)>19) throw std::range_error("Predugacko ime tima");
	if (broj_timova>=max_br_timova) throw std::range_error("Liga popunjena");
	for (int i=0; i<broj_timova; i++)
		if (std::strcmp(timovi[i]->DajImeTima(),ime_tima)==0) throw std::logic_error("Tim vec postoji");
	timovi[broj_timova++]=new Tim(ime_tima);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
	if (rezultat_1<0 || rezultat_2<0) throw std::range_error("Neispravan broj golova");
	bool pronadjen1(false), pronadjen2(false);
	for (int i=0; i<broj_timova; i++) {
		if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0) pronadjen1=true;
		if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0) pronadjen2=true;
	}
	if (!(pronadjen1 && pronadjen2))
		throw std::logic_error("Tim nije nadjen");
	for (int i=0; i<broj_timova; i++) {
		if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0)
			timovi[i]->ObradiUtakmicu(rezultat_1,rezultat_2);
		else if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0)
			timovi[i]->ObradiUtakmicu(rezultat_2,rezultat_1);
	}
}

void Liga::IspisiTabelu()
{
	std::sort(timovi,timovi+broj_timova,[](Tim *p_tim1, Tim *p_tim2) {
		if (p_tim1->DajBrojPoena()!=p_tim2->DajBrojPoena()) return p_tim1->DajBrojPoena()>p_tim2->DajBrojPoena();
		else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()!=p_tim2->DajGolRazliku()) return p_tim1->DajGolRazliku()>p_tim2->DajGolRazliku();
		else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()==p_tim2->DajGolRazliku()) return std::strcmp(p_tim1->DajImeTima(),p_tim2->DajImeTima())<0;
	});
	std::for_each(timovi,timovi+broj_timova,[](Tim *p_tim) {
		p_tim->IspisiPodatke();
	});
}

int main ()
{
	try {
		Liga liga {"Celik","Borac","Jedinstvo","Zeljeznicar","Zrinjski","Sarajevo"};
		do {
			liga.IspisiTabelu();
			char unos1[20], unos2[20];
			std::cout << std::endl << "Unesite ime prvog tima (ENTER za kraj): ";
			if (std::cin.peek()=='\n') return 0;
			std::cin.getline(unos1, sizeof unos1);
			std::cout << "Unesite ime drugog tima: ";
			std::cin.getline(unos2, sizeof unos2);
			int golovi1,golovi2;
			std::cout << "Unesite broj postignutih golova za oba tima: ";
			std::cin >> golovi1 >> golovi2;
			try {
				liga.RegistrirajUtakmicu(unos1,unos2,golovi1,golovi2);
			} catch(std::logic_error izuzetak) {
				std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
			} catch(std::range_error izuzetak) {
				std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
			}
			std::cout << std::endl;
			std::cin.ignore(10000,'\n');
		} while (1);
	} catch(std::bad_alloc) {
		std::cout << "Problemi sa memorijom!" << std::endl;
	}
	return 0;
}*/
/* 
   B16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <memory>

class Tim {
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]) : broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0),
		broj_datih(0), broj_primljenih(0), broj_poena(0) {
			if (std::strlen(ime)>19) throw std::range_error("Predugacko ime tima");
			std::strcpy(ime_tima,ime);
		}
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);	
	const char *DajImeTima() const { return ime_tima; }
	int DajBrojPoena() const { return broj_poena; }
	int DajGolRazliku() const { return broj_datih-broj_primljenih; }
	void IspisiPodatke() const;
}; 

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih) {
	if (broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
	broj_odigranih++;
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenih+=broj_primljenih;
	if (broj_datih>broj_primljenih) {
		broj_pobjeda++;
		broj_poena+=3;
	}
	else if (broj_datih==broj_primljenih) {
		broj_nerijesenih++;
		broj_poena+=1;
	}	
	else broj_poraza++;
}

void Tim::IspisiPodatke() const {
	std::cout << std::setw(20) << std::left << ime_tima << std::setw(4) << std::right << broj_odigranih << std::setw(4) << std::right << broj_pobjeda
	<< std::setw(4) << std::right << broj_nerijesenih << std::setw(4) << std::right << broj_poraza << std::setw(4) << std::right << broj_datih
	<< std::setw(4) << std::right << broj_primljenih << std::setw(4) << std::right << broj_poena << std::endl; 
}

class Liga {
	std::vector<std::shared_ptr<Tim>> timovi;
public:
	explicit Liga()=default;
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	Liga &operator =(const Liga &l);
	Liga &operator =(Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rez_1, int rez_2);
	void IspisiTabelu();
};

Liga::Liga(std::initializer_list<Tim> lista_timova) {
	for (auto it=lista_timova.begin(); it!=lista_timova.end(); it++) {
		try {	
			std::shared_ptr<Tim> p(new Tim(*it));
			timovi.push_back(p);
		}
		catch(std::bad_alloc) {
			for (int i=0; i<lista_timova.size(); i++)
				timovi[i]=nullptr;
			throw;
		}
	}
}

Liga::~Liga() {
	for (int i=0; i<timovi.size(); i++)
		timovi[i]=nullptr;
}

Liga::Liga(const Liga &l) {
	try {
		timovi.resize(l.timovi.size());
		for (int i=0; i<l.timovi.size(); i++) {
			std::shared_ptr<Tim> p(new Tim(*l.timovi[i]));
			timovi[i]=p;
		}
	}
	catch(std::bad_alloc) {
		for (int i=0; i<l.timovi.size(); i++)
			timovi[i]=nullptr;
		throw;
	}
}

Liga::Liga(Liga &&l) {
	timovi=std::move(l.timovi);
}

Liga &Liga::operator =(const Liga &l) {
	int stara_duzina=timovi.size();
	if (l.timovi.size()>timovi.size()) {
		try {
			for (int i=timovi.size(); i<l.timovi.size(); i++) {
				std::shared_ptr<Tim> p(new Tim(*l.timovi[i]));
				timovi.push_back(p);
			}
		}
		catch(std::bad_alloc) {
			for (int i=timovi.size(); i<l.timovi.size(); i++)
				timovi[i]=nullptr;
			timovi.resize(stara_duzina);
			throw;
		}
	}
	timovi.resize(l.timovi.size());
	for (int i=0; i<timovi.size(); i++) *timovi[i]=*l.timovi[i];
	return *this;
}

Liga &Liga::operator =(Liga &&l) {
	timovi=std::move(l.timovi);
	return *this;
}

void Liga::DodajNoviTim(const char ime_tima[]) {
	for (int i=0; i<timovi.size(); i++)
		if (std::strcmp(timovi[i]->DajImeTima(),ime_tima)==0)
			throw std::logic_error("Tim vec postoji");
	std::shared_ptr<Tim> p(new Tim(ime_tima));
	timovi.push_back(p);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
	if (rezultat_1<0 || rezultat_2<0) throw std::range_error("Neispravan broj golova");
	bool pronadjen1(false), pronadjen2(false);
	for (int i=0; i<timovi.size(); i++) {
		if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0) pronadjen1=true;
		if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0) pronadjen2=true;
	}
	if (!(pronadjen1 && pronadjen2))
		throw std::logic_error("Tim nije nadjen");
	for (int i=0; i<timovi.size(); i++) {
		if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0)
			timovi[i]->ObradiUtakmicu(rezultat_1,rezultat_2);
		else if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0)
			timovi[i]->ObradiUtakmicu(rezultat_2,rezultat_1);
	}
}

void Liga::IspisiTabelu() {
	std::sort(timovi.begin(),timovi.end(),[](std::shared_ptr<Tim> p_tim1, std::shared_ptr<Tim> p_tim2){
		if (p_tim1->DajBrojPoena()!=p_tim2->DajBrojPoena()) return p_tim1->DajBrojPoena()>p_tim2->DajBrojPoena();
		else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()!=p_tim2->DajGolRazliku()) return p_tim1->DajGolRazliku()>p_tim2->DajGolRazliku();
		else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()==p_tim2->DajGolRazliku()) return std::strcmp(p_tim1->DajImeTima(),p_tim2->DajImeTima())<0; });
	for (int i=0; i<timovi.size(); i++)
		timovi[i]->IspisiPodatke();
}

int main() {
	try {
		Liga liga{"Borac","Celik","Jedinstvo","Sarajevo","Zeljeznicar","Zrinjski"};
		do {
			liga.IspisiTabelu();
			char unos1[20], unos2[20];
			std::cout << std::endl << "Unesite ime prvog tima (ENTER za kraj): ";
			if (std::cin.peek()=='\n') return 0;
			std::cin.getline(unos1,sizeof unos1);
			std::cout << "Unesite ime drugog tima: ";
			std::cin.getline(unos2,sizeof unos2);
			int golovi1,golovi2;
			std::cout << "Unesite broj postignutih golova za oba tima: ";
			std::cin >> golovi1 >> golovi2;
			try {
				liga.RegistrirajUtakmicu(unos1,unos2,golovi1,golovi2);
			}
			catch(std::logic_error izuzetak) {
				std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
			}
			catch(std::range_error izuzetak) {
				std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
			}
			std::cout << std::endl;
			std::cin.ignore(10000,'\n');
		} while(1);
	}
	catch(std::bad_alloc) {
		std::cout << "Problemi sa memorijom!" << std::endl;
	}
	return 0;
}