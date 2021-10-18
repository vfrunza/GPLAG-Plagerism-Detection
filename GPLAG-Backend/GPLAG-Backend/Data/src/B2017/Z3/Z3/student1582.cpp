/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica {
        int br_kolona, br_redova;
        TipElemenata **elementi=nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if (!mat.elementi)
            return;
        for (int i=0; i<mat.br_redova; i++)
            delete [] mat.elementi[i];
        delete [] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_kolona, int br_redova) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++) 
            mat.elementi[i]=nullptr;
        try {
            for (int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++)
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++)
                std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if (treba_brisati==true)
            UnistiMatricu(mat);
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i=0; i<m1.br_redova; i++)
            for (int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova != m2.br_kolona || m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m2.br_kolona; j++) {
                TipElemenata S;
                S=0;
                for (int k=0; k<m1.br_kolona; k++) {
                    S+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j]=S;
            }
        }
        return m3;
    }

template <typename TipElemenata, typename ItTip>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat, int n, ItTip it) {
        if (n<0)
            throw std::domain_error("Neispravan stepen polinoma");
        if (mat.br_redova!=mat.br_kolona)
            throw std::domain_error("Matrica mora biti kvadratna");
        auto Pn (StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        Matrica<TipElemenata> t;
        auto q=it;
        
        for (int i=0; i<=n; i++) {
            t=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
            for (int y1=0; y1<mat.br_redova; y1++)
                for (int y2=0; y2<mat.br_kolona; y2++)
                    t.elementi[y1][y2]=mat.elementi[y1][y2];
        
            if (i==0) {
                for (int y1=0; y1<mat.br_redova; y1++)
                    for (int y2=0; y2<mat.br_kolona; y2++) {
                        if(y1==y2) Pn.elementi[y1][y2]=1;
                        else Pn.elementi[y1][y2]=0;
                    }
                for (int c=0; c<mat.br_redova; c++) 
                    for (int x=0; x<mat.br_kolona; x++){
                        Pn.elementi[x][c]*=(*q);
                    }
                q++;
                UnistiMatricu(t);
            }
        
            if (i!=0) {
                if (i==1) {
                    for (int r1=0; r1<mat.br_redova; r1++) {
                        for (int r2=0; r2<mat.br_kolona; r2++) {
                            t.elementi[r1][r2]=(*q)*mat.elementi[r1][r2];
                        }
                    }
                    auto s=Pn;
                    Pn=ZbirMatrica(Pn, t);
                    q++;
                    UnistiMatricu(s);
                    UnistiMatricu(t);
                }
                else {
                    for (int v=2; v<=i; v++){
                        auto s=t;
                        t=ProduktMatrica(t, mat);
                        UnistiMatricu(s);
                    }
                    for (int e1=0; e1<mat.br_redova; e1++) {
                        for (int e2=0; e2<mat.br_kolona; e2++) {
                            t.elementi[e1][e2]=(*q)*(t.elementi[e1][e2]);
                        }
                    }
                    auto s=Pn;
                    Pn=ZbirMatrica(Pn, t);
                    q++;
                    UnistiMatricu(t);
                    UnistiMatricu(s);
                }
            }
        }
        return Pn;
    }
        

int main ()
{
    Matrica<double> a;
    int dimenzije;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzije;
    std::cout<<"Unesite elemente matrice A:\n";
    
    //try {
        a=StvoriMatricu<double>(dimenzije, dimenzije);
        UnesiMatricu('A', a);
    //}
    //catch(std::bad_alloc) {
      //  std::cout<<"Nema dovoljno memorije!"<<std::endl;
    //}
    
    
    int n;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>n;
    
    std::vector<double> koef;
    double temp;
    std::cout<<"Unesite koeficijente polinoma: ";
    for (int i=0; i<n+1; i++){
        std::cin>>temp;
        koef.push_back(temp);
    }
    
    auto P=MatricniPolinom(a, n, koef.begin());
    IspisiMatricu(P, 10, 6, false);
    UnistiMatricu(P);
    UnistiMatricu(a);
	return 0;
}
