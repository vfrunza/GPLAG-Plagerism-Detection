#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
   int i=0,j=0,e=0,k=0,brojac=0,l=0; 
   std::vector<std::vector<double>> matrica;
  
    while(i<v.size()-1){
  if(i==v.size()) break;        
         if(v[i]<=v[i+1]){
        
        j=i;brojac=1;
        while(i+1<v.size()){
            
            if(v[i]>v[i+1]) break;
            i++;
            
            brojac++;
        }if(i==v.size()) break;
        e++;
        matrica.resize(e);
        matrica[k].resize(brojac);
        k++;
     
            for(int a=0;a<matrica[l].size();a++){
            matrica[l][a]=v[j];
           if(j==v.size()) break;
            j++;
        }l++;
    }
       
   
    else{
    
    if(i==v.size()) break;
    i++;
        
    }
}
return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
   int i=0,j=0,e=0,k=0,brojac=0,l=0;
   std::vector<std::vector<double>> matrica;
  
    while(i<v.size()-1){
  if(i==v.size()) break;        
         if(v[i]>=v[i+1]){
        
        j=i;brojac=1;
        while(i+1<v.size()){
            if(v[i]<v[i+1]) break;
            i++;
            brojac++;
        }if(i==v.size()) break;
        e++;
        matrica.resize(e);
        matrica[k].resize(brojac);
        k++;
     
            for(int a=0;a<matrica[l].size();a++){
            matrica[l][a]=v[j];
           if(j==v.size()) break;
            j++;
        }l++;
    }
       
   
    else{
    
    if(i==v.size()) break;
    i++;
        
    }
}
return matrica;
}



int main()
{ 
    int n,broj;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::vector<double> v;
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        std::cin>>broj;
        v.push_back(broj);
    }
    
    
   std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
   std::vector<std::vector<double>> matrica=RastuciPodnizovi(v);
     for(int i=0;i<matrica.size();i++){
       for(int j=0;j<matrica[i].size();j++){
           std::cout<<std::setprecision(12)<<matrica[i][j]<<" ";
       }std::cout<<std::endl;
   }
    std::vector<std::vector<double>> matrica1=OpadajuciPodnizovi(v);
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    int j=0;
    for(int i=0;i<matrica1.size();i++){
       for(int j=0;j<matrica1[i].size();j++){
           std::cout<<std::setprecision(12)<<matrica1[i][j]<<" ";
       }std::cout<<std::endl;
   }
    return 0;
}
