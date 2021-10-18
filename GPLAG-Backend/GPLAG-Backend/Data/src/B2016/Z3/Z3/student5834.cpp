/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<vector>
#include<stdexcept>
#include<new>
template <typename tip>
struct Matrica{
    int br_redova,br_kolona;
    tip **elementi=nullptr;
};
template <typename tip>
void UnistiMatricu(Matrica<tip> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename tip>
Matrica<tip> StvoriMatricu(int n,int m){
    Matrica<tip> mat;
    mat.br_redova=n;
    mat.br_kolona=m;
    mat.elementi=nullptr;
    try{
    mat.elementi=new tip *[n];
    }
    catch(...){
        mat.elementi=nullptr;
        throw;
    }
    for(int i=0;i<n;i++)
        mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<n;i++)
            mat.elementi[i]=new tip [m];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename tip>
void UnesiMatricu(char ime,Matrica<tip> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename tip>
Matrica<tip> ProduktMatrica(const Matrica<tip> &a,const Matrica<tip> &b){
    if(a.br_kolona!=b.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto rez(StvoriMatricu<tip>(a.br_redova,b.br_kolona));
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<b.br_kolona;j++)
            rez.elementi[i][j]=0;
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<b.br_kolona;j++)
            for(int k=0;k<a.br_kolona;k++)
                rez.elementi[i][j]+=a.elementi[i][k]*b.elementi[k][j];
    return rez;
}
template <typename tip>
Matrica<tip> kreirajjedinicnu(int n){
    Matrica<tip> rez=StvoriMatricu<tip>(n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                rez.elementi[i][j]=1;
            else
                rez.elementi[i][j]=0;
        }
    }
    return rez;
    
}
template <typename tip,typename tip2>
Matrica<tip> pomnozibrsmat(tip2 x,const Matrica<tip> &mat){
    auto m3(StvoriMatricu<tip>(mat.br_redova, mat.br_kolona));
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            m3.elementi[i][j]=mat.elementi[i][j]*x;
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename tip>
void kopiraj(Matrica<tip> &uovu,Matrica<tip> izove){
    for(int i = 0; i < izove.br_redova; i++) 
        for(int j = 0; j < izove.br_kolona; j++)
            uovu.elementi[i][j]=izove.elementi[i][j];
}
template <typename tip>
Matrica<tip> MatricniPolinom(const Matrica<tip> &mat,const std::vector<double> polinom){
    auto jedinicna=kreirajjedinicnu<tip>(mat.br_kolona);
    Matrica<tip> rez=StvoriMatricu<tip>(mat.br_redova,mat.br_kolona);
    Matrica<tip> pom=pomnozibrsmat(polinom[0],jedinicna);
    Matrica<tip> pom2,pom3;
    
    kopiraj(rez,pom);
   // rez=pom;
    Matrica<tip> stepenamat=StvoriMatricu<tip>(mat.br_redova,mat.br_kolona);
    kopiraj(stepenamat,mat);
    UnistiMatricu(pom);
    for(int i=1;i<polinom.size();i++){
        if(i==1){
            pom=pomnozibrsmat(polinom[i],mat);
            pom2=ZbirMatrica(pom,rez);
            kopiraj(rez,pom2);
            UnistiMatricu(pom);
            UnistiMatricu(pom2);
        }
        else{
     
        pom=pomnozibrsmat<tip>(polinom[i],pom3=ProduktMatrica(stepenamat,mat));
        pom2=ZbirMatrica(pom,rez);
        kopiraj(rez,pom2);
        //rez=pom2;
        kopiraj(stepenamat,pom3);
        //stepenamat=pom3;
        
        UnistiMatricu(pom3);
        UnistiMatricu(pom);
        UnistiMatricu(pom2);
        }
    }
   // UnistiMatricu(pom);
    UnistiMatricu(jedinicna);
    UnistiMatricu(stepenamat);
    return rez;
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=10,int preciznost=6, bool treba_brisati=false){
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}

int main ()
{
  Matrica<double> a,rez;
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
        a=StvoriMatricu<double>(n,n);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int redpolinoma;
        std::cin>>redpolinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> polinom;
        for(int i=0;i<=redpolinoma;i++){
            double x;
            std::cin>>x;
            polinom.push_back(x);
        }
         rez=MatricniPolinom(a,polinom);
        bool treba_brisati=false;
        IspisiMatricu(rez,10,6,treba_brisati);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!"<<std::endl;
    }
    
    UnistiMatricu(a);
    UnistiMatricu(rez);
	return 0;
}