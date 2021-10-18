/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <stdexcept>

std :: vector<int> BrojClanova(int a,int timovi){
    int prvi = a % timovi;
    std :: vector<int> vrati;
    if (prvi == 0) {
        vrati.resize(timovi,(a/timovi));
    }
    
    
    for(int i = 0; i < timovi; i++){
        if(i < prvi){
            
            vrati.push_back((a / timovi) + 1);
        }
        else vrati.push_back( a / timovi);
    }
    return vrati;
}

int KolikoZnakova(std::string prebroj){
    int brojac = 0;
    for(int i = 0; i < prebroj.size(); i++){
        if ((prebroj[i] <= 'Z' && prebroj[i] >= 'A') || (prebroj[i] <= 'z' && prebroj[i] >= 'a') || (prebroj[i] >= '0' && prebroj[i] <= '9' )) {brojac++;  }
    }
    return brojac;
}
void KreirajListu(std :: vector<std :: string> prebaci, std::list<std :: string> &ulista){
    for(int i = 0; i < prebaci.size(); i++){
        ulista.push_back(prebaci[i]);
    }
}
//RAZVRSTAVANJE
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> spisak, int timovi){
    if (timovi < 1 ||timovi > spisak.size()) throw std :: logic_error ("Razvrstavanje nemoguce");
    
    std::vector<int> brojclanova;
    brojclanova = BrojClanova(spisak.size(),timovi);
    std::list<std::string> lista;
    KreirajListu(spisak,lista);
      std::vector<std::set<std::string>> rezultat(timovi);
      auto it = lista.begin();
      auto iti = it;
      int pocetni = 0;
      for(int i = 0; i<timovi; i++){
          for(int j = 0; j<brojclanova[i]; j++){
              int brojac = 0;
                  while(brojac != pocetni){
                     if(lista.size() == 0) return rezultat;
                        iti++;
                      if (iti == lista.end()) {
                          iti = lista.begin();
                      }
                      
                     brojac++;
                  }
                if (iti == lista.end()) {
                    iti = lista.begin();
                }
                  rezultat[i].insert(*iti);
                  pocetni = KolikoZnakova(*iti);
                  iti = lista.erase(iti);
                  if (iti == lista.end()) {
                      iti = lista.begin();
                  }
                  pocetni--;
              }
        }
        return rezultat;  
}
int main ()
{ 
    std::cout << "Unesite broj djece: ";
    int brojdjece;
    std::cin >> brojdjece;
     std::vector<std :: string > djeca ;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: \n";
    for(int i = 0; i < brojdjece; i++){
        std :: string pomocni;
        std :: getline(std :: cin,pomocni);
        djeca.push_back(pomocni);
        
    }
    std::cout << "Unesite broj timova: ";
    int brojtimova;
    std::cin >> brojtimova;
    try{
    std::vector<std::set<std::string>> rezultat = Razvrstavanje(djeca,brojtimova);
    std::vector<int> brojclanova = BrojClanova(brojdjece,brojtimova);
    //ISPIS TIMOVA
    for(int i = 0; i<rezultat.size(); i++){
        std::cout << "Tim " <<i + 1<<": ";
        for(auto it = rezultat[i].begin(); it != rezultat[i].end(); it++) {
                if (it != (--(rezultat[i].end()))) {
                    std::cout << *it <<", ";
                }
                else std::cout << *it;
            }
            std::cout<< std::endl;
        }
    }
    catch(std::logic_error greska){
        std::cout <<"Izuzetak: "<< greska.what() << std::endl;
        return 0;
    }
    return 0;
}