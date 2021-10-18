/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long int Pretvori(int n)
{
	long int pom(0);
	int expon(0);
	int n1;
	while( n!=0)
	{
		n1=n%3;
		pom+=(n1*pow(10,expon));
		expon++;
		n/=3;
	}
	return pom;
}
vector<int> IzdvojiGadne(vector<int> v, bool a)
{
	vector<int> w;
	int br0,br1,br2;
	long int b,c;
	for(int i=0;i<v.size();i++)
	{
		b=Pretvori(v[i]);
		c=b;
		br0=0; br1=0; br2=0;
		if(b<0) b*=-1;
		while(b!=0)
		{
			if(b%10==0) br0++;
			else if(b%10==1) br1++;
			else if(b%10==2) br2++;
			b/=10;
		}
		if(a==false && c==0) w.push_back(v[i]);
		else if(a==true && (br0%2==0 || br0==0) && (br1%2==0|| br1==0) && (br2%2==0 || br2==0) && c!=0) w.push_back(v[i]);
		else if(a==false && (br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) w.push_back(v[i]);
	}
	
	for(int i=0;i<w.size();i++)
	{
		for(int j=i+1;j<w.size();j++)
		{
			if(w[i]==w[j]) { 
				for(int k=j;k<w.size()-1;k++) w[k]=w[k+1];
				w.resize(w.size()-1); j--;
			}
			if(w[i]==w[w.size()-1]) w.resize(w.size()-1); }
	}
	return w;
	
}

int main ()
{
	 vector<int> v;
	long int n;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>n;
		v.push_back(n);
	} while(n!=0);
	v.resize(v.size()-1);
	vector<int> w;
	bool a(true);
	cout<<"Opaki: ";
	w=IzdvojiGadne(v,a);
	for(int i=0;i<w.size();i++)
	{
		cout<<w[i]; 
		if(i!=w.size()-1) cout<<" ";
	} 
	cout<<endl;
	a=false;
	cout<<"Odvratni: ";
		w=IzdvojiGadne(v,a);
	for(int i=0;i<w.size();i++)
	{
		cout<<w[i]; 
		if(i!=w.size()-1) cout<<" ";
	} 

	return 0; 
}