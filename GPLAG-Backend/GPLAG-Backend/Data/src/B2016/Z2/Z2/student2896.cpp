// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <string>
#include <iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo  
};

template<typename tip1>
auto IzdvojiDijagonale3D(tip1 kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type tip2;
    typedef typename std::remove_reference<decltype(kont.at(0).at(0))>:: type tip3;
    tip2 mat(0);
    int x = kont.size(); // BROJ PLOČA
    int y = kont.at(0).size(); // BROJ REDOVA U PLOČI
    int z = kont.at(0).at(0).size(); // BROJ KOLONA U REDU
    for(int i=0; i<kont.size(); i++)
    {
        for(int j=0; j<kont.at(i).size(); j++)
        {
            if(kont.at(i).at(j).size() != kont.at(0).at(0).size())
            {
                throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
    }
    for(int i=0; i<kont.size(); i++)
    {
        if(kont.at(i).size() != kont.at(0).size())
        {
            throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }
    if(smjer == SmjerKretanja::NaprijedNazad)
    {
        for(int i=0; i<x; i++)
        {
            mat.push_back(tip3(0));
            int min = kont.at(i).size();
            if(kont.at(i).at(0).size() < min) min = mat.at(i).at(0);
            for(int j=0; j<min; j++)
            {
                mat.at(i).push_back(kont.at(i).at(j).at(j));
            }
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed)
    {
        for(int i=x-1; i>=0; i--)
        {
            mat.push_back(tip3(0));
            int min = y;
            if(z < min) min = z;
            for(int j = 0; j<min; j++)
            {
                mat.at(x-1-i).push_back(kont.at(i).at(j).at(z-j-1));
            }
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje)
    {
        for(int i=0; i<y; i++)
        {
            mat.push_back(tip3(0));
            int min = x;
            if(z < min) min = z;
            for(int j = 0; j<min; j++)
            {
                mat.at(i).push_back(kont.at(x-j-1).at(i).at(j));
            }
        }
    }
    else if(smjer==SmjerKretanja::DoljeGore)
    {
        for(int i=y-1; i>=0; i--)
        {
            mat.push_back(tip3(0));
            int min = x;
            if(z < min) min = z;
            for(int j=0; j<min; j++)
            {
                mat.at(y-1-i).push_back(kont.at(x-1-j).at(i).at(z-1-j));
            }
        }
    }
    else if(smjer == SmjerKretanja::LijevoDesno)
    {
        for(int i=0; i<z; i++)
        {
            mat.push_back(tip3(0));
            int min = x;
            if(y < min) min = y;
            for(int j=0; j<min; j++)
            {
                mat.at(i).push_back(kont.at(x-j-1).at(j).at(i));
            }
        }
    }
    else if(smjer == SmjerKretanja::DesnoLijevo)
    {
        for(int i=z-1; i>=0; i--)
        {
            mat.push_back(tip3(0));
            int min = x;
            if(y < min) min = y;
            for(int j=0; j<min; j++)
            {
                mat.at(z-1-i).push_back(kont.at(j).at(j).at(i));
            }
        }
    }
    return mat;
}

int main ()
{
    int x, y ,z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0)
    {
        std::cout << "Neispravne dimenzije kontejnera!\n";
        return  0;
    }
    std::cout << "Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> kocka(0);
    for(int i=0; i<x; i++)
    {
        kocka.push_back(std::deque<std::deque<int>>(0));
        for(int j = 0; j<y; j++)
        {
            kocka.at(i).push_back(std::deque<int>(0));
            for(int k=0; k<z; k++)
            {
                int broj;
                std::cin >> broj;
                kocka.at(i).at(j).push_back(broj);
            }
        }
    }
    int sm;
    std::cout << "\nUnesite smjer kretanja [0 - 5]: ";
    std::cin >> sm;
    if(sm<0 || sm>5)
    {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    try
    {
        SmjerKretanja smjer = static_cast<SmjerKretanja>(sm);
        std::deque<std::deque<int>> mat = IzdvojiDijagonale3D(kocka,smjer);
        std::string s;
        if(sm==0) s+= "NaprijedNazad";
        if(sm==1) s+= "NazadNaprijed";
        if(sm==2) s+= "GoreDolje";
        if(sm==3) s+= "DoljeGore";
        if(sm==4) s+= "LijevoDesno";
        if(sm==5) s+= "DesnoLijevo";
        std::cout << s << ": " << std::endl;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat.at(i).size(); j++)
            {
                std::cout << std::setw(4) << mat.at(i).at(j);
            }
            std::cout << std::endl;
        }
    }
    catch(std::domain_error &e)
    {
        std::cout << e.what();
    }
	return 0;
}