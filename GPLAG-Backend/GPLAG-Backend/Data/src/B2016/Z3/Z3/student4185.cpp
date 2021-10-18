#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <new>
template <typename TipElemenata>
struct Matrica {
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
bool Saglasne(const Matrica<TipElemenata> &matrica1, const Matrica<TipElemenata> &matrica2)
{
    if (matrica1.br_kolona == matrica2.br_redova) {
        return true;
    }
    return false;
}
//JEDINICNA I NULA
template <typename TipElemenata>
void Jedinicna(Matrica<TipElemenata> &matrica)
{
    for(int i = 0; i < matrica.br_kolona; i++) {
        for(int j = 0; j < matrica.br_redova; j++) {
            if(i==j) matrica.elementi[i][j]=1;
            else matrica.elementi[i][j]=0;
        }
    }
}
template<typename TipElemenata>
void NulaA(Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_kolona; i++) {
        for(int j = 0; j < mat.br_redova; j++) {
            mat.elementi[i][j] = 0;
        }
    }
}
//S A   S K A L A R O M
template<typename TipElemenata, typename Tip2>
void SaSkalarom(Matrica<TipElemenata> &mat, Tip2 skalar)
{
    for(int i = 0; i < mat.br_kolona; i++) {
        for(int j = 0; j < mat.br_redova; j++) {
            mat.elementi[i][j]=skalar*mat.elementi[i][j];
        }
    }
}


template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(const int &br_redova,const int &br_kolona)
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
void IspisiMatricu( Matrica<TipElemenata> &mat,
                    int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout <<std::setprecision(preciznost)<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
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

//P R O D U K T
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &matrica1, const Matrica<TipElemenata> &matrica2)
{
    if (!Saglasne(matrica1,matrica2)) {
        throw  std::domain_error ("Matrice nisu saglasne za mnozenje");
    }

    auto nova ( StvoriMatricu<TipElemenata>(matrica1.br_redova, matrica2.br_kolona));



    for(int i = 0; i < matrica1.br_redova; i++) {
        for(int j = 0; j < matrica2.br_kolona; j++) {
            TipElemenata suma=0;
            for(int k = 0; k < matrica2.br_redova; k++) {
                suma +=matrica1.elementi[i][k]*matrica2.elementi[k][j];
            }
            nova.elementi[i][j] = suma;
        }
    }
    return nova;
}
template<typename TipElemenata>
void Premjesti(Matrica<TipElemenata> &mat1, Matrica<TipElemenata> mat2)
{
    for(int i = 0; i<mat2.br_kolona; i++) {
        for(int j= 0; j<mat2.br_redova; j++) {
            mat1.elementi[i][j]=mat2.elementi[i][j];
        }
    }
}
//P O L I N O M
template<typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom( const Matrica<TipElemenata> &A, std::vector<double> kovi)
{
    if (A.br_kolona != A.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<TipElemenata> vrati=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    if (kovi.size() == 0 ) {
        NulaA(vrati);
        return vrati;
    }
    Matrica<TipElemenata> pomoc;
    auto nova(StvoriMatricu<TipElemenata>(A.br_kolona,A.br_redova));
    Jedinicna(nova);
    SaSkalarom(nova,kovi[0]);
    Premjesti(vrati,nova);
    
    auto spasi(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    auto spasi2(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> stepen;
    Premjesti(spasi,A);
    Premjesti(spasi2,A);
    for(int i = 1; i < kovi.size(); i++) {
        if(i!=1) {
            stepen=ProduktMatrica(spasi,A);

            Premjesti(spasi,stepen);
            SaSkalarom(stepen,kovi[i]);
            pomoc=ZbirMatrica(vrati,stepen);
            Premjesti(vrati,pomoc);
            UnistiMatricu(pomoc);
            UnistiMatricu(stepen);
        } else {
            SaSkalarom(spasi2,kovi[i]);
            pomoc=ZbirMatrica(vrati,spasi2);
            Premjesti(vrati,pomoc);
            UnistiMatricu(pomoc);

        }
    }
    UnistiMatricu(spasi);
    UnistiMatricu(spasi2);
    UnistiMatricu(nova);
    return vrati;
}

int main()
{
    try {
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        int dim;
        std::cin >> dim;
        auto A(StvoriMatricu<double>(dim,dim));
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu<double>('A',A);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: " ;
        std::vector<double>kovi ;
        for(int i = 0; i <= red; i++) {
            int p;
            std::cin >> p;
            kovi.push_back(p);
        }

        auto b(MatricniPolinom<double>(A,kovi));
        IspisiMatricu(b,10);
        UnistiMatricu(b);
        UnistiMatricu(A);
    } catch(std::domain_error greska) {
        std::cout << greska.what();
    } catch(...) {
        std::cout << "Problemi s memorijom!" << std::endl;
    }
    return 0;
}
