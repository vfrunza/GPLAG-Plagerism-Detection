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
using std::cout;
using std::cin;
using std::vector;

bool Simetrican(int broj){
	vector<int> v;
	while(broj!=0){
		int k(0);
		k=broj%3;
		broj/=3;
		v.push_back(k);
	}
	for(int i(0);i<v.size();i++){
		if(v.at(i)!=v.at(v.size()-1-i)) return false;
	}
	return true;
}

bool ProstSlozen(int broj){
	if(broj==1 || broj==0) return false;
	if(broj==2) return true;
	if(broj%2==0) return false;
	for(int i(3);i<=std::sqrt(broj);i++){
		if(broj%i==0) return false;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v,bool istina){
	if(v.size()!=1){
		for(int i(0);i<v.size();i++){
			for(int j(i+1);j<v.size();j++){
				if(v.at(j)==v.at(i)){
					v.erase(v.begin()+j);
					j--;
				}
			}
		}
	}
	if(istina){
		vector<int> simetricni;
		for(int i(0);i<v.size();i++){
			if(v.at(i)!=0 && ProstSlozen(abs(v.at(i)))){
				if(Simetrican(abs(v.at(i)))) simetricni.push_back(v.at(i));
			}
		}
		return simetricni;
	}
	else{
		vector<int> simetricni;
		for(int i(0);i<v.size();i++){
			if(v.at(i)==0 || !ProstSlozen(abs(v.at(i)))){
				if(abs(v.at(i))!=1)
					if(v.at(i)==0 || Simetrican(abs(v.at(i)))) simetricni.push_back(v.at(i));
			}
		}
		return simetricni;
	}
}

int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int> v;
	for(;;){
		int k(0);
		cin>>k;
		if(k==-1) break;
		v.push_back(k);
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n(0);
	cin>>n;
	while(n!=0 && n!=1){
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>n;
	}
	if(n!=0) v=IzdvojiSimetricneTernarne(v,true);
	else v=IzdvojiSimetricneTernarne(v,false);
	if(v.size()==0 && n!=0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(v.size()==0 && n==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else{
		if(n){
			int i(0);
			cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(i=0;i<v.size()-1;i++) cout<<v.at(i)<<", ";
			cout<<v.at(i)<<".";
		}
		else{
			int i(0);
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(i=0;i<v.size()-1;i++) cout<<v.at(i)<<", ";
			cout<<v.at(i)<<".";
		}
	}
	
	
	
	
	
	return 0;
}