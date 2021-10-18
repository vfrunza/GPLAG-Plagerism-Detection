/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j] ;
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> Jedinicna(int br_redova, int br_kolona){
    auto jedinicna(StvoriMatricu<TipElemenata> (br_redova,br_kolona));
    for(int i=0; i<jedinicna.br_redova; i++){
        for(int j=0; j<jedinicna.br_kolona; j++){
            if(i==j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }
    return jedinicna;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat(StvoriMatricu<TipElemenata> (m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            int suma(0);
            for(int k=0; k<m1.br_kolona; k++) suma += m1.elementi[i][k]*m2.elementi[k][j];
            mat.elementi[i][j] = suma;
        }
    }
    return mat;
}

template <typename TipElemenata>
void MnozenjeMatriceSkalarom(Matrica<TipElemenata> &mat, double skalar){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j] *= skalar;
    }
}

template <typename TipElemenata>
void AnulirajMatricu(Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j] = 0;
    }
}
/*
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> koef){
    if(A.br_redova != A.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    auto mat(StvoriMatricu<TipElemenata> (A.br_redova, A.br_kolona));
    AnulirajMatricu(mat);
    TipElemenata **pok = mat.elementi;
    auto I(Jedinicna<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0; i<v.size(); i++){
        if(i==0){
            MnozenjeMatriceSkalarom(I,v[0]);
            for(int i=0; i<mat.br_redova; i++){
                for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j] = I.elementi[i][j];
            }
            UnistiMatricu(I);
        }
        else if(i==1){
            auto prva(StvoriMatricu<TipElemenata> (A.br_redova, A.br_kolona));
            for(int i=0; i<)
        }
        else{
            for(int j=0; j<i-1; j++){
                auto A2<TipElemenata> (ProduktMatrica(m,m));
                
            }
        }
    }
    return mat;
}
*/
int main ()
{
	Matrica<double> a,b, I;
	int m;
	std::cout << "Unesite dimenzije kvadratne matrice: ";
	std::cin >> m ;
	try{
	    a = StvoriMatricu<double> (m,m);
	    std::cout << "Unesite elemente matrice A:\n";
	    UnesiMatricu('A', a);
	    I = ProduktMatrica<double> (a,a);
	    int red;
	    std::cout << "Unesite red polinoma: ";
	    std::cin >> red;
	    std::vector<double> koef;
	    std::cout << "Unesite koeficijente polinoma: ";
	    for(int i=0; i <= red; i++){
	        double broj;
	        std::cin >> broj;
	        koef.push_back(broj);
	    }
	}
	catch(std::bad_alloc){
	    std::cout << "Nema dovoljno memorije!\n";
	}
	catch(std::domain_error e){
	    std::cout << e.what() << std::endl;
	}
	UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(I);
	
	return 0;
}