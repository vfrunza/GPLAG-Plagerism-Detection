/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;

IntDeque ternary(int a) {
	IntDeque d;
	while (1) {
		if(a==0) break;
		d.push_front(abs(a%3));
		a/=3;
	}
	return d;
}

bool DaLiJeEvil(int a) {
	if(a==0) return false;
	IntDeque d = ternary(a);
	int br0(0), br1(0), br2(0);
	for(int i(0); i<d.size(); i++) {
		if(d[i]==0) br0++;
		else if(d[i]==1) br1++;
		else if(d[i]==2) br2++;
	}
	if((br0%2==0) && (br1%2==0) && (br2%2==0)) return true;
	else return false;
}

bool DaLiJeOdious(int a) {
	if(a==0) return true;
	IntDeque d = ternary(a);
	int br0(0), br1(0), br2(0);
	for(int i(0); i<d.size(); i++) {
		if(d[i]==0) br0++;
		else if(d[i]==1) br1++;
		else if(d[i]==2) br2++;
	}
	if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) return true;
	else return false;
}

IntVector IzdvojiGadne(IntVector v, bool vrijednost) {
	IntVector v2;
	if(vrijednost) {
		for(int i(0); i<v.size(); i++) 
			if(DaLiJeEvil(v[i])) v2.push_back(v[i]);
	}
	else {
		for(int i(0); i<v.size(); i++) 
			if(DaLiJeOdious(v[i])) v2.push_back(v[i]);
	}
	for(int i(0); i<v2.size(); i++) {
		for(int j(i+1); j<v2.size(); j++) {
			if(v2[j]==v2[i]) {
				v2.erase(v2.begin()+j);
				j--;
			}
		}
	}
	return v2;
}

int main ()
{
	IntVector v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while(1){
		int broj;
		std::cin>>broj;
		if(broj==0) break;
		v.push_back(broj);
	}
	IntVector v2 = IzdvojiGadne(v,true);
	IntVector v3 = IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i(0); i<v2.size(); i++) {
		std::cout<<v2[i]<<" ";
	}
	std::cout<<std::endl<<"Odvratni: ";
		for(int i(0); i<v3.size(); i++) {
		std::cout<<v3[i]<<" ";
	}
	return 0;
}