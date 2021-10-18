/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <iomanip>
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
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

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
            for(int k=0;k<m1.br_kolona;k++){
                m3.elementi[i][j]=m3.elementi[i][j]+m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> Korak_Prvi(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2, std::vector<double>v){
    
    for(int i=0; i<m1.br_redova;i++){
            for(int j=0; j<m1.br_kolona;j++){
                if(j==i) m2.elementi[i][j]=v[0];
                else m2.elementi[i][j]=0;
            }
        }
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, std::vector<double>v){
    if(m1.br_kolona != m1.br_redova)throw std::domain_error("Matrica mora biti kvadratna");
        auto mat(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++){
        for(int j=0; j<m1.br_kolona; j++){
            mat.elementi[i][j]=0;
}}
        if(v.size()==0) return mat;
       for(int i=0; i<m1.br_redova;i++){
            for(int j=0; j<m1.br_kolona;j++){
                if(j==i) mat.elementi[i][j]=v[0];
                else mat.elementi[i][j]=0;
            }} 
        
//       double pom=v[0];
//        mat=Korak_Prvi(mat, m1, v);
        if(v.size()==1) return mat;
        for(int i=0; i<m1.br_redova;i++){
            for(int j=0; j<m1.br_kolona;j++){
                if(j==i) mat.elementi[i][j]=v[0]+v[1]*m1.elementi[i][j];
                else mat.elementi[i][j]=v[1]*m1.elementi[i][j];
            }
        }
        if(v.size()==2) return mat;
            
        auto pmat(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        
        for(int i=0; i<m1.br_redova;i++){
            for(int j=0; j<m1.br_kolona;j++){
                pmat.elementi[i][j]=m1.elementi[i][j];
            }
        }
        
        for(int i=2; i<v.size();i++){
            auto produktna=ProduktMatrica(pmat, m1);
            
            for(int j=0; j<m1.br_redova;j++){
                for(int k=0; k<m1.br_kolona;k++){
                    mat.elementi[j][k]+=v[i]*produktna.elementi[j][k];
                }
            }
            
            for(int a=0; a<m1.br_redova;a++){
            for(int b=0; b<m1.br_kolona;b++){
                pmat.elementi[a][b]=produktna.elementi[a][b];
            }
        }
            UnistiMatricu(produktna);
        }
        UnistiMatricu(pmat);
        return mat;
        
}
int main()
{
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int n,m;
    std::cout << "Unesite dimenziju kvadratne matrice:\n";
    std::cin >> n;
    m=n;
    try {
        a = StvoriMatricu<double>(n, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> v;
        for(int i=0; i<=red;i++){
            double el;
            std::cin>>el;
            v.push_back(el);
        }
        auto b(MatricniPolinom(a,v));
        IspisiMatricu(b, 10);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}

//IspisiMatricu(c = ZbirMatrica(a, b), 7);