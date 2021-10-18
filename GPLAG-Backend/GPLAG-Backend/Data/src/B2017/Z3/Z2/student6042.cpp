/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <set>
#include <vector>
#include <memory>


typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Tip;

Tip KreirajIndeksPojmova(Knjiga tekst)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa_koju_vraca;
    for(auto it=tekst.begin(); it!=tekst.end(); it++) {                                 //krece se kroz mapu
        std::string s (it->first);                                                         //s je poglavlje
        int i, j;                                                                        //uzima iz mape ime poglavlja i smjesti ga u string s
        for(i=1; i<((it->second).size()); i++) {                                           //prolazi kroz vektor
            std::string pomocni((it->second)[i]);                                              //u pomocni smjesti jednu stranicu
    
            for(j=0; j<pomocni.length(); ) {                                                  //ide do kraja stranice
                std::string rijec(" ");
                while(pomocni[j]==' ' && j!=pomocni.length()) j++;
                while(pomocni[j]!=' ' && ((pomocni[j]>='A' && pomocni[j]<='Z') || (pomocni[j]>='a' && pomocni[j]<='z') || (pomocni[j]>='0' && pomocni[j]<='9')) && j!=s.length()) {                             //while petlja trazi rijeci
                    rijec.push_back(pomocni[j]);
                    j++;                                                                          //trazi rijec
                }
                while(pomocni.find(rijec, 0)) {                                                   //dok ima te rijeci na toj stranici
                    std::set<std::tuple<std::string, int, int>> skup;
                    std::tuple<std::string, int, int> ntorka;
                    std::get<0>(ntorka)=s;
                    std::get<1>(ntorka)=i;
                    std::get<2>(ntorka)=pomocni.find(rijec, 0);
                    skup.insert(ntorka);                                                        //umestni u ntorku poziciju rijeci
                    mapa_koju_vraca.insert({rijec, skup});              //umetni tu rijec u mapu
                }
            }

        }

    }
    return mapa_koju_vraca;
}

typedef std::set<std::tuple<std::string, int, int>> TipSkupa;

TipSkupa PretraziIndeksPojmova(std::string rijec, Tip m)
{
    TipSkupa skup;
    auto it(m.begin());
    for(it=m.begin(); it!=m.end(); it++) {
        if(rijec==(it->first)) {
            std::set<std::tuple<std::string, int, int>> element;
            element=(it->second);
            std::tuple<std::string, int,int> pomocni;
            for(std::tuple<std::string, int, int> x: element) {
                std::get<0>(pomocni)=std::get<0>(x);
                std::get<1>(pomocni)=std::get<1>(x);
                std::get<2>(pomocni)=std::get<2>(x);
            }
            skup.insert(pomocni);
        }
        if(it==m.end() && !m.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    }

    return skup;
}

void IspisiIndeksPojmova(Tip mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        for(std::tuple<std::string, int, int> x: it->second) {
            std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<", ";
        }
        std::cout<<std::endl;
    }
}


int main ()
{

    std::map<std::string, std::vector<std::string>> tekst;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string naziv_poglavlja("");
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        std::string sadrzaj_stranice;
        int br(1);
        std::vector<std::string> v;
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<br<<": ";
            std::getline(std::cin, sadrzaj_stranice);
            if(sadrzaj_stranice==".") break;
            v.push_back(sadrzaj_stranice);
            br++;
        }
        tekst.insert({naziv_poglavlja, v});
    }
    std::cout<<"Kreirani indeks pojmova: "<<std::endl;
    Tip vracena_mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(vracena_mapa);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        try {
            std::set<std::tuple<std::string, int, int>> skup=PretraziIndeksPojmova(rijec, vracena_mapa);
            for(std::tuple<std::string, int, int> x: skup) {
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
            }
        } catch(std::logic_error e) {
            std::cout<<e.what();
            break;
        }
    }
    return 0;
}
