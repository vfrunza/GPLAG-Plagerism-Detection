/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#include <stdexcept>
typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> IndexPojmova;

bool Ponavljanje(IndexPojmova cijeli, std::string trazim)
{
 for(auto it(cijeli.begin());it!=cijeli.end();it++)
 {
  if(it->first==trazim) return true;
 }
 return false;
}

IndexPojmova KreirajIndeksPojmova(Knjiga objekat)
{
 IndexPojmova vrati;
 for(auto it(objekat.begin());it!=objekat.end();it++)
 {
  auto pomocni=it->first;
  auto vek=it->second;
  for(auto i(0);i<vek.size();i++)
  {
   auto s=vek[i];
   for(int j(0);j<s.length();j++)
   {
    for(int k(0);k<s.length();k++)
    {
     if(s[k]>='A' && s[k]<='Z') s[k]=std::tolower(s[k]);
    }
    if(s[j]!=' ')
    {
     int pozicija(0);
     auto pomocni_brojac=j;
     while(pomocni_brojac<s.length() && s[pomocni_brojac]!=' ') pomocni_brojac++;
     pozicija+=j;
     auto pom=s.substr(j,pomocni_brojac-j);
     if(!Ponavljanje(vrati,pom))
     {
      int stranica=i+1;
      std::tuple<std::string,int,int> pomocni_tuple=std::make_tuple(pomocni,stranica,pozicija);
      std::set<std::tuple<std::string,int,int>> pomocni_set;
      pomocni_set.insert(pomocni_tuple);
      vrati.insert(std::make_pair(pom,pomocni_set));
     }
     else
     {
      auto pom_it(vrati.find(pom));
      auto str=i+1;
      auto tapl=std::make_tuple(pomocni,str,pozicija);
      pom_it->second.insert(tapl);
     }
     j=pomocni_brojac;
    }
   }
  }
 }
 return vrati;
}

void IspisiSkup(std::set<std::tuple<std::string,int,int>> s)
{ 
 for(auto it(s.begin());it!=s.end();it++)
 {
  auto prije_kraja=s.end();
  if (it==(--prije_kraja)) std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
  else std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << ", ";
 }
}

void IspisiIndeksPojmova(IndexPojmova index)
{
 for(auto it(index.begin());it!=index.end();it++)
 {
  if(it!=index.begin()) std::cout << std::endl;
  std::cout << it->first << ": ";
  auto skup=it->second;
  IspisiSkup(skup);
 }
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, IndexPojmova pojam)
{
 int brojac(0);
 for(auto it(pojam.begin());it!=pojam.end();it++)
 {
  if(it->first==rijec) brojac++;
 }
 if(brojac<1) throw std::logic_error("Pojam nije nadjen");
 auto nadji(pojam.find(rijec));
 if(nadji==pojam.end()) throw std::logic_error("Unesena rijec nije nadjena!");
 return nadji->second;
}

int main ()
{
 Knjiga mapa;
 while(1)
 {
  std::string naziv;
  std::cout << "Unesite naziv poglavlja: ";
  std::getline(std::cin,naziv);
  int i(1);
  if(naziv==".") break;
  std::vector<std::string> vektor;
  while(1)
  {
   std::string sadrzaj;
   std::cout << "Unesite sadrzaj stranice " << i << ": ";
   std::getline(std::cin,sadrzaj);
   if(sadrzaj==".") break;
   vektor.push_back(sadrzaj);
   i++;
  }
  mapa.insert(std::make_pair(naziv,vektor));
 }
 std::cout << std::endl;
 std::cout << "Kreirani indeks pojmova:" << std::endl;
 auto indeks_pojmova=KreirajIndeksPojmova(mapa);
 IspisiIndeksPojmova(indeks_pojmova);
 std::cout << std::endl;
 while(1)
 {
  try
  {
   std::string rijec;
   std::cout << "Unesite rijec: ";
   std::getline(std::cin,rijec);
   if(rijec==".") break;
   auto mapa2=PretraziIndeksPojmova(rijec,indeks_pojmova);
   for(auto x(mapa2.begin());x!=mapa2.end();x++) 
   {
    auto test(mapa2.end());
    if(x==(--test)) std::cout << std::get<0>(*x) << "/" << std::get<1>(*x) << "/" << std::get<2>(*x);
    else std::cout << std::get<0>(*x) << "/" << std::get<1>(*x) << "/" << std::get<2>(*x) << " ";
   }
   std::cout << std::endl;
  }
  catch(std::logic_error e)
  {
   std::cout << "Unesena rijec nije nadjena!" << std::endl;
  }
 }
 return 0;
}
