/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include<vector>
template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) {
        return;
    }
    for(int i=0; i<mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) {
        mat.elementi[i]=nullptr;
    }
    try {
        for(int i= 0; i<br_redova; i++) {
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
    } catch(...) {
        UnistiMatricu (mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata>&mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) <<mat.elementi[i][j] ;
        }
        std::cout << std::endl;

    }
    if(treba_brisati) {
        UnistiMatricu(mat);
    }

}

template<typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona  ) {
        throw std:: domain_error("Matrice nemaju jednake dimenzije!");
    }
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i< m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2)
{
    if(m1.br_kolona!=m2.br_redova  ) {
        throw std:: domain_error("Matrice nisu saglasne za mnozenje");
    }
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));

    for(int i=0; i< m1.br_redova; i++) { // sve elemente matrice postavljamo na nula;
        for(int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
        }
    }
    for(int i=0; i< m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            for(int k=0; k<m1.br_kolona; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata>mnozenje (double x, const Matrica<TipElemenata>&y)
{
    auto z (StvoriMatricu<TipElemenata>(y.br_redova,y.br_kolona));
    for(int i=0; i< y.br_redova; i++) {
        for(int j=0; j<y.br_kolona; j++) {
            z.elementi[i][j]=y.elementi[i][j] *x;
        }
    }
    return z;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom ( const Matrica<TipElemenata>&A,std::vector<double>&koeficijenti )
{
    if(A.br_kolona!=A.br_redova) {
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    if(koeficijenti.size()==0) {
        auto rez ( StvoriMatricu<TipElemenata>(A.br_kolona,A.br_redova) );
        for(int j=0; j< A.br_redova; j++) {
            for(int k=0; k<A.br_kolona; k++) {
                rez.elementi[j][k]=0;
            }
        }
        return rez;
    }
    std::vector<Matrica<TipElemenata>>vektor_matrica ;
    std::vector<Matrica<TipElemenata>>vektor_matrica2 ;

    for(int i=0; i<koeficijenti.size(); i++) {
        if(i==0) {
            auto jedinicna_matrica (StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
            for(int j=0; j< A.br_redova; j++) {
                for(int k=0; k<A.br_kolona; k++) {
                    if(j==k) {
                        jedinicna_matrica.elementi[j][k]=1;
                    } else {
                        jedinicna_matrica.elementi[j][k]=0;
                    }
                }
            }
            vektor_matrica.push_back( mnozenje(koeficijenti[i],jedinicna_matrica)  );
            UnistiMatricu(jedinicna_matrica);
        }

        else if(i==1) {
            vektor_matrica2.push_back(A);
            vektor_matrica.push_back( mnozenje(koeficijenti[i],A)  );
        } else {
            vektor_matrica2.push_back(ProduktMatrica(A,vektor_matrica2[i-2]));
            vektor_matrica.push_back(mnozenje(koeficijenti[i],vektor_matrica2[i-1]));
        }
    }
    std::vector<Matrica<TipElemenata>>konacni;

    for(int i=0; i<vektor_matrica.size()-1; i++) {
        if(i==0) {
            konacni.push_back(ZbirMatrica(vektor_matrica[i],vektor_matrica[i+1]));
        } else {
            konacni.push_back(ZbirMatrica(vektor_matrica[i+1], konacni[i-1]));
        }
    }
    for(int i=0; i<vektor_matrica.size(); i++) { // oslobadjanje zauzete memorije!
        UnistiMatricu(vektor_matrica[i]);
    }
    for(int i=1; i<vektor_matrica2.size(); i++) {
        UnistiMatricu(vektor_matrica2[i]);
    }
    for(int i=0; i<konacni.size()-1; i++) { // ne oslobadjamo zadnji element vektora konacni, jer funkcija vraca taj elem. kao rezultat.
        UnistiMatricu(konacni[i]);
    }
    return konacni[konacni.size()-1];
}

int main ()
{
    Matrica<double> a,c;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a=StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A',a);
        std::cout << "Unesite red polinoma: ";
        int n(0);
        std::cin >> n;
        std::vector<double>vek ;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++) {
            double koef(0);
            std::cin >> koef;
            vek.push_back(koef);
        }
        IspisiMatricu(c=MatricniPolinom(a,vek),10);
    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}
