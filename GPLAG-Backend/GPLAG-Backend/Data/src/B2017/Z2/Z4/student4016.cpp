/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <vector>

template <typename IterTip1, typename IterTip2, typename IterTip3, typename FunTip1, typename FunTip2>
void SortirajPodrucjeVrijednosti(IterTip1 pocetak1, IterTip1 kraj1, IterTip2 pocetak2, IterTip3 pocetak3, FunTip1 f, FunTip2 sortiranje){
	
	sort(pocetak1, kraj1, sortiranje);
	
	auto temppocetak=pocetak1;
	int br(0);
	while(temppocetak!=kraj1) {
		temppocetak++;
		br++;}
	
	sort(pocetak2, pocetak2+br, sortiranje);
	for(int i=0; i<br; i++){
		auto rezultat=f(*(pocetak1+i),*(pocetak2+i));
	
		if(std::find(pocetak3, pocetak3+br, rezultat) != pocetak3+br){
			for(int j=i; j<br; j++){
				if(rezultat==*(pocetak3+j)){
					for(int k=0; k<j-i; k++) {	*(pocetak3+j-k)=*(pocetak3+j-k-1); }
					*(pocetak3+i)=rezultat;
				}
			}
		}
		else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> s1, s2, s3;
	int i(0);
	int a;
	std::cout<<"Unesite elemente prvog vektora: ";
	while(i!=n){
		std::cin>>a;
		if(std::find(s1.begin(), s1.end(), a) ==s1.end()){
			s1.push_back(a);
			i++;
		}
	}
		
    i=0;	std::cout<<"Unesite elemente drugog vektora: ";
	while(i!=n){
		std::cin>>a;
		if(std::find(s2.begin(), s2.end(), a)==s2.end()){
			s2.push_back(a);
			i++;
		}
	}
	
	i=0;
	std::cout<<"Unesite elemente treceg vektora: ";
	while(i!=n){
		std::cin>>a;
		if(find(s3.begin(), s3.end(), a)==s3.end()){
			s3.push_back(a);
			i++;
		}
	}
	try{
	SortirajPodrucjeVrijednosti(s1.begin(), s1.end(), s2.begin(), s3.begin(), [](int x, int y){return -2*x+y;}, [](int a, int b){
		int a1=a;
		int b1=b;
		int br_a(0);
		while(a%2==0){
			br_a++;
			a/=2;
		}
		for(int i=3; i<sqrt(a); i+=2){
			while(a%i==0){
				br_a++;
				a/=2;
			}
		}
		if(a>2) br_a++;
		
		
		int br_b(0);
		while(b%2==0){
			br_b++;
			b/=2;
		}
		for(int i=3; i<sqrt(b); i+=2){
			while(b%i==0){
				br_b++;
				b/=2;
			}
		}
		if(b>2) br_b++;
		
		if(br_a==br_b) return(a1 > b1);
		
		return(br_a > br_b);
	});
	
	std::cout <<std::endl;
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
	for(int i=0; i<n; i++){
		std::cout<<"f("<<s1.at(i)<<", "<<s2.at(i)<<") = "<<s3.at(i)<<std::endl;
	}
	
	}
	
	catch(std::logic_error izuzetak){
		std::cout<<std::endl;
		std::cout<<"Izuzetak: " << izuzetak.what();
	}
	return 0;
}