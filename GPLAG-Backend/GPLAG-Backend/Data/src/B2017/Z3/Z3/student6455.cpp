/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata** elementi=nullptr;
    
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat ){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    
    mat.elementi=new TipElemenata*[br_redova];
    try{
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    
        for(int i=0;i<br_redova;i++){
            mat.elementi[i]=new TipElemenata[br_kolona]{};
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout.width(sirina_ispisa);
            std::cout.precision(preciznost);
            std::cout<<mat.elementi[i][j];}
            std::cout<<std::endl;
        
    }
    if(treba_brisati)
    UnistiMatricu(mat);
}
template <typename TipElemenata>
void ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2 ){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            //m1.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
                        m1.elementi[i][j]+=m2.elementi[i][j];

        }
    }
  
}
template<typename TipElemenata>
void PomnoziSkalarom(Matrica<TipElemenata> &m1, int skalar){
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m1.elementi[i][j]*=skalar;
        }
    }
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            TipElemenata suma(0);
            for(int k=0;k<m2.br_redova;k++){
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}


template <typename TipIteratora, typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A,int stepen_polinoma, TipIteratora iter ){
    if(stepen_polinoma<0) throw std::domain_error("Neispravan polinom");
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto matricni_polinom(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
      auto pomocna_matrica(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
     

    auto dodatna_matrica(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        auto dodatna_matrica3(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));

    
    for(int i=0;i<=stepen_polinoma;i++){
        if(i==0){
            for(int b=0;b<A.br_redova;b++){
                for(int j=0;j<A.br_kolona;j++){
                    if(b==j){
                    pomocna_matrica.elementi[b][j]=1;}
                    if(b!=j){
                    pomocna_matrica.elementi[b][j]=0;}
                }
            }
            PomnoziSkalarom(pomocna_matrica, *iter);//dodala
        ZbirMatrica(matricni_polinom, pomocna_matrica ); //dodala
        }
        if(i==1){
            for(int c=0;c<A.br_redova;c++){
                for(int j=0;j<A.br_kolona;j++){
                    pomocna_matrica.elementi[c][j]=A.elementi[c][j];
                    
                }
            }
            PomnoziSkalarom(pomocna_matrica, *iter);//dodala
           ZbirMatrica(matricni_polinom, pomocna_matrica ); //dodala
        }
        if(i!=0 && i!=1){
             //pomocna_matrica=ProduktMatrica(A,A);
             dodatna_matrica=ProduktMatrica(A,A);
             for(int e=0;e<A.br_redova;e++){
                 for(int f=0;f<A.br_kolona;f++){
                     pomocna_matrica.elementi[e][f]=dodatna_matrica.elementi[e][f];
                 }
             }
             UnistiMatricu(dodatna_matrica);
             
            for(int k=2;k<i;k++){
                dodatna_matrica3=ProduktMatrica(A,pomocna_matrica);
                for(int e=0;e<A.br_redova;e++){
                 for(int f=0;f<A.br_kolona;f++){
                     pomocna_matrica.elementi[e][f]=dodatna_matrica3.elementi[e][f];
                 }
             }
            // UnistiMatricu(dodatna_matrica3);
            }
                         UnistiMatricu(dodatna_matrica3);

         PomnoziSkalarom(pomocna_matrica, *iter);//dodala
           ZbirMatrica(matricni_polinom, pomocna_matrica ); //dodala   
        }
    
        iter++;
    }
    UnistiMatricu(pomocna_matrica);
    return matricni_polinom;
    
}
int main ()
{
    Matrica<int> a,c;
    try{
    int m;
    std::cout<<"Unesi dimenziju kvadratne matrice: \n";
    std::cin>>m;
    
        a=StvoriMatricu<int>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: \n";
        int stepen_polinoma;
        std::cin>>stepen_polinoma;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite koeficijente polinoma: \n";
        std::vector<int> koeficijenti;
        double broj;
        for(int i=0;i<=stepen_polinoma;i++){
            
            std::cin>>broj;
            koeficijenti.push_back(broj);
        }
        c=MatricniPolinom(a,stepen_polinoma,koeficijenti.begin());
        IspisiMatricu(c, 10,6);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
        
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    
    UnistiMatricu(a); UnistiMatricu(c);
	return 0;
}
