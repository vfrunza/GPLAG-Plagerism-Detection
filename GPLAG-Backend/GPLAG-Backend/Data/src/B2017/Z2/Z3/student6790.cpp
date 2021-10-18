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

template<typename Tip1>
bool TestPerioda (std::vector<Tip1> v,int pot_period) {
	
	for(int i(0);i<v.size()-pot_period;i++) {
		if (v.at(i)!=v.at(i+pot_period)) 
			return false;
	}
	
	return true;
}

template<typename Tip2>
int OsnovniPeriod (std::vector<Tip2> v) {
	//int osnovni_period(0);
	for(int i(1);i<v.size();i++) {
		if(TestPerioda(v,i)==true) {
			return i;
		}
			
	}
	return 0;
}

template<typename Tip3>
bool DaLiJePeriodicna(std::vector<Tip3> v) {
	if(OsnovniPeriod(v)) return true;
	return false;
}

template<typename Tip4>
int ModifikacijaVektora(std::vector<Tip4> &v) {
	int koliko_puta;
	if(DaLiJePeriodicna(v)) {
		int osnovni_period=OsnovniPeriod(v);
		int dodaj(0);
		
		//Koliko treba dodati elemenata:
		if(v.size()%osnovni_period!=0) {
			dodaj=osnovni_period-(v.size()%osnovni_period);

			for(int i(0);i<v.size();i++) {
				if(dodaj==0) break;
				if(v.at(i)==v.at(v.size()-1)){
					v.push_back(v.at(i+1));
					dodaj--;
				}
			}
		}
		koliko_puta=v.size()/osnovni_period;
	}
	
	else {
		int dodaj(v.size());
		for(int i(0);i<v.size();i++) {
			if(dodaj==0) break;
			v.push_back(v.at(i));
			dodaj--;
		}
		koliko_puta=2;
	}
	return koliko_puta;
}

template<typename Tip>
Tip **AlocirajFragmentalno (std::vector<Tip> const &v, int &koliko_puta){
	
	if(v.size()==0) throw "Prazan vektor!";
	
	for(int i(0);i<v.size();i++) {
		if(v.at(i)<=0) 
			throw std::domain_error("Neispravan vektor!");
	}
	
	Tip **mat=nullptr;
	try {
		mat=new Tip*[v.size()];
		for(int i(0);i<v.size();i++) 
			mat[i]=nullptr;
		try {
			for(int i(0);i<v.size();i++) {
				for(int j(0);j<v.size();j++) {
					if(i==j) {
						mat[j]=new Tip[v[i]];
					}
				}
			}

			for(int i(0);i<v.size();i++) {
				int duzina(v.at(i));
				Tip MaxElement(OsnovniPeriod(v));
				for(int j(duzina-1);j>=0;j--) {
					mat[i][j]=MaxElement;
					MaxElement--;
				}
			}

		}
		catch(...) {
			for(int i(0);i<v.size();i++) 
				delete[] mat[i];
			delete[] mat;
			throw;
		}
	}
	catch(...) {
		throw;
	}
	
	return mat;
}

template <typename TipV>
TipV **AlocirajKontinualno (std::vector<TipV> const &v, int &koliko_puta) {
	if(v.size()==0) throw "Prazan vektor!";
	
	for(int i(0);i<v.size();i++) {
		if(v.at(i)<=0) 
			throw std::domain_error("Neispravan vektor!");
	}
	TipV **mat=nullptr;
	
	try {
		mat=new TipV *[v.size()];
		try {
			int ukupno_elemenata(0);
			for(int i(0);i<v.size();i++)
				ukupno_elemenata+=v.at(i);

			mat[0]= new TipV [ukupno_elemenata]; 
			int predhodna_duzina(v.at(0));
			int element_vektora(1);
			
			for(int i(1);i<v.size();i++) {
				mat[i]=mat[i-1]+predhodna_duzina;
				predhodna_duzina+=v.at(element_vektora);
				element_vektora++;
			}
			
			for(int i(0);i<v.size();i++) {
				int duzina(v.at(i));
				int Minimalni_element(1);
				for(int j(duzina-1);j>=0;j--) {
					mat[i][j]=Minimalni_element;
					Minimalni_element++;
				}
			}
			
		}
		catch(...) {
			delete[] mat;
			throw;
		}
	}
	catch (...){
		throw;
	}
	
	return mat;
}




int main () {
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int br_elemenata;
	std::cin>>br_elemenata;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i(0);i<br_elemenata;i++) {
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alokacija;
	std::cin>>alokacija;
	
	int **mat(nullptr);
	
	try{
	
		int koliko_puta=ModifikacijaVektora(v);
		
		if(alokacija==1) {
			mat=AlocirajFragmentalno(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
			for(int i(0);i<v.size();i++) {
				int duzina(v.at(i));
				for(int j(0);j<duzina;j++) {
					std::cout<<std::left<<std::setw(3)<<mat[i][j];
				}
				std::cout<<std::endl;
			}
			
			for(int i(0);i<v.size();i++) 
				delete[] mat[i];
			delete[] mat;
		}
		if(alokacija==0) {
			mat=AlocirajKontinualno(v,koliko_puta);
			
			int ukupno_elemenata(0);
			for(int i(0);i<v.size();i++)
				ukupno_elemenata+=v.at(i);
			
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i(0);i<ukupno_elemenata;i++) {
				int duzina(v.at(i));
				for(int j(0);j<duzina;j++) {
					std::cout<<std::left<<std::setw(3)<<mat[i][j];
				}
				std::cout<<std::endl;
			}
			
			delete[] mat[0];
			delete[] mat;
		}
		
	}
	
	
	catch(const char izuzetak[]) {
		std::cout<<"Izuzetak: "<<izuzetak;
	}
	
	catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch(...) {
		std::cout<<"Nedovoljno memorije!";
	} 
	
	
	return 0;
}