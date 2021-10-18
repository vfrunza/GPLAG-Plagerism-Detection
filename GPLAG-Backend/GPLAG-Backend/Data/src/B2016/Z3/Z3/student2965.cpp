/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete [] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova,int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0;i<br_redova;i++) 
            mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i=0;i<mat.br_redova;i++) 
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false) {
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) 
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++) 
        for(int j=0;j<m1.br_kolona;j++) 
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;j<m2.br_kolona;j++) {
            TipElemenata suma{};
            for(int k=0; k<m1.br_kolona;k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata>
void SaberiOve(const Matrica<TipElemenata> &a, const Matrica<TipElemenata> &b) {
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije");
    for(int i=0;i<a.br_redova;i++) {
        for(int j=0;j<a.br_kolona;j++) {
            a.elementi[i][j]+=b.elementi[i][j];
        }
    }
}
template<typename TipElemenata>
void MatricaProizvodSkalar(const Matrica<TipElemenata> &a, double n) {
    for(int i=0;i<a.br_redova;i++) {
        for(int j=0;j<a.br_kolona;j++) {
            a.elementi[i][j]*=n;
        }
    }
}
template <typename TipElemenata>
void KopiranjeMatrice(const Matrica<TipElemenata> &a, const Matrica<TipElemenata> &b) {
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije");
    for(int i=0;i<a.br_redova;i++) {
        for(int j=0;j<a.br_kolona;j++) {
            b.elementi[i][j]=a.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom( const Matrica<TipElemenata> &m, std::vector<TipElemenata> v_koef){
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    TipElemenata broj=v_koef.size();
    std::vector<Matrica<TipElemenata>> v(broj);  
    auto jedinicna=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    }     
    try {
        v[0]=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    }
    catch(std::bad_alloc) {
        throw;
    }
    KopiranjeMatrice(m,v[0]);
    for(int i=1;i<broj-1;i++) {
        try {
            v[i]=ProduktMatrica(v[i-1],m);
        }
        catch(std::bad_alloc) {
            for(int i=0;i<broj-1;i++) {
                UnistiMatricu(v[i]);
            }
            throw;
        }
    }
    
    for(int i=0;i<v_koef.size()-1;i++) {
        if(i==0) {
            MatricaProizvodSkalar(jedinicna,v_koef[0]);
            MatricaProizvodSkalar(v[0],v_koef[1]);
            SaberiOve(v[0],jedinicna);
            UnistiMatricu(jedinicna);
        }
        else {
            MatricaProizvodSkalar(v[i],v_koef[i+1]);
            SaberiOve(v[0],v[i]);
            UnistiMatricu(v[i]);
    
        }
    }
    return v[0];
}
    
int main ()
{
    Matrica<double> a,e;
    int m;
    std::vector<double> vektor;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try {
            a=StvoriMatricu<double>(m,m);
            std::cout<<"Unesite elemente matrice A:\n";
            UnesiMatricu('A',a);
            int r;
            std::cout<<"Unesite red polinoma: ";
            std::cin>>r;
            std::cout<<"Unesite koeficijente polinoma: ";
            double broj;
            broj=r+1;
            for(int i=0;i<broj;i++) {
                int k;
                std::cin>>k;
                vektor.push_back(k);
            }
            e=StvoriMatricu<double>(m,m);
            e=MatricniPolinom<double>(a,vektor);
            IspisiMatricu(e,10);
      
    }
    catch(std::bad_alloc) {
        std::cout<<"Memorija!";
    }

    UnistiMatricu(a);
    UnistiMatricu(e);
    UnistiMatricu(jedinicna);
    return 0;
}