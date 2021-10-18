/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool JeLiIsti(vector<int>v, long int n)
{
	for(int i=0;i<v.size();i++)
	if(n==v[i])return true;
	return false;
}

unsigned long long int  BazaTri(long int n)
{
	unsigned long long int s=0,k=1;
	while(n!=0)
	{
		s=(n%3)*k+s;
		n/=3;
		k*=10;
	}
	return s;
	
}

bool  OpakiBrojevi(long int n)
{
	unsigned long long int s=0;
	if(n<0)n*=-1;
	vector<int>v(3);
	s=BazaTri(n); 
	if(s==0)v[s%10]++;
	while(s!=0)
	{
		v[s%10]++;
		s/=10;
	}
	for(int i=0;i<v.size();i++)
	if(v[i]%2!=0) return false;
	return true;
		
}
bool  OdvratniBrojevi(long int n)
{
	unsigned long long int s=0;
	if(n<0)n*=-1; 
	vector<int>v(3);
	s=BazaTri(n);
	if(s==0)v[s%10]++;
	while(s!=0)
	{
		v[s%10]++;
		s/=10;
	}
	for(int i=0;i<v.size();i++)
	if(v[i]%2==0 && v[i]!=0) return false;
	return true;
		
}


vector<int> IzdvojiGadne(vector<int>v, bool a)
{
	vector<int>v1; 
	for(unsigned int i=0;i<v.size();i++){
	if(a){if(OpakiBrojevi(v[i])==true) 
	{	
		
			if(!JeLiIsti(v1,v[i]))v1.push_back(v[i]);
		
			}
		}
	else
	{
		
		if(OdvratniBrojevi(v[i])==true)
	{	
		
	
			if(!JeLiIsti(v1,v[i]))v1.push_back(v[i]);
			}
		}
	}
	return v1;
}

int main ()
{
	long int a;
	vector<int>v;
	vector<int>v1,v2;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin>>a;
		if(a!=0)
		v.push_back(a);
	}
		while(a!=0);
	cout<<"Opaki: ";
	v1=IzdvojiGadne(v,true);
	for(unsigned int i=0;i<v1.size();i++)
	cout<<v1[i]<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
    v2=IzdvojiGadne(v,false);
	for(unsigned int i=0;i<v2.size();i++)
	cout<<v2[i]<<" ";

		
	return 0;
}