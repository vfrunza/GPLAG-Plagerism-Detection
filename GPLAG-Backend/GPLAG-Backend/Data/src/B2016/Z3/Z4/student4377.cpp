/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <set>
#include <iterator> 
#include <list>

int DuzinaImena(const std::string &ime)
{
    int brojac(0);
    for(int i=0; i<ime.size(); i++) 
    if((ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9'))
    brojac++;
    return brojac;
}

int OdrediKapacitet(int br_djece, int br_timova, int *visak)
{
    int kap (br_djece/br_timova);
    if(*visak > 0){ kap++; (*visak)--;}
    return kap;
}

std::list<std::string>::iterator Broj(std::list<std::string> &djeca, std::list<std::string>::iterator it, int broj_iteracija)
{
    if(djeca.size() == 0) return it;
    for(int i=0; i<broj_iteracija-1; i++)
    {
        if(it == djeca.end()) it = djeca.begin();
        it++;
    }
    return it;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &imena, int br_timova)
{
    if(imena.size() < br_timova || br_timova < 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> djeca;
    for(int i=0; i<imena.size(); i++) djeca.push_back(imena[i]);
    int visak = imena.size()%br_timova; auto *p = &visak;
    std::vector<std::set<std::string>> tim(br_timova, std::set<std::string>{});
    auto it_subjekt(djeca.begin());
    for(int l=0; l<br_timova; l++)
    {
        int kapacitet_tima = OdrediKapacitet(imena.size(), br_timova, p);
        for(int i=0; i<kapacitet_tima; i++)
        {
            int broj_iteracija(DuzinaImena(*it_subjekt));
            tim[l].insert(*it_subjekt);
            it_subjekt = djeca.erase(it_subjekt);
            it_subjekt = Broj(djeca, it_subjekt, broj_iteracija);
            if(it_subjekt == djeca.end()) it_subjekt = djeca.begin();
        }
    }
    return tim;
}

int main ()
{
    try
    {
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    if(n < 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> imena(n);
    for(int i=0; i<n; i++)
    std::getline(std::cin, imena[i]);
    std::cout << "\nUnesite broj timova: ";
    int br;
    std::cin >> br;
    
        auto m = Razvrstavanje(imena, br);
        for(int i=0; i<m.size(); i++)
        {
            std::cout << "Tim " << i+1 << ": ";
            for(auto j = m[i].begin(); j != m[i].end(); j++)
            {
                std::cout << *j;
                auto c(m[i].end()); c--;
                if(j != c) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error a) {std::cout << "Izuzetak: "<<a.what() << std::endl;}
	return 0;
}



/*Damir
Ana
Muhamed
Marko
Ivan
Mirsad
Nikolina
Alen
Jasmina
Merima*/