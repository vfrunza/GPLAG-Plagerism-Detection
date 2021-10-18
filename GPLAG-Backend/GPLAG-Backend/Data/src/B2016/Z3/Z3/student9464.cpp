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
        mat.elementi = new TipElemenata* [br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata [br_kolona];
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
                std::cout << ime_matrice << "(" << i + 1<< "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu (const Matrica <TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setprecision(preciznost) <<std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3 (StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3 (StvoriMatricu<TipElemenata> (m1.br_redova, m2.br_kolona));
        for(int k = 0; k < m1.br_redova; k++) {
            for(int i = 0; i < m2.br_kolona; i++) {
                TipElemenata suma(0);
                for(int j = 0; j < m1.br_kolona; j++)
                    suma += m1.elementi[k][j] * m2.elementi[j][i];
                m3.elementi[k][i] = suma;
            }
        }
        return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktSaSkalarom(const Matrica<TipElemenata> &m, double k) {
        auto m2 (StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i = 0; i < m.br_redova; i++)
            for(int j = 0; j < m.br_kolona; j++)
                m2.elementi[i][j] = k*m.elementi[i][j];
        return m2;
    }
  
template <typename TipElemenata>
    Matrica<TipElemenata> KopijaMatrice(const Matrica<TipElemenata> &m) {
        auto m2(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i = 0; i < m.br_redova; i++)
            for(int j = 0; j < m.br_kolona; j++)
                m2.elementi[i][j] = m.elementi[i][j];
        return m2;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, const std::vector<double> &koef) {
        if(m.br_redova != m.br_kolona)
            throw std::domain_error("Matrica mora biti kvadratna");
        Matrica<TipElemenata> p;
        try{
            p = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        }
        catch(std::bad_alloc) {
            throw;
        }
        for(int i = 0; i < m.br_redova; i++)
            for(int j = 0; j <m.br_kolona; j++)
                if(koef.size() && i == j) p.elementi[i][j] = koef[0];
                else p.elementi[i][j] = 0;
        if(koef.size() <= 1) return p;
        Matrica<TipElemenata> tmp, tmp2, tmp3;
        tmp.elementi = nullptr; tmp2.elementi = nullptr; tmp3.elementi = nullptr;
        
        try{
            tmp = KopijaMatrice(m);
            tmp3 = KopijaMatrice(m);
            for(int i = 1; i < koef.size(); i++) {
                if(i > 1) tmp = ProduktMatrica(tmp3, m);
                UnistiMatricu(tmp3);
                tmp2 = ProduktSaSkalarom(tmp, koef[i]);
                tmp3 = KopijaMatrice(tmp);
                auto p2(ZbirMatrica(p, tmp2));
                UnistiMatricu(p);
                p = p2;
                UnistiMatricu(tmp);
                UnistiMatricu(tmp2);
            }
            UnistiMatricu(tmp3);
            return p;
        }
        catch(std::bad_alloc) { 
            UnistiMatricu(p); UnistiMatricu(tmp); UnistiMatricu(tmp2); UnistiMatricu(tmp3);
        }
    }
int main ()
{
    Matrica <double> a,b;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        b = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int p;
        std::cin >> p;
        std::vector<double> polinom;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i < p+1; i++) {
            double tmp;
            std::cin >> tmp;
            polinom.push_back(tmp);
        }
        IspisiMatricu(MatricniPolinom(a, polinom), 10, 6, true);
    }
    catch(std::domain_error e) {
        std::cout << e.what();
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}