/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

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
 Matrica<TipElemenata> StvoriMatricu(int brredova, int brkolona) {
 Matrica<TipElemenata> mat;
 mat.elementi=nullptr;
 mat.br_redova = brredova; mat.br_kolona = brkolona;
 try{
 mat.elementi = new TipElemenata*[brredova];
 }
 catch(...){
  mat.elementi=nullptr;
  throw;
 }
 for(int i = 0; i < brredova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < brredova; i++)
 mat.elementi[i] = new TipElemenata[brkolona];
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
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
 
template <typename TipElemenata>
 void IspisiMatricu
 (const Matrica<TipElemenata> &mat,
 int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
  if(!(mat.elementi)) return;
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 if(treba_brisati) UnistiMatricu(mat);
 }
 }
 /*
 template <typename TipElemenata>
 void IspisiMatricu
 (const Matrica<TipElemenata> &mat, int sirina_ispisa) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 
 }
 }
*/
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 
 template<typename tip>
 Matrica<tip> ProduktMatrica (const Matrica<tip> &m1, const Matrica<tip> &m2){
    /*
     std::cout<<"prva matrica\n";
     IspisiMatricu(m1, 5);
     std::cout<<"\ndruga matrica\n";
     IspisiMatricu(m2, 5);
     std::cout<<std::endl;
     
     */
     if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     auto nova(StvoriMatricu<tip>(m1.br_redova, m2.br_kolona));
     tip suma(0);
     for(int i=0; i<m1.br_redova; i++){
         for(int j=0; j<m2.br_kolona; j++){
             for(int k=0; k<m2.br_redova; k++){
                 suma+=m1.elementi[i][k]*m2.elementi[k][j];
             }
             nova.elementi[i][j]=suma;
             suma=0;
         }
     }
     /*
     std::cout<<"ispis u fji\n";
     IspisiMatricu(nova, 5);
     */
     return nova;
 }
 
 template<typename tip>
 Matrica<tip> NapraviJedinicnu (const Matrica<tip> &m1){
    
     auto nova(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
   
     for(int i=0; i<m1.br_redova; i++){
         for(int j=0; j<m1.br_kolona; j++){
             if(i==j) nova.elementi[i][j]=1;
             else nova.elementi[i][j]=0;
         }
 
     }
  
     return nova;
 }
 /*
  template<typename tip>
 void JediniceMatricu ( Matrica<tip> &m1){
   
     for(int i=0; i<m1.br_redova; i++)
         for(int j=0; j<m1.br_kolona; j++)
          
             m1.elementi[i][j]=1;
     
 }
 */
  template<typename tip>
 Matrica<tip> PomnoziSaSkalarom ( Matrica<tip> &m1, double skalar){
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m1.elementi[i][j]=m1.elementi[i][j]*skalar;
        
     return m1;
 }
 
   template<typename tip>
 void IskopirajPrvuUDrugu (const Matrica<tip> &m1, Matrica<tip>&m2){
     
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
           m2.elementi[i][j]=m1.elementi[i][j];
        
     
 }
 
 
 
  template<typename tip>
 Matrica<tip> MatricniPolinom (const Matrica<tip> &m1, const std::vector<double> &v){
     if(m1.br_kolona!=m1.br_redova) throw std::domain_error("Matrica nije kvadratna");
     Matrica<tip> hrkljus;
     
    
     auto nova(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
     auto temp(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
     auto temp1(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
      auto pamti(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
      IskopirajPrvuUDrugu( m1, pamti);
      IskopirajPrvuUDrugu( m1, temp);
     for(int i=0; i<v.size(); i++){
         if(i==0){
            IskopirajPrvuUDrugu( hrkljus=NapraviJedinicnu(m1), temp);
            UnistiMatricu(hrkljus);
            IskopirajPrvuUDrugu( PomnoziSaSkalarom(temp, v[0]), temp1);
           IskopirajPrvuUDrugu(temp1, nova);
         /*  
         std::cout<<"nova: "<<std::endl;
             IspisiMatricu(nova, 5);
             std::cout<<std::endl;
             */
            //nova=ZbirMatrica(PomnoziSaSkalarom( NapraviJedinicnu(m1),  v[0]), nova);
         }
         else{
             IskopirajPrvuUDrugu(m1, temp);
             
             if(i==1) IskopirajPrvuUDrugu(m1, temp);
            else  for(int u=0; u<i-1; u++){
             
            IskopirajPrvuUDrugu(hrkljus=ProduktMatrica(temp, m1), temp);
            UnistiMatricu(hrkljus);
            }
         
             IskopirajPrvuUDrugu(PomnoziSaSkalarom(temp, v[i]), temp1);
            /*
              std::cout<<"nakon skalara: "<<std::endl;
             IspisiMatricu(temp1, 5);
             std::cout<<std::endl;
             */
            IskopirajPrvuUDrugu( hrkljus=ZbirMatrica(nova, temp1), nova);
            UnistiMatricu(hrkljus);
             //nova=temp;
            /*
             std::cout<<"sad je nova: "<<std::endl;
             IspisiMatricu(nova, 5);
             std::cout<<std::endl;
             */
         }
         
     }
  UnistiMatricu(temp);UnistiMatricu(temp1); UnistiMatricu(pamti);
  return nova;
     
    
    
     
 }
 
 

int main() {
 Matrica<double> a, d; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, red_polinoma;
 double broj;
 //std::cout << "Unesi broj redova i kolona za matrice:\n";
 std::cout<<"Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 std::vector<double> vec;
 try {

 a = StvoriMatricu<double>(m, m);
 //b = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 //b=a;
 std::cout<<"Unesite red polinoma: ";
 std::cin>>red_polinoma;
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0; i<=red_polinoma; i++){
 std::cin>>broj;
 vec.push_back(broj);}
 //std::cout << "Unesi matricu B:\n";
// UnesiMatricu('B', b);
 //std::cout << "Zbir ove dvije matrice je:\n";
 //IspisiMatricu(c = ZbirMatrica(a, b), 7);
 //IspisiMatricu(d=ProduktMatrica(a,b), 7);
 IspisiMatricu(d=MatricniPolinom(a,vec), 10, 6);
 }
 
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 
 UnistiMatricu(a);  UnistiMatricu(d);
 return 0;
}
