/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int n) {
    std::vector<std::set<std::string>> v;
    std::list<std::string> lista;
    int brtimova, brtimova1;
    int brclanova, brclanova1;
    brtimova=s.size()%n;
    brclanova=s.size()/n+1;
    brtimova1=n-brtimova;
    brclanova1=s.size()/n;
    for (auto iter=s.begin(); iter!=s.end(); iter++ ) {
        lista.push_back((*iter));
    }
    std::set<std::string> skup;
    auto it(lista.begin());
    int vel_imena;
        for(int i=0;i<brtimova;i++){
                    for(int k=0;k<brclanova;k++){
                        vel_imena=(*it).size();
                        skup.insert(*it);
                        lista.erase(it);
                        std::advance(it,vel_imena);
                        if(it==lista.end()){
                            auto it2(std::distance(it,lista.end()));
                            it=lista.begin();
                            std::advance(it,it2);
                    }
                }
                v.push_back(skup);
         }
         for(int i=0;i<brtimova1;i++){
                    for(int k=0;k<brclanova1;k++){
                        vel_imena=(*it).size();
                        skup.insert(*it);
                        lista.erase(it);
                        std::advance(it,vel_imena);
                        if(it==lista.end()){
                            auto it2(std::distance(it,lista.end()));
                            it=lista.begin(); 
                            std::advance(it,it2);
                    }
                }  
                v.push_back(skup);
        }
return v;
}

int main ()
{
    std::string string;
    std::vector<std::string> v;
    int broj_djece;
    int broj_timova;
    try {
        int i=0;
        std::cout<<"Unesite broj djece: "<<std::endl;
        std::cin>>broj_djece;
        std::cout<<"Unesite imena djece: "<<std::endl;
        while(i<=broj_djece) {
            std::getline(std::cin,string);
            v.push_back(string);
            i++;
        }
        std::cout<<"Unesite broj timova: ";
        std::cin>>broj_timova;
        if(broj_timova>broj_djece || broj_timova<1)
            throw std::logic_error("Razvrstavanje nemoguce");

        else {                                          /* glavni dio programa */
            std::vector<std::set<std::string>> skup;
            skup=Razvrstavanje(v,broj_timova);
              for(int i=0;i<broj_timova;i++){
                  std::cout<<"Tim "<<i+1<<": ";
                  for(auto it=skup[i].begin();it!=skup[i].end();it++){
                  std::cout<<*it<<", "; }
                  std::cout<<std::endl;
              }
        }
    } catch(std::logic_error greska) {
        std::cout<<greska.what();
    }
    return 0;
}