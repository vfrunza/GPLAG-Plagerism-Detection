#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <stdexcept>
#include<algorithm>
#include <queue>
#include <map>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;
enum class Boje
{
    Pik, Tref, Herc, Karo
};
std::vector<string>vK {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


bool Kriterij(const std::pair< Boje,string> &prva,const std::pair<Boje,string> &druga)
{
    if(prva.first==druga.first) { //ako se porede karte iste boje
        auto iterPrvi(find(vK.begin(),vK.end(),prva.second));
        auto iterDrugi(find(vK.begin(),vK.end(),druga.second));
        return iterPrvi<iterDrugi;
    } else
        return prva.first<druga.first;

}
std::list<std::pair< Boje,string>> KreirajSpil()
{
    std::list<std::pair< Boje,string>> lista;

    for(int j=0; j<13; j++)
        lista.push_back(std::make_pair(Boje::Pik,vK[j]));

    for(int j=0; j<13; j++)
        lista.push_back(std::make_pair(Boje::Tref,vK[j]));

    for(int j=0; j<13; j++)
        lista.push_back(std::make_pair(Boje::Herc,vK[j]));

    for(int j=0; j<13; j++)
        lista.push_back(std::make_pair(Boje::Karo,vK[j]));

    return lista;


}
bool ProvjeriBoje( Boje boja)
{
    if(boja!=Boje::Pik && boja!=Boje::Tref && boja!=Boje::Herc && boja!=Boje::Karo)
        return false;
    return true;
}
bool ProvjeriKartu(string k)
{

    int istina(1);
    for(int i=0; i<13; i++) {
        if(k==vK[i]) {
            istina=1;
            break;
        } else istina=0;
    }
    if(istina) return true;
    return false;
}
bool ProvjeriRed(std::queue<std::pair<string,string>> red)
{
    while(!red.empty()) {
        std::pair<string,string> par(red.front());
        red.pop();
        if(par.first!="Pik" && par.first!="Tref" && par.first!="Herc" && par.first!="Karo") return false;
        if(!ProvjeriKartu(par.second)) return false;
        
    }
    return true;
}
bool DaLijeRedOk(std::list< std::pair< Boje,string>> &spil)
{
    //PROBLEM
    auto lista(KreirajSpil());
    for(std::list< std::pair< Boje,string>>::iterator it=lista.begin(); it!=lista.end(); it++) {

        auto iter=find(spil.begin(),spil.end(),*it);
        if(iter==spil.end()) {
            it=lista.erase(it);
            it--;
        }
    }

    if(equal(lista.begin(),lista.end(),spil.begin()))
        return true;
    else return false;

}

string Konvertuj(Boje b)
{
    if(b==Boje::Pik) return "Pik";
    else if(b==Boje::Tref) return "Tref";
    else if(b==Boje::Herc) return "Herc";
    else return "Karo";
}
Boje KonvertujUB(string b)
{
    if(b=="Pik") return Boje::Pik;
    else if(b=="Tref") return Boje::Tref;
    else if(b=="Herc") return Boje::Herc;
    else return Boje::Karo;
}
void IzbaciKarte(std::list<std::pair< Boje,string>> &spil,std::multimap<Boje, std::string> &multimapa)
{
    if(int(spil.size())>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++)
        if(!ProvjeriBoje(it->first)) throw std::logic_error("Neispravna lista!");

    for(auto it=spil.begin(); it!=spil.end();it++)
        if(!ProvjeriKartu(it->second)) throw std::logic_error("Neispravna lista!"); //provjera da li su karte besmislene
    if(!DaLijeRedOk(spil)) throw std::logic_error("Neispravna lista!");

    for(std::multimap<Boje, std::string>::iterator it=multimapa.begin(); it!=multimapa.end(); it++) {
        auto iter = spil.begin();
        for(iter = spil.begin(); iter != spil.end(); iter++) {
            if(iter->first == it->first && iter->second == it->second) break;
        }
        if(iter!=spil.end()) {
            spil.erase(iter);
            it=multimapa.erase(it);
        } else {
            it++;
            continue;
        }
    }

}
std::queue<std::pair<string,string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje,string>> &spil,const short int &r,const int &b)
{

    if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");

    if(int(spil.size())>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++)
        if(!ProvjeriBoje(it->first)) throw std::logic_error("Neispravna lista!");

    for(auto it=spil.begin(); it!=spil.end(); it++)
        if(!ProvjeriKartu(it->second)) throw std::logic_error("Neispravna lista!"); //provjera da li su karte besmislene
    if(!DaLijeRedOk(spil)) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<string,string>> red;
    auto it=spil.begin();
    int pocetak(0);
    for(int i(0); i < r - 1; i++) {
        it++;
        if(it == spil.end()) it = spil.begin();
    }
    while(pocetak!=b && spil.size() != 0) {

        string boja(Konvertuj(it->first));
        string karta(it->second);
        red.push(std::make_pair(boja,karta));
        it=spil.erase(it);
        //it--;
        for(int i(0); i < r - 1; i++) {
            it++;
            if(it == spil.end()) it = spil.begin();
        }

        pocetak++;
    }
    return red;
}

