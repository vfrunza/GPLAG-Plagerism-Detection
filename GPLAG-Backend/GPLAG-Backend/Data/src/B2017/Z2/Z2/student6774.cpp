#include <iostream>
#include<cmath>
#include<iomanip>
#include<deque> 
#include<limits>
#include<stdexcept>
#include<vector>

enum  SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kontenjer>
kontenjer PjescaniSat (kontenjer v,SmjerKretanja smjer){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if (v[i][j].size()!=v.size()||v[i][j].size()!=v.size())throw std::domain_error {"3D matrica nema oblik kocke"};
        }
    }
    auto temp(v);
    if(v.size()%2==0)throw std::length_error {"3D kontejner ne zadovoljava uvjet neparnosti"};
    
        return v;
}

int main (){
    int n=1;
    std::cout << "Unesite dimenziju (x/y/z): ";
    while(1){
        
        std::cin >> n;
    
    if(n>0)break;
    std::cout << "Dimenzija nije ispravna, unesite opet: " ;
    
    }
    std::cout << "Unesite elemente kontejnera: ";
	std::vector<std::vector<std::vector<int>>>v;
    for(int i=0;i<n;i++){
        std::vector<std::vector<int >>temp2;
        for(int j=0;j<n;j++){
            std::vector<int> temp1;
            for(int k=0;k<n;k++){
                int temp;
                 std::cin >> temp;
                 temp1.push_back(temp);
            }temp2.push_back(temp1);
        }v.push_back(temp2);
    }
   SmjerKretanja smjer=NaprijedNazad;
   std::cout << "Unesite smjer kretanja [0 - 5]: ";
   while (true) {
       int ks;
       std::cin >> ks;
       if(ks>=0&&ks<=5)break;
       std::cout << "Smjer nije ispravan, unesite opet: ";
   }
   try{
       PjescaniSat(v,smjer);
       
   }catch(std::domain_error er){
       std::cout << "\nIzuzetak: " << er.what()<<std::endl;
   }catch(std::length_error er){
       std::cout << "\nIzuzetak: " << er.what()<<std::endl;
   }
	
	return 0;
}