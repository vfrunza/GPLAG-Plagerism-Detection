/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<double, double> Cvor;

std::function<int(int)> LinearnaInterpolacija(std::vector<Cvor> v) {
        
    
}


int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int br;
    std::cin>>br;
    if(br==1){
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double arg;
        while(std::cin>>arg){
            std::cout<<"Unesite argument (ili 'kraj' za kraj): ";
            
        }
    }
    else if(br==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double poc, kraj, korak;
        std::cin>>poc>>kraj>>korak;
        double arg;
        while(std::cin>>arg){
            std::cout<<"Unesite argument (ili 'kraj' za kraj): ";
            
        }
    }
    
	return 0;
}
