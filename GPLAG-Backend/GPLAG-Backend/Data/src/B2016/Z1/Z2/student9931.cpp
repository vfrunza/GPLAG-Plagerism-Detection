#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>>matrica){
    int e(0);
    if(matrica.size()==0){
        throw e=0;
    }
    std::vector<std::vector<double>> M(3*matrica.size(),std::vector<double>(3*matrica[0].size()));
    std::vector<std::vector<double>> h(matrica.size(),std::vector<double>(matrica[0].size()));
    std::vector<std::vector<double>> hv(matrica.size(),std::vector<double>(matrica[0].size()));
    std::vector<std::vector<double>> v(matrica.size(),std::vector<double>(matrica[0].size()));
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica[0].size(); j++) {
            h[i][j]=matrica[i][matrica[0].size()-1-j];
        }
    }
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica[0].size(); j++) {
            v[i][j]=matrica[matrica.size()-1-i][j];
        }
    }
     for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica[0].size(); j++) {
            hv[i][j]=matrica[matrica.size()-1-i][matrica[0].size()-1-j];
        }
    }
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica[0].size(); j++) {
            M[i][j]=hv[i][j];
            M[i][j+matrica[0].size()]=v[i][j];
            M[i][j+2*matrica[0].size()]=hv[i][j];
            M[i+matrica.size()][j]=h[i][j];
            M[i+matrica.size()][j+matrica[0].size()]=matrica[i][j];
            M[i+matrica.size()][j+2*matrica[0].size()]=h[i][j];
            M[i+2*matrica.size()][j]=hv[i][j];
            M[i+2*matrica.size()][j+matrica[0].size()]=v[i][j];
            M[i+2*matrica.size()][j+2*matrica[0].size()]=hv[i][j];
        }
    }
   return M;
}
int main ()
{
    int a(2),b(3),k;
   
     std::cout<<"Unesite dimenzije matrice (m n): ";
     std::cin >> a;
     std::cin >> b;
     
     if(a<0||b<0){std::cout<<"Dimenzije matrice moraju biti nenegativne!";return 0;}
      std::vector<std::vector<double>> matrica1(3*a,std::vector<double>(3*b));
     std::vector<std::vector<double>> matrica;
     std::cout<<"Unesite elemente matrice: ";
     for (int i = 0; i < a; i++) {
         std::vector<double>red;
         for (int j = 0; j < b; j++) {
             std::cin >> k;
             red.push_back(k);
         }
         matrica.push_back(red);
     }
    if(a==0&&b==0){std::cout<<std::endl<<"Rezultantna matrica: ";return 0;}
   try{ matrica1=OgledaloMatrica(matrica);}
    catch (int e){
        std::cout << e << std::endl;
    }
    std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
    
    for (int i = 0; i < matrica1.size(); i++) {
        for (int j = 0; j < matrica1[0].size(); j++) {
            std::cout<<std::setw(4)<<matrica1[i][j];
        }std::cout<<std::endl;
    }
    
	return 0;
}