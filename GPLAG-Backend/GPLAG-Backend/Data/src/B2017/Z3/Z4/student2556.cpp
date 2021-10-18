/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <map>
#include <stdexcept>
#include <queue>
#include <cstring>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> spil;

    for(int i=1; i<=4; i++) {
        std::pair<Boje, std::string> karta;
        std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        for(int j=1; j<=13; j++) {
            karta.first = Boje(i-1);
            karta.second = znak.at(j-1);
            spil.insert(spil.end(), karta);
        }
    }

    return spil;
}
void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &multimapa)
{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it != spil.end(); it++) {
        std::multimap<Boje, std::string>::iterator it_p(multimapa.find(it->first));
        auto it_m(multimapa.begin());
        // for(auto it_m=multimapa.begin(); it_m!=multimapa.end(); it_m++) {
        while(it_m!=multimapa.end()) {
            // std::cout<<it->second<<"*";
            auto a(std::get<0>(*it_m));
            auto b(std::get<1>(*it_m));
            //  if(it->second != 'J' && it->second != 'K' && it->second != 'Q' && it->second != 'A' && it->second < 2 && it->second > 10) throw;
            if(it_p != multimapa.end()) {
                if(it->first == a && it->second == b) {
                    it=spil.erase(it);
                    it_m=multimapa.erase(it_m);
                }
            }
            if(it_m!=multimapa.end()) it_m++;
        }
    }
}

bool JeLiIspravna(std::list<std::pair<Boje, std::string>> &spil)
{
    std::list<std::pair<Boje, std::string>>::iterator it(spil.begin()), it2(spil.begin());
    it2++;
    while(it->first == Boje(0)) {
        if(it2->second < it->second) {
            if(it->second[0]!='A') break;
            return false;
        }
        it++;
        it2++;
    }
    while(it->first == Boje(1)) {
        if(it2->second < it->second) {
            if(it->second[0]!='A') break;
            return false;
        }
        it++;
        it2++;
    }
    while(it->first == Boje(2)) {
        if(it2->second < it->second) {
            if(it->second[0]!='A') break;
            return false;
        }
        it++;
        it2++;
    }
    while(it->first == Boje(3) && it!=spil.end() && it2!=spil.end()) {
        if(it2->second < it->second) {
            if(it->second[0]!='A') break;
            return false;
        }
        it++;
        it2++;
    }

    std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    bool pamti(true);
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        for(int i=0; i<znak.size(); i++) {
            if(it->second == znak[i] && (it->first == Boje(0) || it->first == Boje(1) || it->first == Boje(2) || it->first == Boje(3)))
                pamti=true;
            else {
                pamti=false;
                break;
            }
        }
        if(pamti=false) return false;
    }

    return true;
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int r, const int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    std::multimap<Boje, std::string> multimapa;
    std::list<std::pair<Boje, std::string>>::iterator it(spil.begin());
    std::queue<std::pair<Boje, std::string>> red;
    int j(0);
    std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(auto it_p(spil.begin()); it_p!=spil.end(); it_p++) {
        if(j>52) throw std::logic_error("Neispravna lista!");
        j++;
    }
    if(!JeLiIspravna(spil)) throw std::logic_error("Neispravna lista!");

    int i(1), obrisani(0);
    while(obrisani!=b || obrisani==52) {

        bool prekini(false);

        for(auto it_m=multimapa.begin(); it_m!=multimapa.end(); it_m++) {
            auto deref(*it);
            if(deref.first == it_m->first && deref.second == it_m->second) {
                it++;
                prekini=true;
                break;
            }
        }

        if(i%r==0) {
            if(prekini) continue;
            multimapa.insert(*it);
            red.push(*it);
            obrisani++;
            if(obrisani==b || obrisani==52) break;
        }
        i++;
        it++;
        if(it==spil.end()) it = spil.begin();
        if(obrisani==52) break;
    }
    IzbaciKarte(spil, multimapa);
    return red;
}

