/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <tuple>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova;

bool jeSlovo(char c)
{
    return( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') );
}

IndeksPojmova KreirajIndeksPojmova(Knjiga k)
{
    IndeksPojmova pojmovi;

    for(auto it=k.begin();it!=k.end();it++)
    {
        std::string poglavlje=it->first;
        int brstranice(0);
        for(auto itv=it->second.begin();itv!=it->second.end();itv++)
        {
            brstranice++;
            std::string rijec;
            int brojac(0);
            for(auto c : *itv)
            {
                c=std::tolower(c);
                if(jeSlovo(c)) rijec+=c;
                else 
                {
                    if(rijec.size()>0)
                    {
                        pojmovi[rijec].insert(std::make_tuple(poglavlje,brstranice,brojac-rijec.size()));
                    }
                    rijec="";
                }
                brojac++;
            }
            if(rijec.size()>0)
            {
                pojmovi[rijec].insert(std::make_tuple(poglavlje,brstranice,brojac-rijec.size()));
            }
            rijec="";
        }
    }
    return pojmovi;    
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, IndeksPojmova pojmovi)
{
    auto it(pojmovi.find(rijec));
    if(it == pojmovi.end()) throw std::logic_error("Pojam nije nadjen");
    else return pojmovi[rijec];
}
void IspisiIndeksPojmova(IndeksPojmova pojmovi)
{
    for(auto it=pojmovi.begin();it!=pojmovi.end();it++)
    {
        std::cout<<it->first<<": ";
        for(auto its=it->second.begin();its!=it->second.end();its++)
        {
            auto t=*its;
            std::cout<<std::get<0>(t)<<"/"<<std::get<1>(t)<<"/"<<std::get<2>(t);
            if(its!=--(it->second.end())) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    Knjiga k; //std::map<std::string, std::vector<std::string>>
    while(true)
    {
        std::string poglavlje;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,poglavlje);
        if(poglavlje==".") break;
        std::vector<std::string> v;
        int i(0);
        while(true)
        {
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            std::string unos;
            std::getline(std::cin,unos);
            if(unos==".") break;
            v.push_back(unos);
            i++;
        }
        k[poglavlje]=v;
    }
    auto pojmovi=KreirajIndeksPojmova(k);
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(pojmovi);
    std::cout<<std::endl;
    while(true)
    {
        std::cout<<"Unesite rijec: ";
        std::string unos;
        std::getline(std::cin,unos);
        if(unos==".") break;
        try
        {
            auto nadjeno=PretraziIndeksPojmova(unos,pojmovi);
            for(auto its=nadjeno.begin();its!=nadjeno.end();its++)
            {
                auto t=*its;
                std::cout<<std::get<0>(t)<<"/"<<std::get<1>(t)<<"/"<<std::get<2>(t);
                if(its!=--(nadjeno.end())) std::cout<<" ";
            }
            std::cout<<std::endl;
        }
        catch(...)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
