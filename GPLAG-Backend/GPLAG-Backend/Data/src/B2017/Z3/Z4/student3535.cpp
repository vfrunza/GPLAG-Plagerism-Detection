/B2017/2018: Zadaća 3, Zadatak 4
/*TODO:
    -izbaci (skontati sta zeza memorijska greska)

*/
#include <iostream>
#include <utility>
#include <list>
#include <map>
#include <iterator>
#include <string>
#include <stdexcept>
#include <queue>
#include <algorithm>
using std::queue;
using std::string;
using std::pair;
using std::list;
using std::cin;
using std::cout;
using std::multimap;
enum class Boje
{
    Pik,Tref,Herc,Karo
};

bool PorediKarte(pair<Boje,string> a, pair<Boje,string> b)
{
    if(a.first!=b.first) {
        return static_cast<int>(a.first) < static_cast<int>(b.first);
    } else {
        int prvi(0),drugi(0);
        if(a.second=="J") {
            prvi=11;
        } else if(a.second=="Q") {
            prvi=12;
        } else if(a.second=="K") {
            prvi=13;
        } else if(a.second=="A") {
            prvi=14;
        } else {
            prvi=std::stoi(a.second);
        }

        if(b.second=="J") {
            drugi=11;
        } else if(b.second=="Q") {
            drugi=12;
        } else if(b.second=="K") {
            drugi=13;
        } else if(b.second=="A") {
            drugi=14;
        } else {
            drugi=std::stoi(b.second);
        }
        return prvi<drugi;
    }
}
list<pair<Boje,string>> KreirajSpil()
{
    Boje color;
    list<pair<Boje,string>> spil;
    string temp;
    for(int i=0; i<4; i++) {
        //cout<<i<" ";
        switch(i) {
        case 0:
            color=Boje::Pik;
            break;
        case 1:
            color=Boje::Tref;
            break;
        case 2:
            color=Boje::Herc;
            break;
        case 3:
            color=Boje::Karo;
            break;
        }
        for(int j=2; j<=14; j++) {
            switch(j) {
            case 11:
                temp+=('J');
                break;
            case 12:
                temp+=('Q');
                break;
            case 13:
                temp+=('K');
                break;
            case 14:
                temp+=('A');
                break;
            default:
                temp+=std::to_string(j);
                break;
            }
            //cout<<temp<<" ";
            spil.push_back(std::make_pair(color,temp));
            temp.clear();
        }
    }
    return spil;
}

void IspisiSpil(list<pair<Boje,string>> spil)
{

    cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
    for(int i=0; i<4; i++) {
        switch(i) {
        case 0:
            cout<<"Pik: ";
            break;
        case 1:
            cout<<"Tref: ";
            break;
        case 2:
            cout<<"Herc: ";
            break;
        case 3:
            cout<<"Karo: ";
            break;
        }
        for(auto it(spil.begin()); it!=spil.end(); it++) {
            if(it->first==Boje::Pik&&i==0) {
                cout<<it->second<<" ";
            }
            if(it->first==Boje::Tref&&i==1) {
                cout<<it->second<<" ";
            }
            if(it->first==Boje::Herc&&i==2) {
                cout<<it->second<<" ";
            }
            if(it->first==Boje::Karo&&i==3) {
                cout<<it->second<<" ";
            }
        }

        cout<<"\n";
    }
}

void ProvjeraSpila(list<pair<Boje,string>> spil)
{
    if(spil.size()>52) {
        throw std::logic_error("Neispravna lista!");
    }
    auto it2(spil.begin());
    it2++;
    auto it1(spil.begin());
    for(; it2!=spil.end(); it2++) {
        if(!PorediKarte(*it1,*it2)) {
            throw std::logic_error("Neispravna lista!");
        }
        it1++;
    }
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        auto a(it->first);
        auto b(it->second);
        if(a!=Boje::Pik&&a!=Boje::Tref&&a!=Boje::Herc&&a!=Boje::Karo&&b!="J"
                &&b!="K"&&b!="Q"&&b!="A"&&b!="2"&&b!="3"&&b!="4"&&b!="5"&&b!="6"
                &&b!="7"&&b!="8"&&b!="9"&&b!="10") {
            throw std::logic_error("Neispravna lista!");
        }

    }
}

