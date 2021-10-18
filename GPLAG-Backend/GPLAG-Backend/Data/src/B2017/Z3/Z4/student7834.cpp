/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>
enum class Boje { Pik, Tref, Herc, Karo };

std::list<std::pair<Boje,std::string>> KreirajSpil()
{
 std::list<std::pair<Boje,std::string>> karte;
 std::pair<Boje,std::string> par;
 std::vector<Boje> bojekarti{Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
 std::vector<std::string> brojevikarti{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
 for(int i(0);i<bojekarti.size();i++)
 {
  for(int j(0);j<brojevikarti.size();j++)
  {
   par=std::make_pair(bojekarti[i],brojevikarti[j]);
   karte.push_back(par);
  }
 }
 return karte;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &multimapa)
{
 int brojac(0);
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  brojac++;
 }
 if(brojac>52) throw std::logic_error("Neispravna lista!");
 std::vector<std::string> brojevikarti{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  Boje b=it->first;
  while((it->first)==b)
  {
   int brojac2(0);
   std::string s=(it->second);
   for(int i(0);i<brojevikarti.size();i++)
   {
    if(s==brojevikarti[i]) brojac2++;
   }
   if(brojac2<1) throw std::logic_error("Neispravna lista!");
   it++;
  }
  it--;
  if((it->first)<b) throw std::logic_error("Neispravna lista!");
 }
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  auto prvi=(it->first);
  auto drugi=(it->second);
  for(auto it2(multimapa.begin());it2!=multimapa.end(); )
  {
   if(prvi==(it2->first) && drugi==(it2->second))
   {
    it=spil.erase(it);
    it2=multimapa.erase(it2);
   }
   else ++it2;
  }
 }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &r,const int &b)
{
 if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
 if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
 int br(0);
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  br++;
 }
 if(br>52) throw std::logic_error("Neispravna lista!");
 std::vector<std::string> elementi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  Boje b=it->first;
  while((it->first)==b)
  {
   int br2(0);
   std::string s=(it->second);
   for(int i(0);i<elementi.size();i++)
   {
    if(s==elementi[i]) br2++;
   }
   if(br2<1) throw std::logic_error("Neispravna lista!");
   it++;
  }
  it--;
  if((it->first)<b) throw std::logic_error("Neispravna lista!");
 }
 std::queue<std::pair<std::string,std::string>> izbacene;
 std::string pomocni;
 auto it(spil.begin());
 int brojac(0),n(1);
 while(1)
 {
  brojac++;
  if(n==b+1) break;
  if(it==spil.end()) it=spil.begin();
  if(r*n==brojac) 
  {
   if(it->first==Boje::Pik) pomocni="Pik";
   if(it->first==Boje::Tref) pomocni="Tref";
   if(it->first==Boje::Herc) pomocni="Herc";
   if(it->first==Boje::Karo) pomocni="Karo";
   izbacene.push(std::make_pair(pomocni,it->second));
   it=spil.erase(it);
   n++;
  }
  else ++it;
 }
 return izbacene;
}

bool kriterij(std::pair<Boje,std::string> par1, std::pair<Boje,std::string> par2)
{
 std::vector<std::string> elementi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
 if(par1.first>par2.first) return false;
 if(par1.first==par2.first)
 {
  int pozicija_par1(0),pozicija_par2(0);
  for(int i(0);i<elementi.size();i++)
  {
   if(par1.second==elementi[i]) pozicija_par1=i;
   if(par2.second==elementi[i]) pozicija_par2=i;
  }
  if(pozicija_par1<pozicija_par2) return true;
  else return false;
 }
 return true;
}

