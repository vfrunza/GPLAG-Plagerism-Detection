/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::abs;

vector<int> IzdvojiGadne(vector<int> v, bool n){
	
	vector<int> brojaci(3,0);
	vector<int> opaki;
	vector<int> odvratni;
	
	int c, br_opaki=0,br_odvratni=0;
	long long int x;
	for(int i=0; i<v.size(); i++){
	
		brojaci={0,0,0};
		x=v[i];
		for(;;){
			c=abs(x%3);
			brojaci[c]++;
			x=x/3;
			if(x==0)break;
		}
		
	for(int j=0; j<3; j++){
		if(brojaci[j]==0)continue;
		if(brojaci[j]%2==0)br_opaki++;
		else br_odvratni++;
	}
	
	if(br_odvratni==0 && br_opaki>0)opaki.push_back(v[i]);
	if(br_opaki==0 && br_odvratni>0)odvratni.push_back(v[i]);
	br_opaki=0;
	br_odvratni=0;
		
	}
	
	if(opaki.size()>0){
		for(int i=0; i<opaki.size()-1; i++){
			for(int j=i+1; j<opaki.size(); j++){
				if(opaki[i]==opaki[j]){opaki.erase(opaki.begin()+j);j--;}
			}
		}
	}
	
	if(odvratni.size()>0){
	for(int i=0; i<odvratni.size()-1; i++){
		for(int j=i+1; j<odvratni.size(); j++){
			if(odvratni[i]==odvratni[j]){odvratni.erase(odvratni.begin()+j);j--;}
			
		}
	}
	}
	
	
	
	if(n)return opaki;
	return odvratni;
	
}




int main ()
{
	
	vector<int> v;
	vector<int> opaki;
	vector<int> odvratni;
	int broj;
	bool opaki_odvratni;
	
	
	
	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i=0; ; i++){
		cin>>broj;
		if(broj==0)break;
		v.push_back(broj);
	}
	cout<<"Opaki: ";
	opaki=IzdvojiGadne(v,true);
	for(int i=0; i<opaki.size(); i++){
		cout<<opaki[i]<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	odvratni=IzdvojiGadne(v,false);
	for(int i=0; i<odvratni.size(); i++){
		cout<<odvratni[i]<<" ";
	}
	return 0;
}