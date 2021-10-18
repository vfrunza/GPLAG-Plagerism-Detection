/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    try {
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i] =nullptr;
        for(int i=0; i<br_redova; i++)
        mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i=0; i<mat.br_redova; i++)
    for(int j=0; j<mat.br_kolona; j++) {
        std::cout<<ime_matrice
        <<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost=6, bool treba_bristi=false) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_bristi) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!= m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
 for(int i=0; i<m3.br_redova; i++)
 for(int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=0;
 
 
 for(int i=0; i<m3.br_redova; i++) {
     for(int j=0; j<m3.br_kolona; j++) {
         for(int k=0; k<m1.br_kolona; k++)
         m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
     }
 }
 return m3;
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, Tip p) {
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<m.br_redova; i++)
    for(int j=0; j<m.br_kolona; j++) m.elementi[i][j]=0;
    for(int k=0; k<=n; k++) {
        if(k==0) {
            auto temp(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
            for(int i=0; i<mat.br_redova; i++) {
                for(int j=0; j<mat.br_kolona; j++) {
                    if(i==j) temp.elementi[i][j]=1;
                    else temp.elementi[i][j]=0;
                }
            }
            for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) m.elementi[i][j]+= *p * temp.elementi[i][j];
            p++;
            UnistiMatricu(temp);
        }
        else if(k==1) {
            auto temp(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
            for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) temp.elementi[i][j]=mat.elementi[i][j];
            for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) m.elementi[i][j]+= *p * temp.elementi[i][j];
            p++;
            UnistiMatricu(temp);
        }
        else {
            auto temp(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
            for(int m=0; m<mat.br_redova; m++)
            for(int n=0; n<mat.br_kolona; n++) temp.elementi[m][n]=mat.elementi[m][n];
            for(int z=1; z<k; z++) {
                auto pomocna(ProduktMatrica(temp,mat));
                for(int m=0; m<mat.br_redova; m++)
                for(int n=0; n<mat.br_kolona; n++) temp.elementi[m][n]=pomocna.elementi[m][n];
                UnistiMatricu(pomocna);
            }
            for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) m.elementi[i][j]+= *p * temp.elementi[i][j];
            p++;
            UnistiMatricu(temp);
            }
    }
    return m;
}


int main ()
{
    int dim;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dim;
    Matrica<double> a,c;
    try {
        a=StvoriMatricu<double>(dim,dim);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        int n;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::vector<double> v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++) {
            double broj;
                std::cin>>broj;
                v.push_back(broj);
        }
        IspisiMatricu(MatricniPolinom(a,n,v.begin()), 10,5,true);
    }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); 
    
	return 0;
}
