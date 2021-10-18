// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include<iostream>
#include<type_traits>
#include<vector>
#include<deque>
#include<stdexcept>
#include<iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip>
auto IzdvojiDijagonale3D(tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    for(int i = 0; i < int(kont.size()); i++)
        for(int j = 1; j < int(kont.at(i).size()); j++)
            if(int(kont.at(i).at(0).size()) != int(kont.at(i).at(j).size()))
                throw std::domain_error("Redovi nemaju isti broj elemenata");
                
    for(int i = 1; i < int(kont.size()); i++)
            if(int(kont.at(0).size()) != int(kont.at(i).size()))
                throw std::domain_error("Plohe nemaju isti broj redova");
                
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    
    if(smjer == SmjerKretanja::NaprijedNazad)
    {
        for(int i = 0; i < int(kont.size()); i++)
        {   
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = 0; j < int(kont.at(i).size()); j++)
                for(int k = 0; k < int(kont.at(i).at(j).size()); k++)
                    if(j == k)
                        red.push_back(kont.at(i).at(j).at(k));
            
            mat.push_back(red);
        }
    }
    
    if(smjer == SmjerKretanja::NazadNaprijed)
    {
        for(int i = int(kont.size()) - 1; i >= 0; i--)
        {
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = 0; j < int(kont.at(i).size()); j++)
                for(int k = int(kont.at(i).at(j).size()) - 1; k >= 0; k--)
                    if(j + k == int(kont.at(i).at(j).size()) - 1)
                        red.push_back(kont.at(i).at(j).at(k));
                        
            mat.push_back(red);
        }
    }
    
    if(smjer == SmjerKretanja::GoreDolje)
    {
        for(int i = 0; i < int(kont.at(0).size()); i++)
        {
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = int(kont.size()) - 1; j >= 0; j--)
                for(int k = 0; k < int(kont.at(j).at(i).size()); k++)
                    if(j + k == int(kont.size()) - 1)
                        red.push_back(kont.at(j).at(i).at(k));
                        
            mat.push_back(red);
        }
    }
    
    if(smjer == SmjerKretanja::DoljeGore)
    {
        for(int i = int(kont.at(0).size()) - 1; i >= 0; i--)
        {
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = int(kont.size()) - 1; j >= 0; j--)
                for(int k = int(kont.at(j).at(i).size()) - 1; k >= 0; k--)
                    if(int(kont.size()) - j == int(kont.at(j).at(i).size()) - k)
                        red.push_back(kont.at(j).at(i).at(k));
                        
            mat.push_back(red);
        }
    }
    
    if(smjer == SmjerKretanja::LijevoDesno)
    {
        for(int i = 0; i < int(kont.at(0).at(0).size()); i++)
        {
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = 0; j < int(kont.at(0).size()); j++)
                for(int k = int(kont.size()) - 1; k >= 0; k--)
                    if(j + k == int(kont.size()) - 1)
                        red.push_back(kont.at(k).at(j).at(i));
                        
            mat.push_back(red);
        }
    }
    
    if(smjer == SmjerKretanja::DesnoLijevo)
    {
        for(int i = int(kont.at(0).at(0).size()) - 1; i >= 0; i--)
        {
            typename std::remove_reference<decltype(kont.at(i).at(0))>::type red;
            for(int j = 0; j < int(kont.at(0).size()); j++)
                for(int k = 0; k < int(kont.size()); k++)
                    if(j == k)
                        red.push_back(kont.at(k).at(j).at(i));
                        
            mat.push_back(red);
        }
    }
    return mat;
}
int main ()
{
    try
    {
        int x, y, z;
        std::cout << "Unesite dimenzije (x y z): ";
        std::cin >> x >> y >> z;
        if(x <= 0 || y <= 0 || z <= 0)
        {
            std::cout << "Neispravne dimenzije kontejnera!";
            return 0;
        }
        std::vector<std::deque<std::deque<int>>> k(x, std::deque<std::deque<int>> ((y), std::deque<int> (z)));
        std::cout << "Unesite elemente kontejnera: ";
    
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                for(int s = 0; s < z; s++)
                    std::cin >> k.at(i).at(j).at(s);
                    
        int a;
        std::cout << "\nUnesite smjer kretanja [0 - 5]: ";
        std::cin >> a;
        
        if(a < 0 || a > 5)
        {
            std::cout << "Smjer kretanja nije ispravan!" << std::endl;
            return 0;
        }
            
        const char *smjerovi[] = {"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo" };
        SmjerKretanja smjer = SmjerKretanja (a);
        auto mat = IzdvojiDijagonale3D(k, smjer);
        
        std::cout << smjerovi[a] << ":" << std::endl;
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat.at(i).size(); j++)
                std::cout.width(4), std::cout << mat.at(i).at(j);
            std::cout << std::endl;
        }
    }
    
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
	return 0;
}