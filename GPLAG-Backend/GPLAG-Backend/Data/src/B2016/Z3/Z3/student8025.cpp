#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <new>
template <typename TipElemenata>
struct Matrica{
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
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    }catch(...){
UnistiMatricu(mat);
throw;
    }
return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati==true){
        UnistiMatricu(mat);
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona != m2.br_kolona) 
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
        
    }
    
return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> SkProduktMatrica(double a, Matrica<TipElemenata> b){
    for(int i=0; i<b.br_redova; i++){
        for(int j=0; j<b.br_kolona; j++){
            b.elementi[i][j]=(a*b.elementi[i][j]);
        }
    }
    return b;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b){
    if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto c(StvoriMatricu<TipElemenata>(a.br_redova , b.br_kolona));
   for(int i=0; i<c.br_redova; i++){
       for(int j=0; j<c.br_kolona; j++){
           double suma(0);
           for(int z=0; z<b.br_redova; z++){
               suma+=a.elementi[i][z]*b.elementi[z][j];
           }
           c.elementi[i][j]=suma;
       }
   } 
   return c;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, std::vector<double> v){
    if(A.br_redova != A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto nova(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
     if(v.size()==0) {
         return nova;
     }
    for(int i=0; i<nova.br_redova; i++){
        for(int j=0; j<nova.br_kolona; j++){
            nova.elementi[i][j]=0;
            if(i==j) nova.elementi[i][j]=1;
        }
    }
 
    auto pocetna(SkProduktMatrica<TipElemenata>(v[0],nova));
    auto suma(pocetna);
    auto produkt(A);
    Matrica<TipElemenata> haha;
   try{
    haha=(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
   } catch(...){
       UnistiMatricu(suma);
       UnistiMatricu(produkt);
       UnistiMatricu(nova);
       throw;
   }
   Matrica<TipElemenata> pomocna;
   try{
   pomocna=(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
   } catch(...){
       UnistiMatricu(suma);
       UnistiMatricu(haha);
       UnistiMatricu(produkt);
       UnistiMatricu(nova);
       throw;
   }
   Matrica<TipElemenata> druga;
   try{
   druga=(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
   } catch(...){
       UnistiMatricu(suma);
       UnistiMatricu(haha);
       UnistiMatricu(pomocna);
       UnistiMatricu(produkt);
       UnistiMatricu(nova);
       throw;
   }
   for(int i=0; i<pomocna.br_redova; i++){
        for(int j=0; j<pomocna.br_kolona; j++){
            pomocna.elementi[i][j]=A.elementi[i][j];
        }
    }
    for(int i=0; i<haha.br_redova; i++){
        for(int j=0; j<haha.br_kolona; j++){
            haha.elementi[i][j]=A.elementi[i][j];
        }
    }
    for(int i=0; i<druga.br_redova; i++){
        for(int j=0; j<druga.br_kolona; j++){
            druga.elementi[i][j]=suma.elementi[i][j];
        }
    }
    int n(v.size());
    for(int i=1; i<n; i++){
        if(i>1){
   
            try{
                produkt=ProduktMatrica<TipElemenata>(pomocna,A);
            }catch(...){
                UnistiMatricu(haha);
                UnistiMatricu(druga);
                UnistiMatricu(pomocna);
                UnistiMatricu(suma);
                UnistiMatricu(produkt);
                throw;
            }
            for(int i=0; i<haha.br_redova; i++){
        for(int j=0; j<haha.br_kolona; j++){
            haha.elementi[i][j]=produkt.elementi[i][j];
        }
    }
       for(int i=0; i<pomocna.br_redova; i++){
        for(int j=0; j<pomocna.br_kolona; j++){
            pomocna.elementi[i][j]=produkt.elementi[i][j];
        }
    }
       UnistiMatricu(produkt); 
        }
           if(i==1){
               UnistiMatricu(suma);
           }   
        try{
        suma=ZbirMatrica(druga,SkProduktMatrica(v[i],haha));
        }catch(...){
            UnistiMatricu(haha);
            UnistiMatricu(druga);
            UnistiMatricu(pomocna);
            UnistiMatricu(suma);
            throw;
        }
         for(int i=0; i<druga.br_redova; i++){
        for(int j=0; j<druga.br_kolona; j++){
            druga.elementi[i][j]=suma.elementi[i][j];
        }
    }
    if(i<n-1){
    UnistiMatricu(suma);
    }
    }
    UnistiMatricu(druga);
    UnistiMatricu(pomocna);
    UnistiMatricu(haha);
    return suma;
}
int main ()
{
    int n,m;
    double k;
    Matrica<double> A;
    Matrica<double> c;
    std::vector<double> v;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
        A=StvoriMatricu<double>(n,n);
       std::cout<<"Unesite elemente matrice A: "<<std::endl;
       UnesiMatricu('A',A);
       std::cout<<"Unesite red polinoma: ";
       std::cin>>m;
       std::cout<<"Unesite koeficijente polinoma: ";
       for(int i=0; i<m+1; i++){
           std::cin>>k;
           v.push_back(k);
       }
      c=MatricniPolinom<double>(A,v);
      IspisiMatricu(c,10);
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    UnistiMatricu(A); UnistiMatricu(c);
	return 0;
}