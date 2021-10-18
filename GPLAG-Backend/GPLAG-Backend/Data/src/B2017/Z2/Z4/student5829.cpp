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
#include <cmath>
#include <algorithm>
#include <stdexcept>
using std::vector;
using std::cout;
using std::cin;

void Unesi(vector<int> &v,int n){
	for(int i(0);i<n;i++){
		int k(0);
		cin>>k;
		if(count(v.begin(),v.end(),k)==0) v.push_back(k);
		else i--;
	}
}

int BrojProstihFakt(int x){
	if(x==0 || x==1) return 1;
	int suma(0),i(2);
	while(x!=1){
		if(x%i==0){
			suma++;
			x/=i;
		}
		else i++;
	}
	return suma;
}

bool Kriterij(int x, int y){
	int pfx(BrojProstihFakt(abs(x)));
	int pfy(BrojProstihFakt(abs(y)));
	if(pfx==pfy) return x>y;
	return pfx>pfy;
}

int F1(int a,int b){
	return -2*a+b;
}

template<typename NekiTip1, typename NekiTip2, typename NekiTip3>
	void SortirajPodrucjeVrijednosti(NekiTip1 a0, NekiTip1 a1, NekiTip2 b0, NekiTip3 c0,
	decltype(*c0+*c0) f1(decltype(*a0+*a0),decltype(*a0+*a0)),bool f2(decltype(*a0+*a0),decltype(*a0+*a0))){
		int i(0),j(0);
		NekiTip1 pom(a0);
		while(pom!=a1){ pom++; i++; }
		sort(a0,a1,f2);
		sort(b0,b0+i,f2);
		while(a0!=a1){
			decltype(*c0+*c0) rez=f1(*a0,*b0);
			auto it=find(c0,c0+i,rez);
			if(it!=c0+i){
				decltype(*c0+*c0) pom1=*(c0+j);
				*(c0+j)=*it;
				*it=pom1;
			}
			else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			j++; a0++; b0++;
		}
	}

int main ()
{
	int n(0);
	cout<<"Unesite broj elemenata: ";
	cin>>n;
	try{
		vector<int> v1,v2,v3;
		cout<<"Unesite elemente prvog vektora: ";
		Unesi(v1,n);
		cout<<"Unesite elemente drugog vektora: ";
		Unesi(v2,n);
		cout<<"Unesite elemente treceg vektora: ";
		Unesi(v3,n);
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),F1,Kriterij);
		cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
		for(int i(0);i<n;i++){
			cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}
	}
	catch(std::logic_error izuzetak){
		cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	
	return 0;
}