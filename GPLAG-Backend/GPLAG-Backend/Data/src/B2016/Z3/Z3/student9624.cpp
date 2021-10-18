/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>


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
                   int sirina_ispisa, int preciznost = 6 , bool treba_brisati = false )
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;

    }
    if(treba_brisati == true ) UnistiMatricu(mat);
}


template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int k = 0; k < m1.br_kolona; k++) {
            int suma(0);
            for(int j = 0; j < m1.br_kolona; j++) {
                suma = suma+  m1.elementi[i][j]*m2.elementi[j][k];

            }
            m3.elementi[i][k] = suma ;
        }
    }

    return m3;
}


template <typename TipElemenata>
void IskopirajMatricu(Matrica<TipElemenata> &m1 ,const Matrica<TipElemenata> &m2)
{
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] = m2.elementi[i][j];
}


template <typename TipElemenata>
void IzmnoziSaberi ( Matrica<TipElemenata> &m1, const  Matrica<TipElemenata> &m2, double k){
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
        m1.elementi[i][j] += m2.elementi[i][j]*k;
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
void NulaMatrica(Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
        {
            mat.elementi[i][j]=0;
        }
}

template <typename TipElemenata>
void Jedinicna(Matrica<TipElemenata> &mat, double k){
     for (int i = 0 ; i < mat.br_redova ; i++ ) {
            for (int j = 0 ; j < mat.br_kolona ; j++ ) {
                if(i == j) mat.elementi[i][j]=1*k;
                else mat.elementi[i][j]=0;
            }

        }
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, std::vector<double> v)
{
    if(m1.br_kolona != m1.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
 auto suma (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    if(v.size()==0) {
        NulaMatrica(suma);
        return suma;
    }

     Jedinicna(suma,v[0]);



        Matrica<TipElemenata> stepena , pomocna;

        try {
            stepena = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
            IskopirajMatricu(stepena, m1);
        } catch(...) {
            UnistiMatricu(suma);
            throw;
        }
        int k(2);
        try {

            if(v.size()==1) return suma;
            if(v.size()==2) {

                IzmnoziSaberi(suma,m1,v[1]);
                return suma;
            }
            else if(v.size()>2) {
             IzmnoziSaberi(suma,m1,v[1]);
                while(k<v.size()){
                    pomocna=stepena;
                    stepena=ProduktMatrica(stepena,m1);
                  IzmnoziSaberi(suma,stepena,v[k]);

                    UnistiMatricu(pomocna);
                    k++;
                }
            }
        }
        catch(...) {
           UnistiMatricu(pomocna);
        }
       UnistiMatricu(stepena);






        return suma;
    }
    int main() {
        Matrica<double> a,c; // AUTOMATSKA INICIJALIZACIJA!!!
        int m;
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        std::cin >> m ;
        try {
            a = StvoriMatricu<double>(m, m);
            std::cout << "Unesite elemente matrice A: \n";
            UnesiMatricu('A', a);
            std::cout << "Unesite red polinoma: ";
            int red;
            std::cin>>red;
            std::vector<double> k;
            std::cout << "Unesite koeficijente polinoma: ";
            for(int i = 0 ; i <= red ; i++ ) {
                double x;
                std::cin>>x;
                k.push_back(x);
            }
            try{

                 c=MatricniPolinom(a,k);
                 IspisiMatricu(c,10);
            }
             catch(std::domain_error d)
        {
            std::cout<<d.what()<<std::endl;
        }
        } catch(std::bad_alloc) {
            std::cout << "Nema dovoljno memorije!\n";
        }
        UnistiMatricu(a);
        UnistiMatricu(c);

        return 0;
    }