#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <iomanip>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
            delete[] mat.elementi;
    mat.elementi = nullptr;
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
                std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
            std::cout<<std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
        }
        if(treba_brisati==true){UnistiMatricu(mat);}
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(Matrica<TipElemenata> m1,Matrica<TipElemenata> m2) {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
template<typename TIP>    
    bool MoguSeMnoziti(Matrica<TIP> mat1, Matrica<TIP> mat2){
        return mat1.br_kolona == mat2.br_redova;
    }    
template<typename TIP>
    Matrica<TIP> ProduktMatrica(Matrica<TIP> mat1, Matrica<TIP> mat2){
        if((MoguSeMnoziti(mat1, mat2))==0) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica<TIP> mat3(StvoriMatricu<TIP>(mat1.br_redova, mat2.br_kolona));
        for(int i=0;i<mat1.br_redova;i++){
            for(int j=0;j<mat2.br_kolona;j++){
                double suma(0);
                for(int k=0; k<mat2.br_redova; k++) suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
                mat3.elementi[i][j]=suma;
            }
        }
        return mat3;
    }
template<typename TIP>    
    Matrica<TIP> NulaMatrica(TIP broj){
        Matrica<TIP> mat{StvoriMatricu<TIP>(broj,broj)};
        TIP nula=0;
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                mat.elementi[i][j]=nula;
            }
        }
        return mat;
    } 
Matrica<int> Jedinicna(int broj){
    Matrica<int> mat{StvoriMatricu<int>(broj,broj)};
    for(int i=0; i<broj;i++){
        for(int j=0;j<broj; j++){
            if(i==j) mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }
    return mat;
}
template<typename TIP>
    Matrica<TIP> MnozenjeSkalarom(Matrica<TIP> mat, TIP skalar){
        Matrica<TIP> pomnozena{StvoriMatricu<TIP>(mat.br_redova,mat.br_redova)};
        pomnozena=mat;
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_redova;j++){
                pomnozena.elementi[i][j]=pomnozena.elementi[i][j]*skalar;
            }
        }
        return pomnozena;
    }
template<typename TIP>
    Matrica<TIP> MatricniPolinom(Matrica<TIP> mat, std::vector<TIP> vek){
        if(mat.br_kolona!=mat.br_redova)  throw std::domain_error("Matrica mora biti kvadratna");
        if(vek.size()==0){
            Matrica<TIP> nula{StvoriMatricu<TIP>(mat.br_kolona, mat.br_redova)};
            nula = NulaMatrica(mat.br_kolona);
            return nula;
        }
        Matrica<TIP> rez{StvoriMatricu<TIP>(mat.br_kolona, mat.br_redova)};
        Matrica<TIP> kvadrat{StvoriMatricu<TIP>(mat.br_kolona, mat.br_redova)};
        kvadrat = mat;
        for(int k=0;k<vek.size();k++){
            
            if(k==0){
                Matrica<TIP> jedan{StvoriMatricu<TIP>(mat.br_kolona, mat.br_redova)};
                jedan = Jedinicna(mat.br_kolona);
                rez = MnozenjeSkalarom(jedan, vek[0]);
                continue;
            }
            if(k==1){
                Matrica<TIP> kopija{StvoriMatricu<TIP>(mat.br_kolona, mat.br_redova)};
                kopija = mat;
                kopija = ZbirMatrica(rez, MnozenjeSkalarom(kopija, vek[1]));
                rez = kopija;
                continue;
            }
            kvadrat = ProduktMatrica(kvadrat, mat);
            rez = ZbirMatrica(rez, MnozenjeSkalarom(kvadrat, vek[k]));
        }
        return rez;
    }
int main() {
    Matrica<int> a,c;       // AUTOMATSKA INICIJALIZACIJA!!!        3 1 0 -2 3 -2 0 1
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice:\n";
    std::cin >> n;
    try {
        a = StvoriMatricu<int>(n, n);
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma:\n";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma:\n";
        std::vector<int> koef;
        for(int i=0;i<red+1;i++){
            int broj;
            std::cin>>broj;
            koef.push_back(broj);
        }
        try{
            IspisiMatricu(c = MatricniPolinom<int>(a, koef), 6);
        }catch(std::domain_error izu){
            std::cout<<izu.what();
            UnistiMatricu(a); UnistiMatricu(c);
        }
        }catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(c);
    return 0;
}    