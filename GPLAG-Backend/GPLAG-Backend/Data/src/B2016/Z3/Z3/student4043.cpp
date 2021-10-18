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
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
            delete[] mat.elementi;
            mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
            try {
                for(int i = 0; i < br_redova; i++)
                    mat.elementi[i] = new TipElemenata[br_kolona];
            }
            catch(...) {
                UnistiMatricu(mat);
                throw;
            }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i = 0; i < m1.br_redova; i++) {
            for(int j = 0; j < m1.br_kolona; j++) m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
        return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for(int i(0);i<m1.br_redova;i++) {
            for(int j(0);j<m2.br_kolona;j++) {
                TipElemenata suma(0);
                for(int k(0);k<m1.br_kolona;k++) {
                    suma+=(m1.elementi[i][k]*m2.elementi[k][j]);
                }
                m3.elementi[i][j]=suma;
            }
        }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a,std::vector<double> p) {
        if(a.br_kolona!=a.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
        auto pa(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
        for(int i(0);i<a.br_redova;i++) {
            for(int j(0);j<a.br_kolona;j++) {
                pa.elementi[i][j]=0;
            }
        }
        if(p.size()==0) return pa;
        else {
            auto jedinicna(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
            for(int i(0);i<jedinicna.br_redova;i++) {
                for(int j(0);j<jedinicna.br_kolona;j++) {
                    if(i==j) jedinicna.elementi[i][j]=1*p[0];
                    else jedinicna.elementi[i][j]=0;
                }
            }
            pa=jedinicna;
            auto m(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
            m=a;
            for(int k(1);k<p.size();k++) {
                if(k!=1) m=ProduktMatrica(m,a);
                if(p[k]!=0) {
                    for(int i(0);i<m.br_redova;i++) {
                        for(int j(0);j<m.br_kolona;j++) {
                            m.elementi[i][j]*=p[k];
                        }
                    }
                    pa=ZbirMatrica(pa,m);
                    for(int i(0);i<m.br_redova;i++) {
                        for(int j(0);j<m.br_kolona;j++) {
                            m.elementi[i][j]/=p[k];
                        }
                    }
                }
                
            }
            UnistiMatricu(m); UnistiMatricu(jedinicna);
        }
        return pa;
    }
    
int main() {
    Matrica<double> a; 
    int dim;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin>>dim;
    try {
        a = StvoriMatricu<double>(dim,dim);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::vector<double> p;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i(0);i<n+1;i++) {
            int br;
            std::cin>>br;
            p.push_back(br);
        }
        IspisiMatricu(MatricniPolinom<double>(a,p),10);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    return 0;
}