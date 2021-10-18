/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>
void SveUMala(std::string &rijec)
{
    for(int i=0;i<rijec.length();i++)
    {
        rijec[i]=std::tolower(rijec[i]);
    }
}
std::map<std::string , std::set<int>> KreirajIndeksPojmova(std::string recenica)
{
    std::map<std::string , std::set<int>> mapa;
    std::string pomoc,pomoc2;
    for(int i=0;i<recenica.length();i++)
    {
        if((recenica[i]>='0' && recenica[i]<='9')||(recenica[i]>='a' && recenica[i]<='z')||(recenica[i]>='A' && recenica[i]<='Z'))
        {
            int poz1=i;
            while((recenica[i]>='0' && recenica[i]<='9')||(recenica[i]>='a' && recenica[i]<='z')||(recenica[i]>='A' && recenica[i]<='Z'))i++;
            int poz2=i-poz1;
            pomoc=recenica.substr(poz1,poz2);
            SveUMala(pomoc);
            mapa[pomoc].insert(poz1);
            for(int j=poz2;j<recenica.length();j++)
            {
                if((recenica[j]>='0' && recenica[j]<='9')||(recenica[j]>='a' && recenica[j]<='z')||(recenica[j]>='A' && recenica[j]<='Z'))
                {
                    int poz3=j;
                    while((recenica[j]>='0' && recenica[j]<='9')||(recenica[j]>='a' && recenica[j]<='z')||(recenica[j]>='A' && recenica[j]<='Z'))j++;
                    int poz4=j-poz3;
                    pomoc2=recenica.substr(poz3,poz4);
                    SveUMala(pomoc2);
                    if(pomoc==pomoc2)
                    {
                        mapa[pomoc].insert(poz3);
                    }
                }
            }
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string , std::set<int>> mapa)
{
    auto it(mapa.find(rijec));
    if(it==mapa.end())throw std::logic_error("Pojam nije nadjen");
    else return mapa[rijec];
}
void IspisiIndeksPojmova(std::map<std::string , std::set<int>> mapa)
{
    for(auto i=mapa.begin();i!=mapa.end();i++)
    {
        char znak(',');
        std::cout<<i->first<<": ";
        for(auto j=i->second.begin();j!=i->second.end();j++)
        {
            auto granica(i->second.end());
            granica--;
            if(j==granica)znak=' ';
            std::cout<<*j<<znak;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::string recenica;
    std::string rijec;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,recenica);
    std::map<std::string,std::set<int>> mapa(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(mapa);
    do
    {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".")return 0;
        try
        {
            std::set<int> indeksi(PretraziIndeksPojmova(rijec,mapa));
            for(auto i:indeksi) std::cout<<i<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error)
        {
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }while(rijec!=".");
	return 0;
}