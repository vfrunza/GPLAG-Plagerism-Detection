/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <type_traits>
#include <stdexcept>

bool ProstBroj(int broj){
	if(broj>=2){
		for(int i(2); i<broj-1; i++){
			if(broj%i==0)
				return false;
		}
		return true;
	}
	return false;
}
int BrojProstih(int broj){
	int brojpr(0);
	if(broj <=1) return brojpr;
	else{
	for(int i(2); i<=broj; i++){
		if(ProstBroj(i)){
			if(broj%i==0){
				brojpr++;
				broj=broj/i;
				i=1;
				if(broj==i) break;
			}
		}
	}
	}
	return brojpr;
}				
int f(int a, int b){
	return -2*a+b;
}
bool f2(int a, int b){
	int brojpr1(BrojProstih(a)), brojpr2(BrojProstih(b));
	if(brojpr1>brojpr2) return true;
	else if(brojpr1==brojpr2){
		if(a>b) return true;
		else return false;
	}
	return false;
}
template<typename ittip1,typename ittip2, typename ittip3, typename TIP12, typename TIP3>
void SortirajPodrucjeVrijednosti(ittip1 pocetak1, ittip1 iza_kraja1, ittip2 pocetak2, ittip3 pocetak3, TIP3 f(TIP12,TIP12), bool f2(TIP12,TIP12)){
	int brojac1(0);
	//typedef typename std::remove_reference<decltype(*pocetak1)>::type TIP12;
	//typedef typename std::remove_reference<decltype(*pocetak3)>::type TIP3;
	ittip1 pomocni1(pocetak1);
	ittip2 pomocni2(pocetak2);
	ittip3 trecapomocna(pocetak3);
	while(pomocni1!=iza_kraja1){
		brojac1++;
		pomocni1++;
	}
	pomocni1=pocetak1;
	std::sort(pocetak1, iza_kraja1, f2);
	std::sort(pocetak2, pocetak2+brojac1, f2);
	bool istina(false);
	while(pomocni1!=iza_kraja1){
		TIP12 a(*pomocni1), b(*pomocni2);
		TIP3 x=f(a, b);
		ittip3 pomocna3(pocetak3);
		while(pomocna3!=pocetak3+brojac1){
			if(x==*pomocna3){
				istina=true;
				break;
			}
			pomocna3++;
		}
		if(pomocna3==trecapomocna+brojac1) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pomocni1++;
		pomocni2++;
	}
	if(istina) std::transform(pocetak1, iza_kraja1, pocetak2, pocetak3, f);
}
int main ()
{
	try{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>> n;
	std::cout<<"Unesite elemente prvog vektora: ";
	std::vector<int> S1;
	std::vector<int> S2;
	std::vector<int> S3;
	int brojac(0);
	for(int i(0); i<n; i++){
		int x;
		std::cin>> x;
		brojac++;
		int j(0);
		for(j=0; j<S1.size(); j++){
			if(S1.at(j)==x){
				brojac--;
				i--;;
				break;
			}
		}
		if(j==S1.size()) S1.push_back(x);
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	brojac=0;
	for(int i(0); i<n; i++){
		int x;
		std::cin>> x;
		brojac++;
		int j(0);
		for(j=0; j<S2.size(); j++){
			if(S2.at(j)==x){
				brojac--;
				i--;;
				break;
			}
		}
		if(j==S2.size()) S2.push_back(x);
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	brojac=0;
	for(int i(0); i<n; i++){
		int x;
		std::cin>> x;
		brojac++;
		int j(0);
		for(j=0; j<S3.size(); j++){
			if(S3.at(j)==x){
				brojac--;
				i--;;
				break;
			}
		}
		if(j==S3.size()) S3.push_back(x);
	}
	SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), f,f2);
	std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
	for(int i(0); i<S3.size(); i++)
		std::cout<<"\nf("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i);
	} catch(std::logic_error greska){
		std::cout<<"\nIzuzetak: "<<greska.what();
	}
	return 0;
}