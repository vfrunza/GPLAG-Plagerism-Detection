/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <type_traits>

enum class Boje{Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, std::string>> spil;
typedef std::multimap<Boje, std::string> multimapa;
std::vector<std::string> karte{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

spil KreirajSpil(void) {
    spil moj;
    Boje boja(Boje::Pik);
    int br(0);
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            moj.push_back({boja, karte.at(j)});
        }
        br++;
        boja=Boje(br);
    }
    return moj;
}

/*void IzbaciKarte(spil &s, multimapa &m) {
    // provjera validnosti spila -> MORA SE DOPISATI FUNKCIJA ZA BACANJE IZUZETKA
    if(s.size()>52) throw std::logic_error("Neispravna lista!");
    // glavni dio funkcije
    for(auto mit=m.begin(); mit!=m.end(); mit++) {
        for(auto sit=s.begin(); sit!=s.end(); sit++) {
            std::pair<Boje, std::string> par(*mit);
            if(par==*sit) { 
                std::remove(s.begin(), s.end(), *sit);
                std::remove(m.begin(), m.end(), *mit);
            }
        }
    }
} */

int main ()
{
    spil pov(KreirajSpil());
    multimapa m{{Boje::Tref, "2"}, {Boje::Pik, "A"}, {Boje::Pik, "1"}};
    /*IzbaciKarte(pov, m);*/
    for(spil::iterator it=pov.begin(); it!=pov.end(); it++) {
        std::cout<<static_cast<std::underlying_type<Boje>::type>(it->first)<<", "<<it->second<<" | ";
    }
	return 0;
}
