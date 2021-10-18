/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <iterator>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::vector<std::string> v {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Boje b(Boje::Pik);
    std::list<std::pair<Boje, std::string>> l;
    for(int i=0 ; i<4 ; i++) {
        if(i==0) b=Boje::Pik;
        if(i==1) b=Boje::Tref;
        if(i==2) b=Boje::Herc;
        if(i==3) b=Boje::Karo;
        for(int j=0 ; j<v.size() ; j++) {
            l.push_back(std::make_pair(b,v.at(j)));
        }
    }
    return l;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &l, std::multimap<Boje,std::string> &m)
{
    if(l.size()>52) throw std::logic_error ("Neispravna lista!");
    std::vector<std::string> v {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for(auto it = m.begin() ; it!=m.end() ; it++) {
        for(auto il = l.begin() ; il!=l.end() ; il++) {
            if( it->first==il->first && it->second==il->second) {
                it=m.erase(it);
                il=l.erase(il);
            }

        }
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &l, const short int  &r,const  int   &b)
{

    if(r<1 || r>52 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if(l.size()>52) throw std::logic_error ("Neispravna lista!");
    std::queue<std::pair<std::string,std::string>> q;
    int i(0);

    auto it(l.begin());
    while(i<b) {

        int j(1);
        while(j<r) {

            j++;

            it++;
            if(it==l.end()) it=l.begin();
        }

        std::string prvi;
        if(it->first==Boje::Pik) prvi="Pik";
        if(it->first==Boje::Tref) prvi="Tref";
        if(it->first==Boje::Herc) prvi="Herc";
        if(it->first==Boje::Karo) prvi="Karo";
        q.push(std::make_pair(prvi,it->second));
        it=l.erase(it);


        i++;
    }
    return q;
}

void VratiPrvihHKarata (std::list<std::pair<Boje, std::string>> &l, std::queue<std::pair<std::string,std::string>> &q, int n )
{
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n>q.size()) throw std::range_error ("Nedovoljno karata u redu!");

    if(l.size()>52) throw std::logic_error ("Neispravna lista!");
    std::vector<std::string> v {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int i(0);
    while(i<n) {
        auto it = l.begin();

        while(1) {
            std::string prvi {"Pik"};
            if(q.front().first=="Tref") {
                while(it->first!=Boje::Tref) it++;
                prvi="Tref";
            }
            if(q.front().first=="Herc") {
                while(it->first!=Boje::Herc) it++;
                prvi="Herc";
            }
            if(q.front().first=="Karo") {
                while(it->first!=Boje::Karo) it++;
                prvi="Karo";
            }



            if( q.front().first==prvi) {
                for(int j=0 ; j<v.size() ; j++) {
                    if( it->second==v.at(j)) it++;

                    else if(q.front().second==v.at(j)) break;
                }

                if(q.front().first=="Pik") l.insert(it,std::make_pair(Boje::Pik,q.front().second));
                if(q.front().first=="Tref") l.insert(it,std::make_pair(Boje::Tref,q.front().second));
                if(q.front().first=="Herc") l.insert(it,std::make_pair(Boje::Herc,q.front().second));
                if(q.front().first=="Karo") l.insert(it,std::make_pair(Boje::Karo,q.front().second));

            }
            q.pop();

            break;
        }
        i++;
    }
}
int main ()
{
    try {
        std::vector<std::string> v {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        std::list<std::pair<Boje, std::string>> spil = KreirajSpil();
        int korak_razbrajanja, broj_karata;
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak_razbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> broj_karata;

        std::queue<std::pair<std::string,std::string>> q = IzbaciKarteRazbrajanjem(spil, korak_razbrajanja, broj_karata);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
        std::cout<<"Pik: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Pik) {
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) {
                        std::cout<<v.at(i)<<" ";
                        break;
                    }
                }
            }
        }

        std::cout<<std::endl<<"Tref: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Tref)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }
        std::cout<<std::endl<<"Herc: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Herc)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }
        std::cout<<std::endl<<"Karo: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Karo)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }


        int vrati;
        std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> vrati;

        VratiPrvihHKarata(spil,q,vrati);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
        std::cout<<"Pik: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Pik) {
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) {
                        std::cout<<v.at(i)<<" ";
                        break;
                    }
                }
            }
        }

        std::cout<<std::endl<<"Tref: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Tref)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }
        std::cout<<std::endl<<"Herc: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Herc)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }
        std::cout<<std::endl<<"Karo: ";
        for (auto it = spil.begin(); it != spil.end(); it++) {

            if(it->first==Boje::Karo)
                for(int i=0 ; i<v.size() ; i++) {
                    if(it->second==v.at(i)) std::cout<<v.at(i)<<" ";
                }
        }
    } catch (std::logic_error greska1) {
        std::cout << "Izuzetak: " << greska1.what();
    } catch (std::range_error greska2) {
        std::cout << "Izuzetak: " << greska2.what();
    }


    return 0;
}
