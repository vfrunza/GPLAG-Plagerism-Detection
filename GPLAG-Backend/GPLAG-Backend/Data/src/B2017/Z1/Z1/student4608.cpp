#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool DaLiJeJednak (int a)
{
	int niz[100],i=0,k=0,c=0;
	vector <int> v;
	while (a!=0)
	{
		k=a%3;
		niz[c]=k;
		a=a/3;
		c++;
		
	}
	for (i=c-1;i>=0;i--)
	{
		v.push_back(niz[i]);
	}
	for (i=0;i<v.size();i++)
	{
		if (v[i]!=niz[i]) return false;
	}
	return true;
}
bool DaLiJeProst (int n)
{
	int i,k,r;
	if(n<2) return false;
	if(n==2) return true;
	for (i=2;i<sqrt(n)+1;i++)
	{
		k=n/i;
		r=k*i;
		if (r==n) return false;
	}
	return true;
}
std::vector <int> IzdvojiSimetricneTernarne (vector <int> v, bool k)
{
	int i,j;
	vector <int> prosti;
	vector <int> nisuprosti;
	for (i=0;i<v.size();i++)
	{
		if (DaLiJeProst(v[i])==true) 
		{
			prosti.push_back(v[i]);
		}
		if (DaLiJeProst(v[i])==false)
		{
			nisuprosti.push_back(v[i]);
		}
	}
	if (k=true)
	{
	for (i=0;i<prosti.size();i++)
	{
		if (DaLiJeJednak(prosti[i])==false) prosti.erase(prosti.begin()+i);
	}
	return prosti;
	}
	if (k=false)
	{
	for (i=0;i<nisuprosti.size();i++)
	{
		if (DaLiJeJednak(nisuprosti[i])==false) nisuprosti.erase(prosti.begin()+i);
	}
	return nisuprosti;
	}
}
int main ()
{
	int i,broj=5,k;
	bool l(false);
	vector <int> v;
	vector <int> r;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	while (broj!=-1)
	{
		cin>>broj;
		if (broj!=-1) v.push_back(broj);
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>k;
		if(k!=1 && k!=0) {
			while(k!=1 && k!=0) {
				std::cout<<"Neispravan unos! Unesite ponovo: ";
				std::cin>>k;
			}
		}
		break;
	} while(true);
	if (k==1) l=true;
	r=IzdvojiSimetricneTernarne(v,l);
	if (r.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else
	{
	if(l)	cout<<"Prosti simetricni brojevi iz vektora su: ";
	else cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for (i=0;i<r.size();i++)
	{
		if (i==r.size()-1) cout<<r[i]<<".";
		else
		cout <<r[i]<<", ";
	}
}
	return 0;
}