/B2016/2017: Zadaća 3, Zadatak 4
#include <cctype>
#include <iostream>
#include <list>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


std::list<std::string> vector_u_list(const std::vector<std::string>& vs)
{
    
    std::list<std::string> ls;
    for(const auto &elem : vs)
        ls.push_back(elem);
    return ls;
}

std::vector<int> rasporedi_broj_igraca(int broj_djece, int broj_timova)
{
    std::vector<int> ras (broj_timova, broj_djece/broj_timova);
    int ostatk = broj_djece % broj_timova;
    for(int i = 0; i < ostatk; ++i)
        ++ras[i];
    return ras;
}


int broj_slova(const std::string& s)
{
    int brojac = 0;
    for(auto elem : s)
        if(std::isdigit(elem) || (std::tolower(elem) >= 'a' && std::tolower(elem) <='z'))
            ++brojac;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> const& vs, int broj_timova)
{
    if(broj_timova < 1 || broj_timova > int(vs.size()))
        throw std::logic_error("Razvrstavanje nemoguce");
        
    auto broj_clanova_po_timu = rasporedi_broj_igraca(vs.size(), broj_timova);
  
    auto c_timovi = vector_u_list(vs);    
  
    int broj_clanova_u_timu = 0, broj_tima = 0, broj_slova_imena = 0;
    
    auto it = c_timovi.begin();

    std::vector<std::set<std::string>> rez (broj_timova);
    
    while(!c_timovi.empty())
    {
        
        if(broj_clanova_u_timu < broj_clanova_po_timu[broj_tima]){
            rez[broj_tima].insert(*it);
            ++broj_clanova_u_timu;
            broj_slova_imena = broj_slova(*it);
            it = c_timovi.erase(it);
            if(it == c_timovi.end())
                it = c_timovi.begin();
        }
        
        if(broj_clanova_u_timu == broj_clanova_po_timu[broj_tima]){
            ++broj_tima;
            broj_clanova_u_timu = 0;
        }
        
        for(int i = 0; !c_timovi.empty() && i < broj_slova_imena - 1; ++i){
            ++it;
            if(it == c_timovi.end())
                it = c_timovi.begin();
        }  
    }
    return rez;
}

void ispisi_set(const std::set<std::string>& s)
{
    auto it = s.begin();
    for(int i = 0; i < s.size() - 1; ++i, ++it)
        std::cout << *it << ", ";
    std::cout << *it <<'\n';
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int br_djece;
    std::cin >> br_djece;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> vs(br_djece);
    std::cout << "Unesite imena djece: ";
    for(int i = 0; i <br_djece; ++i)
        std::getline(std::cin, vs[i]);
    std::cout << "\nUnesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova;
    try {
        auto raz = Razvrstavanje(vs, broj_timova);
        for(int i = 0; i < raz.size(); ++i){
            std::cout << "Tim " << i + 1 << ": ";
            ispisi_set(raz[i]);
        }
    }
    catch (std::logic_error e) {
        std::cout << e.what();
    }
    
	return 0;
}