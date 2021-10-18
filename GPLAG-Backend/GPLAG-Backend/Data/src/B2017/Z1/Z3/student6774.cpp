#include<iostream>
#include<vector>
#include<deque>
#include <cmath>
void IzbaciDuplikate(std::vector<int> &s){
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s.at(i)==s.at(j)){
                for(int k=j+1;k<s.size();k++){
                    s.at(k-1)=s.at(k);
                }
                s.resize(s.size()-1);
                j--;
            }
        }
    }
}

bool provjeri(int n){
    for(int i=0;i<32;i++){
        if(pow(2,i)==n)return true;
    }
    return false;
} 

enum Smjer{Rastuci,Opadajuci};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v ,enum Smjer a){
    int b=1;
    if(a==Rastuci) b=1;
    if(a==Opadajuci) b=0;
    std::deque<std::vector<int>> rtn;
    std::vector<int> temp;
    int k=0;
    if(b==1){
        for(int i=0;i<v.size();i++){
          if(provjeri(v.at(i))==true){
              if(k==0){
                  temp.push_back(v.at(i));
                  k++;
              }
                  else{
                      if(v.at(i)>=temp.at(k-1)){
                          temp.push_back(v.at(i));
                          k++;    
                      }
                      else if(k>1){
                          rtn.push_back(temp);
                          k=0;
                          temp.resize(0);
                          i--;
                      }
                      else{
                          k=0;
                          temp.resize(0);
                          i--;
                      }
                  }
              }
                 else{
                     if(k>1){
                         rtn.push_back(temp);
                          k=0;
                          temp.resize(0);
                     }
                    else{
                        k=0;
                         temp.resize(0);
                    }
                 }
          
        }
    }
    if(b==0){
        for(int i=0;i<v.size();i++){
          if(provjeri(v.at(i))==true){
              if(k==0){
                  temp.push_back(v.at(i));
                  k++;
              }
                  else{
                      if(v.at(i)<=temp.at(k-1)){
                          temp.push_back(v.at(i));
                          k++;    
                      }
                      else if(k>1){
                          rtn.push_back(temp);
                          k=0;
                          temp.resize(0);
                          i--;
                      }
                      else{
                          k=0;
                          temp.resize(0);
                          i--;
                      }
                  }
              }
                 else{
                     if(k>1){
                         rtn.push_back(temp);
                          k=0;
                          temp.resize(0);
                     }
                    else{
                        k=0;
                         temp.resize(0);
                    }
                 }
          
        }
     }
    
     if(k>1)rtn.push_back(temp);
     for(int cs=0;cs<rtn.size();cs++){
         IzbaciDuplikate(rtn.at(cs));
     }
     
     
    return rtn;
}

int main(){
    enum Smjer a;
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: " ;
    int s;
    std::vector<int> c;
    for(int i=0;i<n;i++){
        std::cin >> s;
        c.push_back(s);        
    }
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int ss;
    do{
    std::cin >> ss;
    if(ss!=1&&ss!=2)std::cout << "NISTE UNJELI BROJ 1 ILI 2" << std::endl;
    }while(ss!=1&&ss!=2);
    if(ss==1)a=Rastuci;
    if(ss==2)a=Opadajuci;
    std::deque<std::vector<int>> fsd=MaksimalniPodnizoviStepenaDvojke(c,a);
    if (ss==1)std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    if(ss==2)std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    for(int i=0;i< fsd.size();i++){
        for(int j=0;j<fsd.at(i).size();j++){
            std::cout <<fsd.at(i).at(j)<<" ";
        }
        std::cout << std::endl;
    }
    return 0;
}