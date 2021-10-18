#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
 struct Matrica {
     int br_redova, br_kolona;
     TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
 
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
     if(!mat.elementi) return;
     for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
     delete[] mat.elementi;
     mat.elementi = nullptr;
 }
 
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
  Matrica<TipElemenata> mat;
  mat.br_redova = br_redova; mat.br_kolona = br_kolona;
  mat.elementi = new TipElemenata*[br_redova];
   
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 
 try {
   for(int i = 0; i < br_redova; i++)
   mat.elementi[i] = new TipElemenata[br_kolona];
 }
 catch(...) {
   UnistiMatricu(mat);
   throw;
 }
 return mat;
 }
 
 template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(Matrica<TipElemenata> m2, double x)
{
 Matrica<TipElemenata> nova;
    try{ nova = StvoriMatricu<TipElemenata>(m2.br_redova, m2.br_kolona);}
    
    catch(std::bad_alloc){throw;}
    for(int i(0); i < nova.br_redova; i++)
        for(int j(0); j < nova.br_kolona; j++)
            nova.elementi[i][j] *= x;
            
            return nova;
}

 template <typename TipElemenata>
     Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
   if (m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
   
   Matrica<TipElemenata> mat;
   try{ 
   mat = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);}
    catch(std::bad_alloc){ throw;
    }
    
   for(int i=0; i<m1.br_redova; i++) {
    for(int j=0; j<m2.br_kolona; j++) 
    {
     TipElemenata suma {};
    for(int k=0; k < m1.br_kolona; k++)
            {
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            }
    mat.elementi[i][j] = suma;
    }
   }
 return mat;
 }
 
 template <typename TipElemenata>
 Matrica<TipElemenata>  Stepenuj(const Matrica<TipElemenata> &m, int k) {
 Matrica<TipElemenata> nova;
 try{ 
  nova = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);}
    catch(std::bad_alloc){ throw; }
 
 if( k == 0) {
  for(int i=0; i<m.br_redova; i++) { 
    for(int j=0; j<m.br_kolona; j++) {
     if(i == j) nova.elementi[i][j]=1;
     else nova.elementi[i][j] = 0;
    }
  }
  return nova;
 }
 else if(k == 1) return m;
 
 else {
  nova = m;
for(int i=0; i<k; i++) {
 nova = ProduktMatrica(m, nova);
}
}
return nova;
}
 
 template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> &v) {
    
    if(mat.br_kolona != mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
 
    Matrica<TipElemenata> nova;
    try{ nova = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);}
    catch(std::bad_alloc){ throw; }
    
  if (v.size() == 0) {
    for(int i=0; i<mat.br_redova; i++) {
     for (int j=0; j<mat.br_kolona; j++) {
      nova.elementi[i][j] = 0;
     }
    }
    return nova;
    }
    
     Matrica<TipElemenata> e, st;
 
      for(int i=0; i<v.size(); i++) {
      st =Stepenuj(mat, i);
      e = PomnoziSkalarom(st, v[i]);
      nova = ZbirMatrica(nova, e);
      }
      
   UnistiMatricu(e);
   UnistiMatricu(st);
   
 return nova;
}
 
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
     for(int i = 0; i < mat.br_redova; i++)
     for(int j = 0; j < mat.br_kolona; j++) {
     std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
     std::cin >> mat.elementi[i][j];
     }
 }
 
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
     for(int i = 0; i < mat.br_redova; i++) {
         for(int j = 0; j < mat.br_kolona; j++)
         std::cout << std::setw(sirina_ispisa)<< std::setprecision(preciznost) << mat.elementi[i][j];
         std::cout << std::endl;
     }
     if(treba_brisati) UnistiMatricu(mat);
 }
 
 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_redova));
     for(int i = 0; i < m1.br_redova; i++)
     for(int j = 0; j < m1.br_kolona; j++)
     m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
 }

int main() {
 Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, n;
 std::cout << "Unesite dimenzije kvadratne matrice: ";
 std::cin >> m;
 
 std::vector<double> v;
 
 try {
     a = StvoriMatricu<double>(m, m);

     std::cout << "Unesite elemente matricu A:\n";
     UnesiMatricu('A', a);
     std::cout << "Unesite red polinoma: ";
     std::cin >> n;
     std::cout << "Unesite koeficijente polinoma: ";
     for(int i=0; i<n; i++) {
      double k;
      std::cin >> k;
      v.push_back(k);
     }
     
     auto x = MatricniPolinom(a, v);
     
     IspisiMatricu(x, 5);
    
    UnistiMatricu(x);
 }
 
 catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a);
 
 return 0;
 }
