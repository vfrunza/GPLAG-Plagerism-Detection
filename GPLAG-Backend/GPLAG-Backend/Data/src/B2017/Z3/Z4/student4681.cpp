/B2017/2018: Zadaća 3, Zadatak 4
#include "iostream"
#include "list"
#include "utility"
#include "map"
#include "stdexcept"
#include "vector"
#include "string"
#include "queue"

enum class Boje { Pik, Tref, Herc, Karo };
const std::vector<std::string> karte{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil;
    for(int color = (int)Boje::Pik; color != (int)Boje::Karo + 1; color++)
        for(int i = 0; i < karte.size(); i++) 
            spil.push_back(std::make_pair((Boje)color, karte.at(i)));
    return spil;
}

bool vectorFind(std::string first, std::string second) {
    int pF, pS;
    bool found(false);
    for(int i = 0; i < karte.size(); i++) 
        if(first == karte.at(i)) { pF = i; found = true; break; }
    for(int i = 0; i < karte.size(); i++) 
        if(second == karte.at(i)) { pS = i; found = true; break; }
    if(!found) return false;
    else {
        if(pF < pS) return true;
        else return false;
    }
}

bool testList(std::list<std::pair<Boje, std::string>> testSpil) {
    if(testSpil.size() > 52) return false;
    for(auto it = testSpil.begin(); it != testSpil.end(); it++) {
        auto end = it;
        ++end;
        if(end == testSpil.end()) break;
        if((int)std::get<0>(*it) == (int)std::get<0>(*end)) {
             if(vectorFind(std::get<1>(*it), std::get<1>(*end))) continue;
             else return false;
        } else if((int)std::get<0>(*it) < (int)std::get<0>(*end)) continue;
        else return false;
    }
    return true;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &target) {
    if(!testList(spil)) throw std::logic_error("Neispravna lista!");
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if(target.find(std::get<0>(*it)) == target.end()) continue;
        else
            for(auto tarit = target.begin(); tarit != target.end(); tarit++)
                if(it->first == tarit->first && it->second == tarit->second) {
                    auto o = it;
                    spil.erase(o);
                    it = spil.begin();
                    target.erase(tarit);
                    break;
                }
    }
}

std::string convertBoje(Boje boje) {
    if(boje == Boje::Pik) return "Pik";
    else if(boje == Boje::Tref) return "Tref";
    else if(boje == Boje::Herc) return "Herc";
    return "Karo";
}

