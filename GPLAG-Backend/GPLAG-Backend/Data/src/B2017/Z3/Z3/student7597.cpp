/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>

using std::vector;

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
    };
    
    // UNISTI MATRICU
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
    
    // STVORI MATRICU
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
    // KOPIRANJE MATRICA
template<typename TipElemenata>
    Matrica<TipElemenata> Iskopiraj(const Matrica<TipElemenata> &m) {
        auto kopija = StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
                kopija.elementi[i][j] = m.elementi[i][j];
        return kopija;
    }
    
    // UNOS MATRICE
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    // ISPIS MATRICE
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6 , bool treba_brisati=false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati)
            UnistiMatricu(mat);
    }
    
    // ZBIR MATRICA
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
    // PRODUKT MATRICA
template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
            
        auto produkt = StvoriMatricu<TipElemenata>(m1.br_redova , m2.br_kolona);
        try {
            for(int i=0;i<m1.br_redova;i++) {
                for(int j=0;j<m2.br_kolona;j++) {
                    produkt.elementi[i][j] = 0;
                    for(int k=0;k<m1.br_kolona;k++)
                        produkt.elementi[i][j]+= m1.elementi[i][k] * m2.elementi[k][j];
                }
            }
        }
        catch(...) {
            UnistiMatricu(produkt);
            throw;
        }
        return produkt;
    }
    
    // MNOZENJE MATRICE SKALAROM
template<typename TipElemenata>
    Matrica<TipElemenata> pomnoziSkalarom(const Matrica<TipElemenata> &m,int n) {
        auto rez = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        try {
            for(int i=0;i<rez.br_redova;i++)
                for(int j=0;j<rez.br_kolona;j++)
                    rez.elementi[i][j] = m.elementi[i][j] * n;
        }
        catch(...) {
            UnistiMatricu(rez);
            throw;
        }
        return rez;
    }

    // MATRICNI POLINOM
template<typename TipElemenata,typename iterTip>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, iterTip koef) {
        if(n<0) throw std::domain_error("Neispravan stepen polinoma");
        if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
        
        auto it=koef;                                                           // KOEFICIJENTI
        auto rezultat = StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);   // Rezultat polinoma
           
            // Jedinicna matrica ( nulti stepen polinoma )
        try {  
            for(int i=0;i<rezultat.br_redova;i++) {
                for(int j=0;j<rezultat.br_kolona;j++)
                    if(i==j)
                        rezultat.elementi[i][j] = *it * 1;  // Odmah mnozim jedinicnu matricu sa prvim koeficijentom
                    else
                        rezultat.elementi[i][j] = 0;
            }
        }
        catch(...) {
            UnistiMatricu(rezultat);
            throw;
        }
       
        // Tvrda kopija matrice A u pomocnu matricu
        
        Matrica<TipElemenata> pomocna;
        Matrica<TipElemenata> prethodnaPomocna;  // Nakon svake dodjele,moram izbrisati prethodnu verziju...
        Matrica<TipElemenata> prethodniRezultat;    //  ...da ne bi doslo do curenja memorije
        
        // Sabiranje clanova polinoma
        
        it++;                                   // iskoristio sam prvi koef za slobodan clan (jedinicnu matricu)
        try {
            for(int k=1;k<=n;k++) {
                pomocna = Iskopiraj<TipElemenata>(A); prethodnaPomocna = pomocna;
                for(int j=1;j<k;j++) {
                    pomocna = ProduktMatrica<TipElemenata>(pomocna,A); // A^
                    UnistiMatricu<TipElemenata>(prethodnaPomocna);
                    prethodnaPomocna = pomocna;
                }
                pomocna = pomnoziSkalarom<TipElemenata>(pomocna,*it);  // Pk * A^k
                UnistiMatricu<TipElemenata>(prethodnaPomocna);
                prethodnaPomocna = pomocna;
                prethodniRezultat = rezultat;
                rezultat = ZbirMatrica<TipElemenata>(rezultat,pomocna);                  // Novi rezultat
                UnistiMatricu<TipElemenata>(prethodniRezultat); UnistiMatricu<TipElemenata>(prethodnaPomocna); 
                it++;
            }
        }
        catch(...) {
            UnistiMatricu(prethodnaPomocna);
            UnistiMatricu(prethodniRezultat);
            UnistiMatricu(rezultat);
            throw;
        }
        return rezultat;    // rezultat polinoma
    }

int main() {
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    auto A = StvoriMatricu<int>(n,n);
    try {
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A', A);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        vector<int> koef(red+1);
        for(int i=0;i<red+1;i++)
            std::cin>>koef.at(i);
        auto rezPolinoma = MatricniPolinom<int>(A,red,koef.begin());
        IspisiMatricu<int>(rezPolinoma,10,6);
        UnistiMatricu<int>(rezPolinoma);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    UnistiMatricu<int>(A);
    return 0;
}
