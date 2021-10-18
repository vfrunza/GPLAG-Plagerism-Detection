#include <iostream>
#include <vector>
#include <deque>

std::vector<int> IzdvojiGadne (std::vector<int> v,bool x) {
	std::deque<int> moduli;
	std::vector<int> brojac{0,0,0},opaki,odvratni;
		
	for(int i=0;i<v.size();i++) {
		if(v[i]==0) {v.erase(v.begin()+i); i--; }
	}
	
	for(int i=0;i<(v.size()-1);i++) {
			for(int j=i+1;j<v.size();j++) {
				if(v[i]==v[j]) {v.erase(v.begin()+j); j--;}
			}
		}
		
		moduli.resize(0);
	
	for(int i=0;i<v.size();i++) {
		int temp{v[i]};
		while(temp !=0) {
			moduli.push_front(temp%3);
			temp/=3;
		}
		
		
		
		brojac={0,0,0};
		
		for(int j=0;j<moduli.size();j++) {
			if(moduli[j]==0) brojac[0]++ ;
			else if(moduli[j]==1) brojac[1]++ ;
			else if(moduli[j]==2) brojac[2]++ ;
		}
		
	
		if(brojac[0]%2==0 && brojac[1]%2==0 && brojac[2]%2==0) opaki.push_back(v[i]);
		else if(brojac[0]%2==1 && brojac[1]%2==1 && brojac[2]%2==1) odvratni.push_back(v[i]);
		else if(brojac[0]%2==1 && brojac[1]%2==1 && brojac[2]==0) odvratni.push_back(v[i]);
		else if(brojac[0]%2==1 && brojac[2]%2==1 && brojac[1]==0) odvratni.push_back(v[i]);
		else if(brojac[1]%2==1 && brojac[2]%2==1 && brojac[0]==0) odvratni.push_back(v[i]);
		else if(brojac[0]%2==1 && brojac[1]==0 && brojac[2]==0) odvratni.push_back(v[i]);
		else if(brojac[1]%2==1 && brojac[0]==0 && brojac[2]==0) odvratni.push_back(v[i]);
		else if(brojac[2]%2==1 && brojac[0]==0 && brojac[1]==0) odvratni.push_back(v[i]);
		
		
		moduli.resize(0); brojac={0,0,0}; 
 	}
	if(x==true) return opaki;
	else if(x==false) return odvratni;

}	



int main () {
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	std::vector<int> v;
	int n;
	
	do {
		std::cin>>n;
		v.push_back(n);
	} while(n!=0);

	
	std::vector<int> odvratni;
	std::vector<int> opaki;
	
	opaki=IzdvojiGadne(v,true);
	odvratni=IzdvojiGadne(v,false);

	std::cout<<"Opaki: ";
	for(int x:opaki) std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int x:odvratni) std::cout<<x<<" ";
	

	
	return 0;
}