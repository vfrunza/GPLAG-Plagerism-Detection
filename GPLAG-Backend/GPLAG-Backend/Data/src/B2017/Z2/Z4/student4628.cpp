#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

template <typename tip1, typename tip2, typename tip3, typename tip4, typename tip5>
void SortirajPodrucjeVrijednosti(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip3 pocetak3, tip5 funkcija(tip4,tip4), bool Sortiranje(tip4,tip4)) {
	
	
	std::sort(pocetak1, kraj1, Sortiranje);
	
	int duzina=0;
	auto priv(pocetak1);
	while(priv!=kraj1){ duzina++; priv++; }

	duzina--;
	std::sort(pocetak2, pocetak2+duzina+1, Sortiranje); 

	bool pronadjeno(false);
	auto pom1=pocetak1, pom2=pocetak2, pom3=pocetak3;

	while(pom1!=kraj1) {

	auto it(std::find(pom3,pom3+duzina, funkcija(*pom1,*pom2)));

	if(it!=pom3+duzina || *it==funkcija(*pom1,*pom2)){
		
		pronadjeno=true;
		auto tmp(*pom3);
		*pom3=*it;
		*it=tmp;
	}

			
		if(pronadjeno==false) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");  
		pom1++; pom2++; pom3++; duzina--;  pronadjeno=false;
		}
}

	
		
			
		


int funkcija(int x, int y) {

	return -2*x+y;
}

bool JeLiProst(int x) {
	if(x<0) x*=-1;
	if(x==0 || x==1) return false;
	if(x>2) {
		for(int i=2; i<=std::sqrt(x); i++)
		if(x%i==0) return false;
	}
	return true;
}

bool ProstiFaktori(int x, int y) {
	int broj1(0), broj2(0);
	int tmp1(std::abs(x));
	for(int i=1; i<tmp1; i++) {
		if((x%i==0) && JeLiProst(i)) {
			broj1++;
			tmp1/=i;
			i--;
		}
	}

	int tmp2(std::abs(y));
	for(int i=1; i<tmp2; i++) {
		if((y%i==0) && JeLiProst(i)) {
			broj2++;
			tmp2/=i;
			i--;
		}
	}

	if(JeLiProst(x)) broj1=0;
	if(JeLiProst(y)) broj2=0;
	if(broj1==broj2) return (x>y);

	return broj1>broj2;
}

int main ()
{
	cout<<"Unesite broj elemenata: ";
	int n;
	cin>>n;
	std::vector<int> v1;
	int broj;
	cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++) {
		cin>>broj;
		bool pojavljivanje(false);
		for(int j=0; j<v1.size(); j++) 
			if(v1[j]==broj) {
				pojavljivanje=true;
				i--;
			}
		
		if(!(pojavljivanje)) v1.push_back(broj);
	}

	
	std::vector<int> v2;
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) {
		cin>>broj;
		bool pojavljivanje(false);
		for(int j=0; j<v2.size(); j++) 
			if(v2[j]==broj) {
			 i--;	
			 pojavljivanje=true;
			}
		
		if(!(pojavljivanje)) v2.push_back(broj);
	}

	std::vector<int> v3;
	cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++) {
		cin>>broj;
		bool pojavljivanje(false);
		for(int j=0; j<v3.size(); j++) 
			if(v3[j]==broj) {
				pojavljivanje=true;
				i--;
			}
		if(!(pojavljivanje)) v3.push_back(broj);
	} 

	cout<<std::endl;
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), funkcija, ProstiFaktori);
		cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for(int i=0; i<v3.size(); i++) cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
	}
	catch(std::logic_error izuzetak) {
		cout<<"Izuzetak: "<<izuzetak.what();
	}

	
	
	return 0;
}