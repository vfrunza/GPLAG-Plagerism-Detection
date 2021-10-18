/B2017/2018: Zadaća 3, Zadatak 6
/*#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <stack>
#include <memory>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta{
  Boje boja;
  std::string vrijednost;
};

typedef std::multimap<Boje, std::string> MultiMapa;
typedef std::stack<std::pair<std::string, std::string>> Stek;

struct Cvor{
  Karta karta;
  std::shared_ptr<Cvor> sljedeci=nullptr;
};

bool NeispravanSpil(std::shared_ptr<Cvor> it)
{
    auto sljedeci(it); auto trenutni(it);
    auto prethodni(it);
    sljedeci=it->sljedeci; int br(0);
    while(trenutni->sljedeci!=it) {
        if(trenutni->karta.boja>sljedeci->karta.boja) {
            return true;
        } else {
            if(trenutni->karta.boja==sljedeci->karta.boja) {
                if(trenutni->karta.vrijednost=="10") {
                    if(sljedeci->karta.vrijednost!="J" && sljedeci->karta.vrijednost!="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                        return true;
                    }
                } else if(trenutni->karta.vrijednost=="J" && sljedeci->karta.vrijednost!="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost=="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost=="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost>="2" && trenutni->karta.vrijednost<="9" && sljedeci->karta.vrijednost>="2"
                          && sljedeci->karta.vrijednost<="9" && trenutni->karta.vrijednost>sljedeci->karta.vrijednost) {
                    return true;
                }
            }
            if(br!=0 && prethodni->karta.boja==trenutni->karta.boja) {
                if(trenutni->karta.vrijednost=="10") {
                    if(!(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9")) {
                        return true;
                    }
                } else if(trenutni->karta.vrijednost=="J" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10") {
                    return true;
                } else if(trenutni->karta.vrijednost=="Q" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J") {
                    return true;
                } else if(trenutni->karta.vrijednost=="K" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J" && prethodni->karta.vrijednost!="Q") {
                    return true;
                } else if(trenutni->karta.vrijednost=="A" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J" && prethodni->karta.vrijednost!="Q" && prethodni->karta.vrijednost!="K") {
                    return true;
                } else if(trenutni->karta.vrijednost>="2" && trenutni->karta.vrijednost<="9" && prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9"
                          && trenutni->karta.vrijednost<prethodni->karta.vrijednost) {
                    return true;
                }
            }
        }
        sljedeci=sljedeci->sljedeci; trenutni=trenutni->sljedeci;
        if(br!=0) prethodni=prethodni->sljedeci;
        br++;
    }
    return false;
}

std::shared_ptr<Cvor> PostaviBoju(Boje boja, std::shared_ptr<Cvor> it)
{
    for(int i=2; i<=10; i++) {
        it->karta.boja=boja;
        if(i!=10) {
            it->karta.vrijednost=i+'0';
        } else it->karta.vrijednost="10";
        it=it->sljedeci;
    }
    for(int i=0; i<4; i++) {
        it->karta.boja=boja;
        if(i==0)
            it->karta.vrijednost="J";
        else if(i==1)
            it->karta.vrijednost="Q";
        else if(i==2)
            it->karta.vrijednost="K";
        else if(i==3)
            it->karta.vrijednost="A";
        it=it->sljedeci;
    }
    return it;
}

std::shared_ptr<Cvor> StvoriListu(){
    std::shared_ptr<Cvor> pocetak(nullptr), prethodni;
    for(int i=0; i<52; i++){
        std::shared_ptr<Cvor> novi(new Cvor{});
        novi->karta.vrijednost=i+'0';
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    return pocetak;
}

std::shared_ptr<Cvor> KreirajSpil(){
  std::shared_ptr<Cvor> pok(StvoriListu()), it(pok);
  it=PostaviBoju(Boje::Pik, it);
  it=PostaviBoju(Boje::Tref, it);
  it=PostaviBoju(Boje::Herc, it);
  it=PostaviBoju(Boje::Karo, it);

  return pok;
}

int VelicinaListe(std::shared_ptr<Cvor> pok){
    auto it(pok); int br(0);
    while(it->sljedeci!=pok){
        br++;
        it=it->sljedeci;
    }
    br++;
    return br;
}

std::shared_ptr<Cvor> ZadnjiClan(std::shared_ptr<Cvor> pok){
    auto it(pok);
    while(it->sljedeci!=pok){
        it=it->sljedeci;
    }
    return it;
}

void IzbaciKarte(std::shared_ptr<Cvor> pok, MultiMapa &mm)
{
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    int br(0);
    auto itm(mm.begin());
    for(int i=0; i<mm.size(); i++) {
        auto trenutni(pok);
        std::shared_ptr<Cvor> prethodni(ZadnjiClan(pok)), sljedeci(pok);
        sljedeci=sljedeci->sljedeci;
        while(trenutni->sljedeci!=pok) {
            if(trenutni->karta.boja==itm->first && trenutni->karta.vrijednost==itm->second) {
                prethodni->sljedeci=sljedeci; 
                itm=mm.erase(itm);
                br=1;
                break;
            }
            prethodni=prethodni->sljedeci;
            trenutni=trenutni->sljedeci; 
            sljedeci=sljedeci->sljedeci;
        }
        if(br==0)
            itm++;
        br=0;
    }
    if(VelicinaListe(pok)==0) pok=nullptr;
}

Stek IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pok, short int r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    Stek final;
    int brr(0), brb(0);
    auto prethodni(ZadnjiClan(pok));
    auto prethodni_prethodnog(prethodni);
    for(auto it=pok; it->sljedeci!=pok; it=it->sljedeci) {
        while(brr!=r) {
            if(brr!=0)
                prethodni_prethodnog=prethodni_prethodnog->sljedeci;  
            prethodni=prethodni->sljedeci;
            brr++;
            it=it->sljedeci;
        }
        auto sljedeci(it);
        it=prethodni;
        std::pair<std::string, std::string> p;
        p.second=it->karta.vrijednost;
        if(Boje::Pik==it->karta.boja)
            p.first="Pik";
        else if(Boje::Tref==it->karta.boja)
            p.first="Tref";
        else if(Boje::Herc==it->karta.boja)
            p.first="Herc";
        else if(Boje::Karo==it->karta.boja)
            p.first="Karo";
        final.push(p);
        prethodni_prethodnog->sljedeci=sljedeci;
        it=prethodni_prethodnog;
        prethodni=it;
        if(VelicinaListe(pok)==0)
            pok=nullptr;
        if(pok==nullptr) return final;   
        brr=0;
        brb++;
        if(brb==b)
            return final;
    }
    return final;
}

std::pair<Boje, std::string> PretvoriUListu(std::pair<std::string, std::string> p)
{
    std::pair<Boje, std::string> p1;
    p1.second=p.second;
    if(p.first=="Pik")
        p1.first=Boje::Pik;
    else if(p.first=="Tref")
        p1.first=Boje::Tref;
    else if(p.first=="Herc")
        p1.first=Boje::Herc;
    else if(p.first=="Karo")
        p1.first=Boje::Karo;
    return p1;
}

bool NeispravanRed(Stek red)
{
    while(!red.empty()) {
        auto p1(red.top());
        auto p(PretvoriUListu(p1));
        if(p.first!=Boje::Pik && p.first!=Boje::Karo && p.first!=Boje::Tref && p.first!=Boje::Herc)
            return true;
        else if(p.second!="A" && p.second!="J" && p.second!="K" && p.second!="Q"
                && !(p.second>="2" && p.second<="9") && p.second!="10")
            return true;
        red.pop();
    }
    return false;
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pok, Stek &red, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u steku!");
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    if(NeispravanRed(red))
        throw std::logic_error("Neispravne karte!");
    if(pok==nullptr){
        std::shared_ptr<Cvor> prethodni;
        while(!red.empty()){
            auto p(red.top());
            auto p1(PretvoriUListu(p));
            std::shared_ptr<Cvor> novi(new Cvor);
            if(!pok){
                pok=novi;
                pok->karta.boja=p1.first; pok->karta.vrijednost=p1.second;
            } 
            else{
                prethodni->sljedeci=novi;
                prethodni->karta.boja=p1.first; prethodni->karta.vrijednost=p1.second;
            }
            prethodni=novi;
            red.pop();
        }
        prethodni->sljedeci=pok;
    }    
    else{    
    for(int i=0; i<n; i++) {
        auto p(red.top());
        auto p1(PretvoriUListu(p));
        int br(0); auto it(pok); auto prethodni(pok);
        for(it=pok; prethodni->sljedeci!=pok; it=it->sljedeci) {
            if(br==0) prethodni=ZadnjiClan(pok);
            if(p1.second=="A") {
                if(it->karta.boja>p1.first && ((prethodni->karta.vrijednost!="A" && prethodni->karta.boja==p1.first) 
                  || prethodni->karta.boja!=p1.first)){
                    br=0;
                    break;
                } 
            } else if(p1.second=="K") {
                if(((it->karta.boja==p1.first && it->karta.vrijednost=="A") || it->karta.boja>p1.first) 
                   && ((prethodni->karta.vrijednost!="K" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="J") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost>p1.second || it->karta.vrijednost=="A")) || it->karta.boja>p1.first) 
                  && ((prethodni->karta.vrijednost!="J" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="Q") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost=="A" || it->karta.vrijednost=="K")) || it->karta.boja>p1.first) 
                   && ((prethodni->karta.vrijednost!="Q" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="10") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost=="J" || it->karta.vrijednost=="Q" || it->karta.vrijednost=="K" || it->karta.vrijednost=="A"))
                    || it->karta.boja>p1.first) && ((prethodni->karta.vrijednost!="10" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(it->karta.boja==p1.first && p1.second>="0" && p1.second<="9"){ 
                  if((it->karta.vrijednost>p1.second || it->karta.vrijednost=="10") 
                     && ((prethodni->karta.vrijednost!=p1.second && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                      br=0;
                      break;
                  }
             }else if(it->karta.boja==p1.first && it->karta.vrijednost==p1.second) {
                br=1;
                break;
            }
            if(it->sljedeci!=pok)
                br=1;
            else br=0;    
            prethodni=prethodni->sljedeci;
        }
        if(br==0){
           std::shared_ptr<Cvor> novi(new Cvor);
           novi->karta.boja=p1.first; novi->karta.vrijednost=p1.second;
           novi->sljedeci=it;
           prethodni->sljedeci=novi;
        }
        red.pop();
    }
    }
}

int main ()
{
    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    auto s(KreirajSpil());
    try {
        auto s1(IzbaciKarteRazbrajanjem(s, r, b));
        std::cout << "U spilu trenutno ima " << VelicinaListe(s) << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        auto it(s);
        while(Boje::Pik==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << "\nTref: ";
        while(Boje::Tref==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << "\nHerc: ";
        while(Boje::Herc==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Karo: ";
        while(Boje::Karo==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl;
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPosljednjihNKarata(s, s1, n);
        std::cout << "U spilu trenutno ima " << VelicinaListe(s) << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        it=s;
        while(Boje::Pik==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Tref: ";
        while(Boje::Tref==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Herc: ";
        while(Boje::Herc==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Karo: ";
        while(Boje::Karo==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl;
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    
    std::shared_ptr<Cvor> prethodni(ZadnjiClan(s)), trenutni(s);
    int vel(VelicinaListe(s));
    for(int i=0; i<vel; i++){
        prethodni->sljedeci=nullptr;
        prethodni=trenutni;
        trenutni=trenutni->sljedeci;
    }

    return 0;
}*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <stack>
#include <memory>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta{
  Boje boja;
  std::string vrijednost;
};

typedef std::multimap<Boje, std::string> MultiMapa;
typedef std::stack<std::pair<std::string, std::string>> Stek;

struct Cvor{
  Karta karta;
  std::shared_ptr<Cvor> sljedeci=nullptr;
};

bool NeispravanSpil(std::shared_ptr<Cvor> it)
{
    auto sljedeci(it); auto trenutni(it);
    auto prethodni(it);
    sljedeci=it->sljedeci; int br(0);
    while(trenutni->sljedeci!=it) {
        if(trenutni->karta.boja>sljedeci->karta.boja) {
            return true;
        } else {
            if(trenutni->karta.boja==sljedeci->karta.boja) {
                if(trenutni->karta.vrijednost=="10") {
                    if(sljedeci->karta.vrijednost!="J" && sljedeci->karta.vrijednost!="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                        return true;
                    }
                } else if(trenutni->karta.vrijednost=="J" && sljedeci->karta.vrijednost!="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost=="Q" && sljedeci->karta.vrijednost!="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost=="K" && sljedeci->karta.vrijednost!="A") {
                    return true;
                } else if(trenutni->karta.vrijednost>="2" && trenutni->karta.vrijednost<="9" && sljedeci->karta.vrijednost>="2"
                          && sljedeci->karta.vrijednost<="9" && trenutni->karta.vrijednost>sljedeci->karta.vrijednost) {
                    return true;
                }
            }
            if(br!=0 && prethodni->karta.boja==trenutni->karta.boja) {
                if(trenutni->karta.vrijednost=="10") {
                    if(!(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9")) {
                        return true;
                    }
                } else if(trenutni->karta.vrijednost=="J" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10") {
                    return true;
                } else if(trenutni->karta.vrijednost=="Q" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J") {
                    return true;
                } else if(trenutni->karta.vrijednost=="K" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J" && prethodni->karta.vrijednost!="Q") {
                    return true;
                } else if(trenutni->karta.vrijednost=="A" && !(prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9") && prethodni->karta.vrijednost!="10"
                          && prethodni->karta.vrijednost!="J" && prethodni->karta.vrijednost!="Q" && prethodni->karta.vrijednost!="K") {
                    return true;
                } else if(trenutni->karta.vrijednost>="2" && trenutni->karta.vrijednost<="9" && prethodni->karta.vrijednost>="2" && prethodni->karta.vrijednost<="9"
                          && trenutni->karta.vrijednost<prethodni->karta.vrijednost) {
                    return true;
                }
            }
        }
        sljedeci=sljedeci->sljedeci; trenutni=trenutni->sljedeci;
        if(br!=0) prethodni=prethodni->sljedeci;
        br++;
    }
    return false;
}

std::shared_ptr<Cvor> PostaviBoju(Boje boja, std::shared_ptr<Cvor> it)
{
    for(int i=2; i<=10; i++) {
        it->karta.boja=boja;
        if(i!=10) {
            it->karta.vrijednost=i+'0';
        } else it->karta.vrijednost="10";
        it=it->sljedeci;
    }
    for(int i=0; i<4; i++) {
        it->karta.boja=boja;
        if(i==0)
            it->karta.vrijednost="J";
        else if(i==1)
            it->karta.vrijednost="Q";
        else if(i==2)
            it->karta.vrijednost="K";
        else if(i==3)
            it->karta.vrijednost="A";
        it=it->sljedeci;
    }
    return it;
}

std::shared_ptr<Cvor> StvoriListu(){
    std::shared_ptr<Cvor> pocetak(nullptr), prethodni;
    for(int i=0; i<52; i++){
        std::shared_ptr<Cvor> novi(new Cvor{});
        novi->karta.vrijednost=i+'0';
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    return pocetak;
}

std::shared_ptr<Cvor> KreirajSpil(){
  std::shared_ptr<Cvor> pok(StvoriListu()), it(pok);
  it=PostaviBoju(Boje::Pik, it);
  it=PostaviBoju(Boje::Tref, it);
  it=PostaviBoju(Boje::Herc, it);
  it=PostaviBoju(Boje::Karo, it);

  return pok;
}

int VelicinaListe(std::shared_ptr<Cvor> pok){
    auto it(pok); int br(0);
    while(it->sljedeci!=pok){
        br++;
        it=it->sljedeci;
    }
    br++;
    return br;
}

std::shared_ptr<Cvor> ZadnjiClan(std::shared_ptr<Cvor> pok){
    auto it(pok);
    while(it->sljedeci!=pok){
        it=it->sljedeci;
    }
    return it;
}

void IzbaciKarte(std::shared_ptr<Cvor> pok, MultiMapa &mm)
{
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    int br(0);
    auto itm(mm.begin());
    for(int i=0; i<mm.size(); i++) {
        auto trenutni(pok);
        std::shared_ptr<Cvor> prethodni(ZadnjiClan(pok)), sljedeci(pok);
        sljedeci=sljedeci->sljedeci;
        while(trenutni->sljedeci!=pok) {
            if(trenutni->karta.boja==itm->first && trenutni->karta.vrijednost==itm->second) {
                prethodni->sljedeci=sljedeci; 
                itm=mm.erase(itm);
                br=1;
                break;
            }
            prethodni=prethodni->sljedeci;
            trenutni=trenutni->sljedeci; 
            sljedeci=sljedeci->sljedeci;
        }
        if(br==0)
            itm++;
        br=0;
    }
    if(VelicinaListe(pok)==0) pok=nullptr;
}

Stek IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pok, short int r, int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    Stek final;
    int brr(0), brb(0);
    auto prethodni(ZadnjiClan(pok));
    auto prethodni_prethodnog(prethodni);
    for(auto it=pok; it->sljedeci!=pok; it=it->sljedeci) {
        while(brr!=r) {
            if(brr!=0)
                prethodni_prethodnog=prethodni_prethodnog->sljedeci;  
            prethodni=prethodni->sljedeci;
            brr++;
            it=it->sljedeci;
        }
        auto sljedeci(it);
        it=prethodni;
        std::pair<std::string, std::string> p;
        p.second=it->karta.vrijednost;
        if(Boje::Pik==it->karta.boja)
            p.first="Pik";
        else if(Boje::Tref==it->karta.boja)
            p.first="Tref";
        else if(Boje::Herc==it->karta.boja)
            p.first="Herc";
        else if(Boje::Karo==it->karta.boja)
            p.first="Karo";
        final.push(p);
        prethodni_prethodnog->sljedeci=sljedeci;
        it=prethodni_prethodnog;
        prethodni=it;
        if(VelicinaListe(pok)==0)
            pok=nullptr;
        if(pok==nullptr) return final;   
        brr=0;
        brb++;
        if(brb==b)
            return final;
    }
    return final;
}

std::pair<Boje, std::string> PretvoriUListu(std::pair<std::string, std::string> p)
{
    std::pair<Boje, std::string> p1;
    p1.second=p.second;
    if(p.first=="Pik")
        p1.first=Boje::Pik;
    else if(p.first=="Tref")
        p1.first=Boje::Tref;
    else if(p.first=="Herc")
        p1.first=Boje::Herc;
    else if(p.first=="Karo")
        p1.first=Boje::Karo;
    return p1;
}

bool NeispravanRed(Stek red)
{
    while(!red.empty()) {
        auto p1(red.top());
        auto p(PretvoriUListu(p1));
        if(p.first!=Boje::Pik && p.first!=Boje::Karo && p.first!=Boje::Tref && p.first!=Boje::Herc)
            return true;
        else if(p.second!="A" && p.second!="J" && p.second!="K" && p.second!="Q"
                && !(p.second>="2" && p.second<="9") && p.second!="10")
            return true;
        red.pop();
    }
    return false;
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pok, Stek &red,const int &n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u steku!");
    if(VelicinaListe(pok)>52 || NeispravanSpil(pok))
        throw std::logic_error("Neispravna lista!");
    if(NeispravanRed(red))
        throw std::logic_error("Neispravne karte!");
    if(pok==nullptr){
        std::shared_ptr<Cvor> prethodni;
        while(!red.empty()){
            auto p(red.top());
            auto p1(PretvoriUListu(p));
            std::shared_ptr<Cvor> novi(new Cvor);
            if(!pok){
                pok=novi;
                pok->karta.boja=p1.first; pok->karta.vrijednost=p1.second;
            } 
            else{
                prethodni->sljedeci=novi;
                prethodni->karta.boja=p1.first; prethodni->karta.vrijednost=p1.second;
            }
            prethodni=novi;
            red.pop();
        }
        prethodni->sljedeci=pok;
    }    
    else{    
    for(int i=0; i<n; i++) {
        auto p(red.top());
        auto p1(PretvoriUListu(p));
        int br(0); auto it(pok); auto prethodni(pok);
        for(it=pok; prethodni->sljedeci!=pok; it=it->sljedeci) {
            if(br==0) prethodni=ZadnjiClan(pok);
            if(p1.second=="A") {
                if(it->karta.boja>p1.first && ((prethodni->karta.vrijednost!="A" && prethodni->karta.boja==p1.first) 
                  || prethodni->karta.boja!=p1.first)){
                    br=0;
                    break;
                } 
            } else if(p1.second=="K") {
                if(((it->karta.boja==p1.first && it->karta.vrijednost=="A") || it->karta.boja>p1.first) 
                   && ((prethodni->karta.vrijednost!="K" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="J") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost>p1.second || it->karta.vrijednost=="A")) || it->karta.boja>p1.first) 
                  && ((prethodni->karta.vrijednost!="J" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="Q") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost=="A" || it->karta.vrijednost=="K")) || it->karta.boja>p1.first) 
                   && ((prethodni->karta.vrijednost!="Q" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(p1.second=="10") {
                if(((it->karta.boja==p1.first && (it->karta.vrijednost=="J" || it->karta.vrijednost=="Q" || it->karta.vrijednost=="K" || it->karta.vrijednost=="A"))
                    || it->karta.boja>p1.first) && ((prethodni->karta.vrijednost!="10" && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                    br=0;
                    break;
                }
            } else if(it->karta.boja==p1.first && p1.second>="0" && p1.second<="9"){ 
                  if((it->karta.vrijednost>p1.second || it->karta.vrijednost=="10") 
                     && ((prethodni->karta.vrijednost!=p1.second && prethodni->karta.boja==p1.first) || prethodni->karta.boja!=p1.first)) {
                      br=0;
                      break;
                  }
             }else if(it->karta.boja==p1.first && it->karta.vrijednost==p1.second) {
                br=1;
                break;
            }
            if(it->sljedeci!=pok)
                br=1;
            else br=0;    
            prethodni=prethodni->sljedeci;
        }
        if(br==0){
           std::shared_ptr<Cvor> novi(new Cvor);
           novi->karta.boja=p1.first; novi->karta.vrijednost=p1.second;
           novi->sljedeci=it;
           prethodni->sljedeci=novi;
        }
        red.pop();
    }
    }
}

int main ()
{
    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    auto s(KreirajSpil());
    try {
        auto s1(IzbaciKarteRazbrajanjem(s, r, b));
        std::cout << "U spilu trenutno ima " << VelicinaListe(s) << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        auto it(s);
        while(Boje::Pik==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << "\nTref: ";
        while(Boje::Tref==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << "\nHerc: ";
        while(Boje::Herc==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Karo: ";
        while(Boje::Karo==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl;
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPosljednjihNKarata(s, s1, n);
        std::cout << "U spilu trenutno ima " << VelicinaListe(s) << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        it=s;
        while(Boje::Pik==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Tref: ";
        while(Boje::Tref==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Herc: ";
        while(Boje::Herc==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl << "Karo: ";
        while(Boje::Karo==it->karta.boja) {
            std::cout << it->karta.vrijednost << " ";
            it=it->sljedeci;
        }
        std::cout << std::endl;
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    
    std::shared_ptr<Cvor> prethodni(ZadnjiClan(s)), trenutni(s);
    int vel(VelicinaListe(s));
    for(int i=0; i<vel; i++){
        prethodni->sljedeci=nullptr;
        prethodni=trenutni;
        trenutni=trenutni->sljedeci;
    }

    return 0;
}

