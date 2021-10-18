/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>

bool DaLiJeOpak(int b){
	std::vector<int>v(3, 0);
	long long int a=b;
	if(a==0)return false;
	if(a<0)a=-a;
	while(a){
		v[a%3]++;
		a=a/3;
	}
	for(auto i:v){
		if(i!=0){
			if(i%2!=0)return false;
		}
	}
	return true;
}

bool DaLiJeOdvratan(int b){
	std::vector<int>v(3, 0);
	long long int a=b;
	if(a==0)return true;
	if(a<0)a=-a;
	while(a){
		v[a%3]++;
		a=a/3;
	}
	for(auto i:v){
		if(i!=0){
			if(i%2==0)return false;
		}
	}
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	std::vector<int> r;
	for(auto i:v){
		if(a==1){
			if(DaLiJeOpak(i)){
				bool imal=false;
				for(auto j:r){
					if(j==i){
						imal=true;
						break;
					}
				}	
				if(imal==false)r.push_back(i);
			}
		} else {
			if(DaLiJeOdvratan(i)){
				bool imal=false;
				for(auto j:r){
					if(j==i){
						imal=true;
						break;
					}
				}	
				if(imal==false)r.push_back(i);
			}
		}
	}
	return r;
}

int main ()
{
	std::vector<int> b;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int a;
	do{
		std::cin>>a;
		if(a==0)break;
		b.push_back(a);
	}while(true);
	std::vector<int> c;
	c=IzdvojiGadne(b, 1);
	std::cout<<"Opaki: ";
	for(auto i:c){
		std::cout<<i<<" ";
	}
	c=IzdvojiGadne(b, 0);
	std::cout<<"\nOdvratni: ";
	for(auto i:c){
		std::cout<<i<<" ";
	}
	return 0;
}