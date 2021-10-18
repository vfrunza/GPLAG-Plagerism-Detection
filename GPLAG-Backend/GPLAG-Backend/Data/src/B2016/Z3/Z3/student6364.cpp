/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica 
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};  // VEOMA BITNA INICIJALIZACIJA!
    
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) 
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++)  
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) 
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; 
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) 
        mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
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
        for(int j = 0; j < mat.br_kolona; j++) 
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) 
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);

}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    int n = m1.br_kolona;
    int red = m1.br_redova;
    int vvv = m2.br_redova;
    int kolone = m2.br_kolona;
    auto a(StvoriMatricu<TipElemenata>(red, kolone));
    for(int i = 0; i <red; i++)
        for(int j = 0; j < kolone; j++)
            a.elementi[i][j] = 0;
    for(int i = 0; i < red; i++)
        for(int j = 0; j < kolone; j++)
            for(int k = 0; k < vvv; k++)
                a.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j]; 
    return a;
}
template <typename TipElemenata>
void PomnoziSkalarom(Matrica<TipElemenata> &m, double s)
{
    int n(m.br_kolona);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            m.elementi[i][j] = s * m.elementi[i][j];
    } 
}
template <typename TipElemenata>
void Saberi(Matrica<TipElemenata> &a, Matrica<TipElemenata> &b)
{
    int n(a.br_kolona);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a.elementi[i][j] += b.elementi[i][j];

}
template <typename TipElemenata>
void Jedinicna(Matrica<TipElemenata> &m)
{
    int n(m.br_kolona);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) m.elementi[i][j] = 1;
            else m.elementi[i][j] = 0;
        }
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, std::vector<double> v)
{
    if(m.br_kolona != m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    int n (m.br_kolona);
    Matrica<TipElemenata> I, P, tmp;
    bool obrisiI(true);
    try {
        int k(v.size());
        I = StvoriMatricu<TipElemenata>(n, n);
        Jedinicna(I);
        P = StvoriMatricu<TipElemenata>(n, n);
        int asd(0);
        if(v.size() != 0) asd = v[0];
        auto aaa(P);
        PomnoziSkalarom(I, asd);
        P = I;
        UnistiMatricu(aaa);
        aaa.elementi = nullptr;
        Matrica<TipElemenata> tmp;
        for(int i = 1; i < k; i++)
        {
            I = StvoriMatricu<TipElemenata>(n, n);
            Jedinicna(I);
            tmp = I;
            for(int j = 0; j < i; j++)
            {
                auto obrisi(tmp);
                tmp = ProduktMatrica(m, tmp);
                UnistiMatricu(obrisi);
                obrisi.elementi = nullptr;
            }
            PomnoziSkalarom(tmp, v[i]);
            Saberi(P, tmp);
            UnistiMatricu(tmp);
            obrisiI = false;
            tmp.elementi = nullptr;
        } 
        return P;
    } catch(std::bad_alloc) {
        if(obrisiI) UnistiMatricu(I);
        UnistiMatricu(P); UnistiMatricu(tmp);
        throw;
    }
} 
int main() {
    Matrica<double> a;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::vector<double>v(red+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i = 0; i < red + 1; i++)
            std::cin>>v[i];
        auto b = MatricniPolinom(a, v);
        IspisiMatricu(b, 10);
        UnistiMatricu(b);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); 
return 0;
}
