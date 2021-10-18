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
#include<string>
#include<math.h>
typedef std::vector<int> Vekint;
bool DaLiJeProst(long long int a)
{
	if(a==1 || a==2) return 1;
	for(int i=2;i<a;i++)
	{
		if(a%i==0) return 0;
	}
	return 1;
}
Vekint IzdvojiSimetricneTernarne (Vekint a,bool b)
 {
 	Vekint v;
 	
 	for(int i=0;i<a.size();i++)
 	{
 		std::string s1;
 		std::string s2;
 	   	if((DaLiJeProst(abs(a.at(i))))==b) {
 	   		int r=a.at(i);
 	   		int c=0;
 	   		do{
 	   			c=abs(r%3);
 	   			r=r/3;
 	   			//stavimo u string 
 	   			s1=std::to_string(c)+s1;
 	   			s2=s2+std::to_string(c);
 	   			
 	    	   		}while(r>0);
 	    	   
 	   		//ako je string simetrican onda  stavimo u v vektor a.at(i)
 	   		if(s1==s2) v.push_back(a.at(i));
 	   	}
 	}
 	return v;
 }



int main ()
{
	Vekint v1,v2;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int a;
	do{
		std::cin>>a;
		if(a!=-1) v1.push_back(a);
	}while(a!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool b;
	int c,p=0;
	do{
    p=0;
	std::cin>>c;
	if(c==0 || c==1) b=c;
	else{ p=1; 
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
		
	}while(p==1);
	v2=IzdvojiSimetricneTernarne (v1,b);
	if(v2.size()==0) {if(b==1)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else{
		
	if(b==1)
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0;i<v2.size();i++)
	{
		if((i+1)!=v2.size())
		std::cout<<v2.at(i)<<", ";
		else std::cout<<v2.at(i)<<".";
	}
	}
	return 0;
}