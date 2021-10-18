/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima.
	Zalbe za ne analiziranje testova se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using std::vector;
using std::string;

bool IsPalindrome(string broj);

bool IsPrime(int n);

string PretvoriUTernarni(int a);

vector<int> IzdvojiSimetricneTernarne(vector<int> pocetni, bool prost);


int main ()
{
	vector<int> test;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;)
	{
		int x;
		std::cin>>x;
		if(x==-1)break;
		test.push_back(x);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool yes;
	for(;;)
	{
		int a;
		std::cin>>a;
		if(a==1 || a==0)
		{
			yes=a;
			break;
		}
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	std::cin.clear();
	std::cin.ignore(1000,'\n');
	test=IzdvojiSimetricneTernarne(test,yes);
	string output{"prostih"};
	if(!yes)output="slozenih";
	if(std::end(test)-std::begin(test)==0)
	{
		std::cout<<"Nema "<<output<<" simetricnih brojeva u vektoru.";	
	}
	else
	{
		std::cout<<((yes)?"Prosti":"Slozeni")<<" simetricni brojevi iz vektora su: ";
		for(int i=0;i < static_cast<int>(test.size());i++)
		{
			std::cout<<test.at(i);
			if(i != static_cast<int>(test.size())-1)
			{
				std::cout<<", ";
			}
			else
			{
				std::cout<<".";
			}
		}
	}
	
	return 0;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> pocetni, bool prost)
{
	vector<int> rjesenje;
	for(int x : pocetni)
	{
		if(IsPrime(x)==prost && IsPalindrome(PretvoriUTernarni(x)) && x!=1 && x!=-1)
		{
			bool stavi{true};
			for(int y : rjesenje)
			{
				if(y==x)stavi=false;
			}
			if(stavi)
			{
				rjesenje.push_back(x);
			}
		}
	}
	return rjesenje;
}

string PretvoriUTernarni(int a)
{
	if(a==0)return "0";
	
	string ternarni;
	
	for(;a!=0;)
	{
		ternarni=( std::to_string(std::abs(a%3)) )+ternarni;
		a/=3;
	}

	return ternarni;
}

bool IsPrime(int n)
{
	if(n%2==0)return false;
	n=(n<0)?-n:n;
	if(n<2 || (n>2 && n%2==0) )return false;
	for(int i=3;i<=n/i;i+=2)
	{
		if(n%i==0)return false;
	}
	return true;
}

bool IsPalindrome(string broj)
{
	for(int a=0, b=broj.length()-1; a<=b;++a,--b)
	{
		if(broj.at(a) != broj.at(b))return false;
	}
	return true;
}