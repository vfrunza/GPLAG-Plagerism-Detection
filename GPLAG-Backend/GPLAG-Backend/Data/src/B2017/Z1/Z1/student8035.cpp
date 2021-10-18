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
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string toTern(int n)
{
	string s;
	if(n < 0)
		n = -n;
	while(n)
	{
		s.push_back(n % 3 + '0');
		n /= 3;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool jePalindrom(const string &s)
{
	for(int i = 0; i < s.length() / 2; i++)
	if(s.at(i) != s.at(s.length() - i - 1))
		return false;
		
	return true;
}

bool jeSimetrican(int n)
{
	string s = toTern(n);
	return jePalindrom(s);
}

bool jeProst(int n)
{
	if(n < 4) 	
		return true;
		
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
			
	return true;
	
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool Log)
{
	std::vector<int> vek;
	
	for(int i = 0; i < v.size() ; i++)
	{
		if(Log && jeProst(v.at(i)) && jeSimetrican(v.at(i)))
			vek.push_back(v.at(i));
		else if( !Log && !jeProst(v.at(i)) && jeSimetrican(v.at(i)))
			vek.push_back(v.at(i));
	}
	return vek;
}

int main ()
{
	vector<int> v;
	int tmp;
	int n;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	while (true) 
	{
		cin>>tmp;
		if(tmp == -1)
		 	break;
		 v.push_back(tmp);
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>n;
	while(n != 1 && n != 0)
	{
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>n;
	}
	 if(n == 1)
	{
		
		std::vector<int>a = IzdvojiSimetricneTernarne(v, true);
		if(a.size() == 0)
		{
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		else
		{
			cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < a.size(); i++)
		{
			cout<<a.at(i);
			if(i != a.size() - 1)
				cout<<", ";
			else if(i == a.size() - 1)
				cout<<".";
		}
		}
	}
	else if(n == 0)
	{
		std::vector<int>b = IzdvojiSimetricneTernarne(v, false);
		if(b.size() == 0)
		{
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		else 
		{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0; i < b.size(); i++)
		{
			cout<<b.at(i);
			if(i != b.size() - 1)
				cout<<", ";
			else if(i == b.size() - 1)
				cout<<".";
		}
	}
	}
	
	return 0;
}