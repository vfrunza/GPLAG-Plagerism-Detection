/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std; 

bool Opaki(int b) {
	int br0(0); 
	bool opaki=true; 
	while (b!=0) { 
		if(b%3==0) br0++; 
		b/=3; }
	if(br0%2==0 || br0==0) {return true;} 
	 return false;
}
bool Odvratni(int b) {
	int br1(0); 
	bool odvratni=true; 
	while (b!=0) { 
		if(b%3==1) br1++; 
		b/=3; }
	if(br1%2!=0 || br1==0) {return true; }
	  return false;
}
//11111222 nema nula i gadan je 
//kad je 0 da ne ispituje

bool Gadni(int b){
	bool gadni=false; 
	if(Odvratni(b)==true && Opaki(b)==true) {return true; }
	 return false; 
}
std::vector<int> IzdvojiGadne(vector<int>v, bool a){
	vector<int>v1; 
	for(int i=0; i<v.size(); i++) {
		if(Gadni(v[i])==true && a==false) v1.push_back(v[i]);
		else if(Odvratni (v[i])==true && a==true) v1.push_back(v[i]);
		else if(Opaki(v[i])==true && a==true) v1.push_back(v[i]);
	}
	//koji se ponavlja da izbaci 
	for(int i=0; i<v1.size(); i++) 
	{
		for(int j=i+1; j<v1.size(); j++){
			if(v1[j]==v1[i]) {
				for(int k=j; k<v1.size()-1; k++) {
					v1[k]=v1[k+1]; 
				}
			v1.resize(v1.size()-1); 
			j--; 
			}
			
		}
	}
	return v1;
}

int main ()
{
	int n; 
	//cout<<"Unesite broj elemenata vektora: "; 
	cin>>n;
    vector<int>v(n);
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    for(int i=0; i<v.size(); i++)
    cin>>v[i];
    vector<int>v2(n);
    vector<int>v3(n);
    v2=IzdvojiGadne(v, true);
    v3=IzdvojiGadne(v, false);
    cout<< "Opaki su";
    for(int i=0; i<v2.size(); i++)
    cout<<v2[i]<<" ";
    cout<< "odvratni su";
    for(int j=0; j<v2.size(); j++)
    cout<<v3[j]<<" ";
	return 0;
}