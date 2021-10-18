/*B 2017/2018, Zadaća 2, Zadatak 3
	
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
#include <stdexcept>
#include <new>
#include <iomanip>
#include <cmath>

int ZbirElemenata(std::vector<int> v)
{
 int zbir(0);
 for(int i(0);i<v.size();i++)
 {
  zbir+=v.at(i);
 }
 return zbir;
}
int NadjiMax(std::vector<int> v)
{
 int max(0);
 for(int i(0);i<v.size();i++)
 {
  if(v.at(i)>max) max=v.at(i);
 }
 return max;
}
bool DaLiJePeriodican(std::vector<int>vek,int p)
{
 if(p<1 || p>=vek.size()) return false;
 else
 {
  for(int i(0);i<vek.size()-p;i++)
  {
   if(vek.at(i)!=vek.at(i+p)) return false;
  }
 }
 return true;
}

int OsnovniPeriod(std::vector<int> vektor)
{
 for(int i(1);i<vektor.size();i++)
 {
  if(DaLiJePeriodican(vektor,i)) return i;
 }
 return 0;
}
int **AlocirajKontinualno(const std::vector<int> &v,int &koliko_puta)
{
 int granica_redova(0),viska(0),dodaj(0),zbir(0);
 if(v.size()==0) throw std::domain_error("Prazan vektor!");
 for(int i(0);i<v.size();i++)
 {
  if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
 }
 int period=OsnovniPeriod(v);
 if(period>0)
 {
  viska=v.size()%period;
  if(viska==0)
  {
   granica_redova=v.size();
   goto dalje;
  }
  dodaj=period-viska; 
  granica_redova=v.size()+dodaj;
  dalje: koliko_puta=int(granica_redova/period);
 }
 else
 {
  koliko_puta=2;
 }
 int **p=nullptr;
 try
 {
  p=new int*[granica_redova];
  try
  {
   zbir=ZbirElemenata(v);
   p[0]=new int[zbir];
   for(int i(1);i<granica_redova;i++)
   {
    p[i]=p[i-1]+v.at(i-1);
   }
   for(int i(0);i<granica_redova;i++)
   {
    for(int j(0);j<v.at(i);j++)
    {
     if(i==j || j==i-((i-j)/period)*period) p[i][j]=1;
     else p[i][j]=p[i-1][j]+1;
    }
   }
   return p;
  }
  catch(std::bad_alloc)
  {
   for(int i(0);i<granica_redova;i++)
   {
    delete[] p[i];
   }
   delete[] p;
   throw;
  }
 }
 catch(std::bad_alloc)
 {
  delete p;
  throw;
 }
}
int **AlocirajFragmentirano(const std::vector<int> &v, int &koliko_puta) 
{
  int granica_redova(0),viska(0),dodaj(0);
  if(v.size()==0) throw std::domain_error("Prazan vektor!");
  for(int i(0);i<v.size();i++)
  {
   if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
  }
  int period=OsnovniPeriod(v);
  if(period>0) 
  {
   viska=v.size()%period;
   if(viska==0)
   {
    granica_redova=v.size();
    goto dalje;
   }
   dodaj=period-viska;
   granica_redova=v.size()+dodaj;
   dalje: koliko_puta=int(granica_redova/period);
  }
  else
  {
   koliko_puta=2;
  }
  int **p=nullptr;
  try
  {
   p=new int*[granica_redova];
   try
   {
    for(int i(0);i<granica_redova;i++)
    {
     /*if(i>=v.size())
     {
      p[i]=new int[v.at(i%koliko_puta-1)];
     }
     else */p[i]=new int[v[i]];
    }
    for(int i(0);i<granica_redova;i++)
    {/*
     if(i>=v.size())
     {
      for(int j(v.at(i%koliko_puta-1));j<v.at(i%koliko_puta-1+dodaj);j++)
      {
       p[i][j]=1;
      }
     }
     else
     {*/
     for(int j(0);j<v.at(i);j++)
     {
      if(i==j || j==i-((i-j)/period)*period) p[i][j]=NadjiMax(v);
      else p[i][j]=p[i-1][j]-1;
     }
    }
    return p;
   }
   catch(std::bad_alloc)
   {
    for(int i(0);i<granica_redova;i++)
    {
     delete[] p[i]; 
    }
    delete[] p;
    throw;
   }
  }
  catch(std::bad_alloc)
  {
   delete p;
   throw;
  }
}

int main ()
{
 try
 {
  int n,unos,k(0),koliko_puta(0),u(0);
  std::cout << "Unesite broj elemenata vektora: ";
  std::cin >> n;
  std::vector<int> vek(0);
  std::cout << "Unesite elemente vektora: ";
  for(int i(0);i<n;i++)
  {
   std::cin >> unos;
   vek.push_back(unos);
  }
  std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
  std::cin >> k;
  if(k==1)
  {
   auto niz = AlocirajFragmentirano(vek,koliko_puta);
   std::cout << "Dinamicki alocirana matrica: " << std::endl;
   //u=int(vek.size()/koliko_puta);
   for(int i(0);i<(vek.size()+u);i++)
   {
    /*if(i>=vek.size())
    {
     for(int j(vek.at(i%koliko_puta-1));j<vek.at(i%koliko_puta-1+u);j++)
     {
      std::cout << niz[i][j] << " ";
     }
    }
    else
    {*/
    for(int j(0);j<vek.at(i);j++)
    {
     std::cout << std::left << std::setw(3) << niz[i][j];
    }
   delete[] niz[i];
   std::cout << std::endl;
   }
   delete[] niz;
  }
  else if(k==0)
  {
   auto niz = AlocirajKontinualno(vek,koliko_puta);
   std::cout << "Dinamicki alocirana matrica: " << std::endl;
   //u=int(vek.size()/koliko_puta);
   for(int i(0);i<(vek.size()+u);i++)
   {
    for(int j(0);j<vek[i];j++)
    {
     std::cout << std::left << std::setw(3) << niz[i][j];
    }
    std::cout << std::endl;
   }
   delete[] niz[0];
   delete[] niz;
  }
 }
 catch(std::domain_error e)
 {
  std::cout << "Izuzetak: " << e.what();
 }
 catch(std::bad_alloc e)
 {
  std::cout << "Nedovoljno memorije!";
 }
 return 0;
}