#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <cctype>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    std::map<std::string,std::set<int>> pojmovi;
    std::string sub{""};
    int start{0};
    for(int i=0;i<tekst.length();i++)
    {
        if(isalnum(tekst.at(i)))
        {
            sub.push_back(tekst.at(i));
            if(sub.length()==1) start=i;
            if(tekst.length()-1==i) goto EXIT_PROCESS;
        }
        else
        {
EXIT_PROCESS:
            for(int j=0;j<sub.length();j++) sub[j]=tolower(sub[j]);
            pojmovi[sub].insert(start);
            sub.resize(0);
        }
    }
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> pojmovi)
{
    auto slide(pojmovi.find(rijec));
    if(slide==pojmovi.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return slide->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> pojmovi)
{
    for(auto slide=pojmovi.begin();slide!=pojmovi.end();slide++)
    {
        std::cout<<slide->first<<": ";
        for(auto it=slide->second.begin();it!=slide->second.end();it++)
        {
            if(++it!=slide->second.end()) it--, std::cout<<*it<<",";
            else it--, std::cout<<*it;
        }
        std::cout<<std::endl;
    }
}

int main()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst);
    std::map<std::string,std::set<int>> pojmovi(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(pojmovi);
    std::string rijec;
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==std::string{"."}) break;
        try
        {
            for(int x:PretraziIndeksPojmova(rijec,pojmovi)) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error info) {std::cout<<info.what()<<std::endl;}
    }
    return 0;
}