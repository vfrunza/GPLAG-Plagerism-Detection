/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojtim){
    std::vector<std::set<std::string>> rezultat;
    if(brojtim<1 || brojtim> imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n = imena.size();
    std::list<std::string> lista;

    return rezultat;
}

int main (){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> imena;
    for(int i=0;i<n;i++){
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    std::cout<<"\nUnesite broj timova: ";
    int brojtim;
    std::cin>>brojtim;
    std::vector<std::set<std::string>> razvrstani;
    try{
        razvrstani = Razvrstavanje(imena, brojtim);
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}