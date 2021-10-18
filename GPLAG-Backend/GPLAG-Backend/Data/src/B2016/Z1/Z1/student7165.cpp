/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include <limits>
#include <cmath>
std::vector<int> IzdvojiGadne (std::vector<int>v ,bool a)
{
	std::vector<int> PovratniVektor;
	for(int i=0; i<v.size(); i++) {
		std::vector<int> brojac(3,0);
		int temp=v[i];
		//if(temp < 0 ) temp*=-1;
		do {
			brojac[std::abs(temp%3)]++; 
			temp/=3;
		} while(temp != 0);
		bool gadni=true;
		int indeks=0;
		for(int j=0; j<brojac.size(); j++) if(brojac[j] > 0) indeks=j;
		for (int j=0; j<brojac.size(); j++) {
			if(brojac[indeks]%2 != brojac[j]%2 && brojac[j] != 0) {
				gadni=false;
				break;
			}
		}
		if(gadni==true && a==true && brojac[indeks]%2 == 0) PovratniVektor.push_back(v[i]);
		if (gadni==true && a==false && brojac[indeks]%2 != 0) PovratniVektor.push_back(v[i]);
	}
	for(int i=0; i<PovratniVektor.size(); i++){
		for(int j=i+1; j<PovratniVektor.size(); j++){
			if(PovratniVektor[i]==PovratniVektor[j]){
				for(int k=j; k<PovratniVektor.size()-1; k++){
					PovratniVektor[k]=PovratniVektor[k+1];
				}
				PovratniVektor.resize(PovratniVektor.size()-1);
				j--;
			}
		}
	}

	return PovratniVektor;
}
int main1()
{
	std::vector<int> a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int e;
	for(;;) {
		std::cin>>e;
		if(e==0) {
			break;
		}
	 	a.push_back(e);
	 }
		std::vector<int> b=IzdvojiGadne(a,true);
		std::vector<int> c=IzdvojiGadne(a,false);
		std::cout<<"Opaki: ";
		for(int i=0;i<b.size();i++){
			std::cout<<b.at(i)<<" ";
		} 
		std::cout<<std::endl;
		std::cout<<"Odvratni: ";
		for(int i=0;i<c.size();i++) {
			std::cout<<c.at(i)<<" ";
		}
	return 0;
}
int main(){
	int x=std::numeric_limits<int> min();
	std::vector<int> v;
	v.push_back(x);
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";
//Opaki: 608 -608 60 
//Odvratni: 123 333 -15 15 715
}