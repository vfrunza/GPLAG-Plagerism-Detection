/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <cmath>
#include <vector>

bool ImaLiGaVisePutaORIG (std::vector<int> v, int broj, int lok)
{
	for (int i=lok+1; i<v.size(); i++)
		if (v[i]==broj) return true;
	return false;
}

bool ImaLiGaVisePuta (std::vector<int> v, long int broj, int lok)
{
	for (int j=lok-1; j>=0; j--){
		if (broj==v.at(j)) return true;}
	return false;
}

/*int ImaLiGaVisePuta1 (std::vector<int> v, int broj, int lok)
{
	int brojac=0;
	for (int i=0; i<v.size(); i++)
		if (v[i]==broj) brojac++;
	return brojac;	
}*/

int JesuLiParni (int prvi, int drugi, int treci)
{
	if(prvi==0 && drugi==0 && treci%2==0) return 2;
	if(prvi==0 && drugi==0 && treci%2==1) return 1;
	if(prvi==0 && drugi%2==0 && treci==0) return 2;
	if(prvi==0 && drugi%2==1 && treci==0) return 1;
	if(prvi%2==0 && drugi==0 && treci==0) return 2;
	if(prvi%2==1 && drugi==0 && treci==0) return 1;
	
	if(prvi==0 && drugi%2==0 && treci%2==0) return 2;
	if(prvi==0 && drugi%2==1 && treci%2==1) return 1;
	if(prvi%2==0 && drugi==0 && treci%2==0) return 2;
	if(prvi%2==1 && drugi==0 && treci%2==1) return 1;
	if(prvi%2==0 && drugi%2==0 && treci==0) return 2;
	if(prvi%2==1 && drugi%2==1 && treci==0) return 1;
	
	if(prvi!=0 && drugi!=0 && treci!=0 && drugi%2==0 && treci%2==0 && prvi%2==0) return 2; //ako su parni
	if(prvi!=0 && drugi!=0 && treci!=0 && drugi%2!=0 && treci%2!=0 && prvi%2!=0) return 1; //ako su neparni
	else return 0; //nisu ni gadni
}

std::vector <int> IzdvojiGadne (std::vector <int> v, bool gadan)
{
	std::vector <int> rez, test, ponavljanja(3);
	test=v;
	for (int i=0; i<v.size(); i++) {
		std::vector<int> ponavljanja(3);
		int temp, ternarni=0, ostatak=0, br=1;
		bool negativan=false;
		if (v.at(i)<0) {
			v.at(i)=-v.at(i);
			negativan=true;
		}
		temp=v.at(i);
		while (v.at(i)!=0) {
			ostatak=v.at(i)%3;
			ternarni=ternarni+ostatak*br;
			br*=10;
			v.at(i)/=3;
		}
		while (ternarni!=0)
		{
			ostatak=ternarni%10;
			ponavljanja.at(ostatak)++;
			ternarni/=10;
		}
		if (gadan==true) {
			if (negativan) temp*=-1;
			if (JesuLiParni(ponavljanja.at(0), ponavljanja.at(1), ponavljanja.at(2))==2 && (!ImaLiGaVisePuta(test,temp,i))) rez.push_back(temp);
			} else if (gadan==false) {
			if (negativan) temp*=-1;
			if (JesuLiParni(ponavljanja.at(0), ponavljanja.at(1), ponavljanja.at(2))==1 && (!ImaLiGaVisePuta(test,temp,i))) rez.push_back(temp);
		}
	}
	return rez;
}

/* std::vector <int> NapraviTernarne (std::vector<int> v) {
	std::vector <int> rez;
	bool negativan;
	for(int i=0; i<v.size();i++) {
		int temp, ternarni=0, ostatak, br=1;
		if(v[i]<0) {
			v[i]=-v[i];
			negativan=true;
		}
		temp=v[i];
		while(v[i]!=0) {
			ostatak=v[i]%3;
			ternarni=ternarni+ostatak*br;
			br*=10;
			v[i]/=3;
		}
		rez.push_back(ternarni);
	}
	return rez;
}*/

int main ()
{
	std::vector<int> V, IzlazOpaki, IzlazOdvratni, IzlazTernarni;
	int  broj,VelicinaOdvratni, VelicinaOpaki;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> broj;
		if (broj!=0)
		V.push_back(broj);
	} while(broj!=0);
	
	/*IzlazTernarni=NapraviTernarne(V);
	if(IzlazTernarni.size()>0) {
		for(int i=0; i<=IzlazTernarni.size()-1; i++)
		std::cout << IzlazTernarni.at(i) << " ";
	}*/
	
	IzlazOpaki=IzdvojiGadne(V,true);
	VelicinaOpaki=IzlazOpaki.size();
	//std::cout << VelicinaOpaki << std::endl;
	
	if(VelicinaOpaki>0) {
		std::cout << "Opaki: ";
		for(int i=0; i<=IzlazOpaki.size()-1; i++)
		std::cout << IzlazOpaki.at(i) << " ";
	}
	
	IzlazOdvratni=IzdvojiGadne(V,false);
	VelicinaOdvratni=IzlazOdvratni.size();
	//std::cout << VelicinaOdvratni << std::endl;
	
	if(VelicinaOdvratni>0) {
		std::cout << std:: endl << "Odvratni: ";
		for(int i=0; i<=IzlazOdvratni.size()-1; i++)
		std::cout << IzlazOdvratni.at(i) << " ";
	}
	
	return 0;
}