#include<iostream>
#include<vector>
#include<iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
std::vector<std::vector<double>> matrica;
std::vector<double> red;
for(int i=1;i<v.size();i++){
 if(v[i-1]<=v[i])
 {
    while(i<v.size() && v[i-1]<=v[i]){
    red.push_back(v[i-1]);
    i++;
 }
  red.push_back(v[i-1]);
  matrica.push_back(red);
  i--;
 }
 red={};
}
    return matrica;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
std::vector<std::vector<double>> matrica;
std::vector<double> red;
for(int i=1;i<v.size();i++){
 if(v[i-1]>=v[i])
 {
   while(i<v.size() && v[i-1]>=v[i]){
    red.push_back(v[i-1]);
    i++;
 }
 red.push_back(v[i-1]);
 matrica.push_back(red);
 i--;
 }
 red={};
}

    return matrica;
}
	




int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::vector<double>v;
    std::cout<<"Unesite elemente vektora: ";
    int z;
   for(int m=0;m<n;m++){
        std::cin>>z;
        v.push_back(z);
   }
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    std::vector<std::vector<double>> matrica1(RastuciPodnizovi(v));
     for(int i=0; i<matrica1.size(); i++){
      for(int j=0; j<matrica1[i].size(); j++){
         std::cout<<matrica1[i][j]<<" ";
      }
     std::cout<<std::endl;
   }
   
   std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
   std::vector<std::vector<double>> matrica2(OpadajuciPodnizovi(v));
   for(int k=0;k<matrica2.size();k++){
       for(int x=0;x<matrica2[k].size();x++){
          std::cout<<matrica2[k][x]<<" ";
       }
       std::cout<<std::endl;
   }
    
	return 0;
}