/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica {
    int br_redova = 0, br_kolona = 0;
    TipElemenata **elementi = nullptr;

};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>& mat) {
    if(!mat.elementi) return;
        for(int i = 0; i < mat.br_redova; i++) 
          delete [] mat.elementi[i];
      
    delete[]  mat.elementi;
    mat.elementi = nullptr;
    mat.br_kolona = 0;
    mat.br_redova = 0;
}

template<typename TipElemenata> Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; 
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i = 0; i < br_redova; i++) 
            mat.elementi[i] = new TipElemenata[br_kolona]{};  
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int precizost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) 
            std::cout << std::setw(sirina_ispisa) << std::setprecision(precizost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova){
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; ++i){
        for(int j = 0; j < m2.br_kolona; ++j){
            double suma = 0;
            for(int k = 0; k < m2.br_redova; ++k){
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}


template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatricaPom (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    
    if(m1.br_kolona != m2.br_redova){
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    
    auto m3 = ProduktMatrica(m1, m2);
 
    UnistiMatricu(m1);
    
    return m3;
}

template<typename TipElemenata>
void PomnoziSaSkalarom(Matrica<TipElemenata>& m, TipElemenata skalar)
{
    for(int i = 0; i < m.br_redova; ++i){
        for(int j = 0; j < m.br_kolona; ++j){
            m.elementi[i][j] *= skalar;
        }
    }
}

template<typename TipElemenata>
void SaberiSa(Matrica<TipElemenata>& m1, const Matrica<TipElemenata>& m2)
{
    for(int i = 0; i < m1.br_redova; ++i){
        for(int j = 0; j < m1.br_kolona; ++j){
            m1.elementi[i][j] += m2.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void PrepisiMatricu(Matrica<TipElemenata>& m1, const Matrica<TipElemenata>& m2)
{
    for(int i = 0; i < m1.br_redova; ++i){
        for(int j = 0; j < m1.br_kolona; ++j){
            m1.elementi[i][j] = m2.elementi[i][j];
        }
    }
}

template<typename TipElemenata, typename Iter>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata>& m, int stepen, Iter koef)
{
    if(stepen < 0 ){
        throw std::domain_error("Neispravan stepen polinoma");
    }
    
    if(m.br_kolona != m.br_redova){
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    
    Matrica<TipElemenata> m1, m2, m3;
    bool unistena = false;
    try {
        m1 = StvoriMatricu<TipElemenata>(m.br_kolona, m.br_kolona);
        if(*koef != 0){
            for(int i = 0; i < m.br_kolona; ++i){
                m1.elementi[i][i] = *koef;
            }
        }
        
        ++koef;
        
        m2 = StvoriMatricu<TipElemenata>(m.br_kolona, m.br_kolona);
        PrepisiMatricu(m2, m);
        
        for(int i = 1; i <= stepen; ++i, ++koef){
            if(*koef != 0){
                m3 = StvoriMatricu<TipElemenata>(m.br_kolona, m.br_kolona);
                unistena = false;
                PrepisiMatricu(m3, m2);
                PomnoziSaSkalarom(m3, *koef);
                SaberiSa(m1, m3);
                UnistiMatricu(m3);
                unistena = true;
            }
            m2 = ProduktMatricaPom(m2, m);
        }
        
    }
    catch (std::bad_alloc) {
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        if(!unistena)
            UnistiMatricu(m3);
        throw;
    }
    UnistiMatricu(m2);
    return m1;
}

int main ()
{
	std::cout << "Unesite dimenziju kvadratne matrice: ";
	int dim;
	std::cin >> dim;
	try {
	    Matrica<double> m;
	    m = StvoriMatricu<double>(dim, dim);
	    std::cout << "Unesite elemente matrice A:\n";
	    UnesiMatricu('A', m);
	    std::cout << "Unesite red polinoma: ";
	    int red;
	    std::cin >> red;
	    std::cout << "Unesite koeficijente polinoma: ";
	    ++red;
	    std::vector<double> v(red);
	    for(int i = 0; i < red; ++i){
	        std::cin >> v[i];
	    }
	    auto m1 = MatricniPolinom(m, red - 1, v.begin());
	    
	    IspisiMatricu(m1, 10, 6, true);
	    UnistiMatricu(m);
	}
	catch (std::bad_alloc) {
	    std::cout << "Nedovoljno memorije!";
	}
	catch(std::domain_error e){
	    std::cout << e.what() << '\n';
	}
	
}
