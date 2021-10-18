/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr; 
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
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
        
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa)  << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipElemenata> m3;
        
        try{
            m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        }
        catch(std::bad_alloc){
            UnistiMatricu(m3);
            throw std::bad_alloc();
        }
        for(int i = 0; i < m1.br_redova; i++){
            for(int j = 0; j < m1.br_kolona; j++){
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            }
        }
    return m3;
    }
    
template<typename TipElemenata>
    bool MoguSeMnoziti (const Matrica<TipElemenata> m1, const Matrica<TipElemenata> m2){
        return m1.br_kolona == m2.br_redova;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> m1, const Matrica<TipElemenata> m2){
        if (!MoguSeMnoziti(m1,m2)) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        
        Matrica<TipElemenata> m3;
        
        try{
            m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
            for(int i = 0; i < m3.br_redova; i++){
                for(int j = 0; j < m3.br_kolona; j++){
                    TipElemenata suma(0);
                    for(int k = 0; k < m2.br_redova; k++){
                        suma += m1.elementi[i][k] * m2.elementi[k][j];
                    }
                    m3.elementi[i][j] = suma;
                }
            }
        }
        catch(std::bad_alloc){
            UnistiMatricu(m3);
            throw(std::bad_alloc());
        }
        return m3;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> DajJedinicnu(int br_redova, int br_kolona){ 
        Matrica<TipElemenata> i;
        try{
            i = StvoriMatricu<TipElemenata>(br_redova, br_kolona);
            for(int j = 0; j < i.br_redova; j++){
                for(int k = 0; k < i.br_kolona; k++){
                    if(k == j) i.elementi[j][k] = 1;
                    else i.elementi[j][k] = 0;
                }
            }
        }
        catch(std::bad_alloc){
            UnistiMatricu(i);
            throw std::bad_alloc();
        }
        return i;
    }
    
template<typename TipElemenata>
    void PomnoziSkalarom(Matrica<TipElemenata> m, double s){
        for(int i = 0; i < m.br_redova; i++){
            for(int j = 0; j < m.br_kolona; j++){
                m.elementi[i][j] *= s;
            }
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> m, std::vector<double> v){
        Matrica<TipElemenata> p, pomocna, prosla;
        
        if (m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        try{
            p = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        }
        catch(std::bad_alloc){
            throw std::bad_alloc();
        }
        
        for(int i = 0; i < p.br_redova; i++){
            for(int j = 0; j < p.br_kolona; j++){
                    p.elementi[i][j] = 0;
            }
        }
        if(v.size() == 0) return p;
    
        try{
            pomocna = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona); 
        }
        catch(std::bad_alloc){
            UnistiMatricu(pomocna);
            throw std::bad_alloc();
        }
        
        for(int i = 0; i < v.size(); i++){
            
            if (i == 0) {
                Matrica<TipElemenata> jedinicna;
                try{
                    jedinicna = DajJedinicnu<TipElemenata>(m.br_redova, m.br_kolona);
                    prosla = p;
                    p = ZbirMatrica<TipElemenata>(p, jedinicna);
                    PomnoziSkalarom(p, v[0]);
                    UnistiMatricu(jedinicna);
                    UnistiMatricu(prosla);
                }
                catch(std::bad_alloc){
                    UnistiMatricu(jedinicna);
                    UnistiMatricu(p);
                    throw std::bad_alloc();
                }
            }
            else {
                for(int i = 0; i < pomocna.br_redova; i++){
                    for(int j = 0; j < pomocna.br_kolona; j++){
                        pomocna.elementi[i][j] = m.elementi[i][j];
                    }
                }
                if(i > 1) {
                    for(int j = 1; j < i; j++){
                        try{
                            prosla = pomocna;
                            pomocna = ProduktMatrica(pomocna, m);
                            UnistiMatricu(prosla);
                            }
                        catch(std::bad_alloc){
                            UnistiMatricu(pomocna);
                            throw(std::bad_alloc());
                        }
                    }
                }
                prosla = p;
                PomnoziSkalarom<TipElemenata>(pomocna, v[i]); 
                p = ZbirMatrica<TipElemenata>(p, pomocna);
                UnistiMatricu(prosla);
            }
        }
        UnistiMatricu(pomocna);
        return p;
    }

int main() {
    Matrica<double> m, p; 
    std::vector<double> v;
    int d, n;
     
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> d;
    try {
        m = StvoriMatricu<double>(d, d);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', m);
        
        std::cout << "Unesite red polinoma: ";
        std::cin >> n; v.resize(n+1);
        
        if(v.size() != 0){
            std::cout << "Unesite koeficijente polinoma: ";
            for(int i = 0; i < v.size(); i++) std::cin >> v[i];
        }
        IspisiMatricu(p = MatricniPolinom(m, v), 10);
    } 
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(m); UnistiMatricu(p);
return 0;
}