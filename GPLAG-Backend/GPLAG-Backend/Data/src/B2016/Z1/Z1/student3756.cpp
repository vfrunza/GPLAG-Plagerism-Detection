/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>

std::vector<int> ternarni(int n) {
	n = abs(n);
	std::vector<int> vrati;
	while(n!=0){
		int k = n % 3;
		vrati.push_back(k);
		n/=3;
	}
	return vrati;
}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool b){
	std::vector<int> pomocni;
	if(v.size() == 0) return pomocni;
	if (b){
		for(int i(0); i < v.size(); i++){
			int testni (0);
			for(int k(0); k < pomocni.size(); k++){
			if (v[i] == pomocni[k]){
				testni = -1; break; 
			}
			}
			if (testni == -1) continue; 
			
			int nula(0), jedan(0), dva(0);
			int n = v[i];
			if(n == std::numeric_limits<int>::min() || n == std::numeric_limits<int>::max()) continue;
			
			std::vector<int> vektor_broja = ternarni(n);
			
			for(int j(0); j < vektor_broja.size(); j++) {
				if(vektor_broja[j] == 0) nula++;
				if(vektor_broja[j] == 1) jedan++;
				if(vektor_broja[j] == 2) dva++;
			}
			
	if((nula % 2 == 0 && nula != 0 && jedan == 0 && dva == 0) || (jedan % 2 == 0 && jedan != 0 && nula == 0 && dva == 0 ) || (dva % 2 == 0 && dva != 0 && nula == 0 && jedan == 0) || (nula == 0 && jedan % 2 == 0 && dva % 2 == 0 && jedan != 0 && dva != 0 ) || (jedan == 0 && nula % 2 == 0 && dva % 2 == 0 && nula != 0 && dva != 0) || (dva == 0 && nula % 2 == 0 && jedan % 2 == 0 && nula != 0 && jedan != 0) ||(nula % 2 == 0 && jedan % 2 == 0 && dva % 2 == 0 && nula != 0 && jedan != 0 && dva != 0))
	pomocni.push_back(v[i]);
		}
	}
		
	else {
	
		for(int i=0; i < v.size(); i++){
			int testni (0);
			for(int k(0); k < pomocni.size(); k++){
			if (v[i] == pomocni[k]){
				testni = -1; break; 
			}
			}
			
			if (testni == -1) continue; 
			int n = v[i];
			if(n == std::numeric_limits<int>::min() || n == std::numeric_limits<int>::max()) continue;
			std::vector<int> vektor_broja; vektor_broja = ternarni(n);
			int nula(0), jedan(0), dva(0);
			for(int i(0); i<vektor_broja.size(); i++) {
				if(vektor_broja[i] == 0) nula++;
				if(vektor_broja[i] == 1) jedan++;
				if(vektor_broja[i] == 2) dva++;
			}
		if((nula % 2 != 0 && nula != 0 && jedan == 0 && dva == 0) || (jedan % 2 != 0 && jedan != 0 && nula == 0 && dva == 0 ) || (dva % 2 != 0 && dva != 0 && nula == 0 && jedan == 0) || (nula == 0 && jedan % 2 != 0 && dva % 2 != 0 && jedan != 0 && dva != 0 ) || (jedan == 0 && nula % 2 != 0 && dva % 2 != 0 && nula != 0 && dva != 0) || (dva == 0 && nula % 2 != 0 && jedan % 2 != 0 && nula != 0 && jedan != 0) ||(nula % 2 != 0 && jedan % 2 != 0 && dva % 2 != 0 && nula != 0 && jedan != 0 && dva != 0))
	pomocni.push_back(v[i]);
		}
	}
	return pomocni; 
}

int main () {	
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int n; 
	std::vector<int> v;
	while(true){
		std::cin >> n; 
		while(!(std::cin)){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> n;}
		if (n == 0) break; 
		v.push_back(n);
		
	}
	bool b(1);
	std::vector<int> pomocni = IzdvojiGadne(v, b);
	std::cout << "Opaki: ";
	for(int i=0; i<pomocni.size(); i++)
	std::cout << pomocni[i] << " ";
	b=0;
	std::vector<int> pomocni2 = IzdvojiGadne(v, b);
	std::cout << "\nOdvratni: ";
	for(int i=0; i<pomocni2.size(); i++)
	std::cout << pomocni2[i] << " ";

/* Provjera funkcije ternarni
for(int i(0); i<v.size(); i++) {
    std::vector<int> pomocni = ternarni(v[i]);
    for(int j(0); j<pomocni.size(); j++) std::cout << pomocni[j] << " ";

    std::cout << std::endl;
}*/
return 0;
}