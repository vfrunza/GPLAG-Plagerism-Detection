/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stdexcept>

bool DaLiJeSlovoCifra (char s)
{
    if ((s>='a' && s<='z') || (s>='0' && s<='9')) return false;
    else return true;
}

std::vector<std::pair<std::string, int>> rastavi ( std::string s)
{
    std::transform (s.begin(), s.end(), s.begin(), ::tolower);
    std::vector<std::pair<std::string,int>> povratni;
    int i=0;
    while (i!=s.size())
    {
        while (i!=s.size() && DaLiJeSlovoCifra(s[i])) i++; 
        
        int j=i;
        
        while (j!=s.size() && !DaLiJeSlovoCifra(s[j])) j++; 
        
        if (i!=j)
        {
            povratni.push_back(std::make_pair(s.substr(i, j-i),i));
            i=j;
        }

    }
    return povratni;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (std::map<std::string, std::vector<std::string>> knjiga)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> MapaIndeksa;
    
    for (auto it=knjiga.begin(); it!=knjiga.end(); it++)
    {
        std::string poglavlje= it->first;
        std::vector<std::string> stranice= it->second;
        
        for (int i=0; i<stranice.size(); i++)
        {
            std::vector<std::pair<std::string, int>> rijeci= rastavi(stranice[i]);
            
            for (int j=0; j<rijeci.size(); j++)
            {
                if (MapaIndeksa.empty()) 
                {
                    std::set<std::tuple<std::string, int, int>> set; set.insert(std::make_tuple (poglavlje, i+1, rijeci[j].second));
                    MapaIndeksa.insert (std::make_pair(rijeci[j].first,set ));
                }
                else 
                {
                    auto nadji= MapaIndeksa.find (rijeci[j].first);
                    if (nadji!= MapaIndeksa.end()) (nadji->second).insert (std::make_tuple (poglavlje, i+1, rijeci[j].second));
                    else
                    {
                        std::set<std::tuple<std::string, int, int>> set; set.insert(std::make_tuple (poglavlje, i+1, rijeci[j].second));
                        MapaIndeksa.insert (std::make_pair(rijeci[j].first,set ));
                    }
                }
            }
        }
    }
    return MapaIndeksa;
    
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> MapaIndeksa)
{
    std::set<std::tuple<std::string, int, int>> rezultat;
    
    auto it= MapaIndeksa.find(rijec);
    if (it== MapaIndeksa.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    else
    {
        rezultat= it->second;
    }
    return rezultat;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<std::tuple<std::string, int, int>>> MapaIndeksa)
{
    auto it= MapaIndeksa.begin();
    auto kraj= MapaIndeksa.end();
    while (it!=kraj)
    {
        std::cout<<it->first<<": ";
        auto pocetak= (it->second).begin();
        auto kraj1= (it->second).end();
        while (pocetak!=kraj1)
        {
            auto test=pocetak;
            test++;
            if (test==kraj1)
            {
                std::cout<<std::get<0>(*pocetak)<<"/"<<std::get<1>(*pocetak)<<"/"<<std::get<2>(*pocetak);
                pocetak++;
            }
            else
            {
                std::cout<<std::get<0>(*pocetak)<<"/"<<std::get<1>(*pocetak)<<"/"<<std::get<2>(*pocetak)<<", ";
                pocetak++;  
            }
        }std::cout<<std::endl; it++;
    }
    
    
}


int main ()
{   std::map<std::string, std::vector<std::string>> zaSlanje;
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova; 
    std::string poglavlje;
    std::string unos;
    int j=0;
    do {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline (std::cin,poglavlje);
        if (poglavlje==".") break;
        std::vector<std::string> vektor;
        int i=1;
        do {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline (std::cin,unos);
            vektor.push_back(unos);
            i++;
            } while (unos!=".");
        zaSlanje.insert(std::make_pair(poglavlje, vektor));
        j++;
        //std::cout<<std::endl;
    } while (poglavlje!=".");
    
    IndeksPojmova= KreirajIndeksPojmova(zaSlanje);
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(IndeksPojmova);
    std::string rijec;
    do {
        
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec==".") break;
        std::set<std::tuple<std::string, int, int>> rezultat;
        try {
        rezultat= PretraziIndeksPojmova(rijec, IndeksPojmova);
        auto pocetak= rezultat.begin();
        auto kraj1= rezultat.end();
        while (pocetak!=kraj1)
        {

                std::cout<<std::get<0>(*pocetak)<<"/"<<std::get<1>(*pocetak)<<"/"<<std::get<2>(*pocetak)<<" ";
                pocetak++;
        }
        std::cout<<std::endl;
        }
        catch (...)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
        
    } while (rijec!=".");
    
    
	return 0;
}
