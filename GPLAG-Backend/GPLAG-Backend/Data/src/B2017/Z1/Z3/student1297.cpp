#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

enum Smjer{Opadajuci, Rastuci};

bool ManjiIliJednak(char a, char b) {
    if(a<=b) return true;
    
    return false;
} 

bool Stepen(int x) {
for (int i=1; i<=x; i*=2) {
if (x==i) return true;
}

return false;
}

bool Veci(char a, char b) {
    if(a>b) return true;
    
    return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, enum Smjer x) {
    std::deque<std::vector<int>> d;
    if(x) {         // R A S T U C I
        
        for(int i=1; i<int(a.size());i++) {
            if(ManjiIliJednak(a.at(i-1), a.at(i)) && Stepen(a.at(i-1)) && Stepen(a.at(i))) {
                std::vector<int>b;
                b.push_back(a.at(i-1));
                
                for(int j=i; j<a.size();j++) {
                    if(j==a.size()-1) i=a.size();
                    if(ManjiIliJednak(a.at(j-1), a.at(j)) && Stepen(a.at(j-1)) && Stepen(a.at(j))) {
                        b.push_back(a.at(j));
                    }
                    else {
                        i=j;
                        break;
                    }
                }
                d.push_back(b);
            }
        }
        
    }
    
    else { //O P A D A J U C I
        
          for(int i=1; i<int(a.size());i++) {
            if(Veci(a.at(i-1), a.at(i)) && Stepen(a.at(i-1)) && Stepen(a.at(i))) {
                
                std::vector<int>b;
                b.push_back(a.at(i-1));
                
                for(int j=i; j<a.size();j++) {
                    if(j==a.size()-1) i=a.size();
                    if(Veci(a.at(j-1), a.at(j)) && Stepen(a.at(j-1)) && Stepen(a.at(j))) {
                        b.push_back(a.at(j));
                    }
                    else {
                        i=j;
                        break;
                    }
                }
                d.push_back(b);
            }
        }
        
    }
    
    return d;
    
}

int main() {
    std::vector<int> k;
    int n;
    std::deque<std::vector<int>> vrati;
    
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++) {
        int broj;
        std::cin>>broj;
        k.push_back(broj);
    }
    
    int izaberi;
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>izaberi;
    int i,j;
    
    if(izaberi==1) {
        std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        vrati = MaksimalniPodnizoviStepenaDvojke(k, Rastuci);
        for(i=0;i<int(vrati.size());i++) {
            for(j=0; j<int(vrati.at(i).size()); j++){
                std::cout<<vrati.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
        
    }
    
    if(izaberi==2) {
        std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        vrati = MaksimalniPodnizoviStepenaDvojke(k, Opadajuci);
        for(i=0;i<int(vrati.size());i++) {
            for(j=0; j<int(vrati.at(i).size()); j++){
                std::cout<<vrati.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
    
    return 0;
    
}
















