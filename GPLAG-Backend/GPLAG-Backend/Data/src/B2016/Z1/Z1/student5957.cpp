/*B 2016/2017, Zadaća 1, Zadatak 1
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::vector;

vector<int> IzbaciIste(vector<int> v){
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[j]==v[i]){
				for(int h=j;h<v.size()-1;h++){
					v[h]=v[h+1];
				}
				v.resize(v.size()-1);
				j--;
			}
		}
	}
	return v;
}

bool Opak(int n){
	int i(0),v[3]={0};
	if(n<0)n=-n;
	while(n!=0){
		i=n%3;
		v[i]++;
		n=n/3;
	}
	for(int i=0;i<3;i++){
		if(v[i]>0 && v[i]%2!=0)
		return false;
		}
	return true;
}

bool Odvratan(int n){
	int i(0),v[3]={0};
	if(n<0)n=-n;
	while(n!=0){
		i=n%3;
		v[i]++;
		n=n/3;
	}
	for(int i=0;i<3;i++){
		if(v[i]>0 && v[i]%2==0)
		return false;
		}
	return true;
}

vector<int> IzdvojiGadne(vector<int> v,bool istina){
	v=IzbaciIste(v);
	vector<int> a(0);
	if(istina){
		for(int i=0;i<v.size();i++){
			if(Opak(v[i]))
			a.push_back(v[i]);
		}
		return a;
	}
	for(int i=0;i<v.size();i++){
		if(Odvratan(v[i]))
		a.push_back(v[i]);
	}
	return a;
}


int main ()
{
	int g(0);
	vector<int> v;
	vector<int> a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		cin>>g;
		if(g!=0)
		v.push_back(g);
	}while(g!=0);
	a=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	for(int i=0;i<a.size();i++)
	cout<<a[i]<<" "; 
	a=IzdvojiGadne(v,false);
	cout<<"\nOdvratni: ";
	for(int i=0;i<a.size();i++)
	cout<<a[i]<<" ";
	return 0;
}