#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <list>
#include <set>
enum class Boje {Herc, Karo, Pik, Tref};
std::list<std::set<Boje> > KreirajSpil(){
    std::set< Boje> boje {Boje::Herc, Boje:: Karo, Boje:: Pik, Boje::Tref};
    std::list<std::set<Boje> >Spil(13) ;
    auto it (Spil.begin());
    for(int i=0; i<13; i++){
        *it++=boje;
    }
    return Spil;
}
int main() {
    std::list<std::set<Boje> >Spil ;
    Spil=KreirajSpil();
    return 0;
}

