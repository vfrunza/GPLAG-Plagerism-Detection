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
#include <cmath>
#include <new>
#include <memory>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
bool DaLiJePeriodican (const std::vector<Tip> v, int p)
{
	for (int i(0); i<v.size(); i++) {
		if (p<1 || p>=v.size()) return false;
		if (i+p>=v.size()) break;
		if(v.at(i) != v.at(i+p)) return false;
	}
	
	return true;
}

template <typename Tip>
int OdrediPeriod (std::vector<Tip> v, bool &periodicnost) {
	int p(0);
	for (int i(0); i<v.size(); i++) {
		if (DaLiJePeriodican(v, i)) {
			p=i;
			periodicnost=true;
			return p;
		}
	}
	periodicnost=false;
	return p;
}

template <typename Tip>
int BrojElemenata (std::vector <Tip> v) {
	int suma(0);
	for (int i (0); i<v.size(); i++) {
		suma += v.at(i);
	}
	return suma;
}

template <typename Tip>
int MaxElement(std::vector<Tip> v) {
	int max_element(v.at(0));
	for (int i(0); i<v.size(); i++) {
		if (v.at(i)>max_element) max_element=v.at(i);
		}
		
		return max_element;
}

template <typename Tip>
Tip **AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta)
{
	int periodPonavljanja(0);
	int brojElemenata=v.size();
	if (v.size()==0) throw std::domain_error("Prazan vektor!");
	for (int i(0); i < brojElemenata; i++) {
		if (v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
	}
	Tip **a=nullptr;
	int max_element(MaxElement(v));
	try {
		//a = new Tip* [brojElemenata];
		bool periodicnost;
		periodPonavljanja = OdrediPeriod(v, periodicnost);
		if (periodicnost) a=new Tip* [brojElemenata];
		else a=new Tip* [brojElemenata*2];
		if (periodicnost) {
			// Za cijeli broj ponavljanja
			if (brojElemenata % periodPonavljanja == 0) {
				koliko_puta = brojElemenata / periodPonavljanja;
				for (int i(0); i < brojElemenata; i++) {
					//if (v.at(i) <=0) throw std::domain_error ("Neispravan vektor!");
					a[i] = new Tip[v.at(i)];
					int k(max_element);
					for (int j=0; j<v.at(i); j++) {
						if (v.at(i)==1) a[i][j]=k;
						else {
						  a[i][j]=k-v.at(i)+1;
						  k++;
							
						}
					}

				}

			}
			
			else {
				koliko_puta = (brojElemenata / periodPonavljanja) + 1;
				for (int i(0); i < brojElemenata; i++) {
					a[i] = new Tip[v.at(i)];
					int k(max_element);
					for (int j=0; j<v.at(i); j++){
						 if (v.at(i)==1) a[i][j] = max_element;
						else  {
							a[i][j]=k-v.at(i)+1;
							k++;
						}
					}
				}
				int dodatno = koliko_puta * periodPonavljanja - brojElemenata;
				int brojac(0);
				int brElemenataDaPopuni = brojElemenata-dodatno;
				for (int i=brojac; i<dodatno; i++){
					a[i] = new Tip[v.at(brElemenataDaPopuni)];
					int k(max_element);
					for (int j=0; j<=v.at(brElemenataDaPopuni); j++) {
						if (v.at(brElemenataDaPopuni)==1) a[i][j] = max_element;
						 else {
						 	a[i][j]=k-v.at(brElemenataDaPopuni);
						 	k++;
						 }
					}
					
					brElemenataDaPopuni++;
				}
			}

		}
		else {
			koliko_puta=2; 
			for (int i(0); i<v.size(); i++) {
				a[i]=new Tip[v.at(i)];
				int k(max_element);
				for (int j(0); j<v.at(i); j++){ 
					if (v.at(i)==1) a[i][j]=max_element;
					else {
						a[i][j]=k-v.at(i)+1;
						k++;
					}
				}
			}
			
			for (int i(0); i<v.size(); i++){
				a[i+brojElemenata]= new Tip[v.at(i)];
				int k(max_element);
				for (int j(0); j<v.at(i); j++){
					if (v.at(i)==1) a[i][j]=max_element;
					else {
						a[i][j]=k-v.at(i)+1;
						k++;
					}
				}
			}
		}
	}

	catch (...) {
		for (int i(0); i<brojElemenata; i++) delete[] a[i];
		delete[] a;
		throw ;
		//if (v.size()==0) throw std::domain_error("Prazan vektor!");
		//else throw std::domain_error("Neispravan vektor!");
	}
	return a;

}


template <typename Tip>
Tip **AlocirajKontinualno (const std::vector<Tip> &v, int &koliko_puta){
	
	int periodPonavljanja(0);
	int brojElemenata=v.size();
	if (v.size()==0) throw std::domain_error ("Prazan vektor!");
	for (int i(0); i<v.size(); i++) {
		if (v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
	}
	Tip **a=nullptr;
	try {

		int BrojUkupnihElemenata(BrojElemenata(v));
		a=new Tip*[v.size()]{};
		a[0] = new Tip[BrojUkupnihElemenata]{};
		bool periodicnost;
		periodPonavljanja = OdrediPeriod(v, periodicnost);
		if (periodicnost){
			if (brojElemenata % periodPonavljanja ==0) {
				koliko_puta = brojElemenata / periodPonavljanja;
				for (int i(0); i < brojElemenata; i++){
					a[i] = a[i-1] + v.at(i);
				}
				
				for (int i(0); i<v.size(); i++) {
					int k(v.at(i));
					for (int j=0; j<=v.at(i); j++){
						a[i][j]=k;
						k--;
					}
				}
			}
		}
		
	}
	
	catch (...) {
		if (a!=nullptr) {
			delete a[0];
		}
		delete[] a;
		throw ;
	}
	return a;
}

int main ()
{
	int brojElemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> brojElemenata;
	std::vector<int> v(brojElemenata);
	int koliko(0);
	std::cout << "Unesite elemente vektora: ";
	for (int i(0); i<brojElemenata; i++) {
		double broj;
		std::cin >> broj;
		v.at(i) = broj;
	}
	//for (int i(0); i<brojElemenata; i++) std::cout<<v.at(i)<<" ";
	
	int **p=nullptr;
	int izbor;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> izbor;
	if (izbor  == 1) {
	try{
		p=AlocirajFragmentirano(v, koliko);
		std::cout << "Dinamicki alocirana matrica:\n";
		bool periodicnost;
		int k(0);
		int periodPonavljanja = OdrediPeriod(v, periodicnost);
		int dodatno = koliko * periodPonavljanja - brojElemenata;
		int brElemenataDaPopuni = brojElemenata-dodatno;
		if (periodPonavljanja!=0)
		{for (int i(0); i<brojElemenata; i++){
			for (int j(0); j<v.at(i); j++){
				std::cout << std::setw(3) << std::left << p[i][j];
			}
			std::cout << std::endl;
		}
		
		for (int i(0); i<dodatno; i++){
			for (int j=0; j<brElemenataDaPopuni-1; j++){
				std::cout <<  std::setw(3) << std::left << p[i][j];
			}
			std::cout << std::endl;
		}
		
		for (int i(0); i<brojElemenata; i++) delete[] p[i];
		delete[] p;
	}
	else {
		for (int i(0); i<brojElemenata; i++) {
			for (int j(0); j<v.at(i); j++){
				std::cout <<  std::setw(3) << std::left << p[i][j];
			}
			std::cout << std::endl;
		}
		
		for (int i(0); i<brojElemenata; i++){
			for (int j(0); j<v.at(i); j++) {
				std::cout << std::setw(3) << std::left<< p[i][j];
			}
			std::cout << std::endl;
		}
	}
	}
	catch (std::domain_error e){
		std::cout<<"Izuzetak: "<< e.what();
		/*for (int i(0); i<brojElemenata; i++) delete[] p[i];
		delete[] p; */
	} 
	}
	
	if (izbor==0) {
		try{
			p=AlocirajKontinualno(v, koliko);
			std::cout<<"Dinamicki alocirana matrica:\n";
			bool periodicnost;
			int k(0);
			int periodPonavljanja = OdrediPeriod(v, periodicnost);
			int dodatno = koliko * periodPonavljanja - brojElemenata;
			for (int i(0); i<brojElemenata; i++) {
				for (int j(0); j<=v.at(i)-1 ; j++){
					std::cout<<std::setw(3) << std::left << p[i][j] << " ";				
			}
			std::cout << std::endl;
		}
		
		delete[] p[0]; 
		delete[] p;
	}
	
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	
}
	return 0;
}