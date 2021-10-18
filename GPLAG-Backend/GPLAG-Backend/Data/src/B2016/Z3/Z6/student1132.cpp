/B2016/2017: Zadaća 3,  Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <memory>
int broj_slova(std::string s)
{
    int cnt = 0;
    for(auto e: s) cnt += ((e>='0' && e<='9') || (e>='a' && e<='z') || (e>='A' && e<='Z'));
    return cnt;
}

struct Dijete {
  std::string ime;
  std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> v, int tim)
{
     if(tim < 1 || tim > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
     std::shared_ptr<Dijete> pocetak, trenutni;
     pocetak = nullptr;
     pocetak = std::shared_ptr<Dijete>(new Dijete);
     pocetak->ime = v[0];
     trenutni = pocetak;
     for(int i=0; i<(int)v.size(); i++)
     {
           trenutni->ime = v[i];
           if(i == v.size()-1) trenutni->sljedeci = pocetak;
           else 
           {
             try
             {
               trenutni->sljedeci = nullptr;
               trenutni->sljedeci = std::shared_ptr<Dijete>(new Dijete);
               trenutni = trenutni->sljedeci;
             }
             catch(...)
             {
                for(int j=0;j<i;j++) {auto pom = pocetak->sljedeci; pocetak->sljedeci = nullptr; pocetak = pom;}
                throw;
             }
           }
     }
    std::vector<std::set<std::string> > rez(tim); 
    int vrti = 0;
    for(int t=0; t < tim; t++)
    {
        for(int c = 0; c < v.size()/tim + (t < v.size() % tim); c++)
        {
            for(int i=1; i<vrti; i++)
            {
                pocetak = pocetak->sljedeci;
                trenutni = trenutni->sljedeci;
            }
            vrti = broj_slova(pocetak->ime);
            rez[t].insert(pocetak->ime);
            auto pomocni = pocetak;
            pocetak = pocetak->sljedeci;
            pomocni->sljedeci = nullptr;
            if(trenutni != pomocni)
            trenutni->sljedeci = pocetak;
        }
    }
     
  
    return rez;
}

int main ()
{
  std::vector<std::string> v;
  int N;
  std::string s;
  std::cout<<"Unesite broj djece: ";
  std::cin>>N;
  std::cin.ignore(1000,'\n');
  std::cout<<"Unesite imena djece:\n";
  for(int i=0; i<N; i++)
  {
      std::getline(std::cin, s);
      v.push_back(s);
  }
  std::cout<< "Unesite broj timova: ";
  std::cin>> N;
  
  try
  {
      auto hehe = Razvrstavanje(v, N);
      for(int i=0;i<N;i++)
        {
            std::cout<< "Tim "<<i+1<<": ";
            for(auto e: hehe[i])
                if(*hehe[i].rbegin() != e) std::cout<<e<<", ";
                else std::cout<<e<<"\n";

        }
  }
  catch(std::logic_error e)
  {
      std::cout<<"Izuzetak: "<< e.what();
  }
  catch(...){}
	return 0;
}