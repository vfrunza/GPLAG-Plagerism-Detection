/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <new>
#include <iomanip>
#include <stdexcept>

template <typename tip>
struct Matrica {
    int broj_redova, broj_kolona;
    tip **elementi=nullptr;
};

template <typename tip>
void UnistiMatricu(Matrica<tip> mat){
    if(!mat.elementi) return;
    for(int i(0); i<mat.broj_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename tip>
Matrica<tip> StvoriMatricu(int broj_redova, int broj_kolona) {
    Matrica<tip> mat;
    mat.broj_redova=broj_redova;
    mat.broj_kolona=broj_kolona;
    mat.elementi = new tip*[broj_redova];
    for(int i(0); i<broj_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i(0); i<broj_redova; i++) mat.elementi[i] = new tip[broj_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename tip>
void UnesiMatricu(char ime_matrice, Matrica<tip> &mat) {
    for(int i(0); i<mat.broj_redova; i++) {
        for(int j(0); j<mat.broj_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename tip>
void IspisiMatricu(const Matrica<tip> &mat, int sirina, int preciznost=6, bool treba_brisati=false) {
    for(int i(0); i<mat.broj_redova; i++) {
        for(int j(0); j<mat.broj_kolona; j++) {
            std::cout << std::setw(sirina) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename tip>
Matrica<tip> ZbirMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2) {
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) 
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<tip>(m1.broj_redova, m1.broj_kolona));
    for(int i(0); i<m1.broj_redova; i++) {
        for(int j(0); j<m1.broj_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template<typename tip>
Matrica<tip> ProduktMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2) {
    if(m1.broj_kolona!=m2.broj_redova) {
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    auto m3(StvoriMatricu<tip>(m1.broj_redova, m2.broj_kolona));
    for(int i(0); i<m3.broj_redova; i++) {
        for(int j(0); j<m3.broj_kolona; j++) {
            m3.elementi[i][j] = 0;
        }
    }
    for(int i(0); i<m1.broj_redova; i++) {
        for(int j(0); j<m2.broj_kolona; j++) {
            for(int k(0); k<m1.broj_kolona; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template<typename tip> 
Matrica<tip> Stepenovanje(const Matrica<tip> &mat, int stepen) {
    auto rez(StvoriMatricu<tip>(mat.broj_redova, mat.broj_kolona));
    auto jedinicna(StvoriMatricu<tip>(mat.broj_redova, mat.broj_kolona));
    for(int i(0); i<mat.broj_redova; i++) {
            for(int j(0); j<mat.broj_kolona; j++) {
                if(i==j) jedinicna.elementi[i][j]=1;
                else jedinicna.elementi[i][j]=0;
            }
        }
    if(stepen==0) return jedinicna;
    else{
        for(int i(1); i<=stepen; i++){
            rez=ProduktMatrica(mat, jedinicna);
        }
    }
    return rez;
}

template<typename tip>
Matrica<tip> Pomnozi(const Matrica<tip> &mat, int broj){
    auto rez(StvoriMatricu<tip>(mat.broj_redova, mat.broj_kolona));
    for(int i(0); i<mat.broj_redova; i++){
        for(int j(0); j<mat.broj_kolona; j++) rez.elementi[i][j]=mat.elementi[i][j]*broj;
    }
    return rez;
}

template<typename tip>
Matrica<tip> MatricniPolinom(Matrica<tip> A, std::vector<int> v) {
    if(A.broj_redova!=A.broj_kolona) {
        UnistiMatricu(A);
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    auto rez(StvoriMatricu<tip>(A.broj_redova, A.broj_kolona));
    for(int i(0); i<A.broj_redova; i++) {
            for(int j(0); j<A.broj_kolona; j++) rez.elementi[i][j]=0;
        }
    for(int i(0); i<v.size(); i++) {
        //rez=ZbirMatrica(rez, Pomnozi(Stepenovanje(A, i), v[i]));
        auto pomocna(StvoriMatricu<tip>(A.broj_redova, A.broj_kolona));
        for(int i(0); i<A.broj_redova; i++) {
            for(int j(0); j<A.broj_kolona; j++) pomocna.elementi[i][j]=A.elementi[i][j];
        }
        auto stepenovana(StvoriMatricu<tip>(A.broj_redova, A.broj_kolona));
        stepenovana=Stepenovanje(pomocna, i);
        auto pomnozena(StvoriMatricu<tip>(A.broj_redova, A.broj_kolona));
        pomnozena=Pomnozi(stepenovana, v[i]);
        auto suma(StvoriMatricu<tip>(A.broj_redova, A.broj_kolona));
        suma=ZbirMatrica(rez, pomnozena);
        UnistiMatricu(stepenovana);
        UnistiMatricu(pomnozena);
        
    }
    return rez;
}

int main (){
    Matrica <double> a;
    std::vector<int> v;
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try{
        a=StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i(0); i<=n; i++) {
            int broj;
            std::cin >> broj;
            v.push_back(broj);
        }
        IspisiMatricu(MatricniPolinom(a, v), 10, 5, true);
        UnistiMatricu(a);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    
	return 0;
}