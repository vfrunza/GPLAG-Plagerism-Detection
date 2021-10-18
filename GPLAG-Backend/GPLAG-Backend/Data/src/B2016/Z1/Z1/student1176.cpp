#include <iostream> 
#include <vector>
int Konverzija(int n){
	int x, t(0), o, i(1); 
	if(n<0){
		x=-1;
		n*=(-1);
	}   
	else x=1;
	while(n!=0){
		o=n%3; 
		n/=3;  
		t+=o*i;
		i*=10;
	} 
	return t*x;
} 
int Prebroj(int n){ 
	if(n<0) n*=(-1);
	std::vector<int> cifre(3, 0);
	while(n!=0){  
		for(int i(0); i<cifre.size(); i++){
			if(n%10==i) cifre[i]++;
		}
		n/=10;
	} 
	int br_parnih(0), br_neparnih(0); 
	for(int i(0); i<cifre.size(); i++){
		if(cifre[i]%2==0 && cifre[i]!=0) br_parnih++; 
		else if(cifre[i]%2!=0) br_neparnih++;
	}
	if(br_parnih!=0 && br_neparnih==0) return 1;
	else if(br_parnih==0 && br_neparnih!=0) return 2;
}
std::vector<int> IzdvojiGadne(std::vector<int> a, bool test){ 
	std::vector<int> b; 
	std::vector<int> pomocni; 
	pomocni.resize(a.size());
	for(int i=0; i<a.size(); i++){
		pomocni[i]=Konverzija(a[i]);
	}
	if(test==true){
		for(int i=0; i<pomocni.size(); i++){ 
			if(Prebroj(pomocni[i])==1) b.push_back(a[i]);
		}
	} 
	if(test==false){
		for(int i=0; i<pomocni.size(); i++){
			if(Prebroj(pomocni[i])==2) b.push_back(a[i]);
		}
	}   
	for(int i=0; i<b.size()-1; i++){
		for(int j=i+1; j<b.size(); j++){
			if(b[i]==b[j]){
				b.erase(b.begin()+j); 
				j--;
			}
		}
	} 
	return b;
} 

int main ()
{
	std::vector<int> a; 
	std::vector<int> b;
	std::vector<int> c;
	int n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin >> n;
		if(n==0) break;
		else a.push_back(n);
	}
	b=IzdvojiGadne(a, true);
	c=IzdvojiGadne(a, false); 
	std::cout << "Opaki:";
	for(int i=0; i<b.size(); i++) std::cout << " " << b[i];  
	std::cout << std::endl;
	std::cout << "Odvratni:";
	for(int i=0; i<c.size(); i++) std::cout << " " << c[i]; 
	return 0;
}