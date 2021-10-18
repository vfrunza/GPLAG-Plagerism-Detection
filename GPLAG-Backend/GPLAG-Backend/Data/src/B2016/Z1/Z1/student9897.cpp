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
	
	for (int i=0; i<v.size()-1; i++) {
		for (int j=i+1; j<v.size(); j++) {
			
			if (v[j]==v[i]) {
				v.erase(v.begin() + j);  
			}
		}
	}
	
	std::vector<int> opaki; 
	std::vector<int> odvratni; 
	
	 for (int i=0; i<v.size(); i++) {
	
			int x;
		    x=v.at(i); 
	
	     if (x>std::pow(3,9) || x%10==0 || (x/3)%10==0) continue; 
		
		 int br1(0), br2(0), br0(0); 
		
		 while (x!=0) {
			
			int a;
			a=x%3; 
			a=std::abs(a);
			
			if (a>2) break; 
			
			if (a==0) br0++; 
			else if (a==1) br1++; 
			else if (a==2) br2++; 
		
			x=x/3;
		}
	
	   if (br2%2==0 && br1%2==0 && br0%2==0) {
	   	opaki.push_back(v.at(i)); 
	   }
	   else if ((br2%2!=0 && br1%2!=0) || (br2%2!=0 && br0%2!=0) || (br1%2!=0 && br0%2!=0)) {
	   	odvratni.push_back(v.at(i)); 
  }
}
		
	if (n==true) return opaki; 
	else return odvratni;
}


int main ()
{
	std::vector<int> v; 
	
	std::cout << "Unesite brojeve (0 za prekid unosa): "; 
	
	for (;;) {
		
		int broj; 
		std::cin >> broj; 
		
		if (broj==0) break; 
		else v.push_back(broj); 
	}
	
	std::vector<int> opaki; 
	opaki = IzdvojiGadne(v,true); 
	
	std::cout << "Opaki: ";

	for (int x:opaki) {
		std::cout << x << " "; 
	}
	
	std::cout << std::endl; 
	
	std::vector<int> odvratni; 
	odvratni = IzdvojiGadne(v,false);
	
	std::cout << "Odvratni: "; 
	
	for (int x:odvratni) {
		std::cout << x << " "; 
	}
	
	return 0;
}