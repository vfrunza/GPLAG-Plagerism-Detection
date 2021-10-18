#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <algorithm>
// Samo da napomenem da su skoro svi prgrami radeni u CLion-u
// zbog predivnog debugera (o_o)  i zbog toga sto
//  se u CLion-u tokom pisanja koda odmah prijavi greska ako
// fulim neko slovo........itd itd... pozdrav (*__*)
// Ne brinite ne prijavljuju se greske oko formiranja
// funkcija template i tako toga to se skonta tokom kompajliranja

int SumaDjelilaca(long long int broj){
    int suma(0), djelilac(1);
    while(djelilac <= abs(broj/2)){
        if(!abs(broj%djelilac))
            suma+= djelilac;
        djelilac++;
    }
    return suma+broj;
}

int BrojProstihFaktora(long long int broj){
    int djeljitelj(2), brojac(0);
    while(djeljitelj <= abs(broj/2)){
        if(!abs(broj%djeljitelj)){
            int prost(0), i(2);
            while(i <= djeljitelj/2){
                if(!abs(djeljitelj%i)){
                    prost = 1; break;
                }
                i++;
            }
            if(!prost) {
                while(!abs(broj%djeljitelj)){
                    brojac++; broj/= djeljitelj;
                }
            }
        }
        djeljitelj++;
    }
    int i(2);
    while(i <= abs(broj/2)){
        if(!abs(broj%i)) {
            i = broj; break;
        }
        i++;
    }
    if(i != broj) brojac++;
    return brojac;
}

int BrojSavrsenihDjelilaca(long long int broj){
    if(broj == 1) return 0;
    int djeljitelj(2), broj_savrsenih(0), zbir_trenutnog_broja(1);
    while(djeljitelj <= abs(broj/2)){
        if(!(broj%djeljitelj)){   //Ako je djeljiv provjerava se da li je savrsen
            zbir_trenutnog_broja += djeljitelj;
            int i(1), zbir_djelioca(0);
            while(i <= djeljitelj/2){
                if(!(djeljitelj%i)){
                    zbir_djelioca += i;
                }
                i++;
            }
            if(zbir_djelioca == djeljitelj) broj_savrsenih++;  // Tek ako je savrsen dodaje se na broj njegovih faktora
        }
        djeljitelj++;
    }
    if(zbir_trenutnog_broja == broj) return broj_savrsenih+1;
    return broj_savrsenih;
}

template <typename TipJedan, typename TipDva>
auto UvrnutiPresjek(TipJedan poc1, TipJedan kraj1, TipDva poc2,TipDva kraj2, int f(long long int) = nullptr) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
    typedef typename std::remove_reference<decltype(*poc1)>::type TipVrijednosti;
    typedef typename std::vector<std::vector<TipVrijednosti>> MatTip;
    MatTip povratna;
    TipJedan novi1(poc1);   TipDva novi2(poc2);
    int duzina_prvog(0), duzina_drugog(0);
    while(novi1 != kraj1){
        novi1++; duzina_prvog++;
    }
    while(novi2 != kraj2){
        novi2++; duzina_drugog++;
    }
    novi1 = poc1; novi2 = poc2;
    if(!(*f)){
        int k(0);
        for(int i(0); i < duzina_prvog; i++){
            for(int j(0); j < duzina_drugog; j++){
                if(novi1[i] == novi2[j]) {
                    povratna.resize(k+1);
                    povratna.at(k).push_back(novi1[i]);
                    povratna.at(k).push_back(0);
                    povratna.at(k).push_back(0);
                    k++;
                }
            }
        }
    }
    else{
        int k(0);
        for(int i(0); i < duzina_prvog; i++){
            int prvi_element(f(novi1[i]));
            for(int j(0); j < duzina_drugog; j++){
                if(prvi_element == f(novi2[j])) {
                    povratna.resize(k+1);
                    povratna.at(k).push_back(novi1[i]);
                    povratna.at(k).push_back(novi2[j]);
                    povratna.at(k).push_back(prvi_element);
                    k++;
                }
            }
        }
    }
    std::sort(povratna.begin(), povratna.end(), [](std::vector<TipVrijednosti> vektor1, std::vector<TipVrijednosti> vektor2){