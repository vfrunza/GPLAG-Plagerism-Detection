/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElementa>
    struct Matrica {
        int br_redova, br_kolona;
        TipElementa **elementi = nullptr;
    };

template <typename TipElementa>
    void UnistiMatricu(Matrica<TipElementa> mat) {
        if(!mat.elementi) return;
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }

template <typename TipElementa>
    Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElementa> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElementa*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++) 
                mat.elementi[i] = new TipElementa[br_kolona];
               
    
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElementa>
    void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat) {
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "("<< i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElementa>
    void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for(int i = 0; i < mat.br_redova; i++){
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati)
            UnistiMatricu(mat);
    }
    
template <typename TipElementa>
    Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
            throw std::domain_error("Matrice nemaju jednake dimenzije");
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElementa>
    Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
        for(int i = 0; i < m1.br_redova; i++){
            for(int j = 0; j < m2.br_kolona; j++){
                TipElementa suma = 0;
                int red_prve= i;
                int kolona_druge = j;
                for (int n = 0; n < m1.br_kolona; n++){
                    suma = suma + m1.elementi[red_prve][n]*m2.elementi[n][kolona_druge];
                }
                m3.elementi[i][j] = suma;
                
            }
        }
        return m3;
    } 
    
template<typename TipElementa>
    void PomnoziMatricuSkalarom(Matrica<TipElementa> &mat, double skalar){
        
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j < mat.br_kolona; j++) mat.elementi[i][j] *=skalar;
    }
    
template <typename TipElementa>
    Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, const std::vector<double> &vek) {
        if(mat.br_kolona != mat.br_redova ) throw std::domain_error("Matrica mora biti kvadratna");
        auto m(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
        for(int i = 0; i < mat.br_redova; i++) 
            for(int j = 0; j < mat.br_kolona; j++) {
                if (i - j == 0) m.elementi[i][j] = 1;
                else m.elementi[i][j] = 0;
            }
        auto glavna(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j <  mat.br_kolona; j++)
                glavna.elementi[i][j]=0;
        int n(0);
        
        for(auto x : vek){
            
            if(n!=0){
                
                auto matrica = ProduktMatrica(m, mat);
                for(int i = 0; i < m.br_redova; i++)
                    for(int j = 0; j < m.br_kolona; j++)
                        m.elementi[i][j] = matrica.elementi[i][j];
                UnistiMatricu(matrica);
                
            }
            auto pomocna_matrica = StvoriMatricu<int>(m.br_redova, m.br_kolona);
            for(int i = 0; i < pomocna_matrica.br_redova; i++)
                for(int j = 0; j < pomocna_matrica.br_kolona; j++)
                    pomocna_matrica.elementi[i][j] = m.elementi[i][j];
            
            PomnoziMatricuSkalarom(pomocna_matrica, x);
            
            for(int i = 0; i < m.br_redova; i++)
                for(int j = 0; j < m.br_kolona; j++)
                    glavna.elementi[i][j] += pomocna_matrica.elementi[i][j];
            
            UnistiMatricu(pomocna_matrica);
            
            n++;
        }
        UnistiMatricu(m);
        return glavna;
        
    }
int main ()
{
    try{
        int n;
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        std::cin >> n;
        std::cout << "Unesite elemente matrice A: ";
        Matrica<double> m = StvoriMatricu<double>(n,n);
        UnesiMatricu('A',m);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v;
        double x;
        for(int i = 0; i <=red; i++)
        {
            std::cin>>x;
            v.push_back(x);
        }
        auto rezultat = MatricniPolinom<double>(m,v);
        IspisiMatricu<double>(rezultat,8);
        UnistiMatricu(m);
        UnistiMatricu(rezultat);
    }
    catch(std::logic_error e){
        std::cout << e.what();
    }
    
	return 0;
}