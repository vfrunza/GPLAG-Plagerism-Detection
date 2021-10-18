#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <exception>
#include <vector>
#include <limits>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi {nullptr};
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona, bool jedinicna=false) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    int i;
    try {
        mat.elementi = new TipElemenata*[br_redova] {};
        for(i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona] {};
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    if(jedinicna) for(int i=0; i<mat.br_redova; i++) mat.elementi[i][i]=1;
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa=4, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_redova; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j]= m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata, typename It>
Matrica<TipElemenata> MnozenjeSkalarom(const Matrica<TipElemenata> &m1, It x) {
    auto m2(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m2.elementi[i][j]=m1.elementi[i][j] * (*x);
    return m2;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m1.br_redova; k++)
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template<typename TipElemenata, typename It>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &M, int n, It x) {
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(M.br_redova!=M.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> P; // povratna
    Matrica<TipElemenata> E=StvoriMatricu<TipElemenata>(M.br_redova,M.br_kolona,true); // jedinicna
    if(n==0) { P=MnozenjeSkalarom(E,x); UnistiMatricu(E); return P;}
    std::vector<Matrica<TipElemenata>> Matrice(n+1);
    if(n>=1) {
        Matrice.at(0)=E;
        Matrice.at(1)=M;
    }
    for(int i=2; i<n+1; i++) Matrice.at(i)=ProduktMatrica(Matrice.at(i-1),M);
    int i=0,m=n;
    P=StvoriMatricu<TipElemenata>(M.br_redova,M.br_kolona);
    while((n+1)>0) {
        Matrica<TipElemenata> temp1(P),temp2(MnozenjeSkalarom(Matrice.at(i),x));
        P=ZbirMatrica(temp1,temp2);
        UnistiMatricu(temp1);
        UnistiMatricu(temp2);
        std::advance(x,1);
        n--;
        i++;
    }
    for(int j=0; j<m+1; j++) if(j!=1) UnistiMatricu(Matrice.at(j));
    return P;
}

int main() {
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    Matrica<double> a;
    try {
        a=StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koef(n+1);
        for(int i=0; i<n+1; i++) std::cin >> koef.at(i);
        IspisiMatricu(MatricniPolinom<double>(a,n,koef.begin()),10,10,true);
    } catch(std::exception &ex) {
        std::cout << ex.what();
    }
    UnistiMatricu(a);
    return 0;
}
