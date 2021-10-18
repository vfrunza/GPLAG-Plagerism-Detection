#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<std::vector<int> > hOgledalo(std::vector<std::vector<int> > M) {
    
    std::vector<std::vector<int> > mat(M);
    
    for(int i=0; i<M.size(); i++){
        for(int j=0; j<M.size()/2; j++){
            std::swap(mat[i][j], mat[i][M[i].size()-1-i]);
        }
    }
    return mat;
}

std::vector<std::vector<int> > vOgledalo(std::vector<std::vector<int> > M){
    
    std::vector<std::vector<int> > mat(M);
    for(int j=0; j<M[0].size(); j++){
        for(int i=0; i<M.size()/2; i++){
            std::swap(mat[i][j], mat[M.size()-1-i][j]);
        }
    }
    return mat;
}

std::vector<std::vector<int> > OgledaloMatrica(std::vector<std::vector<int> > M){
    
    if(M.size()==0) {
        return M;
    }
    if(M.size()!=0 && M[0].size()==0) {
        M.resize(3*M.size());
        return M;
    }
    for(int i=1; i<M.size(); i++){
        if(M[i].size()!=M[0].size()){
            throw std::domain_error("Matrica nije korektna");
        }
    }
    
    std::vector<std::vector<int> > h(hOgledalo(M)), v(vOgledalo(M)), hv(hOgledalo(vOgledalo(M))), mat;
    mat.resize(3*M.size());
    for(int i=0; i<mat.size(); i++){
        mat[i].resize(3*M[0].size());
    }
    for(int i=0; i<hv.size(); i++){
        for(int j=0; j<hv[i].size(); j++){
            mat[i][j]=hv[i][j];
            mat[i+2*hv.size()][j]=hv[i][j];
            mat[i][j+2*hv[i].size()]=hv[i][j];
            mat[i+2*hv.size()][j+2*hv.size()]=hv[i][j];
        }
    }
    for(int i=0; i<h.size(); i++){
        for(int j=0; j<h[i].size(); j++){
            mat[i+h.size()][j]=h[i][j];
            mat[i+h.size()][j+2*h[i].size()]=h[i][j];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            mat[i][j+v[i].size()]=v[i][j];
            mat[i+2*v.size()][j+v[i].size()]=v[i][j];
        }
    }
    for(int i=0; i<M.size(); i++){
        for(int j=0; j<M[i].size(); j++){
            mat[i+M.size()][j+M[i].size()]=M[i][j];
        }
    }
    return mat;
}

int main() {
    int m, n;
    std::cout<<"Unesite dimenzije matrice (m n): Unesite elemente matrice: "<<std::endl;
    std::cin>>m>>n;
    if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
    std::vector<std::vector<int> >  M;
    M.resize(m);
    for(int i=0; i<m; i++){
        M[i].resize(n);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                std::cin>>M[i][j];
            }
        }
        std::cout<<"Rezultantna matrica: "<<std::endl;
    std::vector<std::vector<int> > O(OgledaloMatrica(M));
    for(int i=0; i<O.size(); i++){
        for(int j=0; j<O[i].size(); j++){
            std::cout<<O[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}