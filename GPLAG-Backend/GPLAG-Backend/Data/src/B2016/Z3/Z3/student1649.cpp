/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    for(int i=0;i<br_redova;i++) for(int j=0;j<br_kolona;j++) mat.elementi[i][j]=0;
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
    std::cout.precision(preciznost);
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++) std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<< std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m3.br_redova;i++){
        for(int j=0;j<m3.br_kolona;j++){
            for(int k=0;k<m1.br_kolona;k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, std::vector<double> p){
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto P(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto Pomocna1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<m.br_redova;i++) Pomocna1.elementi[i][i]=1;
    for(int i=0;i<p.size();i++){
        if(i==0){
            for(int j=0;j<m.br_redova;j++) for(int k=0;k<m.br_redova;k++) P.elementi[j][k]=p[i]*Pomocna1.elementi[j][k];
        }else{
            auto Pomocna2(ProduktMatrica<TipElemenata>(Pomocna1,m));
            for(int j=0;j<m.br_redova;j++) for(int k=0;k<m.br_redova;k++){
                Pomocna1.elementi[j][k]=Pomocna2.elementi[j][k];
                Pomocna2.elementi[j][k]*=p[i];  
            } 
            auto Pomocna3(ZbirMatrica(P,Pomocna2));
            UnistiMatricu(Pomocna2);
            Pomocna2=P;
            P=Pomocna3;
            UnistiMatricu(Pomocna2);
        }
    }
    UnistiMatricu(Pomocna1);
    return P;
}
int main(){
    try{
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int Dimenzija(0);
        std::cin>>Dimenzija;
        std::cout<<"Unesite elemente matrice A: \n";
        auto A(StvoriMatricu<double>(Dimenzija,Dimenzija));
        UnesiMatricu('A',A);
        int RedPolinoma(0);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>RedPolinoma;
        std::vector<double>KoeficijentiPolinoma (RedPolinoma+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(auto &x:KoeficijentiPolinoma) std::cin>>x;
        IspisiMatricu(MatricniPolinom(A,KoeficijentiPolinoma),10,6,true);
        UnistiMatricu(A);
    }catch(...){
        std::cout<<"Problem sa memorijom";
    }
}
int main1 (){
    auto m1(StvoriMatricu<int>(2,2));
    UnesiMatricu('A',m1);
    std::vector<double> koef;
    auto m3(MatricniPolinom(m1,koef));
    IspisiMatricu(m3,3);
    UnistiMatricu(m3);
    UnistiMatricu(m1);
	return 0;
}