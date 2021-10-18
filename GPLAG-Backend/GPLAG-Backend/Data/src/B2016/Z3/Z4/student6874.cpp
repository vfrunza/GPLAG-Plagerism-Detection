/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>


std::vector <std::set<std::string>> Razvrstavanje (const std::vector<std::string> &v, int k){
    if(k<1 || k>v.size())
      throw std::logic_error("Razvrstavanje nemoguce");
    int n(v.size());
    std::vector<int> niz(k);
    for(int i=0; i<k; i++){
        if(i<n%k)
          niz[i] = (n/k) + 1;
        else
          niz[i] = (n/k);
    }
    std::vector<std::set<std::string>> v_skup(k) ;
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++)
      lista.push_back(v[i]);
    auto pocetak(lista.begin());
    int brojac(0);
    while (!lista.empty()) {
        int br_igraca(0);
        while(br_igraca!=niz[brojac]){
            int n;
            n = std::count_if((*pocetak).begin(),( *pocetak).end(), [] (char znak){
                return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
            });
            v_skup[brojac].insert(*pocetak);
            br_igraca++;
            pocetak = lista.erase(pocetak);
            if(lista.empty()) break;
            if(pocetak==lista.end()) pocetak = lista.begin();
            int k(1);
            while(k<n){
                pocetak++;
                if(pocetak==lista.end())
                  pocetak = lista.begin();
                k++;
            }
        }
    
        brojac++;
    }
    return v_skup;
}


int main ()
{
    
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite imena djece:"<<std::endl;
    std::vector<std::string> v(n);
    for(int i=0; i<n; i++)
      std::getline(std::cin, v[i]);
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
   
    try{
        auto v_skup = Razvrstavanje(v, k);
    
        int i(0);
        for(auto skup : v_skup){
          std::cout<<"Tim "<<i+1<<": ";
          int j(0);
          for(auto x : skup){
            std::cout<<x;
            j++;
            if(j!=skup.size())
            std::cout<<", ";
          }
        std::cout<<std::endl;
        i++;
        }
        
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}