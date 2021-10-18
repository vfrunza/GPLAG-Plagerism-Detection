/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<int> Vektor;
typedef std::vector<std::vector<int>> matrica;

matrica TablicaMnozenja(int m, int n) {
    matrica tablica;
    tablica.resize(m);
    for(int i=0; i<n; i++) tablica[i].resize(n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            tablica[i][j]=(i+1)*(j+1);
        }
    }
    return tablica;
    
        
}

int main ()
{
    matrica matrix;
    int m,n;
    std::cout<<"Unesite parametre m i n: ";
    std::cin>>m>>n;
    
   matrix=TablicaMnozenja(m,n);
    
    for(auto red : matrix) {
        for(int x : red) {
            std::cout<<std::setw(5)<<x;
        }
        std::cout<<std::endl;
    }
	return 0;
}
