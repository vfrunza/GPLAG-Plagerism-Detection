/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

/*int ternarni(int n){
	int suma=0;
	int k=1;
	while(n!=0){
		int tern=n%3;
		suma=tern*k+suma;
		n/=3;
		k*=10;
	}
	return suma;
}*/

std::vector<int>IzdvojiGadne(std::vector<int>v, bool a){
	std::vector<int>novi;
	int br2, br1, br0;
	for(int i=0;i<v.size();i++){
		int t=v[i];
		br2=0;
		br1=0;
		br0=0;
		//std::cout<<t<<" ";
		while(t!=0){
			int cifra=t%3;
		    cifra=abs(cifra);
			if(cifra==2) br2++;
			else if(cifra==1) br1++;
			else if(cifra==0) br0++;
			t/=3;
		}
		if(br0%2==0 && br1%2==0 && br2%2==0 && a==true) 
		{
			bool ima=1;
			for(int j=0;j<novi.size();j++) {
			if(v[i]==novi[j]){
				ima=0;
				break;
			}
			} if(ima) novi.push_back(v[i]);
		}
		else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0) && a==false){
			bool ima=1;
			for(int j=0;j<novi.size();j++){
				if(v[i]==novi[j]){
					ima=0;
					break;
				}
			}
			if(ima) novi.push_back(v[i]);
		}
	}
	return novi;
}

int main (){
	int k;
	std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>k;
		if(k==0) break;
		v.push_back(k);
	}while(k!=0);
	
	std::vector<int>par,ne;
	par=IzdvojiGadne(v, true);
	ne=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<par.size();i++){
		std::cout<<par[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";

	for(int i=0;i<ne.size();i++){
		std::cout<<ne[i]<<" ";
	}
	return 0;
}