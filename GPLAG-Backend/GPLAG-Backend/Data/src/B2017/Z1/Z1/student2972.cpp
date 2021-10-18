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

bool DaLiJeProst(int n){
	if(n<=1){
		return false;
	}
	if(n==2){
		return true;
	}
	if(n%2==0){
		return false;
	}
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int PretvoriUTernarni(int a){
	int n(0), broj(0);
	while(a!=0){
		broj=a%3;
		n=n*10+broj;
		a/=3;
	}
	return n;
}

bool Simetrican(int a){
	int n(0), broj(0), b(a);
	while(b!=0){
		broj=b%10;
		n=n*10+broj;
		b/=10;
	}
	if(a==n){
		return true;
	}
	else{
		return false;
	}
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool a){
	vector<int> c;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	if(a){
		for(int i=0;i<v.size();i++){
			if(DaLiJeProst(abs(v.at(i)))){
				c.push_back(v.at(i));
			}
		}
	}
	else{
		for(int i=0;i<v.size();i++){
			if(!DaLiJeProst(abs(v.at(i)))){
				c.push_back(v.at(i));
			}
		}
	}
	vector<int> k;
	int x(0);
	for(int i=0;i<c.size();i++){
		x=PretvoriUTernarni(abs(c.at(i)));
		if(Simetrican(x)){
			k.push_back(c.at(i));
		}
	}
	return k;
}

int main ()
{
	vector<int> v;
	int a(0);
	cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		cin >> a;
		if(a==-1){
			break;
		}
		v.push_back(a);
	}
	int x(0);
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		cin >> x;
		if(x==1 || x==0){
			break;
		}
		else{
			cout << "Neispravan unos! Unesite ponovo: ";
		}
	}
	vector<int>k;
	k=IzdvojiSimetricneTernarne(v,x);
	if(x==1){
		if(k.size()==0){
			cout << "Nema prostih simetricnih brojeva u vektoru.";
		}
		else{
			cout << "Prosti simetricni brojevi iz vektora su: ";
			int i(0);
			for(i=0;i<k.size()-1;i++){
				cout << k.at(i) << ", ";
			}
			cout << k.at(i) << ".";
		}
	}
	else{
		if(k.size()==0){
			cout << "Nema slozenih simetricnih brojeva u vektoru.";
		}
		else{
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			int j(0);
			for(j=0;j<k.size()-1;j++){
				cout << k.at(j) << ", ";
			}
			cout << k.at(j) << ".";
		}
	}
	return 0;
}