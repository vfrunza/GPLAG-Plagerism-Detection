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

bool Prost(int n){
	for (int i(2); i<n; i++){
		if(n%i==0) return false;
		if(i==n-1) return true;
	}
}

std::vector<int> IzbaciVisak(std::vector<int> v){
	if(v.size()==0) return v;
	for(int i(0); i<v.size()-1; i++){
		for(int j(i+1); j<v.size(); j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

int Trans (int n){
	int novi(0), st(1);
	while (n!=0){
		novi+=(n%3)*st;
		n/=3;
		st*=10;
	}
	return novi;
}

bool Simetrija(int n){
	std::vector<int> cifre;
	while(n!=0){
		cifre.push_back(n%10);
		n/=10;
	}
	for (int i(0); i<cifre.size()/2; i++)
		if (cifre.at(i) != cifre.at(cifre.size()-1-i)) return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool n){
	std::vector<int> prosti, slozeni;
	for (int i(0); i<v.size(); i++){
		bool x(Prost(v.at(i)));
		if (x==true) prosti.push_back(v.at(i));
		else slozeni.push_back(v.at(i));
	}
	prosti=IzbaciVisak(prosti);
	slozeni=IzbaciVisak(slozeni);
	for (int i(0); i<prosti.size(); i++) prosti.at(i)=Trans(prosti.at(i));
	for (int i(0); i<slozeni.size(); i++) slozeni.at(i)=Trans(slozeni.at(i));
	for (int i(0); i<prosti.size(); i++){
		bool sim;
		sim=Simetrija(prosti.at(i));
		if(sim==false){
			prosti.erase(prosti.begin()+i);
			i--;
		}
	}
	for (int i(0); i<slozeni.size(); i++){
		bool sim;
		sim=Simetrija(slozeni.at(i));
		if(sim==false){
			slozeni.erase(slozeni.begin()+i);
			i--;
		}
	}
	if(n==false) return slozeni;
	return prosti;
}

int Baza10(int n){
	int st(1), novi(0);
	while (n!=0){
		int cifra(n%10);
		novi+=cifra*st;
		st*=3;
		n/=10;
	}
	return novi;
}
/* 191 233 43 313 143 13 121 678 151 23 -12 727 173 -1 1 */
int main (){
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	for(;;){
		int n;
		std::cin>>n;
		if(n==-1) break;
		v.push_back(n);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool a;
	std::cin>>a;
	v=IzdvojiSimetricneTernarne(v, a);
	if (v.size()==0 && a==false){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if (v.size()==0 && a==true){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	for (int i(0); i<v.size(); i++) v.at(i)=Baza10(v.at(i));
	if (a) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	if (!a) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for (int i(0); i<v.size(); i++){
		if (i==v.size()-1){
			std::cout<<v.at(i)<<".";
			break;
		}
		std::cout<<v.at(i)<<", ";
	}
	return 0;
}