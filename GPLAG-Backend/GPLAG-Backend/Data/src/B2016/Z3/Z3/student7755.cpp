/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template<typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++)
    delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona) {
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i=0;i<mat.br_redova;i++)
     for(int j=0;j<mat.br_kolona;j++) {
         std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
         std::cin>>mat.elementi[i][j];
     }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati==true) {
        UnistiMatricu(mat);
    }
}
template<typename TipElemenata>
Matrica<TipElemenata> Postavi(const Matrica<TipElemenata> &mat) {
    Matrica<TipElemenata>m(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));

    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            m.elementi[i][j]=0;
        }
    }
    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            if(i==j) {
                m.elementi[i][j]=1;
            }
        }
    }
    return m;

}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
     for(int j=0;j<m1.br_kolona;j++)
     m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
     return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> &mat1,Matrica<TipElemenata> &mat2) {
    Matrica<TipElemenata>prodmat(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    if(mat1.br_kolona!=mat2.br_redova) {
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    for(int i=0;i<mat1.br_redova;i++)
       for(int j=0;j<mat2.br_kolona;j++) {
           TipElemenata suma(0);
           for(int k=0;k<mat2.br_redova;k++)
           suma+=mat1.elementi[i][k] * mat2.elementi[k][j];
           prodmat.elementi[i][j]=suma;
       }
       return prodmat;
}
template<typename  TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom(Matrica<TipElemenata>mat,double n) {
    Matrica<TipElemenata>m(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            m.elementi[i][j]=n*mat.elementi[i][j];
        }
    }
    return m;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, std::vector<double> v) {
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>matricnipolinom;
    Matrica<TipElemenata>pomocna;
    Matrica<TipElemenata>pomocna1;
    Matrica<TipElemenata>pomocna2;
    pomocna1=mat;
    Matrica<TipElemenata>jedinicna=Postavi(mat);
    matricnipolinom=MnozenjeSkalarom(jedinicna,v[0]);
    if(v.size()==1) {
        return matricnipolinom;
    }
    for(int i=1;i<v.size();i++) {
        pomocna2=MnozenjeSkalarom(pomocna1,v[i]);
        matricnipolinom=ZbirMatrica(matricnipolinom,pomocna2);
        pomocna1=mat;
        for(int j=0;j<i;j++) {
            pomocna=ProduktMatrica(pomocna1,mat);
            pomocna1=pomocna;
        }
    }
    UnistiMatricu(pomocna);
    UnistiMatricu(pomocna1);
    UnistiMatricu(pomocna2);


return matricnipolinom;
}
int main ()
{
    try {
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    auto  b=StvoriMatricu<double>(m,m);
     std::cout<<"Unesite elemente matrice A: "<<std::endl;
     UnesiMatricu('A',b);
     //a=Postavi(b);
     int n;
     std::cout<<"Unesite red polinoma: ";
     std::cin>>n;
     std::cout<<"Unesite koeficijente polinoma: ";
     std::vector<double>v;
     for(int i=0;i<n+1;i++) {
         double broj;
         std::cin>>broj;
         v.push_back(broj);
     }
     IspisiMatricu(MatricniPolinom(b,v),10,5,true);
     UnistiMatricu(b);
    }
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }



	return 0;
}