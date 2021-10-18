#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stdexcept>
class Berza{
    int max_cijena,min_cijena;
    std::vector<int> cijene;
    public:
    Berza(int min,int max);
    explicit Berza(int max);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena()const{
        return cijene.size();
    }
    void BrisiSve(){
        cijene.resize(0);
    }
    int DajMinimalnuCijenu() const{
        if(cijene[0]<cijene[1])return cijene[0];
        return cijene[1];
    }
    int DajMaksimalnuCijenu() const{
        if(cijene[0]>cijene[1])return cijene[0];
        return cijene[1];
    }
    int DajBrojCijenaVecihOd(int cj);
    void Ispisi() const;
    Berza operator [](int index);
    friend Berza &operator ++( Berza &a);
    friend Berza operator ++( Berza &a, int);
    friend Berza operator -(Berza &a);
    friend Berza operator +(Berza &a,Berza &b);
    friend Berza operator -(Berza &a,Berza &b);
    friend Berza operator -=(Berza &a,const Berza &b);
    friend Berza operator +=(Berza &a,const Berza &b);
    friend Berza operator ==(Berza &a,Berza &b);
    friend Berza operator !=(Berza &a,Berza &b);
};
Berza::Berza(int min,int max){
    if(min<0 || max<0)throw std::range_error ("Ilegalne granicne cijene");
    min_cijena=min;
    max_cijena=max;
}
Berza::Berza(int max){
    if(max<0)throw std::range_error ("Ilegalne granicne cijene");
    min_cijena=0;
    max_cijena=max;
}
void Berza::RegistrirajCijenu(int cijena){
    if(cijena<min_cijena || cijena>max_cijena)throw std::range_error ("Ilegalna cijena");
    cijene.push_back(cijena);
}
int Berza::DajBrojCijenaVecihOd(int cj){
    
}
int main() {
    
    return 0;
}

