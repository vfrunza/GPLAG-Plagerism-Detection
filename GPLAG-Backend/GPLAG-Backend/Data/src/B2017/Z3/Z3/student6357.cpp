#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
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
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu<TipElemenata>(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]*m2.elementi[j][i];
        }
    }
    return m3;
}
template<typename TipElemenata>
void Inicijaliziraj(Matrica<TipElemenata> &m)
{
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            m.elementi[i][j]=0;
}
template<typename TipElemenata, typename TipIteratora>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, TipIteratora it)
{
    if(n<0) throw domain_error("Neispravan stepen polinoma");
    if(m.br_redova!=m.br_kolona) throw domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> jedinicna_mat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            if(i==j) jedinicna_mat.elementi[i][j]=1;
            else jedinicna_mat.elementi[i][j]=0;
        }
    }
    auto polinom(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    Inicijaliziraj(polinom);
    auto pomocna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    Inicijaliziraj(pomocna);
    auto mat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j]=m.elementi[i][j];
    for(int i=0; i<=n; i++) {
        if(i<1) {
            for(int brojac1=0; brojac1<pomocna.br_redova; brojac1++)
                for(int brojac2=0; brojac2<pomocna.br_kolona; brojac2++)
                    polinom.elementi[brojac1][brojac2]=(*it)*jedinicna_mat.elementi[brojac1][brojac2];
            UnistiMatricu(jedinicna_mat);
        } else {
            ++it;
            for(int brojac1=0; brojac1<pomocna.br_redova; brojac1++) {
                for(int brojac2=0; brojac2<pomocna.br_kolona; brojac2++) {
                    pomocna.elementi[brojac1][brojac2]=mat.elementi[brojac1][brojac2]*(*it);
                }
            }
            polinom=ZbirMatrica(polinom,pomocna);
            Inicijaliziraj(pomocna);
            mat=ProduktMatrica(mat,m);
        }
    }
    UnistiMatricu(pomocna);
    UnistiMatricu(mat);
    return polinom;
}
int main()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    Matrica<double> a;
    try {
        a=StvoriMatricu<double>(n,n);
        cout<<"Unesite elemente matrice A:"<<endl;
        UnesiMatricu('A',a);
        cout<<"Unesite red polinoma: ";
        int m;
        cin>>m;
        cout<<"Unesite koeficijente polinoma: ";
        vector<double> koeficijenti;
        double broj;
        for(int i=0; i<=m; i++) {
            cin>>broj;
            koeficijenti.push_back(broj);
        }
        Matrica<double> polinom(StvoriMatricu<double>(a.br_redova,a.br_kolona));
        polinom=MatricniPolinom<double>(a,m,koeficijenti.begin());
        IspisiMatricu(polinom,10,true);
    } catch(bad_alloc) {
        cout<<"Nedovoljno memorije!";
    }
    return 0;
}