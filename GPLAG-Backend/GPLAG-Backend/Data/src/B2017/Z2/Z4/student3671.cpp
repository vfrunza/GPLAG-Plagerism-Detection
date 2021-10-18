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
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <type_traits>
using namespace std;

bool DaLiJeProst(int n)
{
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int SumaProsti(int n)
{
	int br(0);
	int i(2);
	while(n!=1) {
		if(n%i==0) {
			if(DaLiJeProst(i)) {
				n/=i;
				br++;
				i--;
			}
		}
		i++;
	}
	return br;
}

template<typename Tip>
void Razmijeni(Tip &x,Tip &y)
{
	Tip pom(move(x));
	x=move(y);
	y=move(pom);
}

template<typename Tip1,typename Tip2,typename Funtip>
void SortirajPodrucjeVrijednosti(Tip1 p1,Tip1 kraj1,Tip1 p3,Tip2 p4,Funtip f,bool (*f2)(int,int))
{
	int vel=kraj1-p1;
	sort(p1,kraj1,f2);
	sort(p3,p3+vel,f2);
	typedef typename remove_reference<decltype(*p4)>::type tip;
	tip povratni {0};
	Tip2 pozicija {0};
	Tip2 pocetak {p4};
	while(p1!=kraj1) {
		povratni=f(*p1,*p3);
		pozicija=find(pocetak,pocetak+vel,povratni);
		if(pozicija==pocetak+vel){
			throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		Razmijeni(*p4,*pozicija);
		p1++;
		p3++;
		p4++;
	}
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata: ";
	cin>>n;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		cin>>broj;
		bool isti(false);
		for(int j=0; j<v1.size(); j++) {
			if(broj==v1[j]) {
				isti=true;
				break;
			}
		}
		if(!isti) v1.push_back(broj);
		else i--;
	}
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		cin>>broj;
		bool isti(false);
		for(int j=0; j<v2.size(); j++) {
			if(broj==v2[j]) {
				isti=true;
				break;
			}
		}
		if(!isti) v2.push_back(broj);
		else i--;
	}
	cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		cin>>broj;
		bool isti(false);
		for(int j=0; j<v3.size(); j++) {
			if(broj==v3[j]) {
				isti=true;
				break;
			}
		}
		if(!isti) v3.push_back(broj);
		else i--;
	}
	try {
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),[] (int x, int y) {
			return -2*x+y;
		},[] (int x,int y) -> bool {
			return SumaProsti(x)<SumaProsti(y);
		});
	} catch(logic_error x) {
		cout<<"\nIzuzetak: "<<x.what()<<endl;
		return 0;
	}
	cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
	for(int i=0; i<n; i++) {
		cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<endl;
	}
	return 0;
}