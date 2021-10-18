/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica <TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++)
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
    try {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=nullptr;
        try {
            for(int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata[br_kolona];
        } catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    } catch (...) {
        throw;
    }
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<< ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
    else return;

}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
bool SaglasneZaMnozenje (const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(mat1.br_kolona==mat2.br_redova)
        return true;
    return false;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(!SaglasneZaMnozenje(mat1, mat2))
        throw std::domain_error ("Matrice nisu saglasne za mnozenje!\n");

    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona));
    if(mat3.br_redova==0 || mat3.br_kolona==0)
        return mat3;
    for(int i=0; i<mat1.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k<mat2.br_redova; k++)
                suma+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
}

template<typename TipElemenata>
Matrica<TipElemenata> JedinicnaMatrica (const Matrica<TipElemenata> &mat)
{
    auto mat2(StvoriMatricu<TipElemenata> (mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat2.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            if(i==j)
                mat2.elementi[i][j]=1;
            else
                mat2.elementi[i][j]=0;
        }
    }
    return mat2;
}

template<typename TipElemenata, typename TipKoeficijenata>
Matrica<TipElemenata> PomnoziMatricuKoeficijentom (const Matrica<TipElemenata> &mat, TipKoeficijenata Koef)
{
    auto mat2 (StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat2.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            mat2.elementi[i][j]=Koef*mat.elementi[i][j];
        }
    }
    return mat2;
}
template<typename TipElemenata>
void pomfja (const Matrica<TipElemenata> &mat, TipElemenata**elem)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            elem[i][j]=mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat, int n, std::vector<double> v)
{
    if(n<0)
        throw std::domain_error ("Neispravan stepen polinoma");
    if(mat.br_redova != mat.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");

    bool nulvektor(true);
    for(int i=0; i<v.size(); i++) {
        if(std::fabs(v[i])>0.0000000001) {
            nulvektor=false;
            break;
        }
    }

    try {
        auto zavrsna=StvoriMatricu<TipElemenata> (mat.br_redova, mat.br_kolona);
        for(int i=0; i<zavrsna.br_redova; i++)
            for(int j=0; j<zavrsna.br_kolona; j++)
                zavrsna.elementi[i][j]=0;
        if(nulvektor)
            return zavrsna;
        for(int i=0; i<v.size(); i++) {
            if(i==0) {
                try {
                    Matrica<TipElemenata> jedinicna;
                    jedinicna=JedinicnaMatrica<TipElemenata>(mat);
                    try {
                        Matrica<TipElemenata> pom;
                        Matrica<TipElemenata> pom2;
                        pomfja(pom2=ZbirMatrica (zavrsna, pom=PomnoziMatricuKoeficijentom(jedinicna, v[i])), zavrsna.elementi);
                        UnistiMatricu(pom);
                        UnistiMatricu(jedinicna);
                        UnistiMatricu(pom2);
                    } catch(...) {
                        UnistiMatricu(zavrsna);
                        UnistiMatricu(jedinicna);
                        throw;
                    }
                } catch(...) {
                    UnistiMatricu(zavrsna);
                    throw;
                }
            } else if(i==1) {
                try {
                    Matrica<TipElemenata> pom;
                    try {
                        Matrica<TipElemenata> pom2;
                        pomfja(pom2=ZbirMatrica (zavrsna, pom=PomnoziMatricuKoeficijentom(mat, v[i])), zavrsna.elementi);
                        UnistiMatricu(pom);
                        UnistiMatricu(pom2);
                    } catch(...) {
                        UnistiMatricu(zavrsna);
                        UnistiMatricu(pom);
                        throw;
                    }
                } catch(...) {
                    UnistiMatricu(zavrsna);
                    throw;
                }
            } else {
                try {
                    auto matricamnozenja (StvoriMatricu<TipElemenata> (mat.br_redova, mat.br_kolona));
                    pomfja<TipElemenata> (mat, matricamnozenja.elementi);
                    for(int j=1; j<i; j++) {
                        Matrica<TipElemenata> zavrsna1;
                        pomfja (zavrsna1=ProduktMatrica<TipElemenata> (matricamnozenja, mat), matricamnozenja.elementi);
                        UnistiMatricu(zavrsna1);
                    }
                    Matrica<TipElemenata> zavrsna1;
                    pomfja(zavrsna1=PomnoziMatricuKoeficijentom<TipElemenata>(matricamnozenja, v[i]), matricamnozenja.elementi);
                    Matrica<TipElemenata> zavrsna2;
                    pomfja(zavrsna2=ZbirMatrica<TipElemenata> (zavrsna, matricamnozenja), zavrsna.elementi);
                    UnistiMatricu(matricamnozenja);
                    UnistiMatricu(zavrsna1);
                    UnistiMatricu(zavrsna2);
                } catch(...) {
                    UnistiMatricu(zavrsna);
                    throw;
                }
            }
        }
        return zavrsna;
    } catch(...) {
        throw;
    }
}

int main ()
{
    Matrica<double> a;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;

    try {
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);

        int red;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red;

        if(red<0)
            throw std::domain_error ("Neispravan stepen polinoma");

        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v;
        for(int i=0; i<=red; i++) {
            double unos;
            std::cin>>unos;
            v.push_back(unos);
        }
        IspisiMatricu (MatricniPolinom(a,red,v),10,6, true);

    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }

    catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);

    return 0;
}
