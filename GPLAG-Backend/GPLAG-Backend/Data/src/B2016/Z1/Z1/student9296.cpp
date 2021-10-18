/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cstdlib>
std::vector<int> IzdvojiGadne(std::vector<int> v, bool nesto){
	std::vector<int> v_novi;
	for(int i=0; i<v.size(); i++){
        int broj_0(0), broj_1(0), broj_2(0);
		int n(v[i]), y;
		while(1) {
			y=abs(n%3); 
			if(y==0) broj_0++;
			else if(y==1) broj_1++;
			else if(y==2) broj_2++;
			n/=3;
			if(n==0) break;
		}
		if(nesto){
			if(broj_0%2==0 && broj_1%2==0 && broj_2%2==0 || 
			broj_0==0 && broj_1%2==0 && broj_2%2==0 || 
			broj_0%2==0 && broj_1==0 && broj_2%2==0 ||
			broj_0%2==0 && broj_1%2==0 && broj_2==0 ||
			broj_0==0 && broj_1==0 && broj_2%2==0 ||
			broj_0==0 && broj_1%2==0 && broj_2==0 ||
			broj_0%2==0 && broj_1==0 && broj_2==0) v_novi.push_back(v[i]);
		}
		if(!nesto){
			if(broj_0%2!=0 && broj_1%2!=0 && broj_2%2!=0 ||
			broj_0==0 && broj_1%2!=0 && broj_2%2!=0 || 
			broj_0%2!=0 && broj_1==0 && broj_2%2!=0 ||
			broj_0%2!=0 && broj_1%2!=0 && broj_2==0 ||
			broj_0==0 && broj_1==0 && broj_2%2!=0 ||
			broj_0==0 && broj_1%2!=0 && broj_2==0 ||
			broj_0%2!=0 && broj_1==0 && broj_2==0) v_novi.push_back(v[i]);
		}
	}
	for(int i=0; i<v_novi.size(); i++){
		for(int j=i+1; j<v_novi.size(); j++){ 
			if(v_novi[i]==v_novi[j]){
				v_novi.erase(v_novi.begin()+j); 
				i--; 
				break;
			}
		}
	}
	return v_novi;
}

int main ()
{
	int brojevi;
	std::vector<int>v, a, b;
	bool nesto=true;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
        std::cin>>brojevi;
		if(brojevi==0) break;
		v.push_back(brojevi);
	}
	a=IzdvojiGadne(v, nesto);
	std::cout<<"Opaki: ";
	for(int x: a) std::cout<<x<<" ";
	nesto=false;
	b=IzdvojiGadne(v, nesto);
	std::cout<<"\nOdvratni: ";
	for(int x: b) std::cout<<x<<" ";
	return 0;
}