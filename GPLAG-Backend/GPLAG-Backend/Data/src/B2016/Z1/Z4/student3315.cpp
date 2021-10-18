#include <vector>
#include <iostream>
#include <string>

std::vector<std::vector<double>> Hor_matrica(std::vector<std::vector<double>>v){
    
    if(v.size()==0){
        return v;
    }
    
    std::vector<std::vector<double>>p;
    std::vector<double> temp;
    
    for(int i=0;i<v.size();i++){
        for(int  j=v.size()-1;j>=i+1;j--){
            temp=v[j-1];
            v[j-1]=v[j];
            v[j]=temp;
        }
        
    }
    
    return v;
}


std::vector<std::vector<double>> Ver_matrica(std::vector<std::vector<double>>v){
    double zamjena;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()/2;j++){
            zamjena=v[i][v[i].size()-1-j];
            v[i][v[i].size()-1-j]=v[i][j];
            v[i][j]=zamjena;
        }
    }
    return v;
}









std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> v){
    std::vector<std::vector<double>>p;
    
    if(v.size()==0){
        return  v;
    }
    
    // ubacit treba ono za domain error
    
    std::vector<std::vector<double>>p1;
    std::vector<std::vector<double>>p2;
    std::vector<std::vector<double>>p3;
    
    p1=(Hor_matrica(v));
    p2=(Ver_matrica(v));
    p3=(Hor_matrica(v));
    p3=(Ver_matrica(p3));
    
    
    return p1;
}












int main ()
{
    std::vector<std::vector<double>>v;
    std::vector<std::vector<double>>k;
    int m,n;
    std::cout<<"Unesite dimenzije matrice: "
    std::cin<<m<<n;
    
    
   k=OgledaloMatrica(v);
    for(int i=0;i<v.size();i++){
        for(int j=0;v[j].size();j++ ){
            std::cout<<v[i][j];
        }
    }
    
    
	return 0;
}