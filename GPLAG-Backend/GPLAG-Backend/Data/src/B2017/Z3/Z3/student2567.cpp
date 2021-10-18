#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
using std::endl;
using std::cout;
using std::cin;
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
 mat.elementi[i] = new TipElemenata[br_kolona]{};
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
       for(int i = 0; i < mat.br_redova; i++) {
           for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
            std::cout << std::endl;
       }
       if(treba_brisati) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
 Matrica<TipElemenata> m3;
 m3= (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

std::vector<double> UnosKoefPolin(int n){
    std::vector<double> vec;
    for(int i(0);i<n+1;i++){
        double x;
        std::cin>>x;
        vec.push_back(x);
    }
    
    return vec;
}

template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
 if(m1.br_kolona != m2.br_redova)
 throw std::domain_error("Matrice nisu saglasne za mnozenje");
 Matrica<TipElemenata> m3;
 m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));

 for(int i = 0; i < m1.br_redova;i++){
            int k(0);
            for(int j(0);j<m3.br_kolona;j++){
                double suma(0);
                for(int l(0);l<m2.br_redova;){
                    suma+=m1.elementi[i][l] * m2.elementi[l][j];
                    l++;
                }
                k++;
                m3.elementi[i][j] = suma;
            }
 }
 return m3;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> NapraviJedinicnu(const Matrica<TipElemenata> &m1) {
  Matrica<TipElemenata> m3;
  m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    
 for(int i = 0; i < m1.br_redova;i++){
            for(int j(0);j< m1.br_kolona;j++){
                if(i==j)    m3.elementi[i][j]=1;
                else m3.elementi[i][j]=0;
            }
 }
 return m3;
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> Skalarno(const Matrica<TipElemenata> &m1,double x) {
  Matrica<TipElemenata> m3;
  m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova;i++){
            for(int j(0);j<m1.br_kolona;j++){
                m3.elementi[i][j]=x*m1.elementi[i][j];
            }
 }
 return m3;
 }
 
  template <typename TipElemenata>
 Matrica<TipElemenata> NapraviOrginalnu(const Matrica<TipElemenata> &m1) {
  Matrica<TipElemenata> m3;
  m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova;i++){
            for(int j(0);j<m1.br_kolona;j++){
                m3.elementi[i][j]=m1.elementi[i][j];
            }
 }
 return m3;
 }
 
 
 template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,const std::vector<double> &vec) {
 if(m1.br_redova != m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratn");
 Matrica<TipElemenata> m3;
 std::vector<Matrica<TipElemenata>> vektor;
 for(int i = 0; i < (vec.size());i++){
            if(i==0) vektor.push_back(NapraviJedinicnu(m1));
            else if(i==1) {Matrica<TipElemenata> mat;
            mat = NapraviOrginalnu(m1);
            vektor.push_back(mat);}
            else
                vektor.push_back(ProduktMatrica(m1,vektor[i-1]));
            
 }
 std::vector<Matrica<TipElemenata>> vektor1;
 for(int i(0);i<(vec.size());i++){
            vektor1.push_back(Skalarno(vektor[i],vec[i]));
            
 }
 std::vector<Matrica<TipElemenata>> vektor2;

 for(int i(0);i<(vec.size())-1;i++){
     if(i==0) vektor2.push_back(ZbirMatrica(vektor1[i],vektor1[i+1]));
     else
        vektor2.push_back(ZbirMatrica(vektor2[i-1],vektor1[i+1]));
     if(i==(vec.size())-2) {m3=vektor2[i];}
 }
 
 for(int i(0);i<vec.size();i++){
    UnistiMatricu(vektor1[i]);UnistiMatricu(vektor[i]);
 }
 for(int i(0);i<(vec.size())-2;i++)
    UnistiMatricu(vektor2[i]);
 return m3;
 }

int main() {
    Matrica<double> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int  n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: "<<endl;
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int m;
        std::cin>>m;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> vec(UnosKoefPolin(m));
    
       
        IspisiMatricu(c = MatricniPolinom<double>(a, vec), 10);
        
        
    }
    catch(std::bad_alloc) {
             std::cout << "Nema dovoljno memorije!\n";
    }
 UnistiMatricu(a); UnistiMatricu(c);

 return 0;
}
