#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector> 
#include <new>
//k
template<typename tip>
    struct Matrica{
        int br_redova, br_kolona;
        tip **elementi=nullptr;
    };

template<typename tip>
    void UnistiMatricu(Matrica<tip> mat){
        if(!mat.elementi)return;
        for(int i=0;i<mat.br_redova;i++)
            delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }

template<typename tip>
    Matrica<tip> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<tip> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new tip*[br_redova];
        for(int i=0;i<mat.br_redova;i++){
            mat.elementi[i]=nullptr;
        }
        try{
            for(int i=0;i<mat.br_redova;i++)
                mat.elementi[i]=new tip[mat.br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat);
        }
        return mat;
    }
    
template<typename tip>
    void UnesiMatricu(char ime_matrice, const Matrica<tip> &mat){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }
    
template<typename tip>
    void IspisiMatricu(const Matrica<tip> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            }
            std::cout<<"\n";
        }
        if(treba_brisati)UnistiMatricu(mat);
    }
    
template<typename tip>
    Matrica<tip> ZbirMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2){
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<tip>(m1.br_redova, m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m1.br_kolona;j++){
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    }

template<typename tip>
    Matrica<tip> ProduktMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2){
        if(m1.br_kolona!=m2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<tip>(m1.br_redova, m2.br_kolona));
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m2.br_kolona;j++){
                m3.elementi[i][j]=0;
                for(int k=0;k<m1.br_kolona;k++){
                    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        return m3;
    }
    
template<typename tip>
    void PomnoziSkalarom(const Matrica<tip> &m, double a){
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
                m.elementi[i][j]*=a;
    }
    
template<typename tip>
    void Prekopiraj(const Matrica<tip> &a, const Matrica<tip> &b){
        for(int i=0;i<a.br_redova;i++)
            for(int j=0;j<a.br_kolona;j++)
                b.elementi[i][j]=a.elementi[i][j];
    }

template<typename tip>
    void PostaviNaNula(const Matrica<tip> &a){
        for(int i=0;i<a.br_redova;i++) 
            for(int j=0;j<a.br_kolona;j++)
                a.elementi[i][j]=0;
    }
    
template<typename tip>
    void PostaviNaJedinicnu(const Matrica<tip> &a){
        for(int i=0;i<a.br_redova;i++) 
            for(int j=0;j<a.br_kolona;j++)
                if(i!=j)a.elementi[i][j]=0; else a.elementi[i][j]=1;
    }
    
template<typename tip>
    void Ocisti(const Matrica<tip> &a, const Matrica<tip> &s, const Matrica<tip> &d, bool q, bool w, bool e){
        if(q)UnistiMatricu(a);
        if(w)UnistiMatricu(s);
        if(e)UnistiMatricu(d);
    }

template<typename tip>
    Matrica<tip> MatricniPolinom(const Matrica<tip> &a, std::vector<double> v){
        if(a.br_kolona!=a.br_redova)throw std::domain_error("Matrica nije kvardatna");
        int n=a.br_kolona;
        Matrica<tip> stepen, rezultat, pomocna1, pomocna2;
        bool pom1=false;
        try{
            stepen=StvoriMatricu<tip>(n, n);
            PostaviNaJedinicnu(stepen);
        }
        catch(...){
            Ocisti(stepen, rezultat, pomocna1, false, false, pom1);
            throw;
        }
        try{
            rezultat=StvoriMatricu<tip>(n, n);
            PostaviNaNula(rezultat);
        }
        catch(...){
            Ocisti(stepen, rezultat, pomocna1, true, false, pom1);
            throw;
        }
        for(int i=0;i<v.size();i++){
            if(i!=0){
                try{
                    pomocna1=ProduktMatrica(stepen, a);
                    pom1=true;
                }
                catch(...){
                    Ocisti(stepen, rezultat, pomocna1, true, true, pom1);
                    throw;
                }
            } else {
                try{
                    pomocna1=StvoriMatricu<tip>(n, n);
                    PostaviNaJedinicnu(pomocna1);
                    pom1=true;
                }
                catch(...){
                    Ocisti(stepen, rezultat, pomocna1, true, true, pom1);
                    throw;
                }
            }
            Prekopiraj(pomocna1, stepen);
            PomnoziSkalarom(pomocna1, v[i]);
            try{
                pomocna2=ZbirMatrica(rezultat, pomocna1);
            }
            catch(...){
                Ocisti(stepen, rezultat, pomocna1, true, true, pom1);
                throw;
            }
            UnistiMatricu(pomocna1);
            pom1=false;
            UnistiMatricu(rezultat);
            rezultat=pomocna2;
        }
        UnistiMatricu(stepen);
        return rezultat;
    }

int main(){
    Matrica<double> a, b;
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
        a=StvoriMatricu<double>(n, n);
    }
    catch(...){
        return 0;
    }
    std::cout<<"Unesite elemente matrice A:\n";
    UnesiMatricu('A', a);
    int k;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>k;
    std::vector<double> v(k+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for(auto &i:v)std::cin>>i;
    try{
        b=MatricniPolinom(a, v);
    }
    catch(...){
        UnistiMatricu(a);
        return 0;
    }
    IspisiMatricu(b, 10, 6, true);
    UnistiMatricu(a);
    return 0;
}