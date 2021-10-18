/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica{
  int br_redova,br_kolona;
  TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat) {
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=nullptr;
    try {
        mat.elementi=new TipElemenata*[br_redova];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    for(int i=0;i<br_redova;i++) {
        mat.elementi[i]=nullptr;
    }
    try{
        for(int i=0;i<br_redova;i++) {
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat) {
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat,int sirina,int preciznost=6,bool treba_brisati=true) {
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<std::setw(sirina)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;j<m1.br_kolona;j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1,Matrica<TipElemenata> m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto mat=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;j<m2.br_kolona;j++) {
            TipElemenata suma{};
            for(int k=0;k<m1.br_kolona;k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            mat.elementi[i][j]=suma;
        }
    }
    return mat;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat,std::vector<double> p) {
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    auto m=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    if(p.size()==0) return m;
    auto produkt=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i=0;i<produkt.br_redova;i++) {
        for(int j=0;j<produkt.br_kolona;j++) {
            if(i==j) produkt.elementi[i][j]=1;
            else produkt.elementi[i][j]=0;
        }
    }
    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            m.elementi[i][j]=0;
        }
    }
    auto pomocna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i=0;i<=p.size()-1;i++) {
        for(int j=0;j<pomocna.br_redova;j++) {
            for(int k=0;k<pomocna.br_kolona;k++) {
                pomocna.elementi[j][k]=p[i]*produkt.elementi[j][k];
            }
        }
        m=ZbirMatrica(m,pomocna);
        produkt=ProduktMatrica<TipElemenata>(produkt,mat);
    }
    UnistiMatricu(produkt);
    UnistiMatricu(pomocna);
    return m;
}
int main ()
{
    int dim;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dim;
    Matrica<double> a,b;
    try{
        a=StvoriMatricu<double>(dim,dim);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> vektor_koef(n+1);
        for(int i=0;i<=n;i++) std::cin>>vektor_koef[i];
        auto polinom=MatricniPolinom<double>(a,vektor_koef);
        IspisiMatricu(polinom,10,5,true);
    }
    catch(...) {
        return 0;
    }
	return 0;
}