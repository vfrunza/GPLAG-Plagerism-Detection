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

using namespace std;

long int VratiTernarni(int n)
{   
	n=abs(n);
	long int suma=0;long int k=1;
	while(n!=0)
	{  
		suma+=n%3*k;
		k*=10;
		n/=3;
	}
	return suma;
}

int JelGadan(long int n)
{
	vector<int> v(3);

	while(n!=0)
	{
		int c=n%10;
		v[c]++;
		n/=10;
	}

	int neparan=1;
	for(int i=0;i<v.size();i++)
		if(v[i]%2==0 && v[i]!=0) neparan=0;

	return neparan;
}


int JelOpak(long int n)
{   	
	vector<int> v(3);

	while(n!=0)
	{
		int c=n%10;
		v[c]++;
		n/=10;
	}

	int paran=1;
	for(int i=0;i<v.size();i++)
		if(v[i]%2!=0 && v[i]!=0) paran=0;

   	
	return paran;
}

bool DaLiPostoji(vector<int> v,int n)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==n) return true;
	}
	return false;
}

vector<int> IzdvojiGadne(vector<int>v, bool a) 
{
	vector<int>v1;
	
	for(int i=0;i<v.size();i++)
	{
		if(a)
		{
			if(JelOpak(VratiTernarni(v[i]))==1 && !DaLiPostoji(v1,v[i]))
				v1.push_back(v[i]);
			
		}
		else 
		{
			if(JelGadan(VratiTernarni(v[i]))==1 && !DaLiPostoji(v1,v[i]))
				v1.push_back(v[i]);
		}
	}
	
	return v1;
}



int main ()
{  

	int n;
	vector<int>v1;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	
		
		cin>>n;
		while(n!=0)
		{
			v1.push_back(n);
			cin>>n;
			if(n==0) break;
			
		}
	
	vector<int> opaki,odvratni;
	cout<<"Opaki: "; 
	opaki=IzdvojiGadne(v1,true);
	for(int i=0;i<opaki.size();i++) cout<<opaki[i]<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	odvratni=IzdvojiGadne(v1,false);
	for(int i=0;i<odvratni.size();i++) cout<<odvratni[i]<<" ";

	return 0;
}