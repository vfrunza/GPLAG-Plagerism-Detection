/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};


template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(mat.elementi==nullptr) return;
    for (int i = 0; i < mat.br_redova; i++) if (mat.elementi[i]!=nullptr) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
 
 
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    try {
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
 
 
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}


template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) { 
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}


template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) { 
        for(int j = 0; j < m1.br_kolona; j++)  { m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j]; }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
            for (int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
        }
    }
    return m3;
}



template <typename TipElemenata>
void PomnoziMatricuSkalarom(Matrica<TipElemenata> mat, double n) {
    
    for (int j=0; j<mat.br_redova; j++) {
        for (int k=0; k<mat.br_kolona; k++) {
            mat.elementi[j][k]*=n;
        }
    }
    return;
}


template <typename TipElemenata, typename TipPokazivaca>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> A, int n, TipPokazivaca it) {
    if (n<0) throw std::domain_error("Neispravan stepen polinoma");
    if (A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    
    Matrica<TipElemenata> rez, trenutna;
    
    try {
        rez=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        for (int j=0; j<A.br_redova; j++) {
            for (int k=0; k<A.br_kolona; k++) {
                rez.elementi[j][k]=0;
            }
        }
    }
    catch(...) {
        UnistiMatricu(rez);
        throw;
    }
    
    for (int i=0; i<=n; i++) {
        
        try {
            trenutna=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
            
            for (int j=0; j<A.br_redova; j++) {
                for (int k=0; k<A.br_kolona; k++) {
                    if (j==k) trenutna.elementi[j][k]=1;
                    else trenutna.elementi[j][k]=0;
                }
            }
            
            for (int j=0; j<i; j++) {
                auto prosla(trenutna);
                trenutna=ProduktMatrica(trenutna, A);
                UnistiMatricu(prosla);
            }
            
            PomnoziMatricuSkalarom<TipElemenata>(trenutna, *it);
            
            auto prosla(rez);
            
            rez=ZbirMatrica<TipElemenata>(rez, trenutna);
            
            UnistiMatricu(prosla);
            
            UnistiMatricu(trenutna);
        }
        catch (...) {
            UnistiMatricu(trenutna);
            UnistiMatricu(rez);
            throw;
        }
        
        it++;
    }
    
    return rez;
}

int main() {
    Matrica<double> A; // AUTOMATSKA INICIJALIZACIJA!!!
    int n, vel;
    double **koeficijenti(nullptr);
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> vel;
    try {
        A = StvoriMatricu<double>(vel, vel);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', A);
        
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        
        std::cout << "Unesite koeficijente polinoma: ";
        try {
            koeficijenti=new double*[n+1]{};
            koeficijenti[0]=new double[n+1];
            for (int i=1; i<=n; i++) koeficijenti[i]=koeficijenti[i-1]+1;
            
            for (int i=0; i<=n; i++) {
                double koef;
                std::cin >> koef;
                koeficijenti[i][0]=koef;
            }
            
            IspisiMatricu(MatricniPolinom<double>(A, n, *koeficijenti), 10, 6, true);
            UnistiMatricu(A);
            
            if (koeficijenti!=nullptr) delete[] koeficijenti[0];
            delete[] koeficijenti;
        }
        catch(...) {
            if (koeficijenti!=nullptr) delete[] koeficijenti[0];
            delete[] koeficijenti;
            UnistiMatricu(A);
            throw;
        }
    }
    catch(std::bad_alloc) {
        UnistiMatricu(A);
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    return 0;
}