/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new> 
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};


template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu( char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
    for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice <<"(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<  mat.elementi[i][j];
        std::cout << std::endl;
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;j<m1.br_kolona;j++) {
            int proizvod(0);
            for(int k=0;k<m1.br_kolona;k++) {
                proizvod=proizvod + (m1.elementi[i][k]*m2.elementi[k][j]);
            }
            m3.elementi[i][j]=proizvod;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> DajJedinicnu (Matrica<TipElemenata> mat) {
    auto nova(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            if(i==j) nova.elementi[i][j]=1;
            else nova.elementi[i][j]=0;
        }
    }
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> SaSkalarom(Matrica<TipElemenata> &mat, int skalar) {
    auto nova(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            nova.elementi[i][j]=skalar * mat.elementi[i][j];
        }
    }
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, const std::vector<int> &koeficijenti) {
    Matrica<TipElemenata> pomocna;
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;j<m1.br_kolona;j++) {
            pomocna.elementi[i][j]=m1.elementi[i][j];
        }
    }
    Matrica<TipElemenata> I,povratna,proizvod,zbir,skalar;
    I=DajJedinicnu(m1);
    povratna=SaSkalarom(I,koeficijenti[0]);
    for(int i=1;i<koeficijenti.size();i++) {
        if(i==1) { 
            for(int i=0;i<m1.br_redova;i++) {
                for(int j=0;j<m1.br_kolona;j++) {
                    pomocna.elementi[i][j]=m1.elementi[i][j];
                }
            }
        }
        else { 
            proizvod=ProduktMatrica(pomocna,m1);
            for(int i=0;i<m1.br_redova;i++) {
                for(int j=0;j<m1.br_kolona;j++) {
                    pomocna.elementi[i][j]=proizvod.elementi[i][j];
                }
            }
        }
        UnistiMatricu(proizvod);
        skalar=SaSkalarom(pomocna,koeficijenti[i]);
        zbir=ZbirMatrica(povratna,skalar);
        for(int i=0;i<m1.br_redova;i++) {
            for(int j=0;j<m1.br_kolona;j++) {
                povratna.elementi[i][j]=zbir.elementi[i][j];
            }
        }
        UnistiMatricu(skalar);
        UnistiMatricu(zbir);
    }
    UnistiMatricu(pomocna);
    return povratna;
}


int main ()
{
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    Matrica<double> Mat1;
    Mat1=StvoriMatricu<double>(n,n);
    std::cout << "Unesite elemente matrice A: ";
    std::cout << "Unesi: "<< std::endl;
    UnesiMatricu('A', Mat1);
    int red,x;
    std::cout << "Unesite red polinoma: ";
    std::cin >> red;
    std::vector<int> koeficijenti;
    std::cout << "Unesite koeficijente polinoma: ";
    while(koeficijenti.size()<n*n) {
        std::cin >> x;
        koeficijenti.push_back(x);
    }
    auto Mat2=MatricniPolinom(Mat1,koeficijenti);
    IspisiMatricu(Mat2,10,6);
    UnistiMatricu(Mat1);
    UnistiMatricu(Mat2);
	return 0;
}