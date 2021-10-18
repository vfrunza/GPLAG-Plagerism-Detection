/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
typedef std::map<std::string,std::vector<std::string>>Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> Mapa;
typedef std::tuple<std::string,int,int>Trojka;
typedef std::set<std::tuple<std::string,int,int>>Skup;
Mapa KreirajIndeksPojmova(Knjiga k)
{
    Mapa m;
    //Krecemo se kroz Knjigu k i preko svakog kljucnog polja pristupam vektoru stirngova
    for(auto it=k.begin(); it!=k.end(); it++) {
        auto poglavlje(it->first);
        auto vstringova(it->second);//vstringova je vektor pridruzenih vrijednosti
        for(int i=0; i<vstringova.size(); i++) {
            //broj stranice je i
            int strana(i+1);//u mapi mapa u odg elementu skupa indeksacija stranica ide od 1 a ne od nula
            auto stranica(vstringova.at(i));//element vstringova je string
            //idemo kroz string stranica,trazimo rijec i pretvaramo je u mala slova

            for(int j=0; j<stranica.size(); j++) {
                std::string pom,rijec;
                auto znak(stranica.at(j));//to ce biti jedan char
                if(j<stranica.size() &&((znak>='A' && znak<='z') || (znak>='0' && znak<='9'))) {
                    int pozicija(j);//pamtimo pocetak rijeci
                    while(j<stranica.size() &&((znak>='A' && znak<='z') || (znak>='0' && znak<='9'))) {
                        pom+=znak;
                        j++;
                        if(j<stranica.size())znak=stranica.at(j);
                    }
                    //nasli smo rijec,pretvaramo je u mala slova
                    for(auto &x:pom) x=tolower(x);
                    rijec=pom;

                    Trojka trojka=std::make_tuple(poglavlje,strana,pozicija);

                    if(m.begin()==m.end()) m[rijec]=Skup {trojka}; //mapa m je prazna pa odmah ubacujemo elemente u nju
                    else {
                        for(auto itm=m.begin(); itm!=m.end(); itm++) {
                            //prvo provjeravamo da li se rijec nalazi u mapi m
                            auto itnarijec(m.find(rijec));
                            if(itnarijec==m.end()) m[rijec]=Skup {trojka}; //Ako se rijec ne nalazi u mapi ubaci je zajedno sa pratecim skupom uredjene trojke
                            else {
                                //znaci da se rijec vec nalazi u kljucnom polju mape m pa samo trebamo u skup ubacit tu novu uredjenu trojku
                                Skup & skup(itnarijec->second);//dat ce nam bas taj skup koji ima kljucno polje rijec
                                skup.insert(trojka);//ubacujemo u skup novu uredjenu trojku

                            }
                        }
                    }

                }
            }
        }
    }

    return m;
}
Skup PretraziIndeksPojmova(std::string rijec,Mapa m)
{
   //pretvaramo rijec u mala slova
   for(auto &x:rijec) x=tolower(x);
    auto it(m.find(rijec));
    if(it==m.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;

}
void IspisiPozicije(Skup skup)
{
    auto kraj=skup.end();
    for(auto its=skup.begin(); its!=skup.end(); its++) {
        Trojka trojka=*its;
        std::string poglavlje;
        int brojstr,pozicija;
        std::tie(poglavlje,brojstr,pozicija)=trojka;
        std::cout<<poglavlje<<"/"<<brojstr<<"/"<<pozicija;
        //iterator za skupove ne podrzavava operaciju -
        if(std::distance(its,kraj)>1) std::cout<<" ";
    }

}
void IspisiIndeksPojmova( Mapa m)
{

    for(auto it=m.begin(); it!=m.end(); it++) {
        Skup skup(it->second);
        auto kraj(skup.end());
        std::cout<<it->first<<": ";
        for(auto its=skup.begin(); its!=skup.end(); its++) {
            Trojka trojka=*its;
            std::string poglavlje;
            int brojstr,pozicija;
            std::tie(poglavlje,brojstr,pozicija)=trojka;
            std::cout<<poglavlje<<"/"<<brojstr<<"/"<<pozicija;
            //iterator za skupove ne podrzavava operaciju -
            if(std::distance(its,kraj)>1) std::cout<<", ";
        }
        std::cout<<"\n";
    }

}


int main ()
{

    Knjiga knjiga;
    for(;;) {
        std::string poglavlje;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,poglavlje);
        if(poglavlje==".") break;
        int br(1);
        std::vector<std::string>v;//svaki element vektora v predstavlja sadrzaj stranice
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<br<<": ";
            std::string stranica;
            std::getline(std::cin,stranica);
            if(stranica==".") break;
            v.push_back(stranica);
            br++;
        }
        //ubacujemo poglavlje i v u mapu Knjiga
        knjiga[poglavlje]=v;
    }
    std::cout<<std::endl;
    auto m(KreirajIndeksPojmova(knjiga));
    std::cout<<"Kreirani indeks pojmova:\n";
    IspisiIndeksPojmova(m);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        for(auto &x:rijec) x=tolower(x);
        try {
            auto skup( PretraziIndeksPojmova(rijec,m));
            IspisiPozicije(skup);
            std::cout<<std::endl;

        } catch(std::logic_error poruka) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
    return 0;
}
