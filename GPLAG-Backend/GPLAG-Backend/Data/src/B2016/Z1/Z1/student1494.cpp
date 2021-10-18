/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) 
{
	std::vector<int> rez;
	
	int vel=v.size();
	for(int i(0); i<vel; i++) {
		std::string Ternarni;
		int n=std::fabs(v[i]);
		while(n!=0) {
			Ternarni.push_back((n%3)+'0');
			n/=3;
		}
		int tmp=Ternarni.size();
		for(int j(0); j<tmp; j++) {
			std::swap(Ternarni[j], Ternarni[tmp-j-1]);
		}
		bool stavi_u_niz(true);
		for(int j(0); j<3; j++) {
			int brojac(0);
			for(int k(0); k<tmp; k++) {
				if(Ternarni[k]==j+'0') brojac++;
			}
			if(opaki==true && brojac%2!=0 && brojac!=0) {
				stavi_u_niz=false;
			}
				if(opaki==false && brojac%2==0 && brojac!=0) {
					stavi_u_niz=false;
				}
					if(!stavi_u_niz) break;
		}
		bool Postoji(false);
		for(int j(0); j<rez.size(); j++)
			if(rez[j]==v[i]) Postoji=true;
				if(!Postoji && stavi_u_niz)
					rez.push_back(v[i]);
		}
		return rez;
}

int main ()
{
	std::vector<int> novi_vektor;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int n;
	do {
		std::cin >> n;
		if(n==0) break;
		novi_vektor.push_back(n);
	} while(n!=0);

	std::vector<int> vektor1;
	vektor1=IzdvojiGadne(novi_vektor, true);
	//int vel1=vektor1.size();
	std::cout << "Opaki: ";
		for(int i(0); i<vektor1.size(); i++) 
			std::cout << vektor1[i] << " ";
			std::cout << std::endl;
	std::vector<int> vektor2=IzdvojiGadne(novi_vektor, false);
	//int vel2=vektor2.size();
	std::cout << "Odvratni: ";
		for(int j(0); j<vektor2.size(); j++)
			std::cout << vektor2[j] << " ";
	
	
	return 0;
}