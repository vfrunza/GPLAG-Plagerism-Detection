/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <vector>

typedef std::vector<int> Vektor;

Vektor SumaCifara(Vektor v) {
    Vektor v1;
    for(int i=0; i<v.size(); i++){
        int suma(0);
        while(v[i]!=0){
            int c;
            c=v[i]%10;
            suma+=c;
            v[i]/=10;
        }
        v1.push_back(suma);
    }
    return v1;
}




int main ()
{
    int br_elemenata;
    int x;
    Vektor v;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>br_elemenata;
    std::cout<<"Unesite elemente vektora: ";
    
    
    for(int i=0; i<br_elemenata; i++) {
        std::cin>>x;
        v.push_back(x);
    }
    
    Vektor v1(SumaCifara(v));
   

    for(int i=0; i<v1.size(); i++) std::cout<<v1[i]<<" ";
	return 0;
}
