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
#include <stdexcept>
using namespace std;


template<typename T1, typename T2, typename T3>
void SortirajPodrucjeVrijednosti(T1 p1, T1 q1, T2 p2, T3 p3,
                                 auto(f)(decltype(*p1+*p1),decltype(*p2+*p2))-> decltype(*p3+*p3),
                                 bool(f2)(decltype(*p1+*p1),decltype(*p2+*p2))
                                )
{
	T2 q2 = p2 + (q1-p1);
	T3 q3 = p3 + (q1-p1);

	sort(p1, q1, f2);
	sort(p2, q2,f2);


	T1 pocetak1 = p1;
	T2 pocetak2 = p2;
	while(p1<q1) {
		decltype(*p3+*p3) rezultat = f(*p1,*p2);
		if( find(p3,q3,rezultat) == q3) {
			throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		p1++;
		p2++;
	}

	p1 = pocetak1;
	p2 = pocetak2;

	while(p1<q1) {
		decltype(*p3+*p3) rezultat = f(*p1,*p2);
		*p3 = rezultat;
		p1++;
		p2++;
		p3++;
	}

}

int f(int x, int y)
{
	return -2*x+y;
}


bool prost(int broj)
{
	if(broj==1)return false;
	for (int i = 2; i < broj; i++) {
		if(broj%i==0)return false;
	}
	return true;
}

int broj_prostih_faktora(int broj)
{
	int brojac = 0;
	if(broj<=1) return 0;
	while(true) {
		if(prost(broj)) {
			brojac++;
			return brojac;
		}
		for (int i = 2; i < broj; i++) {
			if(prost(i)&&broj%i==0) {
				broj=broj/i;
				brojac++;
				break;
			}
		}

	}
}

bool kriterij_po_broju_prostih_faktora(int x, int y)
{
	int brp1 = broj_prostih_faktora(x);
	int brp2 = broj_prostih_faktora(y);
	if( brp1>brp2) return true;
	else if(brp1==brp2){ return x>y;}
	else{ return false;}
}




int main ()
{

try{
	cout<<"Unesite broj elemenata: ";
	int broj_elemenata;
	cin>>broj_elemenata;
	vector<int>v1;
	int broj;
	cout<<"Unesite elemente prvog vektora: ";
	for (int i = 0; i < broj_elemenata; i++) {
		cin>>broj;
		if(find(v1.begin(),v1.end(),broj)!=v1.end()){
			i--;
			continue;
		}
		v1.push_back(broj);
	}

	vector<int>v2;
	cout<<"Unesite elemente drugog vektora: ";
	for (int i = 0; i < broj_elemenata; i++) {
		cin>>broj;
		if(find(v2.begin(),v2.end(),broj)!=v2.end()){
			i--;
			continue;
		}
		v2.push_back(broj);
	}
	
	vector<int>v3;
	cout<<"Unesite elemente treceg vektora: ";
	for (int i = 0; i < broj_elemenata; i++) {
		cin>>broj;
		if(find(v3.begin(),v3.end(),broj)!=v3.end()){
			i--;
			continue;
		}
		v3.push_back(broj);
	}
	
	
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f,kriterij_po_broju_prostih_faktora);
	cout<<endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
	for (int i = 0; i < v1.size(); i++) {
		cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<endl;
	}

}
catch(logic_error e){
	cout<<endl<<"Izuzetak: "<<e.what()<<endl;
}
	return 0;
}