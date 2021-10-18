/B2016/2017: Zadaća 3, Zadatak 3.
#include <iostream>
#include <stdexcept>
#include <iomanip>
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
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
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
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++) m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata>&mat1, const Matrica<TipElemenata>&mat2) {
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto M=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
    for(int i=0; i<M.br_redova; i++) {
        for(int j=0; j<M.br_kolona; j++) {
            M.elementi[i][j]=0;
            for(int a=0; a<mat1.br_kolona; a++) {
                M.elementi[i][j]+=mat1.elementi[i][a]*mat2.elementi[a][j];
            }
        }
    }
    return M;
}

template <typename TipElemenata>
Matrica<TipElemenata> StepenujIPomnozi(Matrica<TipElemenata>m, int st, double p) {
    
    auto krajnja=StvoriMatricu<TipElemenata>(m.br_redova, m.br_redova);
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_redova; j++) {
            if(i==j) krajnja.elementi[i][j]=1;
            else krajnja.elementi[i][j]=0;
        }
    }
    
    for(int i=0; i<st; i++) {
        auto temp=ProduktMatrica(krajnja, m);
        UnistiMatricu(krajnja);
        krajnja=temp;
    }
    
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_redova; j++) {
            krajnja.elementi[i][j]*=p;
        }
    }
    
    return krajnja;
    
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata>A, std::vector<double>v) {
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto M=StvoriMatricu<TipElemenata>(A.br_redova, A.br_redova);
        for(int i=0; i<A.br_redova; i++) {
            for(int j=0; j<A.br_redova; j++) {
               M.elementi[i][j]=0;
        }
    }
    
    for(int i=0; i<v.size(); i++) {
        auto temp=StepenujIPomnozi(A, i, v[i]);
        auto zbir=ZbirMatrica(M, temp);
        UnistiMatricu(temp); UnistiMatricu(M);
        M=zbir;
    }
    return M;
}

int main () {
	std::cout << "Unesite dimenziju kvadratne matrice: ";
	int n; std::cin >> n;
	Matrica<double>M;
	try { M=StvoriMatricu<double>(n, n); }
	catch(std::bad_alloc) {
	    return 0;
	}
	std::cout << "Unesite elemente matrice A: \n";
	UnesiMatricu('A', M);
	std::cout << "Unesite red polinoma: ";
	int vel; std::cin >> vel;
	std::vector<double>v(vel+1);
	std::cout << "Unesite koeficijente polinoma: ";
	for(double &x : v) std::cin >> x;
	Matrica<double> mat;
	try { mat=MatricniPolinom(M, v); }
	catch(std::bad_alloc) {
	    return 0;
	}
	UnistiMatricu(M);
	IspisiMatricu(mat, 10, 6, true);
	return 0;
}