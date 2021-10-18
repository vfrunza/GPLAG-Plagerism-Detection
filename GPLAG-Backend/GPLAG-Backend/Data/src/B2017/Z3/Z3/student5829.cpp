/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using std::vector;
using std::cout;
using std::cin;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
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
    for(int i(0); i<mat.br_redova; i++)
        for(int j(0); j<mat.br_kolona; j++)
            mat.elementi[i][j]=0;
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> &mat1,Matrica<TipElemenata> &mat2)
{
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            for(int k(0); k<mat.br_redova; k++) {
                mat.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
            }
        }
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            cout<<std::fixed<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
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
Matrica<TipElemenata> PomnoziSa(Matrica<TipElemenata> &mat,int n)
{
    auto pom(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++)
            pom.elementi[i][j]=mat.elementi[i][j]*n;
    }
    return pom;
}

template<typename TipElemenata, typename NekiPokTip>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &mat,int n,NekiPokTip pok)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> pmat(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_redova));
    Matrica<TipElemenata> pom1;
    pom1.br_kolona=0;
    pom1.br_redova=0;
    Matrica<TipElemenata> pom2;
    pom2.br_kolona=0;
    pom2.br_redova=0;
    try {
        for(int i(0); i<n; i++) {
            if(i==0) {
                for(int j(0); j<pmat.br_redova; j++)
                    for(int k(0); k<pmat.br_kolona; k++)
                        if(j==k) pmat.elementi[j][k]+=*pok;
            } else if(i==1) {
                pom1=PomnoziSa(mat,*pok);
                pom2=ZbirMatrica(pmat,pom1);
                UnistiMatricu(pmat);
                UnistiMatricu(pom1);
                pmat=pom2;
            } else {
                pom1=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
                for(int k(0); k<pom1.br_redova; k++)
                    for(int j(0); j<pom1.br_kolona; j++)
                        pom1.elementi[k][j]=mat.elementi[k][j];
                for(int j(0); j<i-1; j++) {
                    pom2=ProduktMatrica(mat,pom1);
                    UnistiMatricu(pom1);
                    pom1=pom2;
                }
                pom1=PomnoziSa(pom2,*pok);
                UnistiMatricu(pom2);
                pom2=ZbirMatrica(pmat,pom1);
                UnistiMatricu(pmat);
                UnistiMatricu(pom1);
                pmat=pom2;
            }
            pok++;
        }
    } catch(...) {
        UnistiMatricu(pmat);
        UnistiMatricu(pom1);
        UnistiMatricu(pom2);
        throw;
    }
    return pmat;
}

int main()
{
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int red_pol(0);
        cout<<"Unesite red polinoma: ";
        cin>>red_pol;
        vector<int> v(red_pol+1);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i(0); i<v.size(); i++) {
            cin>>v[i];
        }
        b=MatricniPolinom(a,red_pol+1,v.begin());
        IspisiMatricu(b,10,0);
    } catch(std::domain_error izuzetak) {
        cout<<izuzetak.what();
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);

    return 0;
}
