#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int Ternarni(int n)
{
	int suma(0);
	vector<int> v;
	do {
		v.push_back(n%3);
		n=n/3;
	} while(n!=0);

	for(int i=0; i<(int)v.size(); i++)
		suma+=v.at(i)*round(pow(10, i));
	return suma;
}

bool DaLiJeProst(int n)
{
	if(n==0)
		return false;
	if(n<0)
		n=(-1)*n;
	for(int i=2; i<n; i++)
		if(n%i==0)
			return false;
	return true;
}

bool Simetricni(int n)
{
	vector<int> v;
	do {
		v.push_back(n%10);
		n=n/10;
	} while(n!=0);

	int velicina=v.size();
	for(int i=0; i<=(int)v.size()/2; i++) {
		if(v.at(i)!=v.at(velicina-1))
			return false;
		velicina--;
	}
	return true;
}

bool ImaLi(vector<int> v, int n)
{
	for(int i=0; i<(int)v.size(); i++)
		if(v.at(i)==n)
			return true;
	return false;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v1, bool a)
{
	vector<int> v2;
	if(a==true) {
		for(int i=0; i<(int)v1.size(); i++)
			if(DaLiJeProst(v1.at(i)) && Simetricni(Ternarni(v1.at(i))) && !ImaLi(v2, v1.at(i)) && v1.at(i)!=1 && v1.at(i)!=(-1))
				v2.push_back(v1.at(i));
	} else {
		for(int i=0; i<(int)v1.size(); i++)
			if(!DaLiJeProst(v1.at(i)) && Simetricni(Ternarni(v1.at(i))) && !ImaLi(v2, v1.at(i)) && v1.at(i)!=1 && v1.at(i)!=(-1))
				v2.push_back(v1.at(i));
	}
	return v2;
}

int main ()
{	
	int i(-1), a, b(-1);
	vector<int> v1;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		cin>>a;
		v1.push_back(a);
		i++;
	} while(v1.at(i)!=(-1));
	v1.erase(v1.begin()+(v1.size()-1));

	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
		cin >> b;
		if (!cin) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
		if (b != 1 && b != 0)
			cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}

	v1=IzdvojiSimetricneTernarne(v1, b);

	if(b==1) {
		if(v1.size()==0) {
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 1;
		}

		cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<(int)v1.size(); i++) {
			if(i<(int)v1.size()-1)
				cout<<v1.at(i)<<", ";
			else
				cout<<v1.at(i)<<".";
		}
	} else if(b==0) {
		if(v1.size()==0) {
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 2;
		}

		cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<(int)v1.size(); i++) {
			if(i<(int)v1.size()-1)
				cout<<v1.at(i)<<", ";
			else
				cout<<v1.at(i)<<".";
		}
	}
	
	return 0;
}