// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Tip_Kontejnera>
auto IzdvojiDijagonale3D(Tip_Kontejnera Kontejner, SmjerKretanja Tip) -> typename std::remove_reference<decltype(Kontejner.at(0))>::type {
    
}


int main ()
{
    
	return 0;
}