void IzbaciKarte(list<pair<Boje,string>> &spil, multimap<Boje,string> &multimapa)
{
    try {
        ProvjeraSpila(spil);
    
        for(auto it1(multimapa.begin()); it1!=multimapa.end();) {
            auto it2(std::find(spil.begin(),spil.end(),std::make_pair(it1->first,it1->second)));
            if(it2!=spil.end()) {
                it1=multimapa.erase(it1);
                spil.erase(it2);
            } else {
            it1++;
            }
        }
    } catch(...) {
        throw;
    }
}

queue<pair<string,string>> IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &spil, short int &korak, const int &broj_za_izbaciti)
{
    try {

        ProvjeraSpila(spil);
        queue<pair<string,string>> rez;
        if(korak>52||korak<1||broj_za_izbaciti<1) {
            throw std::logic_error("Neispravni elementi za izbacivanje!");
        }
        std::multimap<Boje,string>multimapa;
        auto it(spil.begin());
        int brojac(0),izbaceni(0);
        while(true) {
            brojac++;
            if(it==spil.end()) {
                it=spil.begin();
                
            } 
            bool nadjen(false);
            for(auto itm(multimapa.begin());itm!=multimapa.end();itm++){
                if(pair<Boje,string>(itm->first,itm->second)==*it){
                    nadjen=true;
                }
            }
            if(nadjen){
                
                it++;
                nadjen=false;
            }
            if(brojac==korak) {
                multimapa.insert(*it);
                switch(it->first) {
                case Boje::Pik :
                    rez.push(std::make_pair("Pik",it->second));
                    break;
                case Boje::Tref :
                    rez.push(std::make_pair("Tref",it->second));
                    break;
                case Boje::Herc :
                    rez.push(std::make_pair("Herc",it->second));
                    break;
                case Boje::Karo :
                    rez.push(std::make_pair("Karo",it->second));
                    break;
                }

                izbaceni++;
                brojac=0;
            }

            if(izbaceni==broj_za_izbaciti||spil.size()==0) {
                break;
            }

            it++;
        }
        IzbaciKarte(spil,multimapa);
        return rez;
    } catch(...) {
        throw;
    }
}

void VratiPrvihNKarata(list<pair<Boje,string>> &spil,queue<pair<string,string>> red, int n)
{
    try {
        ProvjeraSpila(spil);
        if(n<0) {
            throw std::domain_error("Broj n je besmislen!");
        }
        
        if(n>red.size()) {
            throw std::range_error("Nedovoljno karata u redu!");
        }
        

        pair<Boje,string> element;

        for(int i=0; i<n; i++) {
            if(red.front().first=="Pik") {
                element=std::make_pair(Boje::Pik,red.front().second);
            } else if(red.front().first=="Tref") {
                element=std::make_pair(Boje::Tref,red.front().second);
            } else if(red.front().first=="Herc") {
                element=std::make_pair(Boje::Herc,red.front().second);
            } else if(red.front().first=="Karo") {
                element=std::make_pair(Boje::Karo,red.front().second);
            }

            if(std::find(spil.begin(),spil.end(),element)!=spil.end()) {
                red.pop();
                i--;
            }
            spil.push_back(element);
            red.pop();
        }
        spil.sort(PorediKarte);
    } catch(...) {
        throw;
    }
}

int main ()
{
    try {
        list<pair<Boje,string>> spil;
        spil=KreirajSpil();
        cout<<"Unesite korak razbrajanja: ";
        short int korak;
        cin>>korak;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        int broj;
        cin>>broj;
        queue<pair<string,string>> red=IzbaciKarteRazbrajanjem(spil,korak,broj);
        IspisiSpil(spil);
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>broj;
        VratiPrvihNKarata(spil,red,broj);
        IspisiSpil(spil);
    } catch (std::domain_error err) {
        cout<<"Izuzetak: "<<err.what();
    }     catch (std::logic_error err) {
        cout<<"Izuzetak: "<<err.what();
    } catch (std::range_error err) {
        cout<<"Izuzetak: "<<err.what();
    }
    return 0;
}