bool JeLiDrugiVeci(char a, char b)
{
    return a<b;
}
void IspisiSpil(std::list<std::pair<Boje, std::string>> &spil)
{
    std::list<std::pair<Boje, std::string>>::iterator it(spil.begin());
    for(int i=1; i<=4; i++) {
        if(i==1) std::cout<<"Pik: ";
        else if(i==2) std::cout<<"Tref: ";
        else if(i==3) std::cout<<"Herc: ";
        else if(i==4) std::cout<<"Karo: ";
        while(it->first == Boje(i-1)) {
            std::cout<<it->second<<" ";
            it++;
        }
        std::cout<<std::endl;
    }
}

bool JeLi(std::string a, std::string b)
{
    std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int i, j;
    for(i=0; i<znak.size(); i++) {
        if(znak[i]==b) break;
    }
    for(j=0; j<znak.size(); j++) {
        if(znak[j]==a) break;
    }
    return j>i;
}


void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<Boje, std::string>> &red, int n)
{
    if(n>red.size() && n>0) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
//    if() throw std::logic_error("Neispravne karte!");
    int i(0);
    std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(auto it_p(spil.begin()); it_p!=spil.end(); it_p++) {
        if(i>52) throw std::logic_error("Neispravna lista!");
        i++;
    }
    if(!JeLiIspravna(spil)) throw std::logic_error("Neispravna lista!");

    for(int i=0; i<n; i++) {
        std::list<std::pair<Boje, std::string>>::iterator it(spil.begin());
        while(red.front().first > it->first) it++;
        spil.insert(it, red.front());
        red.pop();
    }

    std::list<std::pair<Boje, std::string>>::iterator it_2(spil.begin());

    while(it_2->first==Boje(0)) {
        std::list<std::pair<Boje, std::string>>::iterator it_3(it_2);
        while(it_3->first==Boje(0)) {
            if(JeLi(it_2->second, it_3->second)) {
                auto temp(*it_2);
                *it_2=*it_3;
                *it_3=temp;
            }
            it_3++;
        }
        it_2++;
    }

    while(it_2->first==Boje(1)) {
        std::list<std::pair<Boje, std::string>>::iterator it_3(it_2);
        while(it_3->first==Boje(1)) {
            if(JeLi(it_2->second, it_3->second)) {
                auto temp(*it_2);
                *it_2=*it_3;
                *it_3=temp;
            }
            it_3++;
        }
        it_2++;
    }

    while(it_2->first==Boje(2)) {
        std::list<std::pair<Boje, std::string>>::iterator it_3(it_2);
        while(it_3->first==Boje(2)) {
            if(JeLi(it_2->second, it_3->second)) {
                auto temp(*it_2);
                *it_2=*it_3;
                *it_3=temp;
            }
            it_3++;
        }
        it_2++;
    }

    while(it_2->first==Boje(3)) {
        std::list<std::pair<Boje, std::string>>::iterator it_3(it_2);
        while(it_3->first==Boje(3)) {
            if(JeLi(it_2->second, it_3->second)) {
                auto temp(*it_2);
                *it_2=*it_3;
                *it_3=temp;
            }
            it_3++;
        }
        it_2++;
    }

}



int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    int r;
    std::cin>>r;

    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;

    try {
        std::list<std::pair<Boje, std::string>> spil(KreirajSpil());
        std::queue<std::pair<Boje, std::string>> razabrani;
        razabrani = IzbaciKarteRazbrajanjem(spil, r, b);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;

        // IspisiSpil(spil);
        IspisiSpil(spil);

        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int v;
        std::cin>>v;
        VratiPrvihNKarata(spil, razabrani, v);

        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;

        IspisiSpil(spil);

    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::domain_error izuzetak2) {
        std::cout<<"Izuzetak: "<<izuzetak2.what();
    } catch(std::range_error izuzetak3) {
        std::cout<<"Izuzetak: "<<izuzetak3.what();
    } catch(...) {

    }

    return 0;
}
