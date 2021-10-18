#include <iostream>
#include <list>
#include <map>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

int Pretvaranje (std::string s)
{
    int y;
    if (s=="2") y=2;
    if (s=="3") y=3;
    if (s=="4") y=4;
    if (s=="5") y=5;
    if (s=="6") y=6;
    if (s=="7") y=7;
    if (s=="8") y=8;
    if (s=="9") y=9;
    if (s=="10") y=10;
    if (s=="J") y=11;
    if (s=="Q") y=12;
    if (s=="K") y=13;
    if (s=="A") y=14;
    return y;
}

bool Ispravan (std::list<std::pair<Boje,std::string>> spil)
{
    std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto it(spil.begin());
    while (it!=spil.end()) {
        for (int i=0; i<karte.size(); i++) {
            if ((*it).second==karte.at(i)) {
                it++;
                break;
            }
            if (i==karte.size()-1) return false;
        }
    }
    return true;
}

bool IspravnoSortiran (std::list<std::pair<Boje,std::string>> spil)
{
    auto it(spil.begin());
    it++;
    while (it!=spil.end()) {
        auto pom(spil.begin());
        while (pom!=it) {
            if ((*pom).first<(*it).first) pom++;
            else if ((*pom).first==(*it).first) {
                int x,y;
                x=Pretvaranje((*pom).second);
                y=Pretvaranje((*it).second);
                if (x<y) pom++;
                else if (x>y || x==y) return false;
            } else if ((*pom).first>(*it).first) return false;
        }
        it++;
    }
    return true;
}



std::list<std::pair<Boje,std::string>> KreirajSpil ()
{
    std::list<std::pair<Boje,std::string>> spil(52);
    auto it(spil.begin());
    std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for (int i=0; i<karte.size(); i++) {
        *it++=std::make_pair(Boje::Pik,karte.at(i));
    }
    for (int i=0; i<karte.size(); i++) {
        *it++=std::make_pair(Boje::Tref,karte.at(i));
    }
    for (int i=0; i<karte.size(); i++) {
        *it++=std::make_pair(Boje::Herc,karte.at(i));
    }
    for (int i=0; i<karte.size(); i++) {
        *it++=std::make_pair(Boje::Karo,karte.at(i));
    }
    return spil;
}

void IzbaciKarte (std::list<std::pair<Boje,std::string>> &spil,std::multimap<Boje, std::string> &karte)
{
    auto ispravan(Ispravan(spil));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(spil));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    if (spil.size()>52) throw std::logic_error ("Neispravna lista!");
    for (auto it1(spil.begin()); it1!=spil.end(); it1++) {
        for (auto it2(karte.begin()); it2!=karte.end(); it2++) {
            if ((*it1).first==(*it2).first && (*it1).second==(*it2).second) {
                it1=spil.erase(it1);
                it1--;
                it2=karte.erase(it2);
            }
            break;
        }
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje,std::string>> &spil,const short int &korak,const int &broj)
{
    std::queue<std::pair<std::string,std::string>> izbacene;
    if (korak<1 || korak>52 || broj<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    auto ispravan(Ispravan(spil));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(spil));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    if (spil.size()>52) throw std::logic_error ("Neispravna lista!");
    int i(1);
    int brojac(0);
    while (brojac!=broj) {
        auto it(spil.begin());
        while (it!=spil.end()) {
            if (i==korak) {
                if ((*it).first==Boje::Pik) izbacene.push({"Pik",(*it).second});
                else if ((*it).first==Boje::Tref) izbacene.push({"Tref",(*it).second});
                else if ((*it).first==Boje::Herc) izbacene.push({"Herc",(*it).second});
                else if ((*it).first==Boje::Karo) izbacene.push({"Karo",(*it).second});
                it=spil.erase(it);
                it--;
                i=0;
                brojac++;
            }
            it++;
            i++;
            if (brojac==broj) break;
        }
    }
    return izbacene;
}

