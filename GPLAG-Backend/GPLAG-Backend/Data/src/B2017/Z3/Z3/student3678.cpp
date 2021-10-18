#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
template <typename NekiTip>
 struct matrica {
 int redovi, kolone;
 NekiTip **elementi=nullptr; 
 };
template <typename NekiTip>
 void Unistimatricu(matrica<NekiTip> mat) {
 if(!mat.elementi) return;
 for(int i=0; i<mat.redovi; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi=nullptr;
 }
template <typename NekiTip>
 matrica<NekiTip> Stvorimatricu(int redovi, int kolone) {
    matrica<NekiTip> mat;
     mat.redovi=redovi; mat.kolone = kolone;
     mat.elementi=new NekiTip*[redovi];
   for(int i=0; i<redovi; i++) mat.elementi[i] = nullptr;
 try {
 for(int i=0; i<redovi; i++)
 mat.elementi[i] = new NekiTip[kolone]{};
 }
 catch(...) {
 Unistimatricu(mat);
 throw;
 }
 return mat;
 }
template <typename NekiTip>
 void Unesimatricu(char ime_matrice, matrica<NekiTip> &mat) {
 for(int i=0; i<mat.redovi; i++)
 for(int j=0; j<mat.kolone; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
template <typename NekiTip>
 void Ispisimatricu(const matrica<NekiTip> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
       for(int i=0; i<mat.redovi; i++) {
           for(int j=0; j<mat.kolone; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
            std::cout << std::endl;
       }
       if(treba_brisati) Unistimatricu(mat);
 }
template <typename NekiTip>
 matrica<NekiTip> Zbirmatrica(const matrica<NekiTip> &mat1,const matrica<NekiTip> &mat2) {
 matrica<NekiTip> mat3;
 mat3= (Stvorimatricu<NekiTip>(mat1.redovi, mat1.kolone));
 for(int i=0; i<mat1.redovi; i++)
 for(int j=0; j<mat1.kolone; j++)
 mat3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
 return mat3;
 }

std::vector<double> UnosKoefPolin(int n){
    std::vector<double> vec;
    for(int i=0;i<n+1;i++){
        double x;
        std::cin>>x;
        vec.push_back(x);
    }
    
    return vec;
}

template <typename NekiTip>
 matrica<NekiTip> Produktmatrica(const matrica<NekiTip> &mat1,const matrica<NekiTip> &mat2) {
 if(mat1.kolone != mat2.redovi)
 throw std::domain_error("matrice nisu saglasne za mnozenje");
 matrica<NekiTip> mat3;
 mat3=(Stvorimatricu<NekiTip>(mat1.redovi, mat2.kolone));

 for(int i=0; i<mat1.redovi;i++){
            int k = 0;
            for(int j=0;j<mat3.kolone;j++){
                double suma(0);
                for(int l = 0;l<mat2.redovi;){
                    suma+=mat1.elementi[i][l] * mat2.elementi[l][j];
                    l++;
                }
                k++;
                mat3.elementi[i][j] = suma;
            }
 }
 return mat3;
 }
template <typename NekiTip>
 matrica<NekiTip> NapraviJedinicnu(const matrica<NekiTip> &mat1) {
  matrica<NekiTip> mat3;
  mat3=(Stvorimatricu<NekiTip>(mat1.redovi, mat1.kolone));
    
 for(int i=0; i<mat1.redovi;i++){
            for(int j=0;j< mat1.kolone;j++){
                if(i==j)    mat3.elementi[i][j]=1;
                else mat3.elementi[i][j]=0;
            }
 }
 return mat3;
 }
 template <typename NekiTip>
 matrica<NekiTip> Skalarno(const matrica<NekiTip> &mat1,double x) {
  matrica<NekiTip> mat3;
  mat3=(Stvorimatricu<NekiTip>(mat1.redovi, mat1.kolone));
 for(int i=0; i<mat1.redovi;i++){
            for(int j=0;j<mat1.kolone;j++){
                mat3.elementi[i][j]=x*mat1.elementi[i][j];
            }
 }
 return mat3;
 }
 
  template <typename NekiTip>
 matrica<NekiTip> NapraviOrginalnu(const matrica<NekiTip> &mat1) {
  matrica<NekiTip> mat3;
  mat3=(Stvorimatricu<NekiTip>(mat1.redovi, mat1.kolone));
 for(int i=0; i<mat1.redovi;i++){
            for(int j=0;j<mat1.kolone;j++){
                mat3.elementi[i][j]=mat1.elementi[i][j];
            }
 }
 return mat3;
 }
 
 
 template <typename NekiTip>
 matrica<NekiTip> matricniPolinom(const matrica<NekiTip> &mat1,const std::vector<double> &vec) {
 if(mat1.redovi != mat1.kolone) throw std::domain_error("matrica mora biti kvadratn");
 matrica<NekiTip> mat3;
 std::vector<matrica<NekiTip>> v;
 for(int i=0; i<(vec.size());i++){
            if(i==0) v.push_back(NapraviJedinicnu(mat1));
            else if(i==1) {matrica<NekiTip> mat;
            mat = NapraviOrginalnu(mat1);
            v.push_back(mat);}
            else
                v.push_back(Produktmatrica(mat1,v[i-1]));
            
 }
 std::vector<matrica<NekiTip>> v1;
 for(int i=0;i<(vec.size());i++){
            v1.push_back(Skalarno(v[i],vec[i]));
            
 }
 std::vector<matrica<NekiTip>> v2;

 for(int i=0;i<(vec.size())-1;i++){
     if(i==0) v2.push_back(Zbirmatrica(v1[i],v1[i+1]));
     else
        v2.push_back(Zbirmatrica(v2[i-1],v1[i+1]));
     if(i==(vec.size())-2) {mat3=v2[i];}
 }
 
 for(int i=0;i<vec.size();i++){
    Unistimatricu(v1[i]);Unistimatricu(v[i]);
 }
 for(int i=0;i<(vec.size())-2;i++)
    Unistimatricu(v2[i]);
 return mat3;
 }

int main() {
    matrica<double> a;
    matrica<double> c;
    int  n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = Stvorimatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        Unesimatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int m;
        std::cin>>m;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> vec(UnosKoefPolin(m));
    
       
        Ispisimatricu(c = matricniPolinom<double>(a, vec), 10);
        
        
    }
    catch(std::bad_alloc) {
             std::cout << "Nema dovoljno memorije!\n";
    }
 Unistimatricu(a); Unistimatricu(c);

 return 0;
}