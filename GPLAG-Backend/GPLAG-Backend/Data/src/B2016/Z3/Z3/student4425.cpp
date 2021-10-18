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
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for (int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for (int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        } catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i = 0; i < mat.br_redova; i++) 
            for (int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
        for (int i = 0; i < mat.br_redova; i++) {
            for (int j = 0; j < mat.br_kolona; j++) 
                std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i = 0; i < m1.br_redova; i++) 
            for (int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }

template <typename TipElemenata> 
    void PomnoziSkalarom (Matrica<TipElemenata> &m, double p) {
        for (int i = 0; i < m.br_redova; i++) {
            for (int j = 0; j < m.br_kolona; j++) {
                m.elementi[i][j]*=p;
            }
        }
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m2.br_kolona; j++) {
                m3.elementi[i][j] = 0;
                for (int k = 0; k < m1.br_kolona; k++) {
                    m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        
        return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m1, const std::vector<double> &p) {
        if (m1.br_kolona!=m1.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
        std::vector<double> empty;
        
            auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for (int i = 0; i < m1.br_redova; i++) 
                for (int j = 0; j < m2.br_redova; j++) 
                    m2.elementi[i][j] = 0;
                    
        if (p==empty) return m2;
        
        /* k(p.size());
        for (int i = 0; i < k; i++) {
            StvoriMatricu(m1.br_redova, m1.br_kolona);
        }*/
        return m2;
        
    }

int main () {
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dim;
    std::cin >> dim;
	
	std::cout << "Unesite elemente matrice A: " << std::endl;
	auto m(StvoriMatricu<double>(dim, dim));
	UnesiMatricu('A', m);
	int red;
	std::cin >> red;
	std::vector<double> v;
	std::cout << "Unesite koeficijente polinoma: ";
	for (int i = 0; i < red+1; i++) {
	    int tmp;
	    std::cin >> tmp;
	    v.push_back(tmp);
	}
	auto ispisi(MatricniPolinom(m, v));
	IspisiMatricu<double>(m,6);
	return 0;
}














