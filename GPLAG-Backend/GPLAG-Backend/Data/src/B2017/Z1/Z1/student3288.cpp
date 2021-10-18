#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
int prost(int n)
{
	if(n<0) n=-n;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) return 0;
	}
	return 1;
}
int ternarni(int n)
{
	int t(0),r(0);
	int predznak(1);
	if(n<0) {
		n=-n;
		predznak=-predznak;
	}
	while(n) {
		t=t*10+n%3;
		n/=3;
	}
	while(t) {
		r=r*10+t%10;
		t/=10;
	}
	return predznak*r;
}
int simetrican(int n)
{
	vector<int> v;
	if(n<0) n=-n;
	while(n) {
		v.push_back(n%10);
		n/=10;
	}
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)!=v.at(v.size()-1-i)) return 0;
	}
	return 1;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool b)
{
	vector<int> n;
	bool t(true);
	if(b) {
		for(int i=0; i<v.size(); i++) {
			if(prost(v.at(i)) && simetrican(ternarni(v.at(i)))) {
				for(int j=0; j<n.size(); j++) {
					if(v.at(i)==n.at(j)) t=false;
				}
				if(t) n.push_back(v.at(i));
				else t=true;
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			if(!prost(v.at(i)) && simetrican(ternarni(v.at(i)))) {
				for(int j=0; j<n.size(); j++) {
					if(v.at(i)==n.at(j)) t=false;
				}
				if(t) n.push_back(v.at(i));
				else t=true;
			}
		}
	}
	return n;
}
int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int> v,z;
	int x(0),y;
	while(x!=-1) {
		cin>>x;
		v.push_back(x);
	}
	v.resize(v.size()-1);
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>y;
	while(y!=0 && y!=1) {
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>y;
	}
	z=IzdvojiSimetricneTernarne(v,y);
	if(y) {
		if(z.size()==0) {
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		} else cout<<"Prosti simetricni brojevi iz vektora su: ";
	} else {
		if(z.size()==0) {
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} else cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i=0; i<z.size()-1; i++)
		cout<<z.at(i)<<", ";
	cout<<z.at(z.size()-1)<<".";
	return 0;
}