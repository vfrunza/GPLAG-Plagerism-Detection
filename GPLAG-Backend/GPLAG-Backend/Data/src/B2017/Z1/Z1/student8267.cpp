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
typedef std::vector<int> Vektor;
bool DaLiJeProst(int n)
{
        if(n>1){
		for(int i(2);i<=sqrt(n);i++)
		if(n%i==0) return false;
        }
        if(n<-1){
        n*=(-1);	
		for(int i(2);i<=sqrt(n);i++)
		if(n%i==0) return false;
        }
	return true;
}
int ObrnutiTernarni(int x)
{
	int obrter(0);
	while(1)
	{

		obrter+=x%3;
		x/=3;
		if(x==0) return obrter;
	    obrter*=10;
	};
	return 0;
}
int Terarni(int x)
{
	int ter(0);
	int a=ObrnutiTernarni(x);
    while(1)
    {
    	ter+=a%10;
    	a/=10;
    	if(a==0) return ter;
    	ter*=10;
    };
	return 0;
}
Vektor IzdvojiSimetricneTernarne(Vektor v,bool p)
{
	Vektor novi_v;
	Vektor drugi_novi_v;
	Vektor treci_novi_v;
	for(int x : v)
	if(p)
	{
	    if(x!=1&&x!=0){
	    if(DaLiJeProst(x)) novi_v.push_back(x);
	    }
	}
	else
	{
		if(x!=1){
		if(DaLiJeProst(x)==0||x==0) novi_v.push_back(x);
		}
	}
	for(int y : novi_v)
	if(Terarni(y)==ObrnutiTernarni(y))	drugi_novi_v.push_back(y);
	for(int i(0);i<drugi_novi_v.size();i++){
	 	     bool postoji=false;
	 		 for(int j : treci_novi_v)
	         if(j==drugi_novi_v.at(i))
	         {
	         	postoji=true;
	         	break;
	         }
	         if(postoji==false) 
	         treci_novi_v.push_back(drugi_novi_v.at(i));
	}
	return treci_novi_v;
}
int main ()
{
	Vektor vektor;
	int unos;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		std::cin>>unos;
		if(unos!=-1) vektor.push_back(unos);
	}while(unos!=-1);
	std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int za_proste;
	do{
	std::cin>>za_proste;
	if(za_proste<0||za_proste>1) std::cout<<"Neispravan unos! "<<"Unesite ponovo: ";
	}while(za_proste<0||za_proste>1);
	Vektor dobijeni_vektor(IzdvojiSimetricneTernarne(vektor,za_proste));
	if(za_proste)
	{
		if(dobijeni_vektor.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	else
	{
		if(dobijeni_vektor.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i(0);i<dobijeni_vektor.size();i++)
	{
		if(i<dobijeni_vektor.size()-1)
	    std::cout<<dobijeni_vektor.at(i)<<", ";
	    else std::cout<<dobijeni_vektor.at(i)<<".";
	}
	return 0;
}