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
std::vector<int> IzdvojiGadne (std::vector<int>v, bool s) {
	std::vector<int>a;
	std::vector<int>b;
	//Brojeve pretvaramo u ternarni brojni sistem
	int brojac0, brojac1, brojac2, zamjena;
	for (int i=0; i<v.size(); i++) {
		zamjena=(v[i]);
		brojac0=0;
		brojac1=0;
		brojac2=0;
		do {
			//Brojimo koliko puta se pojavljuju jedine tri cifre ternarnog brojnog sistema
			if (zamjena%3==0 ) brojac0++;
			else if (zamjena%3==1 || zamjena%3==-1) brojac1++;
			else if (zamjena%3==2 || zamjena%3==-2) brojac2++;
			zamjena/=3;
		} while (zamjena!=0);
			//Ako se pojavljuju paran broj puta, saljemo ih u main kao opake
			if (brojac0%2==0 && brojac1%2==0 && brojac2%2==0) {
				bool ne_postoji=true;
				for (int j=0; j<a.size(); j++) {
					//Provjeramo da li se jedan broj pojavljuje vise puta u vektoru
					if (v[i]==a[j]) ne_postoji=false;
				}
				if (ne_postoji) a.push_back(v[i]);
			}
		//Ako se pojavljuju neparan broj puta, saljemo ih u main kao odvratne
		else if ((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) {
			bool ne_postoji(true);
				for (int j=0; j<b.size(); j++) {
					//Provjeramo da li se jedan broj pojavljuje vise puta u vektoru
					if (v[i]==b[j]) ne_postoji=false;
				}
				if (ne_postoji) b.push_back(v[i]);
			}
	}
if (s) return a;
return b;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v1(0);
	int a;
	do {
		std::cin>>a;
		if (a!=0) v1.push_back(a);
	} while (a!=0);
	std::vector<int>v;
	v=IzdvojiGadne(v1, true);
	std::cout<<"Opaki: ";
	for (int k=0; k<v.size(); k++)
		std::cout<<v[k]<<" ";
	std::cout<<std::endl;
	v=IzdvojiGadne(v1, false);
	std::cout<<"Odvratni: ";
	for (int k=0; k<v.size(); k++)
		std::cout<<v[k]<<" ";
	return 0;
}