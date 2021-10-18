#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica HOgledaloMatrica(Matrica m) {
    Matrica mat(m.size(), std::vector<double>(m[0].size()));
    for(int i(0); i<m.size(); i++) {
        for(int j(0); j<m[i].size(); j++) {
            mat[i][j]=m[i][m[i].size()-1-j];
        }
    }
    return mat;
}
Matrica VOgledaloMatrica(Matrica m) {                                           //uzastopnim pozivanjem VOgledaloMatrica i HOgledaloMatrica dobijemo kombinovano ogledalo
    if(m.size()!=0) {
        Matrica mat(m.size(), std::vector<double>(m[0].size()));
        for(int i(0); i<m.size(); i++) {
            for(int j(0); j<m[i].size(); j++) {
                mat[i][j]=m[m.size()-1-i][j];
            }
        }
        return mat;
    }
}
Matrica OgledaloMatrica(Matrica m) {
    if(m.size()!=0) {
        for(int i(0); i<m.size()-1; i++) {
            if(m[i].size()!=m[i+1].size())
                throw std::domain_error("Matrica nije korektna");               //bacen izuzetak u slucaju da je matrica grbava
        }
    }
    if(m.size()==0) return m;
    Matrica vm=VOgledaloMatrica(m);
    Matrica hm=HOgledaloMatrica(m);
    Matrica hvm=HOgledaloMatrica(VOgledaloMatrica(m));
    Matrica hhvm=HOgledaloMatrica(hvm);
    Matrica mat(3*m.size(), std::vector<double>(3*m[0].size()));
    for(int i(0); i<mat.size(); i++) {
        for(int j(0); j<mat[0].size(); j++) {
            if((i<m.size() && j<m[0].size()) || (i<m.size() && j>2*m[0].size()-1) || (i>2*m.size()-1 && j<m[0].size()) || (i>2*m.size()-1 && j>2*m[0].size()-1)) {
                if(i<m.size() && j<m[0].size())
                    mat[i][j]=hvm[i][j];
                else if(i<m.size() && j>2*m[0].size()-1)
                    mat[i][j]=hhvm[i][3*m[0].size()-1-j];
                else if(i>2*m.size()-1 && j<m[0].size())
                    mat[i][j]=hm[3*m.size()-1-i][j];
                else if(i>2*m.size()-1 && j>2*m[0].size()-1)
                    mat[i][j]=m[3*m.size()-1-i][3*m[0].size()-1-j];
            }
            else if(i>m.size()-1 && j>m[0].size()-1 && i<2*m.size() && j<2*m[0].size())
                mat[i][j]=hvm[2*m.size()-1-i][2*m[0].size()-1-j];
            else if(i<m.size() && j>m[0].size()-1 && j<2*m[0].size())
                mat[i][j]=hvm[i][2*m[0].size()-1-j];
            else if(i>m.size()-1 && i<2*m.size() && j<m[0].size())
                mat[i][j]=hvm[2*m.size()-1-i][j];
            else if(i>m.size()-1 && i<2*m.size() && j>2*m[0].size()-1)
                mat[i][j]=vm[2*m.size()-1-i][3*m[0].size()-1-j];
            else 
                mat[i][j]=hm[3*m.size()-1-i][2*m[0].size()-1-j];
        }
    }
    return mat;
}
int main() {
    int m, n;
    std::cout << "Unesite dimenzije matrice (m n): ";
    std::cin >> m >> n;
    if(m<0 || n<0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    Matrica mat(m, std::vector<double>(n));
    Matrica M;
    std::cout << "Unesite elemente matrice: \n";
    for(int i(0); i<m; i++) {
        for(int j(0); j<n; j++) {
            double element;
            std::cin >> element;
            mat[i][j]=element;
        }
    }
    std::cout << "Rezultantna matrica: \n";
    try {                                                                       //samo poziv f-je u try bloku, moze se sve stavit ali bez potrebe
        M=OgledaloMatrica(mat);
        for(int i(0); i<M.size(); i++) {
            for(int j(0); j<M[i].size(); j++) {
                std::cout << std::setw(4) << M[i][j];
            }
            std::cout << std::endl;
        }
    }
    catch(std::domain_error grbava) {
        std::cout << grbava.what() << std::endl;
    }
    return 0;
}