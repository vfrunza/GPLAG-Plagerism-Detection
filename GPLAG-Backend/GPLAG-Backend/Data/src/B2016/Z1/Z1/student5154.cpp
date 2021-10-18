/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> PretvoriUTernarni(int n)
{
	int pom(n);
	if(n==0) return std::vector<int> {0};
	std::vector<int> v;
	while(pom!=0)
	{                   
		int cif;
		cif=fabs(pom%3);
		v.push_back(cif);
		pom/=3;
	}
	return v;
}

int Opaki(int n)
{
	std::vector<int> brojaci(3);
	std::vector<int> ternarni(0);
	ternarni=PretvoriUTernarni(n);
	for(int i(0); i<ternarni.size(); i++)
	{
		if(ternarni.at(i)==0) brojaci.at(0)++;
		else if(ternarni.at(i)==1) brojaci.at(1)++;
		else if(ternarni.at(i)==2) brojaci.at(2)++;
		if(i==ternarni.size()) break;
	}
    
	bool opaki(false);
	for(int i(0); i<3; i++)
	{
		if(brojaci.at(i)!=0)
		{
			if(brojaci.at(i)%2==0) opaki=true;
			else
			{
				opaki=false; 
				break;
			}
		}
	}
	bool odvratni(false);
	for(int i(0); i<3; i++)
	{
		if(brojaci.at(i)!=0)
		{
			if(brojaci.at(i)%2!=0) odvratni=true;
			else
			{
				odvratni=false;
				break;
			}
		}
	}
	if(opaki==true) return 0;
	else if(odvratni==true) return 1;
	else return 2;
}

bool NePonavljaSe(std::vector<int> v, int pozicija) 
{
	bool rez(true);
	for(int i(0); i<v.size(); i++)
	{
		if(i<pozicija && v.at(i)==v.at(pozicija))
		{
			rez=false;
			break;
		}
		if(i==v.size()) break;
	}
	return rez;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opak)
{
	std::vector<int> opaki,odvratni;
	for(int i(0); i<v.size(); i++)
	{
		if(Opaki(v.at(i))==0 && NePonavljaSe(v,i)==true) opaki.push_back(v.at(i));
		else if(Opaki(v.at(i))==1 && NePonavljaSe(v,i)==true) odvratni.push_back(v.at(i));
		else continue;
		if(i==v.size()) break;
	}
	if(opak==true) return opaki;
	else return odvratni;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;)
	{
		int a;
		std::cin >> a;
		if(std::cin)
		{
			if(a==0) break;
			else v.push_back(a);
		}
	}
	std::vector<int> opaki,odvratni;
	opaki=IzdvojiGadne(v,true);
	odvratni=IzdvojiGadne(v,false);
	std::cout << "Opaki: ";
	for(int i(0); i<opaki.size(); i++) 
	{
		std::cout << opaki.at(i) << " ";
		if(i==opaki.size()) break;
	}
	std::cout << std::endl << "Odvratni: ";
	for(int i(0); i<odvratni.size(); i++)
	{
		std::cout << odvratni.at(i) << " ";
		if(i==odvratni.size()) break;
	}
	return 0;
}