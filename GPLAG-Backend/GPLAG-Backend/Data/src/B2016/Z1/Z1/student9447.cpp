/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool p) {
	std::vector<int> opaki, odvratni;
	for(int i = 0; i < v.size(); i++) {
		int br1(0), br2(0), br3(0), temp;
		temp = v[i];
		while(temp != 0){ 
		   if(temp % 3 == 0) br1++;
	       else if(temp % 3 == 1) br2++;
		   else if(temp % 3 == 2) br3++;
		   temp /= 3;
		}
		if((br1 % 2 == 0) && (br2 % 2 == 0) && (br3 % 2 == 0)) opaki.push_back(v[i]);
		else if((br1 % 2 != 0 || br1 == 0) && (br2 % 2 != 0 || br2 == 0) && (br3 % 2 != 0 || br3 == 0)) odvratni.push_back(v[i]);
	}
	
	for(int i = 0; i < opaki.size(); i++) {
		for(int j = i + 1; j < opaki.size(); j++) {
			if(opaki[i] == opaki[j]) {
				for(int k = j; k < opaki.size() - 1; k++) opaki[k] = opaki[k + 1];
				
				opaki.resize(opaki.size() - 1);
				j--;
			}
		}
	}
	
	for(int i = 0; i < odvratni.size(); i++) {
		for(int j = i + 1; j < odvratni.size(); j++) {
			if(odvratni[i] == odvratni[j]) {
				for(int k = j; k < odvratni.size() - 1; k++) odvratni[k] = odvratni[k + 1];
				
				odvratni.resize(odvratni.size() - 1);
				j--;
			}
		}
	}
	if(p) return opaki;
	return odvratni;
}

int main ()
{
	std::vector<int> v1, v2, v3;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	std::cin >> a;
	while (a != 0) {
		v1.push_back(a);
		std::cin >> a;;
	}
	
	v2 = IzdvojiGadne(v1, true);
	v3 = IzdvojiGadne(v1, false);
	
	std::cout << "Opaki: ";
	for(int i = 0; i < v2.size(); i++) std::cout << v2[i] << " ";
	   
	std::cout << std::endl;
	   
	std::cout << "Odvratni: ";
	for(int i = 0; i < v3.size(); i++) std::cout << v3[i] << " ";
	   
	return 0;
}