/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <iterator>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat){
        if(!mat.elementi) return;
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try{
            for(int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for(int i = 0; i < mat.br_redova; i++)
            for(int j = 0; j < mat.br_kolona; j++){
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati)UnistiMatricu(mat);
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_kolona!=m2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje"); //ako su nesaglasne za mnozenje
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++)  
            for(int j=0; j<m2.br_kolona; j++){
                TipElemenata suma(0); // ne treba nula ja msm vec nesto skontat
                for(int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k] * m2.elementi[k][j];
                m3.elementi[i][j]=suma;
            }
        return m3;
    }
    
template <typename TipElemenata>
    void MnozenjeSkalarom (Matrica<TipElemenata> &m, TipElemenata skalar){
        for(int i=0; i<m.br_redova; i++){
            for(int j=0; j<m.br_kolona; j++){
                m.elementi[i][j]*=skalar;
            }
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> A, int n, std::vector<double>::iterator it){
        if(n<0)throw std::domain_error("Neispravan stepen polinoma");
        if(A.br_redova!=A.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
        
        auto rjesenje(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
        for(int i=0; i<rjesenje.br_redova; i++){ // postavim na startu na nulu sve
            for(int j=0; j<rjesenje.br_kolona; j++){
                rjesenje.elementi[i][j]=0; // da li je ovo dobro posto proizvoljnog tipa treba bit
            }
        }
        //std::cout << "\nRjesenje:\n";
        //IspisiMatricu(rjesenje, 10);
        auto stepen_matrice(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
        for(int i=0; i<stepen_matrice.br_redova; i++){
            for(int j=0; j<stepen_matrice.br_kolona; j++){//postavim na jedinicnu matricu
                if(i==j)stepen_matrice.elementi[i][j]=1;
                else stepen_matrice.elementi[i][j]=0;
            }
        }
        
        
        for(int i=0; i<=n; i++){
            if(i!=0){
                auto pomocna(ProduktMatrica(stepen_matrice, A));
                UnistiMatricu(stepen_matrice);
                stepen_matrice=pomocna;
                pomocna.elementi=nullptr;
            }
            //std::cout << "\nStepen Matrice:\n";
            //IspisiMatricu(stepen_matrice, 10);
            auto sabirak(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
            for(int x=0; x<sabirak.br_redova; x++){
                for(int y=0; y<sabirak.br_kolona; y++){
                    sabirak.elementi[x][y]=stepen_matrice.elementi[x][y];
                }
            }
            //std::cout << "\nSabirak prije:\n";
            //IspisiMatricu(sabirak, 10);
            MnozenjeSkalarom(sabirak, *it++);
            //std::cout << "\nSabirak poslije:\n";
            //IspisiMatricu(sabirak, 10);
            auto pomocna(ZbirMatrica(rjesenje, sabirak));
            UnistiMatricu(rjesenje);
            UnistiMatricu(sabirak);
            rjesenje=pomocna;
            pomocna.elementi=nullptr;
            //std::cout << "\novaj korak:\n";
            //IspisiMatricu(rjesenje, 10);
        }
        UnistiMatricu(stepen_matrice);
        return rjesenje;
    }

int main ()
{
    Matrica<double> a, b;// c;
    int n, dim;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dim;
    try {
        a = StvoriMatricu<double>(dim, dim);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti(n+1);
        for(int i=0; i<=n; i++){
            std::cin >> koeficijenti[i];
        }
        b = MatricniPolinom(a, n, koeficijenti.begin());
        IspisiMatricu(b, 10);
    }
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b); //UnistiMatricu(c);
	return 0;
}
