/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int>IzdvojiGadne(std::vector<int>v, bool a) {
	std::vector<int>novivektor;
	std::vector<int>brojac(3,0);
	std::vector<int>skuplja;
	int cifra;
	for(int i(0); i<v.size(); i++) {
		int isti_op(0),isti_od(0);
		int opaki(0),odvratni(0);
		int broj=v[i];
		while(broj!=0) {
		cifra=broj%3;
		skuplja.push_back(cifra);
		broj/=3;
		}
		
		
		
	for(int j=0; j<3; j++) brojac[j]=0;
	
	

	for(int z(0); z<skuplja.size();z++){ brojac[abs(skuplja[z])]++;
	 }
	 
	 
	
		
	for(int j(0);j<3; j++) {
		if(brojac[j]%2==0) opaki++;
	}
		if (opaki==3 && a==true) {
			for(int s(0);s<novivektor.size();s++) {
				if(v[i]==novivektor[s]) isti_op=1;
			}
			if(isti_op==0) novivektor.push_back(v[i]);
			
	}
	
	
	for(int k(0);k<3; k++) {
		if(brojac[k]%2!=0 || brojac[k]==0) odvratni++;
	}
		//std::cout<<odvratni;
		
		if (odvratni==3 && a==false) {
			for(int s=0; s<novivektor.size();s++) {
				if(v[i]==novivektor[s]) isti_od=1;
			}
			if(isti_od==0) novivektor.push_back(v[i]);
		
	}
	
	
	
	skuplja.resize(0);
	
	}


return novivektor;
}


int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int n;
	std::cin>>n;
	while(n!=0){
		v.push_back(n);
		std::cin>>n;
		
	}
	std::vector<int> opaki;
	opaki=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i(0); i<opaki.size();i++) 
	std::cout<<opaki[i]<<" ";
	std::cout<<std::endl;
	
	std::vector<int>odvratni;
	odvratni=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	for(int i(0); i<odvratni.size();i++) 
	std::cout<<odvratni[i]<<" ";
	
	return 0;
}