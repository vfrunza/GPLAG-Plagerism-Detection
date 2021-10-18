/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>
#include <iomanip>


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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        
            std::cout << std::endl;
        }
        std::cout.unsetf(std::ios::floatfield);
        if(treba_brisati) UnistiMatricu(mat);
        return;
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

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2){
    
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    
    Matrica<TipElemenata> povratna;
    try{
        povratna=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
        povratna.br_redova=mat1.br_redova;
        povratna.br_kolona=mat2.br_kolona;
        
        for(int i=0; i<mat1.br_redova; i++){
            for(int j=0; j<mat2.br_kolona; j++){
                TipElemenata suma(0);
                for(int k=0; k<mat2.br_redova; k++) suma+=mat1.elementi[i][k] * mat2.elementi[k][j];
                povratna.elementi[i][j]=suma;
            }
        }
        return povratna;
        
    }
    catch(...){
       // UnistiMatricu(povratna);
        throw;
    }
}
template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, int n, Tip it){
    
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    
    Matrica<TipElemenata> povratna;
    Matrica<TipElemenata> plus;
    Matrica<TipElemenata> jedinicna;
    Matrica<TipElemenata> stepen;
    Matrica<TipElemenata> pomocna;
    //povratna
    int red=A.br_redova;
    int kolona=A.br_kolona;
    try{
        povratna.br_redova=A.br_redova;
        povratna.br_kolona=A.br_kolona;
        povratna=StvoriMatricu<TipElemenata>(povratna.br_redova, povratna.br_kolona);
    }
    catch(...){
        throw;
    }
    //plus
    try{
        plus.br_redova=A.br_redova;
        plus.br_kolona=A.br_kolona;
        plus=StvoriMatricu<TipElemenata>(plus.br_redova, plus.br_kolona);
    }
    catch(...){
        UnistiMatricu(povratna);
        throw;
    }
    //jedinicna
    try{
        jedinicna.br_redova=A.br_redova;
        jedinicna.br_kolona=A.br_kolona;
        jedinicna=StvoriMatricu<TipElemenata>(jedinicna.br_redova, jedinicna.br_kolona);
    }
    catch(...){
        UnistiMatricu(povratna);
        UnistiMatricu(plus);
        throw;
    }
    //stepen
     try{
        stepen.br_redova=A.br_redova;
        stepen.br_kolona=A.br_kolona;
        stepen=StvoriMatricu<TipElemenata>(jedinicna.br_redova, jedinicna.br_kolona);
    }
    catch(...){
        UnistiMatricu(povratna);
        UnistiMatricu(plus);
        UnistiMatricu(jedinicna);
        throw;
    }
    
    for(int i=0; i<A.br_redova; i++){
        for(int j=0; j<A.br_kolona; j++){
            povratna.elementi[i][j]=0;
            plus.elementi[i][j]=0;
            stepen.elementi[i][j]=A.elementi[i][j];
            jedinicna.elementi[i][j]=0;
        }
    }
    
    for(int i=0; i<A.br_redova; i++) jedinicna.elementi[i][i]=*it;
    
    pomocna=povratna;
    povratna=ZbirMatrica(povratna, jedinicna);
    UnistiMatricu(pomocna);
    UnistiMatricu(jedinicna);
    
    
    
        for(int i=0; i<n; i++){
            it++;
            for(int j=0; j<red; j++){
                for(int k=0; k<kolona; k++){ 
                    plus.elementi[j][k]=stepen.elementi[j][k];
                    plus.elementi[j][k]*=*it;
                    
                }
            }
            
            pomocna=stepen;
            stepen=ProduktMatrica<TipElemenata>(stepen, A);
            UnistiMatricu(pomocna);
            
            pomocna=povratna;
            povratna=ZbirMatrica<TipElemenata>(povratna, plus);
            
            UnistiMatricu(pomocna);
        }
        
        UnistiMatricu(stepen);
        UnistiMatricu(plus);
        return povratna;
          
    
    
    
}





int main ()
{
    
    
    Matrica<double> mat;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija(0);
    std::cin>>dimenzija;
    mat.br_redova=dimenzija;
    mat.br_kolona=dimenzija;
    
    
    try{
        mat=StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A', mat);
        std::cout<<"Unesite red polinoma: ";
        int n(0);
        std::cin>>n;
        std::vector<double> koef(n+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<n+1; i++) std::cin>>koef.at(i);
       
        Matrica<double> pomocna;
        try{
            pomocna=mat;
            mat=MatricniPolinom<double>(mat, n, koef.begin());
            UnistiMatricu(pomocna);
            IspisiMatricu(mat, 10, 6, true);
            
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            UnistiMatricu(pomocna);
        }
        catch(...){
            
        }
    }
    catch(...){
        
    }
 
    

	return 0;
}
