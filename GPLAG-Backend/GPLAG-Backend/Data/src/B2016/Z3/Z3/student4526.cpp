#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
using namespace std;
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
bool MoguLiSeMnoziti(Matrica <TipElemenata> m1,Matrica <TipElemenata> m2)
{
    if(m1[0].size()!=m2.size())return false;
    return true;
}
template<typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(MoguLiSeMnoziti(m1,m2)==false)throw domain_error("Matrice nisu saglasne za mnozenje");
    auto matrica3(StvoriMatricu(m1.size(),m2[0].size()));
    for(int i(0); i<m1.size(); i++)
        for(int j(0); j<m2[0].size(); j++) {
            double x(0);
            for(int s(0); s<m2.size(); s++) {
                x+=m1[i][s]*m1[s][j];
            }
            matrica3[i][j]=x;

        }
    return matrica3;


}
template <typename TipElemenata>
Matrica <TipElemenata> PravimJedinicnu(int brredova, int brkolona){
   
   auto jedinicna(StvoriMatricu (brredova, brkolona));
    for(int i(0);i<brredova;i++){
        for(int j(0);j<brkolona;j++){if(i==j)jedinicna[i][j]=1;
        else jedinicna[i][j]=0;
    }
    
}return jedinicna;}

template<typename TipElemenata>
Matrica <TipElemenata> MnoziSkalarom(double skalar,Matrica<TipElemenata> matrica){
    for(int i(0);i<matrica.size();i++){
        for(int j(0);j<matrica[i].size();j++){
            matrica[i][j]*=skalar;
        }
    }
    return matrica;
}
template<typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom( Matrica <TipElemenata> A, vector <double> n){
    if(A.size()!=A[0].size())throw domain_error("Matrica mora biti kvadratna");
    
   auto nova(StvoriMatricu(A.size(),A[0].size()));
  auto  suma(StvoriMatricu(A.size(),A[0].size()));
    for(int i(0);i<suma.size();i++){
        for(int j=0;j<suma[i].size();j++){
            suma[i][j]=0;
        }
    }
    for(int i(0);i<n.size();i++){
        if(i==0){
            suma=suma+MnoziSkalarom(n[i], PravimJedinicnu(A.size(),A[i].size()));
        }
        else{
            for(int k(0);k<i;k++){
                nova=ProduktMatrica(nova,nova);
            }
            
            suma=ZbirMatrica(suma,MnoziSkalarom(n[i],nova));
        }
        }
        return suma;
    
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            cout << setw(sirina_ispisa) << mat.elementi[i][j];
        cout << endl;
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

int main()
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    cout << "Unesi broj redova i kolona za matrice:\n";
    cin >> m >> n;
    try {
        a = StvoriMatricu<double>(m, n);
        b = StvoriMatricu<double>(m, n);
        cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
        cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a, b), 7);
    } catch(bad_alloc) {
        cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    return 0;
}
