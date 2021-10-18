/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
 
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
 
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }catch(...) {
        UnistiMatricu(mat);
        throw; 
    }
    return mat;
}
 
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}

template <typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma=0;
            int temp=0;
            int tempi=i;
            int tempj=j;
            for(int k=0; k<m1.br_redova; k++) {
                suma+=m1.elementi[tempi][temp]*m2.elementi[temp][tempj];
                temp++;
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
 
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
}
 
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata, typename T>
Matrica<TipElemenata>MatricniPolinom(Matrica<TipElemenata> &m1, int n, T start) {
    if(m1.br_redova!=m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    
    auto rez(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto temp=m1;
    int okidac=2;
    
    for(int i=0; i<=n; i++) {
        if(i==0) {
            for(int j=0; j<m1.br_redova; j++) {
                for(int k=0; k<m1.br_kolona; k++) {
                    if(j==k) rez.elementi[j][k]=start.at(i);
                    else rez.elementi[j][k]=0;
                }
            }
        } else {
            if(i==1) {
               // auto temp(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
                for(int j=0; j<m1.br_redova; j++) {
                    for(int k=0; k<m1.br_kolona; k++) {
                        rez.elementi[j][k]+=(start.at(i)*m1.elementi[j][k]);
                    }
                }
            } else {
                if(i>1) {
                    while(1) {
                        m1=ProduktMatrica(m1, temp);
                        okidac++;
                        break;
                    }
                    for(int j=0; j<m1.br_redova; j++) {
                        for(int k=0; k<m1.br_kolona; k++) {
                            rez.elementi[j][k]+=(start.at(i)*m1.elementi[j][k]);
                        }
                    }
                }
            }
        }
    }
    UnistiMatricu(temp);
    /*for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) {
            if(i==0 && j==0) rez.elementi[i][j]=24;
            else if(i==0 && j==1) rez.elementi[i][j]=5;
            else if(i==1 && j==0) rez.elementi[i][j]=0;
            else if(i==1 && j==1) rez.elementi[i][j]=-1;
        }
    }*/
    return rez;
}


int main() {
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    int polinom;
    std::vector<int>koeficijenti;
    Matrica<double> mat, rez;
    
    try {
        mat = StvoriMatricu<double>(m, m);
    }catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
        UnistiMatricu(mat);
        UnistiMatricu(rez);
        return 0;
    }
    
    std::cout << "Unesite elemente matrice A:" << std::endl;
    UnesiMatricu('A', mat);
    std::cout << "Unesite red polinoma: ";
    std::cin >> polinom;
    std::cout << "Unesite koeficijente polinoma: ";
    for(int i=0; i<=polinom; i++) {
        int broj;
        std::cin >> broj;
        koeficijenti.push_back(broj);
    }
    
    try {    //IspisiMatricu(rez=ProduktMatrica(mat, mat), 5, 3, false);
        IspisiMatricu(rez=MatricniPolinom(mat, polinom, koeficijenti), 10, 6, false);
    }catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
        UnistiMatricu(rez);
        UnistiMatricu(mat);
    }catch(std::domain_error jedan) {
        std::cout << jedan.what() << std::endl;
        UnistiMatricu(rez);
        UnistiMatricu(mat);
    }
    UnistiMatricu(rez);
    UnistiMatricu(mat);

return 0;
}