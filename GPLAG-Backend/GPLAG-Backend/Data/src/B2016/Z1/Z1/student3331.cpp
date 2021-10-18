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


std::vector<int> PretvoriTernarno(int broj){

std::vector<int> ternarno;
if(broj == 0){
	ternarno.push_back(0);
	return ternarno;
}
else{
while(broj){
	int ternarniZapis = broj%3;
	ternarno.push_back(std::fabs(ternarniZapis));
	broj/=3;
}
}
	return ternarno;
}


bool jelOpak(int broj) {
	std::vector<int> pretvoren = PretvoriTernarno(broj);
	int cifra =0;
	bool parno = true;
	std::vector<int> brojaci(3);
	int randomBroj =0;
	for(int i=0; i<pretvoren.size(); i++) {
		cifra = pretvoren[i];
		if(cifra == 0) brojaci[0]++;
		else if(cifra == 1) brojaci[1]++;
		else if(cifra == 2) brojaci[2]++;
		else randomBroj++;
		
	}
	
	for(int koliko : brojaci) if(koliko%2 != 0  || randomBroj != 0){parno = false; break;}
	
	if(parno) return true;
	return false;
}


bool jelOdvratan(int broj){
	std::vector<int> pretvoren = PretvoriTernarno(broj);
	int cifra =0;
	bool neparno = true;
	std::vector<int> brojaci(3);
	int randomBroj=0;
	for(int i=0; i<pretvoren.size(); i++) {
		cifra = pretvoren[i];
		if(cifra == 0) brojaci[0]++;
		else if(cifra == 1) brojaci[1]++;
		else if(cifra == 2) brojaci[2]++;
		else  randomBroj++;
		
	}
	
	for(int koliko : brojaci) if((koliko%2 == 0 && koliko != 0) || randomBroj !=0){neparno = false; break;}
	
	if(neparno) return true;
	return false;
}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool kojaVrsta){
	std::vector<int> gadni;
	
	if(kojaVrsta){
		for(int broj : v) if(jelOpak(broj)) gadni.push_back(broj);
	}
	else if(!kojaVrsta){
		for(int broj : v) if(jelOdvratan(broj)) gadni.push_back(broj);
	}
	
	for(int i=0; i< int(gadni.size()); i++){
		for(int j=0; j< int(gadni.size()); j++) 
		if(i != j && gadni[i] == gadni[j]){ gadni.erase(gadni.begin()+j); j--; } 
	}
	
	return gadni;
}

int main () {
    std::vector<int> v;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    int element;
    do{
    	std::cin>>element;
    	if(element == 0) break;
    	v.push_back(element);
    	
    }while (true);
    	
    std::vector<int> gadniBrojevi = IzdvojiGadne(v,true);
    
    std::cout<<"Opaki: ";
    for(int br: gadniBrojevi) std:: cout<<br<<" ";
    std::cout<<std::endl;
    
     std::vector<int> gadni = IzdvojiGadne(v,false);
    
    std::cout<<"Odvratni: ";
    for(int br: gadni) std:: cout<<br<<" ";
	
	return 0;
}