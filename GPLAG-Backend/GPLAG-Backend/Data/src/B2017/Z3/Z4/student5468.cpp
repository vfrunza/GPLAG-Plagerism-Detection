/B2017/2018: Zadaća 3, Zadatak 4
/*#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> MultiMapa;
typedef std::queue<std::pair<std::string, std::string>> Stek;

Spil::iterator PostaviBoju(Boje boja, Spil::iterator it)
{
    for(int i=2; i<=10; i++) {
        it->first=boja;
        if(i!=10) {
            it->second=i+'0';
        } else it->second="10";
        it++;
    }
    for(int i=0; i<4; i++) {
        it->first=boja;
        if(i==0)
            it->second="J";
        else if(i==1)
            it->second="Q";
        else if(i==2)
            it->second="K";
        else if(i==3)
            it->second="A";
        it++;
    }
    return it;
}

bool NeispravanSpil(Spil s)
{
    auto sljedeci(s.begin());
    auto prethodni(s.begin());
    prethodni--;
    sljedeci++;
    for(auto it=s.begin(); it!=s.end(); it++) {
        if(sljedeci!=s.end() && it->first>sljedeci->first) {
            return true;
        } else {
            if(sljedeci!=s.end() &&  it->first==sljedeci->first) {
                if(it->second=="10") {
                    if(sljedeci->second!="J" && sljedeci->second!="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                        return true;
                    }
                } else if(it->second=="J" && sljedeci->second!="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second=="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second=="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second>="2" && it->second<="9" && sljedeci->second>="2"
                          && sljedeci->second<="9" && it->second>sljedeci->second) {
                    return true;
                }
            }
            if(it!=s.begin() && prethodni->first==it->first) {
                if(it->second=="10") {
                    if(!(prethodni->second>="2" && prethodni->second<="9")) {
                        return true;
                    }
                } else if(it->second=="J" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10") {
                    return true;
                } else if(it->second=="Q" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J") {
                    return true;
                } else if(it->second=="K" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J" && prethodni->second!="Q") {
                    return true;
                } else if(it->second=="A" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J" && prethodni->second!="Q" && prethodni->second!="K") {
                    return true;
                } else if(it->second>="2" && it->second<="9" && prethodni->second>="2" && prethodni->second<="9"
                          && it->second<prethodni->second) {
                    return true;
                }
            }
        }
        sljedeci++;
        prethodni++;
    }
    return false;
}

Spil KreirajSpil()
{
    Spil s(52);
    auto it(s.begin());
    it=PostaviBoju(Boje::Pik, it);
    it=PostaviBoju(Boje::Tref, it);
    it=PostaviBoju(Boje::Herc, it);
    it=PostaviBoju(Boje::Karo, it);

    return s;
}

void IzbaciKarte(Spil &s, MultiMapa &mm)
{
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    int br(0);
    auto itm(mm.begin());
    for(int i=0; i<mm.size(); i++) {
        for(auto its=s.begin(); its!=s.end(); its++) {
            if(its->first==itm->first && its->second==itm->second) {
                s.erase(its);
                itm=mm.erase(itm);
                br=1;
                break;
            }
        }
        if(br==0)
            itm++;
        br=0;
    }
}

Stek IzbaciKarteRazbrajanjem(Spil &s, short int r, int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    Stek final;
    int brr(0), brb(0);
    for(auto it=s.begin(); it!=s.end(); it++) {
        while(brr!=r) {
            if(it==s.end())
                it=s.begin();
            brr++;
            it++;
        }
        it--;
        std::pair<std::string, std::string> p;
        p.second=it->second;
        if(Boje::Pik==it->first)
            p.first="Pik";
        else if(Boje::Tref==it->first)
            p.first="Tref";
        else if(Boje::Herc==it->first)
            p.first="Herc";
        else if(Boje::Karo==it->first)
            p.first="Karo";
        final.push(p);
        it=s.erase(it);
        it--;
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
        auto p1(red.front());
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

void VratiPrvihNKarata(Spil &s, Stek &red, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    if(NeispravanRed(red))
        throw std::logic_error("Neispravne karte!");
    for(int i=0; i<n; i++) {
        auto p(red.front());
        auto p1(PretvoriUListu(p));
        auto it(s.begin());
        int br(0);
        for(it=s.begin(); it!=s.end(); it++) {
            auto pok(it);
            if(it!=s.begin()) pok--;
            if(pok->first!=p1.first) pok++;
            
            if(p1.second=="A" && it->first>p1.first) {
                if(pok->second!="A") {
                    br=0;
                    break;
                } 
            } else if(p1.second=="K") {
                if((it->first==p1.first && it->second=="A" && pok->second!="K") 
                  || (it->first>p1.first && pok->second!="K")) {
                    br=0;
                    break;
                }
            } else if(p1.second=="J") {
                if(((it->first==p1.first && (it->second>p1.second || it->second=="A"))  
                   || it->first>p1.first) && pok->second!="J") {
                    br=0;
                    break;
                }
            } else if(p1.second=="Q") {
                if(((it->first==p1.first && (it->second=="A" || it->second=="K")) || it->first>p1.first) && pok->second!="Q") {
                    br=0;
                    break;
                }
            } else if(p1.second=="10") {
                if(((it->first==p1.first && (it->second=="J" || it->second=="Q" || it->second=="K" || it->second=="A"))
                        || it->first>p1.first) && pok->second!="10") {
                    br=0;
                    break;
                }
            } else if(it->first==p1.first && p1.second>="0" && p1.second<="9"){ 
                if((it->second>p1.second || it->second=="10") && pok->second!=p1.second) {
                br=0;
                break;
                }
            } else if(it->first==p1.first && it->second==p1.second) {
                    br=1;
                    break;
              }
             else{
                auto pok1(it);
                if(pok1++==s.end()) {
                    it=s.begin();
                    br=0;
                    break;
                }
             }
             br=1;
        }
        if(br==0)
            s.insert(it, p1);
        red.pop();
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
        std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        auto it(s.begin());
        while(Boje::Pik==it->first) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << "\nTref: ";
        while(Boje::Tref==it->first) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << "\nHerc: ";
        for(int i=0; i<13; i++) {
            if(Boje::Herc==it->first)
                std::cout << it->second << " ";
            else break;
            it++;
        }
        std::cout << std::endl << "Karo: ";
        for(int i=0; i<13; i++) {
            if(Boje::Karo==it->first)
                std::cout << it->second << " ";
            else break;
            it++;
        }
        std::cout << std::endl;
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPrvihNKarata(s, s1, n);
        std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        it=s.begin();
        for(it=s.begin(); it!=s.end(); it++) {
            if(Boje::Pik==it->first)
                std::cout << it->second << " ";
            else break;
        }
        std::cout << std::endl << "Tref: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Tref==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl << "Herc: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Herc==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl << "Karo: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Karo==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl;
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }

    return 0;
}*/

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> MultiMapa;
typedef std::queue<std::pair<std::string, std::string>> Stek;

