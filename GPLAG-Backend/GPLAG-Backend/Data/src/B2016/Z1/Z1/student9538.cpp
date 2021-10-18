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
bool Postoji(vector<int> v, int n) {
	bool postoji=false;
	for(int i=0; i<v.size();i++)
	if(v[i]==n) postoji=true;
	return postoji; 
}
vector<int>IzdvojiGadne(vector<int> v,bool a)
{
	vector<int> pov;
	for(int i=0; i<v.size();i++) 
	{
		int n=abs(v[i]);
		vector<int>br(3);
		while(n!=0) 
		{
			br[n%3]++;
			n/=3;
		}
		if(a==true)
		{
			bool jeste=true;
			for(int j=0; j<br.size(); j++)
			if(br[j]%2!=0 && br[j]!=0) jeste=false;
			if(jeste==true && !Postoji(pov,v[i]))pov.push_back(v[i]);
		}
		if	(a==false) 
		{
			bool jeste=true;
			for(int j=0; j<br.size();j++)
			if(br[j]%2==0 && br[j]!=0) jeste=false;
			if(jeste==true && !Postoji(pov,v[i]))pov.push_back(v[i]);
		}
	}
	return pov;
}
int main() 
{
	vector<int>v;
	printf("Unesite brojeve (0 za prekid unosa): ");
	do {
		int n;
		cin>>n;
		if(n==0) break;
		v.push_back(n); 
	}
	while(1);
	vector<int>v1;
	v1=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	for(int i=0; i<v1.size();i++)
	cout<<v1[i]<<" ";
	v1=IzdvojiGadne(v,false);
	cout<<endl<<"Odvratni: ";
	for(int i=0;i<v1.size();i++) 
	cout<<v1[i]<<" ";
	return 0; 
}

		