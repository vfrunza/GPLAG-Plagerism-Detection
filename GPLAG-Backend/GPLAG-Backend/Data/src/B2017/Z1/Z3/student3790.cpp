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
#include<string>
#include<vector>
#include<deque>
typedef std::vector<int> Vekint;
typedef std::deque<Vekint> Dekv;
enum Smjer {Rastuci,Opadajuci};
bool DalijestepenDvojke(int a)
{
bool p=1;
if(a==1) return a;
 do{
 	if(a%2!=0) {
 		p=0; break;
 		
 	}
 	a=a/2;
 	
 }while(a!=1);
 return p;
}
Dekv MaksimalniPodnizoviStepenaDvojke(Vekint v,enum Smjer s)
{   
	Dekv d;
	int n=0;
	if(s==Rastuci){
	for(int i=0;i<v.size();i++)
	{
		Vekint g;
		n=0;
	   for(int j=i;j<v.size();j++)
	   {
	   	if(((j<v.size()-1 && v.at(i)<=v.at(j+1) && DalijestepenDvojke(v.at(j+1))) or ((n>0 && j>0) && v.at(j-1)<=v.at(j) && DalijestepenDvojke(v.at(j-1) ))) && DalijestepenDvojke(v.at(j)))
	   	{
	   	
	   	g.push_back(v.at(j));
	   	n++;
	   		
	   	}else break;
	   }
	   i+=n;
	   if(g.size()!=0) d.push_back(g);
	   g.resize(0);
		
	}
	}else if(s==Opadajuci)
	{
		for(int i=0;i<v.size();i++)
	{
	Vekint g;
	   n=0;
	   for(int j=i;j<v.size();j++)
	   {
	   	if(((j<v.size()-1 && v.at(i)>=v.at(j+1) && DalijestepenDvojke(v.at(j+1))) or ((n>0 && j>0) && v.at(j-1)>=v.at(j) && DalijestepenDvojke(v.at(j-1) ))) && DalijestepenDvojke(v.at(j)))
	   	{
	   	
	   	g.push_back(v.at(j));
	    
	   	n++;
	   		
	   	}else break;
	   }
	   
	   i+=n;
	   if(g.size()!=0) d.push_back(g);
	   g.resize(0);	
	}
	}
	
	return d;
}

int main ()
{
	Vekint b;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int k=0;k<n;k++)
	{
		int c;
		std::cin>>c;
		b.push_back(c);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int r;
	std::cin>>r;
	
	if(r==2){
	Dekv d=MaksimalniPodnizoviStepenaDvojke(b,Opadajuci);
		for(int i=0;i<d.size();i++)
	{
		if(d.size()==0) break;
		for(int j=0;j<d.at(i).size();j++)
		{
			std::cout<<"\n"<<d.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	} else { Dekv d=MaksimalniPodnizoviStepenaDvojke(b,Rastuci);
		for(int i=0;i<d.size();i++)
	{
		if(d.size()==0) break;
		for(int j=0;j<d.at(i).size();j++)
		{
			std::cout<<d.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	}
	
	return 0;
}