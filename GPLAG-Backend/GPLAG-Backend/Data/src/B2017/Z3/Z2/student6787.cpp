/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include<vector>
#include<tuple>
#include<map>

typedef std::map<std::string,std::vector<std::tuple<std::string,int,int>>>IndeksPojmova;
typedef std::map<std::string,std::vector<std::string>>Knjiga;

IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    IndeksPojmova index;
    for(auto iterK=knjiga.begin();iterK!=knjiga.end();iterK++)
    {
        auto stranica=iterK->second;
        for(auto i=0;i<stranica.size();i++)
        {
            std::string tekst=stranica[i];
            std::string rijec="";
            for(auto j=0;j<=tekst.size();j++)
            {
                if(!isalnum(tekst[j]) || tekst[j]=='\0')
                {
                    if(rijec!="")
                    {
                        std::tuple<std::string,int,int>info=std::make_tuple(iterK->first,i+1,j-rijec.length());
                        auto pretraga(index.find(rijec));
                        if(pretraga==index.end())
                        index.insert({rijec,{info}});
                        else
                        pretraga->second.push_back(info);
                        rijec="";
                    }
                }
                else
                rijec+=tolower(tekst[j]);
            }
        }
    }
    return index;
}

void IspisiIndeksPojmova(IndeksPojmova index)
{
    for(auto iter=index.begin();iter!=index.end();iter++)
    {
        std::cout<<iter->first<<": ";
        for(auto i=0;i<iter->second.size();i++)
        {
            std::cout<<std::get<0>(iter->second[i])<<"/"<<std::get<1>(iter->second[i])<<"/"<<std::get<2>(iter->second[i]);
            if(i<iter->second.size()-1)
            std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}


std::vector<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string pojam,IndeksPojmova index)
{
    std::string pojam_lower="";
    for(auto i=0;i<pojam.length();i++)
    pojam_lower+=tolower(pojam[i]);
    if(index.count(pojam_lower))
    {
        std::vector<std::tuple<std::string,int,int>>poz=index[pojam_lower];
        return poz;
    }
    else
    throw std::logic_error("Unesena rijec nije nadjena!");
}
int main ()
{
    Knjiga knjiga;
    std::string poglavlje="",sadrzaj="",pojam="";
    int stranica=0;
    do{
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,poglavlje);
        if(poglavlje !=".")
        {
            do{
                std::cout<<"Unesite sadrzaj stranice "<<++stranica<<": ";
                std::getline(std::cin,sadrzaj);
                if(sadrzaj!=".")
                knjiga[poglavlje].push_back(sadrzaj);
            }while(sadrzaj!=".");
        }
        
        }while(poglavlje!=".");
        IndeksPojmova index=KreirajIndeksPojmova(knjiga);
        std::cout<<"\nKreirani indeks pojmova:\n";
        IspisiIndeksPojmova(index);
        do{
            std::cout<<"Unesite rijec: ";
            std::cin>>pojam;
            if(pojam!=".")
            {
                try{
                    auto rezultatPretrage=PretraziIndeksPojmova(pojam,index);
                    for(auto i=0;i<rezultatPretrage.size();i++)
                    {
                        std::cout<<std::get<0>(rezultatPretrage[i])<<"/"<<std::get<1>(rezultatPretrage[i])<<"/"<<std::get<2>(rezultatPretrage[i]);
                        if(i<rezultatPretrage.size()-1)
                        std::cout<<" ";
                    }
                    std::cout<<std::endl;
                }
                catch(std::logic_error err)
                {
                    std::cout<<err.what()<<std::endl;
                }
            }
            
        }while(pojam!=".");
 //   }
	return 0;
}
