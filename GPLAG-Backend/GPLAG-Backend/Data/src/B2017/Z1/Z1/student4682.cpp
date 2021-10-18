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
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

bool JeLiProst(int x) {
	bool prost(true);
	for(int i=2; i<=std::sqrt(x); i++) {
		if(x%i==0){
			prost=false;
			break;
		} 
	}
	return prost;
}

bool Simetrican(vector<int> v) {
	bool simetrican(true);
	int duzina1=v.size()/2;
	int duzina=v.size()-1;
	for(int i=0; i<=duzina1; i++) {
		if(v.at(i)!=v.at(duzina-i)) {
			simetrican=false;
			break;
		}
	}
	return simetrican;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool prosti) {
	vector<int> povratni;
	std::vector<int> pom;
	for(int i=0; i<v.size(); i++) {
		bool nema_ga(true);
		for(auto x : pom) {
			if(v.at(i)==x) nema_ga=false;
		}
		if(nema_ga) pom.push_back(v.at(i));
	}
	v=pom;
	
	if(prosti) {
		for(int i=0; i<v.size(); i++) {
			bool negativan(false);
			if(v.at(i)<0) {
				v.at(i)*=-1;
				negativan=true;
			}
			if(JeLiProst(v.at(i))) {
				vector<int> cifre;
				int tmp=v.at(i);
				while(tmp!=0) {
					int ostatak=tmp%3;
					cifre.push_back(ostatak);
					tmp/=3;
				}
				if(Simetrican(cifre)) {
					if(negativan)	v.at(i)*=-1;
					povratni.push_back(v.at(i));
				}
			}
		}
	}
	else {
		for(int i=0; i<v.size(); i++) {
			if(JeLiProst(v.at(i))==false) {
				vector<int> cifre;
				int tmp=v.at(i);
				while(tmp!=0) {
					int ostatak=tmp%3;
					cifre.push_back(ostatak);
					tmp/=3;
				}
			
				if(Simetrican(cifre)) povratni.push_back(v.at(i));
			}
		}
	}
	
	return povratni;
	
}


int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	vector<int> v;
	for(;;) {
		cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}
	int prosti;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
	cin>>prosti;
	if(prosti==1 || prosti==0) break;
	cout<<"Neispravan unos! Unesite ponovo: ";
	}

	
	vector<int> simetricni;
	simetricni=IzdvojiSimetricneTernarne(v,prosti);
	
	if(prosti==1) {
		if(simetricni.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<simetricni.size(); i++) {
			if(i!=simetricni.size()-1) cout<<simetricni.at(i)<<", ";
			else cout<<simetricni.at(i)<<".";
		}
	}
	}
	
	else {
		if(simetricni.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<simetricni.size(); i++) {
				if(i!=simetricni.size()-1) cout<<simetricni.at(i)<<", ";
				else cout<<simetricni.at(i)<<".";
			}
		}
	}

	
	return 0;
}