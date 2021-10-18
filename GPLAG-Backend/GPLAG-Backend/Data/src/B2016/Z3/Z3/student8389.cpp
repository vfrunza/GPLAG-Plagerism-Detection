#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi= nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if (!mat.elementi) return;
    for (int i = 0; i < mat.br_redova; i++) 
        delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) 
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
    for(int i = 0; i < br_redova; i++) 
        mat.elementi[i] = new TipElemenata[br_kolona]{}; 
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
    for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) 
            std::cout << std::setw (sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
    
    if (treba_brisati=true) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
   auto mat(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    else {
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m2.br_kolona; j++) {
                for (int k=0; k<m2.br_redova; k++) {
                    mat.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
    }
    return mat;
}
template<typename TipElemenata>
void MnozenjeSkalarom (Matrica<TipElemenata> &mat, double a) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            mat.elementi[i][j]*=a;
        }
    }
}
template<typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat, std::vector<double> v) {
    if (mat.br_kolona!=mat.br_redova) 
        throw std::domain_error ("Matrica mora biti kvadratna");
    auto jedinicna (StvoriMatricu<double>(mat.br_redova, mat.br_kolona));
    auto pomocna (StvoriMatricu<double>(mat.br_redova, mat.br_kolona));
    //Jedinicna matrica
    for (int i=0; i<jedinicna.br_redova; i++) {
        for (int j=0; j<jedinicna.br_kolona; j++) {
            if (i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    }
    
    auto matricni_polinom (StvoriMatricu<double>(mat.br_redova, mat.br_kolona));
    if (v.size()==0) {
        for (int i=0; i<matricni_polinom.br_redova; i++) {
            for (int j=0; j<matricni_polinom.br_kolona; j++) {
                matricni_polinom.elementi[i][j]=0;
            }
        }
    }
    else {
        for (int i=0; i<v.size(); i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                for (int k=0; k<mat.br_kolona; k++) {
                    pomocna.elementi[i][j]=mat.elementi[i][j];
                }
            }
            auto pomnozena(StvoriMatricu<double>(mat.br_kolona, mat.br_redova));
            //for (int i=0; i<mat.br_redova; i++) {
              //  for (int j=0; j<mat.br_kolona; j++) {
                //    pomozena.elementi[i][j]=mat.elementi[i][j];
                //}
        //    }
            for (int j=0; j<i; j++) {
                pomnozena=ProduktMatrica(mat, pomnozena);
            }
             MnozenjeSkalarom<double>(pomnozena,v[i]);
             auto sabiranje(ZbirMatrica(pomnozena, matricni_polinom));
             UnistiMatricu(pomnozena);
        }
    }
    return matricni_polinom;
}

int main() {
    Matrica<double> a, b;
    int m;
    std::cout << "Unesi dimenziju kvadratne matrice: ";
    std::cin >> m;;
try
{
    a = StvoriMatricu<double>(m, m); 
    b = StvoriMatricu<double>(m, m);
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', a);
    int red_polinoma;
    std::cin>>red_polinoma;
    std::cout << "Unesite red polinoma: ";
    std::vector<double> polinom(red_polinoma+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for (int i=0; i<red_polinoma+1; i++)
        std::cin>>polinom[i];
    b=MatricniPolinom(a,polinom);
    IspisiMatricu(b,5);
    
}
catch (std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
}
UnistiMatricu(a);
UnistiMatricu(b);
return 0;
}