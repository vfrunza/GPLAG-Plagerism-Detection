/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

std::vector<int> velicine;

void IzracunajVelicineTimova(int br_djece, int br_timova)
{
    velicine.resize(br_timova);
    for(int i(0); i < br_timova; i++)
    {
        if(i < br_djece%br_timova)
          velicine[i] = (br_djece / br_timova) + 1;
        else
          velicine[i] = (br_djece / br_timova);
    }
}

int BrojKaraktera(std::string s)
{
    int br(0);
    for(int i(0); i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
          br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &djeca, int br_timova)
{
    if(br_timova < 1 || br_timova > djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> krug;
    for(int i(0); i < djeca.size(); i++)
      krug.push_back(djeca[i]);
    
    IzracunajVelicineTimova(djeca.size(), br_timova);
    std::vector<std::set<std::string>> timovi(br_timova);
    
    int i(0), br_d(0);
    auto it(krug.begin());
    while(!krug.empty())
    {
        if(br_d == velicine[i])
        {
            br_d = 0;
            i++;
        }
        
        timovi[i].insert(*it);
        int pomak(BrojKaraktera(*it) - 1);
        it = krug.erase(it);
        pomak %= krug.size();
        br_d++;
        
        for(int i(0); i < pomak; i++)
        {
            if(it == krug.end())
            {
                it = krug.begin();
                it++;
            }
            it++;
        }
        
    }
    
    /*std::cout << "LISTA SIZE: " << krug.size() << std::endl;*/
    return timovi;
}

int main ()
{
    int vel;
    std::cout << "Unesite broj djece: ";
    std::cin >> vel;
    
    std::cout << "Unesite imena djece:" << std::endl;
    std::vector<std::string> djeca(vel);
    for(int i(0); i < vel; i++)
      std::cin >> djeca[i];
    
    int br_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> br_timova;
    
    try
    {
        auto timovi(Razvrstavanje(djeca, br_timova));
        for(int i(0); i < br_timova; i++)
        {
            std::cout << "Tim " << i + 1 << ": ";
            
            int j(1);
            for(auto it(timovi[i].begin()); it != timovi[i].end(); it++)
            {
                if(j == velicine[i])
                  std::cout << *it << std::endl;
                else
                {
                    std::cout << *it << ", ";
                    j++;
                }
            }
        }
    }
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
	return 0;
}