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

	
std::vector<int> ternarni(int x){
	std::vector<int> tern;
	do {
		int m;
		m=x%3;
		tern.push_back(m);
		x=x/3;
} while(x!=0);
return tern;
}

bool DaLiJeOpak(long int a){
     std::vector<int> p;
     p=ternarni(a);
     for(int i=0; i<p.size(); i++){
     	int brojac(0);
     	for(int j=0; j<p.size(); j++){
     		if(p[j]==p[i]) brojac++;
     	}
     	if(brojac%2!=0) return false;
    } return true;
}


bool DaLiJeOdvratan(long int b){
	std::vector<int> n;
	n=ternarni(b);
	for(int i=0; i<n.size(); i++){
		int brojac(0);
		for(int j=0; j<n.size(); j++){
			if(n[j]==n[i]) brojac++;
		}
		if(brojac%2==0) return false;
	} return true;
}
     
     
     
std::vector<int> IzdvojiGadne(std::vector<int> v, bool t){
	std::vector<int> opaki;
	std::vector<int> odvratni;
	bool ponovljen_broj=true;
	for(int i=0; i<v.size(); i++){
		ponovljen_broj=true;
		if(DaLiJeOdvratan(v.at(i))){
			for(int j=0; j<odvratni.size(); j++){
				if(v[i]==odvratni[j]){
					ponovljen_broj=false;
			        break;
		        }
			}
		        if(ponovljen_broj) odvratni.push_back(v[i]);
		    }
		
       	if(DaLiJeOpak(v.at(i))){
       		for(int k=0; k<opaki.size(); k++){
       			if(v[i]==opaki[k]){
				ponovljen_broj=false;
				break;
			    }
           	}
           	   if(ponovljen_broj) opaki.push_back(v[i]);
       	}
	} if(t) return opaki;
	else return odvratni;
}


int main() {
	std::vector<int> a;
	std::cout <<"Unesite brojeve (0 za prekid unosa): ";
	double br(1);
	const double e(0.001);
	while(fabs(br-0)>e){
		std::cin >> br; 
		if(fabs(br-0)>e) a.push_back(br);
		else break;
	}
	std::cout <<"Opaki: ";
	std::vector<int> opaki;
	opaki=IzdvojiGadne(a, true);
	for(int i=0; i<opaki.size(); i++){
		std::cout<< opaki[i]<< " ";
	}
	std::cout << std::endl;
	std::cout <<"Odvratni: ";
	std::vector<int> odvratni;
	odvratni=IzdvojiGadne(a, false);
	for(int i=0; i<odvratni.size(); i++){
		std::cout<< odvratni[i]<< " ";
	}
	std::cout << std::endl;
	return 0;
}