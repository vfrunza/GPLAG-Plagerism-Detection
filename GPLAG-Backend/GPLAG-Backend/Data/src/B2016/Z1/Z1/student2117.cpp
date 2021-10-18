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
#include<deque>

std::deque<int> DecimalniUTernarni(int n){
	std::deque<int> d;
	
	while(n!=0){
		d.push_front(n%3);
		n/=3;
	}
	
	return d;
}
int PonavljanjaCifre(std::deque<int> d, int n){
	int br_ponavljanja(0);
	for(int i=0; i<d.size(); i++){
		if(d[i]==n) br_ponavljanja++;
	}
	return br_ponavljanja;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	std::vector<int> ponavljanja, opaki, odvratni;
	for(int i=0; i<v.size(); i++){
		std::deque<int> d = DecimalniUTernarni(v[i]);
		for(int j=0; j<d.size(); j++){
			ponavljanja.push_back(PonavljanjaCifre(d, d[j]));
		}
		int brojac1(0), brojac2(0);
		
		for(int x : ponavljanja){
			if(x%2==0) brojac1++;
			else if(x%2!=0) brojac2++;
		}
		if(brojac1==ponavljanja.size() && v[i]!=0){
			opaki.push_back(v[i]);
		}
		else if(brojac2==ponavljanja.size() && v[i]!=0){
			odvratni.push_back(v[i]);
		}
		ponavljanja.resize(0);
	}
	
	for(int i=0; i<opaki.size(); i++){
		for(int j=i+1; j<opaki.size(); j++){
			if(opaki[i]==opaki[j]){
				opaki.erase(opaki.begin()+j);
				j--;
			}
		}
	}
	
	for(int i=0; i<odvratni.size(); i++){
		for(int j=i+1; j<odvratni.size(); j++){
			if(odvratni[i]==odvratni[j]){
				odvratni.erase(odvratni.begin()+j);
				j--;
			}
		}
	}
	
	if(a==true) return opaki;
	return odvratni;
	
}
int main ()
{
	
	std::vector<int> v, opaki, gadni;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
        std::cin>>broj;
        if(broj!=0) v.push_back(broj);
    }while(broj!=0);
    
    opaki=IzdvojiGadne(v, true);
    std::cout<<"Opaki: ";
    for(int x : opaki) std::cout<<x<<" ";
    
    std::cout<<std::endl;
	gadni=IzdvojiGadne(v, false);
	std::cout<<"Odvratni: ";
    for(int x : gadni) std::cout<<x<<" ";
    
	return 0;
}
