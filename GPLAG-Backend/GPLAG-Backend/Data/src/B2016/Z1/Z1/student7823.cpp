#include <iostream>
#include <vector>

std::vector<int> Pretvanje(int n){ 		//Ovo radi
	std::vector<int> v{};
	int modul{};
	while (n!=0){
		modul=n%3;
		n=n/3;
		v.push_back(modul);
	}
	return v;
}
/*std::vector<int> Izbacivanje(std::vector<int> v){
	std::vector<int> b{};
	b.push_back(v[0]);
	return v;
} */
int Provjera(int n){	//I ovo radi
	if(n==0) return 1;
	std::vector<int> a{Pretvanje(n)};
	int broj{},brojac0{},brojac1{},brojac2{};
	for(int i=0; i<a.size(); i++){
		broj=a[i];
		
		for(int j=0; j<a.size();j++){
			if(broj==a[j] && broj==0){brojac0++;}
			if(broj==a[j] && broj==1){brojac1++;}
			if(broj==a[j] && broj==2){brojac2++;}
		}
	}
	if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0) {return 2;}
	if(brojac0==0) brojac0=1;
	if(brojac1==0) brojac1=1;
	if(brojac2==0) brojac2=1;
	if(brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) {return 1;}
	return 0;
}

std::vector<int> IzdvojiGadne(std::vector<int> a, bool cs){
	std::vector<int> b{};
	if(cs==true){
		for(int i=0;i<a.size();i++){
			int broj{std::abs(a[i])};
			if(Provjera(broj)==2){
				if(b.size()==0) b.push_back(a[i]);
				else{
						bool ispit=false;
					for(int j=0; j<b.size();j++){
					
						if(a[i]==b[j]) ispit=true;
					
					}
					if(ispit==false){
							b.push_back(a[i]);
				}
			}
		}
		}
		return b;
	}
	
	if(cs==false){
		for(int i=0;i<a.size();i++){
			int broj=a[i];
			if(Provjera(broj)==1){

				if(b.size()==0) b.push_back(a[i]);
				else{
						bool ispit=false;
					for(int j=0; j<b.size();j++){
					
						if(a[i]==b[j]) ispit=true;
					
					}
					if(ispit==false){
							b.push_back(a[i]);
				}
			}
		}
		}
		return b;
	}
	return b;
}

int main (){

	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	std::vector<int> a;
	
	while(std::cin>>broj, broj!=0) {
		a.push_back(broj);
	}
	std::vector<int> b{IzdvojiGadne(a,true)};
	std::cout<<"Opaki: ";
	for(int k: b) std::cout<<k<<" ";
	
	std::cout<<std::endl;
	std::vector<int> c{IzdvojiGadne(a,false)};
	std::cout<<"Odvratni: ";
	for(int j: c) std::cout<<j<<" ";

	return 0;
}