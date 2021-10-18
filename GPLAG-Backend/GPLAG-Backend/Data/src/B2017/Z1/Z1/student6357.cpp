#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool prost)
{
	vector<int> v1;
	for(int i=0; i<v.size(); i++) {
		int n(v.at(i)),n1(v.at(i));
		bool prosti=true;
		if(n1<0) n1*=(-1);
		for(int j=2; j<=sqrt(n1); j++) {
			if(n1%j==0) {
				prosti=false;
			}
		}
		if(prosti==prost) {
			int broj1(0);
			do {
				broj1=broj1*10+n1%3;
				n1/=3;
			} while(n1!=0);
			int tmp(broj1),broj2(0);
			do {
				broj2=broj2*10+tmp%10;
				tmp/=10;
			} while(tmp!=0);
			if(broj1==broj2) {
				bool ponavlja_se=false;
				for(int l=0; l<v1.size(); l++) {
					if(v1.at(l)==n) ponavlja_se=true;
				}
				if(ponavlja_se==false) v1.push_back(n);
			}
		}
	}
	return v1;
}
int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int> v;
	int n;
	do {
		cin>>n;
		if(n!=(-1)) v.push_back(n);
	} while(n!=-1);
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int unos;
	cin>>unos;
	while(unos!=1 && unos!=0) {
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>unos;
	}
	bool logicka=true;
	if(unos==1) logicka=true;
	else if(unos==0) logicka=false;
	vector<int> v1(IzdvojiSimetricneTernarne(v,logicka));
	if(v1.size()==0 && logicka) cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(v1.size()==0 && logicka==false) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else {
		if(logicka) cout<<"Prosti simetricni brojevi iz vektora su: ";
		else cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size()-1; i++) {
			cout<<v1.at(i)<<", ";
		}
		cout<<v1.at(v1.size()-1)<<".";
	}
	return 0;
}