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

bool Ponavljanje(Vektor v,int br)
{
 for(int i : v)
  if(br==i) return true;
 return false;
}

bool DaLiJeProst(int f)
{
 int broj(std::abs(f));
 if(f==0) return false;
 for(int i(2);i<=std::sqrt(broj);i++)
 {
  if(broj%i==0) return false;
 }
 return true;
}

int NaopakiTernarni(int n)
{
 int s(0);
 while(n!=0)
 {
  s=s*10; 
  s+=std::abs(n%3);
  n/=3;
 }
 return s;
}

bool DaLiSuSimetricni(int d)
{
 int naopaki(NaopakiTernarni(d));
 int naopaki2(NaopakiTernarni(d));
 int ternarni(0);
 while(naopaki!=0)
 {
  ternarni*=10;
  ternarni+=std::abs(naopaki%10);
  naopaki/=10;
 }
 if(ternarni!=naopaki2) return false;
 else return true;
}

Vektor IzdvojiSimetricneTernarne(Vektor v, bool log)
{
 Vektor prosti;
 Vektor slozeni;
 for(int i : v)
 {
  if(DaLiSuSimetricni(i)==true)
  {
   if(DaLiJeProst(i)==true) 
   {
    if(i!=1)
    {
     if(Ponavljanje(prosti,i)==true) continue;
      prosti.push_back(i);
    }
   }
   else 
   {
    if(DaLiJeProst(i)==false)
    {
     if(i!=1)
     {
      if(Ponavljanje(slozeni,i)==true) continue;
       slozeni.push_back(i);
     }
    }
   }
  }
 }
 if(log==true) return prosti;
 else return slozeni;
}

int main ()
{
	Vektor a;
	int unos;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
 for(int i(0); ;i++)
 {
  std::cin >> unos;
  if(unos==-1) break;
  a.push_back(unos);
 }
 Vektor b(IzdvojiSimetricneTernarne(a,true));
 Vektor c(IzdvojiSimetricneTernarne(a,false));
 int k;
 std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
 unos: std::cin >> k;
 if(k==1) 
 {
  if(b.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
  else
  {
   std::cout << "Prosti simetricni brojevi iz vektora su: ";
   for(int i(0);i<b.size();i++)
   {
    if(i<b.size()-1) std::cout << b.at(i) << ", ";
    else std::cout << b.at(i) << ".";
   }
  }
 }
 else if(k==0)
 {
  if(c.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
  else
  {
   std::cout << "Slozeni simetricni brojevi iz vektora su: ";
   for(int j(0);j<c.size();j++)
   {
    if(j<c.size()-1) std::cout << c.at(j) << ", ";
    else std::cout << c.at(j) << ".";
   }
  }
 }
 else
 {
  std::cout << "Neispravan unos! Unesite ponovo: ";
  goto unos;
 }
	return 0;
}