/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil(){
    std::list<std::pair<Boje, std::string>> noviSpil;
    
    Boje bojeKarata[4]= {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    
    for (auto i : bojeKarata) {
        noviSpil.push_back(std::pair<Boje, std::string>(i, "2"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "3"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "4"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "5"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "6"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "7"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "8"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "9"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "10"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "J"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "Q"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "K"));
        noviSpil.push_back(std::pair<Boje, std::string>(i, "A"));
    }
    
    return noviSpil;
    
}

bool validirajSpil(std::list<std::pair<Boje, std::string>> &spil){
    std::string elementi[]={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    //Validacija za smece
    for (auto i : spil) { //Pregledaj citav spil
        bool tacanSimbol(false); //Pretpostavi da ima smece
        for (auto j : elementi) { // Pogledaj moguce kombinacije
            if (i.second == j){ // Ako je simbol ok
                tacanSimbol = true; // tacanSImbol je true
                break; // Izlazi
            }
        }
        if (!tacanSimbol) // Ako nije nijedan od legalnih simbola
            return false;
    }
    
    auto standardniSpil(KreirajSpil());
    int temp (-1);
    for (auto i : spil) {
        int novaVrijednost(0);
        for (auto j : standardniSpil) {
            
            if (i == j && novaVrijednost < temp) // Nasli i ne valja
                return false;
            
            else if (i == j && novaVrijednost > temp){ //NAsli smo je i ok je
                temp = novaVrijednost;
                break;
            }
                
            novaVrijednost++;
        }
    }
    
    return true;
}

void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &zaIzbaciti){
    if (spil.size() > 52 && validirajSpil(spil))
        throw std::logic_error("Neispravna lista!");
    
    for (auto kartaZaIzbaciti : zaIzbaciti){
        bool nasliKartu(false);
        
        for (auto karta : spil) {
            if (karta.first == kartaZaIzbaciti.first && karta.second == kartaZaIzbaciti.second){
                nasliKartu = true;
                break;
            }
        }
        
        if (nasliKartu)
            spil.remove(kartaZaIzbaciti);
        kartaZaIzbaciti.second = "P";
    }
    
    for (auto i = zaIzbaciti.begin(); i != zaIzbaciti.end(); i++) {
        if (i->second == "P")
            zaIzbaciti.erase(i);
    }
        
}
std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &mala, const int &velika)
{
    if(mala < 1 or mala > 52 or velika < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!validirajSpil(spil))
        throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> Red;
    int korak = mala;
    auto it = spil.begin();
    for(int j = 0; j < velika; j++)
    {
        if(spil.empty())
            break;
        while(korak > 52)
        {
            korak -= 52;
        }
        while(korak > spil.size())
        {
            korak -= spil.size();
        }
        for(int i = 0; i < korak - 1; i++)
        {
            
            if(it == spil.end())
                it = spil.begin();
            it++;
        }
        if(it == spil.end())
            it == spil.begin();
        string boja;
        if(it -> first == Boje::Pik)
            boja = "Pik";
        else if(it -> first == Boje::Tref)
            boja = "Tref";
        else if(it -> first == Boje::Herc)
            boja = "Herc";
        else if(it -> first == Boje::Karo)
            boja = "Karo";
        if(boja.length() == 0)
            cout << "Nesto ne valja";
        pair<string, string> TajPar = pair<string, string>(boja, it -> second);
        //pair<Boje, string> ZaVratiti = *it;
        Red.push(TajPar);
        it = spil.erase(it);
        //spil.push_back(ZaVratiti);
    }
    return Red;
}
void VratiPrvihNKarata(list<pair<Boje, string>> &spil, queue<pair<string, string>> &Red, int n)
{
    if(n > Red.size())
        throw range_error("Nedovoljno karata u redu!");
    if(n < 1 or n > 52)
        throw domain_error("Broj n je besmislen!");
    /*for(auto par : Red)
    {
        if(par.first != "Pik" and par.first != "Tref" and par.first != "Herc" and par.first != "Karo")
            throw logic_error("Neispravne karte!");
        if(par.second != "1" and par.second != "2" and par.second != "3" and par.second != "4" and par.second != "5" and par.second != "6" and par.second != "7" and par.second != "8" and par.second != "9" and par.second != "10" and par.second != "J" and par.second != "Q" and par.second != "K")
            throw logic_error("Neispravne karte!");
    }*/
    if(!validirajSpil(spil))
        throw logic_error("Neispravna lista!");
}
void IspisSpila(std::list<std::pair<Boje, std::string>> &spil)
{
    cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    cout << "\nPik: ";
    for(auto par : spil)
        if(par.first == Boje::Pik)
            cout << par.second << " ";
    cout << "\nTref: ";
    for(auto par : spil)
        if(par.first == Boje::Tref)
            cout << par.second << " ";
    cout << "\nHerc: ";
    for(auto par : spil)
        if(par.first == Boje::Herc)
            cout << par.second << " ";
    cout << "\nKaro: ";
    for(auto par : spil)
        if(par.first == Boje::Karo)
            cout << par.second << " ";
    cout << "\n";
    
}
int main ()
{
    std::list<std::pair<Boje, std::string>> karte = KreirajSpil();
    int korak, brKarata;
    cout << "Unesite korak razbrajanja: ";
    cin >> korak;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> brKarata;
    auto red = IzbaciKarteRazbrajanjem(karte, korak, brKarata);
    IspisSpila(karte);
    int zaVratiti;
    cout << "Unesite broj karata koje zelite vratiti u spil: ";
    cin >> zaVratiti;
    
	return 0;
}
