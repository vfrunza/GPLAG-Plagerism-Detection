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
std::vector<int> IzdvojiGadne (std::vector<int> v, bool a)
{
	//int niz[10]={0};
	std::vector<int> v1;
	for(int i=0; i<v.size(); i++) {
		int ima=1, k(0);
		int niz[10000]= {0};
		int ukupno(0);
		long long int broj=v[i];
		if(broj<0) {
			ima=-1;
			broj*=-1;
		}
		int pamti=broj;
		while(broj!=0) {
			int cifra=broj%3;
			ukupno=ukupno+cifra*pow(10,k);
			k++;
			broj/=3;
		}
		while(ukupno!=0) {
			int prvi=ukupno%10;
			niz[prvi]++;
			ukupno/=10;
		}
		for (int l=0; l<3; l++) if (niz[l]==0 && a==false) niz[l]++; //0 nije ni parna ni neparna, sto moze biti problem kod odvratnih brojeyyyva
		if(a==true) {
			if (niz[0]%2==0 && niz[1]%2==0 && niz[2]%2==0) {
				int rez=pamti*ima;
				bool imavec=false;
				for (int j=0; j<v1.size(); j++) {
					if (v1[j]==rez) {
						imavec=true;
						break;
					}
				}
				if (!imavec) {
					v1.push_back(rez);
				}
			}
		}
		if(a==false) {
			if(niz[0]%2==1 && niz[1]%2==1 && niz[2]%2==1) {
				int rez=pamti*ima;
				bool imavec2=false;
				for (int j=0; j<v1.size(); j++) {
					if (v1[j]==rez) {
						imavec2=true;
						break;
					}
				}
				if (!imavec2) {
					v1.push_back(rez);
				}
			}
		}
	}
	return v1;
}
int main ()
{
	int unos;
	std::vector <int> v1, opak, odvratan;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while (1) {
		std::cin >> unos;
		if (unos==0) break;
		v1.push_back(unos);
	}
	opak=IzdvojiGadne(v1,true);
	odvratan=IzdvojiGadne(v1,false);
	std::cout << "Opaki: ";
	for (int i=0; i<opak.size(); i++)
		std::cout << opak[i] << " ";
	std::cout << "\nOdvratni: ";
	for (int i=0; i<odvratan.size(); i++)
		std::cout << odvratan[i] << " ";
	return 0;
}