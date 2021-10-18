#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::setw;
using std::setprecision;
using std::bad_alloc;
using std::vector;

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
     mat.br_redova = br_redova; 
     mat.br_kolona = br_kolona;
     
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
            cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            cin >> mat.elementi[i][j];
        }
    }
    
    
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    
   
    
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            cout << setw(sirina_ispisa) <<setprecision(preciznost)<< mat.elementi[i][j];
            cout << endl;
    }
    
     if(treba_brisati)UnistiMatricu(mat);
}
 

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw domain_error("Matrice nemaju jednake dimenzije!");
   
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            
            
    return m3;
}

template <typename TipElemenata>

Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    
    if(m1.br_kolona != m2.br_redova)throw domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
        }
    }
    
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            for(int k=0; k<m1.br_kolona; k++){
                m3.elementi[i][j] = m3.elementi[i][j] + m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, vector<double> p){
    if(a.br_kolona!=a.br_redova)throw domain_error("Matrica mora biti kvadratna");
    
    int br_redovaA = a.br_redova;
    int br_kolonaA = a.br_kolona;
    
    
    
    
    int n = p.size();
    Matrica<TipElemenata> polinom = StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
    for(int i=0; i<br_redovaA; i++){
               for(int j=0; j<br_kolonaA; j++){
                   polinom.elementi[i][j]=0;
                   
               }
    }
    
    for(int k=0; k<n; k++){
        
        if(k==0){
            
           auto  jedinicna = StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
           
           for(int i=0; i<br_redovaA; i++){
               for(int j=0; j<br_kolonaA; j++){
                   if(i==j)jedinicna.elementi[i][j]=1;
                   else jedinicna.elementi[i][j]=0;
               }
               
            }
            
            //mnozenje jedinicne sa p
            
            for(int i=0; i<br_redovaA; i++){
                for(int j=0; j<br_kolonaA; j++){
                    jedinicna.elementi[i][j]=jedinicna.elementi[i][j]*p[k];
                }
            }
            
            //dodavanje jedinicne u polinom
            for(int i=0; i<br_redovaA; i++){
                for(int j=0; j<br_kolonaA; j++){
                    polinom.elementi[i][j] = polinom.elementi[i][j]+jedinicna.elementi[i][j];
                }
            }
            
            UnistiMatricu(jedinicna);
        
        }
         
    else{    
        Matrica<TipElemenata> m = StvoriMatricu<TipElemenata>(br_redovaA,br_kolonaA);
    //ubaci u m, ona mi je zamjena za a
    
    for(int i =0; i<br_redovaA; i++){
        for(int j=0; j<br_kolonaA; j++){
            m.elementi[i][j]=a.elementi[i][j];
        }
    }
        //racunanje matrice na stepen
        for(int l=1; l<k; l++){
            auto n = m;
            m = ProduktMatrica(m,a);
            UnistiMatricu(n);
        }
        
        
        //mnozenje matrice na stepen sa pk
        
        for(int i=0; i<br_redovaA; i++){
            for(int j=0; j<br_kolonaA; j++){
                m.elementi[i][j]=m.elementi[i][j]*p[k];
            }
        }
        
        //dodavanje matrice na stepen u polinom
        for(int i=0; i<br_redovaA; i++){
            for(int j=0; j<br_kolonaA; j++){
                polinom.elementi[i][j]=polinom.elementi[i][j]+m.elementi[i][j];
            }
        }
        
        UnistiMatricu(m);
    }
    }
    
    return polinom;
    
    
}

int main() {
    try{
         cout<<"Unesite dimenziju kvadratne matrice: ";
         int n;
         cin>>n;
         
         Matrica<double> a;
         
         a = StvoriMatricu<double>(n,n);
         cout<<"Unesite elemente matrice A: "<<endl;
         UnesiMatricu('A',a);
         
         
         cout<<"Unesite red polinoma: ";
         int k;
         cin>>k;
         
         cout<<"Unesite koeficijente polinoma: ";
         vector<double> p;
         
         for(int i=0; i<=k; i++){
             int broj;
             cin>>broj;
             p.push_back(broj);
         }
         
         Matrica<double> polinom;
         IspisiMatricu(polinom = MatricniPolinom(a,p),10);
         
         UnistiMatricu(polinom);
         UnistiMatricu(a);
    }
    
    catch(bad_alloc){
        cout<<"Nema dovoljno memorije: ";
    }
    catch(domain_error i){
        cout<<i.what();
    }
     
     return 0;
}