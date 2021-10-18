// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <algorithm> 
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <list>


enum class SmjerKretanja {
 NaprijedNazad=0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5
};

typedef std::deque<std::deque<int>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::deque<int>(br_kolona));
}

template <typename IterTip>
 auto IzdvojiDijagonale3D(IterTip kont, SmjerKretanja s) -> typename std::remove_reference<decltype(kont.at(0))>::type
 {
     if(kont.size()==0) return typename std::remove_reference<decltype(kont.at(0))>::type (kont.size());
     for(int i=0;i<kont.size();i++)
        for(int j=0;j<kont.at(i).size();j++)
            if(kont.at(0).at(0).size()!=kont.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
     for(int i=1;i<kont.size();i++)
         if(kont.at(0).size()!=kont.at(i).size()) throw std::domain_error("Plohe nemaju isti broj redova");
     if(kont.at(0).size()==0) 
     {
         return typename std::remove_reference<decltype(kont.at(0))>::type (0);
     }
     if(kont.at(0).at(0).size()==0)
     {
         return typename std::remove_reference<decltype(kont.at(0))>::type (0);
     }
     switch(s)
     {
        case SmjerKretanja::NaprijedNazad:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.size());
            for(int i=0;i<kont.size();i++)
                for(int j=0;j<std::min(kont.at(i).size(),kont.at(i).at(0).size());j++)
                    d2d.at(i).push_back(kont.at(i).at(j).at(j));
            return d2d;
            break;
        }
        case SmjerKretanja::NazadNaprijed:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.size());
            for(int i=kont.size()-1;i>=0;i--)
                for(int j=0;j<std::min(kont.at(i).size(),kont.at(i).at(0).size());j++)
                    d2d.at(kont.size()-1-i).push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-1-j));
            return d2d;
            break;
            }
        case SmjerKretanja::GoreDolje:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.at(0).size());
            for(int j=0;j<kont.at(0).size();j++)
                for(int i=0;i<kont.at(0).at(0).size()&&i<kont.size();i++)
                    d2d.at(j).push_back(kont.at(kont.size()-1-i).at(j).at(i));
            return d2d;
            break;
        }
        case SmjerKretanja::DoljeGore:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.at(0).size());
            for(int j=kont.at(0).size()-1;j>=0;j--)
                for(int i=0;i<kont.at(0).at(0).size()&&i<kont.size();i++)
                    d2d.at(kont.at(0).size()-1-j).push_back(kont.at(kont.size()-1-i).at(j).at(kont.at(0).at(0).size()-1-i));
            return d2d;
            break;
        }
        case SmjerKretanja::LijevoDesno:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.at(0).at(0).size());
            for(int j=0;j<kont.at(0).at(0).size();j++)
                for(int i=0;i<std::min(kont.at(0).size(),kont.size());i++) 
                    d2d.at(j).push_back(kont.at(kont.size()-1-i).at(i).at(j));
            return d2d;
            break;
        }
        case SmjerKretanja::DesnoLijevo:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type d2d(kont.at(0).at(0).size());
            for(int j=kont.at(0).at(0).size()-1;j>=0;j--)
                for(int i=0;i<kont.at(0).size()&&i<kont.size();i++)
                    d2d.at(kont.at(0).at(0).size()-j-1).push_back(kont.at(i).at(i).at(j));
            return d2d;
            break;
        }
     }
 }

int main ()
{
	int x,y,z;
	std::cout << "Unesite dimenzije (x y z): ";
	std::cin >> x >> y >>z;
	if(x<0 ||y<0||z<0)
	{
	    std::cout << "Neispravne dimenzije kontejnera!";
	    return 0;
	}
	try
	{
    	std::vector<Matrica> mat3d(x,KreirajMatricu(y,z));
    	std::cout << "Unesite elemente kontejnera: \n";
    	for(std::deque<std::deque<int>> &a:mat3d)
    	    for(std::deque<int> &b:a)
    	        for(int &c:b) std::cin >> c;
    	int smkr;
    	std::cout << "Unesite smjer kretanja [0 - 5]: ";
    	std::cin >> smkr;
    	switch(smkr)
    	{
    	    case 0:
                std::cout << "NaprijedNazad: \n";
                break;
            case 1:
                std::cout << "NazadNaprijed: \n";
                break;
            case 2:
                std::cout << "GoreDolje: \n";
                break;
            case 3:
                std::cout << "DoljeGore: \n";
                break;
            case 4:
                std::cout << "LijevoDesno: \n";
                break;
            case 5:
                std::cout << "DesnoLijevo: \n";
                break;
            default:
                std::cout << "Smjer kretanja nije ispravan!\n";
                return 0;
                break;
    	}
    	Matrica dij=IzdvojiDijagonale3D(mat3d,SmjerKretanja(smkr));
    	for(std::deque<int> a:dij)
    	{
    	    for(int b:a) std::cout << std::setw(4) << b;
    	    std::cout << "\n";
    	}
	}
	catch(std::bad_alloc x)
	{
	    std::cout << "Nije alocirano dovoljno memorije";
	}
	catch(std::domain_error x)
	{
	    std::cout << x.what();
	}
	return 0;
}