//OVAJ PROGRAM NISAM DOCEKAO DA TESTIRAM 

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer {Rastuci=1, Opadajuci=2};

bool JeLiStepenDvojke(int n){
    int pr(1);
    int br_step(0),x=n;
    while(n!=0){
        n=n/2;
        br_step++;
    }
    for(int i=0;i<br_step-1;i++){
        pr=pr*2;}
    if(pr==x){    
        return true;
    }
    return false;
    }
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v1, Smjer s){
    std::deque<std::vector<int>> d1;
    std::vector<int>v2;
    
    if(s==1){
        for(int i=0;i<v1.size();i++){
            if(i!=v1.size()-1){
                if((v2.size()==0)&&(JeLiStepenDvojke(v1.at(i))==1)&&(v1.at(i)<v1.at(i+1))&&(JeLiStepenDvojke(v1.at(i+1)))){
                    v2.push_back(v1.at(i));
                    if(i<v1.size()-1){
                    i++;}
                }
            }
            if(v2.size()>=1){
                        if((JeLiStepenDvojke(v1.at(i))==1)&&(v1.at(i)>v1.at(i-1))){
                            v2.push_back(v1.at(i));
                
                        }
                            else{
                                d1.push_back(v2);
                                v2.resize(0);
                                i--;
                            }
                        if(i==v1.size()-1) d1.push_back(v2);
            }
        }
    }
    
    if(s==2){
        for(int i=0;i<v1.size();i++){
            if(i!=v1.size()-1){
                if((v2.size()==0)&&(JeLiStepenDvojke(v1.at(i))==1)&&(v1.at(i)>v1.at(i+1))&&(JeLiStepenDvojke(v1.at(i+1)))){
                    v2.push_back(v1.at(i));
                    if(i<v1.size()-1){
                        i++;}
                    }
            }
            if(v2.size()>=1){
                if((JeLiStepenDvojke(v1.at(i))==1)&&(v1.at(i)<v1.at(i-1))){
                    v2.push_back(v1.at(i));
                }
                else{
                    d1.push_back(v2);
                    v2.resize(0);
                    i--;
                }
                if(i==v1.size()-1) d1.push_back(v2);
            }
        }
    }
    
    return d1;
}

int main ()
{
    Smjer s;
    std::deque<std::vector<int>> glavni;
    std::vector<int> v_glavni;
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        v_glavni.push_back(x);
    }
    
    int x;
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>x;
    if(x==1){ s=Rastuci;}
    else{ s=Opadajuci;}
    
    glavni=MaksimalniPodnizoviStepenaDvojke(v_glavni,s);
    

    
        if(x==1){
        std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        for(int i=0;i<=glavni.size()-1;i++){
            for(int j=0;j<=glavni.at(i).size()-1;j++){
                std::cout<<glavni.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
    
  else  if(x==2){
        std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        for(int i=0;i<=glavni.size()-1;i++){
            for(int j=0;j<=glavni.at(i).size()-1;j++){
                std::cout<<glavni.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }

	return 0;
}
