/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include<stdexcept>
void pomjeriIterator(std::list<std::string> lista, std::list<std::string>::iterator &it, int poz)
{
    auto it2 = lista.end();
    it2--;
    for(int i = 0; i < poz; i++)
    {
        if(it++ == lista.end())
            it = lista.begin();
         
    }
}

std::vector<int> brojnostTimova(int n, int k)
{
    std::vector<int> brojnost;
    for(int i = 0; i < k; i++)
    {
        if(i < n % k)
            brojnost.push_back((n/k)+1);
        else
            brojnost.push_back(n/k);
    }
    return brojnost;
}

int DuzinaImena(std::string ime)
{
    int duzina(0);
    
    for (auto znak : ime)
        if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z') || (znak >= '0' && znak <= '9')) duzina++;
    
    return duzina;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj_timova)
{
    if (broj_timova < 1 || broj_timova > djeca.size())
        throw std::logic_error("Razvrstavanje nemoguce");

    std::list<std::string> lista;

    for (int i = 0; i < djeca.size(); i++)
        lista.push_back(djeca[i]);

    std::vector<int> brojnost = brojnostTimova(djeca.size(), broj_timova);
    std::vector<std::set<std::string>> timovi;
    std::set<std::string> tim;
    std::list<std::string>::iterator it(lista.begin());
    
    int pomjeraj = 0, ekipa = 0, clanovi = 0;

    while (!lista.empty())
    {
        while (pomjeraj)
        {
            it++;
            
            if (it == lista.end())
                it = lista.begin();
            
            pomjeraj--;
        }

        tim.insert(*it);
        pomjeraj = DuzinaImena(*it) - 1;
        clanovi++;
        it = lista.erase(it);

        if (brojnost[ekipa] == clanovi)
        {
            timovi.push_back(tim);
            ekipa++;
            clanovi = 0;
            tim.clear();
        }
        
        if (it == lista.end())
            it = lista.begin();
    }
    
    return timovi;
}

void Ispisi(std::vector<std::set<std::string>> timovi)
{
    for(int i = 0; i < timovi.size(); i++)
    {
        std::cout << "Tim " << i+1 << ": ";
        auto it2 = timovi[i].end();
        it2--;
        for(auto it = timovi[i].begin(); it != timovi[i].end(); it++)
        {
            if(it == it2)
                std::cout << *it;
            else
                std::cout << *it << ", ";
        }
        std::cout << std::endl;
    }
}
int main ()
{
    std::vector<std::string> djeca;
    try{
    std::cout << "Unesite broj djece: ";
    int n, k;
    std::cin >> n;
    std::cout << "Unesite imena djece:\n";
    std::cin.ignore(10000, '\n');
    for(int i = 0; i < n; i++)
    {
        std::string ime;
        std::getline(std::cin, ime);
        djeca.push_back(ime);
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> k;
    std::vector<std::set<std::string>> timovi = Razvrstavanje(djeca, k);
    Ispisi(timovi);
    }
    catch(std::logic_error d){
        std::cout<<"Izuzetak: "<<d.what();
    }
	return 0;
}