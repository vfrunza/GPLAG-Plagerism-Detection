// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed,GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename Kontejner>
auto IzdvojiDijagonale3D(const Kontejner &kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont[0])>::type
{
    for(int i(0); i < kont.size(); i++)
    {
        for(int j(0); j < kont[i].size(); j++)
        {
            if(kont[i].size() != kont[i - 1].size() && i != 0)
              throw std::domain_error("Redovi nemaju isti broj elemenata");
            for(int k(0); k < kont[i][j].size(); k++)
            {
                if(kont[i][j].size() != kont[i][j - 1].size() && j != 0)
                  throw std::domain_error("Plohe nemaju isti broj redova");
            }
        }
    }
    typename std::remove_reference<decltype(kont[0])>::type kont2D;
    for(int i(0); i < kont.size(); i++)
    {
        for(int j(0); j < kont[i].size(); j++)
        {
            for(int k(0); k < kont[i][j].size(); k++)
            {
                
            }
        }
    }
    return kont2D;
}

std::string Kompas(SmjerKretanja smjer)
{
    std::string s;
    if(smjer == SmjerKretanja::NaprijedNazad) s = "NaprijedNazad:";
    else if(smjer == SmjerKretanja::NaprijedNazad) s = "NazadNaprijed:";
    else if(smjer == SmjerKretanja::GoreDolje) s = "GoreDolje:";
    else if(smjer == SmjerKretanja::DoljeGore) s = "DoljeGore:";
    else if(smjer == SmjerKretanja::LijevoDesno) s = "LijevoDesno:";
    else s = "DesnoLijevo";
    return s;
}

int main ()
{
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x <= 0 || y <= 0 || z <= 0)
    {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    std::vector<std::deque<std::vector<int>>> kont(x, std::deque<std::vector<int>>(y, std::vector<int>(z)));
    std::cout << "Unesite elemente kontejnera:" << std::endl;
    for(int i(0); i < kont.size(); i++)
    {
        for(int j(0); j < kont[i].size(); j++)
        {
            for(int k(0); k < kont[i][j].size(); k++)
                std::cin >> kont[i][j][k];
        }
    }
    
    int n;
    std::cout <<"Unesite smjer kretanja [0 - 5]: ";
    std::cin >> n;
   /* SmjerKretanja smjer(SmjerKretanja::NaprijedNazad + n);
   
   auto Rez(IzdvojiDijagonale3D(kont, smjer));
   std::cout << Kompas(smjer); << std::endl;
   for(auto niz : Rez)
   {
       for(auto x : niz)
         std::cout << std::setw(4) << x << " ";
        std::cout << std::endl;
        
   }*/
	return 0;
}