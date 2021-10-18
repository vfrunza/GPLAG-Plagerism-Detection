/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <iomanip>

template<typename NekiTip>
struct Matrica {
    int br_redova,br_kolona;
    NekiTip **element=nullptr ;
};

template<typename NekiTip>
void UnistiMatricu (Matrica<NekiTip> m) {
    if(!m.element) return ;
    for(int i=0;i<m.br_redova;i++)
        delete [] m.element[i];
        delete [] m.element ;
        m.element=nullptr;

}

template<typename NekiTip>
Matrica <NekiTip> StvoriMatricu(int br_redova,int br_kolona) {

    Matrica<NekiTip> matrica ;
    matrica.br_redova=br_redova;
    matrica.br_kolona=br_kolona;
    try{
    matrica.element=new NekiTip *[br_redova];
    }  catch(...)  { 
    throw ; }
    for(int i=0;i<br_redova;i++) matrica.element[i]=nullptr ;

    try {

        for(int i=0 ;i<br_redova;i++)
         matrica.element[i]=new NekiTip[br_kolona] ;

        }

    catch (...) {
        UnistiMatricu(matrica) ;
        throw ;
    }
    return matrica ;
}

template<typename NekiTip>
void UnesiMatricu (char ime_matrice,Matrica<NekiTip> &mat) {

    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<ime_matrice <<"("<< i+1 <<","<<j+1<<") = ";
            std::cin>>mat.element[i][j];

        }
    }

}

template<typename NekiTip>
Matrica<NekiTip> SaberiMatrice (const Matrica<NekiTip> &mat1,const Matrica<NekiTip> &mat2) {
    if(mat1.br_redova!=mat2.br_redova || mat1.br_kolona!=mat2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
    auto m3 (StvoriMatricu<NekiTip>(mat1.br_redova,mat1.br_kolona)) ;
    for(int i=0 ;i<mat1.br_redova;i++)
        for(int j=0; j<mat1.br_kolona;j++)

        m3.element[i][j]=mat1.element[i][j]+mat2.element[i][j] ;

    return m3 ;
}

template<typename NekiTip>
void IspisiMatricu(Matrica<NekiTip> matrica,int sirina_ispisa,int s=6,bool n=false) {

    for(int i=0;i<matrica.br_redova;i++) {
        for(int j=0;j<matrica.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(s)<<matrica.element [i][j];

        std::cout<<std::endl ;
    }
    if(n) UnistiMatricu(matrica) ;
}

template<typename NekiTip,typename NekiTip2>
Matrica<NekiTip> PomnoziKIM(const Matrica<NekiTip> &mat,NekiTip2 p) {
    Matrica<NekiTip> matrix (StvoriMatricu<NekiTip>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            matrix.element[i][j]=p*mat.element[i][j] ;

return matrix ;
}


template<typename NekiTip>
Matrica<NekiTip> ProduktMatrica (Matrica<NekiTip> mat1,Matrica<NekiTip> mat2) {
    //if(mat1.br_redova!=mat2.br_kolona) return ;
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje") ;
    try {
    Matrica <NekiTip> m3 (StvoriMatricu<NekiTip>(mat1.br_redova,mat2.br_kolona)) ;


    for(int i=0;i<mat1.br_redova;i++) {
        for(int j=0;j<mat2.br_kolona;j++) {

            NekiTip suma(0);
            for(int k=0;k<mat2.br_redova;k++)
            suma+=mat1.element[i][k]*mat2.element[k][j] ;
            m3.element[i][j]=suma ;
        }
      }

  
    return m3 ;
    }
    catch (...) {
        throw ;
    }
}

template<typename NekiTip,typename NekiTip2>

Matrica<NekiTip> MatricniPolinom(Matrica<NekiTip> mat,int n,NekiTip2 p) {

    if(n<0) throw std::domain_error ("Neispravan stepen polinoma") ;
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    Matrica<NekiTip> Jedinicna_matrica;
    Jedinicna_matrica.br_redova=mat.br_redova;
    Jedinicna_matrica.br_kolona=mat.br_kolona;
    Jedinicna_matrica.element=(StvoriMatricu<NekiTip>(mat.br_redova,mat.br_kolona)).element;

    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            if(i==j)
                Jedinicna_matrica.element[i][j]=1 ;
            else
                Jedinicna_matrica.element[i][j]= 0 ;
        }
    Matrica <NekiTip> produkt;
    produkt.br_redova=mat.br_redova;
    produkt.br_kolona=mat.br_kolona;
    produkt.element=(StvoriMatricu<NekiTip>(mat.br_redova,mat.br_kolona)).element;
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
        
                produkt.element[i][j]=mat.element[i][j] ;
           
        }
    Matrica<NekiTip> matrica(PomnoziKIM(Jedinicna_matrica,*p)) ;
     UnistiMatricu(Jedinicna_matrica);//***
    p=p+1;
    for(int i=1;i<=n ;i++) {
        
        if(i!=1) {
            Matrica<NekiTip> pom(produkt);
            produkt=ProduktMatrica(produkt,mat);
            UnistiMatricu(pom);
        }
       
        Matrica<NekiTip> pomocna (PomnoziKIM(produkt,*p));
        Matrica<NekiTip> pomocna2 (matrica);
        matrica= SaberiMatrice(matrica,pomocna);
        //matrica=pomocna1;//***
        UnistiMatricu(pomocna);
        UnistiMatricu(pomocna2);
        //UnistiMatricu(pomocna1);
     p=p+1 ;
    
    }
    UnistiMatricu(produkt);
   UnistiMatricu(mat);
    return matrica ;
}
int main ()
{
    std::vector<int> v;
    int n{0},k{0} ;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n ;

    try {

    Matrica<int> a =StvoriMatricu<int>(n,n) ;



  std::cout<<"Unesite elemente matrice A:\n";
  
  UnesiMatricu('A',a) ;

  std::cout<<"Unesite red polinoma: ";
  std::cin>>k;

  std::cout<<"Unesite koeficijente polinoma: ";
  for(int i=0 ; i<=k ; i++) {
      
      int temp{0} ;
      std::cin>>temp;
      v.push_back(temp) ;
  }

  try {
     a= MatricniPolinom(a,k,v.begin()) ;//***

IspisiMatricu(a,10) ;
     
  }
 
catch(std::domain_error s) {
    std::cout<<s.what() ;
    
 }
 UnistiMatricu(a);
}
catch(std::domain_error d) {
      std::cout<<d.what();
  }
 
return 0 ;
}

