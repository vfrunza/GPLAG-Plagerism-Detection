/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>

#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<algorithm>
#include<cstring>
#include<vector>
#include<memory>
class Tim
{
	char ime_tima [20];
	int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza, broj_datih,broj_primljenih, broj_poena ;
public:

	Tim(const char ime[]) {
		int brojac(0);
		auto pom2(ime);
		while(*pom2++!='\0') {
			brojac++;
		}
		if(brojac>20) {
			throw std::range_error("Predugacko ime tima");
		}
		auto pom(ime_tima);
		while(*ime!='\0') {
			*pom=*ime;
			pom++;
			ime++;
		}
		*pom=*ime;
		broj_odigranih=0;
		broj_pobjeda=0;
		broj_nerijesenih=0;
		broj_poraza=0;
		broj_datih=0;
		broj_primljenih=0;
		broj_poena=0;
	}

	void ObradiUtakmicu(int broj_datih, int broj_primljenih) {
		if(broj_datih<0 || broj_primljenih<0) {
			throw std::range_error("Neispravan broj golova");
		}
		broj_odigranih++;
		if(broj_datih<broj_primljenih) {
			broj_poraza++;
		}
		if(broj_datih>broj_primljenih) {
			broj_pobjeda++;
			broj_poena+=3;
		}
		if(broj_datih==broj_primljenih) {
			broj_nerijesenih++;
			broj_poena++;
		}
		(*this).broj_datih+=broj_datih;
		(*this).broj_primljenih+=broj_primljenih;
	}

	const char *DajImeTima() const {
		return ime_tima;
	}

	int DajBrojPoena() const {
		return broj_poena;
	}
	int DajGolRazliku() const {
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke() const {
		std::cout <<std::left<<std::setw(20)<< DajImeTima()<<std::right<<std::setw(4)<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<broj_nerijesenih<<std::setw(4)<<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena<<std::endl;
	}


};

class Liga
{
	std::vector<std::shared_ptr<Tim>>timovi; // vektor pametnih pokazivaca na objekte tipa Tim
public:

	explicit Liga(std::initializer_list<Tim> lista_timova) { //lista se ne moze indexirati ...podrzava dvosmjerne iteratore...

		auto it(std::begin(lista_timova));
		while(it!=std::end(lista_timova) ) {
			timovi.push_back(std::make_shared<Tim>(*it++)); // u vektor pametnih pok ubacujemo adresse dinamicki alociranih objekata tipa Tim koji se odmah inicijalizuju;

		}
	}

	Liga(const Liga &l) {
		auto it(std::begin(l.timovi));
		while(it!=std::end(l.timovi) ) {
			timovi.push_back(std::make_shared<Tim>(**it++)); // u vektor pametnih pok ubacujemo adresse dinamicki alociranih objekata tipa Tim koji se odmah inicijalizuju;
		}
	}


	Liga &operator =(const Liga &l) {
		timovi.resize(0);
		auto it(std::begin(l.timovi));
		while(it!=std::end(l.timovi) ) {
			timovi.push_back(std::make_shared<Tim>(**it++)); // u vektor pametnih pok ubacujemo adresse dinamicki alociranih objekata tipa Tim koji se odmah inicijalizuju;
		}
		return *this;
	}

	Liga &operator =(Liga &&l) {
		if (&l!=this) {
			timovi = std::move(l.timovi);
		}
		return *this;
	}

	Liga (const Liga&&l) {
		timovi=std::move(l.timovi);
	}



	void DodajNoviTim(const char ime_tima[]) {
		for(int i=0; i<timovi.size(); i++) {
			if( strcmp(ime_tima,(*(timovi[i])).DajImeTima() )==0 ) {
				throw std::logic_error("Tim vec postoji");
			}
		}
		timovi.push_back(std::make_shared<Tim>(ime_tima));
	}


	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
		if(  std::find_if(std::begin(timovi), std::end(timovi), [tim1] (std::shared_ptr<Tim>t) {
		if(strcmp (tim1,(*t).DajImeTima() )==0 ) {
				return true;
			}
			return false;
		} ) == std::end(timovi) ) {
			throw std::logic_error("Tim nije nadjen");
		}
		if(  std::find_if(std::begin(timovi), std::end(timovi), [tim2] (std::shared_ptr<Tim>t) {
		if(strcmp (tim2,(*t).DajImeTima() )==0 ) {
				return true;
			}
			return false;
		} ) == std::end(timovi) ) {
			throw std::logic_error("Tim nije nadjen");
		}

		if(rezultat_1<0 || rezultat_2<0) {
			throw std::range_error("Neispravan broj golova");
		}
		auto pom= std::find_if( std::begin(timovi), std::end(timovi), [tim1] (std::shared_ptr<Tim>t) {
			if(strcmp (tim1,(*t).DajImeTima() )==0 ) {
				return true;
			}
			return false;
		} );
		auto pom1=  std::find_if( std::begin(timovi), std::end(timovi), [tim2] (std::shared_ptr<Tim>t) {
			if(strcmp (tim2,(*t).DajImeTima() )==0 ) {
				return true;
			}
			return false;
		} );
		(**pom).ObradiUtakmicu(rezultat_1,rezultat_2);
		(**pom1).ObradiUtakmicu(rezultat_2,rezultat_1);
	}

	void IspisiTabelu() {
		std::sort(std::begin(timovi),std::end(timovi), [] (std::shared_ptr<Tim>t1,std::shared_ptr<Tim>t2) {
			if( (*t1).DajBrojPoena()==(*t2).DajBrojPoena() && (*t1).DajGolRazliku()==(*t2).DajGolRazliku()) {
				if(strcmp( (*t1).DajImeTima(),(*t2).DajImeTima() )<0 ) return true;
			}

			if( (*t1).DajBrojPoena()==(*t2).DajBrojPoena()  ) {
				return (*t1).DajGolRazliku()>(*t2).DajGolRazliku() ;
			}
			return (*t1).DajBrojPoena()>(*t2).DajBrojPoena() ;
		});
		std::for_each(std::begin(timovi),std::end(timovi),[] (std::shared_ptr<Tim>t ) {
			(*t).IspisiPodatke();
		});
	}
};
int main ()
{

	return 0;
}
int main ()
{
	return 0;
}