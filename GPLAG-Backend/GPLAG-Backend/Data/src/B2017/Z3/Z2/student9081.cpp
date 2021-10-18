/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool SlovoBroj (char znak)
{
    return ((znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || (znak>='0' && znak<='9'));
}
std::string PretovriUMala (std::string s)
{
    std::string vrati;
    for (int i=0;i<s.size();i++)
    {
        if (s.at(i)>='A' && s.at(i)<='Z')
        s.at(i)+=('a'-'A');
        vrati.push_back(s.at(i));
    }
    return vrati;
}   
std::string IzdvojiRijec (std::string s,int n)
{
    bool neslovo(true);
    std::string vrati;
    for (int i=n;i<s.size();i++) 
    {
        if (!SlovoBroj(s.at(i)))
        neslovo=true;
        else if (neslovo==true)
        {
            neslovo=false;
            while (i<s.size() && SlovoBroj(s.at(i)))
            {
                vrati.push_back(s.at(i));
                if (i==s.length())
                break;
                i++;
            }
            break;
        }
    }
    return vrati;
}
std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga k)
{
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> vrati;
    for (auto it=k.begin();it!=k.end();it++)
    {
        for (int i=0;i<it->second.size();i++)
        {
            for (int j=0;j<it->second[i].size();)
            {
                if (!SlovoBroj(it->second[i][j]))
                j++;
                else
                {
                    auto temp(IzdvojiRijec(it->second[i],j));
                    temp=PretovriUMala(temp);
                    while (SlovoBroj(it->second[i][j]) && j<it->second[i].size())
                    j++;
                    if (!vrati.count(temp))
                    {
                        vrati[temp];
                        std::set<std::tuple<std::string,int,int>> t;
                        for (auto poc=k.begin();poc!=k.end();poc++)
                        {
                            for (int l=0;l<poc->second.size();l++)
                            {
                                for (int m=0;m<poc->second[l].size();)
                                {
                                    if (!SlovoBroj(poc->second[l][m]))
                                    m++;
                                    else
                                    {
                                        auto temp2(IzdvojiRijec(poc->second[l],m));
                                        temp2=PretovriUMala(temp2);
                                        std::tuple<std::string,int,int> tup{poc->first,l+1,m};
                                        while (SlovoBroj(poc->second[l][m]) && m<poc->second[l].size())
                                        m++;
                                        if (temp==temp2)
                                        t.insert(tup);
                                    }
                                }
                            }
                        }
                        vrati[temp]=t;
                    }
                }
            }
        }
    }
    return vrati;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<std::tuple<std::string,int,int>>> indeks)
{
    s=PretovriUMala(s);
    if (!indeks.count(s))
        throw std::logic_error ("Pojam nije nadjen");
    return indeks[s];
}
void IspisiIndeksPojmova (std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks)
{
    for (auto it=indeks.begin();it!=indeks.end();it++)
    {
        std::cout<<it->first<<": ";
        int br(0);
        for (auto x=it->second.begin();x!=it->second.end();x++)
        {
            std::cout<<std::get<0>(*x)<<"/"<<std::get<1>(*x)<<"/"<<std::get<2>(*x);
            if (br!=it->second.size()-1)
            std::cout<<", ";
            br++;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    Knjiga k;
    for (;;)
    {
        std::string temp;
        std::vector<std::string> v;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,temp);
        if (temp==".")
        break;
        int i(1);
        for (;;)
        {
            std::string temp2;
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin,temp2);
            if (temp2==".")
            break;
            i++;
            v.push_back(temp2);
        }
        k.insert({temp,v});
    }
    auto ka(KreirajIndeksPojmova(k));
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(ka);
    for (;;)
    {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if (rijec==".")
        break;
        try 
        {
            auto skup(PretraziIndeksPojmova(rijec,ka));
            for (auto ppp=skup.begin();ppp!=skup.end();ppp++)
            {
                std::cout<<std::get<0>(*ppp)<<"/"<<std::get<1>(*ppp)<<"/"<<std::get<2>(*ppp)<<" ";
            }
            std::cout<<std::endl;
        }
        catch (std::logic_error)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
