#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>>Matrica;

Matrica RastuciPodnizovi (std::vector<double>v){
Matrica K;
int k(0);
std::vector<double>v1;
std::vector<double>v2;
double prvi;
v1=v;
prvi=v1[0];
for(int i=1;i<v1.size();i++){
v2.push_back(prvi);
while(v1[i]>=prvi){
v2.push_back(v1[i]);
prvi=v1[i];
if(i==v1.size()-1){
    break;
}
i++;
}
prvi=v1[i];
if(v2.size()>1){
    K.resize(k+1,std::vector<double>(v2.size()));
    for(int j=k;j<k+1;j++){
        for(int s=0;s<v2.size();s++){
            K[j][s]=v2[s];
        }
    }
k++;
}
v2.resize(0);
}
return K;   
}

Matrica OpadajuciPodnizovi(std::vector<double>v){
Matrica K;
int k(0);
double prvi;
std::vector<double>v1;
std::vector<double>v2;
v1=v;
prvi=v1[0];
for(int i=1;i<v1.size();i++){
v2.push_back(prvi);
while(prvi>=v1[i]){
v2.push_back(v1[i]);
prvi=v1[i];
if(i==v1.size()-1){
    break;
}
i++;
}
prvi=v1[i];
if(v2.size()>1){
K.resize(k+1,std::vector<double>(v2.size()));
for(int j=k;j<k+1;j++){
       for(int s=0;s<v2.size();s++){
        K[j][s]=v2[s];
                    }
             }
        k++;
    }
v2.resize(0);
}
return K;    
}
    

int main ()
{
int n;
double broj;
std::vector<double>v;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;
std::cout<<"Unesite elemente vektora: ";
for(int i=0;i<n;i++){
std::cin>>broj;
v.push_back(broj);
}
Matrica M;
Matrica N;
M=RastuciPodnizovi(v);
N=OpadajuciPodnizovi(v);
if(M.size()!=0){
std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
for(int i=0;i<M.size();i++){
    for(int j=0;j<M[i].size();j++){
    std::cout<<M[i][j]<<" ";
}
std::cout<<std::endl;
}}
if(N.size()!=0){
std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
for(int i=0;i<N.size();i++){
    for(int j=0;j<N[i].size();j++){
        std::cout<<N[i][j]<<" ";
    }
    std::cout<<std::endl;
}}

return 0;
}