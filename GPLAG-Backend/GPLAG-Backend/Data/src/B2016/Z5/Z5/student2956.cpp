/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <list>
#include <stdexcept>

using namespace std;

class Temperature{
    list<int>min;
    list<int>max;
    public:
    Temperature(int maximalna,int minimalna){
        if(minimalna>maximalna) throw range_error("Nekorektne temperature");
    }
   void RegistrirajTemperature(pair<int,int>temp){
       if(temp.first>temp.second) throw range_error("Nekorektne temperature");
       min.push_back(temp.first);
       max.push_back(temp.second);
    }
    void BrisiSve(){
        min.clear();
        max.clear();
    }
    void BrisiTemperature(int parametar);
        
    
    int DajBrojRegistriranihTemperatura(){
        int brojmin=min.size();
        int brojmax=max.size();
        return brojmin+brojmax;
    }
    int DajMinimalnuTemperaturu(){
        int mini=min[0];
        for(int i=0;i<min.size();i++){
            if(min[i]<mini) mini=min[i];
        }
        return mini;
    }
    int DajMaksimalnuTemperaturu(){
        int maxi=max[0];
        for(int i=0;i<max.size();i++){
            if(max[i]>maxi) maxi=max[i]; 
        }
        return maxi;
    }
    
    
};
 void Temperature::BrisiTemperature(int parametar){
        for(int i=0;i<min.size();i++){
            if(min[i]==parametar) min.clear;
            else throw logic_error("Takve temperature nisu registrirane");
        }
        for(int i=0;i<max.size();i++){
            if(max[i]==parametar) max[i].clear();
            else throw logic_error("Takve temperature nisu registrirane");
        }
    }
int main(){
    return 0;
}