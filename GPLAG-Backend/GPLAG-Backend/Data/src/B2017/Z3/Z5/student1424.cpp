#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <iterator>
#include <stack>
#include <stdexcept>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
std::string Nazivi[] {"2","3", "4", "5","6","7", "8", "9", "10", "J", "Q", "K", "A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};
struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};
bool kriterij(Karta prva, Karta druga)
{
    if(prva.boja!=druga.boja) return prva.boja<druga.boja;
    int poz1(0),poz2(0);
    for(int i=0; i<13; i++) {
        if(prva.vrijednost==Nazivi[i]) poz1=i;
        if(druga.vrijednost==Nazivi[i]) poz2=i;
    }
    return poz1<poz2;
}
void izuzetak(Karta prvi)
{
    bool nadjeno(false),nadjeno2(false);
    for(int i=0; i<4; i++) if(Boje(i)==prvi.boja) nadjeno=true;
    for(int i=0; i<13; i++) if(Nazivi[i]==prvi.vrijednost) nadjeno2=true;
    if(!(nadjeno &&nadjeno2)) throw std::logic_error("Neispravna lista");
}



Cvor* KreirajSpil()
{
    Cvor*pocetak(nullptr);
    Cvor*prethodni;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            Cvor *novi {new Cvor {{Boje(i), Nazivi[j]},nullptr}};
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            if((i+1)*(j+1)==52) {
                novi->sljedeci=pocetak;

            }
        }
    }
    return pocetak;
}
void Provjera(Cvor*pocetak)

{
    if(pocetak==nullptr) return;
    Cvor* klizeci(pocetak);
    Cvor*naredni;
    int brojac=0;
    for(;;) {
        izuzetak(klizeci->karta);
        naredni=klizeci->sljedeci;
        brojac++;
        if(klizeci->sljedeci==pocetak) break;
        if(!kriterij(klizeci->karta,naredni->karta)) throw std::logic_error("Neispravna lista");
        klizeci=naredni;
    }
    if(brojac>52) throw std::logic_error("Neispravna lista");
}

void IzbaciKarte(Cvor*&pocetak, std::multimap<Boje, std::string>& mapa)
{
    Provjera(pocetak);
    Cvor* klizeci(pocetak);
    Cvor* prethodni(pocetak);
    if(pocetak==nullptr) return;
    auto it=mapa.begin();
    bool poc(false);
    do {
        if(poc) it=mapa.begin();
        poc=false;
        klizeci=pocetak;
        prethodni=pocetak;
        if(mapa.empty()) return;
        while((klizeci->karta).boja!=it->first || (klizeci->karta).vrijednost!=it->second ) {
            prethodni=klizeci;
            klizeci=klizeci->sljedeci;
            if(klizeci==pocetak) break;
        }
        if((klizeci->karta).boja==it->first && (klizeci->karta).vrijednost==it->second) {
           
            if(pocetak==pocetak->sljedeci) {
                mapa.erase(it);
               delete pocetak;
                pocetak=nullptr;
                break;
            } else {


                auto pok(it);
                if(it!=mapa.begin()) pok--;
                else poc=true;
                mapa.erase(it);

                it=pok;

                
                if(klizeci==pocetak) {
                    pocetak=klizeci->sljedeci;
                    //prethodni->sljedeci=pocetak;
                }
 prethodni->sljedeci=klizeci->sljedeci;
                delete  klizeci;
                
            }
        } else it++;

        if(pocetak==nullptr) break;

    } while(it!=mapa.end());

}

