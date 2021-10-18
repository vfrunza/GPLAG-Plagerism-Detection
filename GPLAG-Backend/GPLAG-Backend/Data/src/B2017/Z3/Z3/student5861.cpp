/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
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
    for(int i=0; i<br_redova; i++)
        mat.elementi[i] = nullptr;
    try {
        for(int i=0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu (Matrica<TipElemenata> mat, int sirina_ispisa)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{

    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto produkt(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    try {
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                TipElemenata s(0);
                for(int k=0; k<m2.br_kolona; k++) {
                    s+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                produkt.elementi[i][j] = s;
                s=0;
            }
        }
    } catch (...) {
        throw;
    }
    return produkt;

}

template <typename TipElemenata>
Matrica<TipElemenata> NapraviJedinicnuMatricu (TipElemenata br_redova){
    Matrica<TipElemenata> m = StvoriMatricu<TipElemenata>(br_redova, br_redova);
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_redova; j++){
            if(i==j) m.elementi[i][j] = 1;
            else m.elementi[i][j] = 0;
        }
    }
    return m;
}

template <typename TipElemenata>
void KopirajElemente (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    for (int i=0; i<m2.br_redova; i++)
        for (int j=0; j<m2.br_kolona; j++)
            m1.elementi[i][j] = m2.elementi[i][j];
}

template <typename TipElemenata>
Matrica<TipElemenata> StepenujMatricu (const Matrica<TipElemenata> &A, int stepen){
    if (stepen < 1) throw;
    if (stepen == 1) return A;
    else{
        Matrica<TipElemenata> prethodna_vrijednost = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        KopirajElemente(prethodna_vrijednost, A);
        Matrica<TipElemenata> sljedeca_vrijednost = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        for (int i=2; i<=stepen; i++)
        {
            sljedeca_vrijednost = ProduktMatrica(prethodna_vrijednost, A);
            KopirajElemente(prethodna_vrijednost, sljedeca_vrijednost);
            UnistiMatricu(sljedeca_vrijednost);
           
        }
        return prethodna_vrijednost;
    }
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m, int n, Tip pocetak)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    //ne unistavam rezultat, jer ga vracam kao rezultat
    Matrica<TipElemenata> prethodna_vrijednost = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    Matrica<TipElemenata> sljedeca_vrijednost = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    Matrica<TipElemenata> pomocna = NapraviJedinicnuMatricu(m.br_redova);
    
    for (int i=0; i<n; i++)
    {
        sljedeca_vrijednost = ZbirMatrica(prethodna_vrijednost,PomnoziSaKoeficijentom(pomocna, *pocetak));
    }
    
}
int main ()
{
    Matrica<double> a, b, c;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        
        b = StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice B:\n";
        UnesiMatricu('B', b);
        IspisiMatricu(b,3);
        c = StepenujMatricu(b,4);
        IspisiMatricu(c, 3);
    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n" << std::endl;
    }
   UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);

    return 0;
}
