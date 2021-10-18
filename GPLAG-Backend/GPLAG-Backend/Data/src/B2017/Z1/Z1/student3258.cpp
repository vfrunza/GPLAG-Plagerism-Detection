
#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fabs;

vector<int> DaLiJeProst(vector<int> v, bool x){
	vector<int> prosti;
	bool temp=false;
	int j;
	if(x){
	for(int i=0; i<v.size(); i++){
		for(j=2; j<v.at(i); j++){
			if(v.at(i)%j==0) break;
		}
		if(j==v.at(i))prosti.push_back(v.at(i));
	}
	return prosti;
	}
	else{
		for(int i=0; i<v.size(); i++){
			temp=false;
		for(j=2; j<v.at(i); j++){
			if(v.at(i)%j==0) temp=true;
		}
		if(temp)prosti.push_back(v.at(i));
	}
	return prosti;
	}
}

vector<int> Duplikati(vector<int> v){
	vector<int>bez_duplih;
	bool tmp=true;
	if(v.empty()) return v;
	bez_duplih.push_back(v.at(0));
	if(v.size()==1) return bez_duplih;
	for(int i=1; i<v.size()-1; i++){
		if(v.at(i)==v.at(i+1))continue;
		else bez_duplih.push_back(v.at(i));
	}
	for(int i=0; i<v.size()-2; i++){
		if(v.at(v.size()-1)==v.at(i)) tmp=false;
	}
	if(tmp) bez_duplih.push_back(v.at(v.size()-1));
	return bez_duplih;
}



bool DaLijeSimetricanTernarno(long long int x){
	if(x==0) return false;
	long int temp;
	vector<int>ternarni;
	while(fabs(x)!=0){
		temp=x%3;
		ternarni.push_back(temp);
		x/=3;
	}
	for(int i=0; i<ternarni.size()/2; i++){
		if(ternarni.at(i)!=ternarni.at(ternarni.size()-i-1)) return false;
	}
	return true;
}

vector<int> SelekcijaTernarnih (vector<int> v){
	vector<int>simetricni;
	for(int i=0; i<v.size(); i++){
		bool temp1=DaLijeSimetricanTernarno(v.at(i));
		if(temp1)simetricni.push_back(v.at(i));
	}
	
	return simetricni;
}


vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool temp ){
	if(temp){
		vector<int> prosti=DaLiJeProst(v, true);
		prosti=Duplikati(prosti);
		prosti=SelekcijaTernarnih(prosti);
		return prosti;
	}
	else{
		vector<int> slozeni=DaLiJeProst(v, false);
		slozeni=Duplikati(slozeni);
		slozeni=SelekcijaTernarnih(slozeni);
		return slozeni;
	}
}

int main (){
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int>v;
	int temp;
	while(1){
		cin>>temp;
		if(temp==-1)break;
		v.push_back(temp);
		
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1){
	cin>>temp;
		if(temp==1 || temp==0)break;
		else cout<<"Neispravan unos! Unesite ponovo: ";
	}
	bool temp2=false;
	if(temp) temp2=true;
	v=IzdvojiSimetricneTernarne(v, temp2);
	if(v.size()==0){
		if(temp2){
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
		} 
		else{
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} 
	}
	if(temp2){
		cout<<"Prosti simetricni brojevi iz vektora su: "<<v.at(0)<<", ";
		for(int i=1; i<v.size()-1; i++){
			cout<<v.at(i)<<", ";
		}
		cout<<v.at(v.size()-1)<<".";
		
	}
	else{
		cout<<"Slozeni simetricni brojevi iz vektora su: "<<v.at(0)<<", ";
		for(int i=1; i<v.size()-1; i++){
			cout<<v.at(i)<<", ";
		}
		cout<<v.at(v.size()-1)<<".";
		
	}
	
	return 0;
}