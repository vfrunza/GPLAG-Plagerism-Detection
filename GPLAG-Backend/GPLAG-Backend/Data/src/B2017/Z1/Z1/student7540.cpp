//B 2017/2018, Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool Prost(int x){
	for(int i=2; i<=std::sqrt(std::fabs(x)); i++) if(x%i == 0) return false;
	if(x==0) return false;
	return true;
}

int Ternar(int u){
	int vrati{0}, n{std::fabs(u)}, br{0}, x{1};
	for(;;){
		if(x*3>n)break;
		x*=3;
		br++;
	}
	for(int i=br; i>=0; i--){
		vrati*=10;
		vrati+=n/x;
		n-=x*(n/x);
		x/=3;
	}
	if(u<0) vrati*=-1;
	return vrati;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool b){
	std::vector<int> vrati;
		for(int i=0; i<v.size(); i++){
			bool ponovo{false};
			for(int j=0; j<i; j++) if(v.at(j) == v.at(i)) ponovo=true;
			
			if( (b && v.at(i)!=1 && Prost( v.at(i) ) && !ponovo) ||  (!b && !Prost( v.at(i) ) && !ponovo)){
				int n{ Ternar( v.at(i) ) };
				std::vector<int> prov;
				while(n!=0){
					prov.push_back(n%10);
					n/=10;
				}
				bool isti{true};
				for(int k=0; k<prov.size(); k++) if(prov.at(k) != prov.at( prov.size()-k-1 )) isti=false;
				if(isti) vrati.push_back(v.at(i));
			}
		}
	return vrati;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		int n;
		std::cin >> n;
		if(n == -1)break;
		v.push_back(n);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n;
	for(;;){
	    std::cin >> n;
    	if(n==1 || n==0) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	v=IzdvojiSimetricneTernarne(v,n);
	if(v.size()>0 && (n==1 || n==0)){	
		if(n==1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	    else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	    for(int i=0; i<v.size(); i++){
	    	if(i==v.size()-1) std::cout << v.at(i) << ".";
	    	else std::cout << v.at(i) << ", ";
    	}
	}
	else if(v.size()==0){
		if(n==1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		if(n==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}