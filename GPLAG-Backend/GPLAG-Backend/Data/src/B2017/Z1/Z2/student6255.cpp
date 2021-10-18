#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> pocetna)
{
    std::vector<std::vector<double>> planina;
    int n=pocetna.size();
    int m=pocetna.at(0).size();
    int x, y;
    int maxd=0;
    double vrh=0;
    double suma1=0;
    double suma2=0;

    if(n==0) throw std::domain_error ("Matrica nije korektna");

    for(int i=0; i<n; i++) {
        if(pocetna.at(i).size()!=m) throw std::domain_error ("Matrica nije korektna");
    }

    if(m==1) {
        for(int i=0; i<pocetna.size(); i++) {
            if(pocetna.at(i).at(0)>vrh) vrh=pocetna.at(i).at(0);
            planina.push_back({vrh});
            return planina;
        }
    }

    if(n==1) {
        for(int i=0; i<pocetna.at(0).size(); i++) {
            if(pocetna.at(0).at(i)>vrh) vrh=pocetna.at(0).at(i);
            planina.push_back({vrh});
            return planina;
        }
    }

    for(int i=0; i<n-1; i++)
        for(int j=1; j<m-1; j++) {
            int pomo=1;
            suma2=pocetna.at(i).at(j);
            while(i-pomo>=0 && j-pomo>=0 && j+pomo<m && i+pomo<n) {
                for(int k=i-pomo; k<i+pomo+1; k++)
                    suma1=suma1+pocetna.at(k).at(j-pomo)+pocetna.at(k).at(j+pomo);
                for(int k=j-pomo+1; k<j+pomo; k++)
                    suma1=suma1+pocetna.at(i+pomo).at(k)+pocetna.at(i-pomo).at(k);

                if(suma1<suma2) {
                    pomo++;
                    suma2=suma1;
                    suma1=0;
                } else {
                    if(pomo-1>maxd) {
                        maxd=pomo-1;
                        x=i;
                        y=y;
                    }
                    suma1=0;
                    if(pomo-1==maxd && pocetna.at(i).at(j)>vrh) {
                        vrh=pocetna.at(i).at(j);
                        x=i;
                        y=j;
                    }
                    break;
                }
            }
            if(pomo-1>maxd) {
                maxd=pomo-1;
                x=i;
                y=j;
            }
            suma1=0;
            if(pomo-1==maxd && pocetna.at(i).at(j)>vrh) {
                vrh=pocetna.at(i).at(j);
                x=i;
                y=j;
            }
        }
    if(maxd==0) {
        for(int i=0; i<pocetna.size(); i++)
            for(int j=0; j<pocetna.at(0).size(); j++)
                if(pocetna.at(i).at(j)>vrh) vrh=pocetna.at(i).at(j);
        planina.push_back({vrh});
        return planina;
    }
    planina.resize(2*maxd+1);

    for(int i=x-maxd; i<x+maxd+1; i++)
        for(int j=y-maxd; j<y+maxd+1; j++) {
            planina.at(i-x+maxd).push_back(pocetna.at(i).at(j));
        }
    return planina;
}

int main()
{
    int m, n;
    double p;
    std::vector<std::vector<double>> matrica;
    std::cout<<"Unesite dimenzije matrice (m i n): ";
    std::cin>>m>>n;
    
    if(m<0 || n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    matrica.resize(m);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            std::cin>>p;
            matrica.at(i).push_back(p);
        }
    }

    try {
        matrica=NajvecaPlaninaMatrice(matrica);
        std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
        
        for(int i=0; i<matrica.size(); i++) {
            for(int j=0; j<matrica.at(0).size(); j++)
                std::cout<<std::setw(6)<<matrica.at(i).at(j);
            std::cout<<std::endl;
        }
    } 
    catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
