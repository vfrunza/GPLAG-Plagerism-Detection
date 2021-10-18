/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <vector>
#include <iomanip>


template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata* [br_redova];
    for( int i = 0; i < br_redova; i++) mat.elementi [i] = nullptr;
    try {
        for( int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata [br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata>&mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i + 1<<","<<j + 1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata>&mat, int sirina_ispisa, int preciznost = 6, bool treba_ispisati = false)
{
    for( int i = 0; i < mat.br_redova; i++) {
        for ( int j = 0; j < mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_ispisati) UnistiMatricu(mat);
    else return;
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata>&m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for( int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona)); // elementi nisu inicijalizirani, moraju se postaviti na nulu
    for(int i = 0; i < m3.br_redova; i++) {
        for(int j = 0; j < m3.br_kolona; j++) {
            m3.elementi[i][j] = 0;
        }
    }
    for (int i = 0; i < m1.br_redova; i++)
        for ( int j = 0; j < m2.br_kolona; j++)
            for( int k = 0; k < m1.br_kolona; k++)
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    return m3;
}

template <typename TipElemenata>//Nula matrica za A^0
Matrica<TipElemenata>NulaMatrica(const Matrica<TipElemenata> &m)
{
    Matrica<TipElemenata>nula;
    try {
        nula = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    } catch(...) {
        throw;
    }
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j< m.br_kolona; j++) {
            nula.elementi[i][j] = 0;
        }
    }
    return nula;
}

template <typename TipElemenata>
void Anuliraj(Matrica<TipElemenata> mat)
{
    for ( int i = 0; i < mat.br_redova; i++) {
        for ( int j = 0; j < mat.br_kolona; j++) {
            mat.elementi[i][j] = 0;
        }
    }
}

template <typename TipElemenata>
void UciniJedinicnom(Matrica<TipElemenata> mat)
{
    for ( int i = 0; i < mat.br_redova; i++) {
        for ( int j = 0; j < mat.br_kolona; j++) {
            if( i == j ) mat.elementi[i][j] = 1;
            else mat.elementi[i][j] = 0;
        }
    }
}

template <typename TipElemenata>
Matrica<TipElemenata>JedinicnaMatrica(const Matrica<TipElemenata>&m)
{
    Matrica<TipElemenata>jedinicna;
    try {
        jedinicna = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    } catch(...) {
        throw;
    }
    for(int i = 0; i < m.br_redova; i++) {
        for ( int j = 0; j < m.br_kolona; j++) {
            if ( i == j ) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0; // u suprotnom neće biti inicijalizirani elementi uopće
        }
    }
    return jedinicna;
}

template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatKoef(Matrica<TipElemenata>m, double k)
{
    Matrica<TipElemenata> mat;
    try {
        mat = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    } catch(...) {
        throw;
    }
    for( int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_kolona; j++) {
            mat.elementi[i][j] = k * m.elementi[i][j];
        }
    }
    return mat;
}

/*template <typename TipElemenata>
void MnozenjeMatriceSkalarom (Matrica<TipElemenata> m, double k)
{
    for( int i = 0; i < m.br_redova; i++) {
        for ( int j = 0; j < m.br_kolona; j++) {
            m.elementi[i][j] *= k;
        }
    }
}*/
template <typename TipElemenata, typename TipIter>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata>&m1, int n, TipIter it )
{
    if ( n < 0 ) throw std::domain_error ("Neispravan stepen polinoma");
    if (m1.br_kolona != m1.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<TipElemenata>MP;
    Matrica<TipElemenata>jedinicna,bezze;
    try {
        MP = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        jedinicna = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    } catch(...) {
        UnistiMatricu(MP); 
        throw;
    }
    UciniJedinicnom(jedinicna);
    Anuliraj(MP);
    for ( int i = 0; i <= n; i++) {
        if ( i == 0 ) {
            auto pomocna (MP);
            auto produkt (ProduktMatKoef(jedinicna, (*it)));
            try{
            MP = ZbirMatrica(MP, produkt);
            }
            catch(...){
                UnistiMatricu(MP);
            }
            UnistiMatricu(pomocna);
            UnistiMatricu(produkt);
            it++;
            continue;
        }
        if ( i == 1 ) {
            auto pomocna (MP);
            auto produkt ( ProduktMatKoef(m1, (*it)));
            try{
            MP = ZbirMatrica(MP, produkt);
            }
            catch(...){
                UnistiMatricu(MP);
            }
            UnistiMatricu(pomocna);
            UnistiMatricu(produkt);
            it++;
            continue;
        }
        auto produkt (ProduktMatrica(jedinicna, m1));
        for(int j = 1; j < i ; j++ ) {
            auto pomocna (produkt);
            try{
            produkt = ProduktMatrica(produkt,m1);
            }
            catch(...){
                UnistiMatricu(produkt);
            }
            UnistiMatricu(pomocna);
        }
        auto pomocna (MP);
        auto produkt1 (ProduktMatKoef(produkt, *it));
        try{
        MP = ZbirMatrica(MP, produkt1);
        }
        catch(...){
            UnistiMatricu(MP);
        }
        UnistiMatricu(pomocna);
        UnistiMatricu(produkt);
        UnistiMatricu(produkt1);
        it++;
    }
    UnistiMatricu(jedinicna);
    return MP;
}


int main ()
{
    Matrica<double>a,pol;
    try {
        int d;
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        std::cin>>d;
        a = StvoriMatricu<double>(d,d);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::vector<double>v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for (int i = 0; i <= n ; i++) {
            double k;
            std::cin>>k;
            v.push_back(k);
        }
        pol = MatricniPolinom(a,n,v.begin());
        IspisiMatricu(pol,10);

    } catch(std::logic_error) {
        std::cout<<"Problem s memorijom";
    }
    UnistiMatricu(a);
    UnistiMatricu(pol);
    return 0;
}