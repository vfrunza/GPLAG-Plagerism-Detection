/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <new>

struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};

int BrSlova(std::string s)
{
    int br = 0;
    for(char i : s)
    {
        if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
            br++;
    }
    return br;
}

void IspisiSkup(std::set<std::string> s)
{
    for(auto i = s.begin(); i != s.end(); )
    {
        std::cout << *i;
        
        i++;
        
        if(i != s.end())
            std::cout << ", ";
    }
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int brt)
{
    if(brt < 1 || brt > imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
        
    int vel1 = imena.size() % brt;
    int br_cl = int(imena.size() / brt) + 1;
    int br_cl2 = int(imena.size() / brt);
    
    Dijete *pocetak = nullptr, *prethodni, *novo = nullptr;
    
    for(int i = 0; i < imena.size(); i++)
    {
        try
        {
            novo = new Dijete;
        }
        catch(...)
        {
            for(int j = 0; j < i; j++)
            {
                Dijete *semra = pocetak;
                pocetak = pocetak->sljedeci;
                delete semra;
            }
            throw;
        }
        novo->ime = imena.at(i);
        novo->sljedeci = nullptr;
        
        if(pocetak == nullptr)
            pocetak = novo;
            
        else
            prethodni->sljedeci = novo;
            
        prethodni = novo;
        prethodni->sljedeci = pocetak;
    }
    std::vector<std::set<std::string>> vss(brt);
    if(imena.size() == 1)
    {
        vss.at(0).insert(pocetak->ime);
        delete pocetak;
        return vss;
    }
    Dijete *kopija = pocetak;
    int brtim = 0;
    int z = 1;
    while(z < imena.size())
    {
        z++;
        int a = BrSlova(kopija->ime);
        if(brtim < vel1)
        {
            if(vss.at(brtim).size() >= br_cl)
                brtim++;
        }
        
        else
        {
            if(vss.at(brtim).size() >= br_cl2)
                brtim++;
        }
        
        vss.at(brtim).insert(kopija->ime);
        
        prethodni->sljedeci = kopija->sljedeci;
        delete kopija;
        
        kopija = prethodni->sljedeci;
        
        for(int i = 1; i < a; i++)
        {
            kopija = kopija->sljedeci;
            prethodni = prethodni->sljedeci;
        }
    }
    if(brtim < vel1)
    {
        if(vss.at(brtim).size() >= br_cl)
            brtim++;
    }
    else
    {
        if(vss.at(brtim).size() >= br_cl2)
            brtim++;
    }
    vss.at(brtim).insert(kopija->ime);
    delete kopija;
    return vss;
}

int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    
    std::vector<std::string> imena;
    std::cout << "Unesite imena djece: ";
    for(int i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        imena.push_back(s);
        
    }
    
    int brt;
    std::cout << "\nUnesite broj timova: ";
    std::cin >> brt;
    
    try
    {
        std::vector<std::set<std::string>> vek = Razvrstavanje(imena, brt);
        
        for(int i = 0; i < brt; i++)
        {
            std::cout << "Tim " << i + 1 << ": ";
            IspisiSkup(vek.at(i));
            std::cout << std::endl;
        }
    }
    
    catch(std::logic_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}