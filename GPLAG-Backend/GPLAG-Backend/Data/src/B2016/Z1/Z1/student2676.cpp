#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> IzdvojiGadne(vector<int> v, bool opak)
{
	vector<int> gad;
	for(int i=0;i<v.size();i++)
	{
		int br0=0, br1=0, br2=0, a;
		a=v[i];
		if(a==0)
		{
			if(!opak)
			{
				bool ima=false;
				for(int j=0;j<gad.size();j++) if(v[i]==gad[j]) ima=true;
				if(!ima) gad.push_back(v[i]);
			}
		}
		else
		{
			while(a!=0)
			{
				if(a%3==0) br0++;
				if(abs(a%3)==1) br1++;
				if(abs(a%3)==2) br2++;
				a/=3;
			}
			if(opak && br0%2==0 && br1%2==0 && br2%2==0) 
			{
				bool ima=false;
				for(int j=0;j<gad.size();j++) if(v[i]==gad[j]) ima=true;
				if(!ima) gad.push_back(v[i]);
			}
			else if(!opak && (br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0))
			{
				bool ima=false;
				for(int j=0;j<gad.size();j++) if(v[i]==gad[j]) ima=true;
				if(!ima) gad.push_back(v[i]);
			}
		}
	}
	return gad;
}

int main ()
{
	vector<int> v;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	do
	{
		cin >> a;
		if(a!=0) v.push_back(a);
	}while(a!=0);
	vector<int> c=IzdvojiGadne(v, true);
	vector<int> d=IzdvojiGadne(v, false);
	cout << "Opaki: ";
	for(int x : c) cout << x << " ";
	cout << "\nOdvratni: ";
	for(int x : d) cout << x << " ";
	return 0;
}