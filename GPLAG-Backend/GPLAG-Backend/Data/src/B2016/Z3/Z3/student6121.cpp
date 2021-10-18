#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>


template <typename TipElemenata> struct Matrica {
int br_redova, br_kolona;
TipElemenata **elementi = nullptr; };

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
if(!mat.elementi) return;
for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i]; delete[] mat.elementi;
mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
Matrica<TipElemenata> mat;
mat.br_redova = br_redova; mat.br_kolona = br_kolona; 
    mat.elementi = new TipElemenata*[br_redova];

for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr; try {
for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
}
catch(...) {
      UnistiMatricu(mat);
throw; }
return mat; }
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
for(int i = 0; i < mat.br_redova; i++) for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice
          << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
      }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
for(int i = 0; i < mat.br_redova; i++) {
for(int j = 0; j < mat.br_kolona; j++) {
std::cout  << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
      }
              std::cout << std::endl;

}
      if(treba_brisati==true) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
const Matrica<TipElemenata> &m2) {
if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
throw std::domain_error("Matrice nemaju jednake dimenzije!"); auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++)
m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m3; }

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
const Matrica<TipElemenata> &m2) {
if(m1.br_kolona != m2.br_redova )
throw std::domain_error("Matrice nisu saglasne za mnozenje"); 
auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona)); 


for(int red = 0; red < m1.br_redova; red++){
for(int kolona=0;kolona< m2.br_kolona;kolona++){ m3.elementi[red][kolona] = 0;
}
}
        for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m2.br_kolona; j++) {
double suma(0);
for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j]; 
m3.elementi[i][j] = suma;
}

return m3; }
   
    template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m1,std::vector<double> vektor) {

    if(m1.br_kolona != m1.br_redova ) throw std::domain_error("Matrica mora biti kvadratna");

    auto suma (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); 
 
     auto m2 (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); 


for(int i = 0; i < m1.br_redova; i++){
for(int j=0;j< m1.br_kolona;j++){ suma.elementi[i][j] = 0;
}
}
    if (vektor.size() == 0) {
        return suma;
    } 
    
    for (int i = 0; i < m1.br_redova; i++) {
    
            for (int j = 0; j < m1.br_kolona; j++) {
        
            m2.elementi[i][j]=m1.elementi[i][j];
        
             }
    
        }
        
    for (int k = 1; k < vektor.size(); k++) {
                   

try {
        if (k != 1) { 

          
          auto c=ProduktMatrica(m2,m1); 
        

for (int i = 0; i < m1.br_redova; i++) {
    
            for (int j = 0; j < m1.br_kolona; j++) {
        
            m2.elementi[i][j]=c.elementi[i][j];
        
             }
    
        }
       UnistiMatricu(c);
        }
}
catch(...) {
    UnistiMatricu(suma);
    UnistiMatricu(m2);
throw;    
} 
          auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); 
       try    {   for (int i = 0; i < m1.br_redova; i++) {


            for (int j = 0; j < m1.br_kolona; j++) {
        
            m3.elementi[i][j]=m2.elementi[i][j]*vektor[k];
        
             }
    
            }
     }
     catch(...) {
    
  UnistiMatricu(m3);  
  UnistiMatricu(suma);
  UnistiMatricu(m2);
  throw;
    
} 
     
       try    {  auto x=ZbirMatrica(suma,m3);
     
     
for (int i = 0; i < m1.br_redova; i++) {
    
            for (int j = 0; j < m1.br_kolona; j++) {
        
            suma.elementi[i][j]=x.elementi[i][j];
        
             }
    
        }
              UnistiMatricu(m3);  

       UnistiMatricu(x);
        }
    
   catch(...) {
    
  UnistiMatricu(m3);
  UnistiMatricu(m2);
  UnistiMatricu(suma);
  throw;
    
}    
    }
    for (int i = 0; i < m1.br_redova; i++) {
    
            for (int j = 0; j < m1.br_kolona; j++) {
        
            if (i==j) suma.elementi[i][j]+=1*vektor[0];
        
             }
    
        }
    UnistiMatricu(m2);
    
    return suma;
   
    }
int main() {


    Matrica<double> a, b, c; 
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
    std::vector<double> koeficijenti;
    a = StvoriMatricu<double>(m, m);

    std::cout << "Unesite elemente matrice A: "<<std::endl; UnesiMatricu('A', a);

    std::cout<<"Unesite red polinoma: ";

    int red;
    std::cin>>red;

    std::cout<<"Unesite koeficijente polinoma: ";

    for (int i = 0; i <= red; i++){
    int koef;
    std::cin>>koef;
    koeficijenti.push_back(koef);
    }
        IspisiMatricu(c = MatricniPolinom(a,koeficijenti),10,6,true);


}
    catch(std::bad_alloc) {
           std::cout << "Nema dovoljno memorije!\n";
         }
        UnistiMatricu(a);
         
         
return 0; 
    
}