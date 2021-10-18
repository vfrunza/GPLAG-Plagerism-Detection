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
std::vector<int> IzdvojiGadne (std::vector<int> v, bool n) {
	std::vector<int> v1;
	std::vector<int> v2;
		for (int i(0); i<v.size(); i++) {
		for (int j(i+1); j<v.size(); j++) {
			if (v[j]==v[i]) {
			v.erase(v.begin()+j);
			j--;
				
		}
	}
	}
	for (int i(0); i < v.size(); i++) {
		int a=v[i];
		long long int c=static_cast<long long int>(a);
		if(c<0) c*=(-1);
		int br0(0), br1(0), br2(0);
		do {
			int cifra = c%3;
			if (cifra==0) br0++;
			else if (cifra==1) br1++;
			else if (cifra==2) br2++;
			c/=3;
		} 
		while(c!=0);
		
	if (br0%2==0 && br1%2==0 && br2%2==0) {
	v1.push_back(v[i]);
	}
	else if ((br2%2!=0 || br2==0) && (br0%2!=0 || br0==0) && (br1%2!=0 || br1==0)) {
		v2.push_back(v[i]);
	}
	}
if (n) return v1;
else return v2;
	

}

 int main ()
{
	std::vector<int> v;
	std::vector<int> v1;
	std::vector<int> v2;
	int elementi;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	while(5) {
		std::cin>>elementi;
		if (elementi==0) break;
		v.push_back(elementi);
	}

	v1=IzdvojiGadne(v, true);
	std::cout << "Opaki: ";
	for (int i(0); i<v1.size(); i++) {
		std::cout << v1[i] << " " ;
	}
	std::cout<< std::endl;
	v2=IzdvojiGadne(v, false);
	std::cout << "Odvratni: ";
	for (int i(0); i<v2.size(); i++) {
		std::cout << v2[i] << " ";
	}
return 0;
}

