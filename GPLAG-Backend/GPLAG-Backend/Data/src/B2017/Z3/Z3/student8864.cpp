/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip> 
#include <stdexcept>
#include <vector>

template < typename TipEl >
struct Matrica {
    int br_redova, br_kolona;
    TipEl **elementi =  nullptr;
};

template <typename TipEl>  
void UnistiMatricu (Matrica<TipEl> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipEl>
Matrica <TipEl> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica <TipEl> mat;
    mat.br_kolona = br_kolona;
    mat.br_redova = br_redova;
    mat.elementi = new TipEl*[br_redova];
    try{
    for(int i=0; i<br_redova; i++) 
        mat.elementi[i] = nullptr;
    for(int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipEl[br_kolona]{};
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;

}

template <typename TipEl>
void UnesiMatricu (char ime_matrice, Matrica<TipEl> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "("<<i+1<<","<<j+1<<") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipEl>
void IspisiMatricu (Matrica<TipEl> mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }

    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipEl>
Matrica<TipEl> ZbirMatrica ( const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona!= m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije");
    Matrica<TipEl> m3;
    try{
        m3=StvoriMatricu<TipEl>(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            }
        }
        return m3;
    }catch(...){
        UnistiMatricu(m3);
        throw;
    }
}

template <typename TipEl>
Matrica<TipEl> ProduktMatrica (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3;
    try{
        m3=StvoriMatricu<TipEl>(m1.br_redova, m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m2.br_kolona; j++) {
                m3.elementi[i][j]=0;
                for(int k=0; k<m1.br_kolona; k++) {
                    m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        return m3;
    }catch(...){
        UnistiMatricu(m3);
        throw;
    }
}

template <typename TipEl>
Matrica<TipEl> ProduktMatriceISkalara ( const Matrica<TipEl> &m1, double n)
{
    Matrica<TipEl> m2;
    try{
        m2=StvoriMatricu<TipEl>(m1.br_redova, m1.br_kolona);
        for(int i=0; i< m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                m2.elementi[i][j] = m1.elementi[i][j] * n;
            }
        }
        return m2;
    }catch(...){
        UnistiMatricu(m2);
        throw;
    }
}

template <typename TipEl>
Matrica <TipEl> JedinicnaMatrica (int format)
{
    Matrica <TipEl> jedinicna_matrica;
    try{
        jedinicna_matrica= StvoriMatricu<TipEl>(format, format);
        for(int i=0; i<format; i++) {
            for(int j=0; j<format; j++) {
                if(i==j) jedinicna_matrica.elementi[i][j] = 1;
            }
        }
        return jedinicna_matrica;
    }catch(...){
        UnistiMatricu(jedinicna_matrica);
        throw;
    }
}

template <typename TipEl, typename IterTip>
Matrica <TipEl> MatricniPolinom (const Matrica <TipEl> &mat, int n, IterTip koeficijenti)
{
    if(n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if(mat.br_kolona != mat.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");

    Matrica <TipEl> matricni_polinom;
    Matrica <TipEl> stepenovana_matrica;
    
    try {
        matricni_polinom=StvoriMatricu<TipEl>(mat.br_redova, mat.br_kolona);
        stepenovana_matrica=JedinicnaMatrica<TipEl>(mat.br_redova);
        for(int i=0; i<=n; i++) { 
            Matrica <TipEl> tmp(ProduktMatriceISkalara(stepenovana_matrica, *koeficijenti));
            Matrica<TipEl> novi_polinom(ZbirMatrica(tmp, matricni_polinom));
            UnistiMatricu(matricni_polinom);
            matricni_polinom = novi_polinom;
            Matrica<TipEl> nova_stepenovana(ProduktMatrica(stepenovana_matrica, mat));
            UnistiMatricu(stepenovana_matrica);
            stepenovana_matrica = nova_stepenovana;
            UnistiMatricu(tmp);
            koeficijenti++;
        }

        UnistiMatricu(stepenovana_matrica);
        return matricni_polinom;
    } catch(...) {
        UnistiMatricu(stepenovana_matrica);
        UnistiMatricu(matricni_polinom);
        throw;
    }
}



int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;

    std::cout << "Unesite elemente matrice A: " << std::endl;
    Matrica<double> a;
    try {
        a = StvoriMatricu<double>(dimenzija,dimenzija);
        UnesiMatricu('A', a);

        std::cout << "Unesite red polinoma: ";
        int red_polinoma;
        std::cin >> red_polinoma;

        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        for(int i=0; i<=red_polinoma; i++) {
            int unos;
            std::cin >> unos;
            koeficijenti.push_back(unos);
        }

        IspisiMatricu(MatricniPolinom(a, red_polinoma, koeficijenti.begin()), 10, 6, true);

    } catch(std::domain_error err) {
        std::cout << err.what() << std::endl;
        UnistiMatricu(a);
    }
    UnistiMatricu(a);
    return 0;
}
