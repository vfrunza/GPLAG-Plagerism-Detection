/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::vector<std::tuple<std::string, int, int>>> IndeksPojmova;

IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    IndeksPojmova noviIndeks;
    for(auto itK = knjiga.begin(); itK != knjiga.end(); itK++)
    {
        auto stranica = itK->second;
        for(auto i = 0; i < stranica.size(); i++)
        {
            std::string tekstStranice = stranica[i];
            std::string rijec = "";
            for(auto j = 0; j <= tekstStranice.size(); j++)
            {
                if(!isalnum(tekstStranice[j]) || tekstStranice[j] == '\0')
                {
                    if(rijec != "")
                    {
                        std::tuple<std::string, int, int> podaciORijeci = std::make_tuple(itK->first, i + 1, j - rijec.length());
                        auto checkIT(noviIndeks.find(rijec));
                        
                        if(checkIT == noviIndeks.end())
                            noviIndeks.insert({rijec, {podaciORijeci}});
                        else
                            checkIT->second.push_back(podaciORijeci);
                            
                        rijec = "";
                    }
                }
                else
                    rijec += tolower(tekstStranice[j]);
            }
            
        }
    }
    return noviIndeks;
}
std::vector<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string kljuc, IndeksPojmova index)
{
    //pretvoriti u lowercase
    std::string kljucTransf = "";
    for(auto i = 0; i < kljuc.length(); i++)
        kljucTransf += tolower(kljuc[i]);
        
    if(index.count(kljucTransf))
    {
        std::vector<std::tuple<std::string, int, int>> pozicije = index[kljucTransf];
        return pozicije;
    }
    else
        throw std::logic_error("Unesena rijec nije nadjena!");
}
void IspisiIndeksPojmova(IndeksPojmova index)
{
    for(auto it = index.begin(); it != index.end(); it++)
    {
        std::cout << it->first << ": ";
        for(auto i = 0; i < it->second.size(); i++)
        {
            std::cout << std::get<0>(it->second[i]) << "/" << std::get<1>(it->second[i])
            <<"/" << std::get<2>(it->second[i]);
            if(i < it->second.size() - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
}
int main ()
{
    Knjiga knjiga;
    std::string poglavlje = "", sadrzaj = "", kljuc = "";
    int brStranica = 0;
    
    do {
     std::cout <<"Unesite naziv poglavlja: ";
     std::getline(std::cin, poglavlje);
     
     if(poglavlje != ".")
     {
         do {
             std::cout << "Unesite sadrzaj stranice " << ++brStranica<< ": ";
             std::getline(std::cin, sadrzaj);
             if(sadrzaj != ".")
                knjiga[poglavlje].push_back(sadrzaj);
         } while(sadrzaj != ".");
     }
    } while(poglavlje != ".");
    
    IndeksPojmova noviIndeks = KreirajIndeksPojmova(knjiga);
    std::cout <<"\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(noviIndeks);
    
    do{
        std::cout << "Unesite rijec: ";
        std::cin >> kljuc;
        
        if(kljuc != ".")
        {
            try
            {
                auto rezultatPretrage = PretraziIndeksPojmova(kljuc,noviIndeks);
                for(auto i = 0; i < rezultatPretrage.size(); i++)
                {
                    std::cout << std::get<0>(rezultatPretrage[i]) <<"/"<<std::get<1>(rezultatPretrage[i])
                    << "/" << std::get<2>(rezultatPretrage[i]);
                    if(i < rezultatPretrage.size() - 1)
                        std::cout <<" ";
                }
                std::cout << std::endl;
            }
            catch(std::logic_error err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        
    }while(kljuc != ".");
    
	return 0;
}
