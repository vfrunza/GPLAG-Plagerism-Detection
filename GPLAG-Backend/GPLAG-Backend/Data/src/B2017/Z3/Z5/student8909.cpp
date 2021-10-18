/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <queue>
#include <utility>
#include <stdexcept>
#include <string>

enum class Boje {Herc, Karo, Pik, Tref};
struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil()
{
    try
    {
        Cvor *pocetak(nullptr), *prethodni;
        for(int i=0; i<4; i++)
        {
            Boje tempboja = Boje(i);
            for(int j=2; j<=14; j++)
            {
                Karta tempkarta;
                std::string temp;
                if(j == 2) temp = "2";
                else if(j == 3) temp = "3";
                else if(j == 4) temp = "4";
                else if(j == 5) temp = "5";
                else if(j == 6) temp = "6";
                else if(j == 7) temp = "7";
                else if(j == 8) temp = "8";
                else if(j == 9) temp = "9";
                else if(j == 10) temp = "10";
                else if(j == 11) temp = "J";
                else if(j == 12) temp = "Q";
                else if(j == 13) temp = "K";
                else if(j == 14) temp = "A";
                tempkarta.boja = tempboja;
                tempkarta.vrijednost = temp;
                Cvor *novi(new Cvor);
                novi->karta = tempkarta;
                novi->sljedeci = nullptr;
                
                if(i == 0 && j == 2)
                {
                    pocetak = novi;
                    prethodni = novi;
                }
                else if(i == 3 && j == 14)
                {
                    prethodni->sljedeci = novi;
                    novi->sljedeci = pocetak;
                }
                else
                {
                    prethodni->sljedeci = novi;
                    prethodni = novi;
                }
            }
        }
        return pocetak;
    }
    catch(std::bad_alloc)
    {
        throw ("Memorijska greska");
    }    
}


void UnistiSpil(Cvor *cvor)
{
    Cvor *krajnji = cvor;
    while(krajnji -> sljedeci != cvor)
    {
        krajnji = krajnji -> sljedeci;
    }
    
    krajnji -> sljedeci = nullptr;
    
    while(cvor -> sljedeci != nullptr)
    {
        Cvor *cvorA = cvor;
        cvor = cvor -> sljedeci;
        cvorA -> sljedeci = cvorA;
        delete cvorA;
    }
    delete cvor;
}

int PrebrojKarte(Cvor *cvor)
{
    Cvor *cvorpoc = cvor;
    int br(0);
    if(cvor == cvor -> sljedeci)
    {
        br = 1; 
        return br;
    }
    br++;
    
    while((cvor -> sljedeci) != cvorpoc)
    {
        cvor = cvor->sljedeci;
        br++;
    }
    br = 52 - br;
    return br;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarte(Cvor *&pocetak, const std::pair<int, int> par)
{
    if(par.first < 1 || par.first > 52 || par.second < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
}

void VratiPosljednjihNKarata (Cvor *cvor, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    int vel = red.size();
    if (n>vel) throw std::range_error("Nedovoljno karata u steku!");
}


int main ()
{
    try{
        
    
    Cvor *pok =KreirajSpil();
    int korak, brkarata;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korak;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> brkarata;
    std::pair<int, int> par_izbaci;
    par_izbaci = std::make_pair(korak, brkarata);
    
    std::queue<std::pair<std::string, std::string>> red = IzbaciKarte(pok, par_izbaci);
    int brizb = PrebrojKarte(pok);
    
    
    
	return 0;
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch(std::range_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch(const char *c)
    {
        std::cout << c << std::endl;
    }
}
