/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<string>
#include<set>
#include<iomanip>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string stringPojmova)
{
    int brojSlova=stringPojmova.length(),pomocna;
    std::string rijec;
    std::map<std::string, std::set<int>> mapaPojmova;
    for(int i=0;i<brojSlova;i++)
    {
        if(stringPojmova[i]==' ') continue;
        pomocna=i;
        rijec="";
        for(;;)
        {
            if(i>=brojSlova) break;
            if(stringPojmova[i]>='a' && stringPojmova[i]<='z' || (stringPojmova[i]>='0' && stringPojmova[i]<='9'))
            {
                rijec=rijec+stringPojmova[i];
            }
            else if(stringPojmova[i]>='A' && stringPojmova[i]<='Z' || (stringPojmova[i]>='0' && stringPojmova[i]<='9'))
            {
                // zapravo z-Z=32
                rijec+=stringPojmova[i]+'c'-'C';
            }
            else break;
            i++;
            
        }
        if(rijec.length()>0)
        {
            auto it=mapaPojmova.find(rijec);
            if(it!=mapaPojmova.end())
            {
                //pojam postoji
                mapaPojmova.at(rijec).insert(pomocna);
            }
            else
            {
                mapaPojmova[rijec];
                mapaPojmova.at(rijec).insert(pomocna);
            }
        }
    }
    return mapaPojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapaPojmova)
{
    auto it=mapaPojmova.begin();
    for(;;)
    {
        if(it==mapaPojmova.end()) break;
        if(it->first.compare(rijec)==0) return mapaPojmova.at(it->first);
        it++;
    }
    //ako nije nadjen baci izuzetak
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapaPojmova)
{
    auto it=mapaPojmova.begin();
    int brojEl=0;
    for(;;)
    {
        brojEl=0;
        if(it==mapaPojmova.end()) break;
        auto it2=begin(it->second);
        for(;;)
        {
            if(it2==end(it->second)) break;
            it2++;
            brojEl++;
        }
        it2=begin(it->second);
        std::cout<<it->first<<":"<<" ";
        for(int j=0;j<brojEl;j++)
        {
            if(brojEl==(j+1)) std::cout<<*it2;
            else std::cout<<*it2<<",";
            it2++;
        }
        std::cout<<"\n";
        it++;
    }
}
int main ()
{
    std::map<std::string, std::set<int>> mapaPojmova;
    std::string stringRijeci,rijec;
    std::cout<<"Unesite tekst: ";
    getline(std::cin,stringRijeci);
    mapaPojmova=KreirajIndeksPojmova(stringRijeci);
    IspisiIndeksPojmova(mapaPojmova);
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(rijec==".") break;
        try {
            /* code */
            std::set<int> skupPojmova=PretraziIndeksPojmova(rijec,mapaPojmova);
            auto it=begin(skupPojmova);
            for(;;)
            {
                if(it==end(skupPojmova)) break;
                std::cout<<*it++<<" ";
            }
            std::cout<<std::endl;
        }
        catch (const std::logic_error error) {
            std::cout <<"Unesena rijec nije nadjena!\n";
        }
        
    }
	return 0;
}