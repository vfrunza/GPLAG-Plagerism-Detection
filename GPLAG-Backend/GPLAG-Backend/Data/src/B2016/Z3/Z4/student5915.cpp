#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int k){
     if(k < 1 || k > imena.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
     std::vector<std::set<std::string>> timovi(k);
     std::list<std::string> lista;
     lista.resize(imena.size());
     auto it(lista.begin());
     int i(0);
     while(it != lista.end()){
         *it = imena[i];
         it++;
         i++;
     }
     int vel_liste(lista.size());
     std::advance(it, -lista.size());
     for(int i = 0; i < (vel_liste % k); i++){
          for(int j = 0; j < ((vel_liste / k) + 1); j++){
               int duzina(0);
               int brojac(0);
               if(i == 0 && j == 0) {
                    timovi[i].insert(*it);
                    j++;
               }
               for(int z = 0; z < (*it).length(); z++){
                 if(((*it)[z] >= '0' && (*it)[z] <= '9') || ((*it)[z] >= 'A' && (*it)[z] <= 'Z') ||  ((*it)[z] >= 'a' && (*it)[z] <= 'z')) 
                     duzina++;
               }
                 it = lista.erase(it);
                 if(lista.size() == 0) break;
                 if(it == lista.end())
                    std::advance(it, -lista.size());
               while(brojac < (duzina - 1)){
                    it++;
                    brojac++;
                    if(it == lista.end())
                         std::advance(it, -lista.size());
               }
               timovi[i].insert(*it);
               
     }
     if (lista.size() == 0) break;
     }
     if(lista.size() != 0){
     for(int i = (vel_liste % k); i < k; i++){
          for(int j = 0; j < (vel_liste / k ); j++){
               int duzina(0);
               int brojac(0);
               if(i == 0 && j == 0){
                    timovi[i].insert(*it);
                    j++;
                    if(vel_liste / k == 1) break;
               }
               for(int z = 0; z < (*it).length(); z++){
                 if(((*it)[z] >= '0' && (*it)[z] <= '9') || ((*it)[z] >= 'A' && (*it)[z] <= 'Z') ||  ((*it)[z] >= 'a' && (*it)[z] <= 'z'))
                  duzina++;
               }
                 it = lista.erase(it);
                 if(lista.size() == 0) break;
                 if(it == lista.end())
                    std::advance(it, -lista.size());
               while(brojac < (duzina - 1)){
                    it++;
                    brojac++;
                    if(it == lista.end())
                    std::advance(it, -lista.size());
               }
               timovi[i].insert(*it);
               
     }
     if(lista.size() == 0) break;
     }
     }
return timovi;

}


int main (){
     try{
     
          int n,k;
          std::cout<<"Unesite broj djece: ";
          std::cin >> n;
          std::vector<std::string>imena;
          imena.resize(n);
          std::cin.ignore(10000, '\n');
          std::cout <<"Unesite imena djece: "<< std::endl;
          for(int i = 0; i < n; i++){
           std::getline(std::cin, imena[i]);
          }
          std::cout << "Unesite broj timova: ";
          std::cin >> k;
          
          auto v(Razvrstavanje(imena,k));
        for(int i = 0; i < v.size(); i++) {
            std::cout << "Tim " << i + 1 << ": ";
            for(auto it = v[i].begin(); it != v[i].end(); it++) {
                it++;
                if(it == v[i].end()) {
                     it--;
                     std::cout << *it;
                }
                else {
                     it--;
                     std::cout << *it << ", ";
                }
            }
                std::cout << std::endl;
        }
     }
     catch(std::logic_error e) {
         std::cout << e.what();
    }
     
     
	return 0;
}