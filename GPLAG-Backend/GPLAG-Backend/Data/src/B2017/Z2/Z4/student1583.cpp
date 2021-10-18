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
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool Prost(int n){
	
	if(n<0) n*=-1;
	if(n==1 || n==0) return false;
	
	for(int i=2;i<=std::sqrt(n);i++){
		if(n%i==0) return false;
	}
	
	return true;
}

int br_prostih_faktora(int n){
	if(n<0) n*=-1;
	if(n==1 || n==0) return 0;
	if(Prost(n)) return 1;
	
	int broj_prostih_faktora(0);
	
	for(int i=2;i<=n/2;i++){
		if(n%i==0 && Prost(i)){
			while(n!=1){
				broj_prostih_faktora++;
				n/=i;
			}
		}
	}
	
	return broj_prostih_faktora;
}

bool Opadajuci_poredak_br_prostih_faktora(int x, int y){
	
	return ( br_prostih_faktora(x)>br_prostih_faktora(y) || ( br_prostih_faktora(x)==br_prostih_faktora(y) && x>y) );
}

int f(int x, int y){ return -2*x+y;}

template<typename IterTip1, typename IterTip2, typename IterTip3, typename NekiTip>
bool Nalazi_se(IterTip1 poc1, IterTip1 iza_kraja1, IterTip2 poc2,IterTip3 poc3,  decltype(*poc3+*poc3) f(decltype(*poc1+*poc1),decltype(*poc1+*poc1)), NekiTip temp){
	
	if(poc1==iza_kraja1-1) return false;
	
	poc1++;
	poc2++;

	while(poc1!=iza_kraja1){
	auto rezultat (f(*poc1,*poc2));
		if(rezultat==temp)
		return true;
		poc1++;
		poc2++;
		}
		
	return false;
	

}

template<typename IterTip1, typename IterTip2, typename IterTip3>
void SortirajPodrucjeVrijednosti(IterTip1 poc1, IterTip1 iza_kraja1, IterTip2 poc2, IterTip3 poc3, decltype(*poc3+*poc3) f(decltype(*poc1+*poc1),decltype(*poc1+*poc1)), bool g(decltype(*poc1+*poc1),decltype(*poc1+*poc1))){
	
	int duzina(iza_kraja1-poc1);
	
	IterTip2 iza_kraja2(poc2);
	for(int i=0;i<duzina;i++)iza_kraja2++; // iza_kraja2 je tacno iza kraja drugog bloka
	
	IterTip3 iza_kraja3(poc3);
	for(int i=0;i<duzina;i++)iza_kraja3++; // iza_kraja3 je tacno iza kraja treceg bloka
	
	IterTip3 kopija_poc3(poc3);
	
	std::sort(poc1,iza_kraja1,g);
	std::sort(poc2,iza_kraja2,g);
	
	auto poc1_2(poc1);
	auto poc2_2(poc2);
	auto poc3_2(poc3);

	
	
	int cnt(0);
	while(poc1!=iza_kraja1){
	
		poc3=kopija_poc3;
		
		auto rezultat (f(*poc1,*poc2));
		
		bool pronadjen_rezultat{false};
		
		while(poc3!=iza_kraja3){
			
		if(*poc3==rezultat){
		pronadjen_rezultat=true;
		break;

		}
		
		poc3++;

		
		}
		
		
			
			if(pronadjen_rezultat){
				auto temp(*poc3);
				auto temp2 (*(kopija_poc3+cnt));
				bool nalazi_se (Nalazi_se(poc1_2,iza_kraja1,poc2_2,kopija_poc3, f,temp2));
			
			
				*(kopija_poc3+cnt)=temp;
				
				if(nalazi_se) *poc3=temp2;
		
			}
		if(!pronadjen_rezultat) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		poc1++; poc2++;
		cnt++;
	}
	
}

int main ()
{
	
	int br_elemenata;
	cout<<"Unesite broj elemenata: ";
	cin>>br_elemenata;
	int clan;
	
	std::vector<int> v1,v2,v3;
	
	cout<<"Unesite elemente prvog vektora: ";
	for(int i=0;i<br_elemenata;i++){
		cin>>clan;
		bool nalazi_se=false;
		for(int x : v1) if(x==clan) { i--; nalazi_se=true;break;}
		if(!nalazi_se) v1.push_back(clan);
	}
	std::cin.ignore(10000,'\n');
	
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0;i<br_elemenata;i++){
		cin>>clan;
		bool nalazi_se=false;
		for(int x : v2) if(x==clan) { i--; nalazi_se=true;break;}
		if(!nalazi_se) v2.push_back(clan);
	}
	std::cin.ignore(10000,'\n');
	
	cout<<"Unesite elemente treceg vektora: ";
	for(int i=0;i<br_elemenata;i++){
		cin>>clan;
		bool nalazi_se=false;
		for(int x : v3) if(x==clan) { i--; nalazi_se=true;break;}
		if(!nalazi_se) v3.push_back(clan);
	}
	std::cin.ignore(10000,'\n');
	
	try{
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f, Opadajuci_poredak_br_prostih_faktora);
	cout<<endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<endl;
	for(int i=0;i<br_elemenata;i++)
		cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<endl;
	}
	catch(std::logic_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what()<<endl;
	}

	
	return 0;
}




