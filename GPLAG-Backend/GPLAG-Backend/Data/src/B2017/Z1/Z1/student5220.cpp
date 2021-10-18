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
#include <vector>
#include <deque>
#include <cmath>



typedef std:: vector<int> Vektor;


bool DaLiJeProst (int n){
	if(n<0){
		n=fabs (n);
	}
	if (n==1 || n==0){
		return false;
	}
	for (int i=2; i<n; i++){
		if (n%i==0){
			return false;
		}
	}
	return true;
}


bool PretvaranjeUTernarni (int broj){
	std::deque<int> ternarni;
	int pomocni;
	while (broj>0){
		pomocni=broj%3;
		ternarni.push_front(pomocni);
		broj/=3;
	}
	int brojac(ternarni.size()-1);
	for (int i(0); i<ternarni.size()/2; i++){
		if (ternarni.at(i)!=ternarni.at(brojac)) return false;
		brojac--;
	}
	
	return true;
}

bool provjera(std::vector<int> a, int broj){
	for(int i(0);i<a.size();i++){
		if(a.at(i)==broj) return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std:: vector <int> v, bool g) {
	std::vector<int> v2;
	if (g==true){
		for(int i(0); i<v.size(); i++){
			if (DaLiJeProst(v.at(i))==true){
				if(PretvaranjeUTernarni(v.at(i))==true)
					if(provjera(v2,v.at(i))==false)
						v2.push_back(v.at(i));
					
			}
		}
	}
	else {
		for (int i(0); i<v.size(); i++){
			if (DaLiJeProst(v.at(i))==false){
				if (PretvaranjeUTernarni(v.at(i))==true)
					if(provjera(v2,v.at(i))==false)
					v2.push_back(v.at(i));
			}
		}
	}
	
	return v2;
}





int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	std::vector<int> v;
	do {
		std:: cin>>broj;
		if (broj==-1){
			break;
		}
		v.push_back(broj);
	}while (broj!=-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int unos;
	do{
	std:: cin>>unos;
	if(unos!=1 && unos!=0) std::cout << "Neispravan unos! Unesite ponovo: ";
	if(unos==1 || unos==0) break;
	}while (unos!=0 && unos!=1);
	std::vector<int> vektorvektora;
	if (unos==1){
		vektorvektora=IzdvojiSimetricneTernarne(v,true);
		if(vektorvektora.size()==0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i(0); i<vektorvektora.size(); i++){
			if (i==vektorvektora.size()-1){
				std::cout << vektorvektora.at(i) << ".";
				break;
			}
			std::cout <<vektorvektora.at(i)<<", ";
			
		}
	}
	else{
			vektorvektora=IzdvojiSimetricneTernarne(v,false);
			if(vektorvektora.size()==0){
				std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
				return 0;
			}
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i(0); i<vektorvektora.size(); i++){
				if (i==vektorvektora.size()-1){
					std::cout << vektorvektora.at(i) << ".";
					break;
				}
				std::cout << vektorvektora.at(i) << ", ";
			}
		}
	

	return 0;
}