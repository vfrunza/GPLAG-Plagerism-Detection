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
void UnistiMatricu (Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
    }
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            mat.elementi[i][j]=0;
        }
    }
    return mat;
}

template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
            for(int i=0;i<mat.br_redova;i++)
                for(int j=0;j<mat.br_kolona;j++){
                    std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                    std::cin>>mat.elementi[i][j];
                }
    }

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
         std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}


template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
 }


template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> &m1,Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> produkt;
    produkt=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            produkt.elementi[i][j]=0;
            for(int k=0;k<m1.br_kolona;k++){
                produkt.elementi[i][j]+=(m1.elementi[i][k])*(m2.elementi[k][j]);
            }
        }
    }
    return produkt;
}

template<typename TipElemenata>
void MnozenjeSkalarom(double skalar,Matrica<TipElemenata> &a){
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<a.br_kolona;j++){
            a.elementi[i][j]*=skalar;
        }
    }
}

template<typename TipElemenata>
void Dodjela(Matrica<TipElemenata> &a,Matrica<TipElemenata> &b){
    for(int i=0;i<a.br_kolona;i++){
        for(int j=0;j<a.br_kolona;j++) b.elementi[i][j]=a.elementi[i][j];
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &a,std::vector<double> v){
    if(a.br_kolona!=a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    if(v.size()==0){
        Matrica<TipElemenata> b;
        b=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
        return b;
    }

    Matrica<TipElemenata> b;
    b=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<a.br_kolona;j++){
            if(i==j) b.elementi[i][j]=1;
        }
    }
    MnozenjeSkalarom(v[0],b);
     Matrica<TipElemenata> c;
     c=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
     Dodjela(a,c);
     MnozenjeSkalarom(v[1],c);
     Matrica<TipElemenata> pom3;
     pom3=ZbirMatrica(c,b);//zbir prva dva elementa
     Dodjela(pom3,c);
     //std::cout<<std::endl;
       //  IspisiMatricu(c,10);
     UnistiMatricu(pom3);
     UnistiMatricu(b);
    Matrica<TipElemenata> pom;
     Matrica<TipElemenata> pom1;
      Matrica<TipElemenata> pom2;

    for(int i=2;i<v.size();i++){
            pom=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
            Dodjela(a,pom);
           for(int k=1;k<i;k++){
                pom1=ProduktMatrica(pom,a);
                Dodjela(pom1,pom);
                UnistiMatricu(pom1);
            }
        MnozenjeSkalarom(v[i],pom);
        pom2=ZbirMatrica(c,pom);
        Dodjela(pom2,c);
        UnistiMatricu(pom2);
        UnistiMatricu(pom);
    }

    return c;
}


int main ()
{
    Matrica<int> a,b;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    try{
        a=StvoriMatricu<int>(n,n);
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int m;
        std::cin>>m;
        std::cout<<"Unesite koeficijente polinoma: ";
        double koef;
        std::vector<double> v;
        for(int i=0;i<m+1;i++){
            std::cin>>koef;
            v.push_back(koef);
        } 
        //std::cout<<std::endl;
        b=MatricniPolinom(a,v);
        IspisiMatricu(b,10,6);
    }
     catch(std::bad_alloc) {
            std::cout << "Nema dovoljno memorije!\n";
        }
 UnistiMatricu(a); 
 UnistiMatricu(b);
 

 return 0;
}
