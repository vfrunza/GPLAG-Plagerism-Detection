/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;

bool opak(long int broj){
	vector<int>v;
	broj=abs(broj);
	for(;;){
		int broj1=broj/3;
			v.push_back(broj-broj1*3);
			broj=broj1;
		
		if(broj==0)break;
	}
	int br0=0, br1=0, br2=0;
	for(int i=0; i<v.size();i++){
		if(v[i]==0)br0++;
		if(v[i]==1)br1++;
		if(v[i]==2)br2++;
	}
	
	if(br0%2==0 and br1%2==0 and br2%2==0)return true;
	return false;
	
	
}

bool odvratan(long long int broj){
	vector<int>v;
	broj=abs(broj);
		for(;;){
		int broj1=broj/3;
			v.push_back(broj-broj1*3);
			broj=broj1;
		
		if(broj==0)break;
	}
	int br0=0, br1=0, br2=0;
	for(int i=0; i<v.size();i++){
		if(v[i]==0)br0++;
		if(v[i]==1)br1++;
		if(v[i]==2)br2++;
	}
	if(br0==0)br0++;if(br1==0)br1++;if(br2==0)br2++;
	if(br0%2!=0 and br1%2!=0 and br2%2!=0)return true;
	return false;
	
}


vector<int> IzdvojiGadne(vector<int> v, bool b){
	vector<int>final;
	for(int x:v){
		
		if(b){
			int temp=0;
			for(int i: final){
					if(i==x){temp =1; break;}
				}
			
			if(opak(x) and temp==0){
				final.push_back(x);
			}
			
			
		}else{
			int temp=0;
			for(int i: final){
					if(i==x){temp =1; break;}
				}
			
			if(odvratan(x) and temp==0){
			   final.push_back(x);
			}
			
			
		}
		
		
		
	}
	return final;
}

int main (){
	vector<int>v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int a;
	for(;;){
		cin>>a;
		if(a==0)break;
	    v.push_back(a);
	}
	
	vector<int>op= IzdvojiGadne(v, true);
	vector<int>od= IzdvojiGadne(v, false);
	cout<<"Opaki: ";
   	for(int x: op){
		cout<<x<<" ";
	}
	cout<<endl<<"Odvratni: ";
	for(int x: od){
		cout<<x<<" ";
	}
	
	return 0;
}