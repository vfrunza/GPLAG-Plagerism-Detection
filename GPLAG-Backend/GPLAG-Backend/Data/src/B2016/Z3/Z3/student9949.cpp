/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata** elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu( Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> Kopija( Matrica <TipElemenata>m){
    Matrica <TipElemenata> m1;
    m1.br_redova=m.br_redova;
    m1.br_kolona=m.br_kolona;
    try{
    m1.elementi= new TipElemenata*[m1.br_redova];
    try{
    for(int i=0; i<m1.br_redova; i++){
        m1.elementi[i]=new TipElemenata [m1.br_kolona];
    }
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++){
            m1.elementi[i][j]=m.elementi[i][j];
        }
    }
      return m1;  
    }
    catch(...){
        throw;
    }}
    catch(...){
        UnistiMatricu<TipElemenata>(m1);
        throw;
    }
    
    
}
template <typename TipElemenata> 
void Dodjela(Matrica<TipElemenata>&m, Matrica<TipElemenata> m1){
    UnistiMatricu<TipElemenata>(m);
    try{
    m=Kopija<TipElemenata>(m1);}
    catch(...){throw;}
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica <TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    try{
        mat.elementi= new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata [br_kolona];
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    mat.elementi[i][j]=0;
                }
            }
        }
        catch(...){
            throw;
        }
    }
    catch(...){
        UnistiMatricu<TipElemenata>(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica <TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu<TipElemenata>(mat);
}
template <typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica <TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!= m2.br_redova|| m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        try{
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for( int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;}
    catch(...){
        throw;
    }
}
template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica( const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje!");
    try{
    Matrica <TipElemenata> m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i=0; i<m3.br_redova; i++){
        for(int j=0; j<m3.br_kolona; j++){
            for(int k=0; k<m2.br_redova; k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
    }
    catch(...){
        throw;
    }
}
template<typename TipElemenata>
void NapraviJedinicnuMatricu(Matrica<TipElemenata> &m){
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++){
            if( i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
        }
    }
}

template<typename TipElemenata>
Matrica <TipElemenata> Stepen( Matrica <TipElemenata> m, int n){
    try{
    Matrica <TipElemenata> m1=Kopija<TipElemenata>(m);
    if(n>=2){
        for(int i=0; i<n; i++){
            Dodjela<TipElemenata>(m, ProduktMatrica<TipElemenata>(m, m1));
        }
        return m1;
    }
    if(n==1)
        return m1;
    NapraviJedinicnuMatricu<TipElemenata>(m1);
    return m1; }
    catch(...){throw;}
}
template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom(Matrica<TipElemenata> m, double a){
    try{
    Matrica <TipElemenata> m1=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++){
            m1.elementi[i][j]=a*m.elementi[i][j];
        }
    }
    return m1;
    }
    catch(...){
        throw;
    }
}
template<typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom( const Matrica <TipElemenata> &m, std::vector<double> v){
    if(m.br_kolona!=m.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    bool nula=true;
    try{
    Matrica<TipElemenata> m1=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i=0; i<v.size(); i++){
        if(v[0]!=0) nula=false;
    }
    if(nula) return m1;
    for(int i=0; i<v.size(); i++){
        Matrica<TipElemenata> m2=Stepen<TipElemenata>(m, i);
        Matrica <TipElemenata> m3=PomnoziSaSkalarom<TipElemenata>(m2, v[i]);
        Dodjela<TipElemenata>(m1, ZbirMatrica<TipElemenata>(m1, m3));
        UnistiMatricu<TipElemenata>(m2);
        UnistiMatricu<TipElemenata>(m3);
    }
    return m1;
    } catch(...){
        throw;
    }
}
int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    try{
        Matrica<double> m= StvoriMatricu<double>(n,n);
        UnesiMatricu('A', m);
        std::cout<<"Unesite red polinoma: ";
        int a;
        std::cin>>a;
        a++;
        std::vector<double> v(a);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<a; i++){
            std::cin>>v[i];
        }
        IspisiMatricu<double>(MatricniPolinom<double>(m, v));
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije";
    }
	return 0;
}