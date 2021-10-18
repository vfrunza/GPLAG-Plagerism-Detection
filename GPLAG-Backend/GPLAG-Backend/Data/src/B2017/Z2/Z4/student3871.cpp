/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <stdexcept>
#include <vector>

int BrojProstihFaktora(int a)
{
 int br(0);
 if(a<0) a*=-1;
 if(a==1 || a==0) return 1;
 int k=a%2;
 while(k==0)
 {
  a/=2;
  br++;
  k=a%2;
 }
 for(int j(3);j<=a;j+=2)
 {
  int k=a%j;
  while(k==0)
  {
   a/=j;
   br++;
   k=a%j;
  }
 }
 return br;
}

bool kriterij(int x,int y)
{
 int br1(BrojProstihFaktora(x));
 int br2(BrojProstihFaktora(y));
 if(br1==br2) return x>y;
 return br1>br2;
}

int f(int x, int y)
{
 return (-2)*x+y;
}

template<typename Pok1,typename Pok2,typename Pok3>
void SortirajPodrucjeVrijednosti(Pok1 pocetak,Pok1 kraj,Pok2 pocetak2,Pok3 pocetak3,typename std::remove_reference<decltype(*pocetak3)>::type f(typename std::remove_reference<decltype(*pocetak)>::type,typename std::remove_reference<decltype(*pocetak2)>::type),bool kriterij(typename std::remove_reference<decltype(*pocetak)>::type,typename std::remove_reference<decltype(*pocetak2)>::type))
{
 int brojac(0);
 int br2(0),pozicija(0);
 auto pomocni3(*pocetak3);
 typename std::remove_reference<decltype(*pocetak3)>::type br{};
 Pok1 pomocni(pocetak);
 while(pocetak!=kraj)
 {
  brojac++;
  pocetak++;
 }
 pocetak=pomocni;
 std::sort(pocetak,kraj,kriterij);
 std::sort(pocetak2,pocetak2+brojac,kriterij);
 for(int i(0);i<brojac;i++)
 {
  pomocni3=*(pocetak3+i);
  br=f(*(pocetak+i),*(pocetak2+i));
  br2=0;
  pozicija=0;
  for(int j(0);j<brojac;j++)
  {
   if(br==*(pocetak3+j)) 
   { 
    br2++;
    pozicija=j;
    break;
   }
  }
  if(br2==0) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
  *(pocetak3+i)=*(pocetak3+pozicija);
  *(pocetak3+pozicija)=pomocni3;
 }
}

int main ()
{
 try
 {
  int n,unos,brojac(0);
  std::cout << "Unesite broj elemenata: ";
  std::cin >> n;
  std::vector<int> vek1;
  std::vector<int> vek2;
  std::vector<int> vek3;
  std::cout << "Unesite elemente prvog vektora: ";
  for(int i(0); ;i++)
  {
   if(vek1.size()==n) break;
   std::cin >> unos;
   brojac=0;
   for(int j(0);j<vek1.size();j++)
   {
    if(unos==vek1[j]) brojac++;
   }
   if(brojac>=1) continue;
   vek1.push_back(unos);
  }
  std::cout << "Unesite elemente drugog vektora: ";
  for(int i(0); ;i++)
  {
   if(vek2.size()==n) break;
   std::cin >> unos;
   brojac=0;
   for(int j(0);j<vek2.size();j++)
   {
    if(unos==vek2[j]) brojac++;
   }
   if(brojac>=1) continue;
   vek2.push_back(unos);
  }
  std::cout << "Unesite elemente treceg vektora: ";
  for(int i(0); ;i++)
  {
   if(vek3.size()==n) break;
   std::cin >> unos;
   brojac=0;
   for(int j(0);j<vek3.size();j++)
   {
    if(unos==vek3[j]) brojac++;
   }
   if(brojac>=1) continue;
   vek3.push_back(unos);
  }
  std::cout << std::endl;
  SortirajPodrucjeVrijednosti(vek1.begin(),vek1.end(),vek2.begin(),vek3.begin(),f,kriterij);
  std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
  for(int i(0);i<vek1.size();i++)
  {
   std::cout << "f(" << vek1[i] << ", " << vek2[i] << ") = " << f(vek1[i],vek2[i]) <<std::endl;
  }
 }
 catch(std::logic_error e)
 {
  std::cout << "Izuzetak: " << e.what();
 }
 return 0;
}