/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica{
    int dimenzija;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.dimenzija; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
    
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int dimenzija){
    Matrica<TipElemenata> mat;
   
    mat.elementi=new TipElemenata*[dimenzija];
    for(int i=0; i<dimenzija; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<dimenzija; i++){
            mat.elementi[i]=new TipElemenata[dimenzija];
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.dimenzija; i++){
        for(int j=0; j<mat.dimenzija; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.dimenzija!=m2.dimenzija) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.dimenzija));
    for(int i=0; i<m1.dimenzija; i++){
        for(int j=0; j<m1.dimenzija; j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    
    return m3;
}

template <typename TipElemenata>
 
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, int n,  )

template <typename TipElemenata>
void  IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost(6), bool treba_pisati(false)){
    for(int i=0; i<mat.dimenzija; i++){
        for(int j=0; j<mat.dimenzija; j++){
            std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
    }
    if(treba_pisati==true) UnistiMatricu(mat);
}


template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1,  Matrica<TipElemenata> m2){
    if(m1.dimenzija!=m2.dimenzija) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.dimenzija));
    for(int i=0; i<m1.dimenzija; i++){
        for(int j=0; j<m1.dimenzija; j++){
            for(int k=0; k<m1.dimenzija; k++){
            m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
        }
    }
}
return m3;
}

int main ()
{
    Matrica<double> a, b, c;
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    std::cout<<"Unesite dimenziju druge kvadratne  matrice:";
    int druga;
    std::cin>>druga;
    try{
        a=StvoriMatricu<double>(dimenzija);
        b=StvoriMatricu<double>(druga);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite elemente matrice B:\n";
        UnesiMatricu('B', b);
        c=ProduktMatrica<double>(a, b);
        IspisiMatricu<double>(c, 5, 6, false);
       std::cout<<"Unesite red polinoma: ";
       int red;
       std::cin>>red;
       std::cout<<"Unesite koeficijente polinoma: ";
       std::vector<int> v;
       for(int i=0; i<red; i++){
           int unos;
           std::cin>>unos;
           v.push_back(unos);
       }
       //poziva se fja matricni polinom
        
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
        
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
	return 0;
}
