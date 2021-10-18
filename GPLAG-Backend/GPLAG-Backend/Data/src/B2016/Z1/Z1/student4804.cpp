/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
bool Opaki(int broj, bool opak) {
	std::vector<int> ternarna_reprezentacija;
	int stepen;
	if(broj<0) broj*=(-1);
	int kopija(broj);
	int najveci_stepen(-1);
	while(kopija!=0) {
		najveci_stepen++;
		kopija/=3;
	}
	stepen=1;
	for(int i=0;i<najveci_stepen;i++) {
		stepen*=3;
	}
	for(int i=0;;i++) {
		if(broj-stepen>=0) broj-=stepen;
		else {
			ternarna_reprezentacija.push_back(i);
			break;
		}
	}
	for(int j=najveci_stepen-1;j>=0;j--) {
		stepen=1;
		for(int k=0;k<j;k++) {
			stepen*=3;
		}
		for(int l=0;;l++) {
			if(broj-stepen>=0) broj-=stepen;
			else {
				ternarna_reprezentacija.push_back(l);
				break;
			}
		}
	}
	int broj_pojavljivanja;
	for(int m=0;m<ternarna_reprezentacija.size();m++) {
		broj_pojavljivanja=0;
		for(int n=0;n<ternarna_reprezentacija.size();n++) {
			if(ternarna_reprezentacija[m]==ternarna_reprezentacija[n]) broj_pojavljivanja++;
		}
		if(broj_pojavljivanja%2!=0 && opak==true) return false;
		else if(broj_pojavljivanja%2!=1 && opak==false) return false;
	}
	return true;
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool gadan) {
	std::vector<int> novi;
	if(gadan) {
		for(int i=0;i<v.size();i++) {
			for(int j=i+1;j<v.size();j++) {
				if(v[i]==v[j]) {
					for(int k=j;k<v.size()-1;k++) {
						v[k]=v[k+1];
					}
					j--;
					v.resize(v.size()-1);
				}
			}
			if(Opaki(v[i],true)) novi.push_back(v[i]);
		}
	}
	else {
		for(int i=0;i<v.size();i++) {
			for(int j=i+1;j<v.size();j++) {
				if(v[i]==v[j]) {
					for(int k=j;k<v.size()-1;k++) {
						v[k]=v[k+1];
					}
					j--;
					v.resize(v.size()-1);
				}
			}
			if(Opaki(v[i],false)) novi.push_back(v[i]);
		}
	}
	return novi;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	std::vector<int> v;
	do{
		std::cin>>broj;
		if(broj!=0) v.push_back(broj);
	}while(broj!=0);
	std::vector<int> opaki=IzdvojiGadne(v,true);
	std::vector<int> odvratni=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++) {
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0;i<odvratni.size();i++) {
		std::cout<<odvratni[i]<<" ";
	}
	return 0;
}