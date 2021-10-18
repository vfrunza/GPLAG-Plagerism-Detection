/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>


enum class Boje
{
    Pik,Herc,Tref,Karo
};
typedef std::list<std::pair<Boje,std::string>> Spil;
std::string ImenaKarata[13]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
Spil KreirajSpil()
{
    Spil spil(52);
    auto NekiIt(spil.begin());
    
    for(int i=0; i<4; i++) {
        if(i==0) {
            int brojac(0);
            for(; brojac!=13; NekiIt++) {
                NekiIt->first=Boje::Pik;
                NekiIt->second=ImenaKarata[brojac];
            }
            brojac=0;
        }
        if(i==1) {
            int brojac(0);
            for(; brojac!=13; NekiIt++) {
                NekiIt->first=Boje::Tref;
                NekiIt->second=ImenaKarata[brojac];
            }
            brojac=0;
        }
        if(i==2) {
            int brojac(0);
            for(; brojac!=13; NekiIt++) {
                NekiIt->first=Boje::Herc;
                NekiIt->second=ImenaKarata[brojac];
            }
            brojac=0;
        }
        if(i==0) {
            int brojac(0);
            for(; brojac!=13; NekiIt++) {
                NekiIt->first=Boje::Karo;
                NekiIt->second=ImenaKarata[brojac];
            }
            brojac=0;
        }
    }
    return spil;
}
int main ()
{
    return 0;
}
