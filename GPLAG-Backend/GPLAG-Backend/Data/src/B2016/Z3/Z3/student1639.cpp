#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

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
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
    for(int j = 0; j < mat.br_kolona; j++) {
    std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
    std::cin >> mat.elementi[i][j];
                                            }
 }
 
 
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
    for(int j = 0; j < mat.br_kolona; j++)
     std::cout << std::setw(sirina_ispisa) <<setprecision(preciznost) << mat.elementi[i][j];
     std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
 }
 
 
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
    for(int j = 0; j < m1.br_kolona; j++)
    m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata>&m2)
 {
   if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
   auto produkt(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona)); 
   for(int i=0; i<m1.br_redova; i++)
   {
      for(int j=0; j<m2.br_kolona; j++)
      {
         produkt.elementi[i][j]=0;
         for(int k=0; k<m2.br_redova; k++)
         produkt.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
      }
   }
   return produkt;
 }
 
 template<typename TipElemenata>
 void Kopiraj (Matrica<TipElemenata> &kopirana, Matrica <TipElemenata> org, bool unistiOrig)
 {
  kopirana = StvoriMatricu<TipElemenata>(org.br_redova, org.br_kolona);
  
  for(int i=0; i<org.br_redova; i++)
    for(int j=0; j<org.br_kolona;j++)
       kopirana.elementi[i][j]=org.elementi[i][j];
       
   if ( unistiOrig ) UnistiMatricu(org);
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> m, vector<double> koeficijenti)
 {
   if(m.br_redova!=m.br_kolona) throw domain_error("Matrica mora biti kvadratna");
   
   Kopiraj<TipElemenata>(m, m, false);
   
   auto p(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
   Matrica<TipElemenata> pomocna;
   auto jedinicna(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
   Kopiraj<TipElemenata>(pomocna,m, false);
   
   int ponavljanje(0);
   
     for(int i=0; i<m.br_redova; i++)
       for(int j=0; j<m.br_kolona; j++)
         p.elementi[i][j]=0;
    
    if(koeficijenti.empty()) return p;
    
     for(int i=0; i<m.br_redova; i++)
       for(int j=0; j<m.br_kolona; j++)
          if(i==j) jedinicna.elementi[i][j]=1*koeficijenti.at(0);
          else jedinicna.elementi[i][j]=0;
          
    auto temp = ZbirMatrica(p, jedinicna);
    UnistiMatricu(p);
    p = temp;
    
    
    for(int i=1; i<koeficijenti.size(); i++)
    {
       while(ponavljanje>0)
       {
         temp = ProduktMatrica(m, pomocna);
         UnistiMatricu(m);
         m = temp;
         
         ponavljanje--;
       }
       
       for(int j=0; j<m.br_redova; j++)
         for(int k=0; k<m.br_kolona; k++)
            p.elementi[j][k]+=m.elementi[j][k]*koeficijenti.at(i);

       ponavljanje=1;
    }
    
    UnistiMatricu(pomocna);
    UnistiMatricu(jedinicna);
    UnistiMatricu(m);
    
   return p;
 }

int main() {
 
 Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> n;
 try {
 a = StvoriMatricu<double>(n, n);

 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 cout << "Unesite red polinoma: ";
 int red_polinoma(0);
 double broj;
 cin >> red_polinoma;
 vector<double> koeficijenti;
 cout << "Unesite koeficijente polinoma: ";
 for(int i=0; i<=red_polinoma; i++)
 {
    cin >> broj;
    koeficijenti.push_back(broj);
    
 }
 
 IspisiMatricu(b=MatricniPolinom(a,koeficijenti),10,5,true);
 
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a);
 return 0;
}
