intstd/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

int BrSlova(std::string s)
{
    int br = 0;Sl
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
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brt)
{
    if(brt < 1 || brt > imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
        
    std::list<std::string> l;
    std::vector<std::set<std::string>> vss(brt);
    int brtim = 0;
    
    for(auto i : imena)
        l.push_back(i);
        
    int vel1 = imena.size() % brt;
    
    int br_cl = int(imena.size() / brt) + 1;
    int br_cl2 = int(imena.size() / brt);
    
    for(auto i = l.begin(); i != l.end(); )
    {
        int a = BrSlova(*i);
        
        if(brtim < vel1)
        {
            if(vss.at(brtim).size() >= br_cl)
                brtim++;
        }
        else
            if(vss.at(brtim).size() >= br_cl2)
                brtim++;  
        
        vss.at(brtim).insert(*i);
        i = l.erase(i);
        
                
        if(i == l.end())
            i = l.begin();
            
        for(int j = 1; j < a; j++)
        {
            i++;
            
            if(i == l.end())
                i = l.begin();
        }
        
        if(i == l.end())
            i = l.begin();
            
    }
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