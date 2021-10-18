#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <type_traits>
using namespace std;
int prost(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	if(!n) return 1;
	return n;
}
int broj_prostih_faktora(int n){
	int brojac(0);
	for(int i=2;i<=n;i++){
		if(n%i==0 && prost(i)){
			n/=i;
			i--;
			brojac++;
		} 
	}
	return brojac;
}
int fun(int a, int b){
	return -2*a+b;
}
bool fj(int a, int b){
	if(broj_prostih_faktora(a)==broj_prostih_faktora(b)) return a>b;
	else return broj_prostih_faktora(a)>broj_prostih_faktora(b);
}
template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 a,Tip1 b,Tip2 c,Tip3 d, typename remove_reference<decltype(*d)>::type f(typename remove_reference<decltype(*a)>::type,typename remove_reference<decltype(*a)>::type), bool g(typename remove_reference<decltype(*a)>::type,typename remove_reference<decltype(*a)>::type)){
	sort(a,b,g);
	sort(c,c+(b-a),g);
	int n(b-a);
	Tip3 q(d+n);
	Tip3 p;
	while(a!=b && c!=c+n){
		p=find(d,d+n,f(*a,*c));
		a++;
		c++;
		if(p==q) throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	a-=n;
	c-=n;
	transform(a,b,c,d,f);
}


int main ()
{
	cout<<"Unesite broj elemenata: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente prvog vektora: ";
	vector<int> v1(n);
	for(int i=0;i<n;i++){
		cin>>v1.at(i);
			for(int j=0;j<i;j++){
				if(v1.at(j)==v1.at(i)) i--;
		}
	}
	cin.ignore(1000,'\n');
	cout<<"Unesite elemente drugog vektora: ";
	vector<int> v2(n);
	for(int i=0;i<n;i++){
		cin>>v2.at(i);
			for(int j=0;j<i;j++){
				if(v2.at(j)==v2.at(i)) i--;
		}
	}
	cin.ignore(1000,'\n');
	cout<<"Unesite elemente treceg vektora: "<<endl;
	vector<int> v3(n);
	for(int i=0;i<n;i++){
		cin>>v3.at(i);
			for(int j=0;j<i;j++){
				if(v3.at(j)==v3.at(i)) i--;
		}
	}
	cin.ignore(1000,'\n');
	try{
	SortirajPodrucjeVrijednosti(begin(v1),end(v1),begin(v2),begin(v3),fun,fj);
	}
	catch(logic_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i];
		cout<<endl;
		}
	return 0;
}