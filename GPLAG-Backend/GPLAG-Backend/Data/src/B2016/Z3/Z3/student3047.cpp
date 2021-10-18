#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica
{
	int br_redova, br_kolona;
	TipElemenata** elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat)
{
	if (!mat.elementi)
		return;
	for (int i = 0; i < mat.br_redova; i++)
		delete[] mat.elementi[i];
	delete[] mat.elementi;
	mat.elementi = nullptr;
}

template <typename TipElemenata>
void AnulirajMatricu (Matrica<TipElemenata>& mat)
{
	for (int i = 0; i < mat.br_redova; i++)
		for (int j = 0; j < mat.br_kolona; j++)
			mat.elementi[i][j] = 0;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
	Matrica<TipElemenata> mat;
	mat.br_redova = br_redova;
	mat.br_kolona = br_kolona;
	mat.elementi = new TipElemenata*[br_redova];
	for (int i = 0; i < br_redova; i++)
		mat.elementi[i] = nullptr;
	try
	{
		for (int i = 0; i < br_redova; i++)
			mat.elementi[i] = new TipElemenata[br_kolona];
	}
	catch (...)
	{
		UnistiMatricu (mat);
		throw;
	}
	return mat;
}
template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata>& mat)
{
	for (int i = 0; i < mat.br_redova; i++)
		for (int j = 0; j < mat.br_kolona; j++)
		{
			std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			std::cin >> mat.elementi[i][j];
		}
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata>& m1, const Matrica<TipElemenata>& m2, bool treba_brisati = false)
{
	if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	auto m3 (StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona) );
	for (int i = 0; i < m1.br_redova; i++)
		for (int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	if (treba_brisati)
		UnistiMatricu (m1);
	
	return m3;
}
template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata>& mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
	for (int i = 0; i < mat.br_redova; ++i)
	{
		for (int j = 0; j < mat.br_kolona; ++j)
			std::cout << std::setw (sirina_ispisa) << std::setprecision (preciznost) << mat.elementi[i][j];
		std::cout << "\n";
	}
	std::cout << "\n";
	if (treba_brisati)
		UnistiMatricu (mat);
}

template<typename T>
Matrica<T> ProduktMatrica(const Matrica<T>& m1, const Matrica<T>& m2)
{
    if(m1.br_kolona !=  m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m = StvoriMatricu<T>(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; ++i){
        for(int j = 0; j < m2.br_kolona; ++j){
            double suma = 0;
            for(int k = 0; k < m2.br_redova; ++k)
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            m.elementi[i][j]=suma;
        }
    }
    return m;
}

template<typename T>
Matrica<T> Jedinicna(int dim)
{
    auto m = StvoriMatricu<T>(dim, dim);
    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim ; ++j)
        if( i == j)
            m.elementi[i][i] = 1;
        else
            m.elementi[i][j] = 0;
    return m;
}


template<typename T>
void Pomnozi_skalarom(Matrica<T>& m, int n)
{
    for(int i = 0; i <m.br_redova; ++i)
        for(int j = 0; j < m.br_kolona; ++j)
            m.elementi[i][j] *= n;
}

template<typename T>
void Dodijela(Matrica<T>& m, const Matrica<T> & m2, bool treba_brisati = false)
{
    for(int i = 0; i <m.br_redova; ++i)
        for(int j = 0; j < m.br_kolona; ++j)
            m.elementi[i][j] = m2.elementi[i][j];
    if(treba_brisati)
        UnistiMatricu(m2);
}


template<typename T>
Matrica<T> MatricniPolinom(const Matrica<T>& A, const std::vector<double>& p)
{
    if(A.br_kolona != A.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
        
    Matrica<T> s, m1, m2;
    try {
        s = Jedinicna<T>(A.br_kolona);
        if(p.size() == 0){
            AnulirajMatricu(s);
            return s;
        }
    
        Pomnozi_skalarom(s, p[0]);
        
        m1 = StvoriMatricu<T>(A.br_kolona, A.br_kolona);
        Dodijela(m1, A);
        
        m2 = StvoriMatricu<T>(A.br_kolona, A.br_kolona);
        Dodijela(m2, A);
        
        for(int i = 1; i< p.size(); ++i){
            Pomnozi_skalarom(m1, p[i]);
            s = ZbirMatrica(s, m1, true);
            Dodijela(m2, ProduktMatrica(m2, A), true);
            Dodijela(m1, m2);
           
        }
    }
    catch (std::bad_alloc) {
       UnistiMatricu(s);
       UnistiMatricu(m1);
       UnistiMatricu(m2);
       throw;
    }
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    return s;
}

int main()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin >> n;
    auto A = StvoriMatricu<double>(n, n);
    std::cout << "Unesite elemente matrice A: \n";
    UnesiMatricu('A', A);
    std::cout << "Unesite red polinoma: ";
    std::cin >> n;
    std::vector<double> p(n + 1);
    std::cout << "Unesite koeficijente polinoma: ";
    for(auto& elem : p)
        std::cin >> elem;
    IspisiMatricu(MatricniPolinom(A, p),10, 6, true);
    UnistiMatricu(A);
}