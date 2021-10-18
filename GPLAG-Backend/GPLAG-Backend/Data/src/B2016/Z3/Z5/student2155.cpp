#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
struct Dijete{
  std::string ime;
  Dijete* sljedeci;
};
int BrojSlovaiCifara(std::string s){
  int brojac(0);
  for(int i(0);i < s.length();i++){
    if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')brojac++;
  }
  return brojac;
}
int BrojDjece(Dijete *pocetak){
  Dijete* p(pocetak);
  int brojac(1);
  while(p->sljedeci != pocetak)brojac++,p=p->sljedeci;
  return brojac;
}
Dijete* IzbrisiPocetak(Dijete* p){
  if(!p)return nullptr;
  Dijete* tmp(p->sljedeci);
  if(p==p->sljedeci){
    delete p;
    return nullptr;
  }
  while(tmp->sljedeci != p){
    tmp=tmp->sljedeci;
  }
  tmp->sljedeci=p->sljedeci;
  delete p;
  return tmp->sljedeci;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int k){
    std::vector<std::set<std::string>> timovi(k);
    if(k < 1 || k > v.size())throw std::logic_error("Razvrstavanje nemoguce");
//Stvaranje kruzne liste
    Dijete* pocetak(nullptr),*prethodni(nullptr);
    try{
    for(int i(0);i < v.size();i++){
      Dijete *novi = new Dijete;
      novi->ime=v[i];novi->sljedeci = nullptr;
      if(!pocetak) pocetak = novi;
      else prethodni->sljedeci = novi;
      prethodni = novi;
    }
    if(prethodni)
      prethodni->sljedeci=pocetak;
    }catch(std::bad_alloc){
      while(pocetak->sljedeci){
        auto tmp(pocetak);
        pocetak=pocetak->sljedeci;
        delete tmp;
      }
    }
    int tmp(BrojDjece(pocetak));
    int mod(tmp%k);
    for(int i(0);i < k;i++){
      int djece_u_timu;
      if(tmp%k != 0 && mod){djece_u_timu=tmp/k+1;mod--;}
      else djece_u_timu=tmp/k;
      for(int j(0);j < djece_u_timu;j++){
        
        int broj(BrojSlovaiCifara(pocetak->ime)-1);
        timovi[i].insert(pocetak->ime);
        pocetak=IzbrisiPocetak(pocetak);
        if(!pocetak)break;
        while(broj){
          pocetak=pocetak->sljedeci;
          broj--;
        }
      }
    }
    return timovi;
}

int main ()
{
  int k,broj_djece;
  std::vector<std::string> djeca;
  std::vector<std::set<std::string>> timovi;
  std::cout << "Unesite broj djece: ";
  std::cin >> broj_djece;
  std::cin.ignore(10000,'\n');
  std::cout << "Unesite imena djece: ";
  for(int i(0);i < broj_djece;i++){
    std::string s;
    std::getline(std::cin,s);
    djeca.push_back(s);
  }
  std::cout << "\nUnesite broj timova: ";
  std::cin >> k;
  try{
    timovi = Razvrstavanje(djeca,k);
  }catch(std::logic_error izuzetak){
    std::cout << "Izuzetak: " << izuzetak.what();
    return 0;
  }catch(std::bad_alloc){
    return 0;
  }
    for(int i(0);i < timovi.size();i++){
      std::cout << "Tim " << i+1 << ": ";
      auto it(timovi[i].begin());
      std::cout << *it++;
      while(it != timovi[i].end())std::cout << ", " << *it++;
      std::cout << std::endl;
    }
  
	return 0;
}