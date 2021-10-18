/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int broj_redova, broj_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> matrica){
    if(!matrica.elementi) return;
    for(int i(0); i<matrica.broj_redova; i++) delete[] matrica.elementi[i];
    delete[] matrica.elementi;
    matrica.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int broj_redova, int broj_kolona){
    Matrica<TipElemenata> matrica;
    matrica.broj_redova = broj_redova;
    matrica.broj_kolona = broj_kolona;
    matrica.elementi = new TipElemenata*[broj_redova]{};
    try {
        for(int i(0); i<broj_redova; i++)
            matrica.elementi[i] = new TipElemenata[broj_kolona];
    } catch(std::bad_alloc) {
        UnistiMatricu(matrica);
        throw;
    }
    return matrica;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0); i<mat.broj_redova; i++)
        for(int j(0); j<mat.broj_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &matrica, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i(0); i<matrica.broj_redova; i++) {
        for(int j(0); j < matrica.broj_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << matrica.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(matrica);
}

template <typename TipElemenata>
void PomnoziMatricuSkalarom(Matrica<TipElemenata> &matrica, TipElemenata x){
    for(int i(0); i<matrica.broj_redova; i++)
        for(int j(0); j<matrica.broj_kolona; j++)
            matrica.elementi[i][j]*=x;
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &matrica1, const Matrica<TipElemenata> &matrica2) {
    if(matrica1.broj_redova != matrica2.broj_redova || matrica1.broj_kolona != matrica2.broj_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto matrica3(StvoriMatricu<TipElemenata>(matrica1.broj_redova, matrica1.broj_kolona));
    for(int i(0); i<matrica1.broj_redova; i++)
        for(int j(0); j<matrica1.broj_kolona; j++)
            matrica3.elementi[i][j] = matrica1.elementi[i][j] + matrica2.elementi[i][j];
    return matrica3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> matrica1, Matrica<TipElemenata> matrica2){
    if(matrica2.broj_redova!=matrica1.broj_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> matrica(StvoriMatricu<TipElemenata>(matrica1.broj_redova, matrica2.broj_kolona));
    for(int i(0); i<matrica.broj_redova; i++){
        for(int j(0); j<matrica.broj_kolona; j++){
            TipElemenata suma(0);
            for(int k(0); k<matrica1.broj_kolona; k++){
                suma+=matrica1.elementi[i][k]*matrica2.elementi[k][j];
            }
            matrica.elementi[i][j]=suma;
        }
    }
    return matrica;
}

template <typename TipElemenata, typename ItTip>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> matrica, int n, ItTip it){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    Matrica<TipElemenata> povratna_matrica(StvoriMatricu<TipElemenata>(matrica.broj_redova, matrica.broj_kolona));
    for(int i(0); i<povratna_matrica.broj_redova; i++)
        for(int j(0); j<povratna_matrica.broj_kolona; j++) povratna_matrica.elementi[i][j]=0;
    for(int i(0); i<=n; i++){
        try{
            Matrica<TipElemenata> temp1(StvoriMatricu<TipElemenata> (matrica.broj_redova, matrica.broj_kolona)), temp2;
            try{
                for(int j(0); j<temp1.broj_redova; j++)
                    for(int k(0); k<temp1.broj_kolona; k++){
                        if(j==k) temp1.elementi[j][k]=1;
                        else temp1.elementi[j][k]=0;
                    }
                temp2=temp1;
                for(int j(1); j<=i; j++){
                    temp1=ProduktMatrica(temp2,matrica);
                    UnistiMatricu(temp2);
                    temp2=temp1;
                } 
                PomnoziMatricuSkalarom(temp1, *it);
                temp2=povratna_matrica;
                povratna_matrica=ZbirMatrica(temp2, temp1);
                UnistiMatricu(temp1); UnistiMatricu(temp2);
            }
            catch(...) {
                UnistiMatricu(temp1);
                UnistiMatricu(temp2);
                throw;
            }
        }
        catch(...){
            UnistiMatricu(povratna_matrica);
            throw;
        }
        it++;
    }
    return povratna_matrica;
    
    
}

int main()
{
    Matrica<double> a, b;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int red_polinoma;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        std::vector<double> koeficijenti(0);
        bool ispisano(false);
        for(int i(0); i<=red_polinoma; i++){
            if(!ispisano){
                 std::cout << "Unesite koeficijente polinoma: ";
                 ispisano=true;
            }
            double broj;
            std::cin >> broj;
            koeficijenti.push_back(broj);
        }
        b = MatricniPolinom(a, red_polinoma, koeficijenti.begin());
        IspisiMatricu(b, 10);
        
    } 
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}