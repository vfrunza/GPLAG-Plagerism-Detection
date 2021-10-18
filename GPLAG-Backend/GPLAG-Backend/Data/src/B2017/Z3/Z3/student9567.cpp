#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <list>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat)
{
    if (!mat.elementi) return;
    for (int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;

    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata * [br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]= nullptr;
    try {
        for (int i=0; i< br_redova; i++)
            mat.elementi [i]= new TipElemenata[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriJedinicnuMatricu (int br_redova, int br_kolona)
{
    auto  mat=StvoriMatricu<double>(br_redova,br_kolona);
 
    for (int i=0; i<br_redova; i++) {
        for (int j=0; j<br_kolona; j++) {
            if (i==j) {
                mat.elementi[i][j]=1;
                continue;
            }
            mat.elementi[i][j]=0;
        }
    }
    return mat;
}

template <typename TipElemenata>
void SkalarM (Matrica<TipElemenata> &mat, double skalar)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            mat.elementi[i][j]*=skalar;
        }
    }

}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout<< ime_matrice <<"("<<i+1 <<","<<j+1<<") = ";
            std::cin >> mat.elementi [i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &a, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{

    for (int i(0); i<a.br_redova; i++) {
        for (int j=0; j<a.br_redova; j++) {
            std::cout<< std::setw(sirina_ispisa)<<std::setprecision(preciznost)<< a.elementi[i][j];
        }
        std::cout << std::endl; 
    }
       if (treba_brisati) {
            UnistiMatricu (a);
        }  
     
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova!= m2.br_redova || m1.br_kolona!= m2.br_kolona) {
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    }
    auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for (int i(0); i<m1.br_redova; i++) {
        for (int j(0); j<m1.br_kolona; j++) {
            m3.elementi [i][j]= m1.elementi[i][j]+ m2.elementi [i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova!=m2.br_kolona ) throw std::domain_error ("Matrice nisu saglasne za mnozenje");

    auto m3 (StvoriMatricu <TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i(0); i< m1.br_redova; i++) {
        for (int j(0); j< m2.br_kolona; j++) {
            double suma(0);
            for (int k(0); k<m2.br_redova; k++) suma+= m1.elementi[i][k]* m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata>
void  Prekopiraj ( Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    for (int i(0); i<m1.br_redova; i++) {
        for (int j(0); j<m1.br_kolona; j++) {
            m1.elementi [i][j]= m2.elementi [i][j];
        }
    }
}


template <typename TipElemenata, typename Iter>
Matrica <TipElemenata> MatricniPolinom ( Matrica<TipElemenata> &m1, int n, Iter it)
{

    if (m1.br_kolona != m1.br_redova) throw std::domain_error ("Matrica mora biti kvadratna.");
    if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
    
    auto SMatrica (StvoriMatricu <TipElemenata> (m1.br_redova, m1.br_kolona));
    auto JMatrica (StvoriJedinicnuMatricu <TipElemenata> (m1.br_redova, m1.br_kolona));
    auto Kopija (StvoriJedinicnuMatricu <TipElemenata> (m1.br_redova, m1.br_kolona));
    Prekopiraj <TipElemenata>(Kopija, m1 );
    Prekopiraj <TipElemenata> (SMatrica, m1 );

    for (int i(0); i<=n; i++) {
        if (i==0) {
            double skalar= *it;
            SkalarM (JMatrica, skalar);
            auto pom(m1);
            m1=JMatrica;
            UnistiMatricu(pom);
            it++;
        }

       else {
            int vr=i-1;
            for (int j(0); j<vr; j++) {
                auto Pomocni(SMatrica);
                SMatrica= ProduktMatrica  (SMatrica, Kopija);
                UnistiMatricu(Pomocni);
            }
            double skalar=*it;
            SkalarM  (SMatrica, skalar);
            auto NPomocni(m1);
            m1= ZbirMatrica  (m1, SMatrica);
            UnistiMatricu(NPomocni);
            it++;
            
            Prekopiraj (SMatrica, Kopija );
            }  
    }
    UnistiMatricu (Kopija);
    UnistiMatricu(SMatrica);

    return m1;
}



int main ()
{
    Matrica<double> a;
    int m,n;
    std::cout<< "Unesite dimenziju kvadratne matrice: ";
    std::cin>> m;
    try {
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu ('A', a);
        std::cout<< "Unesite red polinoma: ";
        std::cin>> n;
        std::list <int> v ;
        int size= n+1;
        std::cout<< "Unesite koeficijente polinoma: ";
        for (int i(0); i<size; i++) {
            int unos;
            std::cin>>unos;
            v.push_back (unos);
        }
       
        MatricniPolinom (a,n,v.begin());
      IspisiMatricu (a,10,5,true);
        
    }

    catch (std::bad_alloc) {
        std::cout<< "Nema dovoljno memorije!\n";
    }
   
     if (!a.elementi) UnistiMatricu(a); 
      
    
    return 0;
}
