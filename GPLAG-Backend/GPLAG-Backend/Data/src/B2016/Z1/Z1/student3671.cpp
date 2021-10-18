/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


vector<int>IzdvojiGadne(vector<int>v, bool p) {
	vector<int> f;
	vector<int> h;
	vector<int>nijedan;
	for(int j=0;j<v.size();j++){
		for(int k=0;k<v.size();k++){
			if((v[j]==v[k]) && (j!=k))
			v.erase(v.begin()+k);
		}
	}
	for(int i=0;i<v.size();i++){
		int br_nula(0),br_jedan(0),br_dva(0);
		int pomocna=v[i];
		while(pomocna!=0){
		if(abs(pomocna)%3==0)
		{br_nula++;}
		if(abs(pomocna)%3==1)
		{br_jedan++;}
		if(abs(pomocna)%3==2)
		{br_dva++;}
		pomocna/=3;
		}
		if((br_nula%2==0 || br_nula==0) && (br_jedan%2==0 || br_jedan==0) && (br_dva%2==0 || br_dva==0))
		f.push_back(v[i]);
		if((br_nula%2==1 || br_nula==0) && (br_jedan%2==1 || br_jedan==0) && (br_dva%2==1 || br_dva==0))
		h.push_back(v[i]);
	}
		if(p==true)
		return f;
		if(p==false)
		return h;
}

int main ()
{
	vector<int>v;
	int n;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		cin>>n;
		if(n==0)
		break;
		v.push_back(n);
	}while(n!=0);
	vector<int>b(n);
	vector<int>c(n);
	cout<<"Opaki: ";
	b=IzdvojiGadne(v,1);
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	c=IzdvojiGadne(v,0);
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<" ";
	}
	return 0;
}