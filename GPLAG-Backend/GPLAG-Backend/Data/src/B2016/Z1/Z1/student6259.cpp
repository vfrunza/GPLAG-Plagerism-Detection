/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

bool Provjera_opaki (int a) {
	if(a<0) a=-a;
	int br0(0), br1(0), br2(0);
	
	for(;;) {
		if(a%3==0) br0++;
		else if(a%3==1) br1++;
		else br2++;
		a=(a-a%3)/3;
		if(a==0) break;
	}
	
	if(br0%2==0 && br0%2==br1%2 && br1%2==br2%2) return true;
	return false;
}

bool Provjera_odvratni (int a) {
	if(a<0) a=-a;
	int br0(0), br1(0), br2(0);
	
	for(;;) {
		if(a%3==0) br0++;
		else if(a%3==1) br1++;
		else br2++;
		
		a=(a-a%3)/3;
		if(a==0) break;
	}
	
	if(br0==0) br0=1;
	if(br1==0) br1=1;
	if(br2==0) br2=1;
	
	if(br0%2==1 && br0%2==br1%2 && br1%2==br2%2) return true;
	return false;
}

std::vector<int> IzdvojiGadne(std::vector<int>vektor, bool f) {
	
	std::vector<int>v;
	
	for(int i(0); i<vektor.size(); i++) {
		if(f) {
			if(Provjera_opaki(vektor.at(i))) v.push_back(vektor.at(i));
		}
		else if(Provjera_odvratni(vektor.at(i))) v.push_back(vektor.at(i)); 
	}
	
	for(int i(0); i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j))  {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
	
}

int main ()
{	
	int a;
	std::vector<int>v, v1, v2;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	for(;;) {
		std::cin>>a;
		if(a==0) break;
		else v.push_back(a);
	}
	
	v2=IzdvojiGadne(v, false);
	v1=IzdvojiGadne(v, true);
	
	std::cout<<"Opaki: ";
	for(int i(0); i<v1.size(); i++) {
		std::cout<<v1.at(i)<<" ";
	}
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int i(0); i<v2.size(); i++) {
		std::cout<<v2.at(i)<<" ";
	}
	
	return 0;
}
