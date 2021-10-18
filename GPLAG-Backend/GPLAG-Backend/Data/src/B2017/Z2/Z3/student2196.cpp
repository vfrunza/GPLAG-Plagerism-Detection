/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
bool TestPreioda(std::vector<Tip> brojevi, int period){
	for(int i=0; i<int(brojevi.size())-period; i++)
		if(brojevi.at(i)!=brojevi.at(i+period)) return false;
	return true;
}

template <typename Tip>
int Period(std::vector<Tip> brojevi){
	for(int i=1; i<int(brojevi.size()); i++)
		if(TestPreioda(brojevi, i)) return i;
	return int(brojevi.size());
}

template <typename Tip>
Tip **AlocirajFragmentirano(const std::vector<Tip> &brojevi, int &koliko_puta) {
	if(brojevi.size()==0) throw ("Prazan vektor!");
	for(int i=0; i<int(brojevi.size()); i++) if(brojevi.at(i)<1) throw std::domain_error("Neispravan vektor!");
	int period(Period(brojevi));
	koliko_puta=int(brojevi.size())/period+1;
	if(int(brojevi.size())%period==0 && koliko_puta!=2) koliko_puta--;
	Tip max=brojevi.at(0);
	for(int i=0; i<int(brojevi.size()); i++) if(brojevi.at(i)>max) max=brojevi.at(i);
	try{
		Tip **matrica(new Tip* [koliko_puta*period]{});
		try{
			for(int i=0; i<koliko_puta*period; i++){
				int temp(i);
				while(temp>=period) temp-=period;
				matrica[i]=new Tip[*(brojevi.begin()+temp)];
				for(int j=0; j<*(brojevi.begin()+temp); j++){
					matrica[i][*(brojevi.begin()+temp)-1-j]=max-j;
				}
			}
			return matrica;
		}
		catch(std::bad_alloc){
			for(int i=0; i<koliko_puta*period; i++) delete[] matrica[i];
			delete[] matrica;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}
}

template <typename Tip>
Tip** AlocirajKontinualno(const std::vector<Tip> &brojevi, int &koliko_puta){
	if(brojevi.size()==0) throw ("Prazan vektor!");
	for(int i=0; i<int(brojevi.size()); i++) if(brojevi.at(i)<1) throw std::domain_error("Neispravan vektor!");
	int period(Period(brojevi)), suma(0);
	koliko_puta=int(brojevi.size())/period+1;
	if(int(brojevi.size())%period==0 && koliko_puta!=2) koliko_puta--;
	Tip** matrica(nullptr);
	for(int i=0; i<period; i++) suma+=brojevi.at(i);
	try{
		matrica = new Tip*[koliko_puta*period]{};
		*matrica = new Tip[suma*koliko_puta];
		for(int i=0; i<brojevi.at(0); i++) matrica[0][i]=brojevi.at(0)-i;
			for(int i=1; i<koliko_puta*period; i++){
			int temp(i-1);
			while(temp>=period) temp-=period;
			matrica[i]=matrica[i-1]+*(brojevi.begin()+temp);
			temp++;
			while(temp>=period) temp-=period;
			for(int j=0; j<*(brojevi.begin()+temp); j++){
				matrica[i][j]=*(brojevi.begin()+temp)-j;
			}
		}
		return matrica;
	}
	catch(std::bad_alloc){
		delete[] matrica;
		throw;
	}
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	try{
		std::vector<int> vektor(broj_elemenata);
		for(int i=0; i<broj_elemenata; i++)
			std::cin >> vektor.at(i);	
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int alokacija, koliko_puta;
		std::cin >> alokacija;
		if(alokacija==1){
			int** matrica(AlocirajFragmentirano(vektor, koliko_puta));
			int period(Period(vektor));
			std::cout << "Dinamicki alocirana matrica:\n";
			for(int i=0; i<period*koliko_puta; i++){
				int temp(i);
				while(temp>=period) temp-=period;
				for(int j=0; j<*(vektor.begin()+temp); j++){
					std::cout << std::left << std::setw(3) << matrica[i][j];
				}
				std::cout << std::endl;
			}
			for(int i=0; i<koliko_puta*period; i++) delete[] matrica[i];
			delete[] matrica;
		}
		else if(alokacija==0){
			int** matrica(AlocirajKontinualno(vektor, koliko_puta));
			int period(Period(vektor));
			std::cout << "Dinamicki alocirana matrica:\n";
			for(int i=0; i<period*koliko_puta; i++){
				int temp(i);
				while(temp>=period) temp-=period;
				for(int j=0; j<*(vektor.begin()+temp); j++){
					std::cout << std::left << std::setw(3) << matrica[i][j];
				}
				std::cout << std::endl;
			}
			delete[] *matrica;
			delete[] matrica;
		}
	}
	catch(const char s[]){
		std::cout << "Izuzetak: " << s << std::endl;
	}
	catch(std::domain_error e){
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	catch(...){	}
	return 0;
}