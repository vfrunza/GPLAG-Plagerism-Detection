/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <cmath>
#include <vector>

template <typename Tip>
struct Matrica {
    int broj_redova, broj_kolona;
    Tip **elementi = nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> mat)
{
    if(!mat.elementi) return;
    for(int i = 0 ; i < mat.broj_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu (int broj_redova,int broj_kolona)
{
    Matrica<Tip> mat;
    mat.broj_redova = broj_redova;
    mat.broj_kolona = broj_kolona;
    mat.elementi = new Tip*[broj_redova];
    for(int i = 0 ; i < broj_redova ; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0 ; i < broj_redova; i++)
            mat.elementi[i] = new Tip[broj_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename Tip>
void UnesiMatricu(char ime_matrice , Matrica<Tip> &mat)
{
    for(int i = 0 ; i < mat.broj_redova; i++)
        for(int j = 0 ; j < mat.broj_kolona; j++) {
            std::cout<<ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &mat, int sirina_ispisa)
{
    for(int i = 0 ; i < mat.broj_redova; i++) {
        for(int j = 0 ; j < mat.broj_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
}

template <typename Tip>
Matrica<Tip> ZbirMatrica (const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.broj_redova,m2.broj_kolona));
    for(int i = 0 ; i < m1.broj_redova; i++)
        for(int j = 0 ; j < m1.broj_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];

    return m3;
}

template <typename Tip>
Matrica<Tip> ProduktMatrica (const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    if(m1.broj_kolona != m2.broj_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<Tip>(m1.broj_redova,m2.broj_kolona));
        for(int i = 0 ; i < m1.broj_redova; i++){
            for(int j = 0 ; j < m2.broj_kolona; j++){
                m3.elementi[i][j] = m1.elementi[i][j]*m2.elementi[i][j];
            }
        }
        
        return m3;
}
template <typename Tip>
Tip MatricniPolinom (const Matrica<Tip> &m, std::vector<Tip> vektor){
    int vrijednost1,vrijednost2(0);
   if ( m.broj_redova != m.broj_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    for ( int i = 0 ; i < vektor.size(); i++){
        for( int j = 0 ; j < vektor.size(); j++){
            vrijednost1 += pow(ProduktMatrica(m,m),vektor.at(j));
        }
        vrijednost2 += vektor.at(i)*vrijednost1;
    }
    return vrijednost2;
}
int main ()
{
    Matrica<double> a, b, c;
    int  n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        b = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
    std::cout<<"Unesite red polinoma: ";
    int m ; 
    std::cin>>m;
        std::cout <<"Unesite koeficijente polinoma: ";
        std::vector<int> vektor;
        for(int i = 0 ; i < m ; i++){
            int x ; 
            std::cin>>x;
            vektor.push_back(x);
        }
        IspisiMatricu(ProduktMatrica(a,b),10);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    return 0;
}