/B2016/2017: Zadaća 3, Zadatak 3
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
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout  << std::setw(sirina_ispisa)  << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
            for (int k=0; k < m1.br_kolona; k++)
            m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &a, std::vector<double> vektor) {
    if(a.br_kolona != a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto nulta(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
    for (int i=0; i < a.br_kolona; i++)
        for (int j=0; j < a.br_kolona; j++)
            nulta.elementi[i][j]=0;
    if(!vektor.size()) return nulta;
    UnistiMatricu(nulta);
    auto jedinicna(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
            for (int i=0; i < a.br_kolona; i++)
                for (int j=0; j < a.br_kolona; j++)
                    if(i == j) jedinicna.elementi[i][j]=1;
                    else jedinicna.elementi[i][j]=0;
                    
    auto polinom(jedinicna);
    auto prethodna(ProduktMatrica<TipElemenata>(a,a));
    Matrica<TipElemenata> zbir;                                                                         //!!!!!
    
    for (int i = 0; i<vektor.size(); i++) {
        
        if (i==0) {
            for (int x = 0; x < a.br_kolona; x++)
                for (int y = 0; y < a.br_kolona; y++) {
                    polinom.elementi[x][y]=vektor[i]*jedinicna.elementi[x][y];
                }
            continue;
        }
        if (i==1) {
            auto proiz(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
            for (int x = 0; x < a.br_kolona; x++)
                for (int y = 0; y < a.br_kolona; y++) {
                    proiz.elementi[x][y]=vektor[i]*a.elementi[x][y];
                }
                
            polinom=ZbirMatrica(polinom, proiz);
            zbir=polinom;
            UnistiMatricu(proiz);
            continue;
        }

        if (i==2) {
            auto pomocna(ProduktMatrica<TipElemenata>(a,a));
            auto proiz(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
            for (int x = 0; x < a.br_kolona; x++)
                for (int y = 0; y < a.br_kolona; y++) {
                    proiz.elementi[x][y]=vektor[i]*pomocna.elementi[x][y];
                }
            polinom=ZbirMatrica(polinom, proiz);
            UnistiMatricu(zbir);
            zbir=polinom;
            UnistiMatricu(proiz);
            UnistiMatricu(pomocna);
            continue;
        }
        //OK
        
        auto sabirak(ProduktMatrica<TipElemenata>(prethodna , a));
        auto pomocna1(prethodna);
        prethodna=sabirak;
        UnistiMatricu(pomocna1); 

        auto proiz(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
            for (int x = 0; x < a.br_kolona; x++)
                for (int y = 0; y < a.br_kolona; y++) {
                    proiz.elementi[x][y]=vektor[i]*sabirak.elementi[x][y];
                }

        polinom=ZbirMatrica(polinom, proiz);
        UnistiMatricu(zbir);
        zbir=polinom;
        UnistiMatricu(proiz);
        UnistiMatricu(sabirak);
    }
     UnistiMatricu(jedinicna);
    return polinom;
}

int main() {
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        Matrica<double>a{ StvoriMatricu<double>(n, n)};
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu ('A', a);
        std::cout<<"Unesite red polinoma: ";
        int m;
        std::cin >> m;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector <double> koeficijenti(m+1);
        for (auto &x : koeficijenti) std::cin >> x;
        Matrica<double> b{MatricniPolinom(a, koeficijenti)};
        IspisiMatricu (b, 10);
        UnistiMatricu(a);
        UnistiMatricu(b);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}