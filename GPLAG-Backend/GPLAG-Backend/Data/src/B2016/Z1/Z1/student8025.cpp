#include <iostream>
#include <vector>
int PretvoriUTernarni(int n, bool a){
    std::vector<int> v;
    std::vector<int> brojaci(10);
    if(n<0) n*=-1;
    if(n==0){
        v.push_back(0);
    }
    while(n!=0){
        v.push_back(n%3);
        n/=3;
    }
    brojaci.resize(v.size());
    for(int i=0; i<brojaci.size(); i++){
        brojaci[i]=1;
    }
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]==v[j]){
                brojaci[i]++;
            }
        }
    }
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]==v[j]){
                v.erase(v.begin() + j);
                brojaci.erase(brojaci.begin()+j);
                j--;
            }
        }
    }
    if(a==true){
        for(int i=0; i<brojaci.size(); i++){
            if(brojaci[i]%2!=0) return 0; 
        }
        return 1;
    }
    if(a==false){
        for(int i=0; i<brojaci.size(); i++){
            if(brojaci[i]%2==0) return 0; 
        }
        return 1;
    }
    return 0;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool x){
    std::vector<int> pomocni=v;
    std::vector<int> potrebni;
    if(v.size()==0) return potrebni;
    for(int i=0; i<pomocni.size()-1; i++){
        for(int j=i+1; j<pomocni.size(); j++){
            if(pomocni[i]==pomocni[j]){
                pomocni.erase(pomocni.begin()+j);
                j--;
            }
        
        }
    }
    for(int i=0; i<pomocni.size(); i++){
    int n=PretvoriUTernarni(pomocni[i],x);
    if(n==1){
        potrebni.push_back(pomocni[i]);
    }
    }
return potrebni;
}
int main ()
{
    int n;
    std::vector<int>v;
    std::vector<int>rezultatni;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
   do{
       std::cin>>n;
       if(n==0) break;
       v.push_back(n);
   }while(n!=0);
   std::cout<<"Opaki: ";
    rezultatni=IzdvojiGadne(v,true);
    for(int i=0; i<rezultatni.size(); i++){
        std::cout<<rezultatni[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
     rezultatni=IzdvojiGadne(v,false);
    for(int i=0; i<rezultatni.size(); i++){
        std::cout<<rezultatni[i]<<" ";
    }
	return 0;
}