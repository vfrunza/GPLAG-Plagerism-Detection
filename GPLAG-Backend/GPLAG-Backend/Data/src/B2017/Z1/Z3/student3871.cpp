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
#include <vector>
#include <deque>
#include <cmath>
enum Smjer {Rastuci,Opadajuci};
typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> DekVektora;

bool DaLiJeStepenDvojke(int n)
{
 int brojac(0);
 if(n<0) return false;
 if(n==1) return true;
 if(n%2!=0) return false;
 for(int i(2); i<=n; i*=2) 
 {
  if(n==i) brojac++;
 }
  if(brojac==0) return false;
  else return true;
}

Vektor OpadajuciElementi(Vektor b,int t)
{
 Vektor sve;
 for(int i(t);i<b.size();i++)
 {
  if(i==b.size()) break;
  if(i==b.size()-1)
  {
   sve.push_back(b.at(i));
   break;
  }
  if(b.at(i)>=b.at(i+1)) sve.push_back(b.at(i));
  else
  {
   sve.push_back(b.at(i)); 
   break;
   }
  }
 return sve;
}

Vektor RastuciElementi(Vektor b,int t)
{
 Vektor sve;
 for(int i(t);i<b.size();i++)
 {
  if(i==b.size()) break;
  if(i==b.size()-1)
  {
   sve.push_back(b.at(i));
   break;
  }
  if(b.at(i)<=b.at(i+1)) sve.push_back(b.at(i));
  else
  {
   sve.push_back(b.at(i));
   break;
  }
 }
 return sve;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(Vektor a,Smjer b)
{
 DekVektora rastuci;
 DekVektora opadajuci;
 int brojac(0);
 if(b==Rastuci)
 {
  if(a.size()==0) return rastuci;
  for(int i(0);i<a.size()-1;i++) 
  {	
   if(i==a.size()-1) break;
   if(a.at(i)<=a.at(i+1))
   {
    Vektor x(RastuciElementi(a,i));
    Vektor novi;
    brojac=0;
    for(int k : x)
    {
     if(DaLiJeStepenDvojke(k)==true) 
     {
      novi.push_back(k);
      brojac++;
     }
     else 
     {
      brojac++;
      break;
     }
    }
    if(novi.size()<=1) continue;
    rastuci.push_back(novi);
    i+=brojac-1;
   }
  }
 }
 else
 {
  if(a.size()==0) return opadajuci;
  for(int i(0);i<a.size()-1;i++)
  {
   if(i==a.size()-1) break;
   if(a.at(i)>=a.at(i+1))
   {
    Vektor y(OpadajuciElementi(a,i));
	   Vektor novi2;
   	brojac=0;
	   for(int r : y)
	   {
	    if(DaLiJeStepenDvojke(r)==true) 
	    {
	     novi2.push_back(r);
	     brojac++;
	    }
	    else 
	    {
	     brojac++;
	     break;
	    }
	   }
	   if(novi2.size()<=1) continue;
	   opadajuci.push_back(novi2);
	   i+=brojac-1;
   }
  }
 }
 if(b==Rastuci) return rastuci;
 else return opadajuci;
}

int main ()
{
 int n,unos;
 Vektor vek;
 std::cout << "Unesite broj elemenata vektora: ";
 std::cin >> n;
 std::cout << "Unesite elemente vektora: ";
 for(int i(0); i<n; i++) 
 {
  std::cin >> unos;
  vek.push_back(unos);
 }
 DekVektora max_rastuci(MaksimalniPodnizoviStepenaDvojke(vek,Rastuci));
 DekVektora max_opadajuci(MaksimalniPodnizoviStepenaDvojke(vek,Opadajuci));
 int k;
 std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
 unos:std::cin >> k;
 if(k==1) 
 {
  std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
  for(int i(0); i<max_rastuci.size(); i++) 
  {
   for(int j(0); j<max_rastuci.at(i).size(); j++) 
	  {
	   std::cout << max_rastuci.at(i).at(j) << " ";
	  }
	  std::cout << std::endl;
  }
 } 
 else if(k==2) 
 {
  std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
  for(int i(0); i<max_opadajuci.size(); i++) 
  {
   for(int j(0); j<max_opadajuci.at(i).size(); j++) 
   {
	   std::cout << max_opadajuci.at(i).at(j) << " ";
   }
   std::cout << std::endl;
  }
 } 
 else 
 {
  std::cout << "Neispravan unos! Unesite ponovo: ";
  goto unos;
 }
 return 0;
}