/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <list>
#include <vector>
using namespace std;
template<typename TipElemenata>
 struct Matrica{
   int br_redova,br_kolona;
   TipElemenata **elementi=nullptr;
 };
 
 template<typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {                          
     if(!mat.elementi) return;
     for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
     delete [] mat.elementi;
     mat.elementi=nullptr;
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
     Matrica<TipElemenata> mat;
     mat.br_redova=br_redova;
     mat.br_kolona=br_kolona;
     
     mat.elementi=new TipElemenata*[br_redova];
     for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
     try{
         for(int i=0;i<br_redova;i++){
             mat.elementi[i]=new TipElemenata[br_kolona];
         }
     }
     catch(...){
         UnistiMatricu(mat);
         throw;
     }
     return mat;
 }
 
 template<typename TipElemenata>
  void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
      for(int i=0;i<mat.br_redova;i++){
          for(int j=0;j<mat.br_kolona;j++){
              cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
              cin>>mat.elementi[i][j];
          }
      }
  }
  
 template<typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost, bool treba_brisati){
     for(int i=0;i<mat.br_redova;i++){
         for(int j=0;j<mat.br_kolona;j++){
             cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
         }
         cout<<endl;
     }
     if(treba_brisati==true){
         UnistiMatricu(mat);
     }
 }
 template<typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
     if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
     throw domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
     for(int i=0;i<m1.br_redova;i++){
         for(int j=0;j<m1.br_kolona;j++){
             m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
         }
     }
     return m3;
 }
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova){
     throw domain_error("Matrice nisu saglasne za mnozenje");
    } 
    Matrica<TipElemenata> m3;
        double element(0);
        m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        for(int i=0;i<m3.br_redova;i++){
            for(int j=0;j<m3.br_kolona;j++){
                for(int k=0;k<m1.br_kolona;k++){
                    element+=((m1.elementi[i][k])*(m2.elementi[k][j]));
                }
                m3.elementi[i][j]=element;
                element=0;
            }
        }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> PomnoziMatricuSkalarom(const Matrica<TipElemenata> &M, int a){
    Matrica<TipElemenata> pomnozena;
    pomnozena=StvoriMatricu<TipElemenata>(M.br_redova,M.br_kolona);
    for(int i=0; i<M.br_redova; i++){
        for(int j=0; j<M.br_kolona; j++){
            pomnozena.elementi[i][j]=a*(M.elementi[i][j]);
        }
    }
    
    return pomnozena;
}

template<typename TipElemenata,typename NekiTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, NekiTip it){
    if(n<0) throw domain_error("Neispravan stepen polinoma");
    Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    for(int i=0;i<=n;i++){
        if(i==0){
            for(int j=0;j<mat.br_redova;j++){
                for(int k=0;k<mat.br_kolona;k++){
                    if(j==k){
                        mat.elementi[j][k]=1;
                    }
                    else{
                        mat.elementi[j][k]=0;
                    }
                }
            }
            Matrica<TipElemenata> pomocna;
            pomocna=PomnoziMatricuSkalarom<TipElemenata>(mat,*it);
            for(int redovi=0; redovi<mat.br_redova; redovi++){
                for(int kolone=0; kolone<mat.br_kolona; kolone++){
                    mat.elementi[redovi][kolone]=pomocna.elementi[redovi][kolone];
                }
            }
            UnistiMatricu(pomocna);
            
        }
        else if(i==1){
            Matrica<TipElemenata> pomocna;
            pomocna=PomnoziMatricuSkalarom<TipElemenata>(A,*it);
            Matrica<TipElemenata> zbir= ZbirMatrica<TipElemenata> (mat,pomocna);
            UnistiMatricu(pomocna);
            
            for(int redovi=0;redovi<mat.br_redova;redovi++){
                for(int kolone=0; kolone<mat.br_redova; kolone++){
                    mat.elementi[redovi][kolone]=zbir.elementi[redovi][kolone];
                 }
            }
            UnistiMatricu(zbir);
        }
        else{
            Matrica<TipElemenata> temp;
            temp=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
            for(int redovi=0; redovi<mat.br_redova;redovi++){
                for(int kolone=0;kolone<mat.br_kolona;kolone++){
                    temp.elementi[redovi][kolone]=A.elementi[redovi][kolone];
                }
            }
            
            for(int l=1;l<i;l++){
                Matrica<TipElemenata> pomocna;
                pomocna=ProduktMatrica<TipElemenata>(temp,A);
                for(int redovi=0;redovi<mat.br_redova;redovi++){
                    for(int kolone=0; kolone<mat.br_kolona;kolone++){
                        temp.elementi[redovi][kolone]=pomocna.elementi[redovi][kolone];
                    }
                }
                UnistiMatricu(pomocna);
                
            }
            Matrica<TipElemenata> pomocna;
            pomocna=PomnoziMatricuSkalarom<TipElemenata>(temp,*it);
            for(int redovi=0; redovi<mat.br_redova; redovi++){
                for(int kolone=0; kolone<mat.br_kolona; kolone++){
                    temp.elementi[redovi][kolone]=pomocna.elementi[redovi][kolone];
                }
            }
            
            UnistiMatricu(pomocna);
            pomocna=ZbirMatrica<TipElemenata>(mat,temp);
            for(int redovi=0; redovi<mat.br_redova; redovi++){
                for(int kolone=0; kolone<mat.br_kolona; kolone++){
                    mat.elementi[redovi][kolone]=pomocna.elementi[redovi][kolone];
                }
            }
            UnistiMatricu(temp);
            UnistiMatricu(pomocna);
        }
        it++;
    }
    return mat;
}


int main ()
{
    Matrica<int> a,krajnja;
    int n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>n;
    try{
        a=StvoriMatricu<int>(n,n);
        cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        cout<<"Unesite red polinoma: ";
        int m;
        cin>>m;
        cout<<"Unesite koeficijente polinoma: ";
        list<double> lista; 
        for(int i=0;i<=m;i++){
        double x;
        cin>>x;
        lista.push_back(x);
        
       }
       krajnja=MatricniPolinom<int>(a,m,lista.begin());
       UnistiMatricu(a);
       IspisiMatricu(krajnja,10,6,true);
    }
    catch(bad_alloc){
        cout<<"Nema dovoljno memorije!\n";
          UnistiMatricu(krajnja);
    }
    catch(domain_error izuzetak){                                             
     cout<<izuzetak.what();
       UnistiMatricu(krajnja);
    }
  return 0;
}
