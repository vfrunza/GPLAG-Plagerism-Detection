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

bool Prosti( int broj){
	if(broj==0 and broj==-1 and broj==1) return false;
	if(broj<0) broj=-1*broj;
	for(int i(2);i<broj; i++){
		if(broj%i==0) return false;
	}
	return true;
}

bool SimetricanTernarni(int broj){
	std::vector<int> k(0);
	int temp;
	while(broj!=0){
		temp=broj%3;
		broj/=3;
		k.push_back(temp);
	}
	bool logicka(true);
	for(int i=0; i<k.size(); i++){
		if(k.at(i)!=k.at(k.size()-i-1))
		logicka=false;
	}
	return logicka;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool logicka )
{
	std::vector<int> novi;
	if(logicka==true){
		for(int i=0; i<v.size();i++){
			if(Prosti(v.at(i))==true and v.at(i)!=1)
			novi.push_back(v.at(i));
		}
	}else{
		for(int i=0; i<v.size();i++){
			if(Prosti(v.at(i))==false and v.at(i)!=1)
			novi.push_back(v.at(i));
		}
	}
	std::vector<int> novi1;
	for(int i=0; i<novi.size();i++){
		if(SimetricanTernarni(novi.at(i))==true)
		novi1.push_back(novi.at(i));
	}
	for(int i=0;i<novi1.size();i++){
		for(int j=i+1;j<novi1.size();j++){
			if(novi1.at(i)==novi1.at(j))
				novi1.erase(novi1.begin()+j);
		}
	}
	return novi1;
}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int broj(0);
	while(broj!=-1) {
		std::cin >> broj;
		if(broj!=-1) v.push_back(broj);
	}
	int logicka;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: " ;
	do{
			std::cin >> logicka;
		if(logicka!=0 and logicka!=1)std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(logicka!=0 and logicka!=1);
	
	std::vector<int> novi=IzdvojiSimetricneTernarne(v,logicka);

	if(logicka==true) {
		if (novi.size()==0) std::cout <<"Nema prostih simetricnih brojeva u vektoru."; 
		else std::cout << "Prosti simetricni brojevi iz vektora su: " ;
	} else {
		if(novi.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: " ;
	}
	for(int i=0; i<novi.size(); i++) {
		if(i==novi.size()-1) {
			std::cout << novi.at(i) << ".";
		} else {
			std::cout << novi.at(i) << ", ";
		}
	}
	return 0;
}