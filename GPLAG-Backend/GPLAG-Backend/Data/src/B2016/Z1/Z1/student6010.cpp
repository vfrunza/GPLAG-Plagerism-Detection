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
using std::endl;
std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) {
	std::vector<int> brojaci(10, 0), opakibrojevi, odvratni, rezultat;
	for(int i=0; i<v.size(); i++) {
		if(v[i]!=0) {
		int zamjena=fabs(v[i]), biljezim=0, bristih=0;
		std::vector<int> brojaci(10, 0);
		while(zamjena!=0) {
		brojaci[(zamjena%3)]++;
		zamjena=zamjena/3;
		} biljezim=0;
		for(int j=0; j<10; j++) {
			if(brojaci[j]!=0) bristih++;
		}
		for(int j=0; j<10; j++) {
			if(brojaci[j]!=0 && brojaci[j]%2==0) biljezim++;
		} if(biljezim==bristih) {
		bool ubaci=true;
		for(int j=0; j<opakibrojevi.size(); j++) {
			if(v[i]==opakibrojevi[j]) {ubaci=false; 
										break;}
		} if(ubaci) opakibrojevi.push_back(v[i]);
			
		}
		else if(biljezim!=bristih) {
			int biljezim2=0;
			for(int j=0; j<10; j++) {
				if(brojaci[j]!=0 && brojaci[j]%2!=0) biljezim2++;
			} if(biljezim2==bristih) {
				bool jedinstven=true;
				for(int j=0; j<odvratni.size(); j++) {
					if(v[i]==odvratni[j]) jedinstven=false;
				}
				if(jedinstven) odvratni.push_back(v[i]);}
		} } 
	}
	if(opaki==true) rezultat=opakibrojevi;
	else rezultat=odvratni;
	return rezultat;
}
int main ()
{
	std::vector<int> v;
	int a(1);
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(a!=0) {
		cin>>a;
		v.push_back(a);
		}
	auto v2(IzdvojiGadne(v, true));
	cout<<"Opaki: ";
	for(int i=0; i<v2.size(); i++) {
		cout<<v2[i]<<" ";
	} cout<<endl;
	auto v3(IzdvojiGadne(v, false));
	cout<<"Odvratni: ";
	for(int i=0; i<v3.size(); i++) {
		cout<<v3[i]<<" ";
	}
	return 0;
}