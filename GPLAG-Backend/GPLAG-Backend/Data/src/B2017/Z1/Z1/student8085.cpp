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

bool DaLiJeProst(int n){
	if(n<0) n=n*(-1);
	for(int i=2; i<=int(std::sqrt(n)); i++){
		if(n%i==0) return false;
	}
	return true;
}
std::vector<int>IzdvojiProsteSlozene(std::vector<int> v, bool T){
	std::vector<int> a,b;
	for(int i=0; i<v.size(); i++){
		if(DaLiJeProst(v.at(i))==true){
			a.push_back(v.at(i));
			for(int j=i+1; j<v.size(); j++){
				if(v.at(i)==v.at(j)) v.erase(v.begin()+j);
			}
		} 
		else{
			b.push_back(v.at(i));
			for(int j=i+1; j<v.size(); j++){
				if(v.at(i)==v.at(j)) v.erase(v.begin()+j);
			}
		} 
	}
	if(T==true) return a;
	else return b;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool T){
	if(T==true){
		std::vector<int> prosti(IzdvojiProsteSlozene(v,true)); // novi vektor sa prostim brojevima
		std::vector<int> simetricni;
		int n;
		for(int i=0; i<prosti.size(); i++){ 
			n=prosti.at(i);
			
			if(n<0) n=-n;
			
			std::vector<int> cifre;
			while (n>0) {
				cifre.push_back(n%3);
				n/=3;
			}
			
		// provjeravamo simetricnost
		bool jednaki=false;
		for(int i=0; i<cifre.size()/2; i++){
			if(cifre.at(i)==cifre.at(cifre.size()-i-1)) jednaki=true;
			else{
				jednaki=false;
				break;
			}
		}
		if(jednaki==true) simetricni.push_back(prosti.at(i));
		
		}
		return simetricni;
	}
	if(T==false){
		std::vector<int>slozeni(IzdvojiProsteSlozene(v,false));
		std::vector<int> simetricni;
		int n;
		for(int i=0; i<slozeni.size(); i++){
			n=slozeni.at(i);
			if(n<0) n=-n;
	
			std::vector<int>cifre;
			while (n>0) {
				cifre.push_back(n%3);
				n/=3;
			}
			
			bool jednaki=false;
			for(int i=0; i<cifre.size()/2; i++){
				if(cifre.at(i)==cifre.at(cifre.size()-1-i)) jednaki=true;
				else{
					jednaki=false;
					break;
				}
			}
			if (jednaki==true) simetricni.push_back(slozeni.at(i)); 
		}
		return simetricni;
	}
}

int main ()
{
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	for(;;){
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin>>n;
		if(n==0 || n==1) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	
	if(n==1){
		std::vector<int>prosti(IzdvojiSimetricneTernarne(v,true));
		if(prosti.size()!=0){
		      std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		     for(int i=0; i<prosti.size(); i++){
			    if(i==prosti.size()-1) std::cout<<prosti.at(i)<<".";
             	else std::cout<<prosti.at(i)<<", ";
		      }
		}
		else std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else if(n==0){
		std::vector<int>slozeni(IzdvojiSimetricneTernarne(v,false));
		if(slozeni.size()!=0){
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<slozeni.size(); i++){
				if(i==slozeni.size()-1) std::cout<<slozeni.at(i)<<".";
				else std::cout<<slozeni.at(i)<<", ";
			}
		}
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}