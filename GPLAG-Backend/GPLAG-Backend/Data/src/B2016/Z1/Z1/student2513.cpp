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
using std::cout;
using std::cin;
typedef std::vector<int>vektor;


bool OpakiBrojevi(int broj)
{
	vektor v(0);
	int brojac=0, i;
	if(broj==0) v.push_back(0);
	while(broj!=0) {
		int cifra=std::abs(broj%3);
		v.push_back(cifra);
		broj=broj/3;
	}

	for(i=0; i < v.size(); i++) { brojac=0;
		for(int j=0; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) brojac ++;
		}
		if(brojac%2!=0) break;
	}
	if(i==v.size()) return true;
	return false;
}

bool OdvratniBrojevi(int broj)
{
	vektor v(0);
	int brojac=0, i;
	broj=abs(broj);
	while(broj!=0) {
		int cifra=broj%3;
		v.push_back(cifra);
		broj=broj/3;
	}

	for(i=0; i < v.size(); i++) { brojac=0;
		for(int j=0; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) brojac ++;
		}
		if(brojac%2==0) return false;
	}
	return true;
	
}

vektor IzdvojiGadne(vektor v, bool tacnost)
{
	vektor v1(0);
	if(tacnost==true) {
		for (int i=0; i<v.size(); i++) {
			if(OpakiBrojevi(v.at(i))==true) v1.push_back(v.at(i));
		}
	} 
	if(tacnost==false) {
		for (int i=0; i<v.size(); i++) {
			if(OdvratniBrojevi(v.at(i))==true) v1.push_back(v.at(i));
		}
	
	}
	for(int i=0; i<v1.size(); i++){
		for(int j=i+1; j<v1.size(); j++){
			if(v1.at(i)==v1.at(j)){
				v1.erase(v1.begin()+j);
				i=0;
			}
		}
	}
	
    return v1;
	
}
	int main () {
		vektor v(0);
		int broj;
		cout << "Unesite brojeve (0 za prekid unosa): ";
		while(1){
			cin>>broj;
			if(broj==0) break;
			v.push_back(broj);
		}
		vektor v1=IzdvojiGadne(v,true);
		vektor v2=IzdvojiGadne(v,false);
		
		cout << "Opaki: ";
		for(int i=0; i<v1.size(); i++) cout << v1[i] << " ";
		cout << std::endl;
		cout << "Odvratni: ";
		for(int i=0; i<v2.size(); i++) cout << v2[i] << " ";
	
		return 0;
	}