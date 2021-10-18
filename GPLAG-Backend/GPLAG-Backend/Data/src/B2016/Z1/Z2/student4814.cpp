#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica UnesiMatricu(int broj_redova, int broj_kolona){
        Matrica m (broj_redova, std::vector<double>(broj_kolona));
        for(int i(0); i<broj_redova; i++){
                for(int j(0); j<broj_kolona; j++){
                        std::cin >>m[i][j];
                }
        }
        return m;
}
int BrojRedova(Matrica A){
        return A.size();
}
int BrojKolona(Matrica A){
        return A[0].size();
}
Matrica OgledaloMatrica (Matrica A){
    int m=BrojRedova(A);
    int n=BrojKolona(A);
    for(int i(0); i<BrojRedova(A); i++){
                if(A[i].size()!=BrojKolona(A))
                        throw std::domain_error ("Matrica nije korektna");
        }
 int k(0);
 int h(0);
        Matrica horizontalna;
        Matrica vertikalna;
        Matrica kombinovana;
        Matrica krajnja;

        for(int i(0); i<m; i++){
            for(int j=n-1; j>=0; j--){
                horizontalna[i][j]=A[i][k];
                k++;
            }
            k=0;
        }
    for(int i=m-1; i>=0; i--){
    	for(int j=0; j<n; j++){
        vertikalna[i][j]=A[h][j];
        }
        h++;
    }
    for(int i(0); i<m; i++){
    	for(int j=n-1; j>=0; j--){
        kombinovana[i][j]=A[i][k];
    }
    }
    for (int i = 0; i < 3*m; i++)
        {
            for (int j = 0; j < 3*n; j++)
            {
                krajnja[i][j] = kombinovana[i][j];
                krajnja[i + m][j] = horizontalna[i][j];
                krajnja[i + m + m][j] = kombinovana[i][j];
                krajnja[i][j+n] = vertikalna[i][j];
                krajnja[i][j+n+n] = kombinovana[i][j];
                krajnja[i + m][j+n] = A[i][j];
                krajnja[i + m][j + n + n] = horizontalna[i][j];
                krajnja[i + m + m][j + n] = vertikalna[i][j];
                krajnja[i + m + m][j + n + n] = kombinovana[i][j];
            }
        }
        
        return krajnja;
}



void IspisiMatricu(Matrica B) {
        for(int i  (0); i < 3*BrojRedova(B); i++) {
                for(int j  (0); j < 3*BrojKolona(B); j++)
                        std::cout << std::setw(10) << B[i][j];
                        std::cout << std::endl;
        }
}
int main() {
        int m, n;
        std::cout<<"Unesite dimenzije matrice (m n): ";
        std::cin>>m>>n;
        if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl; return 0; }
        std::cout<<"Unesite elemente matrice: "<<std::endl;
        Matrica A (UnesiMatricu(m, n));
        try{
        std::cout << "Rezultantna matrica: " <<std::endl;
        Matrica B;
        B=OgledaloMatrica(A);
        IspisiMatricu(B);
        }
        catch(std::domain_error izuzetak){
                std::cout <<izuzetak.what()<<std::endl;
        }
    return 0;
}
