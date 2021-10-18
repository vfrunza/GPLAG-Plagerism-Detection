/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElementa>
struct Matrica{ 
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template<typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat){
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElementa*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try{
            for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElementa[br_kolona]; 
        }
    catch(...){
        UnistiMatricu(mat);
    }
    return mat;
}

template<typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati == true) {
        UnistiMatricu(mat);
    }
}

template<typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    //std::cout << "Uslaa" << std::endl;
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m3.br_redova; i++) {
        for(int j = 0; j < m3.br_kolona; j++) {
            int suma{};
            for(int k = 0; k < m1.br_kolona; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template<typename TipElementa>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, std::vector<double> vektor) {
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto rezz(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
    for(int i = 0; i < rezz.br_redova; i++) {
        for(int j = 0; j < rezz.br_kolona; j++) {
            rezz.elementi[i][j] = 0;
        }
    }
    if(vektor.size() == 0) {
        //std::cout << "aa";
        return rezz;
    }
    for(int i = 0; i < rezz.br_redova; i++) {
        for(int j = 0; j < rezz.br_kolona; j++) {
            if(i == j) rezz.elementi[i][j] = 1;
        }
    }
    //IspisiMatricu(rezz, 10,6,false);
    for(int i = 0; i < rezz.br_redova; i++) {
        for(int j = 0; j < rezz.br_kolona; j++) {
            rezz.elementi[i][j] *= vektor[0];
        }
    }
    //IspisiMatricu(rezz, 10,6,false);
    auto pom(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
    //IspisiMatricu(pom, 10, 6, false);
    for(int i = 1; i < vektor.size(); i++) {
        //IspisiMatricu(mat, 10,6,false);
        for(int j = 0; j < mat.br_redova; j++)
            for(int k = 0; k < mat.br_kolona; k++)
                pom.elementi[j][k] = mat.elementi[j][k];
        if(i > 1) {
            //std::cout << "kad tek udje "  << std::endl;
            //IspisiMatricu(mat, 10,6,false);
            for(int l = 0; l < i - 1; l++){
                //std::cout << "prije " << l << std::endl;
                //IspisiMatricu(pom, 10,6,false);
                pom = ProduktMatrica(pom, mat);
                //std::cout << "poslije " << l << std::endl;
                //IspisiMatricu(pom, 10, 6, false);
            }
        }
        //std::cout << i << std::endl;
        //IspisiMatricu(pom, 10, 6, false);
        for(int j = 0; j < pom.br_redova; j++) {
            for(int k = 0; k < pom.br_kolona; k++) {
                pom.elementi[j][k] *= vektor[i];
            }
        }
        for(int j = 0; j < pom.br_redova; j++) {
            for(int k = 0; k < pom.br_kolona; k++) {
                rezz.elementi[j][k] = rezz.elementi[j][k] + pom.elementi[j][k];
            }
        }
    }
    UnistiMatricu(pom);
    return rezz;
}

int main ()
{
    Matrica<int> A,B;
    int br;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> br;
    try{
    A = StvoriMatricu<int>(br,br);
    B = StvoriMatricu<int>(br,br);
    //C = StvoriMatricu<int>(br,br);
    std::cout << "Unesite elemente matrice A: " << std::endl;
    UnesiMatricu('A', A);
    //UnesiMatricu('C', C);
    std::cout << "Unesite red polinoma: ";
    int red;
    std::cin >> red;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> v;
    for(int i = 0; i <= red; i++) {
        int broj;
        std::cin >> broj;
        v.push_back(broj);
    }
    //for(double x:v) std::cout << x << " " << std::endl;
    B = MatricniPolinom(A,v);
    IspisiMatricu(B, 10, 6, true);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnistiMatricu(A);
     /*Matrica<double> m1;
    Matrica<double> m2;
    m1 = StvoriMatricu<double>(2,3);
    UnesiMatricu<double>('1', m1);
    m2 = StvoriMatricu<double>(3,4);
    UnesiMatricu<double>('2', m2);
    Matrica<double> produkt = ProduktMatrica(m1, m2);
    IspisiMatricu(produkt, 3);
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    UnistiMatricu(produkt);*/
	return 0;
}