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

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
//	std::vector<int> ostaci;
	std::vector<int> brojevi;
	std::vector<int> brojaci{0,0,0};
	long long int ostatak, pomocna;
	for(auto x: v){
		brojaci={0,0,0};
		pomocna=x;
		if(pomocna<0){
		do{
		ostatak=fabs(pomocna%3);
		ostatak=static_cast<double>(ostatak);
		ostatak=fabs(ostatak);
		ostatak=static_cast<int>(ostatak);
		brojaci[ostatak]+=1;
//		ostaci.push_back(ostatak);
		pomocna=pomocna/3;
		}while(pomocna!=0);}
		else{
		do{
		ostatak=pomocna%3;
		brojaci[ostatak]+=1;
//		ostaci.push_back(ostatak);
		pomocna=pomocna/3;	
		}while(pomocna!=0);}
//	brojaci={0,0,0};
/*		if(a==true && brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0){
			brojevi.push_back(x);
			brojaci={0,0,0};
		}
		
*/		
		if(a){
		bool test1=1;
		for(auto z: brojaci){
			if(z>0 && z%2!=0) test1=0;
		}
			if(test1){
				if(brojevi.size()==0){
					brojevi.push_back(x);
					brojaci={0,0,0};
				}
				else{
					bool ubaci=1;
					for(auto m: brojevi){
						if(m==x) ubaci=0;
					}
					if(ubaci){
						brojevi.push_back(x);
						brojaci={0,0,0};
					}
				}
		}
			else brojaci={0,0,0};
		}
		
		else if(a==false){
		bool test2=1;
		for(auto z: brojaci){
			if(z>0 && z%2==0) test2=0;
		}
			if(test2){
				if(brojevi.size()==0){
					brojevi.push_back(x);
					brojaci={0,0,0};
				}
				else{
					bool ubaci=1;
					for(auto m: brojevi){
						if(m==x) ubaci=0;
					}
					if(ubaci){
						brojevi.push_back(x);
						brojaci={0,0,0};
					}
				}
		}
			else brojaci={0,0,0};
		}
		
	}
	return brojevi;	
}


int main(){
/*	std::vector<int> v(1);
	std::vector<int> v2;
	v.push_back(67);
	bool a=true;
	v=IzdvojiGadne(v, a);
	for(auto x: v){
		std::cout<<x;
	}
*/

/*	std::vector<int> v;
	  for(int i=000; i<1000; i++){
	  	v.push_back(i);
	  }
	  
	  std::vector<int> a(IzdvojiGadne(v,true));
	  std::vector<int> b(IzdvojiGadne(v,false));
	  
	 std::cout<<std::endl;
	  std::cout<<"Opaki: ";
	 for(int t : b) std::cout<<t<<" ";
//	 std::cout<<a.size()<<" "<<b.size();
*/

	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	std::vector<int> v;
	std::vector<int> v2;
	std::vector<int> v1;
	while(std::cin>>broj,broj!=0){
		v.push_back(broj);
	}
	v1=IzdvojiGadne(v, 1);
		std::cout<<"Opaki: ";
		for(auto x: v1){
			std::cout<<x<<" ";
		}
	std::cout<<std::endl;	
	v2=IzdvojiGadne(v, 0);
		std::cout<<"Odvratni: ";
		for(auto x: v2){
			std::cout<<x<<" ";	
		
	}
	return 0;
}