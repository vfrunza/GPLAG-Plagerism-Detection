/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <vector>
    
    template<typename TipElemenata>
    struct Matrica{
        int br_redova;
        int br_kolona;
        TipElemenata **elementi = nullptr;
        };
        
    template<typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata>mat){
        if(!mat.elementi) return;
        for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
        
    template<typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata>mat;
        mat.br_redova = br_redova;
        mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        try{
            for(int i=0; i<br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...){
            UnistiMatricu(mat); 
            throw;
        }
        return mat;
    }
    
    template<typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata>&mat){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }
    
    template<typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            }
            std::cout<<std::endl;
        }
        if(treba_brisati)
            UnistiMatricu(mat);
    }
    
    template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0; i<m1.br_redova; i++){
            for(int j=0; j<m1.br_kolona; j++){
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            }
        }
        return m3;
    }
    
    template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata>&mat1, const Matrica<TipElemenata>&mat2){
        if(mat1.br_kolona != mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
        for(int i=0; i<mat1.br_redova; i++)
            for(int j=0; j<mat2.br_kolona; j++)
                mat3.elementi[i][j] = 0;
                
        for(int i=0; i<mat1.br_redova; i++){
            for(int j=0; j<mat2.br_kolona; j++){
                for(int k=0; k<mat1.br_kolona; k++)  mat3.elementi[i][j] += mat1.elementi[i][k] * mat2.elementi[k][j];
            }
        }
            
            return mat3;
    }
    
    template<typename TipElemenata, typename TipVektora>
    void BrojMnoziMatricuISabira(const Matrica<TipElemenata>&mat1, const Matrica<TipElemenata>&mat2, TipVektora broj){
        for(int i=0; i<mat1.br_redova; i++){
            for(int j=0; j<mat1.br_redova; j++){
                mat1.elementi[i][j] += mat2.elementi[i][j]*broj;
            }
        }
    }
    
    template<typename TipElemenata, typename TipVektora>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata>&A, std::vector<TipVektora>v){
        if(A.br_redova != A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        if(v.size() == 0){
            auto nula(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
            for(int i=0; i<A.br_redova; i++){
                for(int j=0; j<A.br_kolona; j++){
                    nula.elementi[i][j] = 0; 
                }
            }
            return nula;
        }
        auto polinom(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        
        for(int i=0; i<A.br_redova; i++)
            for(int j=0; j<A.br_kolona; j++)
                polinom.elementi[i][j] = 0;
        
        Matrica<TipElemenata>stepenovati, za_obrisati;
        try{
            stepenovati = StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
            
            for(int i=0; i<A.br_redova; i++)
                for(int j=0; j<A.br_kolona; j++)
                   if(i==j) stepenovati.elementi[i][j] = 1;
                   else stepenovati.elementi[i][j] = 0;
        }
        catch(...){
            UnistiMatricu(polinom);
            throw;
        }
        
        try{
            za_obrisati = stepenovati;
            BrojMnoziMatricuISabira(polinom,stepenovati,v[0]);
            
            for(int i=0; i<A.br_redova; i++)
                for(int j=0; j<A.br_kolona; j++)
                    stepenovati.elementi[i][j] = A.elementi[i][j];
                    
            za_obrisati = stepenovati;
            BrojMnoziMatricuISabira(polinom,stepenovati,v[1]);
            
            for(int i=2; i<v.size(); i++){
                za_obrisati = stepenovati;
                stepenovati = ProduktMatrica(stepenovati,A);
                BrojMnoziMatricuISabira(polinom,stepenovati,v[i]);
                UnistiMatricu(za_obrisati);
            }
        }
        catch(...){
            UnistiMatricu(za_obrisati);
        }
        
        UnistiMatricu(stepenovati);
        
        return polinom;
        
    }
int main ()
{   
    Matrica<int> a, b;
    std::vector<int>koeficijenti;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    try{
        a = StvoriMatricu<int>(n,n);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int k;
        std::cin>>k;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<k+1; i++){
            int unesi;
            std::cin>>unesi;
            koeficijenti.push_back(unesi);
        }
    try{
        b = MatricniPolinom(a,koeficijenti);
        IspisiMatricu(b, 10, 6, true);
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    
    UnistiMatricu(a);

    
	return 0;
}