#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
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
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++)
    for(int j=0;j<mat.br_kolona;j++){
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica <TipElemenata> &mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati)
    UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimnezije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m2.br_kolona;j++){
        TipElemenata suma(0);
        for(int k=0;k<m1.br_kolona;k++)
        suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
    }
    return m3;
}

template<typename TipElemenata> 
Matrica <TipElemenata> KopirajMatricu(const Matrica<TipElemenata> &A){
    auto M(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++)
        M.elementi[i][j]=A.elementi[i][j];
        return M;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A,std::vector<double> p){
    if(A.br_redova!=A.br_kolona)
    throw std::domain_error("Matrica mora biti kvadratna");
    if(p.size()==0){
        auto m3(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++)
        m3.elementi[i][j]=0;
        return m3;
    }
    auto prviclan(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0;i<A.br_redova;i++)
    for(int j=0;j<A.br_kolona;j++)
    if(i==j)
    prviclan.elementi[i][j]=p[0];
    else
    prviclan.elementi[i][j]=0;
    auto suma(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0;i<A.br_redova;i++)
    for(int j=0;j<A.br_kolona;j++)
    suma.elementi[i][j]=0;
    Matrica <TipElemenata> M;
    for(int i=1;i<p.size();i++){
        M=KopirajMatricu(A);
        for(int k=1;k<i;k++){
            auto pomocna=M;
            M=ProduktMatrica(M,A);
            UnistiMatricu(pomocna);
        }
        for(int k=0;k<A.br_redova;k++)
        for(int l=0;l<A.br_kolona;l++)
        M.elementi[k][l]*=p[i];
        auto pomocna=suma;
        suma=ZbirMatrica(suma,M);
        UnistiMatricu(pomocna);
        UnistiMatricu(M);
    }
    Matrica<TipElemenata> polinom;
    polinom=ZbirMatrica(prviclan,suma);
    UnistiMatricu(prviclan);
    UnistiMatricu(suma);
    return polinom;
}

int main ()
{
    Matrica<double> a,b;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    a=StvoriMatricu<double>(m,m);
    std::cout<<"Unesite elemente matrice A:\n";
    UnesiMatricu('A',a);
    int n;
    cout<<"Unesite red polinoma: ";
    cin>>n;
    std::vector<double> koeficijenti(n+1);
    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0;i<n+1;i++)
    cin>>koeficijenti[i];
    IspisiMatricu(b=MatricniPolinom(a,koeficijenti),10);
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}