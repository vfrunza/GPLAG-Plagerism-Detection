/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <list>
#include <type_traits>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <queue>

enum class Boje
{
      Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> Multimapa; 
std::vector<std::string> Nazivi {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::vector<std::string> NaziviBoja {"Pik", "Tref", "Herc", "Karo"};
Spil KreirajSpil()
{
      Spil rezultat(52);
      auto iter(rezultat.begin());
      for(int j=0; j<4; j++) {
            for(int i=0; i<13; i++) {
                  (*iter).first=static_cast<Boje>(j);
                  (*iter).second=Nazivi[i];
                  iter++;
            }
      }
      return rezultat;
}

bool ProvjeraValidnostiSpila(Spil &spil) {
      if(spil.size()>52) return false;
      if(spil.size()==0) return true; 
      auto iter(spil.begin()); 
      short int brojac(0); 
      short int brojac_unutrasnji(0);
      short int suma_Svih(0); 
      bool nasao_boju_a_nisam_kartu(true); 
      for(int i=0; i<4; i++) {
            if((*iter).first!=static_cast<Boje>(i) && static_cast<int>((*iter).first)>i) { brojac++; continue; }
            if(static_cast<int>((*iter).first)<i) return false;
            brojac_unutrasnji=0; 
            nasao_boju_a_nisam_kartu=true; 
            for(int j=0; j<13; j++) {
                 if((*iter).second!=Nazivi[j]) { if(j==12 && brojac_unutrasnji==0) {std::cout << "tu sam "; return false;}  continue; }
              //ili ako je preskocio neke koje nije trebao 
                  iter++; brojac_unutrasnji++; 
                  suma_Svih++;
                  nasao_boju_a_nisam_kartu=false; 
            }
            if(nasao_boju_a_nisam_kartu) return false;
      }
      if(brojac==4 || suma_Svih!=spil.size()) return false;
      return true; 
}
bool JelValidanStringZaBoju(std::string rijec) {
      for(int i=0; i<4; i++) 
      if(rijec==NaziviBoja[i]) return true; 
      return false; 
}

bool JelValidanStringZaBroj(std::string rijec) {
      for(int i=0; i<13; i++)
      if(rijec==Nazivi[i]) return true; 
      return false; 
}

bool ProvjeraValidnostiReda(std::queue<std::pair<std::string, std::string>> red) {
            for(int i=0; i<red.size(); i++) {
                 if(!JelValidanStringZaBoju(red.front().first) || JelValidanStringZaBroj(red.front().second)) return false; 
                 red.pop(); 
            }
            
            return true; 
}

void IterirajIliNe(Multimapa::iterator &it, bool da_li_da_uvecam) {
      if(da_li_da_uvecam) it++; 
      
}

void IzbaciKarte(Spil &spil, Multimapa &multimapa) {
      if(!ProvjeraValidnostiSpila(spil)) throw std::logic_error("Neispravna lista!"); 
      if(multimapa.size())
      {
      bool obrisao, da_li_da_uvecam(true); 
      for(auto it=multimapa.begin(); it!=multimapa.end(); IterirajIliNe(it, da_li_da_uvecam)) {
            obrisao=false; 
            for(auto it2=spil.begin(); it2!=spil.end(); it2++) {
                  if((it->first)==(it2->first) && (it->second)==(it2->second))  { 
                 // std::cout << "obrisao sam"; 
                  it2=spil.erase(it2);
                  obrisao=true;
                  break;}
            }
           if(obrisao){ it=multimapa.erase(it); da_li_da_uvecam=false; }
           else da_li_da_uvecam=true;
      } }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &radijus,const int &broj_karata) {
      if(radijus<1 || radijus>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
      if(!ProvjeraValidnostiSpila(spil)) throw std::logic_error("Neispravna lista!"); 
      int broj_izbacenih(0), kopijar(radijus); 
      std::queue<std::pair<std::string, std::string>> rezultat;
  //    bool problematicno(false), nasao_problem(false); 
      while (true) {
            for(auto it=spil.begin(); it!=spil.end(); ) {
                  while(kopijar && it!=spil.end()) {
                        kopijar--;
                        if(kopijar==0) break; 
                        it++;
                                     }
                  if(it==spil.end()) { 
                        kopijar=kopijar;
                         break; }
                                           if(broj_izbacenih==broj_karata) break;

                  rezultat.push(std::make_pair(NaziviBoja[static_cast<int>(it->first)], it->second)); 
                  it=spil.erase(it);  //ovdje u zaglavlju for petlje iskoristi onu mogucnost da ti ga ne uveca
                  broj_izbacenih++;
                  kopijar=radijus-kopijar;
            }
            
            if(broj_izbacenih==broj_karata || spil.size()==0) break; 
            if(radijus>spil.size() && broj_izbacenih!=broj_karata) {
                  auto it=spil.begin();
                  while(it!=spil.end()) {
            rezultat.push(std::make_pair(NaziviBoja[static_cast<int>(it->first)], it->second)); 
            it=spil.erase(it);  //ovdje u zaglavlju for petlje iskoristi onu mogucnost da ti ga ne uveca

                  }
                  break; 
            }
      }
      return rezultat; 
} 

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> &red, int n) {
      if(n>spil.size()) throw std::range_error("Nedovoljno karata u redu!");
      if(n<1) throw std::domain_error("Broj n je besmislen!"); //ili od 0 manje
      if(!ProvjeraValidnostiReda(red)) throw std::logic_error("Neispravne karte!"); 
      if(!ProvjeraValidnostiSpila(spil)) throw std::logic_error("Neispravna lista!");
      for(int i=0; i<red.size(); i++) {
            
      }
}

int main ()
{
          return 0;
}
