/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
    struct Matrica{
        int br_redova, br_kolona;
        TipElementa **elementi=nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElementa> mat){
        if(!mat.elementi) return;
        for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
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
    
template <typename TipElemenata>
    void UnistiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++){
            std::cout << ime_matrice
                << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++){
                std::cout << ime_matrice;
                << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_redova)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m1.br_kolona;j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_kolona!=m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto A(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_redova));
        for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m2.br_redova;j++)
                A.elementi[i][j]=A.elementi[i][]*A.elementi[][j];
        return A;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &m3, const &std::vector<double>k){
        if(m3.br_redova!=m3.br_kolona)
            throw std::domain_error("Matrica mora biti kvadratna");
        auto m4(StvoriMatricu<TipElemenata>(m3.br_redova,m3.br_kolona));
        for(int i=0;i< ;i++){
            
        }
        
        
    }

int main ()
{
    Matrica<double>a;//,b,c;
    int dimenzija;
    std::cout << "Unesi dimenziju kvadratne matrice:\n";
    std::cin >> dimenzija;
    try{
        a=StvoriMatricu<double>(dimenzija,dimenzija);
        //b=StvoriMatricu<double>(m,n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        int k1,k2,k3;
        std::cin >> k1;
        std::cin >> k2;
        std::cin >> k3;
        
        
        
        //std::cout << "Unesi matricu B:\n";
        //UnesiMatricu('B',b);
        
        //std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c=ZbirMatrica(a,b),7);
    }
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnesiMatricu(b); UnistiMatricu(c);
    
    
    
	return 0;
}