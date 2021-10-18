/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>

std::vector<int> IzdvojiGadne (std::vector<int> v, bool ok) {
	std::vector<int> rezz;
	for(int i = 0; i < v.size(); i++){
		long long int broj(v[i]);
		unsigned long long int br0{}, br1{}, br2{};
		if(broj < 0) broj *= -1;
		while(broj != 0) {
			int pom;
			pom = broj % 3;
			//std::cout << pom << "   ";
			if(pom == 0) br0++;
			else if(pom == 1) br1++;
			else if(pom == 2) br2++;
			//std::cout << br1 << std::endl;
			broj /= 3;
 		}
 		//std::cout << "br0: " << br0 << std::endl;
 		//std::cout << "br1: " << br1 << std::endl;
 		//std::cout << "br2: " << br2 << std::endl;
 		if(ok == true) {
 			if(br0 != 0 && br1 != 0 && br2 != 0) {
 				if(br0 % 2 == 0 && br1 % 2 == 0 && br2 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br1 != 0) {
 				if(br0 % 2 == 0 && br1 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br2 != 0) {
 				if(br0 % 2 == 0 && br2 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br1 != 0 && br2 != 0) {
 				if(br1 % 2 == 0 && br2 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br1 == 0 && br2 == 0) {
 				if(br0 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br1 != 0 && br0 == 0 && br2 == 0) {
 				if(br1 % 2 == 0) rezz.push_back(v[i]);
 			}
 			else if(br2 != 0 && br0 == 0 && br1 == 0) {
 				if(br2 % 2 == 0) rezz.push_back(v[i]);
 			}
 		}
 		if(ok == false) {
 			//std::cout << "hnjoo" << std::endl;
 			if(br0 != 0 && br1 != 0 && br2 != 0) {
 				if(br0 % 2 != 0 && br1 % 2 != 0 && br2 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br1 != 0) {
 				//std::cout << "aaa";
 				if(br0 % 2 != 0 && br1 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br2 != 0) {
 				if(br0 % 2 != 0 && br2 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br1 != 0 && br2 != 0) {
 				if(br1 % 2 != 0 && br2 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br0 != 0 && br1 == 0 && br2 == 0) {
 				if(br0 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br1 != 0 && br0 == 0 && br2 == 0) {
 				if(br1 % 2 != 0) rezz.push_back(v[i]);
 			}
 			else if(br2 != 0 && br0 == 0 && br1 == 0) {
 				//std::cout << "sklj";
 				//std::cout << br2;
 				if(br2 % 2 != 0) rezz.push_back(v[i]);
 			}
 		}
	}
	for(int i = 0; i < rezz.size(); i++) {
		for(int j = i + 1; j < rezz.size(); j++) {
			if(rezz[i] == rezz[j]) {
				rezz.erase(rezz.begin() + j);
				//j--;
			}
			
		}
	}
	for(int i = 0; i < rezz.size(); i++) {
		for(int j = i + 1; j < rezz.size(); j++) {
			if(rezz[i] == rezz[j]) {
				rezz.erase(rezz.begin() + j);
				//j--;
			}
			
		}
	}
	return rezz;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	std::vector<int> v;
	do {
		std::cin >> broj;
		if(broj != 0) v.push_back(broj);
	} while (broj != 0);
	std::vector<int> v2(IzdvojiGadne(v, true));
	std::cout << "Opaki: ";
	for(int i = 0; i < v2.size(); i++) std::cout << v2[i] << " ";
	std::cout << std::endl;
	std::vector<int> v1(IzdvojiGadne(v, false));
	std::cout << "Odvratni: ";
	for(int i = 0; i < v1.size(); i++) std::cout << v1[i] << " ";
	//for (const auto &a : IzdvojiGadne({121, 15451, 15, 179, 777}, false))
    //std::cout << a << " ";
    //for (const auto &a : IzdvojiGadne({2460, 608, 426, 6560, 364}, true))
    //std::cout << a << " ";
	return 0;
}