Spil::iterator PostaviBoju(Boje boja, Spil::iterator it)
{
    for(int i=2; i<=10; i++) {
        it->first=boja;
        if(i!=10) {
            it->second=i+'0';
        } else it->second="10";
        it++;
    }
    for(int i=0; i<4; i++) {
        it->first=boja;
        if(i==0)
            it->second="J";
        else if(i==1)
            it->second="Q";
        else if(i==2)
            it->second="K";
        else if(i==3)
            it->second="A";
        it++;
    }
    return it;
}

bool NeispravanSpil(Spil s)
{
    auto sljedeci(s.begin());
    auto prethodni(s.begin());
    prethodni--;
    sljedeci++;
    for(auto it=s.begin(); it!=s.end(); it++) {
        if(sljedeci!=s.end() && it->first>sljedeci->first) {
            return true;
        } else {
            if(sljedeci!=s.end() &&  it->first==sljedeci->first) {
                if(it->second=="10") {
                    if(sljedeci->second!="J" && sljedeci->second!="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                        return true;
                    }
                } else if(it->second=="J" && sljedeci->second!="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second=="Q" && sljedeci->second!="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second=="K" && sljedeci->second!="A") {
                    return true;
                } else if(it->second>="2" && it->second<="9" && sljedeci->second>="2"
                          && sljedeci->second<="9" && it->second>sljedeci->second) {
                    return true;
                }
            }
            if(it!=s.begin() && prethodni->first==it->first) {
                if(it->second=="10") {
                    if(!(prethodni->second>="2" && prethodni->second<="9")) {
                        return true;
                    }
                } else if(it->second=="J" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10") {
                    return true;
                } else if(it->second=="Q" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J") {
                    return true;
                } else if(it->second=="K" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J" && prethodni->second!="Q") {
                    return true;
                } else if(it->second=="A" && !(prethodni->second>="2" && prethodni->second<="9") && prethodni->second!="10"
                          && prethodni->second!="J" && prethodni->second!="Q" && prethodni->second!="K") {
                    return true;
                } else if(it->second>="2" && it->second<="9" && prethodni->second>="2" && prethodni->second<="9"
                          && it->second<prethodni->second) {
                    return true;
                }
            }
        }
        sljedeci++;
        prethodni++;
    }
    return false;
}

Spil KreirajSpil()
{
    Spil s(52);
    auto it(s.begin());
    it=PostaviBoju(Boje::Pik, it);
    it=PostaviBoju(Boje::Tref, it);
    it=PostaviBoju(Boje::Herc, it);
    it=PostaviBoju(Boje::Karo, it);

    return s;
}

