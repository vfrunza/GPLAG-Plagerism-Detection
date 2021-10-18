/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (const Matrica<TipElemenata> &mat) {
    if(!mat.elementi) return;
    for(int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    //mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova=0, int br_kolona=0) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; 
    mat.br_kolona=br_kolona;
    try {
        mat.elementi=new TipElemenata*[br_redova];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    } 
    for(int i(0); i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i(0); i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            std::cout.width(sirina_ispisa);
            std::cout.precision(preciznost);
            std::cout << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++) {
        for(int j(0); j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    AnulirajMatricu(m3);
    for(int i(0); i<m1.br_redova; i++) {
        for(int j(0); j<m2.br_kolona; j++) {
            for(int k(0); k<m1.br_kolona; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata>
void PomnoziSkalarom (double broj, const Matrica<TipElemenata> &mat) {
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            mat.elementi[i][j]*=broj;
        }
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat, std::vector<double> v) {
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto matricni_polinom=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
    AnulirajMatricu(matricni_polinom);
    if(v.size()==0) return matricni_polinom;
    for(int i(0); i<=v.size(); i++) {
        auto produkt(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for(int k(0); k<mat.br_redova; k++) {
            for(int s(0); s<mat.br_kolona; s++) {
                if(k==s) produkt.elementi[k][s]=1; 
                else produkt.elementi[k][s]=0;
            }
        }
        for(int j(0); j<i; j++) {
            try {
               produkt=ProduktMatrica<double>(produkt, mat);
            } catch(...) {
                throw;
            }
        }
        try {
        PomnoziSkalarom<double>(v[i], produkt);
        matricni_polinom=ZbirMatrica<double>(matricni_polinom, produkt);
        UnistiMatricu(produkt);
        } catch(...) {throw;}
    }
    return matricni_polinom;
}

template <typename TipElemenata>
void AnulirajMatricu (const Matrica<TipElemenata> &mat) {
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            mat.elementi[i][j]=0;
        }
    }
}

int main () {
    Matrica<double> a, c;
    int n(0);
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a=StvoriMatricu<double>(n,n);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::vector<double> vektor;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i(0); i<=red; i++) {
            double broj;
            std::cin >> broj;
            vektor.push_back(broj);
        }
        //auto c=MatricniPolinom<double>(a, vektor);
        IspisiMatricu<double>(c=MatricniPolinom<double>(a, vektor), 10);
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(...) {
        std::cout << "Problemi sa memorijom" << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
	return 0;
}