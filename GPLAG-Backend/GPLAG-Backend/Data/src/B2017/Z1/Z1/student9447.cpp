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
#include <cmath>
#include <limits>

bool DaLiJeSimetrican (int a){
	int i;
	std::vector<int> tern1;
	do{
		if (a<0) a=abs(a); 
		i=a%3;
		tern1.push_back(i);
		a=a/3;
	}while(a!=0);
	
	for(int i(0);i<(tern1.size()/2);i++){
		if (tern1.at(i)!=tern1.at(tern1.size()-i-1)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a){
	std::vector <int> pro,sl,uk;
	int z=0;
	for (int i(0);i<v.size();i++){
		for(int j(2);j<=sqrt(abs(v.at(i)));j++){
			if (v.at(i)%j==0) {
				z=1;
				break;
			}
		}
		if (z==0) pro.push_back(v.at(i));
		else sl.push_back(v.at(i));
		z=0;
	}
	if (a){  
		for(int i(0);i<pro.size();i++){
			if (DaLiJeSimetrican(pro.at(i))) uk.push_back(pro.at(i));
		}
	}
	else {	
		for(int i(0);i<sl.size();i++){
			if (DaLiJeSimetrican(sl.at(i))) uk.push_back(sl.at(i));
	}
	}
	for (int i(0);i<uk.size();i++){
		for (int j(i+1);j<uk.size();j++){
			if (uk.at(i)==uk.at(j)){
				for (int k=j;k<uk.size()-1;k++){
					uk.at(k)=uk.at(k+1);
				}
				uk.resize(uk.size()-1);
				j--;
			}
		}
	}
	return uk;
}

int main ()
{
	int a,r;
	std::vector<int> l ;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for (;;){
		std::cin >> a;
		if (a==-1) break;
		l.push_back(a);
		
	}
	std::vector<int> k ;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin >> r;
		if (r==1){
			k=IzdvojiSimetricneTernarne(l,true);
			if (k.size()==0){
				std::cout << "Nema prostih simetricnih brojeva u vektoru.";
				return 0;
			}
			else std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i(0);i<k.size();i++){
				if (i==(k.size()-1)) {std::cout << k.at(i) << ".";break;}
				std::cout<< k.at(i) << ", ";
			}
			break;
		}
		else if (r==0){
			k=IzdvojiSimetricneTernarne(l,false);
			if (k.size()==0){
				std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
				return 0;
			}
			else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i(0);i<k.size();i++){
				if (i==(k.size()-1)) {std::cout << k.at(i) << ".";break;}
				std::cout << k.at(i) << ", ";
			}
			break;
		}
		else std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	return 0;
}