#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

template <typename Tip>
int Period(const std::vector<Tip> v){
	int i, pokazivac = 0;
	for(i = 1; i < v.size(); i++){
		if(v.at(pokazivac) == v.at(i)){
			while(i < v.size() && v.at(pokazivac) == v.at(i)){
				i++;
				pokazivac++;
			}
			if(i < v.size()){
				pokazivac = 0;
				i--;
			}
			else if(i >= v.size()) break;
		}
	}
	return (i - pokazivac);
}


template <typename Tip>
int Periodicnost(std::vector<Tip> v, int &velicina, int &p){
	int i, pokazivac = 0;
	for(i = 1; i < v.size(); i++){
		if(v.at(pokazivac) == v.at(i)){
			while(i < v.size() && v.at(pokazivac) == v.at(i)){
				i++;
				pokazivac++;
			}
			if(i < v.size()){
				pokazivac = 0;
				i--;
			}
			else if(i >= v.size()) break;
		}
	}
	int period(i - pokazivac);
	p = period;
	
	if(period == v.size()){
		//Slucaj kada je potrebno dodati još jednom na vektor
		velicina = 2*v.size();
		return 2;
	}else if(v.size() % period != 0){
		//Ovdje moramo nadopuniti vektor kako bi bio periodičan do kraja
		velicina = v.size() + (period - (v.size() % period));
	}else if(v.size() % period == 0){
		velicina = v.size();
	}
	return (v.size() / period);
}

template <typename Tip>
int **AlocirajFragmentirano(const std::vector<Tip> &vektor, int &koliko_puta){
	//Provjera validnosti niza
	if(vektor.size() == 0) throw std::domain_error("Prazan vektor!");
	for(Tip a: vektor){
		if(a <= 0) throw std::domain_error("Neispravan vektor!");
	}
	//Provjeravamo da li je niz periodičan
	int velicina_vektora = 0;
	int period = 0;
	koliko_puta = Periodicnost(vektor, velicina_vektora, period);
	//Alociranje matrice
	try{
		int **a(new int*[velicina_vektora]{});
		//Alociranje redova
		try{
			for(int i = 0; i < velicina_vektora; i++){
				if(i < vektor.size()){
					a[i] = new int[vektor.at(i)];
				}else if(i >= vektor.size()){
					a[i] = new int[vektor.at(i - period)];
				}
			}
		}catch(...){
			for(int i = 0; i < velicina_vektora; i++){
				delete[] a[i];
			}
			delete[] a;
			throw;
		}
		//Popunjavanje matrice/Najveće zlo ikad
		int najveci = *(max_element(vektor.begin(),vektor.end()));
		int idi, broj;
		for(int i = 0; i < velicina_vektora; i++){
			if(i < vektor.size()){
				idi = najveci - vektor.at(i) + 1;
				broj = vektor.at(i);
			}else if(i >= vektor.size()){
				idi = najveci - vektor.at(i - period) + 1;
				broj = vektor.at(i - period);
			}
			for(int e = 0; e < broj; e++){
				a[i][e] = idi;
				idi++;
			}
		}
		//Vraćanje
		return a;
	}catch(...){
		throw;
	}
}

template <typename Tip>
int **AlocirajKontinuirano(const std::vector<Tip> &vektor, int &koliko_puta){
	if(vektor.size() == 0) throw std::domain_error("Prazan vektor!");
	for(Tip a: vektor){
		if(a <= 0) throw std::domain_error("Neispravan vektor!");
	}
	//Provjeravamo da li je niz periodičan
	int velicina_vektora = 0;
	int period = 0;
	koliko_puta = Periodicnost(vektor, velicina_vektora, period);
	//Alociranje matrice
	try{
		int **a(new int*[velicina_vektora]{});
		int broj_elemenata_matrice = 0;
		for(int i = 0; i < velicina_vektora; i++){
			if(i < vektor.size()){
				broj_elemenata_matrice += vektor.at(i);
			}else if(i >= vektor.size()){
				broj_elemenata_matrice += vektor.at(i - period);
			}
		}
		
		try {
			a[0] = new int[broj_elemenata_matrice];
			for(int i = 1; i < velicina_vektora; i++){
				if(i-1 < vektor.size()){
					a[i] = a[i - 1] + vektor.at(i-1);
					//std::cout << "i=" << i << vektor.at(i);
				}else if(i-1 >= vektor.size()){
					a[i] = a[i - 1] + vektor.at(i - period - 1);
					//std::cout << "i=" << i << vektor.at(i - period);
				}
			}
		}catch (...) {
			delete[] a;
			throw;
		}
		//POPUNJAVANJE MATRICE
		int idi, broj;
		for(int i = 0; i < velicina_vektora; i++){
			if(i < vektor.size()){
				idi = vektor.at(i);
				broj = vektor.at(i);
			}else if(i >= vektor.size()){
				idi = vektor.at(i - period);
				broj = vektor.at(i - period);
			}
			for(int e = 0; e < broj; e++){
				a[i][e] = idi;
				//std::cout << idi <<  " ";
				idi--;
			}
		}
		//Vraćanje
		return a;
	}catch(...){
		throw;
	}
}




int main (){
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::vector<int> vektor;
	int koliko_puta = 0;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < broj_elemenata; i++){
		int unos;
		std::cin >> unos;
		vektor.push_back(unos);
	}
	int odabir;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> odabir;
	if(odabir == 1){
		try{
			int period(Period(vektor));
			int broj,duzina_vektora;
			int **a = AlocirajFragmentirano(vektor, koliko_puta);
			
			if(period == vektor.size()) duzina_vektora = 2*vektor.size();
			else duzina_vektora = (ceil(vektor.size() / (period*1.0))) * period;
			
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			for(int i = 0; i < duzina_vektora; i++){
				if(i < vektor.size()){
					broj = vektor.at(i);
				}else if(i >= vektor.size()){
					broj = vektor.at(i - period);
				}
				for(int e = 0; e < broj; e++){
					std::cout << std::setw(2) << std::left << a[i][e] << " ";
				}
				std::cout << std::endl;
			}
			//-----------DEALOCIRANJE-----------------------
			for(int i = 0; i < duzina_vektora; i++){
					delete[] a[i];
			}
			delete[] a;
			//------------------------------------------------
		}catch(std::exception &e){
			//KEČOVANJE
			std::cout << "Izuzetak: " << e.what() << std::endl; 
		}
	}else if(odabir == 0){
		try{
			int period(Period(vektor));
			int broj,duzina_vektora;
			int **a = AlocirajKontinuirano(vektor, koliko_puta);
			
			if(period == vektor.size()) duzina_vektora = 2*vektor.size();
			else duzina_vektora = (ceil(vektor.size() / (period*1.0))) * period;
			
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			for(int i = 0; i < duzina_vektora; i++){
				if(i < vektor.size()){
					broj = vektor.at(i);
				}else if(i >= vektor.size()){
					broj = vektor.at(i - period);
				}
				for(int e = 0; e < broj; e++){
					std::cout << std::setw(2) << std::left << a[i][e] << " ";
				}
				std::cout << std::endl;
			}
			//-----------DEALOCIRANJE-----------------------
			delete[] a[0];
			delete[] a;
			//------------------------------------------------
		}catch(std::exception &e){
			//KEČOVANJE
			std::cout << "Izuzetak: " << e.what() << std::endl; 
		}
	}else{
		std::cout << "Greska u odabiru!";
		return 0;
	}
	return 0;
}