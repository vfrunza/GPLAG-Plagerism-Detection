/B2016/2017: Zadaća 3, Zadatak 3
#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include<vector>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        try{
            for(int i=0; i<br_redova; i++) 
            mat.elementi[i] = new TipElemenata[br_kolona];
        } catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for(int i=0; i<mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++)
                    std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m2.br_kolona; j++) {
                m3.elementi[i][j] = 0;
            }
        }
        for(int k=0; k<m1.br_redova; k++) {
            for(int i=0; i<m2.br_kolona; i++) {
                for(int j=0; j<m1.br_kolona; j++) {
                    m3.elementi[k][i]+=m1.elementi[k][j] * m2.elementi[j][i];
                }
            }
        }
        return m3;
    }
    
    
template <typename TipElemenata>
    void Prekopiraj(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m2.elementi[i][j] = m1.elementi[i][j];
            return;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, std::vector<double> v) {
        if(m1.br_redova!=m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        auto p(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        auto I(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        auto pom(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                if(i == j) I.elementi[i][j] = 1;
                else I.elementi[i][j] = 0;
                p.elementi[i][j] = 0;
            } 
        }
        for(int k=0; k<v.size(); k++) {
            if(k!=0) {
                pom = ProduktMatrica(I,m1);
                Prekopiraj(pom,I);
            }
            for(int i=0; i<m1.br_redova; i++) {
                for(int j=0; j<m1.br_kolona; j++) {
                     p.elementi[i][j]+=v[k] * I.elementi[i][j];
                }
            }
            UnistiMatricu(pom);
        }
        UnistiMatricu(I);
        return p;
    }



int main () {
    Matrica<double> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    a = StvoriMatricu<double>(m,m);
    std::cout << "Unesite elemente matrice A: " << std::endl;
    UnesiMatricu('A',a);
    int n;
    std::cout << "Unesite red polinoma: ";
    std::cin >> n;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> v;
    for(int i=0; i<=n; i++) {
        double element;
        std::cin >> element;
        v.push_back(element);
    }
    IspisiMatricu(MatricniPolinom(a,v),10,6,true);
    UnistiMatricu(a);
	return 0;
}