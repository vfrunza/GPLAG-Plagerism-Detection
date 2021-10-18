// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <type_traits>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

typedef SmjerKretanja sk;

int min(int a, int b) {
    return a < b ? a : b;
}

template <typename T>
auto IzdvojiDijagonale3D(T kont, SmjerKretanja smjer)
-> typename std::remove_reference<decltype(kont.at(0))>::type
{
    int nx = kont.size();
    if (!nx) return {{}};
    
    int nz = 0;
    for (int x = 0; x < nx; x++)
        if (kont.at(x).size()) {
            nz = kont.at(x).at(0).size();
            break;
        }
    
    for (int x = 0; x < nx; x++) 
        for (int y = 0; y < kont.at(x).size(); y++)
            if (kont.at(x).at(y).size() != nz)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
                    
    int ny = kont.at(0).size();
    
    for (int x = 0; x < nx; x++) 
        if (kont.at(x).size() != ny)
            throw std::domain_error("Plohe nemaju isti broj redova");
            
    if (nz == 0) return {{}};
    
    typedef typename std::remove_reference<decltype(kont.at(0))>::type Ploha;
    typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Red;
    
    Ploha rez;
    switch(smjer) {
        case sk::NaprijedNazad:
        for (int x = 0; x < nx; x++) {
            Red red;
            for (int y = 0, z = 0; y < ny && z < nz; y++, z++)
                red.push_back(kont.at(x).at(y).at(z));
            rez.push_back(red);
        }
        break;
        case sk::NazadNaprijed:
        for (int x = 0; x < nx; x++) {
            Red red;
            for (int y = 0, z = 0; y < ny && z < nz; y++, z++)
                red.push_back(kont.at(nx-x-1).at(y).at(nz-z-1));
            rez.push_back(red);
        }
        break;
        case sk::GoreDolje:
        for (int y = 0; y < ny; y++) {
            Red red;
            for (int x = 0, z = 0; x < nx && z < nz; x++, z++)
                red.push_back(kont.at(nx-x-1).at(y).at(z));
            rez.push_back(red);
        }
        break;
        case sk::DoljeGore:
        for (int y = 0; y < ny; y++) {
            Red red;
            for (int x = 0, z = 0; x < nx && z < nz; x++, z++)
                red.push_back(kont.at(nx-x-1).at(ny-y-1).at(nz-z-1));
            rez.push_back(red);
        }
        break;
        case sk::LijevoDesno:
        for (int z = 0; z < nz; z++) {
            Red red;
            for (int y = 0, x = 0; y < ny && x < nx; y++, x++)
                red.push_back(kont.at(nx-x-1).at(y).at(z));
            rez.push_back(red);
        }
        break;
        case sk::DesnoLijevo:
        for (int z = 0; z < nz; z++) {
            Red red;
            for (int y = 0, x = 0; y < ny && x < nx; y++, x++)
                red.push_back(kont.at(x).at(y).at(nz-z-1));
            rez.push_back(red);
        }
        break;
    }
    
    return rez;
}



int main() {
	using std::cin;
	using std::cout;
	using std::deque;
	
	cout << "Unesite dimenzije (x y z): ";
	int x, y, z;
	cin >> x >> y >> z;
	if (x < 0 || y < 0 || z < 0) {
	    cout << "Neispravne dimenzije kontejnera!";
	    return 0;
	}
	auto unos = std::vector<deque<deque<int>>>(x, deque<deque<int>>(y, deque<int>(z, 0)));
	cout << "Unesite elemente kontejnera: \n";
    for (auto& ploha : unos)
        for (auto& red : ploha)
            for (auto& e : red)
                cin >> e;
    
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int br;
    cin >> br;
    
    sk izbor;
    switch (br) {
        case 0:
        izbor = sk::NaprijedNazad;
        cout << "NaprijedNazad:\n";
        break;
        case 1:
        izbor = sk::NazadNaprijed;
        cout << "NazadNaprijed:\n";
        break;
        case 2:
        izbor = sk::GoreDolje;
        cout << "GoreDolje:\n";
        break;
        case 3:
        izbor = sk::DoljeGore;
        cout << "DoljeGore:\n";
        break;
        case 4:
        izbor = sk::LijevoDesno;
        cout << "LijevoDesno:\n";
        break;
        case 5:
        izbor = sk::DesnoLijevo;
        cout << "DesnoLijevo:\n";
        break;
        default:
        cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    try {
        auto rez = IzdvojiDijagonale3D(unos, izbor);
        for (const auto& red : rez) {
            for (const auto& e : red)
                cout << std::setw(4) << e;
            cout << '\n';
        }
    } catch (...) {
        cout << "Izuzetak :(";   
    }
    
    
	return 0;
}