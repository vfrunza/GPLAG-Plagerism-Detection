#include <iostream>
#include <vector>
#include <math.h>

std::vector<int>IzdvojiGadne(std::vector<int>v,bool a){
    
    int broj=0,broj1,brojcic=0,cifra,brojac0=0,brojac1=0,brojac2=0;
    std::vector<int> v1,v2,v3;
    for(int j=0;j<v.size();j++){ 
        for(int k=j+1;k<int(v.size());k++){  
            if(v[k]==v[j]){
                v.erase(v.begin()+k);
            }
            }
        }
    
    
    for(int i=0;i<int(v.size());i++){   
        broj=v[i];
        
        brojac0=0;brojac1=0;brojac2=0;
        do{

            broj1=broj/3;
            
            cifra=broj-broj1*3;
           
            
            if(cifra==0) brojac0++;
            
            if(cifra==1 || cifra==-1) brojac1++;
            if(cifra==2 || cifra==-2) brojac2++;
            broj=broj/3;
            
            if(broj==0) break;
        }while(broj!=0);
    
        if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0 && v[i]!=brojcic){
            v2.push_back(v[i]);
            
                        
        }

 if(brojac0==0 && brojac2==0 && brojac1%2!=0 || brojac0%2!=0 && brojac2==0 && brojac1==0 || brojac0==0 && brojac2%2!=0 && brojac1==0 || brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0  || brojac0==0 && brojac1%2!=0 && brojac2%2!=0 || brojac1==0 && brojac2%2!=0 && brojac0%2!=0 || brojac2==0 && brojac1%2!=0 && brojac0%2!=0 ){
            if(v[i]!=brojcic)
            v3.push_back(v[i]);
        } 

        brojcic=v[i];

    }
    if(a==1){
        return v2;
    }
    else {
            return v3;
    }
}

int main(){
  
  std::vector<int>v,v1;
 
 
  int broj;
   
  std::cout<<"Unesite brojeve (0 za prekid unosa): ";
        
        do{
		 std::cin>>broj;
		  if(broj!=0)
		 
        v.push_back(broj);
         
        }
        while(broj!=0);
      v1=IzdvojiGadne(v,1);
      std::cout<<"Opaki: ";
      for(int i=0;i<int(v1.size());i++){
      	std::cout<<v1[i]<<" ";
      }
      v1=IzdvojiGadne(v,0);
      std::cout<<std::endl;
      std::cout<<"Odvratni: ";
      for(int i=0;i<int(v1.size());i++){
      	std::cout<<v1[i]<<" ";
      }
	
    return 0;


}
