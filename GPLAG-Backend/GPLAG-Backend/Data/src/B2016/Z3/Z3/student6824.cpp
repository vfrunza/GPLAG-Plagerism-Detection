#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
bool t{true};
template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata *[br_redova];
    for(int i=0; i<br_redova; i++)
     mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++)
         mat.elementi[i]=new TipElemenata[br_kolona];
    } 
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++)
     for(int j=0; j<mat.br_kolona; j++){
         std::cout <<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
         std::cin >>mat.elementi[i][j];
     }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m1.br_kolona; j++)
       m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
      return m3; 
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
         std::cout <<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<std::right<<mat.elementi[i][j];
         std::cout <<std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
  if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
  for(int i=0; i<m1.br_redova; i++){
      for(int j=0; j<m2.br_kolona; j++){
          TipElemenata suma{0};
          for(int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
          m3.elementi[i][j]=suma;      
   }
  }
  return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, const std::vector<double> &v){
    if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto m1(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    int ind{0};
    try{
        for(int i=0; i<m1.br_redova; i++){
         for(int j=0; j<m1.br_kolona; j++){
             m1.elementi[i][j]=0;
            }
        }
        if(v.size()==0) {return m1;}
        auto I(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                if(i==j) I.elementi[i][j]=v[0];
                else I.elementi[i][j]=0;
                m1.elementi[i][j]=m1.elementi[i][j]+I.elementi[i][j];
            }
        }
        UnistiMatricu(I);
        if(v.size()==1) {return m1;}
        else if(v.size()>=2){
          for(int i=0; i<m.br_redova; i++){
              for(int j=0; j<m.br_kolona; j++){
                  m1.elementi[i][j]=m1.elementi[i][j]+v[1]*m.elementi[i][j];
              }
           } 
        }
        if(v.size()==2) {return m1;}
       auto a(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int k=2; k<v.size(); k++){
         if(v.size()>=3 && ind==0){
            a=ProduktMatrica(m,m);
            for(int i=0; i<m.br_redova; i++){
                for(int j=0; j<m.br_kolona; j++){
                    m1.elementi[i][j]=m1.elementi[i][j]+v[k]*a.elementi[i][j];
                }
            }
            ind=1;
            if(v.size()==3) {UnistiMatricu(a); return m1;}
        }
        else if(v.size()>=4){
            a=ProduktMatrica(m,a);
            for(int i=0; i<m.br_redova; i++){
                for(int j=0; j<m.br_kolona; j++){
                    m1.elementi[i][j]=m1.elementi[i][j]+v[k]*a.elementi[i][j];
                }
            }
        }
      }
      UnistiMatricu(a);
    }
    catch(std::domain_error izuzetak){
        std::cout <<izuzetak.what()<<std::endl;
        return m;
    }
    return m1;
}
int main (){
    Matrica<double> a;
    int m, red;
    std::vector<double>v;
    double broj;
    std::cout <<"Unesite dimenziju kvadratne matrice: ";
    std::cin >>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout <<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        std::cout <<"Unesite red polinoma: ";
        std::cin >>red;
        std::cout <<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=red; i++){
            std::cin >>broj;
            v.push_back(broj);
        }
       a=MatricniPolinom(a,v);
       IspisiMatricu(a,10,5,t);
    }
    catch(std::bad_alloc){
        std::cout <<"Nema dovoljno memorije!\n";
    }
    if(t==true){}
    else UnistiMatricu(a);
	return 0;
}