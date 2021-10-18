// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include<iostream>
#include<vector>
#include<deque>

typedef std::deque<std::deque<int>> DEK;
typedef std::vector<DEK> VEK;

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
} smjer;

auto IzdvojiDijagonale(VEK kont, SmjerKretanja parametar) -> typename std::remove_reference<decltype(kont)>::type{
    
}

int main ()
{
    int x, y, z;
    int n;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>x>>y>>z;
    std::cout<<"Unesite elemente kontejnera: ";
    
    
    
    std::cout<<"Unesite smjer kretanja [0-5]: ";
    std::cin>>n;
    std::cout<<SmjerKretanja[n];
    
    
	return 0;
}