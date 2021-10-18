/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector> 

template <typename TipElementa>
    struct Matrica {
        int br_redova, br_kolona;
        TipElementa **elementi=nullptr;
    };

template <typename TipElementa>
    void UnistiMatricu (Matrica<TipElementa> mat){
        if (!mat.elementi) return;
        for (int i=0;i<mat.br_redova;i++)
            delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElementa>
    Matrica<TipElementa> StvoriMatricu (int br_redova, int br_kolona){
        Matrica<TipElementa> mat;
        mat.br_redova=br_redova;mat.br_kolona=br_kolona;
        mat.elementi=new TipElementa*[br_redova];
        for (int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
        try{
            for (int i=0;i<br_redova;i++) 
                mat.elementi[i]= new TipElementa[br_kolona];
        }
        
        catch (...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElementa>
    void UnesiMatricu (char ime_matrice, Matrica<TipElementa> &mat){
        for (int i=0;i<mat.br_redova;i++){
            for (int j=0;j<mat.br_kolona;j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }

template <typename TipElementa>
    void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_ispisati=false){
        if (treba_ispisati){
            for (int i=0;i<mat.br_redova;i++){
                for (int j=0;j<mat.br_kolona;j++){
                    std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
                }   
                std::cout<<std::endl;
            }
        }
        return;
    }

template <typename TipElementa>
    Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
        if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
        for (int i=0;i<m1.br_redova;i++){
            for (int j=0;j<m1.br_kolona;j++){
                m3[i][j]=m1[i][j]+m2[i][j];
            }
        }
    return m3;
    }
    
template <typename TipElementa>
    Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona));
        for (int i=0;i<m1.br_redova;i++){
            for (int j=0;j<m2.br_kolona;j++){
                TipElementa suma(0);
                for (int k=0;k<m1.br_redova;k++){
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j]=suma;
            }
        }
        return m3;
    }
    
template <typename TipElementa>
    Matrica<TipElementa> MatricniPolinom (const Matrica<TipElementa>&a, const std::vector<int> &v){
        if (a.br_kolona!=a.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
        auto polinom(StvoriMatricu<TipElementa>(a.br_redova,a.br_kolona));
        if (v.size()==0){
            for (int i=0;i<a.br_redova;i++){
                for (int j=0;j<a.br_kolona;j++){
                    polinom.elementi[i][j]=0;
                }
            }
            return polinom;
        }
        
        auto pomocna(StvoriMatricu<TipElementa>(a.br_redova,a.br_kolona));
        pomocna=a;
        for (int i=0;i<a.br_redova;i++){
            for (int j=0;j<a.br_kolona;j++){
                if (i==j) polinom.elementi[i][j]=v[0]*1;
                else polinom.elementi[i][j]=0;
            }
        }
        
        for (int i=1;i<v.size();i++){
            for (int j=0;j<a.br_redova;j++){
                for (int k=0;k<a.br_kolona;k++){
                    if (i==1){
                        polinom.elementi[j][k]+=v[1]*a.elementi[j][k];
                    }
                    else{
                        pomocna=ProduktMatrica(pomocna,a);
                        polinom.elementi[i][j]+=v[i]*pomocna.elementi[i][j];
                    }
                }
            }
        }
        UnistiMatricu(pomocna);
        return polinom;
    }
int main ()
{
    Matrica<double>a,b;
    int m,r;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>r;
        std::vector<int>v(r+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for (int i=0;i<r+1;i++)
            std::cin>>v[i];
        b=StvoriMatricu<double>(m,m);
        b=MatricniPolinom<double>(b,v);
        IspisiMatricu(b,10,6,true);
    }
    catch (std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
	return 0;
}