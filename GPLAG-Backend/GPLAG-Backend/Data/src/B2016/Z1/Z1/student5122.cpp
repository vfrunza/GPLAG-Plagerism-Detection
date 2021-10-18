#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


std::vector<int> OdstraniDuplikate(std::vector<int> k){
    for(int i=0; i<k.size()-1; i++){
        for(int j=i+1; j<k.size(); j++){
            if(k[i]==k[j]){
                k.erase(k.begin()+j);
                if(i!=0){
                i--;
                    
            }
                
        }
    }
}

return k;
}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool t){
    if(v.size()==0) return std::vector<int>(v.size());
    std::vector<int> n;
    n=OdstraniDuplikate(v);
    if(t){
        std::vector<int> v1;
        std::vector<int> t1;
        int temp;
        for(int i=0; i<n.size(); i++){
            temp=n[i];
            int brojac(0),brojac1(0),brojac2(0);
            while(n[i]!=0){
                int modul;
                modul=abs(n[i])%3;
                if(modul==2) brojac2++;
                if(modul==1) brojac1++;
                if(modul==0) brojac++;
                n[i]=n[i]/3;
                
            }
            if(brojac1%2==0 && brojac2%2==0 && brojac%2==0){
                    v1.push_back(temp);
                }
                
            }
            
            return v1;
        }
        else{
        std::vector<int>v2;
        std::vector<int>t2;    
        int temp;
        for(int i=0; i<n.size(); i++){
            temp=n[i];int brojac(0),brojac1(0), brojac2(0);
            while(n[i]!=0){
                int modul;
                modul=abs(n[i])%3;
                if(modul==2) brojac2++;
                if(modul==1) brojac1++;
                if(modul==0) brojac++;
                n[i]=n[i]/3;
            }
                if((brojac1%2!=0 && brojac2%2!=0 && brojac%2!=0) || (brojac1%2!=0 && brojac2%2!=0 && brojac==0) || (brojac1%2!=0 && brojac%2!=0 && brojac1==0) || (brojac1%2!=0 && brojac%2!=0 && brojac2==0) || (brojac%2!=0 && brojac1==0 && brojac2==0) || (brojac==0 && brojac1%2!=0 && brojac2==0) || (brojac==0 && brojac1==0 && brojac2%2!=0)){
                    v2.push_back(temp);
                }
               
                }
                return v2;
            }
}
        


int main ()
{
    std::vector<int> v;
    int n;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    do{
        std::cin>>n;
        if(n!=0)
        v.push_back(n);
    }
    while(n!=0);
    std::vector<int> v1,v2;
    v1=IzdvojiGadne(v,1);
	v2=IzdvojiGadne(v,0);
	std::cout<<"Opaki: ";
	for(int i=0; i<v1.size(); i++){
	    std::cout<<v1[i]<<" ";
	} std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<v2.size(); i++){
	    std::cout<<v2[i]<<" ";
	}
	return 0;
}