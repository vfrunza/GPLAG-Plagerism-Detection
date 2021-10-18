#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <limits>

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrix;
const double eps{0.00000001};

struct MatrixMountain{
    int n, row, column;
    double peak;
};

void printMatrix(Matrix M){
        for(int i(0); i<M.size(); i++) {
            for(int j(0); j<M.at(i).size(); j++)
                cout << std::right << std::setw(6) << M.at(i).at(j);
            cout<<std::endl;
        }
}

Matrix NajvecaPlaninaMatrice(Matrix x){
    for(int i(1); i<x.size(); i++)
        if(int(x.at(i).size()) != x.at(0).size()) {
            throw std::domain_error("Matrica nije korektna");
            break;
        }
        
    Matrix m;
    if(x.size() == 0 || x.at(0).size() == 0) 
        return m;
    
    MatrixMountain PM{0,0,0,0};
    
    for(int i_red(0); i_red<x.size(); i_red++)
        for(int j_kol(0); j_kol<x.at(0).size(); j_kol++) {
            bool prekid {false};
            int n_temp(1), index_red_temp(i_red), index_kol_temp(j_kol), k(-1);
            double vrh_temp = x.at(i_red).at(j_kol), skk = vrh_temp;    // skk - suma elemenata koncentricnog kvadrata
            do {
                double skk_temp=0;
                for(int i(k); i<abs(k) + 1; i++) {
                    for(int j(k); j<abs(k) + 1; j++) {
                        if(i_red + i < 0 || i_red + i > x.size() - 1 || j_kol + j < 0 || j_kol + j > x.at(0).size() - 1) {
                            prekid = true;
                            break;
                        }
                        
                        if(i >= k + 1 && i <= abs(k) - 1)
                            if(j >= k + 1 && j <= abs(k) - 1) continue;
                            
                        skk_temp += x.at(i_red + i).at(j_kol + j);
                    }
                    
                    if(prekid) break;
                }

                if(!prekid) {
                    if(skk_temp < x.at(i_red).at(j_kol) && skk > skk_temp) {
                        n_temp += 2;
                        skk = skk_temp;
                    } else prekid = true;
                }
                
                k--;
            
            } while(!prekid);

            if(PM.n < n_temp || (PM.n == n_temp && (PM.peak < vrh_temp || (PM.peak - vrh_temp<eps &&
              (index_red_temp < PM.row || (PM.row == index_red_temp && index_kol_temp < PM.column)))))) {
                PM.n = n_temp;
                PM.peak = vrh_temp;
                PM.column = index_kol_temp;
                PM.row = index_red_temp;
            }
        }

    Matrix A(PM.n, vector<double>(PM.n));
    for(int i = PM.row - PM.n/2, k=0; i <= PM.row + PM.n/2; i++,k++)
        for(int j = PM.column - PM.n/2, z=0; j <= PM.column+PM.n/2; j++,z++)
            A.at(k).at(z) = x.at(i).at(j);
    
    return A;
}

int main (){
    int m,n;
    cout << "Unesite dimenzije matrice (m i n): ";
    cin >> m >> n;
    
    if(m<0 || n<0) {
        cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0; }
        
    Matrix M(m,vector<double>(n));
    cout << "Unesite elemente matrice: " << std::endl;
    for(int i=0; i<int(M.size()); i++)
        for(int j=0; j<int(M.at(i).size()); j++)
            cin >> M.at(i).at(j);
            
    cout << "Najveca planina unesene matrice je:" << std::endl;
    printMatrix(NajvecaPlaninaMatrice(M));

    return 0;
}