/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <new>
#include <iomanip>
#include <stdexcept>

template <typename TipElementa>
struct Matrica{
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

// Unistavanje matrice i viska elemenata
template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> matrica){
    // ako ne odgovara
    if(!matrica.elementi){
        return;
    }
    
    // brisanje elementa i redova
    for(int i=0; i<matrica.br_redova; i++){
        delete [] matrica.elementi[i];
    }
    
    // brisanje pokazivaca
    delete[] matrica.elementi;
    // osiguravanje
    matrica.elementi = nullptr;
}

// Kreiranje matrice
template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona){
    // inicijalizacija matrice
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElementa*[br_redova];
    
    // postavljanje svih pokazivaca na nullptr;
    for(int i=0; i<br_redova; i++){
        mat.elementi[i] = nullptr;
    }
    
    // pokusavanje alociranja svakog elementa
    try{
        for(int i=0; i<br_redova; i++){
            mat.elementi[i] = new TipElementa[br_kolona];
        }
    } catch (...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

// Ispis matrice
template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati == true){
        UnistiMatricu(mat);
    }
}

// Unos matrice
template <typename TipElementa>
void UnesitMatricu(char ime_matrice, Matrica<TipElementa> &matrica){
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> matrica.elementi[i][j];
        }
    }
}

// Proizvod skalara 1
template <typename TipElementa>
void MnozenjeSkalarom_1(Matrica<TipElementa> &matrica, double skalar){
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            matrica.elementi[i][j] = matrica.elementi[i][j] * skalar;
        }
    }
}

// Proizvod skalara 2
template <typename TipElementa>
Matrica<TipElementa> MnozenjeSkalarom_2(const Matrica<TipElementa> &matrica, double skalar){
    Matrica<TipElementa> tmp = StvoriMatricu<TipElementa>(matrica.br_redova, matrica.br_kolona);
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            tmp.elementi[i][j] = matrica.elementi[i][j] * skalar;
        }
    }
    return tmp;
}

// Zbir matrica
template <typename TipElementa>
void ZbirMatrica(Matrica<TipElementa> &matrica_1, const Matrica<TipElementa> &matrica_2){
    if(matrica_1.br_redova != matrica_2.br_redova || matrica_1.br_kolona != matrica_2.br_kolona){
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    }
    for(int i=0; i<matrica_1.br_redova; i++){
        for(int j=0; j<matrica_1.br_kolona; j++){
            matrica_1.elementi[i][j] = matrica_1.elementi[i][j] + matrica_2.elementi[i][j];
        }
    }
}

// Produkt dvije matrice
template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &matrica_1, const Matrica<TipElementa> &matrica_2){
    // Nisu saglasne za mnozenje
    if(matrica_1.br_kolona != matrica_2.br_redova){
        UnistiMatricu(matrica_1);
        UnistiMatricu(matrica_2);
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    }
    
    auto produkt = StvoriMatricu<TipElementa>(matrica_1.br_redova, matrica_1.br_kolona); // kvadratna pa mogu isti broj redova i kolona
    
    for(int i=0; i<matrica_1.br_redova; i++){
        for(int j=0; j<matrica_1.br_kolona; j++){
            produkt.elementi[i][j] = 0;
        }
    }
    
    for(int i=0; i<matrica_1.br_redova; i++){
        for(int j=0; j<matrica_1.br_kolona; j++){
            int suma = 0;
            for(int k=0; k<matrica_1.br_kolona; k++){
                suma = suma + (matrica_1.elementi[i][k] * matrica_2.elementi[k][j]); 
            }
            produkt.elementi[i][j] = suma;
        }
    }
    
    return produkt;
}

// Nula matrica
template <typename TipElementa>
void NulaMatrica (Matrica<TipElementa> &matrica){
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            matrica.elementi[i][j] = 0;
        }
    }
}

// Jedinicna
template <typename TipElementa>
void JedinicnaMatrica (Matrica<TipElementa> &matrica){
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            if(i==j){
                matrica.elementi[i][j] = 1;
            } else {
                matrica.elementi[i][j] = 0;
            }
        }
    }
}

