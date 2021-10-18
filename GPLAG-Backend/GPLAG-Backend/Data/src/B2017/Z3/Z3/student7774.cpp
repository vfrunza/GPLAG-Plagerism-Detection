/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElementa>
struct Matrica {
    int br_redova;
    int br_kolona;
    TipElementa** elementi=nullptr;
};
template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat);

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi = new TipElementa* [br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElementa[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu(char ime, Matrica<TipElementa> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &a, const Matrica<TipElementa> &b)
{
    if(a.br_redova!=b.br_redova || a.br_kolona!=b.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
   
        auto m(StvoriMatricu<TipElementa>(a.br_redova, a.br_kolona));
        for(int i=0; i<a.br_redova; i++)
            for(int j=0; j<a.br_kolona; j++)
                m.elementi[i][j]=a.elementi[i][j]+b.elementi[i][j];
        return m;
    
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &a, const Matrica<TipElementa> &b)
{
    if(a.br_kolona!=b.br_redova) throw  std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m(StvoriMatricu<TipElementa>(a.br_redova, b.br_kolona));
    for(int i=0; i<a.br_redova; i++)
        for (int j=0; j<b.br_kolona; j++) {
            double suma=0;
            for(int k=0; k< b.br_redova; k++) suma+=a.elementi[i][k] * b.elementi[k][j];
            m.elementi[i][j]=suma;
        }
    return m;
}

template<typename TipElementa>
Matrica<TipElementa> SkalarniProdukt(const Matrica<TipElementa> &mat, double broj)
{
    auto m(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            m.elementi[i][j]=(mat.elementi[i][j] * broj);
    return m;
}

template<typename TipElementa>
Matrica<TipElementa> JedinicnaMatrica(int dimenzija)
{
    auto m(StvoriMatricu<TipElementa>(dimenzija, dimenzija));
    for(int i=0; i<dimenzija; i++)
        for(int j=0; j<dimenzija; j++) {
            if(i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
        }
    return m;
}


template<typename TipElementa, typename IterTip>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, int stepen, IterTip it)
{
    if(stepen<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");

    Matrica<TipElementa> m;
    try {
        

        Matrica<TipElementa> Jedinicna;

        try {
            Jedinicna=JedinicnaMatrica<TipElementa>(mat.br_redova);
            try {
                m=SkalarniProdukt<TipElementa>(Jedinicna, *it);
                it++;
            } catch(...) {
                UnistiMatricu(Jedinicna);
                throw;
            }
            UnistiMatricu(Jedinicna);
        } catch(...) {
            throw;
        }

        try {
            auto Produkt(SkalarniProdukt<TipElementa>(mat, *it));
            it ++;
            
            try {
                m=ZbirMatrica(m, Produkt);
            } catch(...) {
                UnistiMatricu(Produkt);
                throw;
            }
            UnistiMatricu(Produkt);
        } catch(...) {
            throw;
        }

    Matrica<TipElementa> mat_pomocna;
        try {
            mat_pomocna=StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona);
            for(int i=0; i<mat.br_redova; i++) {
                for(int j=0; j<mat.br_kolona; j++) {
                    mat_pomocna.elementi[i][j]=mat.elementi[i][j];
                }
            }
            for(int i=2; i<=stepen; i++) {
                try {
                    mat_pomocna=ProduktMatrica<TipElementa>(mat, mat_pomocna);
                } catch(...) {

                    throw;
                }
                Matrica<TipElementa> sprodukt;
                try {
                    sprodukt=SkalarniProdukt<TipElementa>(mat_pomocna, *it);
                    it++;
                    try {
                        
                        m=ZbirMatrica(m, sprodukt);
                    } catch(...) {
                        UnistiMatricu(sprodukt);

                        throw;
                    }

                    UnistiMatricu(sprodukt);
                } catch(...) {

                    throw;
                }
            }

            UnistiMatricu(mat_pomocna);


        } catch(...) {
            UnistiMatricu(mat_pomocna);
            throw;
        }


        return m;
    }

    catch(...) {
        UnistiMatricu(m);
        throw;
    }
}

template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost, bool treba_brisati)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) std::cout<< std::setw(sirina_ispisa) <<std::fixed<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) {
        UnistiMatricu(mat);
    }
}

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) {
        delete[] mat.elementi[i];
        mat.elementi[i]=nullptr;
    }
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

int main()
{
    int dim;
    Matrica<double> a,b;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dim;
    try {
        a=StvoriMatricu<double>(dim,dim);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A',a);
        int stepen;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>stepen;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v;
        int k;
        for(int i=0; i<=stepen; i++) {
            std::cin>>k;
            v.push_back(k);
        }

        try {
            IspisiMatricu(MatricniPolinom(a, stepen, v.begin()), 10, 0, true);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }

    } catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!";
    }
    UnistiMatricu(a);

    return 0;
}

/*int main_ ()
{
    Matrica<double> a,b,c,d;
    int n,m;
    std::cout<<"Unesite broj redova i kolona za matrice: ";
    std::cin>> n>> m;
    try {
        a=StvoriMatricu<double>(n,m);
        b=StvoriMatricu<double>(n,m);
        std::cout<<"Unesite matricu A: ";
        UnesiMatricu('A',a);
        std::cout<<"Unesite matricu B: ";
        UnesiMatricu('B',b);
        std::cout<<"Zbir ove dvije matrice je: ";
        IspisiMatricu(c=ZbirMatrica(a,b),7);
        IspisiMatricu(d=ProduktMatrica(a,b),7);

    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno prostora!";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    UnistiMatricu(d);
    return 0;
}*/
