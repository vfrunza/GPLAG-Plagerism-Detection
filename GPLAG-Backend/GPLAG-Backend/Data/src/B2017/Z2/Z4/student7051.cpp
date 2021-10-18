/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <type_traits>
int Funkcija (int x, int y){
	return -2*x+y;
}
bool DaLiJeProst (int x){
	if (x<=1) return false;
	for (int i=2; i<=std::sqrt(x);i++)
	if (x%i==0) return false;
	return true;
}
int BrojProstih (int x){
	int brojac(0);
	if (x<0) x=-1*x;
	for (int i=1;i<x;i++) {
		if (x%i==0) {
			x/=i;
			if (DaLiJeProst(i)) {
				brojac++;
			}
			i=1;
		}
	}
	return brojac;
}
bool PrviImaViseProstihFaktora (int x, int y){
	if (BrojProstih(x)>BrojProstih(y)) return true;
	else if (BrojProstih(x)==BrojProstih(y) && x>y) return true;
	else return false;
}
template <typename IterTip1, typename IterTip2, typename IterTip3> 
void SortirajPodrucjeVrijednosti (IterTip1 pocetak1, IterTip1 iza_kraja1, IterTip2 poc1, IterTip3 poc2, auto F1 (typename std::remove_reference<decltype(*pocetak1)>::type, typename std::remove_reference<decltype(*poc1)>::type)->typename std::remove_reference<decltype(*poc2)>::type, bool F2(typename std::remove_reference<decltype(*pocetak1)>::type,typename std::remove_reference<decltype(*poc1)>::type))
{
	int broj_elemenata(iza_kraja1-pocetak1);
	sort (pocetak1, iza_kraja1, F2);
	sort (poc1, poc1+broj_elemenata,F2);
		for (int i=0;i<broj_elemenata;i++){
			int j(0);
			for (j=0;j<broj_elemenata;j++){
				if (F1(*(pocetak1+i),*(poc1+i))==*(poc2+j)) break;
			}
			if (j==broj_elemenata) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		for (int i=0;i<broj_elemenata;i++){
		*(poc2+i)=F1(*(pocetak1+i),*(poc1+i));
		}
}
int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::vector<int> v1(0);
	std::cout<<"Unesite elemente prvog vektora: ";
	for (int i=0;i<n;i++){
		int a(0);
		std::cin>>a;
		bool VecSeNalazi=false;
		for (int i=0;i<v1.size();i++) {
			if (a==v1.at(i)){
				VecSeNalazi=true;
			}
		}
		if (VecSeNalazi==true) {
			i--;
			continue;
		}
		v1.push_back(a);
	}
	std::cin.ignore(1000,'\n');
		std::vector<int> v2(0);
	std::cout<<"Unesite elemente drugog vektora: ";
		for (int i=0;i<n;i++){
		int a(0);
		std::cin>>a;
		bool VecSeNalazi=false;
		for (int i=0;i<v2.size();i++) {
			if (a==v2.at(i)){
				VecSeNalazi=true;
			}
		}
		if (VecSeNalazi==true) {
			i--;
			continue;
		}
		v2.push_back(a);
	}
	std::cin.ignore(1000,'\n');
		std::vector<int> v3(0);
	std::cout<<"Unesite elemente treceg vektora: ";
		for (int i=0;i<n;i++){
		int a(0);
		std::cin>>a;
		bool VecSeNalazi=false;
		for (int i=0;i<v3.size();i++) {
			if (a==v3.at(i)){
				VecSeNalazi=true;
			}
		}
		if (VecSeNalazi==true) {
			i--;
			continue;
		}
		v3.push_back(a);
	}
	try{
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),Funkcija,PrviImaViseProstihFaktora);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for (int i=0;i<v1.size();i++) std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	}
	catch (std::logic_error e){
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	}
	
	return 0;
}