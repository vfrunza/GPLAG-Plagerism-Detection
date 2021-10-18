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
std::vector<int> IzdvojiGadne(std::vector<int>v,bool n)
{
	std::vector<int>v1,v2,v3,v4;
	int broj,cifra;
	for(int i=0; i<v.size(); i++) {
		int brojac_nula=0,brojac_1=0,brojac_2=0;
		broj=v[i];
		if(v[i]==0)v2.push_back(v[i]);
		else {
			while(broj!=0) {
				cifra=abs(broj%3);
				if(cifra==0)brojac_nula++;
				else if(cifra==1)brojac_1++;
				else if(cifra==2)brojac_2++;
				broj=broj/3;
			}

			if(brojac_nula%2==0 && brojac_2%2==0 && brojac_1%2==0)
				v1.push_back(v.at(i));

			else if((brojac_1%2!=0 || brojac_1==0) && (brojac_2%2!=0 || brojac_2==0) && (brojac_nula%2!=0 || brojac_nula==0))
				v2.push_back(v.at(i));
		}
	}
	for(int i=0; i<v1.size(); i++) {
		bool isti=false;
		for(int j=0; j<v3.size(); j++) {
			if(v1[i]==v3[j] && i!=0) {
				isti=true;
				break;
			}
		}
		if(!isti) v3.push_back(v1.at(i));
	}
	for(int i=0; i<v2.size(); i++) {
		bool isti1=false;
		for(int j=0; j<v4.size(); j++) {
			if(v2[i]==v4[j] && i!=0) {
				isti1=true;
				break;
			}
		}
		if(!isti1) v4.push_back(v2.at(i));
	}

	if(n)return v3;
	return v4;
}
int main ()
{
	std::vector<int>v,v1,v2;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>n;
		if(n!=0)
			v.push_back(n);
	} while(n!=0);

	v1=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i=0; i<v1.size(); i++)
		std::cout<<v1[i]<<" ";
	std::cout<<std::endl;
	v2=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	for(int i=0; i<v2.size(); i++)
		std::cout<<v2[i]<<" ";
	return 0;
}