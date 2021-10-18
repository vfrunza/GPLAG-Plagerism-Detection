/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
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
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try
    {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++)
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }

    if (treba_brisati == true)
        UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");

    Matrica<TipElemenata> rezultat = StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);

    for (int i{};i<m1.br_redova;i++)
        {
            for (int j{};j<m2.br_kolona;j++)
                {
                    TipElemenata suma = 0;
                    for (int k{};k<m2.br_redova;k++)
                        suma += (m1.elementi[i][k] * m2.elementi[k][j]);

                    rezultat.elementi[i][j] = suma;
                }
        }

    return rezultat;
}

template<typename TipElemenata>
Matrica<TipElemenata> Pomnozi_matricu_sa_polinomom (TipElemenata x, Matrica<TipElemenata> m)
{
    Matrica<TipElemenata> rezultat = StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);

    for (int i{};i<m.br_redova;i++)
        {
            for (int j{};j<m.br_kolona;j++)
                rezultat.elementi[i][j] = m.elementi[i][j] * x;
        }

    return rezultat;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &A, std::vector<TipElemenata> p)
{
    if (A.br_kolona != A.br_redova)
        throw std::domain_error ("Matrica mora biti kvadratna");

    int n = A.br_redova;
    Matrica<TipElemenata> rezultat = StvoriMatricu<TipElemenata>(n,n);

    for (int i{};i<n;i++)
        {
            for (int j{};j<n;j++)
                rezultat.elementi[i][j] = 0;
        }

    if (p.size() == 0)
        return rezultat;



    for (int i{};i<p.size();i++)
        {
            Matrica<TipElemenata> pomocna = StvoriMatricu<TipElemenata>(n,n);

            for (int k{};k<n;k++)
                {
                    for (int l{};l<n;l++)
                        {
                            if (k == l)
                                pomocna.elementi[k][l] = 1;
                            else
                                pomocna.elementi[k][l] = 0;
                        }
                }

            if (i == 0)
                {
                    auto m = Pomnozi_matricu_sa_polinomom<TipElemenata>(p[i],pomocna);
                    auto m1 = ZbirMatrica<TipElemenata>(rezultat,m);
                    UnistiMatricu(m);
                    UnistiMatricu(rezultat);
                    rezultat = m1;
                }
            else if (i == 1)
                {
                    auto m = Pomnozi_matricu_sa_polinomom<TipElemenata>(p[i],A);
                    auto m1 = ZbirMatrica<TipElemenata>(rezultat,m);
                    UnistiMatricu(m);
                    UnistiMatricu(rezultat);
                    rezultat = m1;
                }
            else
                {
                    auto produkt = StvoriMatricu<TipElemenata>(n,n);
                    for (int k{};k<n;k++)
                        {
                            for (int l{};l<n;l++)
                                produkt.elementi[k][l] = A.elementi[k][l];
                        }

                    for (int j{2};j<=i;j++)
                        {
                            auto m = ProduktMatrica<TipElemenata>(A,produkt);
                            UnistiMatricu(produkt);
                            produkt = m;
                        }

                    auto m = Pomnozi_matricu_sa_polinomom<TipElemenata>(p[i],produkt);
                    auto m1 = ZbirMatrica<TipElemenata>(rezultat,m);
                    UnistiMatricu(m);
                    UnistiMatricu(rezultat);
                    rezultat = m1;
                    UnistiMatricu(produkt);
                }



            UnistiMatricu(pomocna);
        }


    return rezultat;
}



int main()
{
    Matrica<double> A;
    try
    {
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int n;
        std::cin>>n;
        std::cin.ignore(10000, '\n');

        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        A = StvoriMatricu<double>(n,n);
        UnesiMatricu('A',A);

        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v;
        for (int i{};i<n+1;i++)
            {
                double x;
                std::cin>>x;
                v.push_back(x);
            }

        auto rezultat = MatricniPolinom(A,v);
        IspisiMatricu(rezultat,10,6,true);

    }
    catch (std::domain_error e)
    {
        std::cout<<e.what();
    }

    UnistiMatricu(A);

    return 0;
}
