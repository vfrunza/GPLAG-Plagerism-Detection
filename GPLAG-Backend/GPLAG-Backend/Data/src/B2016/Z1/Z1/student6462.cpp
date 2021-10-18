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

std::vector<int> IzbrisiPonavljanja(std::vector<int> v){
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i]==v[j]) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

int PrebrojiCifre(int broj){
	int broj_cifara=0;
	while(broj!=0){
		broj/=10;
		broj_cifara++;
	}
	return broj_cifara;
}

std::vector<int> DekadniUTernarni(int n){
	long long int broj=n;
	if(broj<0) broj*=-1;
	std::vector<int> ternarni;
	int kolicnik=broj/3;
	int ostatak=broj%3;
	broj/=3;
	ternarni.push_back(ostatak);
	while(kolicnik!=0){
		kolicnik=broj/3;
		ostatak=broj%3;
		broj/=3;
		ternarni.push_back(ostatak);
	}
	return ternarni;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool kategorija){
	v=IzbrisiPonavljanja(v);
	std::vector<int> konacni;
	if(kategorija==true){
		for(int i(0); i<v.size(); i++){
			bool opak(true);
			std::vector<int> cifre=DekadniUTernarni(v[i]);
			
			if(cifre.size()%2!=0) opak=false;
			else{
				std::vector<int> brojaci(3);
				for(int i=0; i<cifre.size(); i++){
					brojaci[cifre[i]]++;
				}
				for(int i=0; i<brojaci.size(); i++){
					if(brojaci[i]%2!=0) {
						opak=false;
						break; 
					}
				}
				if(opak==true) konacni.push_back(v[i]);
				
	     	}
	}
	return konacni;
    }
    
    if(kategorija==false){
    	for(int i(0); i<v.size(); i++){
			bool odvratan(true);
			std::vector<int> cifre=DekadniUTernarni(v[i]);
			std::vector<int> brojaci(3);
		
			for(int i=0; i<cifre.size(); i++){
				brojaci[cifre[i]]++;
			}
			for(int i=0; i<brojaci.size(); i++){
				if(brojaci[i]%2==0 && brojaci[i]!=0) {
					odvratan=false;
					break; 
				}
			}
			if(odvratan==true) konacni.push_back(v[i]);
				
        }
        return konacni;
  
}
}


int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int broj(1);
	while(broj!=0){
		std::cin >>broj;
		if(broj==0) break;
		v.push_back(broj);
	}
	std::vector<int> v1=IzdvojiGadne(v,1);
	std::cout << "Opaki: ";
	for(int i=0; i<v1.size(); i++){
		std::cout <<v1[i]<<" ";
	}
	std::vector<int> v2=IzdvojiGadne(v,0);
	std::cout <<std::endl<< "Odvratni: ";
	for(int i=0; i<v2.size(); i++){
		std::cout << v2[i]<<" ";
	}
	
	return 0;
}