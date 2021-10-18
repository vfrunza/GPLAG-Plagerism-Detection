/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector> 
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
            std::cin.ignore(10000, '\n');
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
        
        if(treba_brisati) UnistiMatricu(mat);
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        //UnistiMatricu(m1);
        //UnistiMatricu(m2);
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    return m3;
    //UnistiMatricu(m3);
}

template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica ( Matrica <TipElemenata> &m1, Matrica <TipElemenata> &m2){
    
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std:: domain_error ("Matrice nisu saglasne za mnozenje");
    //UnistiMatricu(m1);
    //UnistiMatricu(m2);
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i(0); i<m1.br_redova; i++){
        for(int j(0); j<m2.br_kolona; j++){
            for(int k(0); k<m1.br_kolona; k++){
                m3.elementi[i][j]+=m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
   // UnistiMatricu(m1);
   // UnistiMatricu(m2);
    return m3;
    
}

template <typename TipElemenata> 
void PrebaciVrijednost (Matrica<TipElemenata> &naKoju, Matrica<TipElemenata> &saKoje){
    for (int i(0); i<saKoje.br_redova; i++) 
        for (int j(0); j<saKoje.br_kolona; j++) {
            naKoju.elementi[i][j]=saKoje.elementi[i][j];
        }
        
}

template <typename TipElemenata>
Matrica<TipElemenata> Stepen (Matrica<TipElemenata> &mat, int stepen){
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    PrebaciVrijednost(m, mat);
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona; j++){
            
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
            
        }
    }
    if(stepen==0) { 
        UnistiMatricu(m);
        return jedinicna;
        
    }   
    else if (stepen == 1) {
        UnistiMatricu(jedinicna);
        UnistiMatricu(m);
        return mat;
    }
        else{
            for(int i(2); i<=stepen; i++){
                m=ProduktMatrica(m, mat);
            }
        }
        UnistiMatricu(jedinicna);
        
        return m;
        
}

template <typename TipElemenata, typename tip>
Matrica<TipElemenata> Produkt (Matrica<TipElemenata> &mat, tip skalar){
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona; j++){
            m.elementi[i][j]=mat.elementi[i][j]* (*skalar);
        }
    }
    return m;
}

template <typename TipElemenata, typename tip1>

Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> &A, int n, tip1 v){
    if(n<0) throw std::domain_error ("Neispravan stepen polinoma");
    
    if(A.br_redova!=A.br_kolona) 
    throw std::domain_error ("Matrica mora biti kvadratna");

    auto rezultat (StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i(0); i<A.br_redova; i++){
        for(int j(0); j<A.br_kolona; j++){
            rezultat.elementi[i][j]=0;
        }
    }
    auto m(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    auto stepenMatrica = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    auto produktMatrica = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    //Matrica <TipElemenata> produktMatrica;
    //Matrica <TipElemenata> suma;
    
    
        for(int i(0); i<A.br_redova; i++){
            for(int j(0); j<A.br_kolona; j++){
                m.elementi[i][j]=A.elementi[i][j];
            }
            
        }
        int broj(0);
        while (broj!=n+1){
        //stepenMatrica = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        stepenMatrica=Stepen(m, broj);
        //produktMatrica = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        produktMatrica=Produkt(stepenMatrica, v);
        //suma = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        rezultat=ZbirMatrica(rezultat, produktMatrica);
        //UnistiMatricu(stepenMatrica);
        //UnistiMatricu(produktMatrica);
        v++;
        broj++;
    }
    
    UnistiMatricu(stepenMatrica);
    UnistiMatricu(produktMatrica);
    //UnistiMatricu(suma);
    UnistiMatricu(m);
   return rezultat;
}

int main()
{
    Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice:\n";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
       
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
       
       int n;
       std::cout << "Unesite red polinoma: ";
       std:: cin >> n;
       
       int broj;
       std:: vector<double> v;
       std::cout << "Unesite koeficijente polinoma: ";
       for(int i(0); i<n+1; i++){
           
           std:: cin >> broj;
           v.push_back(broj);
       }
       
       IspisiMatricu(MatricniPolinom(a, n, v.begin()), 10, 5, true);
       
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    
    return 0;
}
