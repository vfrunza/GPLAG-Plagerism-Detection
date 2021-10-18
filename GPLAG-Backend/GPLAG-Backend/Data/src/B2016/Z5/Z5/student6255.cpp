#include<iostream>
#include<stdexcept>
#include<list>
#include<utility>
using namespace std;

class Temperature{
    list<int>minimalna;
    list<int>maximalna;
    public:
    Temperature(int min,int max){ if(min>max) throw range_error("Nekorektne temperature"); }
    void RegistrirajTemperature(pair<int,int>minmax); //minimalna i maksimalna dnevna temp
    void BrisiSve();
    void BrisiNegativneTemperature();
    void DajBrojRegistriranihTemperatura()const;
    int DajMinimalnuTemperaturu()const;
    int DajMaksimalnuTeperaturu()const;
    int DajBrojTeperaturaVecihOd()const;
    int DajBrojTeperaturaManjihOd()const;
    friend Temperature &operator++(Temperature &t);
    friend Temperature &operator++(Temperature &t,int);
    friend Temperature &operator--(Temperature &t);
    friend Temperature &operator--(Temperature &t,int);
    friend Temperature operator*(const Temperature &a, const Temperature &b);
    friend Temperature operator-(const Temperature &a, const Temperature &b);
    friend Temperature operator+(const Temperature &a, const Temperature &b);
    double &operator[](int a);
    friend Temperature operator+=(Temperature &a, const Temperature &b);
    friend Temperature operator-=(Temperature &a, const Temperature &b);
    friend bool operator==(const Temperature &a, const Temperature &b);
    friend bool operator!=(const Temperature &a, const Temperature &b);
    friend ostream &operator<<(ostream &tok, const Temperature &a);
    
};

void Temperature::RegistrirajTemperature(pair<int,int>minmax){
    if(minmax.first>minmax.second) throw range_error("Nekorektne temperature");
    auto it1=minimalna.begin();
    while(it1!=minimalna.end()){ *it1=minmax.first; it1++; }
    auto it2=maximalna.begin();
    while(it2!=maximalna.end()){ *it2=minmax.second; it2++; }
   
}
int main(){
    
    return 0; 
}
