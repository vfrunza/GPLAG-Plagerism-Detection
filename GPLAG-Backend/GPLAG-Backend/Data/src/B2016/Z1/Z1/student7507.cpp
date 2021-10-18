/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
int PretvoriUTernarni(int n){
	int c=n%3;
	std::cout<<"ternarni= "<<c<<" ";
	return c;
}

std::vector<int> PostojiUVektoru(std::vector<int> v){
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	std::vector<int> v1;
	if(a==true){
		v=PostojiUVektoru(v);
		for(int i=0; i<v.size(); i++){
			std::vector<int> br(3,0);
			bool paran=true;
			int a=fabs(v[i]);
			while(a!=0){
				int c=fabs(a%3);
				//std::cout<<"cifra: "<<c<<" ";
				br.at(c)++;
				//std::cout<<"br= "<<br[c];
				a/=3;
			}
			for(int j=0; j<3; j++){
				if(br[j]==1){
					paran=false;
					break;
				}
				if(br[j]%2!=0){
					paran=false;
					break;
				}
			}
			if(paran==true) v1.push_back(v[i]);
		}
	}
	else if(a==false){
		v=PostojiUVektoru(v);
		for(int i=0; i<v.size(); i++){
			bool neparan=true;
			int a=v[i];
			std::vector<int> br(3);
			while(a!=0){
				int c=fabs(a%3);
				br.at(c)++;
				a/=3;
			}
			for(int j=0; j<3; j++){
				if(br[j]==0) continue;
				if(br[j]%2==0){
					neparan=false;
					break;
				}
			}
			if(neparan == true) v1.push_back(v[i]);
		}
	}
	return v1;
}
int main (){
	std::vector<int> v;
	int n=1;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(n!=0){
		std::cin>> n;
		if(n==0) break;
		v.push_back(n);
	}
	std::vector<int> opaki,odvratni;
	bool a,b;
	a=true;
	b=false;
	opaki=IzdvojiGadne(v,a);
	odvratni=IzdvojiGadne(v,b);
	
	std::cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		std::cout<< opaki[i] << " ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
		std::cout<< odvratni[i] << " ";
	}
	return 0;
}