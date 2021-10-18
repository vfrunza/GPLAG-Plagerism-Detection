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
#include <algorithm>
#include <cmath>
using namespace std;

bool Prosti(int a)
{
	if(a<2) return 0;
	for(int i=2; i<=sqrt(a); i++) {
		if(a%i==0)
			return false;
	}
	return true;
}

int Ternarni(int n)
{
	int ternarni(0),stepen(1);
	while(n!=0) {
		ternarni+=(n%3)*stepen;
		stepen*=10;
		n/=3;
	}
	return ternarni;
}

bool Palindrom(int n)
{
	int cifra,obrnut(0),k;
	k=n;
	while(n!=0) {
		cifra=n%10;
		obrnut=(obrnut*10)+cifra;
		n/=10;
	}
	if(k==obrnut) return true;
	else return false;
}

vector<int>IzbaciDuple(vector<int>v)
{
	for(int i=0;i<int(v.size())-1;i++)
	{
		for(int j=i+1;j<v.size();j++)
			if(v.at(i)==v.at(j))
			{
				v.erase(v.begin()+j);
				j--;
			}
	}
	return v;
}

vector<int>IzdvojiSimetricneTernarne(vector<int>v,bool p)
{
	vector<int>b;
	vector<int>k;
	vector<int>tern;
	vector<int>tern1;
	for(int i=0; i<v.size(); i++) {
		if(Prosti(v.at(i)))
			b.push_back(v.at(i));
		else k.push_back(v.at(i));
	}
	int c;
	for(int i=0; i<b.size(); i++) {
		c=Ternarni(b.at(i));
		if(Palindrom(c))
			tern.push_back(b.at(i));
	}
	int f;
	for(int i=0; i<k.size(); i++) {
		f=Ternarni(k.at(i));
		if(Palindrom(f))
			tern1.push_back(k.at(i));
	}
	tern=IzbaciDuple(tern);
	tern1=IzbaciDuple(tern1);
	if(p==true) return tern;
	if(p==false) return tern1;
}


int main ()
{
	int n;
	vector<int>v;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		cin>>n;
		if(n==-1) break;
		v.push_back(n);
	} while(n!=-1);
	int izbor;
	do {
		cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
ponovo:
		cin>>izbor;
		if(izbor==1 || izbor==0) break;
		cout<<"Neispravan unos! Unesite ponovo: ";
		goto ponovo;
	} while(izbor==1 || izbor==0);
	vector<int>vektor;
	if(izbor==1) {
		vektor=IzdvojiSimetricneTernarne(v,true);
		if(vektor.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<vektor.size(); i++) {
				cout<<vektor.at(i);
				if(i!=vektor.size()-1) cout<<", ";
			}
			cout<<".";
		}
	}
	vector<int>vektor1;
	if(izbor==0) {
		vektor1=IzdvojiSimetricneTernarne(v,false);
		if(vektor1.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<vektor1.size(); i++) {
				cout<<vektor1.at(i);
				if(i!=vektor1.size()-1) cout<<", ";
			}
			cout<<".";
		}
	}
	return 0;
}