#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>


template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i(0); i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int broj_redova, int broj_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = broj_redova; mat.br_kolona = broj_kolona;
    try{
    mat.elementi = new TipElemenata*[broj_redova];
    for(int i(0); i < broj_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i(0); i < broj_redova; i++){
            mat.elementi[i] = new TipElemenata[broj_kolona];
        }
    }catch(...){
        UnistiMatricu<TipElemenata>(mat);
        throw;
    }
    }catch(...){
        delete mat.elementi;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0); i < mat.br_redova; i++){
        for(int j(0); j < mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1<< "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i(0); i < mat.br_redova; i++){
        for(int j(0); j < mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    
    if(treba_brisati){
     UnistiMatricu<TipElemenata>(mat);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i(0); i < m1.br_redova; i++)
            for(int j(0); j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
                return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> Nova;
    try{
    Nova = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    }catch(...){
        throw;
    }
    
    TipElemenata Suma{};
    
    for(int i(0); i < m1.br_redova; i++){
        for(int j(0); j < m2.br_kolona; j++){
            for(int k(0); k < m1.br_kolona; k++){
                Suma += m1.elementi[i][k] * m2.elementi[k][j];
            }
            Nova.elementi[i][j] = Suma;
            Suma = 0;
        }
    }
    return Nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> VratiJedinicnu(int dimenzija){
    
    Matrica<TipElemenata> VratiMe;
    try{
        VratiMe = StvoriMatricu<TipElemenata>(dimenzija, dimenzija);
        
        for(int i(0); i < dimenzija; i++){
            for(int j(0); j < dimenzija; j++){
                if(i == j) VratiMe.elementi[i][j] = 1;
                else VratiMe.elementi[i][j] = 0;
            }
        }
        
    }catch(...){
        throw;
    }
    return VratiMe;
}
template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom(Matrica<TipElemenata> &m, double x){
    
    for(int i(0); i < m.br_redova; i++)
        for(int j(0); j < m.br_kolona; j++)
            m.elementi[i][j] *= x;
            
            return m;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, std::vector<double> v){
    
    if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> Suma;
    try{
    Suma = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    }catch(...){
        throw;
    }
        
    for(int i(0); i < Suma.br_redova; i++)
        for(int j(0); j < Suma.br_kolona; j++)
            Suma.elementi[i][j] = 0;
            
            
    std::vector<Matrica<TipElemenata>> Vektor(v.size() +1);
    
    for(int i(0); i < Vektor.size(); i++){
        if(i == 0) Vektor[i] = VratiJedinicnu<TipElemenata>(m.br_redova);
        else Vektor[i] = ProduktMatrica<TipElemenata>(Vektor[i-1], m);
    }
    int indeks(0);
    for(int i(0); i < v.size(); i++){
        Matrica<TipElemenata> Novo = Suma;
        Suma = ZbirMatrica<TipElemenata>(Novo, PomnoziSaSkalarom<TipElemenata>(Vektor[indeks++], v[i]));
        UnistiMatricu<TipElemenata>(Novo);
    }
    
    for(int i(0); i < Vektor.size(); i++)
        UnistiMatricu<TipElemenata>(Vektor[i]);
    
    return Suma;
}


int main(){
    Matrica<double> a, b, c;
    int dimenzija;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    try{
        a = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        
        for(int i(0); i <= red; i++){
            double K;
            std::cin >> K;
            koeficijenti.push_back(K);
        }
        
        Matrica<double> s = MatricniPolinom(a, koeficijenti);
        IspisiMatricu(s , 10 , 6);
        UnistiMatricu<double>(s);
        UnistiMatricu<double>(a);
      
    }catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n" << std::endl;
    }
        
    return 0;
}