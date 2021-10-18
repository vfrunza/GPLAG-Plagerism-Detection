/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
 {
     Matrica<TipElemenata> mat;
     mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    try {
     mat.elementi=new TipElemenata*[br_redova]; ////
     for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
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
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
     for(int i=0; i<mat.br_redova; i++)
     for(int j=0; j<mat.br_kolona; j++) {
         std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
         std::cin >> mat.elementi[i][j];
     }
 }
 
 template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
     for(int i=0; i<mat.br_redova; i++){
         for(int j=0; j<mat.br_kolona; j++)
         std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
         std::cout << std::endl;
     }
         if(treba_brisati)
        UnistiMatricu(mat);
 }
 
 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
     if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            return m3;
 }
template <typename TipElemenata> 
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));   ////
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
            for(int k=0; k<m2.br_redova; k++)
            m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
        }
        return m3;    
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> p){
    if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> polinom(StvoriMatricu<TipElemenata>(m.br_redova, m.br_redova));
    if(p.size()==0){
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                polinom.elementi[i][j]=0;
            return polinom;    
    }
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++){
            if(p.size()==1 && i==j){
            polinom.elementi[i][j]=p[0];
            }
            else if(p.size()==1){
            polinom.elementi[i][j]=0;
            }
    
            else{ polinom.elementi[i][j]=p[1]*m.elementi[i][j];
                if(i==j) polinom.elementi[i][j]+=p[0];
        }
    }
    }
    auto x(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona)); ///
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            x.elementi[i][j]=m.elementi[i][j];
        //Matrica<TipElemenata> *matrica;
        //matrica=new Matrica<TipElemenata>[p.size()];
        //for(int i=0; i<p.size(); i++){
        
        
        //matrica[2]=(StvoriMatricu<TipElemenata>(m.br_redova, m.br_redova));
        //for(int i=0; i<m.br_redova; i++)
        //    for(int j=0; j<m.br_redova; j++)
          //      matrica[2].elementi[i][j]=m.elementi[i][j];
    for(int i=2; i<p.size(); i++){
         x=ProduktMatrica(x, m);       /////
         
         for(int j=0; j<m.br_redova; j++)
            for(int k=0; k<m.br_redova; k++)
                polinom.elementi[j][k]+=p[i]*x.elementi[j][k];
    }
     //       UnistiMatricu(x);
            return polinom;
        }
        

 int main() {
     Matrica<double> a, b, c;
     int n;
     std::cout << "Unesite dimenziju kvadratne matrice: ";
     std::cin >> n;
         a=StvoriMatricu<double>(n, n);
         std::cout << "Unesite elemente matrice A:\n";
         UnesiMatricu('A', a);
         std::cout << "Unesite red polinoma: ";
         int x;
         std::cin >> x;
         std::vector<double> p(x+1);
         std::cout << "Unesite koeficijente polinoma: ";
         for(int i=0; i<x+1; i++)
            std::cin >> p[i];
        IspisiMatricu(c=MatricniPolinom(a, p), 10, 6); ////
     
     UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
	
	/* Matrica<double> m1;
    m1 = StvoriMatricu<double>(2,2);
    UnesiMatricu<double>('A', m1);
    IspisiMatricu(m1, 5, 2, true); */
	return 0;
}