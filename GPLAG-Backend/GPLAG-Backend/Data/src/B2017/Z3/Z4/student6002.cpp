qq#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje {
    Pik, Tref, Herc, Karo
};

typedef std::list< std::pair < Boje, std::string > > Lista;
typedef std::pair < Boje, std::string > Par;
typedef std::multimap< Boje,std::string > Multi;

Lista KreirajSpil()
{
    Lista Spil;
    std::vector< std::string > VrijednostKarte = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Boje z[] = {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};  // ask someone if it is OK to do this
    for(int i = 0; i < 4; i ++) {
        for (int j = 0; j < VrijednostKarte.size(); j++) {
            Spil.push_back ( std::make_pair(z[i], VrijednostKarte.at(j) ) );
        }
    }
    return Spil;
}
/*
IzbaciKarte(Lista &Kards, Multi &m){

}
*/

Par IzbaciKarteRazbrajanjem( Lista &Spil, short int &r, const int &b )
{

    Par parovi;
    if ( r > 52 || r < 1 || b < 1 ) throw std::logic_error("Neispravni elementi za izbacivanje!");
    for ( int j = 1; j <= b; j++ ) {
        for ( Lista::iterator i = Spil.begin(); i != Spil.end(); i++ ) {
            if (i = r*j) {
                parovi.push_back()
            }
        }
    }
    return parovi;
}




int main ()
{
    short int r = 3;
    const int b = 6;
    Lista K =  KreirajSpil();

    for (Lista::iterator list_iter = K.begin(); list_iter != K.end(); list_iter++) {
        if (list_iter -> first == Boje::Pik)
            std::cout << list_iter -> second << " ";
    }
    IzbaciKarteRazbrajanjem(K, r, b);
    return 0;
}
