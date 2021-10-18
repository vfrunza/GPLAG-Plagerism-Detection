/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
template <typename TipElemenata>

 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
void UnistiMatricu(Matrica <TipElemenata> m){
    if(!m.elementi) return;
    for(int i=0;i<m.br_redova;i++) delete[]m.elementi[i];
    delete[]m.elementi;
    m.elementi=nullptr;
}

template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> m;
    m.br_redova=br_redova; m.br_kolona=br_kolona;
    m.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) m.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
            m.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(m);
        throw;
    }
    
    return m;
}


template <typename TipElemenata>
void UnesiMatricu(char ime_m, Matrica <TipElemenata> &m){
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            std::cout<<ime_m<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>m.elementi[i][j];
        }
    }
}

template <typename TipElemenata>

Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    
    if(m1.br_kolona!=m2.br_redova)  throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> nova_m=StvoriMatricu(m1.br_kolona,m2.br_kolona);
    int z(0);
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_redova;j++){
            z+=m1.elementi[i][j]*m2.elementi[j][i];
        }
        nova_m=z;
    }
    
    return nova_m;
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A,std::vector<double> v){
    
    Matrica<TipElemenata> mat_polinom(StvoriMatricu(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> pom(StvoriMatricu(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> proizvod(StvoriMatricu(A.br_redova,A.br_kolona));
    int jedan(1),nula(0);
    
    //Jedinicna matrica
    for(int i=0;i<A.br_redova;i++){
        for(int j=0;j<A.br_kolona;j++){
            if(i==j)    pom.elementi[i][j]=jedan;
            else        pom.elementi[i][j]=nula;
            }
    }
    
    int br(0),kolona(0),red(0);
    
    while(br<v.size()){
    for(int i=0;i<A.br_redova;i++){
         for(int j=0;j<A.br_kolona;j++){
            auto p=ProduktMatrica(A,pom);
            pom=p;
            proizvod.elementi[i][j]=v[i]*pom.elementi[i][j];
        }
    }     auto z=ZbirMatrica(mat_polinom,proizvod);
          mat_polinom=z;
       br++;    
    }
    
   UnistiMatricu(pom);
 
    return mat_polinom;
    
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &m,int preciznost=6,bool treba_brisati=false){
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            std::cout<<std::setw(preciznost)<<m.elementi[i][j];
        }
    }
    
    if(treba_brisati)   UnistiMatricu(m);
    
}


int main ()
{
    int kolone, redovi;
    std::cout<<"Unesite broj redova i kolona matrice: "<<std::endl;
    std::cin>>kolone>>redovi;
    try{
        
        
        
        
    }
    
    
    
    
    
    
    
    
	return 0;
}