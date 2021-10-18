#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <list>

template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> m){
    if(!m.elementi) return;
        for(int i=0; i<m.br_redova; i++) delete[] m.elementi[i];
        delete[] m.elementi;
    m.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata>m;
    m.br_redova=br_redova;
    m.br_kolona=br_kolona;
    m.elementi=new TipElemenata *[br_redova];
        for(int i=0; i<br_redova; i++){
            m.elementi[i]=nullptr;
        }
        
    try{
            for(int i= 0; i<br_redova; i++){
                m.elementi[i]=new TipElemenata[br_kolona];
            }
    }catch(...){
        UnistiMatricu(m);
        throw;
    }
    return m;
}

template <typename TipElemenata>
void UnesiMatricu(char ime, Matrica<TipElemenata>&m){
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++) {
            std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>m.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona  ) {
        throw std:: domain_error("Matrice nemaju jednake dimenzije!");
    }
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0; i< m1.br_redova; i++){
            for(int j=0; j<m1.br_kolona; j++){
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i< m1.br_redova; i++){
            for(int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
            }
        }
        for(int i=0; i<m1.br_redova; i++){
            for(int j=0; j<m2.br_kolona; j++){
                for(int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
        return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata>pomnozi(double x, const Matrica<TipElemenata>&m){
    auto mx(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++) mx.elementi[i][j]=x*m.elementi[i][j];
    }
    return mx;
}

template <typename TipElemenata>
Matrica<TipElemenata>jedinicna(const Matrica<TipElemenata>&m){
    auto x(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                if(i==j) x.elementi[i][j]=1;
                else x.elementi[i][j]=0;
            }
        }
        return x;
}

template <typename TipElemenata, typename PokTip>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata>&A, int n, PokTip p){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(n==0){
        auto nula(StvoriMatricu<TipElemenata>(A.br_kolona,A.br_redova) );
        for(int j=0; j<A.br_redova; j++) {
            for(int k=0; k<A.br_kolona; k++) nula.elementi[j][k]=0;
        }
        return nula;
    }
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    std::vector<Matrica<TipElemenata>>vekmatrica;
    std::vector<Matrica<TipElemenata>>vekmatrica2;
    
    for(int i=0; i<n+1; i++){
        if(i==0){
        auto jedm(jedinicna(A));
        vekmatrica.push_back(pomnozi(*(p),jedm));
        UnistiMatricu(jedm);
        
        }else if(i==1){
            vekmatrica2.push_back(A);
            vekmatrica.push_back(pomnozi(*(++p),A));
            
        }else{
            vekmatrica2.push_back(ProduktMatrica(A,vekmatrica2.at(i-2)));
            PokTip pozicija(p);
            for(int j=0; j<i; j++) pozicija++;
            vekmatrica.push_back(pomnozi(*(--pozicija),vekmatrica2.at(i-1)));
        }
    }
        std::vector<Matrica<TipElemenata>>rez;
                for(int i=0; i<vekmatrica.size()-1; i++){
                 if(i==0) rez.push_back(ZbirMatrica(vekmatrica.at(i), vekmatrica.at(i+1)));
                 else rez.push_back(ZbirMatrica(vekmatrica.at(i+1), rez.at(i-1)));
            }
    for(int i=0; i<vekmatrica.size(); i++){
        UnistiMatricu(vekmatrica.at(i));
    }
    for(int i=1; i<vekmatrica2.size(); i++){
        UnistiMatricu(vekmatrica2.at(i));
    }
    for(int i=0; i<rez.size()-1; i++){
        UnistiMatricu(rez.at(i));
    }
    
    return rez.at(rez.size()-1);
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&m, int sirina, int preciznost=6, bool treba_brisati=false){
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                std::cout<<std::setw(sirina)<<std::setprecision(preciznost)<<m.elementi[i][j];
            }
            std::cout<<std::endl;
        }
        if(treba_brisati) UnistiMatricu(m);
}

int main ()
{
    int m(0);
    Matrica<int>x,y;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        x=StvoriMatricu<int>(m,m);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',x);
        std::cout<<"Unesite red polinoma: ";
        int n(0);
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::list<int>l;
            for(int i=0; i<=n; i++){
                int k(0);
                std::cin>>k;
                l.push_back(k);
            }
        y=MatricniPolinom(x,n,l.begin());
        IspisiMatricu(y,10);
    }catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije";
    }
    UnistiMatricu(x);
    UnistiMatricu(y);
	return 0;
}
