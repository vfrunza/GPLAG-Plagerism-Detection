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
#include<cmath>

std::vector<int>  Terarni(int broj)
{
	int c;
	std::vector<int>terarni;
	while(broj!=0)
	{
		c=broj%3;
		terarni.push_back(c);
		broj/=3;
	}
	return terarni;
}

bool DaLiJeProst(int broj)
{
	if(broj<0) broj=broj*(-1);
	if(broj<2) return false;
	for(int i=2;i<=sqrt(broj);i++)
	if(broj%i==0) return false;
	
	return true;
}

bool DaLiJeSimetrican(std::vector<int>pom)
{
	int a=pom.size()-1;
	for(int i=0;i<=pom.size()-1;i++)
	{
			if(pom.at(i)!=pom.at(a)) return false;
			a--;
	}
	return true;
}

 std::vector<int> IzdvojiSimetricneTerarne(std::vector<int>niz,bool uslov)
 {
 	std::vector<int>prosti;
 	std::vector<int>slozeni;
 	for(int i=0;i<niz.size();i++)
 	{
 		
 		if(niz.at(i)<0) niz.at(i)=niz.at(i)*(-1);
 		
 		if( uslov==1 && DaLiJeProst(niz.at(i))==1 && DaLiJeSimetrican(Terarni(niz.at(i)))==1  && niz.at(i)!=1) prosti.push_back(niz.at(i));
 		else if(uslov==0 && DaLiJeProst(niz.at(i))==0 && DaLiJeSimetrican(Terarni(niz.at(i)))==1 && niz.at(i)!=1) slozeni.push_back(niz.at(i));
 	}
 	
 	if(uslov==true)
 	return prosti;
 
 	else return slozeni;
 }

int main ()
{
	std::vector<int>n ;
	std::vector<int> rezultat ;
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    int m;
    do
    {
      std::cin >> m;
      n.push_back(m);
     }while (m!=-1);
     bool b;
     std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: " ;
     std::cin >> b;
     
     rezultat=IzdvojiSimetricneTerarne(n,b);
     
     if(b==1 && rezultat.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru. ";
     else if(b==0 && rezultat.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
     else if(b==1 && rezultat.size()!=0)
     {
    std::cout << "Prosti simetricni brojevi iz vektora su: ";
    for(int i=0;i<rezultat.size();i++)
    {
    
    	if(i==rezultat.size()-1) std::cout << rezultat.at(i) <<".";
        else
    	std::cout <<rezultat.at(i) << ", ";
    }
     }
     
       else if(b==0 && rezultat.size()!=0)
     {
       std::cout << "Slozeni simetricni brojevi iz vektora su: ";
        for(int i=0;i<rezultat.size();i++)
       {
    
    	if(i==rezultat.size()-1) std::cout << rezultat.at(i) <<".";
        else
    	std::cout <<rezultat.at(i) << ", ";
       }
    }
     
     
	return 0;
}