// Matricni Polinom dvije matrice
template <typename TipElementa, typename pok_it>
Matrica<TipElementa> MatricniPolinom (const Matrica<TipElementa> &matrica, int n, pok_it slider){
    // v0
    
    // Ako broj koef. nije dobar
    if(n<0){
        UnistiMatricu(matrica);
        throw std::domain_error ("Neispravan stepen polinoma");
    }
    
    // Ako nije kvadratna matrica
    if(matrica.br_redova != matrica.br_kolona){
        UnistiMatricu(matrica);
        throw std::domain_error ("Matrica mora biti kvadratna");
    }
    
    Matrica<TipElementa> kopija_matricana_matrica = StvoriMatricu<TipElementa>(matrica.br_redova, matrica.br_kolona);
    Matrica<TipElementa> kopija_matrica = kopija_matricana_matrica;
    
    // Pretvori u nula matricu
    NulaMatrica(kopija_matricana_matrica);
    
    // Izuzetak
    if(n == 0){
        return kopija_matricana_matrica;
    }
    
    // Jedinicna
    Matrica<TipElementa> jedinicna = StvoriMatricu<TipElementa>(matrica.br_redova, matrica.br_kolona);
    JedinicnaMatrica(jedinicna);
    
    Matrica<TipElementa> mat = StvoriMatricu<TipElementa>(matrica.br_redova, matrica.br_kolona);
    // Kopiranje
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++){
            mat.elementi[i][j] = matrica.elementi[i][j];
        }
    }
    
    try{
        int brojac = 0;
        while(brojac <= n){
            if (brojac>1){
                Matrica<TipElementa> tmp1;
                Matrica<TipElementa> tmp2;
                
                // Razmjena
                tmp1 = mat;
                mat = ProduktMatrica(mat, matrica);
                tmp2 = MnozenjeSkalarom_2<TipElementa>(mat, *slider);
                
                // Saberi
                ZbirMatrica<TipElementa>(kopija_matricana_matrica, tmp2);
                
                // Brisi novonastale
                UnistiMatricu(tmp1); UnistiMatricu(tmp2);
                
            } else if (brojac == 1){
                kopija_matricana_matrica = MnozenjeSkalarom_2(matrica, *slider);
            } else if(brojac == 0){
                MnozenjeSkalarom_1(jedinicna, *slider);
            }
            
            slider++; brojac++;
        }
        
        ZbirMatrica<TipElementa>(kopija_matricana_matrica, jedinicna);
        
        // Brisanje 
        UnistiMatricu(kopija_matrica); UnistiMatricu(jedinicna); UnistiMatricu(mat);
        return kopija_matricana_matrica;
    } catch(...){
        // Brisanje
        UnistiMatricu(jedinicna); UnistiMatricu(kopija_matricana_matrica); UnistiMatricu(mat);
        throw;
    } 
}

int main (){

    // TEST
    /* int dimenzija_matrice = 2;
    
    Matrica<int> A, B, C, skalar1;
    Matrica<int> produkt;
    A = StvoriMatricu<int>(dimenzija_matrice, dimenzija_matrice);
    B = StvoriMatricu<int>(dimenzija_matrice, dimenzija_matrice);
    C = StvoriMatricu<int>(dimenzija_matrice, dimenzija_matrice);
    
    
    UnesitMatricu('A', A);
    UnesitMatricu('B', B);
    UnesitMatricu('C', C);
    
    // for(int i=0; i<dimenzija_matrice; i++){
    //     for(int j=0; j<dimenzija_matrice; j++){
    //         A.elementi[i][j] = i+1;
    //     }
    // } 
    
    IspisiMatricu(A, 10);
    std::cout << std::endl << std::endl;
    IspisiMatricu(B, 10);
    std::cout << std::endl << std::endl;
    IspisiMatricu(C, 10);
    std::cout << std::endl << std::endl;
    
    skalar1 = ProizvodSkalara(A, 2);
    IspisiMatricu(skalar1, 10);
    std::cout << std::endl << std::endl;
    
    ProizvodSkalaraa(C, 2);
    IspisiMatricu(C, 10);
    std::cout << std::endl << std::endl;
    
    ZbirMatrica(C, A);
    IspisiMatricu(C, 10);
    std::cout << std::endl << std::endl;
    
    produkt = ProduktMatrica(A, B);
    IspisiMatricu(produkt, 10);
    std::cout << std::endl << std::endl;
    
    UnistiMatricu(A);
    UnistiMatricu(B);
    UnistiMatricu(C);
    UnistiMatricu(skalar1);
    UnistiMatricu(produkt); */
    
    // MAIN
    int dimenzija_matrice;
    Matrica<int> matrica_1, matrica_2;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija_matrice;
    
    try{
        matrica_1 = StvoriMatricu<int>(dimenzija_matrice, dimenzija_matrice);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesitMatricu('A', matrica_1);
        
        int red_polinoma;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        for(int i=0; i<red_polinoma+1; i++){
            double tmp;
            std::cin >> tmp;
            koeficijenti.push_back(tmp);
        }
        auto it = koeficijenti.begin();
        matrica_2 = MatricniPolinom(matrica_1, red_polinoma, it);
        IspisiMatricu(matrica_2, 10);
    
    // paziti na izuzetke
    } catch(...){
        UnistiMatricu(matrica_1); UnistiMatricu(matrica_2);
        std::cout << "Nema dovoljno memorije" << std::endl;
    }
    
    UnistiMatricu(matrica_1); UnistiMatricu(matrica_2);
	return 0;
}