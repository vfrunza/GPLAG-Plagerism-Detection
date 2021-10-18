/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

int BrojSlova(std::string s)
{
    int brojac(0);
    for(int i(0);i<s.length();i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        brojac++;
    }
    return brojac;
}

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n)
{
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> pocetak(nullptr), prosli;
    for(int i(0);i<v.size();i++)
    {
        auto novi(std::make_shared<Dijete>());
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prosli->sljedeci=novi;
        prosli=novi;
        novi=nullptr;
    }
    auto zadnji(prosli);
    prosli->sljedeci=pocetak;
    std::vector<std::set<std::string>> tim(n);
    int brprvih(v.size()%n);
    int brc1(int(v.size()/n)+1);
    int brc2(int(v.size()/n));
    auto p(pocetak);
    for(int i(0);i<brprvih;i++)
    {
        for(int j(0);j<brc1;j++)
        {
            tim[i].insert(p->ime);
            int slova(BrojSlova(p->ime));
            auto pom(p->sljedeci);
            p=zadnji;
            p->sljedeci=pom;
            zadnji->sljedeci=pom;
                for(int k(0);k<slova;k++)
                    p=p->sljedeci;
                for(int k(1);k<slova;k++)
                    zadnji=zadnji->sljedeci;

        }
    }
    for(int i(brprvih);i<n;i++)
    {
        for(int j(0);j<brc2;j++)
        {
            tim[i].insert(p->ime);
            int slova(BrojSlova(p->ime));
            auto pom(p->sljedeci);
            p=zadnji;
            p->sljedeci=pom;
            zadnji->sljedeci=pom;

                for(int k(0);k<slova;k++)
                   p=p->sljedeci;
                for(int k(1);k<slova;k++)
                    zadnji=zadnji->sljedeci;
            
        }
    }
    p->sljedeci=nullptr;
    p=nullptr;
    zadnji=nullptr;
    pocetak=nullptr;
    return tim;
}

int main ()
{
    try
    {
    std::cout<<"Unesite broj djece: ";
    int n; std::cin>>n;
    std::cout<<"Unesite imena djece:\n";
    std::vector<std::string> v(n);
    std::cin.ignore(10000,'\n');
    for(std::string &x: v) std::getline(std::cin,x);
    std::cout<<"Unesite broj timova: ";
    int brtim; std::cin>>brtim;
    auto timovi(Razvrstavanje(v,brtim));
    for(int i(0);i<brtim;i++)
    {
        std::cout<<"Tim "<<i+1<<": ";
        auto itend=timovi[i].end(); itend--;
        for(auto it(timovi[i].begin());it!=timovi[i].end();it++)
        {
            std::cout<<*it;
            if(it!=itend) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}