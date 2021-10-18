/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int  br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
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
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica( const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m3.br_redova; i++)
        for(int j=0; j<m3.br_kolona; j++)
            m3.elementi[i][j]=0;
            
    for(int i=0; i<m3.br_redova; i++)
        for(int j=0; j<m3.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> StepenMatrice(const Matrica<TipElemenata> &m, int k){
    Matrica<TipElemenata> m1, jedinicna(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<jedinicna.br_redova; i++)
        for(int j=0; j<jedinicna.br_kolona; j++){
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    
    if(k==0) {return jedinicna;}
    UnistiMatricu(jedinicna);
    m1=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            m1.elementi[i][j]=m.elementi[i][j];
    if(k==1) return m1;
    for(int i=2; i<=k; i++){
        auto pomocna(m1);
        m1=ProduktMatrica(m1,m);
        UnistiMatricu(pomocna);
    }
    return m1;
}

template<typename TipElemenata>
Matrica<TipElemenata> MnozenjeSaSkalarom(double x, const Matrica<TipElemenata> &m){
    Matrica<TipElemenata> m1(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m1.elementi[i][j]=x*m.elementi[i][j];
    return m1;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> p){
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> polinom(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<polinom.br_redova; i++)
        for(int j=0; j<polinom.br_kolona; j++)
            polinom.elementi[i][j]=0;
    if(p.size()==0) return polinom;
    for(int i=0; i<p.size(); i++){
        auto stepen(StepenMatrice(m,i));
        auto m1(MnozenjeSaSkalarom<TipElemenata>(p[i], stepen));
        auto mm(polinom);
        polinom=ZbirMatrica(polinom,m1);
        UnistiMatricu(mm);
        UnistiMatricu(m1);
        UnistiMatricu(stepen);
    }
    return polinom;
}

int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dim;
    std::cin>>dim;
    Matrica<double> a(StvoriMatricu<double>(dim,dim));
    std::cout<<"Unesite elemente matrice A: \n";
    UnesiMatricu('A',a);
    std::cout<<"Unesite red polinoma: ";
    int red;
    std::cin>>red;
    std::vector<double> vek(red+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for(auto &x:vek) std::cin>>x;
    auto m(MatricniPolinom(a,vek));
    IspisiMatricu(m,10,6);
    UnistiMatricu(a);
    UnistiMatricu(m);
	return 0;
}