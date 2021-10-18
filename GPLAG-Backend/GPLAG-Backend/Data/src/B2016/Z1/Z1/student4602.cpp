#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int pf(int n){
	int i=0,a=0,c=1,m=0,t(0),d(0),j(0);
	while(n!=0){
		i=abs(n%3);
		if(i==0) t++;
		else if(i==1) j++;
		else if(i==2) d++;
		n/=3;
	}
	if(j%2==0 && d%2==0 && t%2==0) return 1; 
	if((j%2!=0 || j==0) && (d%2!=0 || d==0) && (t%2!=0 || t==0)) return 0;
	return 2;
}



vector<int>IzdvojiGadne(vector<int>v, bool gadni){
	vector<int>pom1;
	vector<int>brojaci(v.size(), 0);
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
		}
	}
	}
	if(gadni==true){
		for(int i=0; i<v.size(); i++){
			if(pf(v[i])==1) pom1.push_back(v[i]);
		}
	}
		if(gadni==false){
			for(int i=0; i<v.size(); i++){
				if(pf(v[i])==0) pom1.push_back(v[i]);
			}
		}
		return pom1;
}
	
int main ()
{
	
	int n;
	vector<int>v;
	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		cin>>n;
		
		if(n!=0) v.push_back(n);
	}while(n!=0);
	vector<int>opaki=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	
	for(int i=0; i<opaki.size(); i++){
		cout<<opaki[i]<<" ";
	}
	cout<<endl<<"Odvratni: ";
	vector<int>odvratni=IzdvojiGadne(v,false);
	
	for(int i=0; i<odvratni.size(); i++){
		cout<<odvratni[i]<<" ";
	}
	return 0;
}