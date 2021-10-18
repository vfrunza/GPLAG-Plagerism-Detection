/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>

#include <vector>

#include <new>
#include <stdexcept>

template <typename ElType>
struct Matrica
{
    int br_redova, br_kolona;
    ElType **elementi = nullptr;
};

template <typename ElType>
Matrica<ElType> makeIdentity(int);

template <typename ElType>
Matrica<ElType> StvoriMatricu(int, int);

template <typename ElType>
void UnistiMatricu(Matrica<ElType>);

template <typename ElType>
void UnesiMatricu(char, Matrica<ElType>&);

template <typename ElType>
void IspisiMatricu(const Matrica<ElType>&, int, int preciznost = 6, bool treba_brisati = false);

template <typename ElType>
Matrica<ElType> ZbirMatrica(const Matrica<ElType>&, const Matrica<ElType>&);

template <typename ElType>
Matrica<ElType> SkalarniProizvod(const Matrica<ElType>&, ElType);

template <typename ElType>
Matrica<ElType> ProduktMatrica(const Matrica<ElType>&, const Matrica<ElType>&);

template <typename ElType, typename IterType>
Matrica<ElType> MatricniPolinom(const Matrica<ElType>&, int, IterType);

int main ()
{
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    
    Matrica<double> A, I;
    try {
        A = StvoriMatricu<double>(m, m);
        I = makeIdentity<double>(m);
        
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', A);
        
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        
        std::vector<double> koeficijenti(n + 1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (auto &koeficijent : koeficijenti)
            std::cin >> koeficijent;
            
        IspisiMatricu(MatricniPolinom(A, n, koeficijenti.begin()), 10, 6, true);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    
    UnistiMatricu(A);
    UnistiMatricu(I);
    
	return 0;
}

template <typename ElType>
Matrica<ElType> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<ElType> res;
    res.br_redova = br_redova;
    res.br_kolona = br_kolona;
    
    try {
        res.elementi = new ElType*[br_redova]{};
        
        for (int i = 0; i < br_redova; i++)
            res.elementi[i] = new ElType[br_kolona];
    }
    catch(...) {
        UnistiMatricu(res);
        throw;
    }
    
    return res;
}

template <typename ElType>
void UnistiMatricu(Matrica<ElType> mat)
{
    if (!mat.elementi)
        return;
        
    for (int i = 0; i < mat.br_redova; i++)
        delete[] mat.elementi[i];
        
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename ElType>
void UnesiMatricu(char ime_matrice, Matrica<ElType> &mat)
{
    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename ElType>
void IspisiMatricu(const Matrica<ElType> &mat, int sirina_ispisa,
                   int preciznost, bool treba_brisati)
{
    std::cout << std::setprecision(preciznost);
    
    for (int i = 0; i < mat.br_redova; i++)
    {
        for (int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        
        std::cout << std::endl;
    }
    
    std::cout << std::setprecision(6); // Vrati kako je bilo
    if (treba_brisati)
        UnistiMatricu(mat);
}

template <typename ElType>
Matrica<ElType> ZbirMatrica(const Matrica<ElType> &mat1,
                            const Matrica<ElType> &mat2)
{
    if (mat1.br_redova != mat2.br_redova ||
        mat1.br_kolona != mat2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
            
    auto res(StvoriMatricu<ElType>(mat1.br_redova, mat1.br_kolona));
    
    for (int i = 0; i < mat1.br_redova; i++)
        for (int j = 0; j < mat1.br_kolona; j++)
            res.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
            
    return res;
}

template <typename ElType>
Matrica<ElType> SkalarniProizvod(const Matrica<ElType> &mat, ElType skalar)
{
    auto res(StvoriMatricu<ElType>(mat.br_redova, mat.br_kolona));
    
    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++)
            res.elementi[i][j] = skalar * mat.elementi[i][j];
            
    return res;
}

template <typename ElType>
Matrica<ElType> ProduktMatrica(const Matrica<ElType> &mat1,
                               const Matrica<ElType> &mat2)
{
    if (mat1.br_kolona != mat2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
        
    auto res(StvoriMatricu<ElType>(mat1.br_redova, mat2.br_kolona));
    
    for (int i = 0; i < mat1.br_redova; i++)
        for (int j = 0; j < mat2.br_kolona; j++)
        {
            res.elementi[i][j] = 0;
            
            for (int k = 0; k < mat1.br_kolona; k++)
                res.elementi[i][j] += mat1.elementi[i][k] * mat2.elementi[k][j];
        }
        
    return res;
}

template <typename ElType, typename IterType>
Matrica<ElType> MatricniPolinom(const Matrica<ElType> &mat, int n, IterType coef)
{
    
    if (n < 0)
        throw std::domain_error("Neispravan stepen polinoma");
        
    if (mat.br_redova != mat.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
        
    auto stepeni = makeIdentity<ElType>(mat.br_redova);
    auto res = SkalarniProizvod(stepeni, *coef++);
    
    for (int i = 1; i <= n; i++)
    {
        auto tmp(ProduktMatrica(stepeni, mat));
        UnistiMatricu(stepeni);
        
        stepeni = tmp;
        
        tmp = SkalarniProizvod(stepeni, *coef++);
        auto tmp2 = ZbirMatrica(res, tmp);
        UnistiMatricu(tmp);
        UnistiMatricu(res);
        
        res = tmp2;
    }
    UnistiMatricu(stepeni);
    
    return res;
}

template <typename ElType>
Matrica<ElType> makeIdentity(int n)
{
    auto res = StvoriMatricu<ElType>(n, n);
    
    for (int i = 0; i < res.br_redova; i++)
        for (int j = 0; j < res.br_kolona; j++)
            res.elementi[i][j] = i == j ? 1 : 0;
            
    return res;
}
