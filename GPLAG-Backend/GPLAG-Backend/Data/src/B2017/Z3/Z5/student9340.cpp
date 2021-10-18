/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <map>
#include <stdexcept>
#include <stack> /*Izmijenjeno samo umjesto queue - > stack*/
enum class Boje
{
    Pik=0, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje,std::string>> Deklaracija;
void KreirajSpil (Deklaracija& lista)
{
    for (int i=0; i<4; i++) {
        for (int j=1; j<=13; j++) {
            std::pair<Boje,std::string> par;
            if (j==10) par = std::make_pair(Boje(i),"J");
            else if (j==11) par = std::make_pair(Boje(i),"Q");
            else if (j==12) par = std::make_pair(Boje(i),"K");
            else if (j==13) par = std::make_pair(Boje(i),"A");
            else par = std::make_pair(Boje(i),std::to_string(j+1));
            lista.push_back(par);
        }
    }
}
void IspisiSpil (const Deklaracija& lista)
{
    int i(0),prviput0(0),prviput1(0),prviput2(0),prviput3(0);
    for (auto it = lista.begin(); it!=lista.end(); it++) {
        if (int (it->first) == 0 && prviput0==0) {
            std::cout<< "Pik: ";
            prviput0++;
        } else if (int (it->first) == 1 && prviput1==0) {
            std::cout<<std::endl<< "Tref: ";
            prviput1++;
        } else if (int (it->first) == 2 && prviput2==0) {
            std::cout<<std::endl<< "Herc: ";
            prviput2++;
        } else if (int (it->first) == 3 && prviput3==0) {
            std::cout<<std::endl<< "Karo: ";
            prviput3++;
        } else;
        std::cout<<it->second<< " ";
        i++;
    }
}
bool Provjera (const Deklaracija& spil)
{
    if ((spil.size())>52) return false;
    return true;
}
void IzbaciKarte(Deklaracija& lista, std::multimap<Boje,std::string>& mapa)
{
    try {
        if (!Provjera(lista)) throw std::logic_error("Neispravna lista!"); /*DORADI FJU PROVJERA*/ for (auto itMAPE=mapa.begin(); itMAPE!=mapa.end(); itMAPE++) {
            for (auto itLISTE=lista.begin(); itLISTE!=lista.end(); itLISTE++) {
                if (itMAPE->first==itLISTE->first && itMAPE->second==itLISTE->second) {
                    for (auto it=lista.begin(); it!=lista.end(); it++) {
                        /*Brisanje para iz LISTE*/ if (it->first==itLISTE->first && it->second==itLISTE->second) {
                            it=lista.erase(it);
                        }
                    }
                    mapa.erase(itMAPE->first); /*Brisanje para iz MAPE*/
                }
            }
        }
    } catch (std::logic_error e) {
        std::cout<<e.what();
        throw;
    }
}
std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (Deklaracija &lista, const short int& r, const int& b )
{
    std::stack <std::pair<std::string,std::string>> red;
    try {
        if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
        if (!Provjera) throw std::logic_error("Neispravna lista!");
        int broj_izbacenih(0);
        int brojac(1);
        int rr(r);
        for (auto it=lista.begin();; it++) {
            if (it==lista.end()) it=lista.begin();
            if (brojac==rr) {
                std::string s;
                if (int (it->first) == 0) s="Pik";
                else if (int (it->first) == 1) s="Tref";
                else if (int (it->first) == 2) s="Herc";
                else if (int (it->first) == 3) s="Karo";
                else;
                std::pair<std::string,std::string> par(s,it->second);
                red.push(par);
                it=lista.erase(it);
                rr=r;
                brojac=1;
                broj_izbacenih++;
            }
            brojac++;
            if (broj_izbacenih==b) break;
        }
    } catch (std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what();
        throw;
    }
    return red;
}
bool DaLiJeVece (const std::string& poslije,const std::string& karta)
{
    if (karta>="2" && karta<="8") return poslije>karta;
    else if (karta=="9" && poslije=="10") return true;
    else if (karta=="10" && poslije=="J") return true;
    else if (karta=="J" && poslije=="Q") return true;
    else if (karta=="Q" && poslije=="K") return true;
    else if (karta=="K" && poslije=="A") return true;
    else return false;
}
void UbaciKartu (std::pair<std::string,std::string>& par, Deklaracija& lista)
{
    std::pair<Boje,std::string> karta;
    if (par.first==std::string("Pik")) karta=std::make_pair(Boje(0),par.second);
    else if (par.first==std::string("Tref")) karta=std::make_pair(Boje(1),par.second);
    else if (par.first==std::string("Herc")) karta=std::make_pair(Boje(2),par.second);
    else karta=std::make_pair(Boje(3),par.second);
    for (auto it=lista.begin(); it!=lista.end(); it++) { /*Provjera da li se nalaze u spilu karta vec*/
        if (it->first==karta.first && it->second==karta.second) return;
    }
    for (auto it=lista.begin(); it!=lista.end(); it++) {
        if (it->first==karta.first) {
            auto pom(it),prije(it),poslije(it);
            while(pom->first==karta.first) {
                poslije++;
                if (karta.second=="A" && prije->second=="K") {
                    lista.insert(++prije,karta);
                    break;
                }
                if (DaLiJeVece(prije->second,karta.second) && prije!=lista.end()) {
                    lista.insert(prije,karta);
                    break;
                }
                if ((DaLiJeVece(poslije->second,karta.second)) && poslije!=lista.end()) {
                    lista.insert(poslije,karta);
                    break;
                }
                prije++;
                pom++;
            }
            break;
        }
    }
}
void VratiPrvihNKarata (Deklaracija& lista,std::stack<std::pair<std::string,std::string>>& red, int n)
{
    try {
        if (n<0) throw std::domain_error("Broj n je besmislen!");  /*Provjeri sta se smatra besmislenim*/
        if (n>red.size()) throw std::range_error ("Nedovoljno karata u steku!");
        if(!Provjera(lista)) throw std::logic_error("Neispravna lista!");
        /*DODATI PROVJERU ZA NEISPRAVAN RED*/
        for (int i=0; i<n; i++) {
            std::pair<std::string,std::string> par (red.top()); /*POGRESAN STRING UBACI*/
            red.pop();
            UbaciKartu(par,lista);
        }

    } catch(std::range_error e) {
        std::cout<<"Izuzetak: "<<e.what();
        throw;
    } catch(std::domain_error e) {
        std::cout<<"Izuzetak: "<<e.what();
        throw;
    }
}
int main ()
{
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        Deklaracija spil;
        KreirajSpil(spil);
        std::stack<std::pair<std::string,std::string>> red (IzbaciKarteRazbrajanjem(spil,r,b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,red,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);
    } catch(...) {
        return 1;
    };
    return 0;
}