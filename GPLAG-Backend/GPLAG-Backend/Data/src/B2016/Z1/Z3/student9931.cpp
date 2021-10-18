#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>vektor){
    std::vector<std::vector<double>>matrica ;
    std::vector<double>testnivektor ;
    for (int i = 0; i < vektor.size()-1; i++) {
         if(vektor[i]<=vektor[i+1]){
            testnivektor.push_back(vektor[i]);
        }else{ 
            testnivektor.push_back(vektor[i]);
            if(testnivektor.size()!=1){
                matrica.push_back(testnivektor);}
           testnivektor.clear();
       } 
    } 
    testnivektor.push_back(vektor[vektor.size()-1]);
   if(testnivektor.size()!=1) {matrica.push_back(testnivektor);}
    return matrica;
}
std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>vektor){
   std::vector<std::vector<double>>matrica ;
    std::vector<double>testnivektor ;
    for (int i = 0; i <vektor.size()-1; i++) {
         if(vektor[i+1]<=vektor[i]){
            testnivektor.push_back(vektor[i]);
        }else{ 
            testnivektor.push_back(vektor[i]);
            if(testnivektor.size()!=1){
                matrica.push_back(testnivektor);}
            testnivektor.clear();
       } 
    }
     testnivektor.push_back(vektor[vektor.size()-1]);
   if(testnivektor.size()!=1) {matrica.push_back(testnivektor);}
    return matrica;
}
int main ()
{
    std::vector<std::vector<double>>matrica ;
    std::vector<std::vector<double>>matrica1 ;
    std::vector<double>TestniVektor ;
    int a,k(0);
    double b;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin >> a;
    std::cout << "Unesite elemente vektora: ";
    for (int i = 0; i <a ; i++) {
        std::cin >> b;
        TestniVektor.push_back(b);
    }
    matrica=RastuciPodnizovi(TestniVektor);
    std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for (int i = 0; i < matrica.size(); i++) {
       for (int j = 0; j < matrica[k].size(); j++) {
          std::cout << matrica[i][j] <<" "; 
       }k++;std::cout  << std::endl;
    }
    k=0;
    matrica1=OpadajuciPodnizovi(TestniVektor);
    std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    for (int i = 0; i < matrica1.size(); i++) {
       for (int j = 0; j < matrica1[k].size(); j++) {
          std::cout << matrica1[i][j] <<" "; 
       }k++;std::cout  << std::endl;
    }
	return 0;
}