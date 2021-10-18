/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

template <typename TipEl>
struct Matrica{
    
    int redovi, kolone;
    TipEl **el = nullptr;
    
};


template<typename TipEl>
void UnistiMatricu(Matrica<TipEl> mat){
    
    if(!mat.el) return;
    
    for(int i = 0; i < mat.redovi; i++) delete[] mat.el[i];
    delete[] mat.el;
    
    mat.el = nullptr;
}

template <typename TipEl>

Matrica<TipEl> StvoriMatricu (int redovi, int kolone){
    
    Matrica<double> mat;
    
    mat.redovi = redovi;
    mat.kolone = kolone;
    
    mat.el = new TipEl*[redovi];
    
    for(int i = 0; i < redovi; i++) mat.el[i] = nullptr;
    
    try {
        
        for(int i = 0; i < redovi; i++) mat.el[i] = new TipEl[kolone];
        
    } catch(...){
        
        UnistiMatricu(mat);
        throw;
    }
    
    return mat;
}

template <typename TipEl>
void UnesiMatricu(char ime, Matrica<TipEl> &mat){
    
    for(int i = 0; i < mat.redovi; i++)
        
        for(int j = 0; j < mat.kolone; j++){
            
            cout << ime << "(" << i + 1 << "," << j + 1 << ") = ";
            cin >> mat.el[i][j];
        }
    
}

template <typename TipEl>
void IspisiMatricu(const Matrica<TipEl> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    
    for(int i = 0; i < mat.redovi; i++){
        for(int j = 0; j < mat.kolone; j++){
            
            
            cout << setw(sirina_ispisa) << setprecision(preciznost) << mat.el[i][j];
            
        }
        
        cout << endl;
    }
    
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipEl>
Matrica<TipEl> ProduktMatrica(const Matrica<TipEl> &mat1, const Matrica<TipEl> &mat2){
    
    if(mat1.kolone != mat2.redovi) throw domain_error("Matrice nisu saglasne za mnozenje");
    
    auto mat3(StvoriMatricu<TipEl>(mat1.redovi, mat2.kolone));
    
    for(int i = 0; i < mat3.redovi; i++)
        for(int j = 0; j < mat3.kolone; j++)
        {
            mat3.el[i][j]=0;
        }
        
   for(int i = 0; i < mat1.redovi; i++){
       
       for(int j = 0; j < mat2.kolone; j++){
           
           for(int k = 0; k < mat1.kolone; k++){
               
               mat3.el[i][j] += mat1.el[i][k] * mat2.el[k][j];
           }
       }
   }
   
   return mat3;
    
}

template <typename TipEl>
void Jedinicna(Matrica<TipEl> &mat){
    
    
    for(int i = 0; i < mat.redovi; i++) {
        
        for(int j = 0; j < mat.kolone; j++) {
            
            if(i == j) mat.el[i][j] = 0;
            else mat.el[i][j] = 1;
        }
    }

    
}

template <typename TipEl>
void PopuniNulama(Matrica<TipEl> &mat){
    
    
    for(int i = 0; i < mat.redovi; i++) {
        
        for(int j = 0; j < mat.kolone; j++) {
            mat.el[i][j] = 0;
        }
    }

    
}

/*void Izmnozi(Matrica<TipEl> &rez, const Matrica<TipEl> &stepe, vector<double> v, int br){
    
    
    for(int i = 0; i < rez.redovi; i++){
        for(int j = 0; j < rez.redovi; j++){
            
            
            
        }
    }
    
}
*/

template <typename TipEl>

Matrica<TipEl> MatricniPolinom(const Matrica<TipEl> &mat, vector<double> v){
    
    
    if(mat.redovi != mat.kolone) throw domain_error("Matrica mora biti kvadratna");
    
    Matrica<TipEl> MatPol(StvoriMatricu<TipEl>(mat.redovi, mat.redovi));
    PopuniNulama(MatPol);
    Matrica<TipEl> stepen(StvoriMatricu<TipEl>(mat.redovi, mat.redovi));
    
    Matrica<TipEl> jed(StvoriMatricu<TipEl>(mat.redovi, mat.redovi));
    Jedinicna(jed);
    stepen = mat;
    
    
    for(int i = 0; i < v.size(); i++) {
        
        for(int j = 0; j < mat.redovi; j++){
            
            for(int k = 0; k < mat.redovi; k++){
                
                if(i == 0){
                    
                    MatPol.el[j][k] = v[0] * jed.el[j][k];
                    
                }
                
                
                //Izmnozi(MatPol, stepen, v, i);
                
                MatPol.el[j][k] += stepen.el[j][k] * v[i];
                
                stepen = ProduktMatrica(stepen, mat);
                
            }
        }
    }
    
    
    
   
    
}


int main ()
{
    
    Matrica<double> a, matpol;
    int n, red,m;
   
    
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> n;
    
    try {
        
        a = StvoriMatricu<double>(n,n);
     
        
        cout << "Unesite elemente matrice A:" << endl;
        UnesiMatricu('A', a);
        
        cout << "Unesite red polinoma: ";
        cin >> red;
        
        vector<double> v;
        
        cout << "Unesite koeficijente polinoma: ";
        
        for(int i = 0; i < red; i++){
            
            cin >> m;
            v.push_back(m);
        }
        
        
        
        cout << "Matrica glasi: " << endl;
        
        matpol = MatricniPolinom(a, v);
        IspisiMatricu(matpol, 10, 6, false);
        
        
        
        
    }catch(domain_error x){
        
        cout << x.what();
        
    }catch(bad_alloc){
        
    cout << "Nema dovoljno memorije!";
    }
    
    UnistiMatricu(a);
    UnistiMatricu(matpol);
	return 0;
}