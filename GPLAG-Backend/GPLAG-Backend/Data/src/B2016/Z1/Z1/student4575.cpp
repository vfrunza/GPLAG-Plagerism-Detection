/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::vector;

vector <int> IzbaciIsteElemente(vector <int> V){
	int i(0), j(0);
	for(i=0;i<V.size();i++){
		for(j=i+1;j<V.size();j++){
			if(V[i]==V[j]){
				for(int h(j);h<V.size()-1;h++){
					V[h]=V[h+1];
				}
				V.resize(V.size()-1);
				j--;
			}
		}
	}
	return V;
}

bool O1(int n){
	if(n<0){
		n=-n;
	}
	int V[3]{0}, i(0);
	while(n!=0){
		i=n%3;
		n=n/3;
		V[i]++;
	}
	for(i=0;i<3;i++){
		if(V[i]%2!=0 && V[i]>0){
			return false;
		}
	}
	return true;
}

bool O2(int n){
	if(n<0){
		n=-n;
	}
	int V[3]{0}, i(0);
	while(n!=0){
		i=n%3;
		n=n/3;
		V[i]++;
	}
	for(i=0;i<3;i++){
		if(V[i]%2==0 && V[i]>0){
			return false;
		}
	}
	return true;
}

vector <int> IzdvojiGadne(vector <int> V, bool Z){
	V=IzbaciIsteElemente(V);
	vector <int> v1;
	if(Z){
		for(int i(0);i<V.size();i++){
			if(O1(V[i])){
				v1.push_back(V[i]);
			}
		}
		return v1;
	}
	for(int i(0);i<V.size();i++){
		if(O2(V[i])){
			v1.push_back(V[i]);
		}
	}
	return v1;
}

int main ()
{
	vector <int> V;
	vector <int> v1;
	int a(0);
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>a;
		if(a!=0){
			V.push_back(a);
		}
	} while(a!=0);
	O1(20);
	v1=IzdvojiGadne(V, true);
	std::cout<<"Opaki: ";
	int i(0);
	for(i=0;i<v1.size();i++){
		std::cout<<v1[i]<<" ";
	}
	v1=IzdvojiGadne(V, false);
	std::cout<<"\nOdvratni: ";
	for(i=0;i<v1.size();i++){
		std::cout<<v1[i]<<" ";
	}
	return 0;
}