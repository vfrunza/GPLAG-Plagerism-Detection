// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<std::deque<std::deque<int>>> Kontejner;

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont>
auto IzdvojiDijagonale3D(kont &kontejner, SmjerKretanja smjer)->typename std::remove_reference <decltype(kontejner.at(0))>::type {
    typename std::remove_reference <decltype(kontejner.at(0).at(0))>::type temp;

    for(int k = 0; k < kontejner.size() - 1; k++) {
        for(int i = 0; i < kontejner.at(0).size() - 1; i++) {
            if(kontejner.at(k).at(i).size() != kontejner.at(k).at(i + 1).size())
                throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        if(kontejner.at(k).size() != kontejner.at(k+1).size())
            throw std::domain_error("Plohe nemaju isti broj redova");
    }

    if(smjer == SmjerKretanja::NaprijedNazad) {
        typename std::remove_reference <decltype(kontejner.at(0))>::type Naprijed_Nazad;
        for(int k = 0; k < kontejner.size(); k++) {
            for(int i = 0; i < kontejner.at(0).size(); i++) {
                for(int j = 0; j < kontejner.at(0).at(0).size(); j++) {
                    if(i == j)
                        temp.push_back(kontejner.at(k).at(i).at(j));
                }
            }
            Naprijed_Nazad.push_back(temp);
            temp.clear();
        }
        return Naprijed_Nazad;
    }

    temp.clear();

    if(smjer == SmjerKretanja::NazadNaprijed) {
        typename std::remove_reference <decltype(kontejner.at(0))>::type Nazad_Naprijed;
        for(int k = kontejner.size() - 1; k >= 0; k--) {
            for(int i = 0; i < kontejner.at(0).size(); i++) {
                for(int j = kontejner.at(0).at(0).size(); j >= 0; j--) {
                    if(i + j == kontejner.at(0).size())
                        temp.push_back(kontejner.at(k).at(i).at(j));
                }
            }
            Nazad_Naprijed.push_back(temp);
            temp.clear();
        }
        return Nazad_Naprijed;
    }

    temp.clear();

    if(smjer == SmjerKretanja::LijevoDesno) {
        typename std::remove_reference<decltype(kontejner.at(0))>::type Lijevo_Desno;
        for(int k = kontejner.size() - 1; k > 0; k--) {
            for(int i = 0; i < kontejner.at(0).size() - 1; i++) {
                for(int j = 0; j < kontejner.at(0).at(0).size(); j++) {
                    temp.push_back(kontejner.at(k).at(i).at(j));
                    temp.push_back(kontejner.at(k - 1).at(i + 1).at(j));
                    if((k - 1) == 0) {
                        Lijevo_Desno.push_back(temp);
                        temp.clear();
                    } else {
                        temp.push_back(kontejner.at(k - 2).at(i + 2).at(j));
                        if((k - 2) == 0) {
                            Lijevo_Desno.push_back(temp);
                            temp.clear();
                        }
                    }
                }
                break;
            }
            break;
        }
        return Lijevo_Desno;
    }
    temp.clear();

    if(smjer == SmjerKretanja::DesnoLijevo) {
        typename std::remove_reference<decltype(kontejner.at(0))>::type Desno_Lijevo;
        for(int k = 0; k < kontejner.size() - 1; k++) {
            for(int i = 0; i < kontejner.at(0).size() - 1; i++) {
                for(int j = kontejner.at(0).at(0).size() - 1; j >= 0; j--) {
                    temp.push_back(kontejner.at(k).at(i).at(j));
                    temp.push_back(kontejner.at(k + 1).at(i + 1).at(j));
                    if((k + 1) == kontejner.size() - 1) {
                        Desno_Lijevo.push_back(temp);
                        temp.clear();
                    } else {
                        temp.push_back(kontejner.at(k + 2).at(i + 2).at(j));
                        if((k + 2) == kontejner.size() - 1) {
                            Desno_Lijevo.push_back(temp);
                            temp.clear();
                        }
                    }
                }
                break;
            }
            break;
        }
        return Desno_Lijevo;
    }
    temp.clear();

    if(smjer == SmjerKretanja::DoljeGore) {
        typename std::remove_reference<decltype(kontejner.at(0))>::type Dolje_Gore;
        for(int k = kontejner.size() - 1; k > 0; k--) {
            for(int j = kontejner.at(0).at(0).size() - 1; j > 0; j--) {
                for(int i = kontejner.at(0).size() - 1; i >= 0; i--) {
                    temp.push_back(kontejner.at(k).at(i).at(j));
                    temp.push_back(kontejner.at(k - 1).at(i).at(j - 1));
                    Dolje_Gore.push_back(temp);
                    temp.clear();
                }
                break;
            }
        }
        return Dolje_Gore;
    }
    temp.clear();

    if(smjer == SmjerKretanja::GoreDolje) {
        typename std::remove_reference <decltype(kontejner.at(0))>::type Gore_Dolje;
        for(int k = kontejner.size() - 1; k > 0; k--) {
            for(int j = 0; j < kontejner.at(0). at(0).size() - 1; j++) {
                for(int i = 0; i < kontejner.at(0).size(); i++) {
                    temp.push_back(kontejner.at(k).at(i).at(j));
                    temp.push_back(kontejner.at(k - 1).at(i).at(j + 1));
                    Gore_Dolje.push_back(temp);
                    temp.clear();
                }
                break;
            }
        }
        return Gore_Dolje;
    }
    temp.clear();
}

int main ()
{
    try {
        int x, y, z;
        cout << "Unesite dimenzije (x y z): ";
        cin >> x >> y >> z;
        if(x < 0 || y < 0 || z < 0) {
            cout << "Neispravne dimenzije kontejnera!";
            return 1;
        }

        cin.clear();
        cin.ignore(1000, '\n');

        int s;
        Kontejner m;

        cout << "Unesite elemente kontejnera: ";
        std::deque<int> temp;
        std::deque<std::deque<int>> temp2;
        for(int k = 0; k < x; k++) {
            for(int i = 0; i < y; i++) {
                for(int j = 0; j < z; j++) {
                    int e;
                    cin >> e;
                    temp.push_back(e);
                }
                temp2.push_back(temp);
                temp.clear();
            }
            m.push_back(temp2);
            temp2.clear();
        }

        Kontejner &m1 = m;

        cout << endl << "Unesite smjer kretanja [0 - 5]: ";
        cin >> s;
        if(s < 0 || s > 5) {
            cout << "Smjer kretanja nije ispravan!" << endl;
            return 2;
        }

        std::vector<SmjerKretanja> izabrani_smjer {SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
        std::vector<std::string> smjerovi {"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};

        auto matrica (IzdvojiDijagonale3D(m1, izabrani_smjer[s]));
        cout << smjerovi[s] << ": " << endl;
        for(int k = 0; k < matrica.size(); k++) {
            for(int i = 0; i < matrica.at(0).size(); i++)
                cout << std::setw(4) << matrica.at(k).at(i);
            cout << endl;
        }
    } catch(std::domain_error izuzetak) {
        cout /*<< "Izuzetak:"*/<< izuzetak.what();
    }
    return 0;
}