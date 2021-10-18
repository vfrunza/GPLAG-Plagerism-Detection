/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata ** elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova ;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata *[br_redova];
    for(int i=0;i<br_redova;i++)mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
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
    for(int i = 0; i < mat.br_redova; i++)
    for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
    std::cout << std::endl;
    }
    if(treba_brisati)UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
    for(int j = 0; j < m1.br_kolona; j++)m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b){
    if(a.br_kolona!=b.br_redova)throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    auto c(StvoriMatricu<TipElemenata>(a.br_redova,b.br_kolona));
    
    for(int i=0;i<a.br_redova;i++){
        TipElemenata sum;
        for(int j=0;j<b.br_kolona;j++){
            sum=TipElemenata();
            for(int k=0;k<a.br_kolona;k++){
                sum=sum+a.elementi[i][k]*b.elementi[k][j];
            }
            c.elementi[i][j]=sum;
        }
    }
    
    return c;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica <TipElemenata> &a,std::vector<double>v){
    if(a.br_redova!=a.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
    
    auto c(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
     auto b(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
    for(int i=0;i<c.br_redova;i++){
        for(int j=0;j<c.br_kolona;j++){
            b.elementi[i][j]=0;
            if(i==j)c.elementi[i][j]=1;
            else c.elementi[i][j]=0;
        }
    }
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<c.br_redova;j++){
            for(int k=0;k<c.br_kolona;k++){
                b.elementi[j][k]=b.elementi[j][k]+v[i]*c.elementi[j][k];
            }
        }
        
        if(i==0){Matrica<TipElemenata>d(c); c=a; UnistiMatricu(d);}
        else if(i==1)c=ProduktMatrica(c,a);
        else {
            Matrica <TipElemenata>d(c);
            c=ProduktMatrica(c,a);
            UnistiMatricu(d);
        }
    }
    
    UnistiMatricu(c);
    
    return b;
    
}

int main ()
{
    Matrica<double> a;
    
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m ;
    
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A',a);
        
            int red(0);
            std::cout << "Unesite red polinoma: ";
            std::cin >> red;
                
                std::vector<double> v(red+1);
                std::cout << "Unesite koeficijente polinoma: ";
                for(int i=0;i<=red;i++)std::cin >> v[i] ;
                
                    Matrica<double>b;
                    b=MatricniPolinom(a,v);
                    IspisiMatricu(b,10,6);
                    
                        UnistiMatricu(a); UnistiMatricu(b);
        
    }
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    
    
    
	return 0;
}