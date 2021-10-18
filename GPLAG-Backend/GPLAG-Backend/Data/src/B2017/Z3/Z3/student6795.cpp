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
void AnulirajMatricu(Matrica<TipElemenata> mat)
{
    for(int i = 0; i<mat.br_redova; ++i) {
        for(int j = 0; j < mat.br_kolona; ++j) {
            mat.elementi[i][j] = 0;
        }
    }
}

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
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu<TipElemenata>(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu<TipElemenata>(mat);
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
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> a, Matrica<TipElemenata> b)
{

    if(a.br_kolona != b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    Matrica<TipElemenata> nova;
    nova.br_redova = a.br_redova;
    nova.br_kolona = b.br_kolona;
    try {
        nova.elementi = new TipElemenata*[a.br_redova * a.br_kolona];
        for(int i(0); i<nova.br_redova; ++i) nova.elementi[i] = new TipElemenata [nova.br_kolona];

        for(int i(0); i<a.br_redova; ++i) {
            for(int j(0); j<a.br_kolona; ++j) {

                TipElemenata suma(0);
                for(int red(0); red<b.br_kolona; ++red) {
                    suma += a.elementi[i][red] * b.elementi[red][j];
                }

                nova.elementi[i][j] = suma;
                suma = 0;
            }
        }
    } catch(...) {
        throw;
    }


    return nova;
}

template <typename TipElemenata, typename TipPok>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int stepen, TipPok koeficijenti)
{

    if(stepen < 0) throw std::domain_error("Neispravan stepen polinoma");

    //Kreiraj Jedinicnu Matricu
    Matrica<TipElemenata> jedinicna;
    jedinicna.br_kolona = m.br_kolona;
    jedinicna.br_redova = m.br_redova;

    jedinicna.elementi = new TipElemenata*[jedinicna.br_kolona * jedinicna.br_redova];
    for(int i(0); i<jedinicna.br_redova; ++i) jedinicna.elementi[i] = new TipElemenata[jedinicna.br_kolona];

    for(int i(0); i<jedinicna.br_redova; ++i) {
        for(int j(0); j<jedinicna.br_kolona; ++j) {
            if(i==j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }

    Matrica<TipElemenata> P = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona); //POKUSAJ
    Matrica<TipElemenata> Rezultat; //POKUSAJ
    for(int i(0); i <= stepen; ++i) {

        if(i == 0) {

            for(int red(0); red<m.br_redova; ++red) {
                for(int kolona(0); kolona<m.br_kolona; ++kolona) {
                    P.elementi[red][kolona] = *koeficijenti * jedinicna.elementi[red][kolona];
                }
            }
            UnistiMatricu<TipElemenata>(jedinicna);
            ++koeficijenti;
            continue;
        } else {
            Matrica<TipElemenata> referenca;
            Matrica<TipElemenata> temp;
            if(i > 1) {

                temp = ProduktMatrica<TipElemenata>(m, m);
                referenca = temp;
                
                //Koliko puta
                for(int kolko_puta(1); kolko_puta < i - 1; ++kolko_puta) {
                    temp = ProduktMatrica<TipElemenata>(temp, m);
                    UnistiMatricu(referenca);
                    referenca = temp;
                }
            } else {
                temp = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);

                for(int x(0); x<temp.br_redova; ++x) {
                    for(int y(0); y<temp.br_kolona; ++y) {

                        temp.elementi[x][y] = m.elementi[x][y];

                    }
                }
                referenca = temp;
            }

            for(int red(0); red<temp.br_redova; ++red) {
                for(int kolona(0); kolona<temp.br_kolona; ++kolona) {
                    temp.elementi[red][kolona] = *koeficijenti * temp.elementi[red][kolona];
                }
            }

            ++koeficijenti;
            Rezultat = P;
            P = ZbirMatrica<TipElemenata>(P, temp);
            UnistiMatricu(Rezultat);
            UnistiMatricu(temp);
        }
    }

    return P;
}

int main()
{
    Matrica<double> a, polinom; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu<double>('A', a);
        std::vector<double> stepeni;
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i(0); i<=red; ++i) {
            double unos;
            std::cin>>unos;
            stepeni.push_back(unos);
        }
        polinom = MatricniPolinom<double>(a, red, std::begin(stepeni));
        IspisiMatricu<double>(polinom, 10, 6);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error e) {
        std::cout<<"Izuzetak: "<<e.what();
    }
    UnistiMatricu<double>(a);
    UnistiMatricu<double>(polinom);
    return 0;
}