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


typedef std::vector<int> vektor;
vektor IzdvojiGadne(vektor v, bool t){
	
	if(t){
		
		vektor opak;
		
		for(int x: v){
			vektor a;
	int cifra,brojac1(0),brojac2(0),brojac3(0),broj{};
    int t;
    t=x;
	x=fabs(x);
	while(x!=0){
		for(int i=a.size();i>=0;i--){
	    	if(x==0) break;
		cifra=x%3;
		a.push_back(cifra);
		x/=3;
		
		}
		}
	
	for(int i:a){
			if(i==0)
			brojac1++;
			else if(i==1)
			brojac2++;
			else if(i==2)
			brojac3++;
		}
	
		if(brojac1%2==0 && brojac2%2==0 && brojac3==0 || brojac1%2==0 && brojac3%2==0 && brojac2==0 || brojac2%2==0 && brojac3%2==0 && brojac1==0 || brojac1%2==0 && brojac2%2==0 && brojac3%2==0)
		opak.push_back(t);
		
		}
		
			for(unsigned i(0);i<=opak.size()-1;i++){
			for(unsigned j(i+1);j<=opak.size()-1;j++){
				if(opak[j]==opak[i])
				opak.erase(opak.begin()+j);
				
			}
			}
			return opak;
		}
	
	else{
		vektor odvratan;
		
		for(int x: v){
			vektor a;
	int cifra,brojac1(0),brojac2(0),brojac3(0),broj{};
    int t;
    t=x;
	x=fabs(x);
	while(x!=0){
		for(int i=a.size();i>=0;i--){
	    	if(x==0) break;
		cifra=x%3;
		a.push_back(cifra);
		x/=3;
		
		}
		}
	
	for(int z:a){
			if(z==0)
			brojac1++;
			else if(z==1)
			brojac2++;
			else if(z==2)
			brojac3++;
		}
	
		if(brojac1%2!=0 && brojac2%2!=0 && brojac3==0 || brojac1%2!=0 && brojac3%2!=0 && brojac2==0 || brojac2%2!=0 && brojac3%2!=0 && brojac1==0|| brojac1%2!=0 && brojac2%2!=0 && brojac3%2!=0)
		odvratan.push_back(t);
		
		}
		for(unsigned i(0);i<=odvratan.size()-1;i++){
			  for(unsigned j(i+1);j<=odvratan.size()-1;j++){
				if(odvratan[j]==odvratan[i])
				odvratan.erase(odvratan.begin()+j);
			}
			}

			return odvratan;	
		}
}
			
int main (){
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
		vektor v;
		int i(0),vr(0);
		for(;;){
		std::cin>>vr;
		
		if(vr==0) break;
		v.push_back(vr);
			i++;
		}
		vektor o(IzdvojiGadne(v,true));
	std::cout<<"Opaki: ";
	for(unsigned int i(0);i<=o.size()-1;i++){
	std::cout<<o[i]<<" ";
		
	}
	std::cout<<std::endl;
	vektor od(IzdvojiGadne(v,false));
	std::cout<<"Odvratni: ";
	for(unsigned int i(0);i<=od.size()-1;i++){
	std::cout<<od[i]<<" "; }

	return 0;
}