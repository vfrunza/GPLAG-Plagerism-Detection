/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
 
int **KreirajTrougao(int n){
    if(n<=0) throw std::domain_error ("Broj redova mora biti pozitivan");
    int **mat(nullptr);
    try{
        mat = new int*[n];
        mat[0] = nullptr;
        mat[0] = new int [n*n];
        if(n != 1){
            mat[1] =  mat[0] + 1;
        }
        int j(3);
        for(int i=2; i<n; i++) {
            mat[i] = mat[i-1] + j;
            j+=2;
        }
       
        j = 1;
        for(int i=0; i<n; i++){
            for(int k=0; k<j; k++){
                if(i == k){
                    mat[i][k] = 1;
                }else if( i > k){
                    mat[i][k] = mat[i-1][k] + 1;
                }else if( i < k){
                    mat[i][k] = mat[i][k-1] + 1;
                }
            }
            j+=2;
        }
       
    }catch(std::bad_alloc){
        delete[] mat[0];
        delete[] mat;
        throw ;
    }catch(...){
        delete[] mat[0];
        delete[] mat;
        throw;
    }
    return mat;
}
 
int main ()
{
    std::cout << "Koliko zelite redova: ";
    int n;
    std::cin >> n;
    try{
        int **matrica( KreirajTrougao(n) );
        int j(1);
        for(int i=0; i<n; i++){
            for(int k=0; k<j; k++){
                std::cout << matrica[i][k] << " ";
            }
            std::cout << std::endl;
            j+=2;
        }
       
        delete[] matrica[0];
        delete[] matrica;
       
    }catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }catch(std::bad_alloc izuzetak){
        std::cout << "Izuzetak: Nedovoljno memorije!" << std::endl;
    }catch(...){
        std::cout << "Izuzetak";
    }
   
    return 0;
}