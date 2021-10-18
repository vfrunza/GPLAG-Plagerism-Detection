/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>

int main ()
{
    int a,b,n;
    std::cout << "Unesi broj: " << std::endl;
    std::cin>>n;
    
    for(int i=0;i<n;i++){
        std::cout << "Unesite centar:" << std::endl;
        std::cin >> a;
        while(a<0 || !std::cin){
        std::cout << "Neispravan centar"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite centar "<<i+1<<". kugle: " ;
        std::cin >>a;
    
        }
        std::cin >> b;
        while(b<0 ||!std::cin){
         std::cout << "Ilegalan poluprecnik" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> b;
        }
        
    }
	return 0;
}
