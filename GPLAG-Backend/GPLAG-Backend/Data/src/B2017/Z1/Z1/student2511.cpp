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
#include <cmath>
using namespace std;
int test (int n)
{
	int cifra,rev=0;
	while(n!=0)
	{
		cifra=n%10;
		rev=(rev*10)+cifra;
		n=n/10;
	}
return rev;
}
int pretvori (int n)
{
	int sum=0,i=1;
	while(n!=0)
	{ 
		int x;
		x=n%3;
		sum=sum+(x*i);
		i*=10;
		n/=3;
	}
	return sum;
}
vector <int> IzdvojiSimetricneTernarne(vector<int> v,bool vrijednost)
{
	vector<int> v4;
	if(vrijednost==true)
	{
		vector<int> v2;
		for(int i=0;i<v.size();i++)
		{
			int brojac=0;
			for(int j=2;j<v.at(i);j++)
			{
				if(v.at(i)%j==0)
				{
					brojac++;
				}
			}
			if(brojac==0)v2.push_back(v.at(i));
		}
		vector<int> v3;
	
		for(int i=0;i<v2.size();i++)
		{
			int d=v2.at(i);
			int n=pretvori(v2.at(i));
			if(test(n)==n)
			v4.push_back(d);
		}
	}
	if(vrijednost==false){
	vector<int> v2;
	for(int i=0;i<v.size();i++)
	{
		for(int j=2;j<v.at(i);j++)
		{
			if(v.at(i)%j==0){
			v2.push_back(v.at(i));
			break;}
		}
	}
	vector<int> v3;
	
	int cifra,num,rev=0;
	for(int i=0;i<v2.size();i++)
	{
		int d=v2.at(i);
		int n=pretvori(v2.at(i));
		if(test(n)==n)
		v4.push_back(d);
	}
	}
return v4;
}
int main ()
{
	int n;
	bool vrijednost;
	vector<int> v;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		cin>>n;
		while(!cin)
		{
			cout<<"Neispravan unos! ";
			cin.clear();
			cin.ignore(1000,'\n');

			cout<<"Unesite ponovo: ";
			cin>>n;
		}
		if(n==-1)break;
		v.push_back(n);
	}while(n!=-1);
	vector<int> d;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int broj;
	cin>>broj;
	while(broj>1){
	cout<<"Neispravan unos! ";
	cout<<"Unesite ponovo: ";
	cin>>broj;
	if(broj==0 || broj==1)break;
	}
	if(broj==1)vrijednost=true;
	if(broj==0)vrijednost=false;
	d=IzdvojiSimetricneTernarne(v,vrijednost);
	if(d.size()==0)
	{
		if(broj==0){
		cout<<"Nema slozenih simetricnih brojeva u vektoru."<<endl;
		return 0;
		}
		if(broj==1){
		cout<<"Nema prostih simetricnih brojeva u vektoru."<<endl;
		return 0;
		}
			}
	if(broj==0)
	cout<<"Slozeni simetricni brojevi iz vektora su: ";
	if(broj==1)
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<d.size();i++) 
	{
		cout<<d.at(i);
		if(i>=0 && i<d.size()-1)cout<<", ";
	}
	cout<<"."<<endl;
	return 0;
}