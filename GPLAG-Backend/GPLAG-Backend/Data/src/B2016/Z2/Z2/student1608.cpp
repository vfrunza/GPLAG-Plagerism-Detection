// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <type_traits>
#include <vector>
enum class SmjerKretanja{
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename TipKont3d>
auto IzdvojiDijagonale3D(const TipKont3d &kont, SmjerKretanja smjer) -> std::remove_reference<decltype(kont)> {
	
	typename std::remove_reference<decltype(kont)> kont2d;
	typename std::remove_reference<decltype(kont)> kontVert;
	typename std::remove_reference<decltype(kont)> kontHor;
	// l lista po matricama
	// i lista po redovima
	// j lista po kolonama
	typename std::remove_reference<decltype(kont[0])>::type* red;
	typename std::remove_reference<decltype(kont[0][0])> var;
	for (int l = 0; l < kont.at(0).size(); l++) { 	// l su redovi kad se 3d gleda okomito
		kontVert[l].resize(l + 1);
		for (int i = 0; i <= l; l++) { 	// i je broj redova
			if (i == l)
				kontVert.at(l).push_back(kont.at(l).at(i).at(i));
		}
	}
	return kont2d;
}

int main () {
	std::vector<std::vector<std::vector<int>>> niz3d;
	std::vector<std::vector<int>> niz2d;
	std::vector<int> niz1d;
	int var;
	niz3d.push_back(niz2d);
	niz3d.push_back(niz2d);
	niz3d[0].push_back(niz1d);
	niz3d[0].push_back(niz1d);
	niz3d[0].push_back(niz1d);
	niz3d[0][0].push_back(var);
	auto jaoMeni = IzdvojiDijagonale3D(niz3d, SmjerKretanja::GoreDolje);
	std::cout << jaoMeni.size() << "\n" << jaoMeni[0].size() << "\n" << jaoMeni[0][0].size();
}