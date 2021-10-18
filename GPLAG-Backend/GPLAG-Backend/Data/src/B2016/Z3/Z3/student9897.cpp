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
void UnistiMatricu (Matrica<TipElementa> mat) {
    if (!mat.elementi) return; 
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i]; 
    delete[] mat.elementi; 
    mat.elementi=nullptr; 
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica <TipElementa> mat; 
    
    mat.br_redova=br_kolona; 
    mat.br_kolona=br_kolona; 
    
    mat.elementi = new TipElementa*[br_redova]; 
    
    for (int i=0; i<br_redova; i++) {
        mat.elementi[i]=nullptr; 
    }
    
    try {
        for (int i=0; i<br_redova; i++) 
        mat.elementi[i]=new TipElementa[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat); 
        throw; 
    }
    
    return mat; 
}

template <typename TipElementa> 
void UnesiMatricu (char ime_matrice, Matrica<TipElementa> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
         std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j]; 
        }
        std::cout << std::endl; 
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa> 
Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
    throw std::domain_error ("Matrice nemaju jednake dimenzije!"); 
    
    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona)); 
    
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j]; 
        }
    }
    return m3; 
}

template <typename TipElementa> 
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona || m1.br_kolona != m1.br_redova || m2.br_kolona != m2.br_redova) 
    throw std::domain_error ("Matrice nisu saglasne za mnozenje!"); 
    
    auto m4 (StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona)); 
    
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            TipElementa suma(0); 
            
            for (int k=0; k<m1.br_redova; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j]; 
            }
            m4.elementi[i][j]=suma; 
        }
    }
    return m4; 
}

template <typename TipElementa> 
Matrica<TipElementa> MatricniPolinom (const Matrica<TipElementa> &m1, std::vector<TipElementa> v) {
    
    if (m1.br_redova != m1.br_kolona) throw (std::domain_error) ("Matrica mora biti kvadratna"); 
    if (v.empty()) {
        std::fill(m1.elementi[0], m1.elementi[0]+m1.br_redova*m1.br_kolona, 0); 
        return m1; 
    }
    
    auto Jedinicna (StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            if (i==j) Jedinicna.elementi[i][j]=1; 
            else     Jedinicna.elementi[i][j]=0;
        }
    }
    
    auto suma (StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    auto m5 (StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));

        for (int j=0; j<m1.br_redova; j++) {
            for (int k=0; k<m1.br_kolona; k++) {
                if (k==0) suma.elementi[j][k]=v[k]*Jedinicna.elementi[j][k];  
                if (k==1) suma.elementi[j][k]+=v[k]*m1.elementi[j][k]; 
                
                else {
                m5=ProduktMatrica(m1,m1); 
                
                }
                suma.elementi[j][k]+=v[k]*m5.elementi[j][k];
            }
        }
    return suma; 
}

int main ()
{
    Matrica<double> a,b; 
    
    int n; 
    std::cout << "Unesite dimenziju kvadratne matrice: "; 
    std::cin >> n; 
    
    try {
        a=StvoriMatricu<double>(n,n); 
        
        std::cout << "Unesite elemente matrice A:\n"; 
        UnesiMatricu('A', a); 
        
        std::cout << "Unesite red polinoma: "; 
        int m; 
        std::cin >> m; 
        
        std::vector<double> v; 
        std::cout << "Unesite koeficijente polinoma: "; 
        for (int i=0; i<=m; i++) {
            int k; 
            std::cin >> k; 
            v.push_back(k); 
        }
        
        b = MatricniPolinom(a, v); 
        IspisiMatricu(b, 10, true); 
        
    }
    
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n"; 
    }
    
    UnistiMatricu(a); 
    UnistiMatricu(b);

	return 0;
}