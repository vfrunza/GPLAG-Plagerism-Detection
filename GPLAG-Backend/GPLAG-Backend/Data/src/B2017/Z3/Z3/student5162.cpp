/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i(0); i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i(0); i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona; j++) 
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for (int j(0); j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
void VratiJedinicnu(Matrica<TipElemenata> &matrica){
    for(int i(0); i<matrica.br_redova; i++){
        for(int j(0); j<matrica.br_kolona; j++){
            if(i==j) matrica.elementi[i][j]=1;
            else matrica.elementi[i][j]=0;
        }
    }
}
template <typename TipElemenata>
void IspuniNulama(Matrica<TipElemenata> &matrica){
    for(int i(0); i<matrica.br_redova; i++){
        for(int j(0); j<matrica.br_kolona; j++){
            matrica.elementi[i][j]=0;
        }
    }
}
template<typename TipElemenata,typename Ittip>
void PomnoziKoeficijentom(Matrica<TipElemenata> &matrica, Ittip iter){
    for(int i(0); i<matrica.br_redova; i++){
        for(int j(0); j<matrica.br_kolona; j++){
            matrica.elementi[i][j]=(*iter)*(matrica.elementi[i][j]);
        }
    }
}   
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> rezultantna(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    IspuniNulama(rezultantna);
    for(int i(0); i<rezultantna.br_redova; i++){
        for(int j(0); j<rezultantna.br_kolona; j++){
            for(int k(0); k<m2.br_kolona; k++) 
            rezultantna.elementi[i][j]+=(m1.elementi[i][k])*(m2.elementi[k][j]);
        }
    }
    return rezultantna;
}
template <typename TipElemenata,typename Ittip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, Ittip iter){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    int pomocna(0);
    Matrica<TipElemenata> finalna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    Matrica<TipElemenata> jedinicna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    VratiJedinicnu(jedinicna);
    IspuniNulama(finalna);
    while(pomocna<=n){
        if(pomocna==0){
            PomnoziKoeficijentom(jedinicna,iter);
            auto pomocnamat2(ZbirMatrica(finalna,jedinicna));
            UnistiMatricu(finalna);
            finalna=pomocnamat2;
            iter++;
            pomocna++;
        }
        else{
            Matrica<TipElemenata> pomocnamat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
            VratiJedinicnu(pomocnamat);
            int stepen(pomocna);
            while(stepen>0){
                auto pomocnamat2(ProduktMatrica(pomocnamat,m));
                UnistiMatricu(pomocnamat);
                pomocnamat=pomocnamat2;
                stepen--;
            }
            PomnoziKoeficijentom(pomocnamat,iter);
            auto pommat3(ZbirMatrica(finalna,pomocnamat));
            UnistiMatricu(finalna);
            finalna=pommat3;
            UnistiMatricu(pomocnamat);
            iter++;
            pomocna++;
        }
    }
        UnistiMatricu(jedinicna);
        return finalna;
}
int main ()
{
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    Matrica<int> matrica(StvoriMatricu<int>(dimenzija, dimenzija));
    std::cout<<"Unesite elemente matrice A:\n";
    UnesiMatricu('A',matrica);
    int red_polinoma;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>red_polinoma;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<int> elementi_polinoma(red_polinoma+1);
    for(int i(0); i<=red_polinoma; i++) std::cin>>elementi_polinoma.at(i);
    Matrica<int> finalna(MatricniPolinom(matrica,red_polinoma,elementi_polinoma.begin()));
    IspisiMatricu(finalna,10);
    UnistiMatricu(matrica);
    UnistiMatricu(finalna);
	return 0;
}
