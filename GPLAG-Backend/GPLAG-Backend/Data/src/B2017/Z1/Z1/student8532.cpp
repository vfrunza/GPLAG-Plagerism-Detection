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
#include<vector>
#include<cmath>


bool prost(int broj)
{
	for(int i=2;i<broj;i++)
	{
		if(broj%i==0)
		return false;
	}
	return true;
}

bool dalijesimetrican(int broj)
{
	int suprotan(0),cifra(0);
	int n=broj;
	do
	{
		cifra=n%10;
		suprotan=(suprotan*10)+cifra;
		broj=broj/10;
	}while(broj!=0);
	
	if(n==suprotan)
	return true;
	else
	return false;
}
 std::vector<int> IzdvojiSimetricneTenarne (std::vector<int>a, bool n)
 {
 	std::vector<int> prosti;
 	std::vector<int> slozeni;
 	for(int i=0;i<a.size();i++)
 	{
 		int broj=a.at(i);
 		if(n==true)
 		{
 			if(prost(broj)==true){
 			int ostatak(0);
			int tenarnibr(0);
			int i(0);
		while(broj!=0)
		{
		ostatak=broj%3;
		broj=broj/3;
		tenarnibr+=ostatak*(pow(10,i));
		i++;
		}
 		if(dalijesimetrican(tenarnibr))
 		prosti.push_back(tenarnibr);
 		return prosti;
 		}}
 		else if(n==false)
 		{
 			if(prost(broj)==false){
 		int ostatak(0);
		double tenarnibr(0);
		int i(0);
		while(broj!=0)
		{
		ostatak=broj%3;
		broj=broj/3;
		tenarnibr+=ostatak*(pow(10,i));
		i++;
}
 			if(dalijesimetrican(tenarnibr))
 			slozeni.push_back(tenarnibr);}
 			return slozeni;
 		
 	}
 }
 }



int main ()
{  
std::cout<<"Unesite elemente vektora (-1 za kraj): ";
std::vector<int>a;
int element;
for(;;)
{
	std::cin>>element;
	a.push_back(element);
	if(element==-1)
	break;
}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int cifra;
	std::cin>>cifra;
	
	if(cifra==1)
{
	std::vector<int> prosti;
	prosti=IzdvojiSimetricneTenarne(a,true);
	//std::cout<<prosti.size();
	if(prosti.size()==0)
	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else{
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<prosti.size();i++)
	std::cout<<prosti.at(i)<<", ";
}}
if(cifra==0)
{
	std::vector<int>slozeni;
	slozeni=IzdvojiSimetricneTenarne(a,false);
	if(slozeni.size()==0)
	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else{
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0;i<slozeni.size();i++)
	std::cout<<slozeni.at(i)<<", ";
}}
	
	return 0;
}