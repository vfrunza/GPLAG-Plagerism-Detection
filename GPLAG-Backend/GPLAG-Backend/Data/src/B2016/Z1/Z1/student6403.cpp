/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool n)
{
	std::vector<int> novi;
	for(int i(0); i<v.size(); i++) {
		int temp(v.at(i));
		std::vector<int> brojaci(10,0);
		do {
			int c(abs(temp%3));
			brojaci.at(c)++;
			temp/=3;
			if(temp==0) break;
		} while(temp!=0);
		
		bool x(true), y(true), z(true);
		for(int j(0); j<brojaci.size(); j++) {
			if(brojaci.at(j)==0) continue;
			if(n==true && brojaci.at(j)%2!=0) {
				x=false;
				break;
			}

			if(n==false && brojaci.at(j)%2==0) {
				y=false;
				break;
			}
			if (j==brojaci.size()-1) break;
		}
		for(int j(0);j<novi.size();j++) {
			if(novi.at(j)==v.at(i)) {
				z=false;
				break;
			}
			if(j==novi.size()-1) break;	
		}
		if(n==true && x==true && z==true) novi.push_back(v.at(i));
		if(n==false && y==true && z==true) novi.push_back(v.at(i));
		if(i==v.size()-1) break;
	}
	return novi;
}

int main ()
{
	std::vector<int> vektor;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	int a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>a;
	while(a!=0) {
		if(a==0) break;
		vektor.push_back(a);
		std::cin>>a;
	}
	opaki=IzdvojiGadne(vektor, true);
	odvratni=IzdvojiGadne(vektor, false);
	if(opaki.size()>=1) {
		std::cout<<"Opaki: ";
		for(int i(0); i<opaki.size(); i++) {
			std::cout<<opaki.at(i)<<" ";
			if(i==opaki.size()-1) break;
		}
	}
	std::cout<<std::endl;
	if(odvratni.size()>=1) {
		std::cout<<"Odvratni: ";
		for(int i(0); i<odvratni.size(); i++) {
			std::cout<<odvratni.at(i)<<" ";
			if(i==odvratni.size()-1) break;
		}
	}
	return 0;
}