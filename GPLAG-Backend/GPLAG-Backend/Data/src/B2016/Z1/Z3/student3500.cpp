#include <iostream>
#include <vector>

typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> vektorvektora;

vektorvektora RastuciPodnizovi(vektor v){
    int r=v.size()/2;
    vektorvektora V(r);                                                               
    int p1(1), p2(0), i(0);
    while(p1<v.size()){
        while((p1<v.size())&&(v[p1]>=v[p1-1])){                                                   
            p1++;
            
        }
        if((p1-p2)>1){                                                                                 
            while(p2<p1){
                V[i].push_back(v[p2]);
                p2++;
            }
            i++;
            p1++;
        }
        else if((p1-p2)<=1) {
            p2=p1;
            if(p1<v.size()) p1++;
        }
    }
    V.resize(i+1);
    return V;
    
}
vektorvektora OpadajuciPodnizovi(vektor v){
    int r=v.size()/2;
    vektorvektora V(r);                                                               
    int p1(1), p2(0), i(0);
    while(p1<v.size()){
        while((p1<v.size())&&(v[p1-1]>=v[p1])){                                                   
            p1++;
            
        }
        if((p1-p2)>1){                                                                                 
            while(p2<p1){
                V[i].push_back(v[p2]);
                p2++;
            }
            i++; 
            p1++;
        }
        else if((p1-p2)<=1) {
            p2=p1;
            if(p1<v.size()) p1++;
        }
            
    }
    if(i==0){
        vektorvektora P(0);                           ///pisemo dole sada o
        return P;
    }
    V.resize(i+1);
    return V;
    
}

int main ()
{
    int Size;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>Size;
    vektor v(Size);
    std::cout<<"Unesite elemente vektora: ";
    for(double &a: v) std::cin>>a;
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    
    for(vektor i: RastuciPodnizovi(v)){
        for(double j: i) std::cout<<j<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    
    for(vektor i: OpadajuciPodnizovi(v)){
        for(double j: i) std::cout<<j<<" ";
        std::cout<<std::endl;
    }
	return 0;
}