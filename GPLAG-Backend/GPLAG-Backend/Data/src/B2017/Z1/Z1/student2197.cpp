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

  std::vector<int> IzbaciDuplikate(std::vector<int> v){
  	std::vector<int> rez;
  for(int i=0; i<v.size(); i++){
  	bool nemaga=true;
  	for(int j=i+1; j<v.size(); j++){
  		if(v.at(i)==v.at(j)) nemaga=false;
  	}
  		if(nemaga==true) rez.push_back(v.at(i));
  }
  return rez;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool x){
	//prvo ispitat jesu li djeljivi
	std::vector<int> prosti;
	std::vector<int> slozeni;
	for(int i=0; i<v.size(); i++){
		int broj = v.at(i);
		bool prost=true;
		for(int j=2; j<broj; j++){
			if(broj%j== 0) { prost=false;
			}
		}
	if(prost)  prosti.push_back(broj);
	else slozeni.push_back(broj);
}
	    std::vector<int> prostisim;
		std::vector<int> slozenisim;
		std::vector<int>prostisim1;
		std::vector<int> cifre;
		
	for(int i=0; i<prosti.size(); i++){
		int broj=prosti.at(i);
		int m=broj;
		cifre.resize(0);
		while(broj!=0){
			int cif=broj;
			cif%=3;
			cifre.push_back(cif);
			broj/=3;
		}
		bool simetrican=true;
		for(int j=0; j<cifre.size(); j++){
			if(cifre.at(j) != cifre.at(cifre.size()-1-j)) { simetrican=false; break; }
		}
			if(simetrican) prostisim.push_back(m);
	}
		
	
	for(int i=0; i<slozeni.size(); i++){
		int broj=slozeni.at(i);
		int m=broj;
		cifre.resize(0);
		while(broj!=0){
			int cif=broj;
			cif%=3;
			cifre.push_back(cif);
			broj/=3;
		}
		bool simetrican=true;
		for(int j=0; j<cifre.size(); j++){
			if(cifre.at(j)!= cifre.at(cifre.size()-1-j)) { simetrican=false; break; }
		}
		if(simetrican) slozenisim.push_back(m);
	}
		
	if(x) return IzbaciDuplikate(prostisim);
	else return IzbaciDuplikate(slozenisim);

}

int main ()
{

	int x=1;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(x!=(-1)){
		std::cin>>x;
		if(x == -1) continue;
		v.push_back(x);
	}

	std::vector<int> prostisim = IzdvojiSimetricneTernarne(v,true);
	std::vector<int> slozenisim = IzdvojiSimetricneTernarne(v,false);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	    int y=1;
	    std::cin>>y;
		while(y!=0 && y!=1 ){
		    std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin>>y;
		}
	if(y==1){
		 if(prostisim.size()==0)  std::cout<<"Nema prostih simetricnih brojeva u vektoru. "; 
		 else {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<prostisim.size(); i++){
				if(i==prostisim.size()-1) std::cout<<prostisim.at(i)<<".";
				else std::cout<<prostisim.at(i)<<", ";
			}
	    }
	}
	else if(y==0) {

		if(slozenisim.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru. ";
		else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<slozenisim.size(); i++){
	    		if(i==slozenisim.size()-1) std::cout<<slozenisim.at(i)<<".";
				else std::cout<<slozenisim.at(i)<<", ";
			 }
		}
	}
	return 0;
}
