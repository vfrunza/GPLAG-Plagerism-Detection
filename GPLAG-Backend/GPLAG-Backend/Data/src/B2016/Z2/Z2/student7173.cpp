// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>
#include <deque>
#include <iomanip>

using std::cout;
using std::cin;
using std::domain_error;
using std::endl;
using std::vector;
using std::deque;
using std::remove_reference;

typedef int (*PokNaFun) (int, int, int);

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Matrica>
    void IspisiMatricu(const Matrica &mat)
    {
        int len1(mat.size()), len2(0);
        if (len1 > 0) len2 = mat.at(0).size();
        
        for (int row = 0; row < len1; row++) {
            for (int col = 0; col < len2; col++) {
                cout << std::setw(4) << mat.at(row).at(col);
            }
            cout << endl;
        }
    }

        
template <typename Kocka>
    auto IzdvojiDijagonale3D(const Kocka &cube, SmjerKretanja smjer) -> typename remove_reference<decltype(cube.at(0))>::type
    {
        int len1(cube.size()), len2(0), len3(0);
        if (len1 > 0) len2 = cube.at(0).size();
        if (len2 > 0) len3 = cube.at(0).at(0).size();
        
        // Projera ispravnosti kontejnera
        bool plohe(true);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) { // POGRESNO PRETPOSTAVILI DA JE LEN2 == J!!!!
                if (cube.at(i).at(j).size() != len3) throw domain_error("Redovi nemaju isti broj elemenata");
            }
            if (cube.at(i).size() != len2) plohe = false;
        }
        if (!plohe) throw domain_error("Plohe nemaju isti broj redova");
        
        auto kvadrat(typename remove_reference<decltype(cube.at(0))>::type {});
        auto linija(typename remove_reference<decltype(kvadrat.at(0))>::type {});

        int n, m, broj((int)smjer);
        PokNaFun f1, f2, f3, f4;
        f1 = [](int i, int j, int len) { return i; };
        f2 = [](int i, int j, int len) { return len - 1 - i; };
        f3 = [](int i, int j, int len) { return j; };
        f4 = [](int i, int j, int len) { return len - 1 - j; };
        PokNaFun fp1, fp2, fp3;
        if (broj < 2) {
            n = len1;
            m = len2 < len3 ? len2 : len3;
            fp2 = f3;
            if (broj == 0) {
                fp1 = f1;
                fp3 = f3;
            } else {
                fp1 = f2;
                fp3 = f4;
            }
        } else if (broj < 4) {
            n = len2;
            m = len1 < len3 ? len1 : len3;
            fp1 = f4;
            if (broj == 2) {
                fp2 = f1;
                fp3 = f3;
            } else {
                fp2 = f2;
                fp3 = f4;
            }
        } else {
            n = len3;
            m = len1 < len2 ? len1 : len2;
            fp2 = f3;
            if (broj == 4) {
                fp1 = f4;
                fp3 = f1;
            } else {
                fp1 = f3;
                fp3 = f2;
            }
        }
        
        for (int i = 0; i < n; i++) {
            kvadrat.push_back(linija);
            for (int j = 0; j < m; j++) {
                kvadrat.at(i).push_back( cube.at(fp1 (i, j, len1)).at
                    (fp2 (i, j, len2)).at(fp3 (i, j, len3)) );
            }
        }
        
        return kvadrat;
    }
        
int main() {
    int x(0), y(0), z(0);
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    if (x < 0 || y < 0 || z < 0) {
        cout << "Neispravne dimenzije kontejnera!\n";
        return 0;
    }
    
    vector<deque<deque<int>>> kocka(x, deque<deque<int>>(y, deque<int>(z, 0)));
    cout << "Unesite elemente kontejnera: \n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cin >> kocka.at(i).at(j).at(k);
            }
        }
    }
    
    int broj(0);
    cout << "Unesite smjer kretanja [0 - 5]: ";
    cin >> broj;
    if (broj < 0 || broj > 5) {
        cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    
    vector<std::string> smjerovi {"NaprijedNazad", "NazadNaprijed", "GoreDolje",
        "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    cout << smjerovi[broj] << ": \n";
    
    try {
        IspisiMatricu(IzdvojiDijagonale3D(kocka, SmjerKretanja(broj) ));
    } catch (const std::domain_error &e) {
        cout << e.what();
    }

    return 0;
}

