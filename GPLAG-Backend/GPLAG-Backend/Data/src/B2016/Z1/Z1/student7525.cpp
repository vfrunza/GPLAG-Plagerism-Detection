#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using std::cin;
using std::vector;

vector<int> IzdvojiGadne(vector<int> v, bool t){
	vector<int>opaki,odvratni;
	
	for(int i=0; i<v.size(); i++){
		int nule(0),jedinice(0),dvice(0);
		vector<int>ternarni;
		int c(0);
		int br=v[i];
		
		do{
			c=br%3;
			ternarni.push_back(c);
			br=br/3;
		}while(br!=0);
		
		for(int j=0; j<ternarni.size(); j++){
			if(ternarni[j]==0) nule++;
			if(abs(ternarni[j])==1) jedinice++;
			if(abs(ternarni[j])==2) dvice++;
		}
		if(nule%2==0 && jedinice%2==0 && dvice%2==0) opaki.push_back(v[i]);
		if((nule%2!=0 && jedinice%2!=0 && dvice%2!=0) || (nule==0 && jedinice%2!=0 && dvice%2!=0) || (nule%2!=0 && jedinice==0 && dvice%2!=0) || (nule%2!=0 && jedinice%2!=0 && dvice==0))
		odvratni.push_back(v[i]);
	}
	for(int i=0; i<opaki.size()-1; i++){
		if(opaki.size()==0) break;
		for(int j=i+1; j<opaki.size(); j++){
			if(opaki[i]==opaki[j]){ 
				opaki.erase(opaki.begin() + j);
				j--;
			}
		}
	}
	for(int i=0; i<odvratni.size()-1; i++){
		if(odvratni.size()==0) break;
		for(int j=i+1; j<odvratni.size(); j++){
			if(odvratni[i]==odvratni[j]){ 
			odvratni.erase(odvratni.begin() + j);
			j--;
		}	
	}
	}
	if(t==true) return opaki;
	else return odvratni;
}

int main ()
{
	vector<int>v;
	int x;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
		do{
			cin>>x;
			if(x==0) break;
			v.push_back(x);
		}while(x!=0);

	vector<int> opaki, odvratni;
	opaki=IzdvojiGadne(v,true);
	odvratni=IzdvojiGadne(v,false);
	cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		if(i==opaki.size()-1){ 
			cout<<opaki[i];
		}else{
		cout<<opaki[i]<<" ";
		}
	}
	cout<<std::endl;
	cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
		if(odvratni.size()==0) break;
		if(i==odvratni.size()-1){ 
			cout<<odvratni[i];
		}else{
		cout<<odvratni[i]<<" ";
		}
	}
	return 0;
}