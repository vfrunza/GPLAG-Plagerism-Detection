#include <iostream>
#include <vector>
#include <cmath>
#include <limits>


/*bool JesuLiJednaki(double x, double y, double epsilon=1e-10) {
    if (y<0 && x>0 || x<0 && y>0 ) return false;
    return std::fabs(x-y) <= epsilon*(std::fabs(x)+std::fabs(y));
}

bool JesuLiJednakiZaMale(double x, double y, double epsilon=1e10) {
    double c=fabs(x-y)*epsilon;
    if (c==0) return true; // jedan je da su isti
    return false;
    
}*/

std::vector<std::vector<double> >  RastuciPodnizovi(std::vector<double> v) {
    std::vector<std::vector<double> > matrica;
    int counter(0);
    for(unsigned int i=0; i<v.size(); i++) {
       int k;
       k=i;
       bool t(false);
        for(unsigned int j=i+1; j<v.size(); j++) {
      
        if(v[i]-v[j]<std::numeric_limits<double>::epsilon()) { 
                if(j==k+1) {counter++; t=true;}       
                matrica.resize(counter);
             matrica[counter-1].push_back(v[i]);
             
           if(i!=v.size()-2)  i++;
           else {
               if(v[i]-v[j]<std::numeric_limits<double>::epsilon()) matrica[counter-1].push_back(v[j]);
           }
            }
        else {if(t) matrica[counter-1].push_back(v[i]); break;    }
            if(j==v.size()-1) break; 
        }
        t=false;
        if(i==v.size()-1) break;
    }
    return matrica;
}

std::vector<std::vector<double> > OpadajuciPodnizovi(std::vector<double> v) {
    std::vector<std::vector<double> > matrica;
    int counter(0);
    for(unsigned int i=0; i<v.size(); i++) {
        int k;
        k=i;
        bool t(false);
        for(unsigned int j=i+1; j<v.size(); j++) {
         
            if(v[i]-v[j]>-std::numeric_limits<double>::epsilon()) {
                if(j==k+1) {counter++; t=true; }
                matrica.resize(counter);
                matrica[counter-1].push_back(v[i]);
                
                if(i!=v.size()-2) i++;
                else {
                    if(v[i]-v[j]>-std::numeric_limits<double>::epsilon()) matrica[counter-1].push_back(v[j]);
                }
            }
            else {if (t) matrica[counter-1].push_back(v[i]); break; }
            
            if(j==v.size()-1) break;
        }
        t=false;
        if(i==v.size()-1) break;
        
    }
    return matrica;
}

void IspisiMatricu(std::vector<std::vector<double> > matrica) {
    for(auto red : matrica) {
        for(auto x : red) {
            std::cout << x << " ";  }
        std::cout << std::endl;
    }
}
int main ()

{
  
std::cout << "Unesite broj elemenata vektora: ";
int n;
std::cin >> n;
std::cout << "Unesite elemente vektora: ";
std::vector<double> a;
for(unsigned int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    a.push_back(x);
    if(i==n-1) break;
}
std::cout << "Maksimalni rastuci podnizovi: " << std::endl; 
IspisiMatricu(RastuciPodnizovi(a));
std::cout << "Maksimalni opadajuci podnizovi: " << std::endl; 
IspisiMatricu(OpadajuciPodnizovi(a));


	return 0;
}