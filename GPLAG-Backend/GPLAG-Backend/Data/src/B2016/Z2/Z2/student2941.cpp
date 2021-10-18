// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>

using namespace std;

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename GenerickiTip>

auto IzdvojiDijagonale3D(GenerickiTip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    
    typename std::remove_reference<decltype(kont.at(0))>::type DvaDKont;
    
    for(int i(0);i<kont.size();i++) {
        for(int j(0);j<kont.at(i).size();j++) {
            if(kont.at(i).at(j).size() != kont.at(0).at(0).size()) {
                throw domain_error("Redovi nemaju isti broj elemenata");
            }
        }
        if(kont.at(i).size() != kont.at(0).size()) throw domain_error("Plohe nemaju isti broj redova");
    }
    
    if(smjer==SmjerKretanja::DesnoLijevo) {
        for(int k(kont.at(0).at(0).size()-1);k>=0;k--) {
            DvaDKont.resize(DvaDKont.size()+1);
            for(int i(0);i<kont.size();i++) {
                for(int j(0);j<kont.at(i).size();j++) {
                    if(i==j) DvaDKont.at(kont.at(0).at(0).size()-1-k).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    if(smjer==SmjerKretanja::NazadNaprijed) {
        for(int i(kont.size()-1);i>=0;i--) {
            DvaDKont.resize(DvaDKont.size()+1);
            for(int k(kont.at(0).at(0).size()-1);k>=0;k--) {
                for(int j(0);j<kont.at(i).size();j++) {
                    if(kont.at(0).at(0).size()-1-k==j) DvaDKont.at(kont.size()-1-i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    if(smjer==SmjerKretanja::GoreDolje) {
        for(int j(0);j<kont.at(0).size();j++) {
            DvaDKont.resize(DvaDKont.size()+1);
            for(int k(0);k<kont.at(0).at(0).size();k++) { 
                for(int i(kont.size()-1);i>=0;i--) { 
                    if(k==kont.size()-1-i) DvaDKont.at(j).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    if(smjer==SmjerKretanja::DoljeGore) {
        for(int j(kont.at(0).size()-1);j>=0;j--) {
            DvaDKont.resize(DvaDKont.size()+1);
            for(int k(kont.at(0).at(0).size()-1);k>=0;k--) { 
                for(int i(kont.size()-1);i>=0;i--) { 
                    if(kont.at(0).at(0).size()-1-k==kont.size()-1-i) DvaDKont.at(kont.at(i).size()-1-j).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    if(smjer==SmjerKretanja::LijevoDesno) {
        for(int k(0);k<kont.at(0).at(0).size();k++) { 
            DvaDKont.resize(DvaDKont.size()+1);
            for(int i(kont.size()-1);i>=0;i--) {
                for(int j(0);j<kont.at(0).size();j++) {  
                    if(j==kont.size()-1-i) DvaDKont.at(k).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    if(smjer==SmjerKretanja::NaprijedNazad) {
        for(int i(0);i<kont.size();i++) {
            DvaDKont.resize(DvaDKont.size()+1);
            for(int j(0);j<kont.at(0).size();j++) { 
                for(int k(0);k<kont.at(0).at(0).size();k++) { 
                    if(j==k) DvaDKont.at(i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return DvaDKont;
    }
    
    return DvaDKont;
}

int main () {

    cout << "Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>> x >> y >> z;
    if(x<0 || y<0 || z<0) {
        cout<< "Neispravne dimenzije kontejnera!\n";
        return 1;
    }
    cout << "Unesite elemente kontejnera: ";
    vector<deque<deque<int> > > kont;
    kont.resize(x);
    for(int i(0);i<kont.size();i++) kont[i].resize(y);
    for(int i(0);i<kont.size();i++) {
        for(int j(0);j<kont[i].size();j++) {
            kont[i][j].resize(z);
        }
    }
    for(int i(0);i<x;i++) {
        for(int j(0);j<y;j++) {
            for(int k(0);k<z;k++) {
                cin >> kont[i][j][k];
            }
        }
    }
    cout << "\nUnesite smjer kretanja [0 - 5]: ";
    vector<string> smjer={"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"};
    int n;
    cin >> n;
    if(n<0 || n>5) {
        cout << "Smjer kretanja nije ispravan!\n";
        return 1;
    }
    cout << smjer[n]<<": \n";
    deque<deque<int> > pom;
    try{
        pom=IzdvojiDijagonale3D(kont,SmjerKretanja(n));
    }catch(domain_error izuzetak) {
        cout<< izuzetak.what();
    }
    for(int i(0);i<pom.size();i++) {
        for(int j(0);j<pom[i].size();j++) {
            cout<<setw(4)<<pom[i][j];
        }
        cout << endl;
    }
    
	return 0;
} 