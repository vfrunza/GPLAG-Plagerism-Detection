/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <new>
//#include "TestCurenja.h"
/*
template <typename tipel>
typedef std::vector<std::vector<tipel>> Matrica;
*/
template <typename tipel>
    struct Matrica {
        int br_redova, br_kolona;
        tipel **elementi = nullptr;
    };
template <typename tipel>
    void UnistiMatricu(Matrica<tipel> mat){
        if(!mat.elementi) return;
            for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
            delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try{
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_kolona]{};
 }
 catch(...) {
    UnistiMatricu(mat);
    throw;
 }
 return mat;
 }
template <typename tipel>
void UnesiMatricu (char ime_matrice, Matrica<tipel> &mat){
    for(int i = 0; i<mat.br_redova; ++i)
        for(int j = 0; j<mat.br_kolona; ++j){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename tipel>
void IspisiMatricu(const Matrica<tipel> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i = 0; i<mat.br_redova; ++i){
        for(int j = 0; j<mat.br_kolona; ++j)
            std::cout<<std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
            std::cout<<std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
}
template <typename tipel>
Matrica<tipel> ZbirMatrica (const Matrica<tipel> &m1, const Matrica<tipel> &m2){
     auto m3 (StvoriMatricu<tipel>(m1.br_redova, m1.br_kolona));
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
       try{
   
    for(int i = 0; i<m1.br_redova; i++)
        for(int j = 0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
       }
       catch(...){
            UnistiMatricu(m3); throw;
       }
    return m3;
}
template <typename tipel>
    Matrica <tipel> ProduktMatrica (const Matrica<tipel> &m1, const Matrica<tipel> &m2){
        auto m3 (StvoriMatricu<tipel>(m1.br_redova, m2.br_kolona));
        
        if (m1.br_kolona!=m2.br_redova){UnistiMatricu(m1); UnistiMatricu(m2);
            throw std::domain_error("Matrice nisu saglasne za mnozenje");}
           try{
        for(int i = 0; i<m1.br_redova; i++){
            for(int j = 0; j<m2.br_kolona; j++){
               // double suma = 0;
                for(int k = 0; k<m1.br_kolona; k++)
                    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                   // m3.elementi[i][j] = suma;
            }
        }
        }
       catch(...){
         UnistiMatricu(m3); throw;
       }
    return m3;
    }
template <typename tipel>
    Matrica<tipel> NapraviNulMatricu (const Matrica<tipel> &A){
        auto m3 (StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
        try{
        for(int i = 0; i<A.br_redova; ++i){
            for(int j = 0; j<A.br_kolona; ++j){
                m3.elementi[i][j] = 0;
            }
        }
        }
    catch(...){UnistiMatricu(m3); throw;}
    return m3;
}
template <typename tipel>
    Matrica <tipel> NapraviJedinicnu (const Matrica<tipel> &A){
        auto m3 (StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
       try{
           
        for(int i = 0; i<A.br_redova; ++i) {
            for(int j = 0; j<A.br_kolona; ++j) {
                if(i==j) m3.elementi[i][j]=1;
                else m3.elementi[i][j]=0;
            }
        }
       }
       catch(...){UnistiMatricu(m3);  throw;} 
    return m3;
    }
template <typename tipel>
    void ProduktSkalaraIMatrice (const Matrica <tipel> &A, double n){
        for(int i = 0; i<A.br_redova; ++i){
            for(int j = 0; j<A.br_kolona; ++j){
                A.elementi[i][j]*=n;
            }
        }
    }
template <typename tipel>
    Matrica<tipel> MatricniPolinom (const Matrica<tipel> &A, std::vector<double> p1){
        
     auto m3=(StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
     auto m4=(StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
     auto  m5=(StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
     auto pomocna=(StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
   //  auto pomocnaProdukt (StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
    //Matrica<tipel> m5;
     Matrica <tipel> nova=(StvoriMatricu<tipel>(A.br_redova,A.br_kolona));
     try{
     for(int i = 0; i< A.br_redova; i++){
         for(int j = 0; j<A.br_kolona; j++){
             m5.elementi[i][j] = A.elementi[i][j];
         }
     }
     //IspisiMatricu(m5, 7);
    if(A.br_kolona != A.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
    if(p1.size()==0)
        return NapraviNulMatricu(A);
    int n = p1.size();
    UnistiMatricu(m4);
    UnistiMatricu(m3);
    //UnistiMatricu(pomocna);
    m4 = NapraviJedinicnu(m4);
    m3 = NapraviNulMatricu(m3);
   // pomocna=NapraviNulMatricu(pomocna);
    int m;
    for(int i = 0; i!=n; ++i){
        m = 2;
        if(i==0){
            ProduktSkalaraIMatrice(m4, p1[0]);
            UnistiMatricu(pomocna);////////////////3
            pomocna = ZbirMatrica(m3,m4);
            //IspisiMatricu(m3,7);
        }
        if(i==1){
            ProduktSkalaraIMatrice(A, p1[1]);
            UnistiMatricu(m3);////////////////3
            m3= ZbirMatrica(pomocna, A);//m3,a
            //IspisiMatricu(m3,7);
        }
        if(i>1){
            if(m==n)
                break;
           //
             UnistiMatricu(nova);
            nova = ProduktMatrica(m5, m5);
            //IspisiMatriu(nova,7);
            //UnistiMatricu(pomocnaProdukt);
            //pomocnaProdukt=nova;
            //auto  (StvoriMatricu<tipel>(A.br_redova, A.br_kolona));
           
            for(int j=2; j<=m;j++){
                UnistiMatricu(nova);
                nova = ProduktMatrica(nova, m5);
                
                /*for(int s=0; s<pomocnaProdukt.br_redova; s++){
                    for(int l=0; l<pomocnaProdukt.br_kolona; l++){
                        nova.elementi[s][l]=pomocnaProdukt.elementi[s][l];
                    }
                }
                UnistiMatricu(pomocnaProdukt);*/
            }
           
            //IspisiMatricu(nova, 7);
            ProduktSkalaraIMatrice(nova, p1[i]);
            UnistiMatricu(pomocna);
            UnistiMatricu(m5);/////////////////////////////////////////m3
            pomocna = ZbirMatrica(m3, nova);
            //IspisiMatricu(m3, 7);
            m++;
        }
    }
    UnistiMatricu(m4); ; UnistiMatricu(m3); //UnistiMatricu(pomocnaProdukt);  ///////////dodalaaaaaaaaa
        }
        catch(...){
           UnistiMatricu(pomocna);
           throw;
        }
    return pomocna;
}

int main (){
    Matrica<double> a,c;
    int m,n;
    std::vector<double> vektor;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try {
        a = StvoriMatricu<double>(m, m);
        //b = StvoriMatricu<double>(m ,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        
       // std::cout<<"Unesi matricu B:\n";
        //UnesiMatricu('B', b);
        
       std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        double broj;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i = 0; i<n+1; ++i){
            std::cin>>broj;
            vektor.push_back(broj);
        }
        c = MatricniPolinom(a, vektor);
        IspisiMatricu(c,10,6, true);
        UnistiMatricu(a);
    }
    catch (...){
        UnistiMatricu(a);
        std::cout<<"Izuzetak";
    }
    UnistiMatricu(a);  UnistiMatricu(c);
    
  
	return 0;
}