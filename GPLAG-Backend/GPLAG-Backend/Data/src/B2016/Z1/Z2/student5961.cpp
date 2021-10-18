#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

int NevaljaMatrica(std::vector<std::vector<double>> test){
    for(int i = 0; i < test.size(); i++){
        if(test[0].size() != test[i].size()) return true;
    }
    return false;
}

std::vector<std::vector<double>> OgledaloKolona(std::vector<std::vector<double>> H){
    for(int i = 0; i < H.size(); i++){
        int k = H[i].size()-1;
        for(int j = 0; j < H[i].size()/2; j++){
            double x = H[i][j];
            H[i][j] = H[i][k]; H[i][k] = x;
            k--;
        }
    }
    return H;
}

std::vector<std::vector<double>> OgledaloVrsta(std::vector<std::vector<double>> V){
    int j = V.size()-1;
    for(int i = 0; i < V.size()/2; i++){
        std::vector<double> temp = std::move(V[i]);
        V[i] = std::move(V[j]); V[j] = std::move(temp);
        j--;
    }
    return V;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M){
    if(NevaljaMatrica(M)) throw std::domain_error("Matrica nije korektna");
    if(!M.size()) return M;
    else if (!M[0].size()) {
        M.resize(3*M.size());
        return M;
    }
    std::vector<std::vector<double>> temp = M;
    std::vector<std::vector<double>> hM = OgledaloKolona(M);
    std::vector<std::vector<double>> vM = OgledaloVrsta(M);
    std::vector<std::vector<double>> hvM = OgledaloVrsta(hM);
    int v = 3*M.size(), l = 3*M[0].size();
    M.resize(v);
    for(int i(0); i < v; i++) M[i].resize(l);
    {
        int k(0);
        for(int i(0); i < v; i++){
            int h(0);
            if(k == v/3) k = 0;
            for(int j(0); j < l; j++){
                if(h == l/3) h = 0;
                if(((i < v/3 || i >= 2*v/3) && (j < l/3 || j >= 2*l/3))) M[i][j] = hvM[k][h];
                else if((i < v/3 && j >= l/3 && j < 2*l/3) || (i >= 2*v/3 && j >= l/3 && j < 2*l/3)) M[i][j] = vM[k][h];
                else if(i >= v/3 && i < 2*v/3 && (j < l/3 || j >= 2*l/3)) M[i][j] = hM[k][h];
                else if(i >= v/3 && i < 2*v/3 && j >= l/3 && j < 2*l/3 ) M[i][j] = temp[k][h];
                h++;
            }
            k++;
        }
    }
    return M;
}

int main (){
    std::cout << "Unesite dimenzije matrice (m n): ";
    int m, n;
    std::cin >>m >> n;
    if(m < 0 || n < 0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!"; return 0;
    }
    std::cout << "Unesite elemente matrice:";
    std::vector<std::vector<double>> M(m, std::vector<double>(n));
    for(int i = 0; i < m; i++){
        for(int j(0); j < n; j++){
            std::cin >> M[i][j];
        }
    }
    try{
        M = OgledaloMatrica(M);
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    std::cout << "\nRezultantna matrica:" << std::endl;
    for(std::vector<double> v : M){
        for(double x : v){
            std::cout << std::setw(4) << x;
        }
        std::cout << std::endl;
    }
    return 0;
}