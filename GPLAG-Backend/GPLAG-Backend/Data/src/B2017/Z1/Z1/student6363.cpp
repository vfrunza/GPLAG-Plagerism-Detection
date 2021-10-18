#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using std::vector;
using std::cin;
using std::cout;

bool DaLiJeProst(int n){
	if(n==1 || n==0 || n==std::numeric_limits<int>::lowest()) return false;
	for(int i=2; i<=int(std::sqrt(abs(n))); i++)
		if(abs(n)%i==0) return false;
	return true;
}

unsigned long long int uTernarni(int n){
	double faktor {1};
	unsigned long long int ternarni {0};
	while (abs(n)>0) {
			ternarni+=static_cast<unsigned long long int>(faktor*(abs(n)%3));
			n=abs(n/3);
			faktor*=10;}
	return ternarni;
}

bool Simetrican(int n){
	unsigned long long int x {uTernarni(n)}, temp {x}, obrnut {0};
	while(temp!=0) {
		obrnut = obrnut*10 + temp%10;
		temp /= 10; }
	return (x==obrnut) ? true:false;
}

bool Sadrzan(vector<int> x, int y){
	for(int j=int(x.size()-1); j>=0; j--)
		if(x.at(j)==y) return true;
	return false; 
}

vector<int> IzdvojiSimetricneTernarne(vector<int> x,bool z){
	vector<int> y;
	for(int i=0; i<x.size(); i++) {
		if(x.at(i)==1) continue;
		if(Simetrican(x.at(i)) && !Sadrzan(y,x.at(i)))
			if((z && DaLiJeProst(x.at(i))) || (!z && !DaLiJeProst(x.at(i))))
				y.push_back(x.at(i));}
	return y;
}

int main(){
	vector<int> x;
	int y;
	cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		cin>>y;
		if(y==-1) break;
		else x.push_back(y);
	}
	if(x.empty()) return 0;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		cin>>y;
		if(!(y==1 || y==0)) cout << "Neispravan unos! Unesite ponovo: ";
	} while(!(y==1 || y==0));
	vector<int> k(IzdvojiSimetricneTernarne(x,y));
	if(k.empty()) {
		if(y==1) cout << "Nema prostih simetricnih brojeva u vektoru.";
		else if(y==0) cout << "Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(y==1) cout << "Prosti simetricni brojevi iz vektora su: ";
		else cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<k.size(); i++)
			if(i==k.size()-1) cout << k.at(i) << ".";
			else cout << k.at(i) << ", ";
	}
	return 0;
}