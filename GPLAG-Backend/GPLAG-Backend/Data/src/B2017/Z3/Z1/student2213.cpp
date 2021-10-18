/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>

void Unos_Parova(int br_cvorova){
    double x, y;
    std::vector<std::pair<double, double> parovi;
    for(int i=0;i<br_cvorova;i++){
        
        std::cin >> x >> y ;
       parovi.push_back( std::make_pair(x , y));
       std::cin.clear();
       std::cin.ignore(1000,'\n');
    }
}

LinearnaInterpolacija( std::vector<std::pair<double, double> parovi )

int main ()
{   int opcija,br_cvorova;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija: "<<std::endl;
    std::cin>>opcija;
    switch(opcija):
    case 1: {
        std::cout << "Unesite broj cvorova: " << std::endl;
        std::cin >> br_cvorova;
        
    }
	return 0;
}
