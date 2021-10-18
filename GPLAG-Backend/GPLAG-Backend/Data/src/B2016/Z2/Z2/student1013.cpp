// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <deque>
#include <vector>
#include <type_traits>
#include <stdexcept>

enum class SmjerKretanja {
    NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template < typename Kontejner >

auto IzdvojiDijagonale3D (Kontejner kont, SmjerKretanja smjer) -> std::remove_reference<decltype(kont.at(0))>::type {
    
}

int main () {
    
	return 0;
}