#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

/*Fje za alokacije, te ispis u mainu su podijeljeni na dva dijela, tj dvije verzije:
ako je slijed brojeva u vektoru periodican i ako on nije periodican.

Takodjer, dio fje za alokaciju, te ispis, upisivanje elemenata su podijeljeni na
dva dijela: do duzine vektora(broja elemenata) i na produzenje vektora.*/

template <typename CjelobrojniTip>
bool ProvjeraPerioda(std::vector<CjelobrojniTip> v, int p)
{
	if(p<=0 || p>=v.size()) return false;
	for(int i=0; i<v.size()-p; i++)
		if(v.at(i)!=v.at(i+p)) return false;
	return true;
}

template <typename CjelobrojniTip>
int OdrediPeriod(std::vector<CjelobrojniTip> v)
{
	for(int i=0; i<v.size(); i++)
		if(ProvjeraPerioda(v,i)) return i;
	return 0;
}

template <typename CjelobrojniTip>
CjelobrojniTip **AlocirajFragmentirano (const std::vector<CjelobrojniTip> &v,int &koliko_puta)
{
	bool nije_periodican(false);
	for(const auto &x: v)
		if(x<=0) throw std::domain_error("Neispravan vektor!");					//neki el ima besmislenu vrijednost
	if(v.size()==0) throw("Prazan vektor!");
	int osnovni_period(OdrediPeriod(v));										//provjera da li je slijed periodican
	int nova_duzina(0);
	if(osnovni_period!=0) {
		int duzina(v.size());
		while(duzina%osnovni_period!=0) duzina++;
		koliko_puta=duzina/osnovni_period;
	} else {
		osnovni_period=v.size();
		koliko_puta=2;
		nije_periodican=true;
	}
	nova_duzina=osnovni_period*koliko_puta;
	CjelobrojniTip max_element(v.at(0));
	for(auto x: v) if(x>max_element) max_element=x;
	CjelobrojniTip **matrica(nullptr);											//pocetak dinamicke alokacije
	try {
		matrica=new CjelobrojniTip*[nova_duzina];
		for(int i=0; i<nova_duzina; i++) matrica[i]=nullptr;					//Sada je sve osigurano na nullptr
		for(int i=0; i<v.size(); i++)
			matrica[i]=new CjelobrojniTip[v.at(i)];
		if(nije_periodican) {
			int brojac(0);
			for(int i=v.size(); i<nova_duzina; i++) {
				matrica[i]=new CjelobrojniTip[v.at(brojac)];
				brojac++;
			}

			for(int i=0; i<v.size(); i++) {
				for(int j=0; j<v.at(i); j++)
					matrica[i][j]=max_element-v.at(i)+j+1;						//upisivanje elemenata
			}

			brojac=0;
			for(int i=v.size(); i<nova_duzina; i++) {
				int element(v.at(brojac));
				for(int j=0; j<element; j++)
					matrica[i][j]=max_element-v.at(brojac)+j+1;					//upisivanje elemenata
				brojac++;
			}
		} else {
			int indeks(0);
			//trazenje indeksa el sa kojim ce poceti periodicno produzenje
			for(int i=0; i<v.size()-1; i++)
				if(v.at(i)==v.at(v.size()-1)) {
					indeks=i+1;
					break;
				}

			int pomocni_indeks(indeks);
			for(int i=v.size(); i<nova_duzina; i++) {
				matrica[i]=new CjelobrojniTip[v.at(pomocni_indeks)];
				pomocni_indeks++;
			}

			for(int i=0; i<v.size(); i++) {
				for(int j=0; j<v.at(i); j++)
					matrica[i][j]=max_element-v.at(i)+j+1;						//upisivanje elemenata
			}

			pomocni_indeks=indeks;
			for(int i=v.size(); i<nova_duzina; i++) {
				for(int j=0; j<v.at(indeks); j++)
					matrica[i][j]=max_element-v.at(pomocni_indeks)+j+1;			//upisivanje elemenata
				pomocni_indeks++;
			}
		}

		return matrica;
	} catch (std::bad_alloc) {
		for(int i=0; i<nova_duzina; i++) delete[] matrica[i];					//brise se sve sto je do sada alocirano
		delete[] matrica;
		throw;																	//izuzetak se dalje proslijedi u main
	}
}

