#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

template <typename T>
struct Matrica
{
    int br_redova, br_kolona;
    T **elementi{};
};
template <typename T>
void UnistiMatricu(const Matrica<T> &mat)
{
    if (!mat.elementi) return;
    for (int i(0); i < mat.br_redova && mat.elementi[i]; ++i) delete[] mat.elementi[i];
    delete[] mat.elementi;
}
template <typename T>
Matrica<T> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<T> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new T*[br_redova]{};
    try { for (int i(0); i < br_redova; ++i) mat.elementi[i] = new T[br_kolona]{}; }
    catch (...) { UnistiMatricu(mat); throw; }
    return mat;
}
template <typename T>
Matrica<T> ZbirMatrica(const Matrica<T> &a, const Matrica<T> &b)
{
    if (a.br_redova != b.br_redova || a.br_kolona != b.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto rez(StvoriMatricu<T>(a.br_redova, a.br_kolona));
    for (int i(0); i < a.br_redova; ++i)
        for (int j(0); j < a.br_kolona; ++j)
            rez.elementi[i][j] = a.elementi[i][j] + b.elementi[i][j];
    return rez;
}
template <typename T>
Matrica<T> ProduktMatrica(Matrica<T> a, Matrica<T> b)
{
    if (a.br_kolona != b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto rez(StvoriMatricu<T>(a.br_redova, b.br_kolona));
    for (int i(0); i < a.br_redova; i++)
        for (int j(0); j < b.br_kolona; j++)
            for (int k(0); k < a.br_kolona; k++)
                rez.elementi[i][j] += a.elementi[i][k] * b.elementi[k][j];
    return rez;
}
template <typename T>
Matrica<T> ProduktSkalarom(Matrica<T> mat, T x)
{
    Matrica<T> rez(StvoriMatricu<T>(mat.br_redova, mat.br_kolona));
    for (int i(0); i < mat.br_redova; i++)
        for (int j(0); j < mat.br_kolona; j++) rez.elementi[i][j] = mat.elementi[i][j] * x;
    return rez;
}
template <typename T, typename U>
Matrica<T> MatricniPolinom(const Matrica<T> &mat, int n, U start)
{
    if (n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if (mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<T> rez(StvoriMatricu<T>(mat.br_redova, mat.br_kolona)), _rez(rez), pom, stepen(mat), _stepen;
    for (int i(0); i < mat.br_redova; ++i) rez.elementi[i][i] = *start;
    try
    {
        for (int i(1); i <= n; ++i)
        {
            pom.elementi = nullptr;
            rez = ZbirMatrica(rez, pom = ProduktSkalarom(i == 1 ? stepen : stepen = ProduktMatrica(stepen, mat), *++start));
            UnistiMatricu(_rez);
            UnistiMatricu(pom);
            if (i > 2) UnistiMatricu(_stepen);
            _rez = rez;
            _stepen = stepen;
        }
        if (n >= 2) UnistiMatricu(stepen);
    }
    catch (...)
    {
        UnistiMatricu(_rez);
        UnistiMatricu(pom);
        if (_stepen.elementi != mat.elementi) UnistiMatricu(_stepen);
        if (rez.elementi != _rez.elementi) UnistiMatricu(rez);
        if (stepen.elementi != _stepen.elementi && stepen.elementi != mat.elementi) UnistiMatricu(stepen);
        throw;
    }
    return rez;
}
template <typename T>
void IspisiMatricu(const Matrica<T> &mat, int sirina, int preciznost = 6, bool treba_brisati = false)
{
    for (int i(0); i < mat.br_redova; i++)
    {
        for (int j(0); j < mat.br_kolona; j++)
            std::cout << std::setw(sirina) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}
template <typename T>
void UnesiMatricu(char ime, Matrica<T> &mat)
{
    for (int i(0); i < mat.br_redova; i++)
        for (int j(0); j < mat.br_kolona; j++)
        {
            std::cout << ime << '(' << i+1 << ',' << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
int main()
{
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    std::cout << "Unesite elemente matrice A:\n";
    Matrica<double> mat;
    try
    {
        mat = StvoriMatricu<double>(n, n);
        UnesiMatricu('A', mat);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koef(n+1);
        for (double &x : koef) std::cin >> x;
        IspisiMatricu(MatricniPolinom(mat, n, koef.begin()), 10, 6, true);
    }
    catch (...) { std::cout << "Izuzetak"; }
    UnistiMatricu(mat);
	return 0;
}