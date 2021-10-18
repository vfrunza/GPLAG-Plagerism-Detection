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

bool DaLiJeSimetrican (int a)
{
	vector<int> v;
	while (a!=0)
	{
		v.push_back(a%10);
		a=a/10;
	}
	
	for(int i=0; i<=v.size()/2; i++)
	{
		if(v.at(i)!=v.at(v.size()-1-i)) return false;
	}
	return true;
	//mozda nece raditi ako bude neparan broj cifara
}

bool DaLiJeProst (int n)
{
	if(n<=1) return false;
	for (int i=2; i<=sqrt(n); i++)
	{
		if (n%i==0) return false;
	}
	return true;
}

int PretvoriUTernarni (int a)
{
	int b,c,d,e;
	vector<int> v;
	c=a; b=0;
		while(c!=0)
		{
			e=c;
			c=c/3; d=e-c*3; v.push_back(d);
		}
		
		for(int j=v.size()-1; j>=0; j--)
		{
			b=b+pow(10,j)*v.at(j);
		}
	return b;
}

vector <int> IzdvojiSimetricneTernarne (vector<int> v, bool a)
{
	vector<int> ter,v1,v2,v3;
	int b(0);
	
	if(a==true)
	{
		for(int i=0; i<v.size(); i++)
		{
			if(DaLiJeProst(v.at(i)))
			{
				for(int j=0; j<v1.size(); j++)
				{
					if(v.at(i)==v1.at(j)) b=1;
				}
				if(b==0) v1.push_back (v.at(i));
				b=0;
			}
		}
	}
	
	else
	{
		for(int i=0; i<v.size(); i++)
		{
			if(DaLiJeProst(v.at(i))==false)
			{
				for(int j=0; j<v1.size(); j++)
				{
					if(v.at(i)==v1.at(j)) b=1;
				}
				if(b==0) v1.push_back (v.at(i));
				b=0;
			}
		}
	}
	 
	// for(int i=0; i<v1.size(); i++) cout<<v[i]<<", ";
	 
	for(int i=0; i<v1.size(); i++) ter.push_back(PretvoriUTernarni(v1.at(i)));
		

	
	for(int i=0; i<v1.size(); i++)
	{
		if(DaLiJeSimetrican(ter.at(i)))
		{
			//cout<<"Jeste simetricni";
			v3.push_back(v1.at(i));
		}
	}
	return v3;
}
int main ()
{
	int a,b;
	//bool c;
	vector<int> v,v1;
/*	cin>>a;
	a=PretvoriUTernarni(a);
	cout<<a<<endl;
	c=DaLiJeSimetrican(a);
	if(c==true) cout<<"Begoooooo";

	*/
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		cin>>a;
		if(a!=-1)v.push_back(a);
	}
	while (a!=-1);
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>b;
	while(b!=1 && b!=0)
	{
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>b;
	}
	if(b==1) 
	{

		v1=IzdvojiSimetricneTernarne (v,true);
		if(v1.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		{
			cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v1.size(); i++)
			{
				if(i==v1.size()-1)
				cout<<v1.at(i)<<".";
				else cout<<v1.at(i)<<", ";
			}
		}
	}
	else
	{
		v1=IzdvojiSimetricneTernarne (v,false);
		if(v1.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
		{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v1.size(); i++)
			{
				if(i==v1.size()-1)
				cout<<v1.at(i)<<".";
				else cout<<v1.at(i)<<", ";
			}
		}
	}
	
	return 0;
}