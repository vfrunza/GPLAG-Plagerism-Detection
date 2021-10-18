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
#include <vector>
#include <algorithm>
#include <utility>
#include<stdexcept>
int funkcija(int a, int b){
	return (-2)*a+b;
}

bool Prost(int x){
	if(x==1 || x==2) return true;
	for(int i=2;i<x;i++){
		if(x%i==0) return false;
	}
	return true;
}

bool funkcija1 (int x,int y){
	int brojacX(0);
	int brojacY(0);
	int a(x),b(y);
	for(int i=2;i<=x;i++){
		if(x%i==0 && Prost(i)==true) {
			brojacX++;
			x=x/i;
			if(x==1) break;
			i--;
		}
	}
	for(int i=2;i<=y;i++){
		if(y%i==0 && Prost(i)==true) {
			brojacY++;
			y=y/i;
			if(y==1) break;
			i--;
		}
	}
	
	if(brojacX==brojacY){
		if(a>b) return true;
		else return false;
	}else if(brojacX>brojacY) return true;
	else return false;
}



template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, decltype(*p4+0) f(decltype(*p1+0),decltype(*p3+0)),bool f1(decltype(*p1+0), decltype(*p3+0))){
	
	std::sort(p1,p2,f1);
	/*Tip1 pocetak(p1);
	do{
		std::cout<<*pocetak<<" ";
	}while(pocetak++<p2);
	*/
	int br_elemenata(p2-p1);
	std::sort(p3,p3+br_elemenata,f1);
/*	Tip2 pocetak(p3);
	do{
		std::cout<<*pocetak<<" ";
	}while(pocetak++<br_elemenata+p3);
*/	
	Tip3 duzina(p4+br_elemenata);
	Tip3 pok(p4);
	int brojac(0);
	bool x;
	while(p1<p2){
		x=false;
		p4=pok;
		while(p4<duzina){
				
				if(f(*p1,*p3)==*p4) {
				std::swap(*(pok+brojac),*p4);
				x=true;
				break;
			}
			p4++;
		};
		if(x==false) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		brojac++;
		p1++;
		p3++;
	};
	
}

int main ()
{
	try {
	
		int n;
		std::cout<<"Unesite broj elemenata: ";
		std::cin>>n;
		std::cout<<"Unesite elemente prvog vektora: ";
		std::vector<int> blok1;
		std::vector<int> blok2;
		std::vector<int> blok3;
		int broj;
		for(int i=0;i<n;i++){
			bool ponavljanje(false);
			std::cin>>broj;
			for(int j=0;j<i;j++){
				if(broj==blok1.at(j)){
					ponavljanje=true;
					i--;
					break;
				}
			}
			if(!ponavljanje) blok1.push_back(broj);
		} 
		
		std::cout<<"Unesite elemente drugog vektora: ";
		for(int i=0;i<n;i++){
			bool ponavljanje(false);
			std::cin>>broj;
			for(int j=0;j<i;j++) {
				if(broj==blok2.at(j)){
					ponavljanje=true;
					i--;
					break;
				}
			}
			if(!ponavljanje) blok2.push_back(broj);
		}
	
		std::cout<<"Unesite elemente treceg vektora: "<<std::endl;;
		for(int i=0;i<n;i++){
			std::cin>>broj;
			bool ponavljanje(false);
			for(int j=0;j<i;j++){
				if(broj==blok3.at(j)) {
					ponavljanje=true;
					i--;
					break;
				}	
			}
			if(!ponavljanje) blok3.push_back(broj);
			
		}
		
		
		SortirajPodrucjeVrijednosti(blok1.begin(),blok1.end(),blok2.begin(),blok3.begin(),funkcija,funkcija1);
		std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		n=blok1.size();
		for(int i=0;i<n;i++){
			std::cout<<"f("<<blok1.at(i)<<", "<< blok2.at(i)<<") = "<<blok3.at(i)<<std::endl;
		}
	}
	catch(std::logic_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}