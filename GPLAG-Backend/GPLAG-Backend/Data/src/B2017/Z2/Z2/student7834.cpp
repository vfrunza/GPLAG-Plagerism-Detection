/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
#include <type_traits>
#include <stdexcept>
enum class SmjerKretanja{NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};

template<typename Tip>
Tip PjescaniSat(Tip kont,SmjerKretanja smjer)
{
 Tip pomocni;
 if(kont.size()==0) return pomocni;
 typename std::remove_reference<decltype(kont[0][0])>::type vek1;
 typename std::remove_reference<decltype(kont[0])>::type vek2;
 if((kont.size()!=kont[0].size())||(kont.size()!=kont[0][0].size())||(kont[0].size()!=kont[0][0].size()))
  throw std::domain_error("3D matrica nema oblik kocke");
 for(int i(0);i<kont.size();i++)
 {
  if(kont[0].size()%2==0 || kont[0][0].size()%2==0)
   throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
 }
 if(smjer==SmjerKretanja::GoreDolje)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(0);j<kont[0].size();j++)
   {
    for(int k(0);k<kont[0][0].size();k++)
    {
     if(j==0 || j==kont[0].size()-1)
     {
      if(k>=0 && k<kont[0][0].size())
      {
       vek1.push_back(kont[i][j][k]);
      }
     }
     else 
     {
      if(j==k)
      vek1.push_back(kont[i][j][k]);
     }
    }
    vek2.push_back(vek1);
    vek1.clear();
   }
   pomocni.push_back(vek2);
   vek2.clear();
  }
 } 
 else if(smjer==SmjerKretanja::DoljeGore)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(kont[0].size()-1);j>=0;j--)
   {
    for(int k(0);k<kont[0][0].size();k++)
    {
    	if(j==0 || j==kont[0].size()-1)
    	{
    	 if(k>=0 && k<kont[0][0].size())
    	 {
    	  vek1.push_back(kont[i][j][k]);
    	 }
    	}
    	else if(j==k)
    	vek1.push_back(kont[i][j][k]);
    }
    vek2.push_back(vek1);
    vek1.clear();
   }
   pomocni.push_back(vek2);
   vek2.clear();
  }
 }
 else if(smjer==SmjerKretanja::LijevoDesno)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(0);j<kont[0][0].size();j++)
   {
    for(int k(0);k<kont[0].size();k++)
    {
     if(j==0 || j==kont[0][0].size()-1)
     {
      if(k>=0 && k<kont[0].size())
      {
       vek1.push_back(kont[i][k][j]);
      }
     }
     else if(j==k)
     vek1.push_back(kont[i][j][k]);
    }
    vek2.push_back(vek1);
    vek1.clear();
   }
   pomocni.push_back(vek2);
   vek2.clear();
  }
 }
 else if(smjer==SmjerKretanja::DesnoLijevo)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(kont[0][0].size()-1);j>=0;j--)
   {
   	for(int k(0);k<kont[0].size();k++)
   	{
   	 if(j==0 || j==kont[0][0].size()-1)
   	 {
   	  if(k>=0 && k<kont[0].size())
   	  {
   	   vek1.push_back(kont[i][k][j]);
   	  }
   	 }
   	 else if(j==k)
   	 vek1.push_back(kont[i][j][k]);
   	}
   	vek2.push_back(vek1);
   	vek1.clear();
   }
   pomocni.push_back(vek2);
   vek2.clear();
  }
 }
 else if(smjer==SmjerKretanja::NaprijedNazad)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(0);j<kont[0].size();j++)
   {
    for(int k(0);k<kont[0][0].size();k++)
    {
     
    }
   }
  }
 }
 else if(smjer==SmjerKretanja::NazadNaprijed)
 {
  for(int i(0);i<kont.size();i++)
  {
   for(int j(0);j<kont[0].size();j++)
   {
    for(int k(0);k<kont[0][0].size();k++)
    {
     
    }
   }
  }
 }
 return pomocni;
}
int main ()
{
 try
 {
  int n,nekibroj;
  std::vector<std::deque<std::deque<double>>> kon;
  std::cout << "Unesite dimenziju (x/y/z): ";
  unos: std::cin >> n;
  if(n<0) 
  {
   std::cout << "Dimenzija nije ispravna, unesite opet: ";
   goto unos;
  }
  std::cout << "Unesite elemente kontejnera: ";
  kon.resize(n);
  for(int i(0);i<n;i++) kon[i].resize(n);
  for(int i(0);i<n;i++)
  {
   for(int j(0);j<n;j++)
   {
    kon[i][j].resize(n);
   }
  }
  for(int i(0);i<n;i++)
  {
   for(int j(0);j<n;j++)
   {
    for(int k(0);k<n;k++)
    {
     std::cin >> kon.at(i).at(j).at(k);
    }
   }
  }
  std::cout << "Unesite smjer kretanja [0 - 5]: ";
  unesi: std::cin >> nekibroj;
  if(nekibroj<0 || nekibroj>5)
  {
   std::cout << "Smjer nije ispravan, unesite opet: ";
   goto unesi;
  }
  std::cout << std::endl;
  auto kocka=PjescaniSat(kon,SmjerKretanja(nekibroj));
  std::cout << "Pjescani sat unesene matrice je: ";
  std::cout << std::endl;
  for(int i(0);i<n;i++)
  {
   for(int j(0);j<n;j++)
   {
    for(int k(0);k<kocka.at(i).at(j).size();k++)
    {
     if(!(j==0 || j==n-1)) std::cout << std::setw(8) << kocka[i][j][k];
     else std::cout << std::setw(4) << kocka[i][j][k];
    }
    std::cout << std::endl;
   }
   std::cout << std::endl;
  }
 }
 catch(std::domain_error e)
 {
  std::cout << "Izuzetak: " << e.what();
 }
 catch(std::length_error izuzetak)
 {
  std::cout << "Izuzetak: " << izuzetak.what();
 }
 return 0;
}