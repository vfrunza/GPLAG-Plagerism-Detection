/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> karte = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

int PronadjiPoziciju (std::pair<Boje, std::string> karta) {
    for (int i = 0 ; i < karte.size() ; i++)
        if (karta.second == karte.at(i))
            return i;
        return - 1;
}

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil;
    for (int i = 0 ; i < 13 ; i++)
        spil.push_back({Boje::Pik, karte.at(i)});
    for (int i = 0 ; i < 13 ; i++)
        spil.push_back({Boje::Tref, karte.at(i)});
    for (int i = 0 ; i < 13 ; i++)
        spil.push_back({Boje::Herc, karte.at(i)});
    for (int i = 0 ; i < 13 ; i++)
        spil.push_back({Boje::Karo, karte.at(i)});
    
    return spil;
}

void IspitajKorektnostListe (std::list<std::pair<Boje, std::string>> &spil) {
    if (spil.size() > 52)
        throw std::logic_error ("Neispravna lista!");
    for (std::list<std::pair<Boje, std::string>>::iterator it = spil.begin() ; it != spil.end() ; it++) {
        bool besmislen = true;
        for (int i = 0 ; i < karte.size() ; i++)
            if (it->second == karte.at(i))
                besmislen = false;
        for (std::list<std::pair<Boje, std::string>>::iterator itj = spil.begin() ; itj != it ; itj++)
            if (itj->first == it->first && itj->second == it->second) {
                besmislen = true;
                break;
            }
            
        if (besmislen == true)
            throw std::logic_error ("Neispravna lista!");
            
        if (it != spil.begin()) {
            std::pair<Boje, std::string> drugi = *it;
            it--;
            std::pair<Boje, std::string> prvi = *it;
            it++;
            if (prvi.first == drugi.first) {
                int pozPrvog = PronadjiPoziciju(prvi), pozDrugog = PronadjiPoziciju(drugi);
                if (pozPrvog > pozDrugog)
                    throw std::logic_error ("Neispravna lista!");
            }
        }
        
    }
}
    
    void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &izbaci) {
        IspitajKorektnostListe(spil);
        for (std::multimap<Boje, std::string>::iterator iti = izbaci.begin() ; iti != izbaci.end() ; iti++) {
            bool postoji = false;
            for (/*std::list<std::pair<Boje, std::string>::iterator*/auto itj = spil.begin() ; itj != spil.end() ; itj++)
                if (iti->first == itj->first && iti->second == itj->second) {
                    postoji = true;
                    spil.remove({iti->first, iti->second});
                    break;
                }
            if (postoji == true)
                iti = izbaci.erase(iti);
            else
                iti++;
        }
        return;
    }


std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, const short int r, const int b) {
    if (r < 1 || r > 52 || b < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    IspitajKorektnostListe(spil);
    std::queue<std::pair<std::string, std::string>> izbaceneKarte;
    int pozicija = 0;
    std::list<std::pair<Boje, std::string>>::iterator it = spil.begin();
    while (izbaceneKarte.size() != b && spil.size() != 0) {
        int brojac = 1;
        while (brojac < r) {
            it++;
            brojac++;
            if (it == spil.end())
                it = spil.begin();
        }
        std::string boja;
        switch (int(it->first)) {
            case 0:
                boja = "Pik";
                break;
            case 1:
                boja = "Tref";
                break;
            case 2:
                boja = "Herc";
                break;
            case 3:
                boja = "Karo";
                break;
        }
        izbaceneKarte.push({boja, it->second});
        it = spil.erase(it);
    }
    return izbaceneKarte;
}

void VratiPrvihNKarata (std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &vratiti, int n) {
    if (n < 0)
        throw std::domain_error ("Broj n je besmislen!");
    else if (n > vratiti.size())
        throw std::range_error ("Nedovoljno karata u redu!");
        
    for (int i = 0 ; i < vratiti.size() ; i++) {
        std::pair<std::string, std::string> karta = vratiti.front();
        vratiti.pop();
        bool korektna = false;
        for (int j = 0 ; j < karte.size() ; j++)
            if (karta.second == karte.at(j)) {
                korektna = true;
                break;
            }
        if (!korektna || (karta.first != "Pik" && karta.first != "Tref" && karta.first != "Herc" && karta.first != "Karo"))
            throw std::logic_error ("Neispravne karte!");
        vratiti.push(karta);
    }
    
    IspitajKorektnostListe(spil);
    
    for (int i = 0 ; i < n ; i++) {
        std::pair<std::string, std::string> temp = vratiti.front();
        vratiti.pop();
        Boje boja;
        if (temp.first == "Pik")
            boja = Boje::Pik;
        else if (temp.first == "Tref")
            boja = Boje::Tref;
        else if (temp.first == "Herc")
            boja = Boje::Herc;
        else if (temp.first == "Karo")
            boja = Boje::Karo;
            
        std::pair<Boje, std::string> karta = {boja, temp.second};
        int pozicijaKarte = PronadjiPoziciju(karta);
        std::list<std::pair<Boje, std::string>>::iterator it = spil.begin();
        it++;
        for (it; it != spil.end() ; it++) {
            if (pozicijaKarte == 0 && karta.first == Boje::Pik)
                spil.push_front(karta);
            else if (pozicijaKarte == 0 && it->first == karta.first)
                spil.insert(it, karta);
            else if (pozicijaKarte == 12 && karta.first == Boje::Karo)
                spil.push_back(karta);
            else if (pozicijaKarte == 12 && int(it->first) == int(karta.first) + 1)
                spil.insert(it, karta);
            else if (it->first == karta.first) {
                int pozTrenutne = PronadjiPoziciju(*it);
                it--;
                int pozPrethodne = PronadjiPoziciju(*it);
                it++;
                if (pozicijaKarte > pozPrethodne && pozicijaKarte < pozTrenutne)
                    spil.insert(it, karta);
            }
                
        }
    }
}

void IspisiSpil (std::list<std::pair<Boje, std::string>> &spil) {
    std::list<std::pair<Boje, std::string>>::iterator it = spil.begin();
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
    if (it != spil.end() && it->first == Boje::Pik) {
        std::cout << "Pik: ";
        while (it != spil.end() && it->first == Boje::Pik) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
    }
    if (it != spil.end() && it->first == Boje::Tref) {
        std::cout << "Tref: ";
        while (it != spil.end() && it->first == Boje::Tref) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
    }
    if (it != spil.end() && it->first == Boje::Herc) {
        std::cout << "Herc: ";
        while (it != spil.end() && it->first == Boje::Herc) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
    }
    if (it != spil.end() && it->first == Boje::Karo) {
        std::cout << "Karo: ";
        while (it != spil.end() && it->first == Boje::Karo) {
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
    }
    
}

int main ()
{
    try{
        std::cout << "Unesite korak razbrajanja: ";
        int korak;
        std::cin >> korak;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int n;
        std::cin >> n;
        
        std::list<std::pair<Boje, std::string>> spil(KreirajSpil());
        std::queue<std::pair<std::string, std::string>> izbacene(IzbaciKarteRazbrajanjem(spil, korak, n));
        IspisiSpil(spil);
        
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int vracanje;
        std::cin >> vracanje;
        VratiPrvihNKarata(spil, izbacene, vracanje);
        IspisiSpil(spil);
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    catch(std::domain_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    catch(std::range_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
	return 0;
}
