// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
#include <deque>

#define pb push_back

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

void IspisiMatricu_DEBUG(std::vector<std::vector<std::vector<int> > > Ma) {
    std::cout << "POCETAK DEBUGA!\n";
    for (auto i : Ma) {
	    for (auto j : i) {
	        for (auto k : j) std::cout << k << " ";
	        std::cout << "\n";
	    }
	    std::cout << "\n********\n";
	}
	std::cout << "KRAJ DEBUGA!\n";
}

template<typename T>
auto IzdvojiDijagonale3D(T &kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
	/*
	Ukoliko nije ispunjeno da svi redovi u svim plohama imaju isti broj elementa,
	funkcija treba baciti izuzetak tipa “domain_error” uz prateći tekst “Redovi nemaju isti broj
	elemenata”. Ukoliko je ovaj uvjet ispunjen, ali nije ispunjen uvjet da sve plohe imaju isti broj
	redova, funkcija treba baciti izuzetak istog tipa, ali uz prateći tekst “Plohe nemaju isti broj redova”.
	*/
	
	int x = kont.size();
	for (int i = 1; i < x; i++) {
		if (kont.at(i).size() != kont.at(0).size()) 
			throw std::domain_error("Redovi nemaju isti broj elemenata");
	}
	int y = kont.at(0).size();
	int z = kont.at(0).at(0).size();
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			if (kont.at(i).at(j).size() != kont.at(0).at(0).size())
				throw std::domain_error("Plohe nemaju isti broj redova");
	}
	
	typename std::remove_reference<decltype(kont.at(0))>::type zaVratiti;
	
	
	if (smjer == SmjerKretanja::NaprijedNazad) {
	    // NAPRIJED-NAZAD
	    
	    for (int i = 0; i < x; i++) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	    	
	        for (int j = 0; j < y; j++) {
	        	Temporarni.pb(kont.at(i).at(j).at(j));
	        }
	        zaVratiti.pb(Temporarni);
	    }
	    
	}
	else if (smjer == SmjerKretanja::NazadNaprijed) {
	    // NAZAD-NAPRIJED
	    
	    for (int i = x - 1; i >= 0; i--) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	        for (int j = 0; j < y; j++) {
	        	Temporarni.pb(kont.at(i).at(j).at(z - j - 1));
	            //std::cout << kont.at(i).at(j).at(z - j - 1) << " "; //Matrica[i][j][z - j - 1] << " ";
	        }
	        zaVratiti.pb(Temporarni);
	        //std::cout << "\n";
	    }
	}
	else if (smjer == SmjerKretanja::GoreDolje) {
	    // GORE-DOLJE
	    
	    for (int j = 0; j < y; j++) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	        for (int i = x - 1; i >= 0; i--) {
	        	Temporarni.pb(kont.at(i).at(j).at(x - i - 1));
	            //std::cout << kont.at(i).at(j).at(x - i - 1) << " "; //Matrica[i][j][x - i - 1] << " ";
	        }
	        zaVratiti.pb(Temporarni);
	        //std::cout << "\n";
	    }
	    
	}
	else if (smjer == SmjerKretanja::DoljeGore) {
	    // DOLJE-GORE
	    
	    for (int j = y - 1; j >= 0; j--) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	        for (int i = x - 1; i >= 0; i--) {
	        	Temporarni.pb(kont.at(i).at(j).at(z - (y - x - i) - 1));
	          //  std::cout << kont.at(i).at(j).at(z - (y - x - i) - 1) << " "; //Matrica[i][j][z - (y - x - i) - 1] << " ";
	        }
	        zaVratiti.pb(Temporarni);
	        //std::cout << "\n";
	    }
	}
	else if (smjer == SmjerKretanja::LijevoDesno) {
	    // LIJEVO-DESNO
	    
	    for (int j = 0; j < z; j++) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	        for (int i = x - 1; i >= 0; i--) {
	        	Temporarni.pb(kont.at(i).at(x - i - 1).at(j));
	            //std::cout << kont.at(i).at(x - i - 1).at(j) << " ";//Matrica[i][x - i - 1][j] << " ";
	        }
	        zaVratiti.pb(Temporarni);
	        //std::cout << "\n";
	    }
	}
	else if (smjer == SmjerKretanja::DesnoLijevo) {
	    // DESNO-LIJEVO
	
	    for (int j = z - 1; j >= 0; j--) {
	    	typename std::remove_reference<decltype(kont.at(0).at(0))>::type Temporarni;
	        for (int i = 0; i < x; i++) {
	        	Temporarni.pb(kont.at(i).at(i).at(j));
	            //std::cout << kont.at(i).at(i).at(j) << " ";//Matrica[i][i][j] << " ";
	        }
	        zaVratiti.pb(Temporarni);
	        //std::cout << "\n";
	    }
	}
	return zaVratiti;
}
int main ()
{
    
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
	std::cin >> x >> y >> z;
	if (x < 0 || y < 0 || z < 0) {
		std::cout << "Neispravne dimenzije kontejnera!\n";
		return 0;
	}
	
	std::vector<std::vector<std::vector<int> > > Matrica;
	std::vector<std::vector<int> > RedMatrice;
	std::vector<int> ZaPush;
	int tmp;
	
	std::cout << "Unesite elemente kontejnera: \n";
	
	for (int i = 0; i < x; i++) {
	    for (int j = 0; j < y; j++) {
	        for (int k = 0; k < z; k++) {
	            
	            std::cin >> tmp;
	            ZaPush.pb(tmp);
	        
	        }
	        
	        RedMatrice.pb(ZaPush);
	        ZaPush.clear();
	    
	    }
	    
	    Matrica.pb(RedMatrice);
	    RedMatrice.clear();
	}
	
	//IspisiMatricu_DEBUG(Matrica);
	
	int query;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	std::cin >> query;
	if (query < 0 || query > 5) {
		std::cout << "Smjer kretanja nije ispravan!\n";
		return 0;
	}
	
	try {
		SmjerKretanja zaParametar;
		std::string SamoIspis;
		
		if (query == 0) { zaParametar = SmjerKretanja::NaprijedNazad; std::cout << "NaprijedNazad: ";}
		if (query == 1) { zaParametar = SmjerKretanja::NazadNaprijed; std::cout << "NazadNaprijed: ";}
		if (query == 2) { zaParametar = SmjerKretanja::GoreDolje; std::cout << "GoreDolje: ";}
		if (query == 3) { zaParametar = SmjerKretanja::DoljeGore; std::cout << "DoljeGore: ";}
		if (query == 4) { zaParametar = SmjerKretanja::LijevoDesno; std::cout << "LijevoDesno: ";}
		if (query == 5) { zaParametar = SmjerKretanja::DesnoLijevo; std::cout << "DesnoLijevo: ";}
		
		auto sol = IzdvojiDijagonale3D(Matrica, zaParametar);
		
		std::cout << "\n";
		for (int i = 0; i < sol.size(); i++) {
			for (int j = 0; j < sol.at(i).size(); j++)
				std::cout.width(4), std::cout << sol.at(i).at(j);
			std::cout << "\n";
		}
	}
	catch (std::domain_error c) {
		std::cout << "Izuzetak: " << c.what();
	}
	
	return 0;
}