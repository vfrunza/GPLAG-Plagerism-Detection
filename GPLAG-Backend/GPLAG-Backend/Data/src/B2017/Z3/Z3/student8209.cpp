/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <memory>
#include <stdexcept>
#include <iomanip>
#include <vector>


template <typename Tip>
struct Matrica {
    int br_redova, br_kolona;
    Tip **elementi = nullptr;
};

template<typename Tip>
void UnistiMatricu(Matrica<Tip> matrica)
{
    if(!matrica.elementi) return;
    for(int i = 0; i <matrica.br_redova; i++) delete[] matrica.elementi[i];
    delete [] matrica.elementi;
    matrica.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<Tip> matrica;
    matrica.br_redova = br_redova;
    matrica.br_kolona = br_kolona;

    matrica.elementi = new Tip* [br_redova];
    for(int i = 0; i< br_redova; i++) matrica.elementi[i] = nullptr;

    try {
        for(int i = 0; i < br_redova ; i++) matrica.elementi[i] = new Tip [br_kolona];
    } catch (const std::bad_alloc &e) {
        UnistiMatricu(matrica);
        throw;
    }

    return matrica;
}

template<typename Tip>
void UnesiMatricu (char ime_matrice, Matrica<Tip> &matrica)
{
    for(int i = 0; i < matrica.br_redova; i++) {
        for(int j = 0; j < matrica.br_kolona; j++) {
            std::cout <<ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> matrica.elementi[i][j];
        }
    }
}

template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &matrica, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < matrica.br_redova; i++) {
        for(int j = 0; j < matrica.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << matrica.elementi[i][j];

        }
        
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(matrica);
}

template <typename Tip>
Matrica<Tip> ZbirMatrica (const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];

    return m3;


}

template<typename Tip>
void NapraviJedinicnu (Matrica<Tip> &jedinicna)
{
    for(int i = 0; i< jedinicna.br_kolona; i++)
        for(int j = 0; j <jedinicna.br_kolona; j++) {
            if(i == j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }

}

template <typename Tip>
bool NesaglasneZaMnozenje (const Matrica<Tip> &prva, const Matrica<Tip> &druga)
{
    return prva.br_kolona != druga.br_redova;
}


template<typename Tip>
Matrica<Tip> PomnoziSkalarom (const Matrica<Tip> &matrica, Tip skalar)
{

    auto rezultujuca (StvoriMatricu<Tip>(matrica.br_redova,matrica.br_kolona));
    for(int i = 0; i < matrica.br_redova; i++)
        for(int j = 0; j < matrica.br_kolona; j++)
            rezultujuca.elementi[i][j] = matrica.elementi[i][j] * skalar;

    return rezultujuca;

}


template<typename Tip>
Matrica<Tip> KopirajiBrisi (Matrica<Tip> &matrica)
{
    auto rez (StvoriMatricu<Tip>(matrica.br_redova, matrica.br_kolona));
    for(int i = 0; i< matrica.br_redova; i++)
        for(int j = 0; j < matrica.br_kolona; j++)
            rez.elementi[i][j] = matrica.elementi[i][j];
    UnistiMatricu(matrica);

    return rez;
}
template<typename Tip>
void Kopiraj (Matrica<Tip> &matrica, Matrica<Tip> druga)
{
    for(int i = 0; i< matrica.br_redova; i++)
        for(int j = 0; j < matrica.br_kolona; j++)
            matrica.elementi[i][j] = druga.elementi[i][j];

}

template <typename Tip>
void ZbirPoPolinomu (Matrica<Tip> &prva,  Matrica<Tip> &druga)
{
    auto rezultujuca (ZbirMatrica<Tip>(prva, druga));
    UnistiMatricu(druga);
    Kopiraj(prva, rezultujuca);
    UnistiMatricu( rezultujuca);
}

template<typename Tip>
Matrica<Tip> ProduktMatrica (const Matrica<Tip> &prva, const Matrica<Tip> &druga)
{
    if (NesaglasneZaMnozenje(prva,druga)) throw std::domain_error ("Matice nisu saglasne za mnozenje");

    try {
        auto rezultujuca (StvoriMatricu<Tip>(prva.br_redova, druga.br_kolona));

        for(int i = 0; i < prva.br_redova; i++) {
            for(int j = 0; j < druga.br_kolona; j++) {
                Tip suma {};
                for(int k = 0; k < druga.br_redova; k++) suma += prva.elementi[i][k] * druga.elementi[k][j];
                rezultujuca.elementi[i][j] = suma;
            }
        }
        return rezultujuca;
    }

    catch (...) {
        std::cout<< "Problemi sa memorijom" << std::endl;
        throw;

    }
}


template <typename Tip, typename TipPodatka>
Matrica<Tip> MatricniPolinom (Matrica<Tip> A, int stepen_polinoma, TipPodatka koeficijenti)
{
    if(stepen_polinoma < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona != A.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");

    Matrica<Tip> rezultujuca;

    auto trenutni_stepen (StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
    NapraviJedinicnu(trenutni_stepen);

    auto vrijednost = PomnoziSkalarom<Tip>(trenutni_stepen, *koeficijenti);
    rezultujuca = vrijednost;

    koeficijenti++;

    for(int i = 1; i <= stepen_polinoma; i++) {

        auto trenutna = ProduktMatrica<Tip>(trenutni_stepen, A);

        Kopiraj(trenutni_stepen,trenutna);
        UnistiMatricu(trenutna);

        trenutna = PomnoziSkalarom(trenutni_stepen, *koeficijenti);
        ZbirPoPolinomu(rezultujuca, trenutna);

        koeficijenti++;
    }
    UnistiMatricu(trenutni_stepen);

    return rezultujuca;
}

int main ()
{
    Matrica<double> a, c;
    int dimenzija, red_polinoma;

    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    std::vector<double> koeficijenti;

    try {
        a = StvoriMatricu<double>(dimenzija,dimenzija);

        std::cout << "Unesite elemente matrice A: " <<std::endl;
        UnesiMatricu('A', a);

        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;

        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= red_polinoma; i++ ) {
            double temp;
            std::cin >> temp;
            koeficijenti.push_back(temp);
        }

        IspisiMatricu(c = MatricniPolinom<double>(a, red_polinoma, koeficijenti.begin()), 10, 6,true);

    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n" << std::endl;
    }

    UnistiMatricu(a);
    return 0;
}