void VratiPrvihNKarata(std::list<std::pair<Boje,string>> &spil, std::queue<std::pair<string,string>> &red,int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");

    if(!ProvjeriRed(red)) throw std::logic_error("Neispravne karte!");
    if(int(spil.size())>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++)
        if(!ProvjeriBoje(it->first)) throw std::logic_error("Neispravna lista!");

    for(auto it=spil.begin(); it!=spil.end(); it++)
        if(!ProvjeriKartu(it->second)) throw std::logic_error("Neispravna lista!"); //provjera da li su karte besmislene
    if(!DaLijeRedOk(spil)) throw std::logic_error("Neispravna lista!");
    int j(n);
    while(j!=0) {
        std::pair<string,string> par(red.front()); //uzimam iz reda
        red.pop();
        auto rezPar=std::make_pair(KonvertujUB(par.first),par.second);
        auto iteratorListe(spil.begin());
        bool postoji(false);

        while(iteratorListe != spil.end()) {
            if(Konvertuj(iteratorListe->first) == par.first && iteratorListe->second == par.second) {
                postoji = true;
                break;
            }
            iteratorListe++;
        }
        if(postoji) continue;
        spil.push_back(rezPar);
        j--;
    }
    spil.sort(Kriterij);

}

int main ()
{
    try {
        cout<<"Unesite korak razbrajanja: ";
        short int korak_razbrajanja;
        cin>>korak_razbrajanja;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        int izbaciti;
        cin>>izbaciti; //poziv funkcije kreiraj spil
        auto spil(KreirajSpil());
        auto red(IzbaciKarteRazbrajanjem(spil,korak_razbrajanja,izbaciti)); //iz spila izbacene karte i vracen red koji sadrzi izbacene karte
        cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;

        for(auto it(spil.begin()); it!=spil.end(); it++) {
            cout<<Konvertuj(it->first)<<": ";
            auto boja(it->first);
            while(it->first==boja && it!=spil.end()) {
                cout<<it->second<<" ";
                it++;
            }
            it--;
            cout<<std::endl;
        }
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        cin>>n;
        VratiPrvihNKarata(spil,red,n);
        cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        for(auto it =spil.begin(); it!=spil.end(); it++) {
            cout<<Konvertuj(it->first)<<": ";
            auto boja(it->first);
            while(it->first==boja && it!=spil.end()) {
                cout<<it->second<<" ";
                it++;
            }
            it--;
            cout<<std::endl;
        }

    } catch(std::logic_error e) {
        cout<<"Izuzetak: "<<e.what();
    } catch(std::domain_error e) {
        cout<<"Izuzetak: "<<e.what();
    } catch(std::range_error e) {
        cout<<"Izuzetak: "<<e.what();
    }

    return 0;
}
