/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata *[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrica, Matrica<TipElemenata> &mat) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrica << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
    
    template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for(int i=0; i<mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++) std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) <<mat.elementi[i][j];
        std::cout << std::endl;
        }
        
        if(treba_brisati==true) {
            UnistiMatricu(mat);
        }
    }

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) 
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template < typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
        int suma(0);
        for(int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> vekt) {
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    if(vekt.size()==0) {
        auto nula(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        
        for(int i=0; i<nula.br_redova; i++) {
            for(int j=0; j<nula.br_kolona; j++) {
                nula.elementi[i][j]=0;
            }
        }
        
        return nula;
    }
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            if(i==j) jedinicna.elementi[i][j]=vekt[0];
            else jedinicna.elementi[i][j]=0;
        }
    }
    
    auto a(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) a.elementi[i][j]=mat.elementi[i][j];
    }
    
    for(int i=1; i<vekt.size(); i++) {
        if(i>1) { auto pomocna=ProduktMatrica(a, mat); 
            UnistiMatricu(a);
            a=pomocna; 
        }
        for(int r=0; r<mat.br_redova; r++) {
            for(int p=0; p<mat.br_kolona; p++) {
                jedinicna.elementi[r][p]=jedinicna.elementi[r][p]+a.elementi[r][p]*vekt[i];
            }
        }
    }
    UnistiMatricu(a);
    return jedinicna;
}
    


int main () 
{
    Matrica<double> a,c;
    int dimenzija, red_poli;
    std::vector<double> vekt;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    bool brisi=false;
    try {
        a=StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_poli;
        
        std::cout << "Unesite koeficijente polinoma: ";
        if(red_poli!=0) {
        for(int i=0; i<red_poli+1; i++) {
            int k;
            std::cin >> k;
            vekt.push_back(k);
        }
        }
        IspisiMatricu(c=MatricniPolinom(a, vekt), 10, 5, brisi);
        
    }
    catch(std::domain_error e) {
        std::cout << e.what();
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
        
    }
    UnistiMatricu(a); UnistiMatricu(c);
    
	return 0;
} 
