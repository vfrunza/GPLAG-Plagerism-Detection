#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> vv) {
    for(int i=1;i<vv.size();i++) if(vv[i].size() != vv[i-1].size()) throw std::domain_error("Matrica nije korektna");
    if(vv.size() == 0) return vv;

    std::vector<std::vector<double>> rez(3*vv.size(),std::vector<double>(3*vv[0].size()));
    int R(vv.size()), C(vv[0].size());

    for(int i=0;i<R;i++)  {
        for(int j=0;j<C;j++) {
            rez[i][j] = rez[i+2*R][j] = rez[i][j+2*C] = rez[i+2*R][j+2*C] = vv[R-1-i][C-1-j];
            rez[i+R][j+C] = vv[i][j];
            rez[i][j+C] = rez[i+2*R][j+C] = vv[R-1-i][j];
            rez[i+R][j] = rez[i+R][j+2*C] = vv[i][C-1-j];
        }

    }
    return rez;
}

int main (){
    int M,N;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>> N>> M;
    if(N<0 || M<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice:\n";
    std::vector<std::vector<double> > vv(N,std::vector<double>(M));
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) std::cin>>vv[i][j];
    try{
    vv = OgledaloMatrica(vv);
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
        return 0;
    }
    std::cout<<"Rezultantna matrica:\n";
    for(int i=0;i<3*N;i++) {
        for(int j=0;j<3*M;j++) std::cout<<std::setw(4)<< vv[i][j];
        std::cout<<'\n';
    }
	return 0;
}