int convertBoje(std::string boje) {
    if(boje == "Pik") return 0;
    else if(boje == "Tref") return 1;
    else if(boje == "Herc") return 2;
    return 3;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &korak, const int &izbaciti) {
    if(korak < 1 || korak > 52 || izbaciti < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!testList(spil)) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> red;
    int izbaceno(0), Tkorak(-1);
    auto it = spil.begin();
    while(izbaceno < izbaciti) {
        Tkorak += korak;
        if(spil.size() == 0) break;
        if(Tkorak >= spil.size()) {
            Tkorak -= spil.size();
            it = spil.begin();
            std::advance(it, Tkorak);
        } else std::advance(it, korak - 1);
        red.push(std::make_pair(convertBoje(it->first), it->second));
        it = spil.erase(it);
        --Tkorak;
        izbaceno++;
    }
    return red;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n) {
    if(n < 0) throw std::logic_error("Broj n je besmislen!");
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    std::queue<std::pair<std::string, std::string>> red2 = red;
    bool tst(false);
    while(!red2.empty()) {
        if(std::get<0>(red2.front()) == "Herc" || std::get<0>(red2.front()) == "Pik" || std::get<0>(red2.front()) == "Tref" || std::get<0>(red2.front()) == "Karo") {
            for(int i = 0; i < karte.size(); i++)
                if(std::get<1>(red2.front()) == karte.at(i)) tst = true;
        }
        else if(tst) throw std::logic_error("Neispravne karte!");
        else throw std::logic_error("Neispravne karte!");
        red2.pop();
    }
    if(!testList(spil)) throw std::logic_error("Neispravna lista!");
    for(int i = 0; i < n; i++) {
        bool ima = false;
        int spilPos(-1), redPos, prev;
        for(auto j = spil.begin(); j != spil.end(); j++)
            if(j->first == (Boje)convertBoje(std::get<0>(red.front()))) {
                ima = true;
                if(j->second == std::get<1>(red.front())) {
                    --i; break;
                }
                for(int k = 0; k < karte.size(); k++)
                    if(j->second == karte.at(k)) {
                        if(spilPos < k) {
                            prev = spilPos;
                            spilPos = k;
                        }
                        break;
                    }
                for(int k = 0; k < karte.size(); k++)
                    if(std::get<1>(red.front()) == karte.at(k)) {
                        redPos = k;
                        break;
                    }
                auto end = j;
                ++end;
                if((prev <= redPos && redPos < spilPos) || (end == spil.end() && prev <= redPos) || end->first != j->first) {
                    if(end == spil.end()) ++j;
                    if(end->first != j->first && !((prev <= redPos && redPos < spilPos) || (end == spil.end() && prev <= redPos))) 
                    j = spil.insert(end, std::make_pair((Boje)convertBoje(std::get<0>(red.front())), std::get<1>(red.front())));
                    else
                    j = spil.insert(j, std::make_pair((Boje)convertBoje(std::get<0>(red.front())), std::get<1>(red.front())));
                    break;
                }
            }
            if(!ima) {
                bool tjt(false);
                int color = int((Boje)convertBoje(std::get<0>(red.front())));
                if(spil.size() == 0) spil.insert(spil.begin(), std::make_pair((Boje)convertBoje(std::get<0>(red.front())), std::get<1>(red.front())));
                else if(spil.size() != 0)
                for(auto it = spil.begin();; it++) {
                    if(it == spil.end()) {
                        --color;
                        if(color < 0) break;
                        it = spil.begin();
                    }
                    auto end = it;
                        ++end;
                        if(it->first == (Boje)color)
                        if(it->first != end->first || end == spil.end()) {
                        spil.insert(end, std::make_pair((Boje)convertBoje(std::get<0>(red.front())), std::get<1>(red.front())));
                        tjt = true;
                        break;
                        }
                }
                else if(color == 0 && !tjt) spil.insert(spil.begin(), std::make_pair((Boje)convertBoje(std::get<0>(red.front())), std::get<1>(red.front())));
            }
        red.pop();
        if(red.empty()) return;
    }
}

void ispisSpil(const std::list<std::pair<Boje, std::string>> &spil) {
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    bool begin(true);
    for(auto it = spil.begin(); it != spil.end(); it++) {
        auto end = it;
        ++end;
        if(end == spil.end()) std::cout << it->second << " ";
        else {
            if(std::get<0>(*it) == std::get<0>(*end) && !begin) std::cout << it->second << " ";
            else if(std::get<0>(*it) != std::get<0>(*end) && !begin || begin) {
                if(!begin) {
                    std::cout << it->second << " ";
                    std::cout << "\n" + convertBoje(std::get<0>(*end)) + ": ";
                } else {
                    std::cout << "\n" + convertBoje(std::get<0>(*it)) + ": ";
                    std::cout << it->second << " ";
                }
                begin = false;
            }
        }
    }
}

int main ()
{
    std::cout << "Unesite korak razbrajanja: ";
    int korakRazbrajanja;
    std::cin >> korakRazbrajanja;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int izbaciti;
    std::cin >> izbaciti;
    std::list<std::pair<Boje, std::string>> spil(KreirajSpil());
    try {
    std::queue<std::pair<std::string, std::string>> red(IzbaciKarteRazbrajanjem(spil, korakRazbrajanja, izbaciti));
    ispisSpil(spil);
    std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
    int vrati;
    std::cin >> vrati;
    VratiPrvihNKarata(spil, red, vrati);
    } catch (std::range_error e) {
        std::cout << "Izuzetak: " <<  e.what();
        return 0;
    } catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
        return 0;
    }
    ispisSpil(spil);
	return 0;
}