void IzbaciKarte(Spil &s, MultiMapa &mm)
{
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    int br(0);
    auto itm(mm.begin());
    for(int i=0; i<mm.size(); i++) {
        for(auto its=s.begin(); its!=s.end(); its++) {
            if(its->first==itm->first && its->second==itm->second) {
                s.erase(its);
                itm=mm.erase(itm);
                br=1;
                break;
            }
        }
        if(br==0)
            itm++;
        br=0;
    }
}

Stek IzbaciKarteRazbrajanjem(Spil &s, short int r, int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    Stek final;
    int brr(0), brb(0);
    for(auto it=s.begin(); it!=s.end(); it++) {
        while(brr!=r) {
            if(it==s.end())
                it=s.begin();
            brr++;
            it++;
        }
        it--;
        std::pair<std::string, std::string> p;
        p.second=it->second;
        if(Boje::Pik==it->first)
            p.first="Pik";
        else if(Boje::Tref==it->first)
            p.first="Tref";
        else if(Boje::Herc==it->first)
            p.first="Herc";
        else if(Boje::Karo==it->first)
            p.first="Karo";
        final.push(p);
        it=s.erase(it);
        it--;
        brr=0;
        brb++;
        if(brb==b)
            return final;
        it++;
        if(it==s.end()){ it=s.begin(); it--;}
        else it--;
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
        auto p1(red.front());
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

void VratiPrvihNKarata(Spil &s, Stek &red,const int &n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(s.size()>52 || NeispravanSpil(s))
        throw std::logic_error("Neispravna lista!");
    if(NeispravanRed(red))
        throw std::logic_error("Neispravne karte!");
    for(int i=0; i<n; i++) {
        auto p(red.front());
        auto p1(PretvoriUListu(p));
        auto it(s.begin());
        int br(0);
        for(it=s.begin(); it!=s.end(); it++) {
            auto pok(it);
            if(it!=s.begin()) pok--;
            if(pok->first!=p1.first) pok++;
            
            if(p1.second=="A" && it->first>p1.first) {
                if(pok->second!="A") {
                    br=0;
                    break;
                } 
            } else if(p1.second=="K") {
                if((it->first==p1.first && it->second=="A" && pok->second!="K") 
                  || (it->first>p1.first && pok->second!="K")) {
                    br=0;
                    break;
                }
            } else if(p1.second=="J") {
                if(((it->first==p1.first && (it->second>p1.second || it->second=="A"))  
                   || it->first>p1.first) && pok->second!="J") {
                    br=0;
                    break;
                }
            } else if(p1.second=="Q") {
                if(((it->first==p1.first && (it->second=="A" || it->second=="K")) || it->first>p1.first) && pok->second!="Q") {
                    br=0;
                    break;
                }
            } else if(p1.second=="10") {
                if(((it->first==p1.first && (it->second=="J" || it->second=="Q" || it->second=="K" || it->second=="A"))
                        || it->first>p1.first) && pok->second!="10") {
                    br=0;
                    break;
                }
            } else if(it->first==p1.first && p1.second>="0" && p1.second<="9"){ 
                if((it->second>p1.second || it->second=="10") && pok->second!=p1.second) {
                br=0;
                break;
                }
            } else if(it->first==p1.first && it->second==p1.second) {
                    br=1;
                    break;
              }
             else{
                auto pok1(it);
                if(pok1++==s.end()) {
                    it=s.begin();
                    br=0;
                    break;
                }
             }
             br=1;
        }
        if(br==0)
            s.insert(it, p1);
        red.pop();
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
        std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        auto it(s.begin());
        while(Boje::Pik==it->first) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << "\nTref: ";
        while(Boje::Tref==it->first) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << "\nHerc: ";
        for(int i=0; i<13; i++) {
            if(Boje::Herc==it->first)
                std::cout << it->second << " ";
            else break;
            it++;
        }
        std::cout << std::endl << "Karo: ";
        for(int i=0; i<13; i++) {
            if(Boje::Karo==it->first)
                std::cout << it->second << " ";
            else break;
            it++;
        }
        std::cout << std::endl;
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPrvihNKarata(s, s1, n);
        std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
        std::cout << "Pik: ";
        it=s.begin();
        for(it=s.begin(); it!=s.end(); it++) {
            if(Boje::Pik==it->first)
                std::cout << it->second << " ";
            else break;
        }
        std::cout << std::endl << "Tref: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Tref==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl << "Herc: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Herc==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl << "Karo: ";
        for(auto it1=it; it1!=s.end(); it1++) {
            if(Boje::Karo==it1->first)
                std::cout << it1->second << " ";
            else {
                it=it1;
                break;
            }
        }
        std::cout << std::endl;
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }

    return 0;
}

