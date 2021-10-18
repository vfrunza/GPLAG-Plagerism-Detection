#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};


int Broj_slova (std::string s)
{
    int n = 0;
    for (int i{};i<s.length();i++)
        {
            if (s[i]>='A' && s[i]<='Z')
                n++;
            else if (s[i]>='a' && s[i]<='z')
                n++;
            else if (s[i]>='0' && s[i]<='9')
                n++;
        }
    
    return n;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena_djece, int k)
{
    int n = imena_djece.size();
    
    if (k<1 || k>n)
        throw std::logic_error ("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> rezultat;       
    if (n == 0)
        return rezultat;
    
    int ostatak = n%k;
    int cijeli_dio = n/k;
    
    rezultat.resize(k);
    
    std::shared_ptr<Dijete> pocetni (nullptr), prethodni;
    for (int i{};i<imena_djece.size();i++)
        {
            std::shared_ptr<Dijete> novi = std::make_shared<Dijete> ();
            novi->ime = imena_djece[i];
            novi->sljedeci = nullptr;
            
            if (pocetni == nullptr)
                pocetni = novi;
            else
                prethodni->sljedeci = novi;
            prethodni = novi;
        }
    prethodni->sljedeci = pocetni;
        
    std::shared_ptr<Dijete> it = pocetni;
    int brojac = 0;
    int broj_upisanih = 0;
    int broj_tima = 0;
    int granica = cijeli_dio+1;
    if (ostatak == 0)
        granica--;
    while(true)
        {
            rezultat[broj_tima].insert(it->ime);
            broj_upisanih++;
            brojac++;
            
            if (brojac == n)
                {
                    it->sljedeci = nullptr;
                    it = nullptr;
                    break;
                }
                
            int pomjeranje = Broj_slova(it->ime);
            pomjeranje--;
            
            /* Brisanje */
            std::shared_ptr<Dijete> pomocni = it;
            std::shared_ptr<Dijete> prije_pocetnog = it;
            
            pomocni = pomocni->sljedeci;
            while (pomocni!=it)
                {
                    pomocni = pomocni->sljedeci;
                    prije_pocetnog = prije_pocetnog->sljedeci;
                }
            
            pomocni = pomocni->sljedeci;
            prije_pocetnog->sljedeci = pomocni;
            it = pomocni;
            
            prije_pocetnog = nullptr;
            pomocni = nullptr;
            
            for (int i{};i<pomjeranje;i++)
                it = it->sljedeci;
                
            
             if (broj_upisanih == granica)
                {
                    broj_tima++;
                    broj_upisanih = 0;
                    if (broj_tima >= ostatak && ostatak!=0)
                        granica = cijeli_dio;
                        
                }
        }
    
    pocetni->sljedeci = nullptr;
    pocetni = nullptr;
    prethodni->sljedeci = nullptr;
    prethodni = nullptr;
    return rezultat;
}





int main ()
{
    
    try
    {
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(10000, '\n');
        
        std::vector<std::string> v;
        std::cout<<"Unesite imena djece:"<<std::endl;
        for (int i{};i<n;i++)
            {
                std::string s;
                std::getline(std::cin,s);
                v.push_back(s);
            }
        
        std::cout<<"Unesite broj timova: ";
        int k;
        std::cin>>k;
        
        auto ispis = Razvrstavanje(v,k);
        for (int i{};i<ispis.size();i++)
            {
                std::cout<<"Tim "<<i+1<<": ";
                
                auto it = ispis[i].begin();
                auto zadnji = ispis[i].end();
                zadnji--;
                while (it!=ispis[i].end())
                    {
                        if (it == zadnji)
                            std::cout<<*it;
                        else
                            std::cout<<*it<<", ";
                        
                        it++;
                    }
                std::cout<<std::endl;
                
            }
    }
    catch (std::logic_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}