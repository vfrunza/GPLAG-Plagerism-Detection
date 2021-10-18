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
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

bool DaLiJeProst(int n)
{	
	n=fabs(n);
	if(n<2) {
		return 0;
	}
	for (int i=2; i<=sqrt(n); i++) {
		if(n%i==0)
			return false;
	}
	return true;
}


int Broj_U_Ternarni(int broj)
{
	vector<int> br;
	vector<int> pomocni;
	int brojtern(0);
	int brojac(0);
	int i,r;
	i=broj;

while(i!=0)
{
	r=i%3;
	i=i/3;
	br.push_back(r);
	brojac++;
}
	for(int m=0; m<brojac; m++) {
		brojtern+=br.at(brojac-m-1)*pow(10,m);
	}

return brojtern;
}


bool DaLiJeSimetrican(int broj){
	vector<int> cifre;
    int cifra=0;
   
	if(broj<0) broj*=-1;
	while(broj!=0){
		 cifra=broj%10;
		cifre.push_back(cifra);
		broj/=10;
	}
	int j=cifre.size()-1;
	
	for(int i=0; i<cifre.size(); i++){
		if(cifre.at(i)!=cifre.at(j)) return false;
		j--;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne (vector <int> a, bool t)
{
	vector <int> b;
	vector <int> c;
	int broj(0), s(0), p(0);
	for(int i=0; i<a.size(); i++) {
		broj=Broj_U_Ternarni(a.at(i));
		p=DaLiJeProst(a.at(i));
		s=DaLiJeSimetrican(broj);
		if(p==true) {
			if(s==true) {
				b.push_back(a.at(i));
			}

		} else if(p==false) {
			if(s==true) {
				c.push_back(a.at(i));
			}
		}

	}
	if (t==true)
		return b;
	else return c;
}




int main ()
{
	int b;
	vector <int> c;
	cout<<"Unesite elemente vektora (-1 za kraj): ";

	int x;

	do {
		cin>>x;
		if(x!=-1) c.push_back(x);
		else break;

	} while(1);

	vector <int> p;
	vector <int> s;

	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	do {
		cin>>b;
		if(b==1) {
			p=IzdvojiSimetricneTernarne(c,true);
			if(p.size()==0)
				cout<<"Nema prostih simetricnih brojeva u vektoru.";
			else {
				cout<<"Prosti simetricni brojevi iz vektora su: ";

				for(int i=0; i<p.size(); i++) {
					if(i==p.size()-1)
						cout<<p.at(i)<<".";
					else
						cout<<p.at(i)<<", ";
				}
			}
			break;
		} else if(b==0) {
			s=IzdvojiSimetricneTernarne(c,false);
			if(s.size()==0) {
				cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			} else {
				cout<<"Slozeni simetricni brojevi iz vektora su: ";

				for(int i=0; i<s.size(); i++) {
					if(i==s.size()-1)
						cout<<s.at(i)<<".";
					else
						cout<<s.at(i)<<", ";
				}
			}
			break;
		}
		if(b!=0 || b!=1)
			cout<<"Neispravan unos! Unesite ponovo: ";
	} while(1);
	return 0;
}