void VratiPrvihNKarata (std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &bacene,int n)
{
    if (n!=int(n) || n<0) throw std::domain_error ("Broj n je besmislen!");
    if (n>bacene.size()) throw std::range_error ("Nedovoljno karata u redu!");
    auto ispravan(Ispravan(spil));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(spil));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    if (spil.size()>52) throw std::logic_error ("Neispravna lista!");
    int brojac(0);
    while (brojac!=n) {
        auto it(spil.begin());
        while (spil.size()==0 || it!=spil.end()) {
            int x,y;
            if (spil.size()==0) {
                if (bacene.front().first=="Pik") spil.insert(it,std::make_pair(Boje::Pik,bacene.front().second));
                if (bacene.front().first=="Tref") spil.insert(it,std::make_pair(Boje::Tref,bacene.front().second));
                if (bacene.front().first=="Herc") spil.insert(it,std::make_pair(Boje::Herc,bacene.front().second));
                if (bacene.front().first=="Karo") spil.insert(it,std::make_pair(Boje::Karo,bacene.front().second));
                brojac++;
                bacene.pop();
                break;
            }
            y=Pretvaranje(bacene.front().second);
            x=Pretvaranje((*it).second);
            if (bacene.front().first=="Pik") {
                while ((*it).first==Boje::Pik && x<=y) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                spil.insert(it,std::make_pair(Boje::Pik,bacene.front().second));
            } else if (bacene.front().first=="Tref") {
                while ((*it).first==Boje::Pik) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Tref && x<=y) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                spil.insert(it,std::make_pair(Boje::Tref,bacene.front().second));
            } else if (bacene.front().first=="Herc") {
                while ((*it).first==Boje::Pik) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Tref) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Herc && x<=y) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                spil.insert(it,std::make_pair(Boje::Herc,bacene.front().second));
            } else if (bacene.front().first=="Karo") {
                while ((*it).first==Boje::Pik) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Tref) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Herc) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                while ((*it).first==Boje::Karo && x<=y) {
                    it++;
                    x=Pretvaranje((*it).second);
                }
                spil.insert(it,std::make_pair(Boje::Karo,bacene.front().second));
            }
            bacene.pop();
            brojac++;
            break;
        }
    }
}






int main ()
{
    try {
        std::list<std::pair<Boje,std::string>> spil;
        spil=KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        auto izbacene(IzbaciKarteRazbrajanjem(spil,r,b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        auto it(spil.begin());
        std::cout<<"Pik: ";
        while ((*it).first==Boje::Pik) {
            std::cout<<(*it).second<<" ";
            it++;
        }
        std::cout<<std::endl<<"Tref: ";
        while ((*it).first==Boje::Tref) {
            std::cout<<(*it).second<<" ";
            it++;
        }
        std::cout<<std::endl<<"Herc: ";
        while ((*it).first==Boje::Herc) {
            std::cout<<(*it).second<<" ";
            it++;
        }
        std::cout<<std::endl<<"Karo: ";
        while ((*it).first==Boje::Karo) {
            std::cout<<(*it).second<<" ";
            it++;
        }
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,izbacene,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        auto iter(spil.begin());
        std::cout<<"Pik: ";
        while ((*iter).first==Boje::Pik) {
            std::cout<<(*iter).second<<" ";
            iter++;
        }
        std::cout<<std::endl<<"Tref: ";
        while ((*iter).first==Boje::Tref) {
            std::cout<<(*iter).second<<" ";
            iter++;
        }
        std::cout<<std::endl<<"Herc: ";
        while ((*iter).first==Boje::Herc) {
            std::cout<<(*iter).second<<" ";
            iter++;
        }
        std::cout<<std::endl<<"Karo: ";
        while ((*iter).first==Boje::Karo) {
            std::cout<<(*iter).second<<" ";
            iter++;
        }
    } catch (std::domain_error l) {
        std::cout<<"Izuzetak: "<<l.what();
    } catch (std::logic_error r) {
        std::cout<<"Izuzetak: "<<r.what();
    } catch (std::range_error d) {
        std::cout<<"Izuzetak: "<<d.what();
    }
    return 0;
}
