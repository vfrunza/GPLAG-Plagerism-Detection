/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i(0); i <mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i(0); i < br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i(0); i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0); i < mat.br_redova; i++)
        for(int j(0); j < mat.br_kolona; j++){
            std::cout<<ime_matrice<<" (" << i+1<< ", " << j+1 <<") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa){
    for(int i(0); i < mat.br_redova; i++){
        for(int j(0); j < mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i(0); i < m1.br_redova; i++)
        for(int j(0); j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_kolona, m2.br_redova));
    for(int i(0); i < m1.br_redova; i++){
        for(int j(0); j < m2.br_kolona; j++){
            double suma(0);
            for(int k(0); k < m2.br_kolona; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int stepen, IterTip it){
    if(stepen < 0) throw std::domain_error("Neispravan stepen polinoma");
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto pomocna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto jedinicna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto povratna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto kvadratna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    kvadratna = m;
    for(int i(0); i < jedinicna.br_redova; i++){
        for(int j(0); j < jedinicna.br_kolona; j++){
            if(i == j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }
    for(int i(0); i <= stepen; i++){
        for(int j(0); j < pomocna.br_redova; j++){
            for(int k(0); k < pomocna.br_kolona; k++){
                pomocna.elementi[j][k] = *it;
            }
        }
        it++;
        if(i == 0){
            m3 = ProduktMatrica(pomocna,jedinicna);
            povratna = m3;
        }
        else{
            for(int l(0); l < i; l++){
                kvadratna = ProduktMatrica(kvadratna,m);
            }
            m3 = ProduktMatrica(pomocna,kvadratna);
            povratna = ZbirMatrica(povratna,m3);
        }
        
    }
    return povratna;
}

int main ()
{
    Matrica<double> a,rezultat;
    int m,n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try{
        a = StvoriMatricu<double>(m, m);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A', a);
       std::cout << "Unesite red polinoma: ";
       std::cin >> n;
       std::cout << "Unesite koeficijente polinoma: ";
       std::vector<double> v(n+1);
       for(int i(0); i <= n; i++){
           std::cin>> v[i];
       }
       rezultat = MatricniPolinom(a,n,v.begin());
       IspisiMatricu(rezultat,6);
    }
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!"<<std::endl;
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        UnistiMatricu(rezultat);
    }
    UnistiMatricu(a); UnistiMatricu(rezultat);// UnistiMatricu(b); UnistiMatricu(c);
	return 0;
}
