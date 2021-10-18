/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata> //struktura
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata> //Obustavljanje curenja
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
 
template <typename TipElemenata> //Stvaranje
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
        } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
 
template <typename TipElemenata> //Unosenje elemenata
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
 
template <typename TipElemenata> //Ispisivanje
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool Treba_brisati) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename TipElemenata> //Mnozenje matrica
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("“Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma=0;
            int temp=0;
            for(int a=0; a<m1.br_redova; a++) {
                suma+=m1.elementi[temp][a]*m2.elementi[a][temp];
                temp++;
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template<typename TipElemenata>//ZBRAJANJE I MNOZENJE POLINOM 2in1
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &m1, std::vector<int> brojevi) {
    if(m1.br_kolona != m1.br_redova) throw std::domain_error("“Matrica mora biti kvadratna");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto mTemp(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto JEDINICNA(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto m4(StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_kolona));
    
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; i<m1.br_kolona; j++) {
            mTemp.elementi[i][j]=m1.elementi[i][j];
        }
    }

    int brojac=brojevi.size();
    while(brojac>0) {
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                if(brojac==brojevi.size()) {
                    if(i==j) {
                        JEDINICNA.elementi[i][j]=1;
                    } else {
                        JEDINICNA.elementi[i][j]=0;
                    }
                    m3.elementi[i][j]+=JEDINICNA.elementi[i][j]*brojevi[brojac];
                } else {
                    if(brojac==brojevi.size()-1) {
                        m3.elementi[i][j]+=m1.elementi[i][j]*brojevi[brojac];
                    } else {
                        m4=ProduktMatrica(mTemp, m3);
                        for(int a=0; a<m4.br_redova; a++) {
                            for(int b=0; b<m4.br_kolona; b++) {
                                m3.elementi[a][b]+=m4.elementi[a][b]*brojevi[brojac];
                            }
                        }
                        mTemp=m3;
                        break;
                    }
                } 
            }
        }
        brojac++;
    }
    return m3;
}

int main() {
    Matrica<double> a;
    int m;
    std::cout << "Unesi dimenzije kvadratne matrice: ";
    std::cin >> m;
    std::vector<double> broj;
    int polinom;
    
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesi elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> polinom;
        std::cout << "Unesite koeficijente polinoma: ";
        
        for(int i=0; i<polinom; i++) {
            double temp;
            std::cin >> temp;
            broj.push_back(temp);
        }
        
        IspisiMatricu(MatricniPolinom(a, broj), 10, 6, false);
    } catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    UnistiMatricu(a);
    return 0;
}
