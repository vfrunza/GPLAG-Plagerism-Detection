/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include <deque>
#include <algorithm>

template <typename TipElementa>
struct Matrica {
    int br_redova,br_kolona;
    TipElementa **elementi=nullptr;
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
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElementa>
void UnesiMatricu(char ime_matrice,Matrica<TipElementa>&mat)
{
    for(int i(0); i<mat.br_redova; i++)
        for(int j(0); j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }

    if(treba_brisati) UnistiMatricu(mat);
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

template<typename TipElementa>
Matrica<TipElementa>ProduktMatrica(const Matrica <TipElementa> &m1,const Matrica<TipElementa> &m2)
{

    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    Matrica<TipElementa> m3(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    int red(m3.br_redova);
    int kolona(red);
    for(int i(0); i<m3.br_redova; i++) {
        for(int j(0); j<m3.br_kolona; j++) {


            int saltac(0);
            m3.elementi[i][j]=0;
            while(saltac<red || saltac<kolona) {
                m3.elementi[i][j]+=m1.elementi[i][saltac]*m2.elementi[saltac][j];
                saltac++;
            }
        }
    }
    return m3;
}

template<typename TipElementa,typename pok_it>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &m,int n,pok_it it)
{

    if(n<0) throw std::domain_error("Neispravan stepen polinoma");

    Matrica<TipElementa> Polinom(StvoriMatricu<TipElementa>(m.br_redova,m.br_kolona));
    const int redovi=m.br_redova;
    const int kolone=m.br_kolona;

    for(int i(0); i<redovi; i++) {
        for(int j(0); j<kolone; j++) {
            if(i==j) Polinom.elementi[i][j]=*it;
            else Polinom.elementi[i][j]=0;
        }
    }
    it++;

    for(int i(0); i<redovi; i++) {
        for(int j(0); j<kolone; j++) {
            Polinom.elementi[i][j]=Polinom.elementi[i][j]+(m.elementi[i][j]*(*it));
        }
    }
    it++;

    if(n<2) return Polinom;
    else {

        int brojac=2;

        while(brojac<=n) {
            Matrica<TipElementa>memorija=Polinom;

            Matrica<TipElementa>Stepen=ProduktMatrica(m,m);
            Matrica<TipElementa>Stepen_kopija=Stepen;
            for(int stepen(2); stepen<brojac; stepen++) {
                Stepen=ProduktMatrica(Stepen,m);
                UnistiMatricu<TipElementa>(Stepen_kopija);
                Stepen_kopija=Stepen;
            }

            for(int i = 0; i<redovi; i++) {
                for(int j = 0; j<kolone; j++) {
                    Stepen.elementi[i][j] *= *it;
                }
            }

            Polinom = ZbirMatrica<TipElementa>(Stepen, Polinom);
            UnistiMatricu<TipElementa>(memorija);
            UnistiMatricu<TipElementa>(Stepen);
            brojac++;
            it++;
        }
    }


    return Polinom;
}
int main ()
{

    Matrica<double> a, funkcija;
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    try {
        a = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::deque<double> dek_p(red_polinoma + 1);
        std::for_each(dek_p.begin(), dek_p.end(), [](double &p) {
            std::cin>>p;
        });
        funkcija = MatricniPolinom(a, red_polinoma, dek_p.begin());
        IspisiMatricu(funkcija, 10, 6, true);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    UnistiMatricu(a);
    return 0;
}