/*B 2017/2018, Zadaća 1, Zadatak 3

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
#include <deque>

enum Smjer {Opadajuci=0,Rastuci};

bool JeStepenDvojke(int a);

std::deque< std::vector<int> > MaksimalniPodnizoviStepenaDvojke(std::vector<int> pocetni, int direction);


int main ()
{

	std::deque<std::vector<int> > dek;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int BrojElemenata;
	std::cin>>BrojElemenata;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> input;
	
	for(int i=0; i<BrojElemenata; ++i)
	{
		int temp;
		std::cin>>temp;
		input.push_back(temp);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int KojiSmjer;
	std::cin>>KojiSmjer;
	
	Smjer zadani=Opadajuci;
	if(KojiSmjer==1)zadani=Smjer(1);
	
	dek=MaksimalniPodnizoviStepenaDvojke(input,zadani);
	
	std::cout<<"Maksimalni "<<((zadani==Rastuci)?"rastuci":"opadajuci")<<" podnizovi: \n";
	for(std::vector<int> a:dek)
	{
		for(int x:a)
		{
			std::cout<<x<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}

std::deque<std::vector<int> > MaksimalniPodnizoviStepenaDvojke(std::vector<int> pocetni, int direction)
{
	if(direction!=0 && direction!=1)return std::deque<std::vector<int>>(0);
	std::deque< std::vector<int> > dek;
	std::vector<std::vector<int> > test;
	std::vector<int> a;
	//pravimo vektor vektora stepena dvojke
	for(int i=0; i<pocetni.size(); ++i)
	{
		if(JeStepenDvojke(pocetni.at(i)))
		{
			a.push_back(pocetni.at(i));
			if(i+1==pocetni.size() )
			{
				if(a.size()>1)test.push_back(a);
				a.resize(0);
			}
		}
		else
		{
			if(a.size()>1)test.push_back(a);
			a.resize(0);
		}
	}

	for(int i=0; i<test.size(); ++i)
	{
		int temp { test.at(0).at(0)  };
		for(int  j=0; j<test.at(i).size(); ++j)
		{
			if(j==0)
			{
				temp=test.at(i).at(j);
				a.push_back(temp);
			}
			else
			{
				if((temp==test.at(i).at(j))||direction^(temp>test.at(i).at(j)))
				{
					temp=test.at(i).at(j);
					a.push_back(temp);
					if(j==test.at(i).size()-1)
					{
						if(a.size()>1)dek.push_back(a);
						a.resize(0);
					}
				}
				else
				{
					if(a.size()>1)dek.push_back(a);
					a.resize(0);
					if(j!=test.at(i).size()-1)
					{
						temp=test.at(i).at(j);
						a.push_back(temp);
					}

				}
			}
		}
	}
	return dek;
}

bool JeStepenDvojke(int a)
{
	if(a<1)return false;
	for(; a!=0;)
	{
		if( (!(a%2==0)) && a!=1)
		{
			return false;
		}
		a/=2;
	}
	return true;
}