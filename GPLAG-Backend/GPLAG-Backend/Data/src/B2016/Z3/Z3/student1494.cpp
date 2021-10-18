/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>
#include <cmath>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi)
        return;
        for(int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i(0); i<br_redova; i++) mat.elementi[i]=nullptr;
        try {
            for(int i(0); i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for(int i(0); i<mat.br_redova; i++) 
            for(int j(0); j<mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for(int i(0); i<mat.br_redova; i++) {
            for(int j(0); j<mat.br_kolona; j++) {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
            }
        }
            if(treba_brisati) 
            UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
                for(int i(0); i<m1.br_redova; i++) 
                    for(int j(0); j<m1.br_kolona; j++)
                        m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
                        
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona!=m2.br_redova) {
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        }
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
                for(int i(0); i<m1.br_redova; i++) {
                    for(int j(0); j<m2.br_kolona; j++) {
                        int suma(0);
                            for(int k(0); k<m1.br_kolona; k++)
                                suma+=(m1.elementi[i][k])*(m2.elementi[k][j]);
                                    m3.elementi[i][j]=suma;
                    }
                }
            return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> v) {
        if(A.br_kolona!=A.br_redova) {
            throw std::domain_error("Matrica mora biti kvadratna");
            }
        if(v.size()==0) {
        for(int i(0); i<A.br_redova; i++) {
            for(int j(0); j<A.br_kolona; j++)
            A.elementi[i][j]=0;
        }
        return A; 
        }
            auto Jmatrica(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
            for(int i(0); i<A.br_redova; i++) {
                for(int j(0); j<A.br_kolona; j++) {
                    if(i==j) {
                        Jmatrica.elementi[i][j]=1;
                    }
                    else {
                        Jmatrica.elementi[i][j]=0;
                    }
                }
                return Jmatrica;
            }
            auto mat(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
            for(int i(0); i<v.size(); i++) {
                for(int j(0); j<A.br_redova; j++) {
                    for(int k(0); k<A.br_kolona; k++) {
                        mat.elementi[j][k]=(v[i]*(Jmatrica[j][k]));
                    }
                }
                for(int p(0); p<A.br_redova; p++) {
                    for(int r(0); r<A.br_kolona; r++) {
                        mat.elementi[p][r]+=(v[i]*(A[p][r]));
                        }
                    }
            }
            for(int i(2); i<v.size(); i++) {
                for(int z(0); z<A.br_redova; z++) {
                    for(int x(0); x<A.br_kolona; x++) {
                        mat.elementi[z][x]+=v[i]*(pow(A[z][x]), i);
                    }   
                }
            }  
        return mat;
        }

int main ()
{
    Matrica<double> a;
    int d;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> d;
    try {
        a=StvoriMatricu<double>(d, d);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        int m;
        for(int i(0); i<=n; i++) {
            std::cin >>  m;
        }
        std::vector<double> v;
        for(int i(0); i<v.size(); i++) {
            int x;
            std::cin >> x;
            v.push_back(x);
        }
        IspisiMatricu(MatricniPolinom(a, v), 10, 6);
    }
    catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    catch(std::logic_error l) {
        std::cout << l.what() << std::endl;
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    
    UnistiMatricu(a);
    
	return 0;
}