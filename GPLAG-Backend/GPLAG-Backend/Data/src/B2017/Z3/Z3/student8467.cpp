/B2017/2018: Zadaća 3, Zadatak 3
//RAZMISLI O UNOSU! 
//Postoji mogućnost da nestane memorije, razmisli o tome

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <new>

template <typename Tip>
struct Matrica{
    int br_redova, br_kolona;
    Tip **elementi = nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> &mat){
    if(!mat.elementi) return; //U slucaju double delete-a
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<Tip> mat;
    mat.br_redova = br_redova; 
    mat.br_kolona = br_kolona;
    
    try {
        mat.elementi = new Tip*[br_redova]; //Stvara niz pokazivača na dereferenciranom pokazivacu, poslije taj niz popunjava sa drugim nizovima
        for(int i = 0; i < br_redova; i++)  mat.elementi[i] = nullptr; // Inicijalizacija pokazivača, radi sigurnosti(double delete)
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    
    try {
        for(int i = 0; i < br_redova; i++)  mat.elementi[i] = new Tip[br_kolona]{};
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename Tip>
void UnesiMatricu(char ime_matrice, Matrica<Tip> &mat){
    for(int i = 0; i < mat.br_kolona; i++){
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << ime_matrice <<"(" << (i + 1) << "," << (j + 1) << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename Tip>
void IspisiMatricu(Matrica<Tip> &mat, int sirina, int preciznost = 6, bool treba_brisati = false){
    
    for(int i = 0; i < mat.br_kolona; i++){
        for(int j = 0; j < mat.br_redova; j++){
            std::cout << std::setprecision(preciznost) << std::setw(sirina) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
    
}

template <typename Tip, typename Tip1>
auto ZbirMatrica(const Matrica<Tip> &mat1, const Matrica<Tip1> &mat2) -> Matrica<decltype(**mat1.elementi + **mat2.elementi)>{
    if(mat1.br_kolona != mat2.br_kolona || mat1.br_redova != mat2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije");
    
    auto mat3(StvoriMatricu<decltype(**mat1.elementi + **mat2.elementi)>(mat1.br_redova, mat1.br_kolona));
    
    for(int i = 0; i < mat1.br_redova; i++){
        for(int j = 0; j < mat1.br_kolona; j++){
            mat3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
            //std::cout << mat3.elementi[i][j];
        }
    }
    
    return mat3;
}

template <typename Tip, typename Mnozitelj>
void Skalarno(Matrica<Tip> &mat, Mnozitelj broj){
    for(int i = 0; i < mat.br_redova; i++){
        for(int j = 0; j < mat.br_redova; j++){
            mat.elementi[i][j] = mat.elementi[i][j] * broj; //Manipulira matricu tako što množi svaki element sa nekim skalarom
        }
    }
}

template <typename Tip>
bool DaLiJeDealocirana(Matrica<Tip> mat){ // 1-Jeste dealocirana, 0-nije dealocirana
    return (!mat.elementi);
}

template <typename Tip, typename Tip1>
void PrekopirajMatrice(Matrica<Tip> &mat1, Matrica<Tip1> &mat2, bool da_li_brisati = false){
    for(int i = 0; i < mat1.br_redova; i++){
        for(int j = 0; j < mat1.br_kolona; j++){
            mat2.elementi[i][j] = mat1.elementi[i][j];
        }
    }
    if(da_li_brisati){
        UnistiMatricu(mat1);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
template <typename Tip, typename Tip1>
auto ProduktMatrica(const Matrica<Tip> &mat1, const Matrica<Tip1> &mat2) -> Matrica<decltype(**mat1.elementi * **mat2.elementi)>{
    if(mat1.br_kolona != mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<Tip> rezultat(StvoriMatricu<decltype(**mat1.elementi * **mat2.elementi)>(mat1.br_redova, mat2.br_kolona));
    
    for(int i = 0; i < mat1.br_redova; ++i){
        for(int j = 0; j < mat2.br_kolona; ++j){
            for(int k = 0; k < mat1.br_kolona; ++k){
                rezultat.elementi[i][j] += mat1.elementi[i][k] * mat2.elementi[k][j];
            }
        }
    }
    return rezultat;
}

template <typename Tip>
Matrica<Tip> Stepen(const Matrica<Tip> &mat, int stepen){
    //if(stepen < 0) return;
    Matrica<Tip> vrati(StvoriMatricu<decltype(**mat.elementi * **mat.elementi)>(mat.br_redova, mat.br_redova));
    //Stvaranje jedinične matrice(Moglo bi sa funkcijom)
    for(int i = 0; i < vrati.br_kolona; i++){
        for(int j = 0; j < vrati.br_redova; j++){
            if(i == j) vrati.elementi[i][j] = (Tip)1;
        }
    }
    //Proces samomnoženja, korištena je funkcija za kopiranje radi plitkog brisanja
    for(int i = 0; i < stepen; i++){
        Matrica<Tip> temp(ProduktMatrica(vrati, mat));
        PrekopirajMatrice(temp, vrati, true);
        //UnistiMatricu(temp); Brisanje je riješeno funkcijom za kopiranje
    }
    //Vraćanje izmanipulirane dinamički alocirane matrice, početna matrica ostaje ista!
    return vrati;
}

template <typename Tip, typename IterTip>
auto MatricniPolinom(Matrica<Tip> &mat, int n, IterTip it)-> Matrica<decltype(**mat.elementi * (*it))>{
    // n - stepen polinoma, it - pokazivač na koeficiente
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_kolona != mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto vrati(StvoriMatricu<decltype(**mat.elementi * (*it))>(mat.br_redova, mat.br_redova));
    //Postavi vrati na 0;
    for(int i = 0; i < vrati.br_kolona; i++){
        for(int j = 0; j < vrati.br_redova; j++){
            vrati.elementi[i][j] = (Tip)0;
        }
    }
    
    for(int i = 0; i < n; i++){
        auto clan(Stepen(mat,i));
        Skalarno(clan,*it);
        
        //std::cout << "Skalarno: ";
        //std::cout << "Izmnozeni stepen: " << std::endl;
        //IspisiMatricu(clan);
        //std::cout << std::endl;
        
        auto zbir(ZbirMatrica(vrati, clan));
        
        //std::cout << "Zbir: " << zbir.elementi[0][0] << std::endl;
        //std::cout << "Zbir stepena i vrati: " << std::endl;
        //IspisiMatricu(zbir);
        
        PrekopirajMatrice(zbir, vrati, true);
        
        //std::cout << "Vrati: " << vrati.elementi[0][0] << std::endl;
        //IspisiMatricu(vrati);
        //std::cout << std::endl;
        it++;
        UnistiMatricu(clan);
    }
    //IspisiMatricu(vrati);
    return vrati;
}


int main (){
    
    try {
        int dim;
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        std::cin >> dim;
        
        auto a = StvoriMatricu<double>(dim, dim);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        
        std::vector<int> v(red + 1);
        std::for_each(v.begin(), v.end(), [](int &x){ std::cin >> x;});
        
        auto stepen(MatricniPolinom(a, red + 1, v.begin()));
        IspisiMatricu(stepen, 10, 6, true);
        UnistiMatricu(a);
        
	
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
   
	return 0;
}
