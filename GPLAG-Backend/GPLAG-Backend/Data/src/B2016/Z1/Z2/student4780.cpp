#include <iostream>
# include <vector>
# include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>>Prvi_i_treci(std::vector<std::vector<double>>mat)
{
    std::vector<std::vector<double>>nova(mat.size(), std::vector<double>(0));
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[mat.size()-1-i][mat.at(i).size()-1-j]);
            if(j==(mat.at(i).size()-1)) break;
        }
        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[mat.size()-1-i][j]);
            if(j==(mat.at(i).size()-1))break;
        }

        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[mat.size()-1-i][mat.at(i).size()-1-j]);
            if(j==(mat.at(i).size()-1))break;
        }
        if(i==mat.size()-1)break;
    }
    return nova;

}

std::vector<std::vector<double>>Sreda(std::vector<std::vector<double>>mat)
{
    std::vector<std::vector<double>>nova(mat.size(), std::vector<double>(0));
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[i][mat.at(i).size()-1-j]);
            if(j==(mat.at(i).size()-1)) break;
        }
        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[i][j]);
            if(j==(mat.at(i).size()-1))break;
        }
        for(int j=0; j<mat.at(i).size(); j++) {
            nova.at(i).push_back(mat[i][mat.at(i).size()-1-j]);
            if(j==(mat.at(i).size()-1))break;
        }
        if(i==(mat.size()-1))break;

    }

    return nova;
}



std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>>mat)
{
    for(int i=0; i<mat.size(); i++) {
        for(int j=i+1; j<mat.size(); j++)
            if(mat.at(i).size()!=mat.at(j).size()) throw std::domain_error("Matrica nije korektna");
    }
    std::vector<std::vector<double>>nova;
    std::vector<std::vector<double>>prva=Prvi_i_treci(mat);
    std::vector<std::vector<double>>druga=Sreda(mat);

    for(int i=0; i<prva.size(); i++) {
        nova.push_back(prva.at(i));
        if(i==(prva.size()-1))break;
    }

    for(int i=0; i<druga.size(); i++) {
        nova.push_back(druga.at(i));
        if(i==(druga.size()-1))break;
    }

    for(int i=0; i<prva.size(); i++) {
        nova.push_back(prva.at(i));
        if(i==(prva.size()-1))break;
    }
    return nova;

}



int main ()
{
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::vector<std::vector<double>>mat(m ,std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            std::cin>>mat[i][j];
        }
    }

    std::vector<std::vector<double>>ogledalo;
    try {
        ogledalo=OgledaloMatrica(mat);
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    std::cout<<"Rezultantna matrica: "<<std::endl;
    for(std::vector<double> red: ogledalo) {
        for(double x : red)std::cout<<" "<<std::setw(3)<<x;
        std::cout<<std::endl;
    }
    return 0;
}