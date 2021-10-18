#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
    Matrica mat;
    std::vector<double> red ;
    double tmp;
    if(v.size()==0) return mat;
    tmp=v[0];
    for(int i=0;i<v.size();i++){
        if(i==0)tmp=v[0];
        else{
            red.resize(0);
            while(tmp>v[i]){
                tmp=v[i];
                if(i==v.size()-1)break;
                i++;
            }
           if(i==v.size()-1)break;
            while(tmp<=v[i]){
                red.push_back(tmp);
                tmp=v[i];
                if(i==v.size()-1)break;
                i++;
            }
            red.push_back(tmp);
            mat.push_back(red);
           //if(i==v.size()-1)break;
          i--;
        }
    }
    return mat;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
    Matrica mat;
    std::vector<double> red;
    double tmp;
    if(v.size()==0) return mat;
    tmp=v[0];
    for(int i=0;i<v.size();i++){
        if(i==0)tmp=v[0];
        else{
            red.resize(0);
            while(tmp<v[i]){
                tmp=v[i];
                if(i==v.size()-1)break;
                i++;
            }
            if(i==v.size()-1)break;
            while(tmp>=v[i]){
                red.push_back(tmp);
                tmp=v[i];
                if(i==v.size()-1)break;
                i++;
            }
            red.push_back(tmp);
            mat.push_back(red);
            //if(i==v.size()-1)break;
            i--;
           
        }
    }
    return mat;
}
void Ispisi(Matrica m){
    for(auto red:m){
        for(auto x:red){
            std::cout << x<<" "; 
        }
        std::cout << std::endl;
    }
}

int main ()
{
    int n;
    double a;
    std::cout << "Unesite broj elemenata vektora: ";
    try{
        std::cin >> n;
        if(n<0) throw std::domain_error("Greska");
    }
    catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
   std::vector<double> v;
   std::cout << "Unesite elemente vektora: ";
   for(int i=0;i<n;i++){
       std::cin >> a;
       v.push_back(a);
   }
   Matrica mat;
   Matrica mat1;
   std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
   mat=RastuciPodnizovi(v);
   if(mat.size()!=0){
        Ispisi(mat);
   }
   std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
   mat1=OpadajuciPodnizovi(v);
   if(mat1.size()!=0){
        Ispisi(mat1);
   }
	return 0;
}