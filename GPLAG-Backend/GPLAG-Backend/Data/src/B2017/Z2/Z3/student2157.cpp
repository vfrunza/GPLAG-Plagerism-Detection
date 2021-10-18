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
#include <string>
#include <iomanip>

void Periodicnost(std::vector<int> V, int &p){
	bool periodican;
	for(int i = 1; i < V.size(); i++){
		periodican = true;
		for(int j = 0; j < V.size(); j++){
			if(i+j==V.size()){p=i;return;}
			if(V.at(j) != V.at(j + i)){
				periodican = false;
				break;
			}
		}
		if(periodican){ p = i; return;}
	}
}

bool DaLiImaSmisla(std::vector<int> V){
	for(int i = 0; i < V.size(); i++){
		if(V.at(i) <= 0) return false;
	}
	return true;
}

int **AlocirajFragmentirano(const std::vector<int> &V, int &koliko_puta){
	if(!DaLiImaSmisla(V)) throw std::domain_error("Neispravan vektor!");
	if(V.size() == 0) throw ("Prazan vektor! ");
	int p = 0;
	Periodicnost(V, p);
	
	if(p == 0){
		p = V.size();
		koliko_puta = 2;
	}
	else if(V.size() % p == 0) koliko_puta = V.size()/p;
	else  koliko_puta = int(V.size() / p + 1);
	
	int nesto = koliko_puta * p;
	int **pokazivac(new int *[nesto]);
	int j = 0;
	for(int i = 0; i < nesto; i++){
			pokazivac[i] = new int [V.at(j) + 1];
			j++;
			if(j == p) j = 0;
	}
    
	//popunjavanje
	int k = 0;
	for(int i  = 0; i < nesto; i++){
		int nezz(0);
		for(int j = V.at(k) - 1; j >= 0; j--){
			pokazivac[i][j] = p - nezz;
			nezz++;
		}
		k++;
		if(k == p) k = 0;
	}
	return pokazivac;
}

int **AlocirajKontinualno(const std::vector<int> &V, int &koliko_puta){
	if(!DaLiImaSmisla(V)) throw std::domain_error("Neispravan vektor!");
	if(V.size() == 0) throw ("Prazan vektor!");
	int p = 0;
	Periodicnost(V, p);
	if(p == 0){
		p = V.size();
		koliko_puta = 2;
	}
	else if(V.size() % p == 0) koliko_puta = V.size()/p;
	else koliko_puta = int(V.size() / p + 1);
	int **pok(new int *[koliko_puta * p]);
	int k = 0;
	int suma(0);
	for(int i = 0; i < p; i++){
		suma += V.at(i);
	}
	suma *= koliko_puta;
	pok[0] = new int[suma];
	for(int i = 1; i < koliko_puta * p; i++){
		pok[i] = pok[i - 1] + V.at(k);
		k++;
		if(k == p) k = 0;
	}
	//popunjavanje
	k = 0;
	int nesto(koliko_puta*p);
	for(int i  = 0; i < nesto; i++){
		int nezz=1;
		for(int j = V.at(k)-1; j >=0; j--){
			pok[i][j] =nezz; 
			nezz++;
		}
		k++;
		if(k == p) k = 0;
	}
	return pok;
}


int main ()
{
	try{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> V(n);
	for(int i = 0; i < n; i++){
		std::cin>>V.at(i);
	}
	int opcija;
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin>>opcija;
	int koliko_puta;
	int **pok;
	if(opcija == 1) pok = AlocirajFragmentirano(V, koliko_puta);
	else pok = AlocirajKontinualno(V, koliko_puta);
	std::cout<<"Dinamicki alocirana matrica: \n";
	int p = 0;
	Periodicnost(V, p);
	if(p == 0){
		p = V.size();
		koliko_puta = 2;
	}
	int koliko = p * koliko_puta;
	int k = 0;
	for(int i = 0; i < koliko; i++){
		for(int j = 0; j < V.at(k); j++){
			std::cout<<std::setw(3)<<std::left<<pok[i][j];
			
		}
		k++; 
		if(k == p) k = 0;
		std::cout<<std::endl;
	}
	if(opcija == 1){
	for(int i = 0; i < koliko; i++){
		delete[] pok[i];
	}
	delete[] pok;
	}
	else{
		delete[] pok[0]; delete[] pok;
	}
	
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	catch(std::bad_alloc){
		std::cout<<"Izuzetak: Problemi sa memorijom! ";
	}
	catch(const char poruka[]){
		std::cout<<"Izuzetak: "<<poruka;
	}

	return 0;
}