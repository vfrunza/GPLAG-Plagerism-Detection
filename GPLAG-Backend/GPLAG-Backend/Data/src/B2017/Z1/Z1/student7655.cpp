#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
std::vector<int>PretvoriUTernarne(std::vector<int>a )
{
	int cifra,suma(0);
	std::vector<int>v;
	std::vector<int>novi_vektor;
	for(int i=0; i<a.size(); i++) {
		while (a.at(i)!=0) {
			cifra=a.at(i)%3;
			a.at(i)/=3;
			v.push_back(cifra);
		}
		int duzina=v.size()-1;
		for(int j=v.size()-1; j>=0; j--) {
			cifra=v.at(j)*pow(10,duzina);
			suma+=cifra;
			duzina--;
		}
		v.resize(0);
		novi_vektor.push_back(suma);
		suma=0;
	}
	return novi_vektor;
}
std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v,bool t)
{
	std::vector<int>v_prosti;
	std::vector<int>v_slozeni;
	bool prost(true);
	for(int i=0; i<v.size(); i++) {
		for(int j=2; j<abs(v.at(i)); j++) {
			if(abs(v.at(i)%j)==0) {
				prost=false;
				break;
			}
		}
		if(prost) v_prosti.push_back(v.at(i));
		else v_slozeni.push_back(v.at(i));
		prost=true;
	}
	std::vector<int>prosti_ternarni(PretvoriUTernarne(v_prosti));
	std::vector<int>slozeni_ternarni(PretvoriUTernarne(v_slozeni));
	bool uslov(true);
	std::vector<int>vektor;
	std::vector<int>vektor_prosti;
	std::vector<int>vektor_slozeni;
	if(t) {
		bool isti(false);
		for(int k=0; k<prosti_ternarni.size(); k++) {
			while (prosti_ternarni.at(k)!=0) {
				vektor.push_back(prosti_ternarni.at(k)%10);
				prosti_ternarni.at(k)/=10;
			}
			for(int i=0; i<vektor.size(); i++) {
				if(vektor.at(i)!=vektor.at(vektor.size()-1-i)) {
					uslov=false;
					break;
				}
			}
			if(uslov) {
				for(int i=0; i<vektor_prosti.size(); i++) {
					if(v_prosti.at(k)==vektor_prosti.at(i)) 
						isti=true;
				}
				if(!isti) vektor_prosti.push_back(v_prosti.at(k));
				isti=false;
			}
			uslov=true;
			vektor.resize(0);
		}
		return vektor_prosti;
	} else {
		bool isti(false);
		for(int k=0; k<slozeni_ternarni.size(); k++) {
			while (slozeni_ternarni.at(k)!=0) {
				vektor.push_back(slozeni_ternarni.at(k)%10);
				slozeni_ternarni.at(k)/=10;
			}
			for(int i=0; i<vektor.size(); i++) {
				if(vektor.at(i)!=vektor.at(vektor.size()-1-i)) {
					uslov=false;
					break;
				}
			}
			if(uslov) {
				for(int i=0; i<vektor_slozeni.size(); i++) {
					if(v_slozeni.at(k)==vektor_slozeni.at(i))
						isti=true;
				}
				if(!isti) 
					vektor_slozeni.push_back(v_slozeni.at(k));
				isti=false;
			}
				uslov=true;
				vektor.resize(0);
			}
			return vektor_slozeni;
		}
	}
	int main () {
		std::vector<int>v;
		std::vector<int>vp;
		std::vector<int>vs;
		int broj(0);
		std::cout <<"Unesite elemente vektora (-1 za kraj): ";
		for(;;) {
			std::cin >> broj;
			if(broj==-1) break;
			v.push_back(broj);

		}
		std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		int izbor;
		for(;;) {
			std::cin >> izbor;
			if(izbor==1||izbor==0) break;
			else std::cout << "Neispravan unos! Unesite ponovo: ";
		}
		if(izbor==1) {
			vp=IzdvojiSimetricneTernarne(v,true);
			if(vp.size()>0) {
				std::cout << "Prosti simetricni brojevi iz vektora su: ";
				for(int i=0; i<vp.size(); i++) {
					std::cout <<vp.at(i);
					if(i<vp.size()-1) std::cout <<", ";
					else std::cout << "." ;
				}
			} else std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
		} else if(izbor==0) {
			vs=IzdvojiSimetricneTernarne(v,false);
			if(vs.size()>0) {
				std::cout << "Slozeni simetricni brojevi iz vektora su: ";
				for(int i=0; i<vs.size(); i++) {
					std::cout <<vs.at(i);
					if(i<vs.size()-1) std::cout << ", ";
					else std::cout << ".";
				}
			} else std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;
		}
		return 0;
	}