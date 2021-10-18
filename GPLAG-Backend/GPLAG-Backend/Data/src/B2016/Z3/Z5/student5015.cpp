/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};

int BrojSlovaImena(std::string ime)
{
    int brojac(0);
    for (int i=0; i<ime.length(); i++) 
    {
        if ((ime[i]>='a' and ime[i]<='z') or (ime[i]>='A' and ime[i]<='Z') or (ime[i]>='0' and ime[i]<='9'))
        brojac++;
    }
    return brojac;
}

Dijete *KreirajCirkularnuListu(std::vector<std::string> v)
{
    Dijete *pocetak(nullptr), *prethodni;
    for (int i=0; i<v.size(); i++)
    {
        try
        {
            Dijete *novi(new Dijete);
            novi->ime=v[i]; novi->sljedeci=nullptr;
            
            if (!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            if (i==v.size()-1) prethodni->sljedeci=pocetak;
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    return pocetak;
}

void UnistiListu(Dijete *pocetak)
{
    auto prethodni=pocetak;
    while (pocetak!=nullptr)
    {
        pocetak=pocetak->sljedeci;
        delete prethodni;
        prethodni=pocetak;
    }
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int br_timova)
{
    if (imena.size()<br_timova or br_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    int br_djece(imena.size());
    int br_clanova_tima(br_djece/br_timova), br_timova_s_vise_cl(br_djece%br_timova);
    Dijete *pocetak;
    try
    {
        pocetak=KreirajCirkularnuListu(imena);  //Kreiranje cirkularne liste
    }
    catch(std::bad_alloc)
    {
        UnistiListu(pocetak);
        throw;
    }
    auto trenutni(pocetak);
    auto prethodnik(pocetak);
    int broj(0);
    while (broj<br_djece-1) broj++, prethodnik=prethodnik->sljedeci;
    //Kreiranje timova
    if (br_djece%br_timova==0) 
    {
        std::vector<std::set<std::string>> timovi(br_timova);
        for (int i=0; i<br_timova; i++)
        {
            int j(0);
            while (j<br_clanova_tima and i<br_timova)
            {
                while (j<br_clanova_tima)
                {
                    timovi[i].insert(trenutni->ime);
                    std::string ime=trenutni->ime;
                    auto pomocni=trenutni;
                    trenutni=trenutni->sljedeci;
                    prethodnik->sljedeci=trenutni;
                    delete pomocni;
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (prethodnik==trenutni) break;
                        prethodnik=prethodnik->sljedeci;
                        trenutni=prethodnik->sljedeci;
                        k--;
                    }
                }
            }
        }
        return timovi;
    }
    else 
    {
        std::vector<std::set<std::string>> timovi;
        for (int i=0; i<br_timova_s_vise_cl; i++)
        {
            std::set<std::string> tim;
            int j(0);
            while (j<br_clanova_tima+1 and i<br_timova_s_vise_cl)
            {
                while (j<br_clanova_tima+1)
                {
                    tim.insert(trenutni->ime);
                    std::string ime=trenutni->ime;
                    auto pomocni=trenutni;
                    trenutni=trenutni->sljedeci;
                    prethodnik->sljedeci=trenutni;
                    delete pomocni;
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (prethodnik==trenutni) break;
                        prethodnik=prethodnik->sljedeci;
                        trenutni=prethodnik->sljedeci;
                        k--;
                    }
                }
            }
            timovi.push_back(tim);
        }
        for (int i=0; i<br_timova-br_timova_s_vise_cl; i++)
        {
            std::set<std::string> tim;
            int j(0);
            while (j<br_clanova_tima and i<br_timova-br_timova_s_vise_cl)
            {
                while (j<br_clanova_tima)
                {
                    tim.insert(trenutni->ime);
                    std::string ime=trenutni->ime;
                    auto pomocni=trenutni;
                    trenutni=trenutni->sljedeci;
                    prethodnik->sljedeci=trenutni;
                    delete pomocni;
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (prethodnik==trenutni) break;
                        prethodnik=prethodnik->sljedeci;
                        trenutni=prethodnik->sljedeci;
                        k--;
                    }
                }
            }
            timovi.push_back(tim);
        }
        return timovi;
    } 
}

int main ()
{
    try
    {
        int n;
        std::cout << "Unesite broj djece: ";
        std::cin >> n;
        std::cin.ignore(1000, '\n');
        std::cout << "Unesite imena djece: " << std::endl;
        std::vector<std::string> imena;
        for (int i=0; i<n; i++)
        {
            std::string ime;
            std::getline(std::cin, ime);
            imena.push_back(ime);
        }
        int br_timova;
        std::cout << "Unesite broj timova: ";
        std::cin >> br_timova;
        auto timovi=Razvrstavanje(imena, br_timova);
        for (int i=0; i<br_timova; i++)
        {
            std::cout << "Tim " << i+1 << ": ";
            for (auto p=timovi[i].begin(); p!=timovi[i].end(); p++) 
            {
                p++;
                auto pomocni=p;
                p--;
                if (pomocni==timovi[i].end()) std::cout << *p << std::endl;
                else std::cout << *p << ", ";
            }
        }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
	return 0;
}