void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &red, int k)
{
 std::vector<std::string> elementi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
 std::vector<Boje> boje{ Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo };
 if(k<0) throw std::domain_error("Broj n je besmislen!");
 if(k>red.size()) throw std::range_error("Nedovoljno karata u redu!");
 int br(0);
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  br++;
 }
 if(br>52) throw std::logic_error("Neispravna lista!");
 for(auto it(spil.begin());it!=spil.end();it++)
 {
  Boje b=it->first;
  while((it->first)==b)
  {
   int br2(0);
   std::string s=(it->second);
   for(int i(0);i<elementi.size();i++)
   {
    if(s==elementi[i]) br2++;
   }
   if(br2<1) throw std::logic_error("Neispravna lista!");
   it++;
  }
  it--;
  if((it->first)<b) throw std::logic_error("Neispravna lista!");
 }
 Boje pomocni;
 int i(0);
 while(!red.empty() && i<k)
 {
  if(red.front().first=="Pik") pomocni=Boje::Pik;
  if(red.front().first=="Tref") pomocni=Boje::Tref;
  if(red.front().first=="Herc") pomocni=Boje::Herc;
  if(red.front().first=="Karo") pomocni=Boje::Karo;
  std::pair<Boje,std::string> par=std::make_pair(pomocni,red.front().second);
  int brojac1(0);
  for(int i(0);i<boje.size();i++)
  {
   if(par.first==boje[i]) brojac1++;
  }
  if(brojac1<1) throw std::logic_error("Neispravne karte!");
  int brojac2(0);
  for(int i(0);i<elementi.size();i++)
  {
   if(par.second==elementi[i]) brojac2++;
  }
  if(brojac2<1) throw std::logic_error("Neispravne karte!");
  spil.push_back(par);
  red.pop();
  i++;
 }
 spil.sort();
 spil.sort(kriterij);
}

int main ()
{
 try
 {
  int m,n,vrati;
  std::vector<Boje> boje{Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
  std::vector<std::string> boje2{"Pik","Tref","Herc","Karo"};
  std::list<std::pair<Boje,std::string>> lista;
  std::multimap<Boje,std::string> multimapa;
  //multimapa.insert({Boje::Pik,"4"});
  //multimapa.insert({Boje::Pik,"6"});
  std::cout << "Unesite korak razbrajanja: ";
  std::cin >> m;
  std::cout << "Unesite broj karata koje zelite izbaciti: ";
  std::cin >> n;
  lista=KreirajSpil();
  int ostalo=(52-n);
  IzbaciKarte(lista,multimapa);
  std::queue<std::pair<std::string,std::string>> red;
  red=IzbaciKarteRazbrajanjem(lista,m,n);
  std::cout << "U spilu trenutno ima " << ostalo << " karata, i to:" << std::endl;
  for(auto it(lista.begin());it!=lista.end(); )
  {
   if(it->first==Boje::Pik)
   {
    std::cout << "Pik: ";
    while(it->first==Boje::Pik)
    {
     std::cout << it->second << " ";
     it++;
    } 
   } 
   std::cout << std::endl;
   if(it->first==Boje::Tref) 
   {
    std::cout << "Tref: ";
    while(it->first==Boje::Tref)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
   if(it->first==Boje::Herc)
   {
    std::cout << "Herc: ";
    while(it->first==Boje::Herc)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
   if(it->first==Boje::Karo)
   {
    std::cout << "Karo: ";
    while(it->first==Boje::Karo)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
  }
  std::cout <<"Unesite broj karata koje zelite vratiti u spil: ";
  std::cin >> vrati;
  int nazad=ostalo+vrati;
  VratiPrvihNKarata(lista,red,vrati);
  std::cout << "U spilu trenutno ima " << nazad << " karata, i to: " << std::endl;
  for(auto it(lista.begin());it!=lista.end(); )
  {
   if(it->first==Boje::Pik)
   {
    std::cout << "Pik: ";
    while(it->first==Boje::Pik)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
   if(it->first==Boje::Tref)
   {
    std::cout << "Tref: ";
    while(it->first==Boje::Tref)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
   if(it->first==Boje::Herc)
   {
    std::cout << "Herc: ";
    while(it->first==Boje::Herc)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
   if(it->first==Boje::Karo)
   {
    std::cout << "Karo: ";
    while(it->first==Boje::Karo)
    {
     std::cout << it->second << " ";
     it++;
    }
   }
   std::cout << std::endl;
  }
 }
 catch(std::domain_error e)
 {
  std::cout << "Izuzetak: " << e.what() << std::endl;
 }
 catch(std::logic_error e)
 {
  std::cout << "Izuzetak: " << e.what() << std::endl;
 }
 catch(std::range_error e)
 {
  std::cout << "Izuzetak: " << e.what() <<std::endl;
 }
 return 0;
}
