#include <iostream>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Tip;

bool JeLiSlovoIliBroj(char znak) {
      if(znak>='a' && znak<='z' || znak>='A' && znak<='Z' || znak>='0' && znak<='9') return true;
      return false;
}



Tip KreirajIndeksPojmova(Knjiga lolita) {
      Tip indexi; 
      int i=0;
      int j=0;
      for(auto it1=lolita.begin(); it1!=lolita.end(); it1++) {
            j=0;
      for(auto it2=(it1->second).begin(); it2!=(it1->second).end(); it2++) {
            i=0; 
            j++;
            for(auto it3=(*it2).begin(); it3<(*it2).end(); it3++) {
                  if(!JeLiSlovoIliBroj(*it3)) {i++; continue;}
                  else {
                        i++;
                        std::string pomocni;
                        int zapamceno_i;
                        zapamceno_i=i;
                        while(JeLiSlovoIliBroj(*it3)) {
                              if(it3==(*it2).end()) break; 
                              if(*it3>='A' && *it3<='Z') *it3=*it3-'A'+'a';
                              pomocni.push_back(*it3);  //OVDJE IH PRETVORI U MALA HEHE
                              it3++;
                              i++;
                        }
                        indexi[pomocni].insert(std::make_tuple(it1->first, j, zapamceno_i-1));
                  }
            }
      } }

      return indexi; 
} 

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string trazeni, Tip indexpojmova) {
      auto moj(indexpojmova.find(trazeni)); 
      if(moj==indexpojmova.end()) throw std::logic_error("Pojam nije nadjen"); 
      else return indexpojmova[trazeni]; 
}

void IspisiIndeksPojmova(Tip indexpojmova) {
      for(auto it1=indexpojmova.begin(); it1!=indexpojmova.end(); it1++) {
            std::cout << it1->first << ": ";
            auto predzadni(--(it1->second.end()));
            for(auto it2=it1->second.begin(); it2!=it1->second.end(); it2++) {
            std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2); 
                  if(it2!=predzadni) std::cout << ", "; 
            }
            std::cout << std::endl;
            
      }
}

void IspisiIndexPojma(std::set<std::tuple<std::string, int, int>> skup_pripadni) {
      auto predzadni(--skup_pripadni.end());
      for(auto it1=skup_pripadni.begin(); it1!=skup_pripadni.end(); it1++) {
            std::cout << std::get<0>(*it1) << "/" << std::get<1>(*it1) << "/" << std::get<2>(*it1);
            if(predzadni!=it1) std::cout << " "; 
      }
}


int main() {
      Knjiga avkg;
      while(1) {
            std::cout << "Unesite naziv poglavlja: "; 
            std::string poglavlje; 
            std::getline(std::cin, poglavlje); 
            if(poglavlje==".") break; 
            int i=0;
            while(1) {
                  
                  std::cout << "Unesite sadrzaj stranice " << i+1 << ": "; 
                  std::string stranica_i; 
                  std::getline(std::cin, stranica_i);
                  if(stranica_i==".") break;
                  avkg[poglavlje].push_back(stranica_i);
                  i++;
            }
      }
      
      auto glossary(KreirajIndeksPojmova(avkg));
      std::cout << std::endl << "Kreirani indeks pojmova: " << std::endl;
      IspisiIndeksPojmova(glossary);
      
      while(1) {
            std::cout << "Unesite rijec: ";
            std::string rijec; 
            std::cin >> rijec; 
            if(rijec==".") break;
            try {
            auto nesto(PretraziIndeksPojmova(rijec, glossary)); 
                  IspisiIndexPojma(nesto); 
            }
            catch(std::logic_error l) { std::cout << "Unesena rijec nije nadjena!"; }
            std::cout << std::endl;
      }
      return 0; }