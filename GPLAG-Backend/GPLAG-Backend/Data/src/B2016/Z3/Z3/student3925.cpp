/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename tip>
struct Matrica{
    int br, bk;
    tip **el=nullptr;
};


template <typename tip>
void UnistiMatricu(Matrica<tip> m){
    if(!m.el) return;
    for(int i(0); i<m.br;i++) delete[] m.el[i];
    delete[] m.el;
    m.el=nullptr;
}

template <typename tip>
void Sigurnounisti(Matrica<tip> &m){
    UnistiMatricu(m);
    m.el=nullptr;
}

template <typename tip>
Matrica<tip> StvoriMatricu (int br, int bk){
    Matrica<tip> m;
    m.br=br;
    m.bk=bk;
    m.el=new tip*[br];
    for(int i(0);i<br;i++) m.el[i]=nullptr;
    try{
        for(int i(0);i<br;i++){
            m.el[i]=new tip[bk];
        }
    }
    catch(...){
        UnistiMatricu(m);
        throw;
    }
    return m;
}

template<typename tip>
Matrica<tip> kopiraj(Matrica<tip> m){
    auto a(StvoriMatricu<tip>(m.br,m.bk));
    for(int i(0);i<m.br;i++){
        for(int j(0);j<m.bk;j++) a.el[i][j]=m.el[i][j];
    }
    return a;
}

template <typename tip>
void UnesiMatricu(char ime, Matrica<tip> &m){
    for(int i(0);i<m.br;i++)
    for(int j(0);j<m.bk;j++){
        std::cout << ime<<"("<<i+1<<","<<j+1<<") = ";
        std::cin >> m.el[i][j];
    }
}

template <typename tip>
void IspisiMatricu( const Matrica<tip> &m, int sirina, int preciznost=6, bool treba_brisati=false){
    for(int i(0);i<m.br;i++){
        for(int j(0);j<m.bk;j++){
            std::cout << std::setw(sirina)<<std::setprecision(preciznost)<<m.el[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu<tip>(m);
}

template<typename tip>
Matrica<tip> ZbirMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2){
    if(m1.br != m2.br || m1.bk!=m2.bk) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<tip>(m1.br,m1.bk));
    for(int i(0);i<m1.br;i++){
        for(int j(0);j<m2.bk;j++) m3.el[i][j]=m1.el[i][j]+m2.el[i][j];
    }
    return m3;
}

template <typename tip>
Matrica<tip> ProduktMatrica(Matrica<tip> m1, Matrica<tip> m2){
    if(m1.bk!=m2.br) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<tip>(m1.br,m2.bk));
    for(int i(0);i<m3.br;i++){
        for(int j(0);j<m3.bk;j++){
            tip suma(0);
            for(int k(0);k<m1.bk;k++) suma+=m1.el[i][k]*m2.el[k][j];
            m3.el[i][j]=suma;
        }
    }
    return m3;
}

template <typename tip>
Matrica <tip> inicijaliziraj (Matrica<tip> m){
    for(int i(0);i<m.br;i++){
        for(int j(0);j<m.bk;j++) m.el[i][j]=0;
    }
    return m;
}

template <typename tip>
Matrica <tip> MatricniPolinom(Matrica <tip> A, std::vector<double> v){
    if(A.br!=A.bk) throw std::domain_error("Matrica mora biti kvadratna");
    if(v.size()==0) {
        auto q(StvoriMatricu<tip>(A.br, A.bk));
        q=inicijaliziraj<tip>(q);
        return q;
    }
    
    auto jedinicnamatrica(StvoriMatricu<tip>(A.br, A.bk));
    for(int i(0);i<jedinicnamatrica.br;i++){
        for(int j(0);j<jedinicnamatrica.bk;j++) {
            if(i==j) jedinicnamatrica.el[i][j]=1;
            else jedinicnamatrica.el[i][j]=0;
    }
    }
    Matrica<tip> r;
    try{
    r=StvoriMatricu<tip>(A.br, A.bk);
    }
    catch(std::bad_alloc b){
        Sigurnounisti<tip>(jedinicnamatrica);
        throw;
    }
    r=inicijaliziraj<tip>(r);
    Matrica<tip> m;
    for(int k(0);k<v.size();k++){
        if(k==0){
        try{
            m=kopiraj<tip>(jedinicnamatrica);}
            catch(std::bad_alloc b){
                Sigurnounisti<tip>(jedinicnamatrica);
                Sigurnounisti<tip>(r);
                throw;
            }
        } 
        else {
            try{
            m=kopiraj<tip>(A);
            }
            catch(std::bad_alloc b){
                Sigurnounisti<tip>(m);
                Sigurnounisti<tip>(jedinicnamatrica);
                Sigurnounisti<tip>(r);
                throw;
            }
            for(int p(1);p<k;p++) {
                Matrica<tip> temp;
                try{
                temp=ProduktMatrica<tip>(m,A);
                }
                catch(std::bad_alloc b){
                    Sigurnounisti<tip>(m);
                    Sigurnounisti<tip>(jedinicnamatrica);
                    Sigurnounisti<tip>(r);
                    throw;
                }
            
                Sigurnounisti<tip>(m);
                m=temp;
        }
        }
        for(int i(0);i<m.br;i++){
            for(int j(0);j<m.bk;j++) m.el[i][j]=v[k]*m.el[i][j];
        }
        
        Matrica<tip> t;
        try{
        t=ZbirMatrica(r,m);
        } catch(std::bad_alloc b){
            Sigurnounisti<tip>(jedinicnamatrica);
            Sigurnounisti<tip>(m);
            Sigurnounisti<tip>(r);
            throw;
        }
        Sigurnounisti<tip>(m);
        Sigurnounisti<tip>(r);
        r=t;
    }
    
    UnistiMatricu<tip>(jedinicnamatrica);
    return r;
}


int main ()
{
    int a;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> a;
    if(a<0) return 0;
    std::cout << "Unesite elemente matrice A:" << std::endl;
    Matrica<double> m,c;
    try{
    m=StvoriMatricu<double>(a,a);
    UnesiMatricu('A', m);
    std::cout << "Unesite red polinoma: ";
    int p;
    std::cin >> p;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> v(p+1);
    for(int i(0);i<=p;i++) std::cin>> v[i];
    IspisiMatricu<double>(c=MatricniPolinom<double>(m,v), 10, 6);
}
catch(std::domain_error izuzetak){
    std::cout << izuzetak.what();
}
catch(std::bad_alloc){
    std::cout << "Nema dovoljno memorije!" << std::endl;
}
UnistiMatricu<double>(m); UnistiMatricu<double>(c);
	return 0;
}