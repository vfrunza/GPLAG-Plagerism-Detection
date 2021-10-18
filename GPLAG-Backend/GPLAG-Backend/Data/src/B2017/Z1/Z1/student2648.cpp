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

bool ProstBroj(int broj)
{
	if(broj<2)
	return false;
	
	for(int i=2;i<=std::sqrt(broj);i++)
	{
		if(broj%i==0)
          return false;
	}
	
	return true;
}

std::vector<int> PretvoriUTernarni(int k)
{    
	
	std::vector<int>f;
	while(k!=0)
	{
	   int rezultat=k%3;
		k=k/3;
	  f.push_back(rezultat);
	}
    return f;
}

bool Simetrican(std::vector<int>b)
{   
	int j=b.size()-1;
	
	for(int i=0;i<=j;i++)
	{
		if(b.at(i)!=b.at(j))
	    {
	    	return false;
	    }
	    j--;
	    
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool d)
{    
	   if(d==true)
	   {  std::vector<int>c,b;
	   	for(int i=0;i<a.size();i++)
	   	{    
	   	    int p=a.at(i);
	   	    bool m=ProstBroj(p);
	   		if(m==true)
	   		{
	   		  b=PretvoriUTernarni(p);
	   		 bool h=(Simetrican(b));
	   		 if(h==true)
	   		 c.push_back(p);
	   	     }
	   	     
	   	 
	   	}
	   	 return c;
	   	}
	   	
	   	
	    
 if(d==false)
 { std::vector<int>f,e;
 	for(int i=0;i<a.size();i++)
 	{
 		int q=a.at(i);
 		if(q==-1)
 		break;
 		else
 		{
 		bool n=ProstBroj(q);
 		if(n==false)
 		{ 
 			f=PretvoriUTernarni(q);
 			bool g=(Simetrican(f));
 			if(g==true)
 			e.push_back(q);
 			
 		}
 		
 	}
 	}
 	return e;
 }

 

}
        
       

		
	



int main ()
{    int broj;
     std::vector<int>a;
     std::vector<int>c;
    
     std::cout<<"Unesite elemente vektora (-1 za kraj): ";
     do
     {
     	std::cin>>broj;
     	a.push_back(broj);
     } while(broj!=-1);
    
     
     std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
     
     int broj1;
     do
     {
     std::cin>>broj1;
     if(broj1!=0 && broj1!=1)
     std::cout<<"Neispravan unos! Unesite ponovo: ";
     } while(broj1!=0 && broj1!=1);
     
   
     
     if(broj1==1)
     { 
     	c=IzdvojiSimetricneTernarne(a,true);
     	if(c.size()!=0 )
     	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        else 
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
     }
     
     if(broj1==0)
     {    
     	c=IzdvojiSimetricneTernarne(a,false);
     	if(c.size()==0)
     	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
     	else
     	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
     }
     
     for(int i=0;i<c.size();i++)
     {
     	if(i==c.size()-1)
     	std::cout<<c.at(i)<<".";
     	else 
     	std::cout<<c.at(i)<<", ";
     }
	return 0;
}