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

bool PonavljaSe (std::vector<int> s, int n){
	if(int(s.size())==0) return false;
	for(int i(0); i<int(s.size()); i++ ){
		if(s.at(i)==n) return true;
	}
	return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool tip){

	std::vector<int> s;
	if(int(v.size())==0) return s;
	
	for(int i(0); i<int(v.size()); i++){
		
		
		long int n(v.at(i));
		
		if(n<0) n=n*(-1);	
		
		std::vector<int> brojac(3);
		
		while(n!=0){
			brojac.at(n%3)++;
			n=n/3;
		}
		
		if(tip){
			bool p(true);
			for(int j(0); j<3; j++){
				if(brojac.at(j)%2!=0 && brojac.at(j)!=0)  {
					p=false; break;
				}
			}
			if(p && !PonavljaSe(s,v.at(i)) && v.at(i)!=0) s.push_back(v.at(i));
		}
		else {
			bool n(true);
			for(int j(0); j<3; j++){
				if(brojac.at(j)%2==0 && brojac.at(j)!=0){
					n=false; break;
				}
			}
			if(n && !PonavljaSe(s,v.at(i))) s.push_back(v.at(i));
		}
		
		
	}
	return s;
}

int main ()
{
	int n;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin>>n;
		if(n==0) break;
		v.push_back(n);
	}
	
	std::vector <int> s(IzdvojiGadne(v, true)), p(IzdvojiGadne(v,false));
	
	std::cout<<"Opaki: ";
	for(auto x: s) std::cout<<x<<" ";
	
	std::cout<<std::endl<<"Odvratni: ";
	for(auto x: p) std::cout<<x<<" ";
	
	return 0;
}