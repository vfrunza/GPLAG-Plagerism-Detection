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
#include<deque>
#include<cmath>

bool ProstiBrojevi(int n)
{
	n=fabs(n);
	if(n<=1)	
		return false;
		
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}



bool JesuLiSimetricni (int broj)
{
	if(broj==0 || broj==1)
		return false;
	std::deque<int> n;
	int x;
	int a(fabs(broj));
	while(a!=0)
	{
		x=a%3;
		n.push_front(x);
		a/=3;
	}
	int j(n.size()-1);
	for(int i=0;i<n.size()-1;i++)
	{
		if(n.at(i)!=n.at(j))
			return false;
		if(i==j)	
			break;
		j--;	
	}
	
	return true;
}

std::vector<int> IzdvojiSimetricneTenarne(std::vector<int> v,bool n)
{
	std::vector<int> a,b;
	
	
	
	for(int i=0;i<v.size()-1;i++)
    {
    	for(int j=i+1;j<v.size();j++)
    	{
    		if(v.at(i)==v.at(j))
    			v.erase(v.begin() + j);
    	}
    }
	
	for(int i=0;i<v.size();i++)
	{
		if(ProstiBrojevi(v.at(i)) && JesuLiSimetricni(v.at(i)))
		{
				a.push_back(v.at(i));
		}		
		else if(ProstiBrojevi(v.at(i))==false)
		{	
			if(JesuLiSimetricni(v.at(i)))
				b.push_back(v.at(i));
		}	
	}
	if(n)	
		return a;
	
	return b;
}


int main ()
{
	std::vector<int> v,n;
	int broj;
	int t;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(int i=0;;i++)
    {
        std::cin>>broj;
        if(broj==-1)	
        	break;
        v.push_back(broj);
        std::cin.clear();
        std::cin.ignore(100,' ');
    }
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    do
    {
    	std::cin>>t;
    	if(t!=1 && t!=0)
    		std::cout<<"Neispravan unos! Unesite ponovo: ";
    }while(t!=1 && t!=0);
    
    
    if(t==1)
    {
    	n=IzdvojiSimetricneTenarne(v,true);
    	if(n.size()==0)
    	{
    		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
    		return 0;
    	}
    	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<n.size();i++)
			{
				if(i==n.size()-1)
					std::cout<<n.at(i)<<".";
				else	
					std::cout<<n.at(i)<<", ";
    		}
    }		
    else if(t==0)
    {
    	n=IzdvojiSimetricneTenarne(v,false);
    	if(n.size()==0)
    	{
    		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    		return 0;
    	}
    	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<n.size();i++)
			{
				if(i==n.size()-1)
					std::cout<<n.at(i)<<".";
				else	
					std::cout<<n.at(i)<<", ";
    		}
    }
	
	return 0;
}