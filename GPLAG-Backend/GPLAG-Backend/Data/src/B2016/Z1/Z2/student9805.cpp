#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> MMatrix(std::vector<std::vector<double>> xyz){
    if(xyz.size()){
        for(std::vector<double>vektor:xyz) if(vektor.size()!=xyz[0].size()) throw std::domain_error("Matrica nije korektna!");
    }
    std::vector<std::vector<double>> povratnamatrica(3*xyz.size(),std::vector<double>(xyz[0].size()*3));
    for (int i=0;i<xyz.size();i++){
        for(int j=0;j<xyz[0].size();j++){
            povratnamatrica[i][j]                              =xyz[xyz.size()-1-i][xyz[0].size()-1-j];
            povratnamatrica[i][j+xyz[0].size()]                =xyz[xyz.size()-1-i][j];
            povratnamatrica[i][j+2*xyz[0].size()]              =xyz[xyz.size()-1-i][xyz[0].size()-1-j];
            povratnamatrica[i+xyz.size()][j]                   =xyz[i][xyz[0].size()-1-j];
            povratnamatrica[i+xyz.size()][j+xyz[0].size()]     =xyz[i][j];
            povratnamatrica[i+xyz.size()][j+2*xyz[0].size()]   =xyz[i][xyz[0].size()-1-j];
            povratnamatrica[i+2*xyz.size()][j]                 =xyz[xyz.size()-1-i][xyz[0].size()-1-j];
            povratnamatrica[i+2*xyz.size()][j+xyz[0].size()]   =xyz[xyz.size()-1-i][j];
            povratnamatrica[i+2*xyz.size()][j+2*xyz[0].size()] =xyz[xyz.size()-1-i][xyz[0].size()-1-j];
        }
    }
    return povratnamatrica;
    
}

int main ()
{
    int x,y;
    std::cout<<"Unesite dimenzije matrice (x y): ";
    std::cin>>x>>y;
    if(x<0 || y<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
    std::vector<std::vector<double>> kraj(x,std::vector<double>(y));
    std::cout<<"Unesite elemente matrice: ";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            std::cin>>kraj[i][j];
        }
    }
    kraj=MMatrix(kraj);
    std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
    for(int k=0;k<kraj.size();k++){
        for(int l=0;l<kraj[0].size();l++){
            std::cout<<std::setw(4)<<kraj[k][l]<<std::endl;
        }
    }
	return 0;
}