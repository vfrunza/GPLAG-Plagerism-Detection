#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
template <typename TipElemenata>
    struct Matrica {
         int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
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
    std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
    std::cin >> mat.elementi[i][j];
    }
 }
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=6,int preciznost=6,bool treba=false) {
    for(int i = 0; i < mat.br_redova; i++) {
    for(int j = 0; j < mat.br_kolona; j++)
    std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
    std::cout << std::endl;
    }
    if(treba)UnistiMatricu(mat);
 }
template <typename TipElemenata>
   void ZbirMatrica(Matrica<TipElemenata> &m1,
     Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i < m1.br_redova; i++)
    for(int j = 0; j < m1.br_kolona; j++)
    m1.elementi[i][j] += m2.elementi[i][j];
    
 }
  template <typename TipElemenata>
  int broj(Matrica<TipElemenata> a,Matrica<TipElemenata> b,int i,int j){
      int suma=0;
      for(int k=0;k<a.br_kolona;k++){
          suma+=a.elementi[i][k]*b.elementi[k][j];
      }
      return suma;
  }
template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(Matrica <TipElemenata>a,Matrica<TipElemenata> b){
     if(a.br_kolona!=a.br_redova||b.br_kolona!=b.br_redova||a.br_redova!=b.br_redova)throw std::domain_error{"“Matrice nisu saglasne za mnozenje"};
     Matrica<TipElemenata> c;
     c=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
     for(int i=0;i<a.br_kolona;i++){
         for(int j=0;j<a.br_kolona;j++){
             c.elementi[i][j]=broj(a,b,i,j);
         }
     }
   return c;
 }
 template <typename TipElemenata>
void mnozi(Matrica<TipElemenata> &c,int a){
     for(int i=0;i<c.br_kolona;i++){
         for(int j=0;j<c.br_kolona;j++){
             c.elementi[i][j]*=a;
         }
     }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> kopiraj(Matrica<TipElemenata> a){
     Matrica<TipElemenata>c;
     c=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
     for(int i=0;i<a.br_kolona;i++){
         for(int j=0;j<a.br_kolona;j++){
             c.elementi[i][j]=a.elementi[i][j];
         }
     }
     return c;
 }
  template <typename TipElemenata>
 Matrica<TipElemenata> digni(Matrica<TipElemenata> a,int i){
     Matrica<TipElemenata> c;
     c=kopiraj(a);
    for(int j=1;j<i;j++){
        Matrica<TipElemenata>e;
        e=(ProduktMatrica(c,a));
        UnistiMatricu(c);
        c=kopiraj(e);
        UnistiMatricu(e);
    }
   return c;       
 }
template <typename TipElemenata,typename iter>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a,int n,iter p ){
    if (n<0)throw std::domain_error{"Neispravan stepen polinoma"};
    if(a.br_kolona!=a.br_redova)throw std::domain_error{"Matrica mora biti kvadratna"};
    Matrica<TipElemenata>c;
    c=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
    for(int i=0;i<a.br_kolona;i++){
        for(int j=0;j<a.br_kolona;j++){
            if(i==j)c.elementi[i][j]=1;
            else c.elementi[i][j]=0;
        }
    }
    mnozi(c,*p);
     
    
    for(int i=1;i<=n;i++){
        Matrica<TipElemenata>e;
        e=digni(a,i);
        p++;
        
        mnozi(e,*p);
       
        ZbirMatrica(c,e);
        UnistiMatricu(e);
    }
    return c;
}//2 3 1 0 -2 3 3 -2 0 1
 
int main() {
    Matrica<double> a, b,c; // AUTOMATSKA INICIJALIZACIJA!!!
     int  n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
    a = StvoriMatricu<double>(n,n);
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', a);
    std::cout << "Unesite red polinoma: " ;
    int m;
    std::cin >> m;
    std::vector<int> v;
    std::cout << "Unesite koeficijente polinoma: ";
    for(int i=0;i<=m;i++){
        int temp;
        std::cin >> temp;
        v.push_back(temp);
        }
       
      
    c=MatricniPolinom(a,m,v.begin());
     IspisiMatricu(c,10);
 
    }
     catch(std::bad_alloc) {
     std::cout << "Nema dovoljno memorije!\n";
     }catch(std::domain_error er){
         std::cout << "Izuzetak: "<<er.what() << std::endl;
     }
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
 return 0;
}
