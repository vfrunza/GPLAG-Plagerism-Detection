/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo};
typedef std::pair<Boje, std::string> Karta;

//validacija karata
template<typename T>
bool validiraj(const T karte)
{
    //mora biti sortiran ispravno (prvo boje pa onda vrijednosti),
    //s ispravnim brojem elemenata, bez besmislenih podataka
    //ako nije then throw logic_error("Neispravna lista!");
    //definisati "besmislenost" podataka ?
    
    //mozda int IspravanSpil() pa return broj karata u spilu?
    return true;
}

std::list<Karta> KreirajSpil()
{
    //napravi kompletan spil (52 para)
    //sortiraj po boji pa onda po vrijednostima
    std::vector<std::string> vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::list<Karta> noviSpil;
    for(auto i = 0; i < 4; i++) //boje
    {
        for(auto j = 0; j < vrijednosti.size(); j++) //vrij.
        {
            noviSpil.push_back(std::make_pair(Boje (i), vrijednosti[j]));
        }
    }
    return noviSpil;
}

std::list<Karta> IzbaciKarte(std::list<Karta>& spil, std::multimap<Boje, std::string>& elem)
{
    //check if ispravanSpil(spil)
    validiraj<std::list<Karta>>(spil);
    //spil ne mora biti kompletan 
    //iz spila izbaciti sve karte iz elem pa iste te iz elem ukloniti
    //*moguce da u eleme ostane neka karata, ako se ne pronadje u spilu
    return spil;
}
std::queue<Karta> IzbaciKarteRazbrajanjem(std::list<Karta>& spil, const short int& r, const int& b)
{
    //check if ispravanSpil(spil); && check if b <= Spil.brojKarata
    //r >= 1 && r <= 52 || b < 1 ----> throw logic_error("Neispravni elementi za izbacivanje!")
    std::queue<Karta> karte;
    return karte;
}
std::list<Karta> VratiPrvihNKarata(std::list<Karta>& spil, std::queue<Karta>& r, int n)
{
    //u spil pohraniti prvih n karata iz r
    //if n > r.size() throw range_error("Nedovoljno karata u redu!")
    //n == undefined throw domain_error("Broj n je besmislen!");
    //ispravanSpil(r) ---> mozda ispravanSpil moze biti template funkcija?
    //if(validiraj<std::queue<Karta>(r))
    //if n-> karta == spil-> karta then skip
    return spil;
}

int main ()
{
    
    std::list<Karta> noviSpil = KreirajSpil();
	return 0;
}
