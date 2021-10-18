#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice (Matrica matrica)
{
    Matrica planina;
    int n;
    for (int i=1; i<matrica.size(); i++) {
        if (matrica.at(0).size()!=matrica.at(i).size()) throw std::domain_error("Matrica nije korektna");
    }
    if (matrica.size()%2==0) n=1;
    if (matrica.size()%2!=0) n=0;
    while (matrica.size()-n>0) {
        double suma=0;
        for (int i=0; i<matrica.size()-n; i++) {
            for (int j=0; j<matrica.size()-n; j++) {
                if (i==(matrica.size()-n)/2 && j==(matrica.size()-n)/2) continue;
                suma+=matrica.at(i).at(j);
            }
        }
        if (matrica.at((matrica.size()-n)/2).at((matrica.size()-n)/2)>suma) {
            if (matrica.size()%2==0) n=1;
            else if (matrica.size()%2!=0) n=0;
            planina.resize(matrica.size()-n);
            for(int k=0; k<matrica.size()-n; k++) {
                planina.at(k).resize(planina.size());
            }
            for (int i=0; i<planina.size(); i++) {
                for (int j=0; j<planina.size(); j++) {
                    planina.at(i).at(j)=matrica.at(i).at(j);
                }
            }
        }
        if (matrica.size()<3) {
            double max=matrica.at(0).at(0);
            Matrica maksimalni (1,std::vector<double>(1));
            for (int i=0; i<matrica.size(); i++) {
                for (int j=0; j<matrica.at(i).size(); j++) {
                    if (max<matrica.at(i).at(j)) {
                        max=matrica.at(i).at(j);
                    }
                }
            }
            maksimalni.at(0).at(0)=max;
            return maksimalni;
        } else if (planina.size()>0) break;
        else n++;
        if (n<=0) break;
    }
    return planina;
}






int main ()
{
    std::cout<<"Unesite dimenzije matrice (m i n): ";
    int m;
    int n;
    std::cin>>m>>n;
    if (m<0 || n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    if (m==0 || n==0) return 0;
    Matrica mat(m, std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: ";
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            std::cin>>mat.at(i).at(j);
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            }
        }
    }
    mat=NajvecaPlaninaMatrice(mat);
    std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat.at(i).size(); j++) {
            std::cout<<std::setw(6)<<mat.at(i).at(j);
        }
        std::cout<<std::endl;
    }
    return 0;
}