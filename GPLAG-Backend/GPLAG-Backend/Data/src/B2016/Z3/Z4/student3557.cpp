#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

int BrojSlova(std::string s) {
    int br(0);
    for(int i=0; i<s.length(); i++) 
        if ((s[i] >='A' && s[i] <='Z') || (s[i] >='0' && s[i] <='9') || (s[i] >='a' && s[i] <='z')) br++;
        
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova) {
    
    if(br_timova<1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<int> v1;
    std::vector<std::set<std::string>> v;
   
    std::list<std::string> lista(imena.begin(), imena.end());
    
    int br_prvi (imena.size() % br_timova);  
    int br_clan1 (imena.size()/br_timova + 1); 
    int br_drugi (br_timova - imena.size() % br_timova);  
    int br_clan2 (imena.size()/br_timova);
    auto it1 = lista.begin();
    
    for(int i=0; i<br_prvi; i++) v1.push_back(br_clan1);
    for(int i=0; i<br_drugi; i++) v1.push_back(br_clan2);
    int br_slova(0);
    for (int i=0; i<br_timova; i++) {
        auto   it = it1;
         std::set<std::string> skup;
         int vel = v1[i];
       for (int j=0; j<v1[i]; j++) {
        
            skup.insert(*it);
   //          std::cout << "\nDijete: " << *it << " BrojSlova: " <<BrojSlova(*it)  ;
             br_slova = (BrojSlova(*it));
            it = lista.erase(it); 
            
      for(int k =0; k < br_slova-1; k++) {              // POMJERANJE ITERATORA ZA BROJ SLOVA
                if(it == lista.end()) 
                    it = lista.begin();
                it++;
      }    
      if(it == lista.end()) 
            it = lista.begin();
       }    
    v.push_back(skup);
    it1=it;
   }
    return v;
}


int main() {
    
    try {
    int br_djece;
    std::cout <<"Unesite broj djece: ";
    std::cin >> br_djece;
    std::cin.ignore(100, '\n');
    
    std::vector<std::string> imena;
    std::cout << "Unesite imena djece: ";
    
    for(int i=0; i<br_djece; i++) {
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    
    int br_timova;
    std::cout << "\nUnesite broj timova: ";
    std::cin >> br_timova;
    
    auto v = Razvrstavanje(imena, br_timova);
    
    for(int i=0; i<v.size(); i++) {
        std::cout << "Tim " << i+1 <<": ";
         auto pomocni = (v[i].end());
            pomocni--;
        for(auto it = v[i].begin(); it != v[i].end(); it++) {
            std::cout << *it ;
            if(it != pomocni) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    } catch(std::logic_error izuzetak) {
        std::cout <<"Izuzetak: " << izuzetak.what();
    }
    
	return 0;
}


/*

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova) {
    
    if(br_timova<1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> v;
    std::set<std::string> skup;
    std::list<std::string> lista(imena.begin(), imena.end());
    
    int br_prvi (imena.size()%br_timova);  std::cout<< "br_prvi: " << br_prvi << " !\n";
    int br_clan1 (imena.size()/br_timova + 1);  std::cout<< "br_clan1 : " <<br_clan1  << " !\n";
    int br_drugi (br_timova - br_prvi);     std::cout<< "br_drugi: " << br_drugi  << " !\n";
    int br_clan2 (imena.size()/br_timova);
    
    std::cout<< "VELICINA VEKTORA u fji 1: " << v.size() << " !\n";

    for(int i=0; i<br_prvi; i++) {
        int br=0;
        for(auto it = lista.begin(); it != lista.end(); it++) {
            skup.insert(*it); br++;
            if(br == br_clan1) break;
            for(int j =0; j<(BrojSlova(*it)); j++) {              // POMJERANJE ITERATORA ZA BROJ SLOVA
                if(it == lista.end()) {
                    it = lista.begin();
                    continue;
                }
                j++;
            } 
            
            it = lista.erase(it);
        }
        v.push_back(skup);
    }
    
    for(int i=0; i<br_drugi; i++) {
        int br=0;
        for(auto it = lista.begin(); it != lista.end(); it++) {
            skup.insert(*it); br++;
            if(br == br_clan2) break;
            for(int j =0; j<(BrojSlova(*it)); j++) {              // POMJERANJE ITERATORA ZA BROJ SLOVA
                if(it == lista.end()) {
                    it = lista.begin();
                    continue;
                }
                j++;
            } 
            it = lista.erase(it);
        }
        v.push_back(skup);
    }
    return v;
}
} */
/* BOLJA
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova) {
    
    if(br_timova<1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> v;
    std::set<std::string> skup;
    std::list<std::string> lista(imena.begin(), imena.end());
    
    int br_prvi (imena.size()%br_timova);  std::cout<< "br_prvi: " << br_prvi << " !\n";
    int br_clan1 (imena.size()/br_timova + 1);  std::cout<< "br_clan1 : " <<br_clan1  << " !\n";
    int br_drugi (br_timova - imena.size()%br_timova);     std::cout<< "br_drugi: " << br_drugi  << " !\n";
    int br_clan2 (imena.size()/br_timova);
    
    std::cout<< "VELICINA VEKTORA u fji 1: " << v.size() << " !\n";
    auto it1 = lista.begin();
  int br(0), brc(0);
  br=0;
    for(int i=0; i<br_prvi; i++) {
       for(auto it = it1; it != lista.end(); ) {
         //   for (;;) {
            skup.insert(*it); br++;
              int br_slova = (BrojSlova(*it)); std::cout<< "Broj slova: " << br_slova << " !\n";
              std::cout<< "ime: " << *it << " !\n";
              it = lista.erase(it);
            if(br == br_clan1) {
                 v.push_back(skup);
                 brc++;
                 br = 0;
            }
            if(brc == br_prvi) {
                brc=0; break;
            }
            for(int j =0; j<br_slova; j++) {              // POMJERANJE ITERATORA ZA BROJ SLOVA
                if(it == lista.end()) 
                    it = lista.begin();
    
                it++;
            } 
            it1 = it;
        }
    }

    return v;
}*/

     /*       while(1) {
                
                 if(it == lista.end()) {
                    it = lista.begin(); }
                  else {
                    it++;
                    br++;
                    }
                    if(br == br_slova) break;
            }*/
            
            /*    std::cout << "\nDijete: " << *it << " BrojSlova: " <<BrojSlova(*it)  ;
             br_slova = (BrojSlova(*it));*/
             
             /*
             std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova) {
    
    if(br_timova<1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<int> v1;
    std::vector<std::set<std::string>> v;
   
    std::list<std::string> lista(imena.begin(), imena.end());
    
    int br_prvi (imena.size() % br_timova);  std::cout<< "br_prvi: " << br_prvi << " !\n";
    int br_clan1 (imena.size()/br_timova + 1);  std::cout<< "br_clan1 : " <<br_clan1  << " !\n";
    int br_drugi (br_timova - imena.size() % br_timova);     std::cout<< "br_drugi: " << br_drugi  << " !\n";
    int br_clan2 (imena.size()/br_timova);
    auto it1 = lista.begin();
    
    for(int i=0; i<br_prvi; i++) v1.push_back(br_clan1);
    for(int i=0; i<br_drugi; i++) v1.push_back(br_clan2);
    int br_slova(0);
    for (int i=0; i<br_timova; i++) {
        auto   it = it1;
         std::set<std::string> skup;
         
       for (int j=0; j<v1[i]; j++) {
        if(it != lista.end()) 
            skup.insert(*it);
            br_slova = (BrojSlova(*it));
            it = lista.erase(it); 

      for(int k =0; k < br_slova; k++) {              // POMJERANJE ITERATORA ZA BROJ SLOVA
                if(it == lista.end()) 
                    it = lista.begin();
                it++;
      }    
      if(it == lista.end()) 
            it = lista.begin();
       }    
    v.push_back(skup);
   }
    return v;
} */