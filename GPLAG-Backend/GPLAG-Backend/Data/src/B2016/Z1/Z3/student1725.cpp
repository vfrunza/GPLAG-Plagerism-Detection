#include <iostream>
#include <vector>
#include<iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
    typedef std::vector<std::vector<double>> Matrica;
    Matrica m;
    std::vector<double> niz;
    
        m.resize(1);
        for(int i=0;i<(v.size()-1);i++) {
            if((i<v.size()-1) && v[i]<=v[i+1]) {
                while(i<(v.size()-1) && v[i]<=v[i+1]) {
                    niz.push_back(v[i]); i++;
                }
                niz.push_back(v[i]);
                if(niz.size()>1) {
                    for(int j=0;j<niz.size();j++) m[m.size()-1].push_back(niz[j]);
                    m.resize(m.size()+1);    
                }
                niz.resize(0);
            }
            else continue;
        }
       
     m.resize(m.size()-1);
      
return m;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
    typedef std::vector<std::vector<double>> Matrica;
    Matrica m;
    std::vector<double> niz;
    
        m.resize(1);
        for(int i=0;i<v.size()-1;i++) {
            if((i<v.size()-1) && v[i]>=v[i+1]) {
                while((i<v.size()-1) && v[i]>=v[i+1]) {
                    niz.push_back(v[i]); i++;
                }
                niz.push_back(v[i]);
                if(niz.size()>1) {
                    for(int j=0;j<niz.size();j++) m[m.size()-1].push_back(niz[j]);
                    m.resize(m.size()+1);    
                    }
                niz.resize(0);
            }
            else continue;
        }
        
        m.resize(m.size()-1);
      
return m;
}


int main () {
    
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    
    std::vector<double> v(n);
    
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<v.size();i++) std::cin>>v[i];
    
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(auto red:RastuciPodnizovi(v)) {
        for(auto x:red) std::cout<<std::setprecision(12)<<x<<" ";
        std::cout<<std::endl;
        }
        
        
         std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(auto red:OpadajuciPodnizovi(v)) {
        for(auto x:red) std::cout<<std::setprecision(12)<<x<<" ";
        std::cout<<std::endl;
        }
        
	return 0;
}

