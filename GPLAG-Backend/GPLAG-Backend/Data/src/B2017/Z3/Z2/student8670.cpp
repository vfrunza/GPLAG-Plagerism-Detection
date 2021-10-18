/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <set>

typedef std::map < std::string, std::vector < std::string >> Knjiga;

std::map < std::string, std::set < std::tuple <std::string,int, int >>> KreirajIndeksPojmova (Knjiga knjiga) 
{
    std::map < std::string, std::set < std::tuple < std::string,int,int >>> mapa;
    for(auto it = knjiga.begin(); it != knjiga.end(); it++) 
    {
        std::vector < std::string > StraniceJednogPoglavlja = it -> second;
        for(int i = 0; i < StraniceJednogPoglavlja.size(); i++)
        {
            std::string SadrzajJedneStranice = it -> second[i];
            std::string rijec;
            bool PostojiRijec;
            int IndexRijeci;
            for(int j = 0; j < SadrzajJedneStranice.size(); j++)
            {
                if(SadrzajJedneStranice[j] != ' ') 
                {
                    rijec.resize(0);
                    PostojiRijec = true;
                    IndexRijeci = j;
                    while(SadrzajJedneStranice[j] != ' ' && j < SadrzajJedneStranice.size())
                    {
                        if(SadrzajJedneStranice[j] >= 'A' && SadrzajJedneStranice[j] <= 'Z')
                        SadrzajJedneStranice[j] += 32;
                        rijec.push_back(SadrzajJedneStranice[j]);
                        j++;
                    }
                    j--;
                    for(auto itMapa = mapa.begin(); itMapa != mapa.end(); itMapa++)
                    {
                        if(itMapa -> first == rijec)
                        {
                            PostojiRijec = false;
                            itMapa -> second.insert(std::make_tuple(it->first, i+1, IndexRijeci));
                        }
                    }
                    if(PostojiRijec)
                    {
                        mapa[rijec].insert(std::make_tuple(it->first, i+1, IndexRijeci));
                    }
                }
            }
        }
    }
    return mapa;
}


std::set < std::tuple < std::string,int,int >> PretraziIndeksPojmova(std::string rijec, std::map < std::string, std::set < std::tuple < std::string,int,int >>> mapa)
{
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(std::map < std::string, std::set < std::tuple < std::string, int, int >>> mapa) 
{
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        std::cout << it->first << ": ";
        std::cout << std::get<0>(*it->second.begin()) << "/";
        std::cout << std::get<1>(*it->second.begin()) << "/";
        std::cout << std::get<2>(*it->second.begin()) << "";
        for(auto x = it->second.begin(); x != it->second.end(); x++)
        {
            if(x != it->second.begin())
            {
                std::cout << ", ";
                std::cout << std::get<0>(*x) << "/";
                std::cout << std::get<1>(*x) << "/";
                std::cout << std::get<2>(*x) <<"";
            }
        }
        std::cout << std::endl;
     }
}


int main ()
{
    Knjiga knjiga;
    for(;;)
    {
    std::cout << "Unesite naziv poglavlja: ";
        std::string NazivPoglavlja;
        std::getline(std::cin, NazivPoglavlja);
        if(NazivPoglavlja == ".") break;
        for(int i = 1; ; i++)
        {
            std::string SadrzajJedneStranice;
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, SadrzajJedneStranice);
            if(SadrzajJedneStranice == ".") break;
            knjiga[NazivPoglavlja].push_back(SadrzajJedneStranice);
        }
        
    }
    std::map < std::string, std::set < std::tuple < std::string, int, int >>> mapa = KreirajIndeksPojmova(knjiga);
    std::cout << "\nKreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(mapa);
    for(;;)
    {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec == ".") return 0;
        try 
        {
            std::set < std::tuple <std::string,int, int >> skup (PretraziIndeksPojmova(rijec,mapa));
            for(auto x : skup)
            {
                std::cout << std::get<0>(x) << "/";
                std::cout << std::get<1>(x) << "/";
                std::cout << std::get<2>(x) << " ";
                }
        }
        catch(std::logic_error poruka)
        {
            std::cout << poruka.what();
        }
        std::cout << std::endl;
    }
	return 0;
}
