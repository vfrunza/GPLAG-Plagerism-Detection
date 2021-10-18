#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<limits>
#include<stdexcept>
std::vector<std::vector<double>>  NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat){
    
    if(mat.size()==0||mat.at(0).size()==0)return std::vector<std::vector<double>> (0,std::vector<double>(0));
    for(int i=1;i<mat.size();i++){
        if(mat.at(i).size()!=mat.at(i-1).size())throw std::domain_error {"Matrica nije korektna"};
    }
    std::vector<std::vector<double>> max2;
    int max=1;
    int a;
    int suma=0;
    int red=999,kolona=999;
    for(int i=1;i<mat.size()-1;i++){
        for(int j=1;j<mat.at(0).size()-1;j++){
            a=1;
            while(j-a>=0&&j+a<mat.at(0).size()&&i-a>=0&&i+a<mat.size()){
                int suma1=suma;
                suma=0;
                for(int u=i-a;u<=i+a;u++){
                    for(int z=j-a;z<=j+a;z++){
                         if(a==1){if(z==j&&u==i)continue;suma+=mat.at(u).at(z);}
                       else{ if(u==i-a||u==i+a||z==j-a||z==j+a)suma+=mat.at(u).at(z);}
                    }
                }
                if(a==1){if(suma<mat.at(i).at(j))a++;else break;}
                else if (a!=1){if(suma<suma1)a++;else break;}
            }
            if(a>max){red=i;kolona=j;max=a;}
        }
    }
    
    if(red==999){
        int max_num=mat.at(0).at(0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                if(mat.at(i).at(j)>max_num)max_num=mat.at(i).at(j);
            }
        }
        return std::vector<std::vector<double>> (1,std::vector<double> (1,max_num));
    }
    max2.resize(max+max-1);
    
    double k=0;
    if(max%3==0){
        for(int g=red-max+1;g<=max+max-1;g++){
        for(int f=kolona+1-max;f<=max+max-1;f++){
            max2.at(k).push_back(mat.at(g).at(f));
           
        }
       k++;
    }
    }
    else{for(int g=red-max+1;g<max+max-1;g++){
        for(int f=kolona+1-max;f<max+max-1;f++){
            max2.at(k).push_back(mat.at(g).at(f));
           
        }
       k++;
    }
    }
    return max2;
}
int main (){
   
    int c,y,r;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    std::cin >> y;
    std::cin>>c;
    if(c<0||y<0)std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
    else {std::cout << "Unesite elemente matrice:\n";
    std::vector<std::vector<double>> a(y);
    for(int i=0;i<y;i++){
        for(int j=0;j<c;j++){
            std::cin >> r;
            a.at(i).push_back(r);
        }
    }
    auto ctt=(NajvecaPlaninaMatrice(a));
    std::cout << "Najveca planina unesene matrice je:" << std::endl;
    for(int i=0;i<ctt.size();i++){
        for(int j=0;j<ctt.at(0).size();j++){
        std::cout <<std::setw(6)<< ctt.at(i).at(j) ;
        }
        std::cout<<std::endl;
    }
    }
	return 0;
}
/*
 0 0 0 15 12 6 
 1 25 1 5 2 9
 1 1 20 15 10 5 
 3 2 19 130 14 8 
 90 6 20 12 17 2 
 12 3 5 1 8 4*/
/*
0 0 0 15 
1 25 1 5 
1 1 20 15*/
/*5 5 0 0 0 0 0 0 4 4 4 0 0 4 200 4 0 0 4 4 4 0 0 0 0 0 0*/
/*3 3 0 0 0 0 5 0 0 0 0 */
/*13 13
0 0 0 0 0 0   0      0     0  0 0 0 0
 0 0 0 0 0 0   0      0     0  0 0 0 0
0 0 0 0 0 0   0      0     0  0 0 0 0 
 0 0 0 1 1 1   1      1     1  1 0 0 0
0 0 0 1 4 4   4      4     4  1 0 0 0
0 0 0 1 4 17  17     17 4 1 0 0 0
0 0 0 1 4 17  10000  17 4 1 0 0 0 
0 0 0 1 4 17  17     17 4 1 0 0 0
 0 0 0 1 4 4   4      4  4  1  0 0 0 
0 0 0 1 1 1   1      1 1  1  0 0 0
0 0 0 0 0 0   0      0 0  0  0 0 0
0 0 0 0 0 0   0      0     0 0 0 0 0 
0 0 0 0 0 0   0      0     0  0 0 0 0
  */