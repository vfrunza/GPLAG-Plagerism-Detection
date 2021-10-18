/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;


template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};


template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {

    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;

    
}

template<typename Tip>
void inicijalizuj(Matrica<Tip> &matrica){
    
    for(int i = 0 ; i < matrica.br_redova ; i++){
        for(int j = 0 ; j < matrica.br_kolona ; j++){
            matrica.elementi[i][j] = 0;
        }
    }
    
}


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


template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }


template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {

    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa)<< std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    
    if(treba_brisati){
        UnistiMatricu(mat);
    }

}


template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m3;
}
 
template<typename Tip>
Matrica<Tip> ProduktMatrica(Matrica<Tip> &matrica_1 , Matrica<Tip> &matrica_2){
    
    Matrica<Tip> matrica_3 = StvoriMatricu<Tip>(matrica_1.br_redova , matrica_2.br_kolona);
    inicijalizuj(matrica_3);
    
    if(matrica_2.br_redova == matrica_1.br_kolona){
        for(int i = 0 ; i < matrica_1.br_redova ; i++){
            for(int j = 0 ; j < matrica_2.br_kolona ; j++){
                
                double zbir = 0;
                for(int m = 0 ; m < matrica_2.br_redova ; m++){
                    zbir = zbir + matrica_1.elementi[i][m] * matrica_2.elementi[m][j];
                }
                matrica_3.elementi[i][j] = zbir;
                
            }
        }
    }
    else{
        UnistiMatricu(matrica_3);
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    
    return matrica_3;
}

template<typename Tip>
void PomnoziSaBrojem(Matrica<Tip> &matrica , double broj){

    for(int i = 0 ; i < matrica.br_redova ; i++){
        for(int j = 0 ; j < matrica.br_kolona ; j++){
            matrica.elementi[i][j] = matrica.elementi[i][j] * broj;
        }
    }
}

template<typename Tip>
void Kopiraj(Matrica<Tip> &matrica_1 , Matrica<Tip> &matrica_2){
    
    for(int i = 0 ; i < matrica_1.br_redova ; i++){
        for(int j = 0 ; j < matrica_1.br_kolona ; j++){
            
            matrica_1.elementi[i][j] = matrica_2.elementi[i][j];
            
        }
    }
    
}

template<typename Tip>
void Saberi(Matrica<Tip> &matrica_1 , Matrica<Tip> &matrica_2){
    
    for(int i = 0 ; i < matrica_1.br_redova ; i++){
        for(int j = 0 ; j < matrica_1.br_kolona ; j++){
            
            matrica_1.elementi[i][j] = matrica_1.elementi[i][j] + matrica_2.elementi[i][j];
            
        }
    }
    
}

template<typename Tip>
Matrica<Tip> MatricniPolinom(Matrica<Tip> &matrica, vector<double> brojevi){
    Matrica<Tip> rez = StvoriMatricu<Tip>(matrica.br_redova , matrica.br_kolona);
    inicijalizuj(rez);
    
    
    //IspisiMatricu(rez , 5 , 20);
    for(int i = 0 ; i < brojevi.size() ; i++){

        Matrica<Tip> pomocna(StvoriMatricu<Tip>(matrica.br_redova, matrica.br_kolona));
        //inicijalizuj(pomocna);
        
        if(i == 0){
            
            for(int m = 0 ; m < pomocna.br_redova ; m++){
                for(int j = 0 ; j < pomocna.br_kolona ; j++){
                    
                    if(m == j){
                        pomocna.elementi[m][j] = 1;
                    }
                    else{
                        pomocna.elementi[m][j] = 0;
                    }
                }
            }
        }
        else{
            //pomocna = matrica;
            Kopiraj(pomocna, matrica);
        }
        
        for(int j = 0 ; j < i - 1 ; j++){
            Matrica<Tip> privremena(StvoriMatricu<Tip>(pomocna.br_redova , pomocna.br_kolona));
            //inicijalizuj(privremena);
            Kopiraj(privremena, pomocna);
            //UnistiMatricu(pomocna);
           // cout << "Unisti pomocnu" << endl;
            Matrica<Tip> prod(ProduktMatrica(matrica, privremena));
            Kopiraj(pomocna, prod);
            //pomocna = ProduktMatrica(matrica , privremena);
            //Kopiraj(pomocna, ProduktMatrica(matrica, privremena));
            //pomocna = ProduktMatrica(matrica, pomocna);
            UnistiMatricu(privremena);
            UnistiMatricu(prod);
        }

        Matrica<Tip> produkt(StvoriMatricu<Tip>(pomocna.br_redova , pomocna.br_kolona));
        inicijalizuj(produkt);
        
        Kopiraj(produkt , pomocna);
        
        PomnoziSaBrojem(produkt, brojevi[i]);
        
        Saberi(rez, produkt);
        
        
      
        UnistiMatricu(pomocna);
        UnistiMatricu(produkt);
        
        //return rez;
        
    }

    return rez;
}
 
int main(){

    cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    cin >> dimenzija;
    Matrica<double> matrica = StvoriMatricu<double>(dimenzija, dimenzija);
    cout << "Unesite elemente matrice A:" << endl;
    UnesiMatricu('A' , matrica);
    cout << "Unesite red polinoma: ";
    int red_polinoma;
    cin >> red_polinoma;
    cout << "Unesite koeficijente polinoma: ";
    vector<double> v;
    for(int i = 0 ; i <= red_polinoma ; i++){
        int b;
        cin >> b;
        v.push_back(b);
    }
    Matrica<double> rez = MatricniPolinom(matrica, v);
    IspisiMatricu(rez, 10, 6);
    UnistiMatricu(rez);
    UnistiMatricu(matrica);
    

  
    return 0;
}