// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<stdexcept>
#include<vector>
#include<deque>
#include<iomanip>
#include<type_traits>

using namespace std;

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename triD>
auto IzdvojiDijagonale3D (triD kont, SmjerKretanja smjer) -> typename remove_reference<decltype(kont.at(0))>::type {
    for(int i = 0; i < kont.size(); i++) {
        for(int j = 0; j < kont.at(i).size(); j++) {
            if(kont.at(i).at(j).size() != kont.at(0).at(0).size()) {
                throw domain_error("Redovi nemaju isti broj elemenata");
            }
        }
        if(kont.at(i).size() != kont.at(0).size()) {
            throw domain_error("Plohe nemaju isti broj redova");
        }
    }
    typename remove_reference<decltype(kont.at(0))>::type podKont;
    int dimenzija;
    if(kont.at(0).size() <= kont.at(0).at(0).size())
        dimenzija = kont.at(0).size();
    else
        dimenzija = kont.at(0).at(0).size();
    typename remove_reference<decltype(kont.at(0).at(0))>::type red1;
    int br = 0;
    switch(smjer) {
    case SmjerKretanja::NaprijedNazad:
        for(int i = 0; i < kont.size(); i++) {
            typename remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j = 0; j < dimenzija; j++) {
                red.push_back(kont.at(i).at(j).at(j));
            }
            podKont.push_back(red);
        }
        break;
    case SmjerKretanja::NazadNaprijed:
        for(int i = kont.size() - 1; i >= 0; i--) {
            typename remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j = 0; j < dimenzija; j++) {
                red.push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-1-j));
            }
            podKont.push_back(red);
        }
        break;
    case SmjerKretanja::GoreDolje:
        for(int i = 0; i < kont.at(0).size(); i++) 
            podKont.push_back(red1);
        for(int i = kont.size() - 1; i >= 0; i--) {
            for(int j = 0; j < kont.at(i).size(); j++) {
                podKont.at(j).push_back(kont.at(i).at(j).at(kont.size() - 1 - i));
            }
        }
        break;
    case SmjerKretanja::DoljeGore:
        for(int i = 0; i < kont.at(0).size(); i++)
            podKont.push_back(red1);
        for(int i = kont.size() - 1; i >= 0; i--) {
            for(int j = kont.at(i).size() - 1; j >= 0; j--) {
                podKont.at(kont.at(i).size() - 1 - j).push_back(kont.at(i).at(j).at(kont.at(i).at(j).size() - 1 - br));
            }
            br++;
        }
        break;
    case SmjerKretanja::LijevoDesno:
        for(int i = 0; i < kont.at(0).at(0).size(); i++) 
            podKont.push_back(red1);
        for(int i = kont.size() - 1; i >= 0; i--) {
            for(int j = 0; j < kont.at(i).at(i).size(); j++) {
                podKont.at(j).push_back(kont.at(i).at(kont.size() - 1 - i).at(j));
            }
        }
        break;
    case SmjerKretanja::DesnoLijevo:
        for(int i = 0; i < kont.at(0).at(0).size(); i++) 
            podKont.push_back(red1);
        for(int i = 0; i < kont.size(); i++) {
            for(int j = kont.at(i).at(i).size() - 1; j >= 0; j--) {
                podKont.at(kont.at(i).at(i).size() - 1 - j).push_back(kont.at(i).at(i).at(j));
            }
        }
        break;
    default:
        break;
    }
    return podKont;
}

int main ()
{
    int x, y, z;
    cout << "Unesite dimenzije (x y z): ";
    cin >> x;
    cin >> y;
    cin >> z;
    if(x < 0 || y < 0 || z < 0) {
        cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> triDim;
    triDim.resize(x);
    for(int i = 0; i < x; i++) {
        triDim[i].resize(y);
        for(int j = 0; j < y; j++)
            triDim[i][j].resize(z);
    }
    cout << "Unesite elemente kontejnera: " << endl;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            for(int k = 0; k < z; k++)
                cin >> triDim[i][j][k];
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    cin >> smjer;
    switch(smjer) {
    case 0:
        cout << "NaprijedNazad: ";
        break;
    case 1:
        cout << "NazadNaprijed: ";
        break;
    case 2:
        cout << "GoreDolje: ";
        break;
    case 3:
        cout << "DoljeGore: ";
        break;
    case 4:
        cout << "LijevoDesno: ";
        break;
    case 5:
        cout << "DesnoLijevo: ";
        break;
    default:
        cout << "Smjer kretanja nije ispravan!" << endl;
        return 0;
    }
    cout << endl;
    try {
        std::deque<std::deque<int>> ret = IzdvojiDijagonale3D(triDim, (SmjerKretanja)smjer);
        for(int i = 0; i < ret.size(); i++) {
            for(int j = 0; j < ret[i].size(); j++)
                cout << setw(4) << ret[i][j];
            cout << endl;
        }
    }
    catch(domain_error err) {
        cout << err.what();
        return 0;
    }
    
	return 0;
}