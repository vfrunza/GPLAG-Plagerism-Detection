#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>
bool DaLiJe(int broj,bool DaNe){
    int brojac0(0),brojac1(0),brojac2(0);
    std::vector<int>natri ;
        do{
            natri.push_back(fabs(broj%3));
            broj=broj/3;
        }while (broj!=0);
    for (int i = 0; i < natri.size(); i++) {
        if(natri[i]==0){
            brojac0++;
        }
        if(natri[i]==1){
            brojac1++;
        }
        if(natri[i]==2){
            brojac2++;
        }
    }
    if(DaNe){if((brojac2%2==0)&&(brojac0%2==0)&&(brojac1%2==0)){
        return true;
    }
         else {return false;}
    }
    if(!DaNe){ 
        if(brojac2==0){brojac2++;}if(brojac1==0){brojac1++;}if(brojac0==0){brojac0++;}
        if(((brojac2%2==1)&&(brojac0%2==1)&&(brojac1%2==1))){
        return false;}
         else {return true;}
    }
   
    return false;
        
}
std::vector<int>IzdvojiGadne(std::vector<int>cijeli,bool istina){
    std::vector<int>opaki;
    std::vector<int>odvratni;
    if(istina){
        for (int i = 0; i < cijeli.size(); i++) {
           if (DaLiJe(cijeli[i],1)) {
               opaki.push_back(cijeli[i]);
           }
        }
        for (int i = 0; i < opaki.size(); i++) {
        for (int j = i+1; j < opaki.size();j++) {
           
            if(opaki[i]==opaki[j]){opaki.erase(opaki.begin()+j);
                
            }   
        }
    }
      for (int i = 0; i < opaki.size(); i++) {
        for (int j = i+1; j < opaki.size();j++) {
           
            if(opaki[i]==opaki[j]){opaki.erase(opaki.begin()+j);
                
            }   
        }
    }
        return  opaki;
    }
    int brojac(0);
    if(!istina){
        for (int i = 0; i < cijeli.size(); i++) {
           if(!DaLiJe(cijeli[i],0)){
                for (int k = 0; k < opaki.size(); k++) {
                if(cijeli[i]==opaki[k]){brojac++;}
            }if(brojac==0&&cijeli[i]!=0){
               odvratni.push_back(cijeli[i]);
           }}
        }
        for (int i = 0; i < odvratni.size(); i++) {
        for (int j = i+1; j < odvratni.size();j++) {
            if(odvratni[i]==odvratni[j]){odvratni.erase(odvratni.begin()+j);
                
            }   
        }
    }
    for (int i = 0; i < odvratni.size(); i++) {
        for (int j = i+1; j < odvratni.size();j++) {
            if(odvratni[i]==odvratni[j]){odvratni.erase(odvratni.begin()+j);
                
            }   
        }
    }
        return odvratni;
    }
    
    return opaki;
}

int main ()
{
    int b;
    bool tacno(true);
    std::vector<int>brojevi;
    std::vector<int>opaki ;
    std::vector<int>odvratni ;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    do{        
        std::cin >> b;
        brojevi.push_back(b);
    }while(b!=0);
    std::cout << "Opaki: ";
    opaki=IzdvojiGadne(brojevi,tacno);
    for (int i = 0; i < opaki.size(); i++) {
        for (int j = i+1; j < opaki.size();j++) {
            if(opaki[i]==opaki[j]){opaki.erase(opaki.begin()+j);
                
            }   
        }
    }
    for (int i = 0; i <opaki.size(); i++) {
        std::cout << opaki[i] <<" ";
    }
    std::cout << std::endl;
    std::cout << "Odvratni: ";
    odvratni=IzdvojiGadne(brojevi,0);
    
   for (int i = 0; i <odvratni.size(); i++) {
      std::cout << odvratni[i]<<" ";
   }
	return 0;
}