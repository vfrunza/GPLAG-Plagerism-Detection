/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat){
        if (!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
        Matrica<TipElemenata> mat;
        try{
        mat.br_redova=br_redova;  mat.br_kolona=br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        
            for(int i=0; i<br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
         for (int i(0); i<mat.br_redova; i++){
             for (int j(0); j<mat.br_kolona; j++){
                 mat.elementi[i][j]={};
             }
    }
    return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++)
            for (int j=0; j<mat.br_kolona; j++){
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati){
        for (int i=0; i<mat.br_redova; i++){
            for (int j=0; j<mat.br_kolona; j++){
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            } cout << std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost){
        for (int i=0; i<mat.br_redova; i++){
            for (int j=0; j<mat.br_kolona; j++){
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            } cout << std::endl;
        }
       
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa){
        for (int i=0; i<mat.br_redova; i++){
            for (int j=0; j<mat.br_kolona; j++){
                std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];;
            } cout << std::endl;
        }
       
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        try{
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        }catch(std::domain_error izuzetak){
            cout << izuzetak.what();
            UnistiMatricu(m1);
            UnistiMatricu(m2);
            throw;
        }
         Matrica<TipElemenata> a;
         try {
         a= StvoriMatricu<TipElemenata>(m1.br_kolona,m2.br_redova);
         for (int i(0); i<m1.br_redova; i++){
             for (int j(0); j<m1.br_kolona; j++){
                 a.elementi[i][j]={};
             }
         }
         for (int i(0); i<m1.br_redova; i++){
             int o(0);
             for (int j(0); j<m1.br_kolona; j++){
                 for (int k(0); k<m2.br_kolona; k++){
                     j=0;
                    for (int h(0); h<m2.br_redova; h++){
                     a.elementi[i][o]+=m1.elementi[i][j]*m2.elementi[h][k];
                     j++;
                    }
                    o++;
                }
             }  
         }
         return a;
        }catch(...){
            UnistiMatricu(a);
            UnistiMatricu(m1);
            UnistiMatricu(m2);
            throw;
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
      try{  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::range_error("Matrice nemaju jednake dimenzije!");
      Matrica<TipElemenata> m3;
      try{
         m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
      }catch(...){
          UnistiMatricu(m3);
          UnistiMatricu(m1);
          UnistiMatricu(m2);
          throw;
      }
         for (int i(0); i<m3.br_redova; i++){
             for (int j(0); j<m3.br_kolona; j++){
                 m3.elementi[i][j]={};
             }
    }
        for (int i=0; i<m1.br_redova; i++)
            for (int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
      } catch(...){
          throw;
      }
    }
    
   
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom( const Matrica<TipElemenata> &x, vector<double> polinom){
        
       
        if (x.br_redova!=x.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
      Matrica<TipElemenata> a(StvoriMatricu<TipElemenata>(x.br_redova,x.br_kolona));
      Matrica<TipElemenata> jedinicna(StvoriMatricu<TipElemenata>(x.br_redova,x.br_kolona));
    Matrica<TipElemenata> pomocna2(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
         
       for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
               if (i==j) jedinicna.elementi[i][j]=1;
           }
       }
       for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
                a.elementi[i][j]=jedinicna.elementi[i][j]*polinom[0];
           }
       }
       
       for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
               jedinicna.elementi[i][j]=x.elementi[i][j];
           }
       }
       
      
        for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
               pomocna2.elementi[i][j]=x.elementi[i][j];
           }
       }
       
       for (int k=1; k<polinom.size(); k++){
           for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
               a.elementi[i][j]+=(jedinicna.elementi[i][j]*polinom[k]);
           }
       }
       
      Matrica<TipElemenata> pomocna3(ProduktMatrica(jedinicna,pomocna2));
      for (int i(0); i<a.br_redova; i++){
           for (int j(0); j<a.br_kolona; j++){
               jedinicna.elementi[i][j]=pomocna3.elementi[i][j];
           }
       }UnistiMatricu(pomocna3);
       }
       UnistiMatricu(jedinicna);
       UnistiMatricu(pomocna2);
       return a;
    }
       /* 
        Matrica<TipElemenata> jedinicna;
        Matrica<TipElemenata> matricni_polinom;
        Matrica<TipElemenata> pomocna;
        Matrica<TipElemenata> pomocna1;
        Matrica<TipElemenata> pomocna2;
     //   Matrica<TipElemenata> pomocna3;
    try{
    
    
    try{
    jedinicna=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
     for (int i(0); i<jedinicna.br_redova; i++){
             for (int j(0); j<jedinicna.br_kolona; j++){
                 jedinicna.elementi[i][j]={};
             }
    }
    }catch(...){
        UnistiMatricu(jedinicna);
        throw;
    }
    
    try{
    matricni_polinom = StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
    }catch(...){
        UnistiMatricu(matricni_polinom);
        throw;
    }
    for (int i(0); i<jedinicna.br_redova; i++){
        for (int j(0); j<jedinicna.br_kolona; j++){
            if (i==j) jedinicna.elementi[i][j]=1;
        }
    }
  
  
  try{
        pomocna=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);}
        catch(...){
            UnistiMatricu(pomocna);
            throw;
        }
        for (int i(0); i<jedinicna.br_redova; i++){
        for (int j(0); j<jedinicna.br_kolona; j++){
             pomocna.elementi[i][j]=a.elementi[i][j];
        }
    }
        
         
         try{
        pomocna1=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
         } catch(...){
             UnistiMatricu(pomocna1);
             throw;
         }
         for (int i(0); i<jedinicna.br_redova; i++){
        for (int j(0); j<jedinicna.br_kolona; j++){
             pomocna1.elementi[i][j]=a.elementi[i][j];
        }
    }
     
         try{
        pomocna2=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
         } catch(...){
             UnistiMatricu(pomocna2);
             throw;
         }
               
for (int k(0); k<polinom.size(); k++){
         
        if(k==1) {
            for (int i(0); i<jedinicna.br_redova; i++){
                 for (int j(0); j<jedinicna.br_kolona; j++){
                     pomocna1.elementi[i][j]=a.elementi[i][j];
        }
    } 
    for (int i(0); i<jedinicna.br_redova; i++){
                for (int j(0); j<jedinicna.br_kolona; j++){
                    TipElemenata x;
                    x = pomocna1.elementi[i][j];
                    TipElemenata y;
                    y=polinom[k]*x;
                    pomocna1.elementi[i][j]=y;
            }   }
             for (int i(0); i<a.br_redova; i++){
                for (int j(0); j<a.br_kolona; j++){
                    matricni_polinom.elementi[i][j]+=pomocna1.elementi[i][j];
                }
            }
        }
        else if (k==0) {
            for (int i(0); i<jedinicna.br_redova; i++){
        for (int j(0); j<jedinicna.br_kolona; j++){
             pomocna1.elementi[i][j]=jedinicna.elementi[i][j];
        }
    }
        
       
             for (int i(0); i<jedinicna.br_redova; i++){
                for (int j(0); j<jedinicna.br_kolona; j++){
                    TipElemenata x;
                    x = pomocna1.elementi[i][j];
                    TipElemenata y;
                    y=polinom[k]*x;
                    pomocna1.elementi[i][j]=y;
            }   }
            for (int i(0); i<a.br_redova; i++){
                for (int j(0); j<a.br_kolona; j++){
                    matricni_polinom.elementi[i][j]+=pomocna1.elementi[i][j];
                }
            }
        
        }
       else  {
            
               auto pomocna3=ProduktMatrica(a,pomocna);
                
                   for (int i(0); i<jedinicna.br_redova; i++){
                         for (int j(0); j<jedinicna.br_kolona; j++){
                            pomocna2.elementi[i][j]=pomocna.elementi[i][j];
                     }
                         }
                          UnistiMatricu(pomocna);
                pomocna=ProduktMatrica(pomocna2,a);
                 for (int i(0); i<jedinicna.br_redova; i++){
                for (int j(0); j<jedinicna.br_kolona; j++){
                    TipElemenata x;
                    x = pomocna3.elementi[i][j];
                    TipElemenata y;
                    y=polinom[k]*x;
                    pomocna3.elementi[i][j]=y;
            }   }
             for (int i(0); i<a.br_redova; i++){
                for (int j(0); j<a.br_kolona; j++){
                    matricni_polinom.elementi[i][j]+=pomocna3.elementi[i][j];
                }
            }
            UnistiMatricu(pomocna3);
        } 
    }
     UnistiMatricu(pomocna);
     UnistiMatricu(pomocna1);
     UnistiMatricu(pomocna2);
     
    return matricni_polinom;
    }catch(...){
         UnistiMatricu(pomocna);
     UnistiMatricu(pomocna1);
     UnistiMatricu(pomocna2);
     
     UnistiMatricu(matricni_polinom);
        throw;
    }

}
    
*/
int main ()
{
    
    Matrica<int> a;
    Matrica<int> c;
    int m,n;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> m;
    n=m;
    try{
    a=StvoriMatricu<int>(m,n);
    cout << "Unesite elemente matrice A: " << std::endl;
    UnesiMatricu('A',a);
    cout << "Unesite red polinoma: ";
    int red;
    cin >> red;
    vector<double> polinom;
    cout << "Unesite koeficijente polinoma: ";
    for (int i(0); i<=red; i++){
        double x;
        cin >> x;
        polinom.push_back(x);
    }
    

             c=MatricniPolinom(a,polinom);
   
    IspisiMatricu(c,10,6,true);
    
    UnistiMatricu(a);
   
	return 0;
    }catch(std::domain_error izuzetak){
        cout << izuzetak.what();
        UnistiMatricu(a);
        
        return 0;
    }catch(std::range_error izuzetak){
        cout << izuzetak.what();
        UnistiMatricu(a);
        UnistiMatricu(c);
        return 0;
    }
    
     catch(...){
        UnistiMatricu(a);
        UnistiMatricu(c);
        return 0;
    }
}