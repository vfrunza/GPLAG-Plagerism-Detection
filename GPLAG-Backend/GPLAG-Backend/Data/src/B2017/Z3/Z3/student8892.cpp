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
    if(!mat.elementi)return;
    for(int i = 0; i <mat.br_redova; i++) delete[] mat.elementi[i];
    
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; 
    mat.br_kolona = br_kolona;
    
    try{
        mat.elementi = new TipElemenata *[br_redova];
        
    }
    catch(...){
        delete[] mat.elementi;
        mat.elementi = nullptr;
        throw;
    }
    for(int i = 0; i < br_redova; i++)mat.elementi[i] = nullptr;
    try{
        for(int i = 0; i <br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }

    return mat;
}

template<typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i = 0; i <mat.br_redova; i++){
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i + 1<< "," << j + 1<< ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i = 0; i < mat.br_redova; i++){
        for(int j = 0; j <mat.br_kolona; j++){
            std::cout<<std::setw(sirina_ispisa)<< std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati == true){
      UnistiMatricu(mat);
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++){
        for(int j = 0; j <m1.br_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova ) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    
    for(int i = 0; i < m1.br_redova; i++){
        for(int j = 0; j < m2.br_kolona; j++){
            TipElemenata suma = 0;
            for(int k = 0; k < m2.br_redova; k++){
                suma = suma + m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template<typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &A, int n, Tip na_koeficijente){
    if(n < 0)throw std::domain_error("Neispravan stepen polinoma");
    
    Matrica<TipElemenata> konacna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    auto jedinicna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    for(int i = 0; i < jedinicna.br_redova; i++){
        for(int j = 0; j < jedinicna.br_kolona; j++){
            if(i == j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }
    int brojac = 0;
    for(auto it = na_koeficijente; it != (na_koeficijente + n + 1); it++){
        
        if(brojac == 0){
            for(int i = 0; i < konacna.br_redova; i++){
                for(int j = 0; j < konacna.br_kolona; j++){
                    konacna.elementi[i][j] = *it * jedinicna.elementi[i][j];
                }
            }
        }
        else{
            //auto pomocna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
            auto  pomocna = ProduktMatrica(jedinicna, A);
            for(int i = 0; i < konacna.br_redova; i++){
                for(int j = 0; j < konacna.br_kolona; j++){
                    konacna.elementi[i][j] += *it * pomocna.elementi[i][j];
                }
            }
            for(int i = 0; i < pomocna.br_redova; i++){
                for(int j = 0; j < pomocna.br_kolona; j++){
                    jedinicna.elementi[i][j] = pomocna.elementi[i][j];
                }
            }
            UnistiMatricu(pomocna);
        }
        brojac++;
    }
    UnistiMatricu(jedinicna);
    return konacna;
}

int main(){
    std::cout <<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;
    Matrica<double> A ;
    try{
        A = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout <<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',A);
        std::cout <<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>> red_polinoma;
        std::cout <<"Unesite koeficijente polinoma: ";
        std::vector<double> vektor_polinoma;

        for(int i = 0; i <= red_polinoma; i++){
           double element;
            std::cin>> element;
            vektor_polinoma.push_back(element);
        }
        auto p = std::begin(vektor_polinoma);
        Matrica <double> za_ispis;
        za_ispis = MatricniPolinom(A, red_polinoma, p);
        IspisiMatricu(za_ispis, 10, 6, true );
        
        UnistiMatricu(A);
       // UnistiMatricu(za_ispis);
    }
    catch(std::bad_alloc){
        std::cout <<"Problemi sa memorijom!"<<std::endl;
        UnistiMatricu(A);
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    
    return 0;
}