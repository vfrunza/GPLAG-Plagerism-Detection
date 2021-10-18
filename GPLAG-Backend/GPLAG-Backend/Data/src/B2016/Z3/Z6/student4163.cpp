#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
#include <memory>

int duzinaImena(std::string s)
{
    int brojac(0);
    for(int i(0);i<s.size();i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imenik, int k)
{
    if(k<1 || k>imenik.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> pocetak(nullptr), trenutni(nullptr);
    for(int i(0);i<imenik.size();i++)
    {
        if(i==0)
        {
            pocetak=std::make_shared<Dijete>();
            pocetak->ime=imenik[i];
            pocetak->sljedeci=nullptr;
            trenutni=pocetak;
        }else
        {
            trenutni->sljedeci=std::make_shared<Dijete>();
            trenutni=trenutni->sljedeci;
            trenutni->ime=imenik[i];
            trenutni->sljedeci=nullptr;
        }
    }
    
    if(trenutni!=pocetak) trenutni->sljedeci=pocetak;
    else trenutni=nullptr;
   
    std::vector<std::set<std::string>> vektorSkupova;
    std::vector<int> brojaci;
    for(int i(0);i<imenik.size()%k;i++)
        brojaci.push_back(imenik.size()/k+1);
    for(int i(0);i<k-(imenik.size()%k);i++)
        brojaci.push_back(imenik.size()/k);
        
    int brDjece(imenik.size());
    auto it(pocetak);
    pocetak=nullptr;
    auto izaTrenutnog(trenutni);
    trenutni=nullptr;
    int brRep(0);
    
    for(int i(0);i<brojaci.size();i++)
    {
        int brojac(0);
        std::set<std::string> skup;
        while(brojac<brojaci[i])
        {
            for(int k(0);k<brRep-1;k++)
            {
                it=it->sljedeci;
                izaTrenutnog=izaTrenutnog->sljedeci;
            }
            skup.insert(it->ime);
            brRep=duzinaImena(it->ime);
            
            if(brDjece==1)
            {
                izaTrenutnog=nullptr;
                it->sljedeci=nullptr;
                it=nullptr;
                brDjece--;
            }else if(brDjece>=2)
            {
                auto pom(it->sljedeci);
                it=nullptr;
                izaTrenutnog->sljedeci=pom;
                it=pom;
                pom=nullptr;
                brDjece--;
            }
            
            brojac++;
        }
        vektorSkupova.push_back(skup);
    }
    
    return vektorSkupova;
}

int main()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::vector<std::string> vektor(n);
    std::cout<<"Unesite imena djece:"<<std::endl;
    std::cin.ignore(1000, '\n');
    for(int i(0);i<n;i++)
    {
        std::string s;
        std::getline(std::cin,s);
        vektor[i]=s;
    }
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    try
    {
        std::vector<std::set<std::string>> vektorSkupova;
        vektorSkupova=Razvrstavanje(vektor,k);
        for(int i(0);i<vektorSkupova.size();i++)
        {
            int brojac(1);
            std::cout<<"Tim "<<i+1<<": ";
            for(std::string x:vektorSkupova[i])
            {
                if(brojac++!=vektorSkupova[i].size()) std::cout<<x<<", ";
                else std::cout<<x;
            }
            std::cout<<std::endl;
        }
    }catch(std::logic_error l)
    {
        std::cout<<l.what();
    }
    return 0;
}