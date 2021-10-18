/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata** elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if (!mat.elementi) return;
    for (int i=0;i<mat.br_redova;i++)
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    try {
        mat.elementi=new TipElemenata*[br_redova]();
        for (int i=0;i<br_redova;i++) 
            mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for (int i=0;i<mat.br_redova;i++) {
        for (int j=0;j<mat.br_redova;j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for (int i=0;i<mat.br_redova;i++) {
        for (int j=0;j<mat.br_kolona;j++) {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata, typename TipElemenata2>
auto ZbirMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata2> &mat2) ->Matrica<decltype(**mat1.elementi+**mat2.elementi)>{
    if (mat1.br_kolona!=mat2.br_kolona || mat1.br_redova!=mat2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto mat3(StvoriMatricu<decltype(**mat1.elementi+**mat2.elementi)>(mat1.br_redova, mat1.br_kolona));
    for (int i=0;i<mat3.br_redova;i++) 
        for (int j=0;j<mat3.br_kolona;j++) 
            mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
    return mat3;
}
template <typename TipElemenata, typename TipElemenata2>
auto ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata2> &mat2)->Matrica<decltype(**mat1.elementi***mat2.elementi)> {
    if (mat1.br_kolona!=mat1.br_redova) throw std::domain_error("Matrice nisu saglasne sa mnozenje");
    auto mat3(StvoriMatricu<decltype(**mat1.elementi***mat2.elementi)>(mat1.br_redova, mat2.br_kolona));
    for (int i=0;i<mat3.br_redova;i++) {
        for (int j=0;j<mat3.br_kolona;j++) {
            decltype(**mat1.elementi***mat2.elementi) suma(0);
            for (int k=0;k<mat1.br_kolona;k++)
                    suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
}
template <typename TipElemenata, typename TipElemenata2> 
Matrica<TipElemenata> JedinicnaMatrica(const Matrica<TipElemenata2> &mat) {
    auto mat2(StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_redova));
    for (int i=0;i<mat.br_redova;i++) {
        for (int j=0;j<mat.br_kolona;j++) {
            if (i==j) mat2.elementi[i][j]=1;
            else mat2.elementi[i][j]=0;
        }
    }
    return mat2;
}
template <typename TipElemenata, typename TipKoeficijenta>
void MnozenjeSkalarom(Matrica<TipElemenata> &mat, TipKoeficijenta koef) {
    for (int i=0;i<mat.br_redova;i++) 
        for (int j=0;j<mat.br_kolona;j++)
            mat.elementi[i][j]*=koef;    
}
template <typename TipElemenata, typename TipElemenata2>
void PrekopirajElemente(const Matrica<TipElemenata> mat1, Matrica<TipElemenata2> mat2) {
    for (int i=0;i<mat1.br_redova;i++) 
        for (int j=0;j<mat1.br_kolona;j++) 
            mat2.elementi[i][j]=mat1.elementi[i][j];
}
template <typename TipElemenata, typename PokTip>
auto MatricniPolinom(const Matrica<TipElemenata> &mat, int n, PokTip pok)->Matrica<decltype(**mat.elementi**pok)> {
    if (n<0) throw std::domain_error("Neispravan stepen polinoma");
    if (mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto PolMat=StvoriMatricu<decltype(**mat.elementi**pok)>(mat.br_redova, mat.br_kolona);
    for (int i=0;i<=n;i++) {
        if (i==0) {
            auto Jedinicna(JedinicnaMatrica<decltype(*pok***mat.elementi)>(mat));
            MnozenjeSkalarom(Jedinicna, *pok);
            PrekopirajElemente(Jedinicna, PolMat);
            UnistiMatricu(Jedinicna);
        }
        else {
            auto Faktor=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
            PrekopirajElemente(mat, Faktor);
            for (int j=1;j<i;j++) {
                auto temp=Faktor;
                Faktor=ProduktMatrica(Faktor, mat);
                UnistiMatricu(temp);
            }
            MnozenjeSkalarom(Faktor, *pok);
            auto temp2=PolMat;
            PolMat=ZbirMatrica(PolMat, Faktor);
            UnistiMatricu(temp2);
            UnistiMatricu(Faktor);
        }
        pok++;
    }
    return PolMat;
}
int main ()
{
    
    int dim;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dim;
    Matrica<double> mat;
    try {
    mat=StvoriMatricu<double>(dim,dim);
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    UnesiMatricu('A', mat);
    std::cout<<"Unesite red polinoma: ";
    int red;
    std::cin>>red;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<int> koeficijenti(red+1);
    std::for_each(koeficijenti.begin(), koeficijenti.end(), [](int &x) { std::cin>>x;});
    auto MatPol=MatricniPolinom(mat, red, koeficijenti.begin());
    IspisiMatricu(MatPol, 10, 6, true); 
    }
    catch(std::exception &e) {
        std::cout<<e.what(); 
    }
    UnistiMatricu(mat); 
	return 0;
}