template <typename CjelobrojniTip>
CjelobrojniTip **AlocirajKontinualno (const std::vector<CjelobrojniTip> &v, int &koliko_puta)
{
	for(const auto &x: v)
		if(x<=0) throw std::domain_error("Neispravan vektor!");
	if(v.size()==0) throw("Prazan vektor!");
	bool nije_periodican(false);
	int osnovni_period(OdrediPeriod(v));
	int nova_duzina(0);

	if(osnovni_period!=0) {														//provjera da li je slijed periodican
		int duzina(v.size());
		while(duzina%osnovni_period!=0) duzina++;
		koliko_puta=duzina/osnovni_period;
	} else {
		osnovni_period=v.size();
		koliko_puta=2;
		nije_periodican=true;
	}

	int broj_elemenata(0);
	for(int i=0; i<osnovni_period; i++) broj_elemenata+=v.at(i);
	broj_elemenata*=koliko_puta;

	nova_duzina=koliko_puta*osnovni_period;

	CjelobrojniTip **matrica(nullptr);
	matrica=new CjelobrojniTip*[nova_duzina];									//pocetak dinamicke alokacije
	try {
		int indeks(0), pomocni_indeks(0);
		if(nije_periodican==false)
			for(int i=0; i<v.size()-1; i++) {
				if(v.at(i)==v.at(v.size()-1)) {
					indeks=i+1;
					break;
				}
			}

		pomocni_indeks=indeks;
		for(int i=v.size(); i<nova_duzina; i++) {
			broj_elemenata+=v.at(pomocni_indeks);
			pomocni_indeks++;
		}

		matrica[0]=nullptr;
		matrica[0]=new CjelobrojniTip[broj_elemenata];

		if(nije_periodican) {													//poslani slijed nije periodican
			int brojac=0;
			for(int i=1; i<nova_duzina; i++) {
				if(brojac==osnovni_period) brojac=0;
				matrica[i]=matrica[i-1]+v[brojac];
				brojac++;
			}

			brojac=0;
			for(int i=0; i<v.size(); i++) { 									//elementi se upisuju
				for(int j=0; j<v.at(brojac); j++)
					matrica[i][j]=v.at(brojac)-j;
				brojac++;
			}

			brojac=0;
			for(int i=v.size(); i<nova_duzina; i++) {
				for(int j=0; j<v.at(brojac); j++)
					matrica[i][j]=v.at(brojac)-j;
				brojac++;
			}
		} else {																//poslani slijed brojeva je periodican
			for(int i=1; i<v.size(); i++)
				matrica[i]=matrica[i-1]+v.at(i-1);

			pomocni_indeks=indeks-1;
			for(int i=v.size(); i<nova_duzina; i++) {
				matrica[i]=matrica[i-1]+v.at(pomocni_indeks);
				pomocni_indeks++;
			}

			int brojac(0);
			for(int i=0; i<v.size(); i++) {
				for(int j=0; j<v.at(brojac); j++)
					matrica[i][j]=v.at(brojac)-j;
				brojac++;
			}

			pomocni_indeks=indeks;
			for(int i=v.size(); i<nova_duzina; i++) {
				for(int j=0; j<v.at(pomocni_indeks); j++)
					matrica[i][j]=v.at(pomocni_indeks)-j;
				pomocni_indeks++;
			}
		}

		return matrica;

	} catch (std::bad_alloc) {
		delete[] matrica[0];
		delete[] matrica;
		throw;
	}
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> uneseni_vektor(broj_elemenata);
	for(int i=0; i<broj_elemenata; i++)
		std::cin>>uneseni_vektor.at(i);
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alokacija;
	std::cin>>alokacija;
	int koliko_puta(0);

	try {
		int** matrica(nullptr);
		if(alokacija==1) {
			matrica=AlocirajFragmentirano(uneseni_vektor, koliko_puta);
		} else {
			matrica=AlocirajKontinualno(uneseni_vektor, koliko_puta);
		}
		std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
		int osnovni_period(OdrediPeriod(uneseni_vektor));
		bool nije_periodican(false);
		if(osnovni_period==0) {
			osnovni_period=uneseni_vektor.size();
			nije_periodican==true;
		}
		if(nije_periodican) {													//ispis ako slijed nije periodican
			for(int i=0; i<uneseni_vektor.size(); i++) {
				for(int j=0; j<uneseni_vektor.at(i); j++)
					std::cout<<std::setw(3)<<std::left<<matrica[i][j];
				std::cout<<std::endl;
			}

			int brojac(0);
			for(int i=uneseni_vektor.size(); i<2*osnovni_period; i++) {
				int element(uneseni_vektor.at(brojac));
				for(int j=0; j<element; j++)
					std::cout<<std::setw(3)<<std::left<<matrica[i][j];
				std::cout<<std::endl;
				brojac++;
			}
		} else {																//ispis ako je slijed brojeva periodican
			int indeks(0);
			for(int i=0; i<uneseni_vektor.size()-1; i++)
				if(uneseni_vektor.at(i)==uneseni_vektor.at(uneseni_vektor.size()-1)) {
					indeks=i+1;
					break;
				}

			for(int i=0; i<uneseni_vektor.size(); i++) {
				for(int j=0; j<uneseni_vektor.at(i); j++)
					std::cout<<std::setw(3)<<std::left<<matrica[i][j];
				std::cout<<std::endl;
			}

			for(int i=uneseni_vektor.size(); i<koliko_puta*osnovni_period; i++) {
				for(int j=0; j<uneseni_vektor.at(indeks); j++)
					std::cout<<std::setw(3)<<std::left<<matrica[i][j];
				indeks++;
				std::cout<<std::endl;
			}
		}
		if(alokacija==1) {														//brisanje fragmentirano alocirane matrice
			for(int i=0; i<koliko_puta*osnovni_period; i++) delete[] matrica[i];
			delete [] matrica;
		} else {																//brisanje kontinualno alocirane matrice
			delete[] matrica[0];
			delete[] matrica;
		}
	} catch (const char poruka[]) {												//hvatanje svih mogucih izuzetaka
		std::cout<<"Izuzetak: "<<poruka;
	} catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}