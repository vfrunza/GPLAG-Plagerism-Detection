/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <new>
#include <vector>

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

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
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

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            m3.elementi[i][j]=TipElemenata();
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            for(int k=0;k<m1.br_kolona;k++)
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> PomnoziMatricuSkalarom(const Matrica<TipElemenata> &m, double s){
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            m3.elementi[i][j]=m.elementi[i][j]*s;
        }
    }
    return m3;
}

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, IterTip koef){
    if(n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<TipElemenata> P(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            P.elementi[i][j]=TipElemenata();
        }
    }
    auto a(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<a.br_kolona;j++){
            if(i==j) a.elementi[i][j]=1;
            else a.elementi[i][j]=0;
        }
    }
    Matrica<TipElemenata> b,c;
    b=PomnoziMatricuSkalarom(a,*koef++);
    c=P;
    P=ZbirMatrica(P,b);
    UnistiMatricu(c);
    UnistiMatricu(b);
    for(int i=1;i<=n;i++){
        b=a;
        a=ProduktMatrica(a,m);
        UnistiMatricu(b);
        b=PomnoziMatricuSkalarom(a,*koef++);
        c=P;
        P=ZbirMatrica(P,b);
        UnistiMatricu(c);
        UnistiMatricu(b);
    }
    UnistiMatricu(a);
    return P;
}

int main ()
{
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    Matrica<double> a,p;
    try{
        a=StvoriMatricu<double>(dimenzija,dimenzija);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v(n+1);
        for(double &x:v) std::cin>>x;
        IspisiMatricu(p=MatricniPolinom(a,n,v.begin()),10,6);
    }
    catch(...){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(p);
	return 0;
}
