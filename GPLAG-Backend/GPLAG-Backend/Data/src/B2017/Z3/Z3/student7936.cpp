#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <list>

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
Matrica<TipElemenata> StvoriMatricu(int m)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = m;
    mat.br_kolona = m;
    mat.elementi = new TipElemenata*[m];
    for(int i = 0; i < m; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < m; i++)
            mat.elementi[i] = new TipElemenata[m];
    } catch(std::bad_alloc) {
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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<< mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            TipElemenata suma=TipElemenata();
            for (int k=0; k<m1.br_kolona; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata, typename Kontejner>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> &m1, int n, Kontejner k)
{
    if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if (m1.br_kolona!=m1.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    auto jedinicna(StvoriMatricu<TipElemenata>(m1.br_redova));
    auto rez(StvoriMatricu<TipElemenata>(m1.br_redova));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_redova; j++) {
            rez.elementi[i][j]=TipElemenata();
        }
    }
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_redova; j++) {
            if (i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=TipElemenata();
        }
    }
    for (int i=0; i<rez.br_redova; i++) {
        for (int j=0; j<rez.br_redova; j++) {
            rez.elementi[i][j]+=*k*jedinicna.elementi[i][j];
        }
    }
    UnistiMatricu(jedinicna);
    k++;
    if (n==0) return rez;
    for (int i=0; i<rez.br_redova; i++) {
        for (int j=0; j<rez.br_redova; j++) {
            rez.elementi[i][j]+=*k*m1.elementi[i][j];
        }
    }
    if (n==1) return rez;
    k++;
    int brojac(2);
    auto pom(StvoriMatricu<TipElemenata>(m1.br_redova));
    for (int i=0; i<pom.br_redova; i++) {
        for (int j=0; j<pom.br_redova; j++) {
            pom.elementi[i][j]=m1.elementi[i][j];
        }
    }
    while (brojac<=n) {
        auto p=pom;
        pom=ProduktMatrica(pom,m1);
        UnistiMatricu(p);
        for (int i=0; i<rez.br_redova; i++) {
            for (int j=0; j<rez.br_redova; j++) {
                rez.elementi[i][j]+=*k*pom.elementi[i][j];
            }
        }
        k++;
        brojac++;

    }
    UnistiMatricu(pom);
    return rez;
}

int main()
{
    Matrica<double> a,b;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    a = StvoriMatricu<double>(m);
    std::cout << "Unesite elemente matrice A:"<<std::endl;
    UnesiMatricu('A', a);
    std::cout << "Unesite red polinoma: ";
    int polinom;
    std::cin>>polinom;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::list<int> koeficijenti;
    while (koeficijenti.size()<polinom+1) {
        int unos;
        std::cin>>unos;
        koeficijenti.push_back(unos);
    }
    auto it(koeficijenti.begin());
    IspisiMatricu(b=MatricniPolinom(a,polinom,it),10,6,true);
    UnistiMatricu(a);
    return 0;
}
