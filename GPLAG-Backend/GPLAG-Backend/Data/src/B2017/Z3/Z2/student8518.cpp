/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <tuple>
#include <iterator>

std::map<std::string, std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova ( std::map<std::string,std::vector<std::string>> knjiga)
{
    std::map<std::string, std::set<std::tuple<std::string,int,int>>> indeks_pojmova;
    
    typename std::map<std::string, std::vector<std::string>>::iterator it_knjiga=knjiga.begin();  //itertaor na prosljedjenu promjenjivu
    
    std::string rijec;
    
    typename std::string::iterator it_str;
    int i=0;
    
    int pozicija(0);
    
    do{
        do{
            it_str=it_knjiga->second.at(i).begin();
            do{
                
                while(it_str!=it_knjiga->second.at(i).end() && (*it_str<'a' || *it_str>'z') && (*it_str<'A' || *it_str>'Z') && (*it_str<'0' || *it_str>'9') )
                {
                    it_str++;
                    pozicija++;
                }
                
                
                auto pomocni=it_str;
                
                if(it_str==it_knjiga->second.at(i).end())
                continue;
                
                while(it_str!=it_knjiga->second.at(i).end() && ( (*it_str>='a' && *it_str<='z') || (*it_str>='A' && *it_str<='Z') || (*it_str>='0' && *it_str<='9') ) )
                it_str++;
                
                
                while(pomocni!=it_str)    //sve dok "pomocni" ne dodje do kraja rijeci gdje stoji "it_str" (defincicija rijeci iz postavke)
                {
                    if(*pomocni>='A' && *pomocni<='Z')
                    {
                        rijec.push_back(*pomocni+32);
                        pomocni++;
                        continue;
                    }
                    
                    rijec.push_back(*pomocni);
                    pomocni++;
                }
                
                
                indeks_pojmova[rijec];
                auto nadji_poziciju=indeks_pojmova.find(rijec);
                
                if(nadji_poziciju!=indeks_pojmova.end()) 
                nadji_poziciju->second.insert( std::make_tuple(it_knjiga->first, i+1, pozicija ));
                
               pozicija+=rijec.size();
               
               rijec.resize(0);     //vracanje promjenjive "rijec" na prazan string
               
            }while(it_str!=it_knjiga->second.at(i).end());  //PROLAZAK KROZ JEDNU STRANICU
            
            i++;
            pozicija=0;
        }while(i!=it_knjiga->second.size());               //PRELAZAK NA SLJEDECU STRANU
            
        i=0;
        it_knjiga++;
    }while(it_knjiga!=knjiga.end());                      //PRELAZAK NA DRUGO POGLAVLJE
    
    return indeks_pojmova;
}

void IspisiSkup( std::set<std::tuple<std::string, int, int>> skup, std::string znak)
{
    typename std::set<std::tuple<std::string, int, int>>::iterator it_set=skup.begin(), it_set_predzadnji;
    
    it_set_predzadnji=skup.end();
    
    std::advance(it_set_predzadnji, -1);
    
    while(it_set!=it_set_predzadnji)
    {
        std::cout<< std::get<0>(*it_set) <<"/"<< std::get<1>(*it_set) <<"/"<< std::get<2>(*it_set)<<znak;
        it_set++;
    }
    
    std::cout<< std::get<0>(*it_set) <<"/"<< std::get<1>(*it_set) <<"/"<< std::get<2>(*it_set);
}

void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string, int, int>>> indeks_pojmova)
{
    typename std::map<std::string,std::set<std::tuple<std::string,int,int>>>::iterator it_map=indeks_pojmova.begin();
    
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    
    do{
        std::cout<< it_map->first <<": ";
        
        /*for(it_set=(it_map->second).begin(); it_set!=(it_map->second).end(); it_set++)
        {
            std::cout<< std::get<0>(*it_set) <<"/"<< std::get<1>(*it_set) <<"/"<< std::get<2>(*it_set)<<", ";   
        }
        std::cout<<std::endl;*/
        IspisiSkup( it_map->second, ", ");
        std::cout<<std::endl;
        
        it_map++;
    }while(it_map!=indeks_pojmova.end());
}

std::set<std::tuple<std::string,int,int>> PretratziIndeksPojmova(std::string rijec, std::map<std::string,std::set<std::tuple<std::string, int, int>>> indeks_pojmova)
{
    typename std::string::iterator it_rijec=rijec.begin();
    
    while(it_rijec!=rijec.end())  
    {
        if(*it_rijec>='A' && *it_rijec<='Z')
            *it_rijec=(*it_rijec+32);
        it_rijec++;
    }
    
    std::set<std::tuple<std::string,int,int>> skup;
    
    typename std::map<std::string, std::set<std::tuple<std::string, int, int>>>::iterator it_map; //DA LI JE I ZA POSLANU RIJEC SVEJEDNO JE L VELIKA ILI MALA SLOVA KORISTI
    
    it_map=indeks_pojmova.find(rijec);
    
    if(it_map==indeks_pojmova.end())
    throw std::logic_error("Unesena rijec nije nadjena!");
    
    skup=it_map->second;
    
    return skup;
}

int main ()
{
    std::map<std::string, std::vector<std::string>> knjiga;
    
    typename std::map<std::string, std::vector<std::string>>::iterator it_map=knjiga.begin();
    
    std::map<std::string, std::set<std::tuple<std::string,int,int>>> indeks_pojmova;
    
        std::string poglavlje, sadrzaj_stranice;
        do{
            std::cout<<"Unesite naziv poglavlja: ";
            getline(std::cin, poglavlje);
            
            if(poglavlje!=".")
            {
                knjiga[poglavlje];
                
                it_map=knjiga.find(poglavlje);
                
                int i(0);
                do{
                    std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
                    getline(std::cin, sadrzaj_stranice);
                    i++;
                    
                    if(sadrzaj_stranice!=".")
                    (it_map->second).push_back(sadrzaj_stranice);
                    
                }while(sadrzaj_stranice!=".");
            }
            
        }while(poglavlje!=".");
        
        indeks_pojmova=KreirajIndeksPojmova(knjiga);
        IspisiIndeksPojmova(indeks_pojmova);
        
        std::string rijec;
        do{
            try
            {
                std::cout<<"Unesite rijec: ";
                getline(std::cin, rijec);
                if(rijec==".")
                break;
                
                auto skup=PretratziIndeksPojmova(rijec, indeks_pojmova);
                IspisiSkup(skup, " ");
                std::cout<<" "<<std::endl;
            }
            catch(std::logic_error poruka)
            {
                std::cout<<poruka.what()<<std::endl;
            }
        }while(rijec!=".");
   
	return 0;
}


//abc qwe stsda abc abc dhi qwe hrkw dhi