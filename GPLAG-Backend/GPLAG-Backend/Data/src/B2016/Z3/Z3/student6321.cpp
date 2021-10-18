/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include<vector>

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    
  // std::cout<<"+";
    
    
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    
  //  std::cout<<"|";
    
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi = new TipElemenata *[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriJedinicnuMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata *[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
        
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            if(i==j){
                mat.elementi[i][j]=1;
            }
            else mat.elementi[i][j]=0;
        }
    }
    
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice
            <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
    
  
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<< mat.elementi[i][j];
            
        std::cout<<std::endl;
        
    }
    
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova)
    throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    
    for(int i=0;i<m1.br_redova;i++){
        
        for(int j=0;j<m2.br_kolona;j++){
            
            TipElemenata pomocna(0);
            for(int k=0;k<m1.br_kolona;k++){
               
                pomocna+=m1.elementi[i][k]*m2.elementi[k][j];
                
            }
            m3.elementi[i][j]=pomocna;
            
        }
    }
    
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> p){
    if(m.br_kolona!=m.br_redova)
    throw std::domain_error("Matrica mora biti kvadratna");
    
    auto pn(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    

   
   for(int i=0;i<m.br_redova;i++){
       for(int j=0;j<m.br_kolona;j++){
           pn.elementi[i][j]=0;
       }
   }
   if(p.size()==0){
       return pn;
   }
  
   
     Matrica<TipElemenata> I(StvoriJedinicnuMatricu<TipElemenata>(m.br_redova,m.br_kolona));
   
   auto m1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
   
   for(int i=0;i<m.br_redova;i++){
       for(int j=0;j<m.br_kolona;j++){
           m1.elementi[i][j]=m.elementi[i][j];
       }
   }
 Matrica<TipElemenata> pomocna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
   for(int  i=0;i<p.size();i++){
    
       
        for(int ii=0;ii<m.br_redova;ii++){
            for(int jj=0;jj<<m.br_redova;jj++){
                pomocna.elementi[ii][jj]=0;
            }
        }
        
       
       
        if(i==0){
         
            for(int ii=0;ii<m.br_redova;ii++){
                for(int jj=0;jj<m.br_kolona;jj++){
                   
                       pomocna.elementi[ii][jj]=p[0]*I.elementi[ii][jj];
                        
                    
                }
            }
       
            
            
        }
        
   else if(i==1) {
          for(int ii=0;ii<m.br_redova;ii++){
              for(int jj=0;jj<m.br_kolona;jj++){
                  pomocna.elementi[ii][jj]=p[1]*m1.elementi[ii][jj];
                 
                  }
              }
               
          
          
     }
   
          else{
               
           auto r(ProduktMatrica(m1,m));
           for(int ii=0;ii<m1.br_kolona;ii++){
               for(int jj=0;jj<m1.br_kolona;jj++){
                   m1.elementi[ii][jj]=r.elementi[ii][jj];
               }
           }
           UnistiMatricu(r);
             
                  
              
              for(int ii=0;ii<m.br_redova;ii++){
                  for(int jj=0;jj<m.br_kolona;jj++){
                      pomocna.elementi[ii][jj]=p[i]*m1.elementi[ii][jj];
                      
                  }
              }
              
              
          }
          
          
      auto g=ZbirMatrica<TipElemenata>(pomocna,pn);
            
            for(int ii=0;ii<pn.br_kolona;ii++){
                for(int jj=0;jj<pn.br_kolona;jj++){
                    pn.elementi[ii][jj]=g.elementi[ii][jj];
                }
            }
            
            UnistiMatricu(g);
      
          
      }  
      
    
        UnistiMatricu(pomocna); 
       UnistiMatricu(m1);
        UnistiMatricu(I);
       
        
    return pn;
    
}

int main ()
{
  
Matrica<double> a,b;
int m;
std::cout<<"Unesite dimenziju kvadratne matrice: ";
std::cin>>m;
try{
    a=StvoriMatricu<double>(m,m);
    std::cout<<"Unesite elemente matrice A: \n";
    UnesiMatricu('A',a);
    
    std::cout<<"Unesite red polinoma: ";
    int n;
    std::cin>>n;
    
    std::vector<double> v;
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i=0;i<=n;i++){
        double p;
        std::cin>>p;
        v.push_back(p);
    }
    IspisiMatricu(b=MatricniPolinom(a,v),10);
}
catch(std::bad_alloc){
    std::cout<<"Nema dovoljno memorije";
}
UnistiMatricu(a); UnistiMatricu(b);


	return 0;
}