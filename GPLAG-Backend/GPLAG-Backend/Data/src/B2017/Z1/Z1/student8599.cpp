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
#include<cmath>
#include<iomanip>
using namespace std;


bool Ternarni(int x){
	x=fabs(x);
	int ostatak,n(0),multiplier(1);
	while(x!=0){
		ostatak=x%3;
		n+=ostatak*multiplier;
		multiplier*=10;
		x=x/3;
	}
	int broj=n;
	int cifra,obrnut(0);
	do{
		cifra=n%10;
		obrnut=(obrnut*10)+cifra;
		n/=10;
	}
	while(n!=0);
	if(broj==obrnut) return true;
	else return false;
}

bool Prost(int x){
	x=fabs(x);
	int flag(0);
	for(int i=2;i<x/2;i++){
		if(x%i==0) flag=1;
	}
	if(flag==0) return true;
	else return false;
}

vector <int> IzdvojiSimetricneTernarne(vector <int> v,bool t){
	vector <int> p,n;
	for(int x:v){
		if(Ternarni(x)==true && Prost(x)==true) p.push_back(x);
		else if(Ternarni(x)==true && Prost(x)==false) n.push_back(x);
	}
	if(t==true) return p;
	else return n;
}





int main ()
{
	vector <int> a;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int n;
	cin>>n;
	while(n!=-1){
		a.push_back(n);
		cin>>n;
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int y;
	cin>>y;
	while(y!=1 && y!=0){
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>y;
	}
	if(y==1){
		if(IzdvojiSimetricneTernarne(a,true).empty()) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {cout<<"Prosti simetricni brojevi iz vektora su: ";
		int i;
		for( i=0;i<(IzdvojiSimetricneTernarne(a,true).size())-1;i++){
			cout<<IzdvojiSimetricneTernarne(a,true).at(i)<<", ";
		}
		cout<<IzdvojiSimetricneTernarne(a,true).at(i)<<".";}
	}
	else if(y==0){
		if(IzdvojiSimetricneTernarne(a,false).empty()) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {cout<<"Slozeni simetricni brojevi iz vektora su: ";
		int i;
		for( i=0;i<(IzdvojiSimetricneTernarne(a,false).size()-1);i++){
			cout<<IzdvojiSimetricneTernarne(a,false).at(i)<<", ";
		}
		cout<<IzdvojiSimetricneTernarne(a,false).at(i)<<".";}
	}
	
	return 0;
}