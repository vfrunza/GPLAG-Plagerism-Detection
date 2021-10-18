/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst( int n){
	if(n<2) return false;
	double a=std::sqrt(n);
	for(int i=2;i<=a;i++) {
		if(n%i==0) return false;
		
	}
		return true;
	
}

std::vector<int> IzdvojiSimetricneTernarne( std::vector<int>v, bool vrijednost){
std::vector<int>V_prosti;
std::vector<int>V_slozeni;


for (int i=0;i<v.size();i++) {
	int e=v.at(i);
	if(DaLiJeProst(e)==1) {
		V_prosti.push_back(e);
	}
	else {
	V_slozeni.push_back(e);
}
}
int brojac1(0);
int element1(0),pomocni1(0),isti1(0),novi_element1(0),element2(0),pomocni2(0),isti2(0);
std::vector<int>V_elem1,V_elem2,v_brojac1,v_brojac2,V_prosti_t,V_slozeni_t;
for(int i=0;i<V_prosti.size();i++) {
	element1=V_prosti.at(i);
	if(element1==0) i++;
	if(element1!=0){
	do {
	
		  novi_element1=abs(element1%3);
		  V_elem1.push_back(novi_element1);
		  element1=abs(element1/3);
		  brojac1++;
		  
	} while(element1!=0);
		
	}
	v_brojac1.push_back(brojac1);
	brojac1=0;
}

int POM1(0);
for(int i=0;i<V_prosti.size();i++){
	int j=0,k=0;
	while(k<V_elem1.size()-1 && j<(v_brojac1.size())){
		pomocni1=(v_brojac1.at(j));
		if (V_elem1.at(k)==V_elem1.at(pomocni1-k-1)){
			isti1++;
			k++;
			
		}
			if (isti1==v_brojac1.at(j)-1) {
				POM1=V_prosti.at(i);
				V_prosti_t.push_back(POM1);
				isti1=0;
				while(k>=0){
					V_elem1.erase(V_elem1.begin()+k);
					k--;
					
				}
				i++;
				j++;
				k=0;
				
			}
			else if (V_elem1.at(k)!=V_elem1.at(pomocni1-k-1)) {
				i++;
				k=v_brojac1.at(j)-1;
				while(k>=0){
					V_elem1.erase(V_elem1.begin()+k);
					k--;
				}
				k=0;
				if(k==V_elem1.size()) break;
				j++;
			}
	
		
	}
}
	

int novi_element2(0),brojac2(0);
for(int i=0;i<V_slozeni.size();i++){
	element2=V_slozeni.at(i);
	if(element2==0) i++;
	if(element2!=0) {
		do {
			novi_element2=abs(element2)%3;
			V_elem2.push_back(novi_element2);
			element2=abs(element2)/3;
			brojac2++;
		} while(element2>0);
	}
	v_brojac2.push_back(brojac2);
	brojac2=0;
}
int POM2(0),m(0),n(0);
for(int s=0;s<V_slozeni.size();s++) {
	while(n<V_elem2.size()-1 && m<(v_brojac2.size())) {
		pomocni2=v_brojac2.at(m);
		if(V_elem2.at(n)==V_elem2.at(pomocni2-n-1)) {
			isti2++;
			n++;
		}
		if(isti2==v_brojac2.at(m)-1) {
			POM2=V_slozeni.at(s);
			V_slozeni_t.push_back(POM2);
			isti2=0;
			while(n>=0) {
				V_elem2.erase(V_elem2.begin()+n);
				n--;
			}
			s++;
			m++;
			n=0;
		}
		else if(V_elem2.at(n)!=V_elem2.at(pomocni2-n-1)) {
			s++;
			n=v_brojac2.at(m)-1;
			while(n>=0) {
				V_elem2.erase(V_elem2.begin()+n);
				n--;
			}
			n=0;
			if(n==V_elem2.size()) break;
			m++;
		}
		
	}
	
}
		for(int i=0;i<V_prosti_t.size();i++){
		for(int j=i+1;j<V_prosti_t.size();j++){
			if(V_prosti_t.at(i)==V_prosti_t.at(j))
			V_prosti_t.erase(V_prosti_t.begin()+j);
		}
}	
	for(int k=0;k<V_slozeni_t.size();k++){
		for(int l=k+1;l<V_slozeni_t.size();l++){
			if(V_slozeni_t.at(k)==V_slozeni_t.at(l))
			V_slozeni_t.erase(V_slozeni_t.begin()+l);
			
		}
	}
		
	


		
if (vrijednost==1) return V_prosti_t;
else if(vrijednost==0) return V_slozeni_t;
	
}
int main ()
{
	int e(0);
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		std::cin>>e;
		if(e==-1) break;
		v.push_back(e);
	}
	int vrijednost(0);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
	std::cin>>vrijednost;
	if (vrijednost==1) break; 
	else if (vrijednost==0) break;
	else {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	
	}
	
	v=IzdvojiSimetricneTernarne(v,vrijednost);
	if(vrijednost==1){
		if(v.size()>0){
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<v.size();i++) {
		if(i==v.size()-1) std::cout<<v.at(i);
		else std::cout<<v.at(i)<<", ";
	}
	std::cout<<std::endl;
		
	}
	else std::cout<<"Nema prostih simetricnih brojeva u vektoru."; 
		
	}
	else if(vrijednost==0) {
		if(v.size()>0){
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0;i<v.size();i++) {
				if(i==v.size()-1) std::cout<<v.at(i)<<".";
			else	std::cout<<v.at(i)<<", ";
		}
		std::cout<<std::endl;
	}
	else std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
		
	}
	return 0;
}