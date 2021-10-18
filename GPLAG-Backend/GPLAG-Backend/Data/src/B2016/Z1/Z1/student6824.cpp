#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> v, bool p){
	std::vector<int>v1;
	if(v.size()==0){
		return v;
	}
	for(int i=0; i<v.size()-1; i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	int brojac0{0}, brojac1{0}, brojac2{0}, ostatak, broj, ind{0}, pokaz{0};
	for(int i=0; i<v.size(); i++){
		broj=v[i];
		if(broj<0) broj=broj*(-1);
		ind=0;
		brojac0=0;
		brojac1=0;
		brojac2=0;
		if(broj==0) brojac0++;
		else{
			while(broj>0){
				ostatak=broj%3;
				broj=(broj-ostatak)/3;
				if(ostatak==0) brojac0++;
				 else if(ostatak==1) brojac1++;
				  else brojac2++;
			}
		}
		if(p==true){
			if(brojac0>0){
			 if(brojac0%2==0) ind++;
			 else pokaz=1;
			}
			if(brojac1>0){
				if(brojac1%2==0) ind++;
				else pokaz=1;
			} 
			if(brojac2>0){
				if(brojac2%2==0) ind++;
				else pokaz=1;
			} 
			if(pokaz==1){pokaz=0;}
			else v1.push_back(v[i]);
		}
		else{
			if(brojac0>0){
				if(brojac0%2!=0) ind++;
				else continue;
			}
			if(brojac1>0){
				if(brojac1%2!=0) ind++;
				else continue;
			}
			if(brojac2>0){
				if(brojac2%2!=0) ind++;
				else continue;
			}
			if(ind>0) v1.push_back(v[i]);
		}
	}
	return v1;
}
int main (){
    std::vector<int>v;
    int broj;
    std::cout <<"Unesite brojeve (0 za prekid unosa): ";
    do{
    	std::cin >>broj;
    	if(broj==0) break;
    	v.push_back(broj);
     }while(broj!=0);
    std::vector<int>v1;
    v1=IzdvojiGadne(v,true);
    std::cout <<"Opaki: ";
     for(int i=0; i<v1.size(); i++){
    	std::cout <<v1[i]<<" ";
    }
    std::cout <<std::endl<<"Odvratni: ";
    v1=IzdvojiGadne(v,false);
    for(int i=0; i<v1.size(); i++)
     std::cout<<v1[i]<<" ";
	return 0;
}