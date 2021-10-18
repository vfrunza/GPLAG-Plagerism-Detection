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
std::vector<int> ProvjeriDaLiImaIstihElemenata(std::vector<int>v) {
	
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
		if(v[i]==v[j]) v.erase(v.begin()+j);
		}
	}
	return v;
}
std::vector<int> PretvoriUTernarni(int n) {
	int cifra;
	std::vector<int>v;
	while(abs(n)!=0) {
	cifra=abs(n)%3;
	n=abs(n)/3;
	v.push_back(cifra);
	}
return v;
 }
 
std::vector<int> IzdvojiGadne (std::vector < int> v, bool vrijednost ) {
	std::vector < int > odvratni;
	std::vector < int > opaki;
	std::vector <int> odbaci;
	
		for(int i=0; i<v.size(); i++) {
		//int p=v[i];
		for(int j=i+1; j<v.size(); j++) {
		if(v[j]==v[i]) v.erase(v.begin()+j);
		}
	}
		
		for(int x:v) {
			std::vector<int> y;
			y=PretvoriUTernarni(x);
			int br0(0),br1(0),br2(0);
			for(int c:y) {
		if(c==0) br0++;
		else if(c==1) br1++;
		else if(c==2) br2++;
	}
	if(br0%2==0 && br1%2==0 && br2%2==0) opaki.push_back(x);
	else if ((br0==0 && br1%2!=0 && br2%2!=0) || (br0%2!=0 && br1==0 && br2%2!=0) || (br0%2!=0 && br1%2!=0 && br2==0) 	||(br0%2!=0 && br1%2!=0 && br2%2!=0)  || (br0%2!=0 && br1%2!=0 && br2%2!=0 ) ||(br0==0 && br1==0 && br2%2!=0) || (br0==0 && br1%2!=0 && br2==0) || (br0%2!=0 &&  br1==0 && br2==0)) odvratni.push_back(x);
	else odbaci.push_back(x);
			}
		
	
	if(vrijednost==true) return opaki;
	else return odvratni;
	
}
int main ()
{
	std::vector<int> v;
	std::vector<int>pomocni;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1) {
		int i;
		std::cin>>i;
		if(i!=0) v.push_back(i);
		else break;
	}
	pomocni=ProvjeriDaLiImaIstihElemenata(v);
	std::vector<int>b=IzdvojiGadne(pomocni, true);
	std::vector<int>c=IzdvojiGadne(pomocni, false);
	std::cout<<"Opaki: ";
	for(int x:b) {
		std::cout<<x<<" ";
	}
	std::cout<<"\nOdvratni: ";
	for(int x:c) {
		std::cout<<x<<" ";
	}
	return 0;
}