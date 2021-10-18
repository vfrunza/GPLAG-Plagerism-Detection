/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include <vector>
long long int obrni_broj(long long int n) {
long long	int broj(0);
	while(n!=0){
		broj=broj*10+n%10;
		n/=10;
		
	}
	return broj;
}
	long long int pretvori_u_ternarni(long long int n) {
long long	int broj(1);
	if(n<0) n=-n;
	while(n!=0) {
		 broj=broj*10+n%3;
		 n/=3;
	}

	long long	int broj1(obrni_broj(broj));
	return broj1/10;
}
int parni(long long int n) {
	if(n<0) n=-n;
	int v[20]={0};
	while(n!=0) {
		v[n%10]++;
		n/=10;
	}
	for(int i(0);i<20;i++) {
		if(v[i]!=0 && v[i]%2==1) return 0;
		
	}
	return 1;
}
 int neparni(long long int n) {
	if(n<0)n=-n;
	int v[20]={0};
		while(n!=0) {
		v[n%10]++;
		n/=10;
	}
	for(int i(0);i<20;i++) {
		if(v[i]!=0 && v[i]%2==0) return 0;
		
	}
	return 1;
}
std::vector<int> IzdvojiGadne(std::vector<int> V, bool n) {
	std::vector<int> NV;
	if(n==true) {
		for(int i(0);i<V.size();i++) {
			bool ispisi=true;
			if(parni(pretvori_u_ternarni(V[i]))) {
				for(int j(0);j<i;j++) {
					if(V[i]==V[j]) ispisi=false;
					
				}
				if(ispisi) NV.push_back(V[i]);
			}
		}
	}
	if(n==false) {
		for(int i(0);i<V.size();i++) {
			bool ispisi=true;
			if(neparni(pretvori_u_ternarni(V[i]))) {
				for(int j(0);j<i;j++) {
					if(V[i]==V[j]) ispisi=false;
					
				}
				if(ispisi) NV.push_back(V[i]);
			}
		}
	}
	return NV;
}
int main ()
{ 	std::vector<int> V;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>n;
		if(n!=0) V.push_back(n);
	} while(n!=0);
	std::vector<int> V1;
	V1=IzdvojiGadne(V,true);
	std::vector<int> V2;
	V2=IzdvojiGadne(V,false);
	std::cout<<"Opaki: ";
	for(int i(0);i<V1.size();i++) {
		std::cout<<V1[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i(0);i<V2.size();i++) {
		std::cout<<V2[i]<<" ";
	}
	
	return 0;
}









