#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> IzbaciVisak(std::vector<int> v){
         if(int(v.size())==0)
         return v;
    for(int i=0;i<int(v.size())-1;i++){
        for(int j=i+1;j<int(v.size());j++){
            if(v[i]==v[j]){
            v.erase(v.begin()+j);
            j--;
        }
        }
    }
    return v;
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool Gadni){
    std::vector<int> v1,v2;
    for(int i=0;i<int(v.size());i++){
      int n=v[i];
      int pomocni=abs(v[i]);
      std::vector<int> TreZap(3,0);
      while(pomocni!=0){
          TreZap[pomocni%3]++;
          pomocni=pomocni/3;
      }
      bool Opak=true;
      for(int j=0;j<3;j++){
          bool Pojavljuje=true;
          if(TreZap[j]==0)
          Pojavljuje=false;
          if(Pojavljuje && TreZap[j]%2!=0){
          Opak=false;
          break;
          }
      }
          bool Odvratan(true);
          for(int j=0;j<3;j++){
              bool Pojavljuje(true);
          if(TreZap[j]==0)
          Pojavljuje=false;
          if(Pojavljuje && TreZap[j]%2==0){
          Odvratan=false;
          break;
          }
          }
          
          if(Opak) v1.push_back(n);
          if(Odvratan) v2.push_back(n);
    }
    v1=IzbaciVisak(v1);
    v2=IzbaciVisak(v2);
    if(Gadni) return v1;
    else return v2;
}

int main(){
    std::vector<int> v;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    int p;
    while(std::cin >> p,p!=0){
        v.push_back(p);
    }
    std::vector<int> m;
    m=IzdvojiGadne(v,true);
    std::cout << "Opaki: "  ;
    for(int i=0;i<int(m.size());i++){
    std::cout << m[i] << " ";
    }
    std::cout <<  std::endl<<"Odvratni: ";
     std::vector<int> n;
    n=IzdvojiGadne(v,false);
    for(int i=0;i<int(n.size());i++){
    std::cout << n[i] << " ";
    }
    return 0;
    
}