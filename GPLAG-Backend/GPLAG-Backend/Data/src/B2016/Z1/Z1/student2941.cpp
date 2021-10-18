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

vector<int> IzbaciPonavljanja(vector<int> v) {
	for(int i(0);i<v.size()-1;i++) {
		for(int j(i+1);j<v.size();j++) {
			if(v[i]==v[j]) {
				for(int k(j);k<v.size()-1;k++) {
					v[k]=v[k+1];
				}
				v.resize(v.size()-1);
				j--;
			}
		}
	}
	return v;
}

int Ternarni(int n) {
	int br0=0,br1=0,br2=0;
	if(n==0) br0++;
	while(n!=0) {
		
		if(n%3==0) br0++;
		if(n%3==1 || n%3==-1) br1++;
		if(n%3==2 || n%3==-2) br2++;
		n/=3;
	}
	if((br0%2==0 || br0==0) && (br1%2==0 || br1==0) && (br2%2==0 || br2==0)) return 1;
	else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) return 0;
	else return 2;
}

vector<int> IzdvojiGadne(vector<int> v, bool t) {
	vector<int> pomocni;
	if(v.size()==0) return v;
	v=IzbaciPonavljanja(v);
	for(int i(0);i<v.size();i++){
		if(Ternarni(v[i])==t) pomocni.push_back(v[i]);
	}
	return pomocni;
}

int main ()
{
	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> v;
	vector<int> pomocni;
	long int n;
	cin>>n;
	while(n!=0) {
		v.push_back(n);
		cin>>n;
	}
	cout<<"Opaki: ";
	
	pomocni=IzdvojiGadne(v,true);
	for(int j(0);j<pomocni.size();j++) {
		cout<<pomocni[j]<< " ";
	}
	cout<<"\nOdvratni: ";
	
	pomocni=IzdvojiGadne(v,false);
	for(int j(0);j<pomocni.size();j++) {
		cout<<pomocni[j]<< " ";
	}
	
	return 0;
}