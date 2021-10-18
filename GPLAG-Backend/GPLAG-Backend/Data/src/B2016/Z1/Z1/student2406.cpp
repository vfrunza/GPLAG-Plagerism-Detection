#include <iostream>
#include <vector>

using namespace std;

vector<int>IzdvojiGadne(vector<int>x, bool y)
{
	vector<int> rezultat;   
	
	if(y) {
		
		int zadnja,	brojac(0),broji_0(0),broji_1(0),broji_2(0);
		for(int i(0); i<x.size(); i++) {
		
  		int pomocna(x[i]);
			do {      
				zadnja=pomocna%3;
				if(zadnja==0){
					broji_0++;
				}
				else if(zadnja==1){
					broji_1++;
				}                        
				else if(zadnja==2){                  
					broji_2++;
				}
				brojac++;
				pomocna/=3;
   
			} while(pomocna!=0);       
			
			if(brojac%2==0) {
				
			if((broji_0%2==0||broji_0==0)&&(broji_1%2==0||broji_1==0)&&(broji_2%2==0||broji_2==0)){
			rezultat.push_back(x[i]);      
	
			}
		
		}
}
}
	else {
			int zadnja,	brojac(0), broji_0(0),broji_1(0),broji_2(0);
		for(int i(0); i<x.size(); i++) {
				
			  		int pomocna(x[i]);
			do {    
				zadnja=pomocna%3;
				if(zadnja==0){
					broji_0++;
				}
				else if(zadnja==1){
					broji_1++;
				}
				else if(zadnja==2){
					broji_2++;
				}
				brojac++;
				pomocna/=3;
   
			} while(pomocna!=0);           
		
			if((broji_0%2!=0||broji_0==0)&&(broji_1%2!=0||broji_1==0)&&(broji_2%2!=0||broji_2==0)){
					rezultat.push_back(x[i]);
			}
			
	}
}
return rezultat;         
}

int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	vector<int> vek;
       
	do {
		cin>>broj;
		if(broj!=0) {
			vek.push_back(broj);  
		}
		
	}while(broj!=0);
	
for(int i(0); i<vek.size(); i++) {
				for(int j(i+1);j<vek.size();j++){
					if(vek[i]==vek[j]){
						for(int k(j);k<vek.size()-1;k++){
							vek[k]=vek[k+1];
						}
					vek.resize(vek.size()- 1);
					j--;
						
					}
			}
		}
	vector<int>v1;         
	v1=IzdvojiGadne(vek, true);
	vector<int>v2;
	v2=IzdvojiGadne(vek, false);
	cout<<"Opaki: ";
	for(int k(0); k<v1.size(); ++k) {
		cout<<v1[k]<<" ";
	}
	cout<<"Odvratni: ";
	for(int l(0); l<v2.size(); ++l) {
		cout<<v2[l]<<" ";
	}
	return 0;
}