/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <list>
std::vector<std::set<std::string>> Razvrstaj(std::vector<std::string> imena,int broj_timova)
{
    if(broj_timova<1 || broj_timova>imena.size())throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista(imena.size());
    std::vector<std::set<std::string>> Vratiti(broj_timova);
    int i(0);
    for(auto j=lista.begin();j!=lista.end();j++)
    {
        *j=imena[i];i++;
    }
    int timovi,ostatak,provjera_reda(0),j(0);
    timovi=imena.size()/broj_timova;
    ostatak=imena.size()%broj_timova;
    auto granica(lista.end());
    granica--;
    for(auto i=lista.begin();i!=lista.end();i++)
    {
        int duzina(0),k=0;
        while((*i)[k]!='\0')
        {
            if(((*i)[k]>='0' && (*i)[k]<='9')||((*i)[k]>='a' && (*i)[k]<='z')||((*i)[k]>='A' && (*i)[k]<='Z'))duzina++;
            k++;
        }
        Vratiti[j].insert(*i);
        if(i!=granica)i=lista.erase(i);
        else{lista.erase(i);i=lista.begin();}
        granica=lista.end();granica--;
        while((duzina-1)!=0)
        {
            if(i==granica)i=lista.begin();
            else i++;
            duzina--;
        }
        provjera_reda++;
        if(ostatak>0)
        {
            if(provjera_reda==timovi+1)
            {
                j++;
                provjera_reda=0;
                ostatak--;
            }
        }
        else
        {
            if(provjera_reda==timovi)
            {
                j++;
                provjera_reda=0;
            }
        }
        i--;
    }
    return Vratiti;
}
int main ()
{
    try
    {
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        std::vector<std::string> imena;
        for(auto i=0;i<n;i++)
        {
            std::string ime;
            std::getline(std::cin,ime);
            imena.push_back(ime);
        }
        std::cout<<"Unesite broj timova: ";
        int broj_timova;
        std::cin>>broj_timova;
        auto vraceni(Razvrstaj(imena,broj_timova));
        for(int i=0;i<vraceni.size();i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            auto granica(vraceni[i].end());
            granica--;
            for(auto j=vraceni[i].begin();j!=vraceni[i].end();j++)
            {
                if(j!=granica)std::cout<<*j<<", ";
                else std::cout<<*j;
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error)
    {
        std::cout<<"Razvrstavanje nemoguce";
    }
	return 0;
}