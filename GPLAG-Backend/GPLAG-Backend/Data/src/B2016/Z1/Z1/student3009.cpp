/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t) {
	std::vector<int> rez;
	for (int i=0; i<v.size(); i++) {
		bool ponavlja(false);
		for (int j=0; j<i; j++) {
			if (v[i]==v[j]) {
				ponavlja=true;
				break;
			}
		}
		if (!ponavlja) {
			int x(v[i]);
			int br0(0), br1(0), br2(0);
			while (x!=0) {
				if (x%3==0) br0++;
					else if (x%3==1 || x%3==-1) br1++;
						else if (x%3==2 || x%3==-2) br2++;
				x/=3;
			}
			
			if (t && br0%2==0 && br1%2==0 && br2%2==0) {
				rez.push_back(v[i]);
			}
				else if (!t && (br0%2==1 || br0==0) && (br1%2==1 || br1==0) && (br2%2==1 || br2==0)) {
					rez.push_back(v[i]);
				}
		}
	}
	return rez;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int a;
	std::cin >> a;
	while (a!=0) {
		v.push_back(a);
		std::cin >> a;
	}
	
	std::vector<int> opaki(IzdvojiGadne(v, true));
	std::cout << "Opaki: " ;
	for (int i=0; i<opaki.size(); i++) {
		std::cout << opaki[i] << " ";                  
	} 
	std::cout << std::endl << "Odvratni: ";
	std::vector<int> odvratni(IzdvojiGadne(v, false));
	for (int i=0; i<odvratni.size(); i++) {
		std::cout << odvratni[i] << " ";                  
	} 
	return 0;
}