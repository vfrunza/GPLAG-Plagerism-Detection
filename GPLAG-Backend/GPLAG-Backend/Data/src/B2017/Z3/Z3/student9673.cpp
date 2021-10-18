/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++)
       delete [] mat.elementi[i];
       delete [] mat.elementi;
       mat.elementi=nullptr;
} 

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
     for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
     try{
         for(int i=0;i<br_redova;i++)
            mat.elementi[i]=new TipElemenata[br_kolona]{};
        }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
  void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
       for(int i=0;i<mat.br_redova;i++)
          for(int j=0;j<mat.br_kolona;j++){
              std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
              std::cin>>mat.elementi[i][j];
          }
  }
  
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
         std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    try {
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m1.br_kolona;j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }
    catch(...) {
        throw;
    }
}
 
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    try {
        Matrica<TipElemenata> rezultat = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        for(int i(0); i < m1.br_redova; i++) {
            for(int j(0); j < m2.br_kolona; j++) {
                rezultat.elementi[i][j] = 0;
            }
        }
        for(int i(0); i < m1.br_redova; i++) {
            for(int j(0); j < m2.br_kolona; j++) {
                for(int k(0); k < m1.br_kolona; k++) {
                    rezultat.elementi[i][j] += (m1.elementi[i][k] * m2.elementi[k][j]); 
                }
            }
        }
        return rezultat;
    }
    catch(...) {
        throw;
    }
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, Tip p) {
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_redova != A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    try {
        Matrica<TipElemenata> rezultat = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        for(int i(0); i <= n; i++) {
            if(i == 0) {
                try {
                    Matrica<TipElemenata> jedinicna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
                    for(int j(0); j < A.br_redova; j++) {
                        for(int k(0); k < A.br_kolona; k++) {
                            if(j == k) jedinicna.elementi[j][k] = 1;
                            else jedinicna.elementi[j][k] = 0;
                        }
                    }
                    for(int j(0); j < A.br_redova; j++) {
                        for(int k(0); k < A.br_kolona; k++) {
                            jedinicna.elementi[j][k] *= *p; 
                        }
                    }
                    auto dosadasnjirez = rezultat;
                    rezultat = ZbirMatrica(dosadasnjirez, jedinicna);
                    UnistiMatricu(dosadasnjirez);
                    UnistiMatricu(jedinicna);
                }
                catch(...) {
                    UnistiMatricu(rezultat);
                    throw;
                }
            }
            else {
                try {
                    auto stepenovana = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
                    for(int j(0); j < A.br_redova; j++) {
                        for(int k(0); k < A.br_kolona; k++) {
                            stepenovana.elementi[j][k] = A.elementi[j][k];
                        }
                    }
                    for(int j(1); j < i; j++) {
                        auto dosadasnjastepenovana = stepenovana;
                        stepenovana = ProduktMatrica(dosadasnjastepenovana, A);
                        UnistiMatricu(dosadasnjastepenovana);
                    }
                    for(int j(0); j < A.br_redova; j++) {
                        for(int k(0); k < A.br_kolona; k++) {
                            stepenovana.elementi[j][k] *= *p;
                        }
                    }
                    auto dosadasnjirez = rezultat;
                    rezultat = ZbirMatrica(dosadasnjirez, stepenovana);
                    UnistiMatricu(dosadasnjirez);
                    UnistiMatricu(stepenovana);
                }
                catch(...) {
                    UnistiMatricu(rezultat);
                    throw;
                }
            }
            p++;
        }
        return rezultat;
    }
    catch(...) {
        throw;
    }
}


int main ()
{
    Matrica<double> a;
    a.elementi = nullptr;
    Matrica<double> polinom;
    polinom.elementi = nullptr;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;
    try {
        a = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int redpolinoma;
        std::cin >> redpolinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        for(int i(0); i <= redpolinoma; i++) {
            double x;
            std::cin >> x;
            koeficijenti.push_back(x);
        }
        polinom = MatricniPolinom(a, redpolinoma, koeficijenti.begin());
        IspisiMatricu(polinom, 10);
    }
    catch(...) {
        // ???
    }
    UnistiMatricu(a);
    UnistiMatricu(polinom);
	return 0;
}