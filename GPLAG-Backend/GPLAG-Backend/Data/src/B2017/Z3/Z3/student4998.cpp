/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // Kako bismo izbjegli duplo brisanje
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
void IspisiMatricu( Matrica<TipElemenata> mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost)<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
void PomnoziSaSkalarom( Matrica<TipElemenata> mat, double p)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            mat.elementi[i][j]=p*mat.elementi[i][j];
        }

    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++) {
            double suma(0);
            for(int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];

            m3.elementi[i][j] = suma;
        }

    return m3;
}
template <typename TipElemenata>
void UciniJedinicnom(Matrica<TipElemenata>  mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            if(i==j)mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }

}
template <typename TipElemenata,typename Itertip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, int n,Itertip poc)
{

    //poc+n+1 je iza kraja bloka
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(a.br_kolona!=a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    int m(a.br_redova);
    auto polinom(StvoriMatricu<TipElemenata>(m,m));
    UciniJedinicnom(polinom);
    auto it=poc;
    PomnoziSaSkalarom(polinom,*it);
    it++;
    //sad cemo samo ovu matricu sabirati sa odgovarajucim koeficijentima
    auto stepena(StvoriMatricu<TipElemenata>(m,m));//sluzi da racunam A^2,A^3... a da pri tome ne mijenjam matricu A
    UciniJedinicnom(stepena);
    while( it!=poc+n+1) {
        auto proizvod (ProduktMatrica(stepena,a));
        //sad vrijednosti polja matrice proizvod kopirat u stepenu i onda unistit proizvod
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                stepena.elementi[i][j]=proizvod.elementi[i][j];
            }
        }

        PomnoziSaSkalarom(proizvod,*it);
        auto zbir(ZbirMatrica(polinom,proizvod));

        UnistiMatricu(proizvod);//ne treba nam vise,ali ako je ne unistimo do kraja ovog bloka desit ce se curenje memorije jer bismo izgubili pok na din alociranu matricu
//sad kopiramo polja matrice zbir u matricu polinom
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                polinom.elementi[i][j]=zbir.elementi[i][j];
            }
        }

        UnistiMatricu(zbir);
        it++;
    }
    UnistiMatricu(stepena);
    return polinom;
}

int main()
{
    Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double>v(n+1);
        for(int i=0; i<n+1; i++) {
            std::cin>>v.at(i);

        }

        IspisiMatricu(MatricniPolinom(a,n,v.begin()),10,6,true);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error poruka) {
        std::cout<<poruka.what();
    }
    UnistiMatricu(a);

    return 0;
}