/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica <TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova] {};
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(std::bad_alloc) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
void NapraviJedinicnu(Matrica <TipElemenata>& mat,bool jedinicna)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            if(i==j && jedinicna) mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> Transformiraj(Matrica<TipElemenata> mat1,Matrica <TipElemenata> mat2, double k){
    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova, mat1.br_kolona));
    
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat1.br_kolona;j++){
            mat3.elementi[i][j]=mat1.elementi[i][j]+k*mat2.elementi[i][j];
        }
    }
    UnistiMatricu(mat1);
    return mat3;
    
}

template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2, bool unisti=false){
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat2.br_kolona;j++){
            TipElemenata suma=TipElemenata();
            for(int k=0;k<mat1.br_kolona;k++){
                suma=suma+mat1.elementi[i][k]*mat2.elementi[k][j];
            }
            mat3.elementi[i][j]=suma;
        }
    }
    if(unisti) UnistiMatricu(mat1);
   return mat3; 
    
}

template <typename TipElemenata, typename IterTip>
Matrica <TipElemenata> MatricniPolinom(Matrica <TipElemenata> A, int n, IterTip polinom){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto stepen(StvoriMatricu<TipElemenata>(A.br_redova,A.br_redova));
    NapraviJedinicnu(stepen,true);
    auto zbir(StvoriMatricu<TipElemenata>(A.br_redova, A.br_redova));
    NapraviJedinicnu(zbir, false);

    int i=0;
    while(i<=n){
        try{
        zbir=Transformiraj(zbir, stepen,*polinom);
       stepen=ProduktMatrica(stepen, A,true);
       
        polinom++;
        i++;}
        catch(std::bad_alloc){
            UnistiMatricu(zbir);UnistiMatricu(stepen);throw;
        }
    }
    UnistiMatricu(stepen);
 return zbir;   
}


int main ()
{
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    auto A(StvoriMatricu<double>(n, n));
    try{
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    
    UnesiMatricu('A', A);
    std::cout<<"Unesite red polinoma: ";
    std::cin>>n;
    std::vector<double> koef(n+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i=0;i<=n;i++) std::cin>>koef[i];
    auto zbir(MatricniPolinom<double>(A,n, koef.begin() ));
    IspisiMatricu(zbir,10);
        UnistiMatricu(zbir);
    }
    catch(std::bad_alloc){
        
    }
    
    UnistiMatricu(A);
    return 0;
}
