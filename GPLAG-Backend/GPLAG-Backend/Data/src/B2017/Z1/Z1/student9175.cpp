/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>

class Tim
{
	char ime_tima[20];
	int bo,bn,bp; //broj odigranih, broj nerijesenih, broj pobjeda
	int bpor, bdat, bprim, bpoena; // brojporaza, brojdatih, brojprimljenih, broj poena

public:
	Tim (const char ime []) {
		int brojac=std::strlen(ime);
		if(brojac>20) throw std::range_error("Predugacko ime tima");
		std::strcpy(ime_tima, ime);
		bo=0;
		bn=0;
		bp=0;
		bpor=0;
		bdat=0;
		bprim=0;
		bpoena=0;
	}
	void ObradiUtakmicu(int brojdat, int brojprim) {
		if(brojdat<0 || brojprim<0) throw std::range_error("Neispravan broj golova");

		bo++;
		bdat+=brojdat;
		bprim+=brojprim;
		if(brojdat<brojprim) bpor++;
		else if(brojdat==brojprim) {
			bn++;
			bpoena+=1;
		} else {
			bp++;
			bpoena+=3;

		}
	}
		const char *DajImeTima() const {
			return ime_tima;
		}
		int DajBrojPoena() const {
			return bpoena;
		}
		int DajGolRazliku() const {
			return (bdat-bprim);
		}
		void IspisiPodatke() const {
			std::cout << std::setw(20)<<std::left<<ime_tima<< std::setw(4)<<std::right<<
			          bo<<std::setw(4)<<std::right<< bp<<std::setw(4)<<std::right<< bn<< std::setw(4)<<std::right<<bpor<<
			          std::setw(4)<<std::right<< bdat<<std::setw(4)<<std::right<< bprim<< std::setw(4)<<std::right<<bpoena<< std::endl;
		}
	};

class Liga {
	int brt;
	const int maxbrt;
	Tim **timo;
public:
	explicit Liga(int velicina_lige);
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga(){
		for(int i(0);i<brt;i++) delete timo[i];
		delete [] timo;
	}
	Liga (const Liga &l);
	Liga (Liga &&l);
	Liga &operator = (const Liga &l);
	Liga &operator = (Liga && l);
	void DodajNoviTim(const char ime_tima []);
	void RegistrirajUtakmicu (const char tim1[], const char tim2[], int rez1, int rez2);
	void IspisiTabelu();
	static bool Kriterij(const Tim *tim1, const Tim *tim2);
};


int main ()
{
	Liga l1{"Celik", "Borac", "Jedinstvo", "Zeljeznicar", "Zrinjski", "Sarajevo"};
	l1.RegistrirajUtakmicu("Sarajevo", "Zeljeznicar", 5, 0);
	Liga l2(l1);
	std::cout << "Liga 1: " << std::endl;
	l1.IspisiTabelu();
	std::cout << "Liga 2(kopija l1): " << std::endl;
	l2.IspisiTabelu();
	Liga l3{"Celik", "Borac", "Jedinstvo", "Zeljeznicar", "Zrinjski", "Sarajevo"};
	Liga l4{"barca", "real", "iuventus", "chelsea", "manchester", "liverpool"};
	l3.RegistrirajUtakmicu("Sarajevo", "Zeljeznicar", 3,1);
	l3.RegistrirajUtakmicu("Sarajevo", "Jedinstvo", 3,0);
	l3.RegistrirajUtakmicu("Borac", "Jedinstvo", 1,2);
	l3.RegistrirajUtakmicu("Zrinjski", "Borac",0,2);
	
	std::cout << "Liga l3: " << std::endl;
	l3.IspisiTabelu();
	std::cout << "Liga l4: " << std::endl;
	l4.IspisiTabelu();
	l4=l3;
	std::cout << "Liga l4 sada je (kopija l3): " << std::endl;
	l4.IspisiTabelu();
	
	return 0;
}



Liga::Liga(int velicina_lige):maxbrt(velicina_lige), brt(0), timo(new Tim*[velicina_lige]){
	for(int i(0);i<maxbrt;i++) timo[i]=nullptr;
}
Liga::Liga(std::initializer_list<Tim> lista_timova):maxbrt(lista_timova.size()), brt(lista_timova.size()){
		timo=new Tim *[lista_timova.size()];
		int br(0);
		for(auto i=lista_timova.begin(); i!=lista_timova.end();i++){
			timo[br]=new Tim(*i);
			br++;
		}
}

Liga::Liga (const Liga &l): maxbrt(l.maxbrt), brt(l.brt), timo(new Tim*[l.maxbrt]){
	for(int i(0);i<l.brt;i++) timo[i]=new Tim (*l.timo[i]);
}

Liga::Liga(Liga &&l): maxbrt(l.maxbrt), brt(l.brt){
	timo=l.timo;
	l.brt=0;
	l.timo=nullptr;
}
Liga &Liga::operator = (const Liga &l){
	if(l.maxbrt!=maxbrt) throw std::logic_error("Nesaglasni kapaciteti liga");
	if(&l!=this){
		for(int i(0);i<brt;i++) delete timo[i];
		for(int i(0);i<l.brt;i++) timo[i]=new Tim(*l.timo[i]);
		brt=l.brt;
	}
	
	return *this;
}

Liga &Liga::operator= (Liga &&l){
	if(l.maxbrt!=maxbrt) throw std::domain_error("Nesaglasni kapaciteti liga");
	if(&l != this){
		for(int i(0);i<brt;i++) delete timo[i];
		timo=l.timo;
		brt=l.brt;
		l.timo=nullptr;
		l.brt=0;
	}
	return *this;
}

void Liga::DodajNoviTim(const char ime_tima[]){
	if(brt==maxbrt) throw std::range_error("Liga popunjena");
	timo[brt++]=new Tim(ime_tima);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rez1, int rez2){
	if(rez1<0 || rez2<0) throw std::range_error("Neispravan broj golova");
	int p1(-1), p2(-1);
	
	
	for(int i(0);i<brt;i++) {
		if(strcmp(tim1, timo[i]->DajImeTima())==0) p1=i;
		if(strcmp(tim2,timo[i]->DajImeTima())==0) p2=i;
	}
	
	if(p2>-1 && p1>-1) {
		timo[p1]->ObradiUtakmicu(rez1,rez2);
		timo[p2]->ObradiUtakmicu(rez2,rez1);
	}
	else throw std::logic_error("Tim nije nadjen");
}

void Liga::IspisiTabelu(){
	std::sort(timo, timo+brt, Kriterij);
	for(int i(0); i<brt;i++) timo[i]->IspisiPodatke();
}

bool Liga::Kriterij(const Tim *tim1, const Tim *tim2){
	if(tim1->DajBrojPoena()== tim2->DajBrojPoena()) return tim1->DajGolRazliku() > tim2->DajGolRazliku();
	return tim1->DajBrojPoena() > tim2->DajBrojPoena();

int main ()
{
	return 0;
}