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

bool DaLiJeProst(int a)
{
	for(int i=2; i<=sqrt(a); i++)  //Fermaova teorema
	{
		if(a%i==0)
			return false;
	}
	return true;
}

int PretvoriUTernarne(int element)
{
	std::vector<int>b;
	int p=1;
	int a=element;
	if(element<0){
		element=(-1) * element;
		p=-1;
	}
	while(element>0)
	{
		b.push_back(element%3);
		element/=3;
	}
	int k;
	k=b.size()-1;
	for(int i=0; i<b.size()/2; i++)
	{
		if(b.at(i)!=b.at(k))
		return 0; //////
		
		k--;
	}
	if(p==-1)
	return p*a;
	else
	return a;
}



std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool a)
{
	std::vector<int> vektor_prostih, vektor_slozenih, ternarni, finalni;
	
	if(a)
	{
			for(int i=0; i<v.size(); i++)
			{
				bool isti(false);
				for(int j=0; j<i; j++)
				{
					if(v.at(i)==v.at(j))
					isti=true;
				}
				if(isti)
				continue;
				
				if(v.at(i)==0 || abs(v.at(i))==1)
				continue;
				int c=abs(v.at(i));
				if( DaLiJeProst( c ) )
				{
					vektor_prostih.push_back(v.at(i));
					
					ternarni.push_back( PretvoriUTernarne(v.at(i)));
				}
			}
			
			for(int i=0; i<vektor_prostih.size(); i++)
			{
				if(ternarni.at(i)!=0)
				finalni.push_back(vektor_prostih.at(i));
			}
		
			return finalni;
	}
	else
	{
		for(int i=0; i<v.size(); i++)
		{
			bool isti(false);
			for(int j=0; j<i; j++)
			{
				if(v.at(i)==v.at(j))
					isti=true;
			}
			if(isti)
				continue;
				
			if(v.at(i)==0 || abs(v.at(i))==1)
			continue;
				
			if( !(DaLiJeProst(abs(v.at(i)))))
			{
				vektor_slozenih.push_back(v.at(i));
				
			    ternarni.push_back( PretvoriUTernarne(v.at(i)));
			}
		}
		
		for(int i=0; i<vektor_slozenih.size(); i++)
		{
			if(ternarni.at(i)!=0)
			finalni.push_back(vektor_slozenih.at(i));
		}
		
		return finalni;
	}
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v, v2;
	int a;
	do{
		std::cin>>a;
		if(a!=(-1))
		v.push_back(a);
	}while(a!=-1);
	
	int b;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> b;
	while (b!=0 && b!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> b;
		
	}
	
	v2=IzdvojiSimetricneTernarne(v, b);
	
	if(b)
	{	
		if(v2.size()==0)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru."<<std::endl;
		else
		{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++)
			{
				if(i!=v2.size()-1)
				std::cout<<v2.at(i)<<", ";
				else
				std::cout<<v2.at(i)<<".";
			}
		}
	}
	else
	{
		if(v2.size()==0)
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru."<<std::endl;
		else
		{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++)
			{
				if(i!=v2.size()-1)
				std::cout<<v2.at(i)<<", ";
				else
				std::cout<<v2.at(i)<<".";
			}
		}
	}
	
	return 0;
}