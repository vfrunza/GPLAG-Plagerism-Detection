/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>

struct Dijete
{
    std::string ime;
    Dijete* sljedeci;
};

std::vector<int> velicine;

void IzracunajVelicineTimova(int br_djece, int br_timova)
{
    velicine.resize(br_timova);
    for(int i(0); i < br_timova; i++)
    {
        if(i < br_djece%br_timova)
          velicine[i] = (br_djece / br_timova) + 1;
        else
          velicine[i] = (br_djece / br_timova);
    }
}

int BrojKaraktera(const std::string &s)
{
    int br(0);
    for(int i(0); i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
          br++;
    }
    return br;
}

Dijete* KreirajKruznuListu(const std::vector<std::string> &dijeca)
{
    Dijete *pocetak(nullptr), *prethodni;
    
    for(int i(0); i < dijeca.size(); i++)
    {
        Dijete *novi = new Dijete;
        novi->ime = dijeca[i];
        if(pocetak == nullptr)
        {
            pocetak = novi;
        }
        else if(i == dijeca.size() - 1)
        {
            novi->sljedeci = pocetak;
        }
        else
          prethodni->sljedeci = novi;
        prethodni = novi;
    }
    return pocetak;
}

void UbijDijete(Dijete* trenutni, Dijete* prethodni)
{
    if(trenutni->sljedeci == trenutni)
    {
        delete trenutni;
        return;
    }
    prethodni->sljedeci = trenutni->sljedeci;
    delete trenutni;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &dijeca, int br_timova)
{
    if(br_timova <= 0 || br_timova > dijeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete *pocetak(KreirajKruznuListu(dijeca));
    Dijete *prethodni = pocetak;
    for(int i(0); i < dijeca.size() - 1; i++) prethodni = prethodni->sljedeci;
    
    std::vector<std::set<std::string>> timovi(br_timova);
    IzracunajVelicineTimova(dijeca.size(), br_timova);
    
    int i(0), br_d(0), vel(dijeca.size());
    auto it(pocetak);
    while(i < br_timova)
    {
        timovi[i].insert(it->ime);
        int korak(BrojKaraktera(it->ime));
        UbijDijete(it, prethodni);
        br_d++;
        vel--;
        
        for(int j(0); j < korak%vel; j++)
        {
            prethodni = it;
            it = it->sljedeci; 
        }
        
        if(br_d == velicine[i])
        {
            i++;
            br_d = 0;
        }
    }
    return timovi;
}

int main ()
{
    int vel;
    std::cout << "Unesite broj djece: ";
    std::cin >> vel;
    
    std::cout << "Unesite imena djece:" << std::endl;
    std::vector<std::string> djeca(vel);
    for(int i(0); i < vel; i++)
      std::cin >> djeca[i];
    
    int br_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> br_timova;
    try
    {
        auto timovi(Razvrstavanje(djeca, br_timova));
        for(int i(0); i < br_timova; i++)
        {
            std::cout << "Tim " << i + 1 << ": ";
            
            int j(1);
            for(auto it(timovi[i].begin()); it != timovi[i].end(); it++)
            {
                if(j == velicine[i])
                  std::cout << *it << std::endl;
                else
                {
                    std::cout << *it << ", ";
                    j++;
                }
            }
        }
    }
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
    return 0;
}