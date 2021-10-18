#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci=1,Opadajuci=2};

typedef std::vector <int> Vektor;

bool DaLiJeStepenDvojke(int x) {    //funkcija za provjeravanje brojeva da li su stepeni dvojke
    while(x%2==0) {
        x/=2;
    }
    if(x==1) return true;
    return false;
}


std::deque<Vektor> MaksimalniPodnizoviStepenaDvojke(Vektor v1, enum Smjer s) {
    std::deque<Vektor> d ;
    int a;
   switch(s) {
        case Rastuci:
        a=1;
        int j;
        for(int i=0;i<v1.size();i++){
            d.resize(i+1);
            for(j=a;j<v1.size();j++){
                if(DaLiJeStepenDvojke(v1.at(j))){
                    if(v1.at(j-1)<=v1.at(j)) d.at(i).push_back(v1.at(j-1));
                    else{
                        d.at(i).push_back(v1.at(j-1));
                        a=j+1;
                        break;
                    }
                }
                else{
                    a=j+1;
                    break;
                }
                if(j==v1.size()-1){
                    if(v1.at(j)>=v1.at(j-1) && DaLiJeStepenDvojke(v1.at(j))) d.at(i).push_back(v1.at(j));
                }
            }
            if(j==v1.size()-1) break;
        }

        break;
        case Opadajuci:
        a=0;
        for(int i=0;i<v1.size()-1;i++){
            d.resize(i+1);
            for(j=a;j<v1.size()-1;j++){
                if(DaLiJeStepenDvojke(v1.at(j))){
                    if(v1.at(j)>=v1.at(j+1)) d.at(i).push_back(v1.at(j));
                    else{
                        d.at(i).push_back(v1.at(j));
                        a=j+1;
                        break;
                    }
                }
                else{
                    a=j+1;
                    break;
                }
                if(j==v1.size()-2){
                    if(v1.at(j+1)<=v1.at(j) && DaLiJeStepenDvojke(v1.at(j+1))) d.at(i).push_back(v1.at(j+1));
                }
            }
            if(j==v1.size()-1) break;
        }
        break;
   }
   for(int i=0;i<d.size();i++){
       if(d.at(i).size()==0 || d.at(i).size()==1) d.erase(d.begin()+i);
   }

        return d;
    }

    int main() {
        std::deque<Vektor> d;
        Vektor v1;
        int x, br_el;
        std::cout<<"Unesite broj elemenata vektora: ";
        std::cin>>br_el;
        std::cout<<"Unesite elemente vektora: ";
        for(int i=0; i<br_el; i++) {
            int broj;
            std::cin>>broj;
            v1.push_back(broj);
        }
        std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
        do {
            std::cin>>x;
            if(x>2 || x<1) std::cout<<"Neispravan unos! Pokusajte ponovo: ";
        } while(x<1 || x>2);
        if(x==1) {
            d=MaksimalniPodnizoviStepenaDvojke(v1,Rastuci);
            std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        } else {
            d=MaksimalniPodnizoviStepenaDvojke(v1,Opadajuci);
            std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        }
        for(auto x : d) {
                 if(x.size()==1 || x.size()==0){
                   continue;
             }
            for(int j=0; j<x.size(); j++) {
                std::cout<<x.at(j)<<" ";
            }
            std::cout<<std::endl;
        }
        return 0;
    }