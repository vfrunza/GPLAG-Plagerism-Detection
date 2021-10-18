/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<int> vektor;

int IsIt(int x){
	if(x<0) x=std::abs(x);
	vektor Istina(3,0);
	while(x!=0){
		int y(x/3);
		if(std::abs(x-(y*3)) == 0) Istina[0]++;
		else if(std::abs(x-(y*3)) == 1) Istina[1]++;
		else if(std::abs(x-(y*3)) ==2) Istina[2]++;
		x/=3;
		
	}
	if(Istina[0]%2==0 && Istina[1]%2==0 && Istina[2]%2==0) return 1;
	else if((Istina[0]%2!=0 && Istina[1]%2!=0 && Istina[2]==0)|| (Istina[1]%2!=0 && Istina[2]%2!=0 && Istina[0]==0) || (Istina[2]%2!=0 && Istina[0]%2!=0 && Istina[1]==0) || (Istina[0]%2!=0 && Istina[1]%2!=0 && Istina[2]%2!=0) || (Istina[0]%2!=0 && Istina[1]==0 && Istina[2]==0) || (Istina[0]==0 && Istina[1]%2!=0 && Istina[2]==0) || (Istina[0]==0 && Istina[1]==0 && Istina[2]%2!=0)) return 2;
	return 3;
}

vektor IzdvojiGadne(vektor v, bool a){
	vektor x;
	if(a){
		bool istina;
		for(int s : v){
			 if(IsIt(s)==1) {
			 	istina=false;
			 	for(int i=0; i<x.size(); i++){
			 		if(i==x.size()) break;
			 		if(s==x[i]) {
			 			istina=true;
			 			break;
			 		}
			 	}
			 	if(!istina) x.push_back(s);
			 }
		}
	}
	else{
		bool istina(false);
		for(int s : v){
			 if(IsIt(s)==2) {
			 	istina=false;
			 	for(int i=0; i<x.size(); i++){
			 		if(i==x.size()) break;
			 		if(s==x[i]) istina=true;
			 	}
			 	if(!istina) x.push_back(s);
			 }
		}
	}
	return x;
}

int main ()
{
	vektor v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int x;
		std::cin>>x;
		if(x==0) break;
		v.push_back(x);
	}
	vektor a(IzdvojiGadne(v,true));
	vektor b(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int x : a) std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int x : b) std::cout<<x<<" ";
	return 0;
}