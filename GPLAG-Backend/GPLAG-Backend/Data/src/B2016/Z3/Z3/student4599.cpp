/B2016/2017: Zadaća 3, Zadatak 3
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
void UnistiMatricu (Matrica<TipElemenata> mat){
    
    if (!mat.elementi) return;
    
    for(int i=0; i<mat.br_redova;i++)
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    
    mat.elementi=nullptr;
}

template<typename TipElemenata> 
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    
    mat.elementi=new TipElemenata*[br_redova];
    
    for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
   
    try{
        for(int i(0);i<br_redova;i++)
            mat.elementi[i]= new TipElemenata[br_kolona];
    
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    
    return mat;
}

template<typename TipElemenata>

void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6, bool treba_ispisati=false){
    
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
    std::cout<<std::endl;
    }
    
    if (treba_ispisati)
        UnistiMatricu(mat);
    
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    
    if (m1.br_redova != m2.br_redova || m1.br_kolona !=m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        
    auto m4(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m2.br_kolona;j++){
            double suma(0);
            
            for(int k(0);k<m2.br_redova;k++)
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
            
            m4.elementi[i][j]=suma;
        }
    }
    
    return m4;
}

template<typename TipElemenata>
void ProduktSkalara (Matrica<TipElemenata> &m, double broj){
    
    
    for(int i(0);i<m.br_redova;i++){
        for(int j(0);j<m.br_kolona;j++){
            m.elementi[i][j]=m.elementi[i][j]*broj;
        }
    }
}
template<typename TipElemenata>
void zMatrica(Matrica<TipElemenata> &m, Matrica<TipElemenata> p){
    
    for(int i(0);i<m.br_redova;i++){
        for(int j(0);j<m.br_kolona;j++){
            m.elementi[i][j]=m.elementi[i][j]+p.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m,std::vector<double> p){
    
    if(m.br_redova!=m.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
    
    if (p.size()==0){
        auto mp=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        return mp;
    }
    
    auto mat=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    auto I=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
 
    
    for (int i(0);i<p.size();i++){
        
        if(i==0){
            for(int j(0);j<m.br_redova;j++){
                for(int k(0);k<m.br_kolona;k++){
                    
                    if(k==j)
                    I.elementi[j][k]=p[0];
                }
            }
      
     
        }
        
      
        
        else if (i==1){ 
            
            auto mtr=StvoriMatricu<TipElemenata> (m.br_redova,m.br_kolona);
             
             
             for(int i(0);i<m.br_redova;i++){
                 for(int j(0);j<m.br_kolona;j++){
                     mtr.elementi[i][j]=m.elementi[i][j];
                 }
             }

              ProduktSkalara(mtr,p[i]);
              zMatrica(I,mtr);
              
             
        
        }

          
          else if (i>1) {
              
              auto pomocna=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
                int br(i);
                
                for(int i(0);i<m.br_redova;i++){
                    for(int j(0);j<m.br_kolona;j++){
                        pomocna.elementi[i][j]=m.elementi[i][j];
                    }
                }
                
                while(br>0){
                
                
                    pomocna=ProduktMatrica(pomocna,m);
                    br--;
                }
                
            
                 ProduktSkalara(pomocna,p[i]);
                
                 zMatrica(I,pomocna);
      
                 UnistiMatricu(pomocna);
          }
          
    }
    
          
          
          for(int k(0);k<m.br_redova;k++){
              for(int l(0);l<m.br_kolona;l++){
                  mat.elementi[k][l]=I.elementi[k][l];
              }
          }
          

          
            
        UnistiMatricu(I);
    
    
    return mat;
}



int main ()
{
    
    Matrica<double> a,b,c;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;

    
    try{
        
        a=StvoriMatricu<double>(m,m);
        b=StvoriMatricu<double>(m,m);
        
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        
        UnesiMatricu('A',a);

        
        int red;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red;
        
        std::vector<double> polinom(red);
        std::cout<<"Unesite koeficijente polinoma: ";
        
        for(int i(0);i<red;i++){
            int broj;
            std::cin>>broj;
            polinom[i]=broj;
        }

        IspisiMatricu(b=(MatricniPolinom(a,polinom)),7);
        
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}