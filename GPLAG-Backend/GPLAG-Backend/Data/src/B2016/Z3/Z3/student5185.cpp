#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

template <typename TipElemenata> //Sigurno ok
    struct Matrica{
        int brRedova, brKolona;
        TipElemenata **elementi = nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> A){
        if (!A.elementi) return;
        
        for (int i = 0; i < A.brRedova; i++) delete [] A.elementi[i];
        delete [] A.elementi;
        A.elementi = nullptr;
    } //Trebalo bi biti ok

template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int redovi, int kolone){
        Matrica<TipElemenata> A;
        A.brKolona=kolone; A.brRedova=redovi;
        A.elementi = new TipElemenata*[redovi];
        
        for (int i = 0; i < redovi; i++) A.elementi[i] = nullptr;
        
        try{
            for (int i = 0; i < redovi; i++) A.elementi[i] = new TipElemenata[kolone];
        }
        catch(...){
            UnistiMatricu(A);
            throw;
        }
        return A;
    } //Trebalo bi biti ok

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> A, Matrica<TipElemenata> B){
        if (A.brKolona != B.brRedova) { /*UnistiMatricu(A); UnistiMatricu(B);*/ throw std::domain_error ("Matrice nisu saglasne za mnozenje");}
        auto C(StvoriMatricu<TipElemenata>(A.brRedova, B.brKolona));
        
        for (int i = 0; i < A.brRedova; i++) {
            for (int j = 0; j < B.brKolona; j++) {
                TipElemenata suma=0;
                for (int k = 0; k < B.brRedova; k++) suma += A.elementi[i][k] * B.elementi[k][j];
                C.elementi[i][j] = suma;
            }
        }
        //Unistavam prijasnju verziju A
        
        return C; //Postaje novo A
    }
    
template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat){
        for (int i = 0; i < mat.brRedova; i++) {
            for (int j = 0; j < mat.brKolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    } //Trebalo bi biti ok
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriJedinicnuMatricu (int n){
        Matrica<TipElemenata> A (StvoriMatricu<TipElemenata>(n,n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i==j) A.elementi[i][j]= 1;
                else A.elementi[i][j]= 0;
            }
        }
        return A;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &A, const Matrica<TipElemenata> &B){
        if (A.brRedova != B.brRedova || A.brKolona != B.brKolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
        
        auto C(StvoriMatricu<TipElemenata>(A.brRedova, A.brKolona));
        for (int i = 0; i < A.brRedova; i++) {
            for (int j = 0; j < A.brRedova; j++) {
                C.elementi[i][j] = A.elementi[i][j] + B.elementi[i][j];
            }
        }
        
      
        return C;
    }

template <typename TipElemenata, typename TipElemenata1>
    Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> A, std::vector<TipElemenata1> koeficijentiPolinoma){
        if (A.brKolona != A.brRedova)  throw std::domain_error ("Matrica mora biti kvadratna"); //Ako nije kvadratna
        if (koeficijentiPolinoma.size() == 0) {
            auto C (StvoriMatricu<TipElemenata>(A.brRedova,A.brKolona));
            for (int i = 0; i < A.brRedova; i++) {
                for (int j = 0; j < A.brKolona; j++) {
                    C.elementi[i][j] = 0;
                }
            }
            UnistiMatricu(A);
            return C;
        }//Ako prazan koeficijentPolinoma
    
        auto B (StvoriMatricu<TipElemenata>(A.brRedova,A.brKolona)); for (int i = 0; i < A.brRedova; i++) {
            for (int j = 0; j < A.brKolona; j++) {
                B.elementi[i][j] = A.elementi[i][j];
            }
        }
        auto Z (StvoriMatricu<TipElemenata>(A.brRedova,A.brKolona)); for (int i = 0; i < A.brRedova; i++) {
            for (int j = 0; j < A.brKolona; j++) {
                Z.elementi[i][j] = A.elementi[i][j];
            }
        }
        
        auto C (StvoriJedinicnuMatricu<TipElemenata>(A.brKolona));
        for (int i = 0; i < A.brKolona; i++) for (int j = 0; j < A.brKolona; j++) C.elementi[i][j] *= koeficijentiPolinoma[0];
        
        
        for (int k = 1; k < koeficijentiPolinoma.size(); k++) {
            
            if (koeficijentiPolinoma[k]!=0){
            
            for (int i = 0; i < A.brKolona; i++) for (int j = 0; j < A.brKolona; j++) Z.elementi[i][j] *= koeficijentiPolinoma[k];
            
            auto E (StvoriMatricu<TipElemenata>(C.brRedova,C.brKolona)); for (int i = 0; i < C.brRedova; i++) {
            for (int j = 0; j < C.brKolona; j++) {
                E.elementi[i][j] = C.elementi[i][j];
            }
        }
            UnistiMatricu(C);
            C = ZbirMatrica(E, Z); //Problem ovdje! U pozivu brisem A iaako ne bih trebao
            UnistiMatricu(E);
            
          
            for (int i = 0; i < A.brKolona; i++) for (int j = 0; j < A.brKolona; j++) Z.elementi[i][j] = Z.elementi[i][j] / koeficijentiPolinoma[k];
            }
            
            auto F (StvoriMatricu<TipElemenata>(A.brRedova,A.brKolona)); for (int i = 0; i < A.brRedova; i++) {
            for (int j = 0; j < A.brKolona; j++) {
                F.elementi[i][j] = Z.elementi[i][j];
            }
        }
            UnistiMatricu(Z);
            Z = ProduktMatrica(F, B); //Problem ovdje! U pozivu brisem A iaako ne bih trebao
            UnistiMatricu(F);
        }
        UnistiMatricu(Z); 
        UnistiMatricu(B); //OBavezno se brise
        return C;
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirinaIspisa, int preciznost=6, bool treba_brisati=false){
        for (int i = 0; i < mat.brRedova; i++) {
            for (int j = 0; j < mat.brKolona; j++) {
                std::cout << std::setprecision(preciznost) << std::setw(sirinaIspisa) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        
        if (treba_brisati) UnistiMatricu(mat);
    
    }

int main (){
    /*
    std::cout << "Unesite dimenziju kvadratne matrice: "; int n; std::cin >> n;
    std::cout << "Unesite elemente matrice A: " << std::endl;
    
    Matrica<double> A (StvoriMatricu<double>(n,n));
    UnesiMatricu('A', A);
    
    std::cout << "Unesite red polinoma: "; std::cin >> n; n++; 
    std::cout << "Unesite koeficijente polinoma: "; std::vector<double> koeficijentiPolinoma(n);
    for (int i = 0; i < n; i++)  std::cin >> koeficijentiPolinoma[i];
    
    auto S (MatricniPolinom(A, koeficijentiPolinoma));
    UnistiMatricu(A); 
    IspisiMatricu(S, 10, 6, true);
    */
    
     Matrica<int> m1, m2, m3;
    m1 = StvoriMatricu<int>(3,3);
    UnesiMatricu<int>('A', m1);
    std::vector<double> v{1.4, 3.4, 5.6, 4.9, 3.2345, 0.4, 0, 4};
    try{
        m2 = MatricniPolinom(m1, v);
    }
    catch(std::domain_error e){
        std::cout <<  e.what() << std::endl;
    }
    UnistiMatricu(m1);
    IspisiMatricu(m2, 10);
    UnistiMatricu(m2);

    
    
    
    
	return 0;
}