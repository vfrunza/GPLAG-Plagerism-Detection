/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <list>
#include <iomanip>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n){
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista;
    //std::list<std::string>::iterator it(lista.begin());
    for(int i=0;i<v.size();i++){
        lista.push_back(v[i]);

    }// prepisivanje u listu
   // std::cout<<"Prepisano u listu: ";
   // for(auto x : lista) std::cout << x << " ";

    //prvo odrediti koliko timova se moze napraviti i koliko oni mogu imati clanova
    int broj_clanova1,broj_clanova2,br_sa_vise,br_sa_manje;
    if(v.size()%n==0){
        broj_clanova1=broj_clanova2=v.size()/2;
        br_sa_vise=n-1;
        br_sa_manje=1;
    }else{
            broj_clanova1=(v.size()/n+1);
            broj_clanova2=(v.size()/n);
            br_sa_vise=(v.size()%n);
            br_sa_manje=(n-br_sa_vise);
    }



    std::vector<std::set<std::string>> povratni;
    std::set<std::string> timovi;
    std::list<std::string>::iterator it(lista.begin());
    std::list<std::string>::iterator it1(lista.begin());
     timovi.insert(*it);
    it=lista.erase(it);
    for(int i=0;i<1;i++){
           for(int j=0;j<broj_clanova1-1;j++){
              std::string pom(*it1);
              int brojac(0);
              for(int k=0;k<pom.size();k++){
                  if((pom[k]>'a' && pom[k]<'z') || (pom[k]>'A' && pom[k]<'Z') || (pom[k]>48 && pom[k]<57)) brojac++;
              }
           for(int k=0;k<brojac;k++){
               if(it==lista.end()) it=lista.begin();
               it++;
           }
                    it--;
                    it1=it;
                   timovi.insert(*it);
                   it=lista.erase(it);
       }
        povratni.push_back(timovi);
    }
     // std::cout<<"opeta na *it1 "<<*it1;
   for(int i=0;i<br_sa_vise-1;i++){
            std::set<std::string> timovi;
           for(int j=0;j<broj_clanova1;j++){
              int brojac((*it1).size());
           for(int k=0;k<brojac;k++){
               if(it==lista.end()) it=lista.begin();
               it++;
           }
                    it--;
                    it1=it;
                      //std::cout<<"opeta na *it1 "<<*it1;
                   timovi.insert(*it);
                   it=lista.erase(it);
       }
        povratni.push_back(timovi);
    }




        // std::list<std::string>::iterator it2(it1);
        it--;
      // std::cout<<"sad na *it "<<*it;
    for(int i=0;i<br_sa_manje;i++){
              std::set<std::string> timovi1;
           for(int j=0;j<broj_clanova2;j++){
              int brojac((*it1).size());
          for(int k=0;k<brojac;k++){
               if(it==lista.end()) it=lista.begin();
               it++;
           }
                    it--;
                    it1=it;
                   timovi1.insert(*it);
                   it=lista.erase(it);

       }
        povratni.push_back(timovi1);

    }
    return povratni;

}


int main ()
{
    try{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> v;
    std::string pom;
      std::cin.clear();
       std::cin.ignore(1000 , '\n');
    for(int i=0;i<n;i++){
       std::getline(std::cin,pom);
        v.push_back(pom);
         std::cin.clear();
    }
    //std::cout<<"Imena iz vekotra: "<<std::endl;
    //for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    //std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    int m;
    std::cin>>m;
    auto p(Razvrstavanje(v,m));
    
       
        for(int i=0;i<p.size();i++){
             std::cout<<"Tim "<<i+1<<": ";
             std::set<std::string>::iterator it(p[i].begin());
            for(int j=0;j<p[i].size()-1;j++) {
                std::cout<<*it<<", ";
                it++;
            }
            std::cout<<*it;
            std::cout<<std::endl;
        }}
        catch(std::logic_error izuzetak){
             std::cout<<"Izuzetak: "<<izuzetak.what();
        }
        

    
	return 0;
}