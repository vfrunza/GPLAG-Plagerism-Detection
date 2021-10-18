/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <memory>
struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

bool SlovoIliCifra (char znak){
  return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
}



std::vector<std::set<std::string>> Razvrstavanje (const std::vector<std::string> &v, int k){
    if(k<1 || k>v.size())
      throw std::logic_error("Razvrstavanje nemoguce");
    int n(v.size());
    std::vector<int> niz(k);
    for(int i=0; i<k; i++){
        if(i<(n%k))
          niz[i] = (n/k) + 1;
        else
          niz[i] = (n/k);
    }
    std::vector<std::set<std::string>> v_skup(k);
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    for(int i=0; i<v.size(); i++){
      std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
      
      novi->ime = v[i];
      novi->sljedeci = nullptr;
      if(!pocetak) pocetak = novi;
      else prethodni->sljedeci = novi;
      prethodni = novi;
      
    }
    if(pocetak)
    prethodni->sljedeci = pocetak;
    int brojac(0), br(0);
    while(brojac<k){
      int br_igraca(0);
      while(br_igraca<niz[brojac]){
        int s = std::count_if(pocetak->ime.begin(), pocetak->ime.end(), SlovoIliCifra );
        v_skup[brojac].insert(pocetak->ime);
        br_igraca++;
        auto trenutni(pocetak->sljedeci);
        prethodni->sljedeci = trenutni;
        pocetak = trenutni;
        br++;
        if(br==v.size()){
          prethodni->sljedeci = nullptr;
          prethodni = nullptr;
          trenutni = nullptr;
          pocetak = nullptr;
          break;
        }
        int a(1);
        while(a<s){
          pocetak = pocetak->sljedeci;
          prethodni = prethodni->sljedeci;
          a++;
        }
      }
      brojac++;
    }
    return v_skup;
}



int main ()
{
  
  int n;
  std::cout<<"Unesite broj djece: ";
  std::cin>>n;
  std::cin.ignore(10000, '\n');
  std::vector<std::string> v(n);
  std::cout<<"Unesite imena djece: "<<std::endl;
  for(int i=0; i<n; i++)
    std::getline(std::cin, v[i]);
  std::cout<<"Unesite broj timova: ";
  int k;
  std::cin>>k;
  try{
  auto v_skup = Razvrstavanje(v, k);
  int brojac(0);
  for(auto skup : v_skup){
    int i(0);
    std::cout<<"Tim "<<brojac+1<<": ";
    for(auto x: skup){
      std::cout<<x;
      if(i!=skup.size() - 1)
        std::cout<<", ";
      i++;
    }
    std::cout<<std::endl; 
    brojac++;
  }
  }
  catch(std::logic_error e){
    std::cout<<"Izuzetak: "<<e.what();
  }
	return 0;
}