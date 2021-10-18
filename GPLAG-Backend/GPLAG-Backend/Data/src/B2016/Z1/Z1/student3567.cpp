#include<iostream>
#include <vector>
using namespace std;
bool DalisuParne (int n){
	vector<int> v;
	while(n!=0){
		v.push_back(n%3);
		n=n/3;
	}
		int brojac0=0;
			int brojac1=0;
			int brojac2=0;
			for(int k=0;k<v.size();k++) {
			if(v[k]==0) brojac0++;
			if(v[k]==1) brojac1++;
			if(v[k]==2) brojac2++;
			}
			
			return(((brojac0%2)==0 || brojac0==0) && ((brojac1%2)==0 || brojac1==0) && ((brojac2%2)==0 || brojac2==0));
	}
bool DalisuNeparne (int n){
	vector<int> v;
	while(n!=0){
		v.push_back(n%3);
		n=n/3;
	}
		int brojac0=0;
			int brojac1=0;
			int brojac2=0;
			for(int k=0;k<v.size();k++) {
			if(v[k]==0) brojac0++;
			if(v[k]==1) brojac1++;
			if(v[k]==2) brojac2++;
			}
			if(brojac2%2==0 && brojac1%2==0 && brojac0%2==0){
				return false;
			}
			return(((brojac0%2)!=0 || brojac0==0) && ((brojac1%2)!=0 || brojac1==0) && ((brojac2)%2!=0 || brojac2==0));
	}
vector<int> IzdvojiGadne (vector<int> v,bool z) {

		vector<int> rezultat;
		for( int i=0;i<v.size();i++){
			if(z && DalisuParne(v[i])){
		rezultat.push_back(v[i]);
			}
			if(z==false && DalisuNeparne(v[i])){
		rezultat.push_back(v[i]);
		}
		}
		for(int i=0;i<rezultat.size();i++){
			for(int j=i+1;j<rezultat.size();j++){
				if(rezultat[i]==rezultat[j]){
					for(int k=j;k<rezultat.size()-1;k++){
						rezultat[k]=rezultat[k+1];
					}
					rezultat.resize(rezultat.size()-1);
					j--;
				}
			}
		}
		return rezultat;
	}
int main ()
{ int broj=1;
vector<int> v;
vector<int> m;
vector<int> c;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(broj!=0){
		cin>>broj>>ws;
		if(broj==0) break;
		v.push_back(broj);
	}
	cout<<"Opaki: ";
	m=IzdvojiGadne(v,true);
	for(int i=0;i<m.size();i++){
	cout<<m[i]<<" ";
	}
	cout<<endl<<"Odvratni: ";
	c=IzdvojiGadne(v,false);
	for(int u=0;u<c.size();u++){
		cout<<c[u]<<" ";
	}
	
	
	
	return 0;
}