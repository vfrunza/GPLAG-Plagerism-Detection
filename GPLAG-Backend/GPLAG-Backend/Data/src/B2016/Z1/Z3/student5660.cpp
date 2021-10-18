#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
const double epsilon=0.0000000001;
bool jelimanji(double prvi,double drugi){
    if(prvi<drugi || fabs(prvi-drugi)<epsilon)return true;
    return false;
}
bool jeliveci(double prvi,double drugi){
    if(prvi>drugi|| fabs(prvi-drugi)<epsilon)return true;
    return false;
}
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor){
    std::vector<std::vector<double>> matrica(0);
    std::vector<double>niz(0);
    int save(0);
    for(int i=1;i<vektor.size();i++){
        niz.resize(0);
        for(int j=i;j<vektor.size();j++){
            
            if(jeliveci(vektor[j],vektor[j-1])){
                if(niz.size()==0){
                    niz.push_back(vektor[j-1]);
                    niz.push_back(vektor[j]);
                    save=j;
                }else{
                    niz.push_back(vektor[j]);
                    save=j;
                }
            }else break;
        }
        if(niz.size()!=0){matrica.push_back(niz); i=save;}
    }
    return matrica;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor){
    std::vector<std::vector<double>> matrica(0);
    std::vector<double>niz(0);
    int save(0);
    for(int i=1;i<vektor.size();i++){
        niz.resize(0);
        for(int j=i;j<vektor.size();j++){
            
            if(jelimanji(vektor[j],vektor[j-1])){
                if(niz.size()==0){
                    niz.push_back(vektor[j-1]);
                    niz.push_back(vektor[j]);
                    save=j;
                }else{
                    niz.push_back(vektor[j]);
                    save=j;
                }
            }else break;
        }
        if(niz.size()!=0){matrica.push_back(niz); i=save;}
    }
    return matrica;
}
int main ()
{
   
    
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    if(n>=0){
        std::vector<double> vek(n);
        std::cout<<"Unesite elemente vektora: ";
        for(int i=0; i<n;i++){
           std::cin>>vek[i];  
        }
        std::vector<std::vector<double>> matrica(RastuciPodnizovi(vek));
        std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
        for(int i=0; i<matrica.size();i++){
            for(int j=0; j<matrica[i].size();j++){
                std::cout << std::setprecision(12) << matrica[i][j] << " ";
            }
            std::cout<<std::endl;
        }
        matrica=OpadajuciPodnizovi(vek);
        std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
        for(int i=0; i<matrica.size();i++){
            for(int j=0; j<matrica[i].size();j++){
                std::cout << std::setprecision(12) << matrica[i][j] << " ";
            }
            std::cout<<std::endl;
        }
    }
	return 0;
}