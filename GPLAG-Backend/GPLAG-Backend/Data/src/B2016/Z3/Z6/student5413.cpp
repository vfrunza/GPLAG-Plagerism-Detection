/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <memory>

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

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

Dijete* KreirajKruznuListu(const std::vector<std::string> &dijeca)
{
       
}

void UbijDijete(std::shared_ptr<Dijete> trenutni, std::shared_ptr<Dijete prethodni)
{
    
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
	return 0;
}