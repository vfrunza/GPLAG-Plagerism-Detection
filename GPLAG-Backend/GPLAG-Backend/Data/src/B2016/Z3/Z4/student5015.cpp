/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <stdexcept> 

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

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int br_timova)
{
    if (imena.size()<br_timova or br_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    int br_djece(imena.size());
    int br_clanova_tima(br_djece/br_timova), br_timova_s_vise_cl(br_djece%br_timova);
    //Kopiranje u listu
    std::list<std::string> lista_imena;
    for (int i=0; i<imena.size(); i++) lista_imena.push_back(imena[i]);
    auto it=lista_imena.begin();
    //Kreiranje timova
    if (br_djece%br_timova==0) 
    {
        std::vector<std::set<std::string>> timovi(br_timova);
        for (int i=0; i<br_timova; i++)
        {
            int j(0);
            while (j<br_clanova_tima and i<br_timova)
            {
                while (!lista_imena.empty() and j<br_clanova_tima)
                {
                    timovi[i].insert(*it);
                    std::string ime=*it;
                    it=lista_imena.erase(it);
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (it==lista_imena.end()) it=lista_imena.begin();
                        it++; k--;
                        if (it==lista_imena.end()) it=lista_imena.begin();
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
                    tim.insert(*it);
                    std::string ime=*it;
                    it=lista_imena.erase(it);
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (it==lista_imena.end()) it=lista_imena.begin();
                        it++; k--;
                        if (it==lista_imena.end()) it=lista_imena.begin();
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
                    tim.insert(*it);
                    std::string ime=*it;
                    it=lista_imena.erase(it);
                    j++;
                    int k=BrojSlovaImena(ime)-1;
                    while (k>0)
                    {
                        if (it==lista_imena.end()) it=lista_imena.begin();
                        it++; k--;
                        if (it==lista_imena.end()) it=lista_imena.begin();
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