std::stack<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(Cvor* &pocetak, const short int & r, const int & b)
{
    if(r<1 || r>52 || b<1) throw std:: logic_error("Neispravni elementi za izbacivanje!");
    std::stack<std::pair<Boje, std::string>> red ;
    Provjera(pocetak);

    int broj_izbacenih(0);
    Cvor* it(pocetak);
    Cvor*prethodni(pocetak);
    int predjeno(1);
    while(broj_izbacenih<b ) {

        while(predjeno<r) {
            prethodni=it;
            it=it->sljedeci;
            predjeno++;
        }
        predjeno=0;
        Cvor*tmp=it->sljedeci;
        red.push(std::make_pair((it->karta).boja, (it->karta).vrijednost));
        (prethodni->sljedeci)=tmp;
        if(it==pocetak && pocetak->sljedeci==pocetak) {
            delete it;
            pocetak=nullptr;
            break;
        }
        if(it==pocetak) pocetak=pocetak->sljedeci;
        delete it;
        it=prethodni;
        broj_izbacenih++;
    }
    return red;
}
void provjera(std::stack<std::pair<Boje, std::string>> red)
{
    int s(red.size());
    for(int i=0; i<s; i++) {
        bool nadjeno1(false),nadjeno2(false);
        std::pair<Boje, std::string> pomocni(red.top());
        for(int j=0; j<4; j++) if(pomocni.first==Boje(j)) nadjeno1=true;
        for(int k=0; k<13; k++)
            if(pomocni.second==Nazivi[k]) nadjeno2=true;
        if(!(nadjeno2 && nadjeno1)) throw std::logic_error("Neispravne karte");
        red.pop();
    }
}
void VratiPosljednjihNKarata(Cvor*&pocetak, std::stack<std::pair<Boje, std::string>>&red, int n)
{
    int s(red.size());
    if(n>s) throw std::range_error("Nedovoljno karata u steku!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    provjera(red);
    if(pocetak!=nullptr) Provjera(pocetak);
    int broj_ubacenih(0);
    Cvor*klizeci(pocetak);
    Cvor*prethodni(pocetak);
    while(broj_ubacenih<n) {
        prethodni=pocetak;
        klizeci=pocetak;
        auto pomocna(red.top());

        if(klizeci==nullptr ) {
            auto it =new Cvor {{pomocna.first, pomocna.second}, nullptr};
            pocetak=it;
            pocetak->sljedeci=pocetak;
            broj_ubacenih++;


        } else  {

            if(klizeci->sljedeci==klizeci) {

                auto it =new Cvor {{pomocna.first, pomocna.second}, nullptr};
                if(pomocna.first<(pocetak->karta).boja || (pomocna.first==(pocetak->karta).boja && kriterij({pomocna.first, pomocna.second}, pocetak->karta))) {
                    klizeci->sljedeci=it;
                    it->sljedeci=klizeci;
                    pocetak=it;

                }
                else if((klizeci->karta).boja!=pomocna.first || (klizeci->karta).vrijednost!= pomocna.second) {
                    pocetak->sljedeci=it;
                    it->sljedeci=pocetak;
                }
                broj_ubacenih++;


            } else {

                while((klizeci->karta).boja<pomocna.first) {
                    prethodni=klizeci;
                    klizeci=klizeci->sljedeci;
                    if(klizeci==pocetak) break;

                }
                if(pomocna.first<(pocetak->karta).boja || (pomocna.first==(pocetak->karta).boja && kriterij({pomocna.first, pomocna.second}, pocetak->karta))) {
                    do {
                        prethodni=klizeci;
                        klizeci=klizeci->sljedeci;
                    } while(klizeci!=pocetak);

                    auto it =new Cvor {{pomocna.first, pomocna.second}, nullptr};

                    it->sljedeci=prethodni->sljedeci;
                    prethodni->sljedeci=it;
                    pocetak=it;
                    broj_ubacenih++;

                }
                
               else if((klizeci->karta).boja>pomocna.first){
                    auto it =new Cvor {{pomocna.first, pomocna.second}, nullptr};

                    it->sljedeci=prethodni->sljedeci;
                    prethodni->sljedeci=it;
                    broj_ubacenih++;
                    
                }
                else if(klizeci==pocetak  && (prethodni->karta).boja<pomocna.first ) {
                    auto it =new Cvor {{pomocna.first, pomocna.second}, nullptr};


                    it->sljedeci=prethodni->sljedeci;
                    (prethodni->sljedeci)=it;

                    broj_ubacenih++;

                } else if((klizeci->karta).boja==pomocna.first) {
                    while( (klizeci->karta).boja==pomocna.first && kriterij(klizeci->karta,Karta {pomocna.first,pomocna.second})) {
                        prethodni=klizeci;
                        klizeci=klizeci->sljedeci;
                        if(klizeci==pocetak) break;

                    }
 if((klizeci->karta).boja!=pomocna.first || (klizeci->karta).vrijednost!= pomocna.second){

                    auto it= new Cvor {{pomocna.first, pomocna.second}, nullptr};

                    it->sljedeci=prethodni->sljedeci;
                    (prethodni->sljedeci)=it;

                    broj_ubacenih++;}

                }
            }
        }
       
        red.pop();
        if(red.empty()) break;
        
    }
    
}

void Ispisi(Cvor*pocetak)
{
    const char* imena[4]= {"Pik","Tref","Herc","Karo"};
    Cvor*prethodni(pocetak);
    Cvor*klizeci=pocetak;
    if(pocetak==nullptr) return;
    for(;;) {

        for(int i=0; i<4; i++) {
            if((klizeci->karta).boja==Boje(i)) {
                std::cout<<imena[i]<<": ";
                do {
                    std::cout<<(klizeci->karta).vrijednost<<" ";
                    prethodni=klizeci;
                    klizeci=klizeci->sljedeci;

                }  while((klizeci!=pocetak) && (klizeci->karta).boja==Boje(i));
                std::cout<<std::endl;
            }
        }
        if(klizeci!=pocetak)  klizeci=prethodni->sljedeci;
        else break;
    }
}
void UnistiSpil(Cvor* pocetak)
{
    Cvor*klizeci(pocetak),*prethodni(pocetak);
    if(pocetak!=nullptr) {
        do {
            prethodni=prethodni->sljedeci;
            klizeci=prethodni->sljedeci;
        } while(klizeci!= nullptr && klizeci!=pocetak);
        prethodni->sljedeci=nullptr;

        Cvor*tmp(nullptr);
        while(pocetak!=nullptr) {
            tmp=pocetak->sljedeci;
            delete pocetak;
            pocetak=tmp;


        }
    }

}
int main()
{
    Cvor*pocetak(nullptr);
    try {
        pocetak=KreirajSpil();
 
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        int b;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::stack<std::pair<Boje, std::string>> red (IzbaciKarteRazbrajanjem(pocetak, r,b));
        
        if(b>52) b=52;

        std::cout<<"U spilu trenutno ima "<<52-b<<" karata, i to: "<<std::endl;
        Ispisi(pocetak);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
int sad(red.size());
        VratiPosljednjihNKarata(pocetak, red, n);
       int c(red.size()); 
        std::cout<<"U spilu trenutno ima "<<52-b+sad-c<<" karata, i to:"<<std::endl;
        Ispisi(pocetak);

    }

    catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::bad_alloc) {};
    UnistiSpil(pocetak);
    return 0;
}
