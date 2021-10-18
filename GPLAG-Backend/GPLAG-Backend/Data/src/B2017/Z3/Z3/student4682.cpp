/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <vector>

using std::cin;
using std::cout;

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
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename tip>
void UnesiMatricu(char ime, Matrica<tip> &mat) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}


template <typename tip>
void IspisiMatricu(const Matrica<tip> &mat, int sirina_ispisa, int preciznost=6, bool brisanje=false) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        }
        cout<<std::endl;
    }
    if(brisanje) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova;i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename tip>
Matrica<tip> ProduktMatrica(Matrica<tip> mat1, Matrica<tip> mat2) {
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<tip> povratna(StvoriMatricu<tip>(mat1.br_redova, mat2.br_kolona));
    for(int i=0; i<mat1.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            tip suma{};
            for(int k=0; k<mat2.br_redova; k++) {
                suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            }
            povratna.elementi[i][j]=suma;
        }
    }
    return povratna;
}

template <typename tip, typename tip2>
void PomnoziBrojem(Matrica<tip> &mat, tip2 broj) {
    for(int i=0; i<mat.br_redova; i++)  {
        for(int j=0; j<mat.br_kolona; j++) {
            mat.elementi[i][j]*=broj;
        }
    }
}

template <typename tip>
Matrica<tip> Jedinicna(Matrica<tip> mat) {
    auto povratna(StvoriMatricu<tip>(mat.br_redova, mat.br_redova));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_redova; j++) {
            if(i==j) povratna.elementi[i][j]=1;
            else povratna.elementi[i][j]=0;
        }
    }
    return povratna;
}

template <typename tip, typename tip_pok>
Matrica<tip> MatricniPolinom(Matrica<tip> mat, int stepen, tip_pok p) {
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica nije kvadratna");
    if(stepen<0) throw std::domain_error("Neispravan stepen polinoma");
    auto povratna(StvoriMatricu<tip>(mat.br_redova, mat.br_kolona));
    auto jedinicna(StvoriMatricu<tip>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
         for(int j=0; j<mat.br_redova; j++) {
            povratna.elementi[i][j]=0;
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
         }
    }
   // IspisiMatricu(povratna, 3);
    
    //IspisiMatricu(pom, 3);
    
    //IspisiMatricu(jedinicna, 3);
    for(int i=0; i<=stepen; i++, p++) {
        
            auto pom(StvoriMatricu<tip>(mat.br_redova, mat.br_kolona));
            for(int i=0; i<mat.br_redova; i++) {
                for(int j=0; j<mat.br_kolona; j++) {
                    pom.elementi[i][j]=jedinicna.elementi[i][j];
                }
            }
            PomnoziBrojem(pom, *p);
            //IspisiMatricu(jedinicna, 3);
           // auto pom3=StvoriMatricu(mat.br_redova, mat.br_kolona);
            auto pom3=ZbirMatrica(povratna, pom);
            UnistiMatricu(pom);
            pom=ProduktMatrica(jedinicna,mat);
            UnistiMatricu(jedinicna);
            jedinicna=pom;
            UnistiMatricu(povratna);
            povratna=pom3;
        
    }
    UnistiMatricu(jedinicna);
    return povratna;
}

int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";//
    int n;
    cin>>n;
    cout<<"Unesite elemente matrice A:"<<std::endl;
     try {
        auto matA(StvoriMatricu<double>(n,n));
        UnesiMatricu('A', matA);
        cout<<"Unesite red polinoma: ";
        std::vector<double> koeficijenti;
        double vel, broj;
        cin>>vel;
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=vel; i++) {
            cin>>broj;
            koeficijenti.push_back(broj);
        }
        auto mat_polinom(MatricniPolinom(matA,vel, koeficijenti.begin() ));
        IspisiMatricu(mat_polinom, 10, 6, true);
        UnistiMatricu(matA);
    }

    
    catch(std::domain_error izuzetak) {
        cout<<izuzetak.what();
    }
	return 0;
}
