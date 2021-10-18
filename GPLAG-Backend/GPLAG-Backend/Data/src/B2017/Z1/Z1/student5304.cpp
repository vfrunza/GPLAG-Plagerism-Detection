#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int> Ternarni(long int broj){
	vector<int> cifre;
	if(broj == 0) return vector<int>(1, 0);
	while(broj != 0){
		cifre.push_back(std::abs(broj%3));
		broj/=3;
	}
	return cifre;
}

bool Prost(int broj){
	if(broj == 2) return true;
	if(broj % 2 == 0) return false;
	long int korijen(sqrt(broj) + 1);
	for(long int i = 3; i < korijen; i++){
		if(broj % i == 0) return false;
	}
	return true;
}

bool Simetrican(long int broj){
	vector<int> cifre(Ternarni(broj));
	int j(cifre.size() - 1);
	for(int i = 0; i < cifre.size(); i++){
		if(cifre.at(i) != cifre.at(j)) return false;
		j--;
	}
return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> V, bool p){
	vector<int> A;
	for(int i  = 0; i < V.size(); i++){
		if(Simetrican(V.at(i)) && Prost(V.at(i)) == p) A.push_back(V.at(i));
	}
	return A;
}

int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int> V;
	int x;
	cin>>x;
	while(x != -1){
		if(x != -1) V.push_back(x);
		cin>>x;
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int opcija;
	cin>>opcija;
	while(opcija != 0 && opcija != 1){
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>opcija;
	}
	vector<int> A(IzdvojiSimetricneTernarne(V, opcija));
	if(opcija == 1 && A.size() != 0) cout<<"Prosti simetricni brojevi iz vektora su: ";
	else if(opcija == 1 && A.size() == 0){
		 cout<<"Nema prostih simetricnih brojeva u vektoru. ";
		 return 0;
	}
	else if(opcija == 0 && A.size() == 0){
		cout<<"Nema slozenih simetricnih brojeva u vektoru. ";
		return 0;
	}
	else cout<<"Slozeni simetricni brojevi iz vektora su: ";
	cout<<A.at(0);
	for(int i = 1; i < A.size();  i++){
		cout<<", "<<A.at(i);
	}
	cout<<".";
	return 0;
}