#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long int Ternarni_zapis(int n)
{
	long int broj=0, k=1;
	while(n != 0)
	{
		broj = broj + (n%3)*k;
		k=k*10;
		n=n/3;
	}
	return broj;
}

bool Opak(long int n)
{
		if(n < 0) n=fabs(n);
		vector<int> v(3,0);
		bool opak=true;
		while(n != 0)
		{
			v[n%10]++;
			n/=10;
		}
		for(int i = 0 ; i < 3 ; i++)
		{
			if(v[i]%2==1) 
			{
				opak=false;
				break;
			}
		}
		return opak;
}
bool Odvratan(long int n)
{
		if(n < 0) n=fabs(n);
		vector<int> v(3,0);
		bool odvratan=true;
		while(n != 0)
		{
			v[n%10]++;
			n/=10;
		}
		for(int i = 0 ; i < 3 ; i++)
		{
			if(v[i]%2==0 && v[i] != 0) 
			{
				odvratan=false;
				break;
			}
		}
		return odvratan;
}
vector<int> IzbaciDuple(vector<int> v)
{
	if(v.size() == 0) return v;
	for(int i = 0 ; i < v.size()-1 ; i++)
	{
		for(int j = i+1 ; j < v.size() ; j++)
		{
			if(v[j]==v[i])
			{
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
vector<int> IzdvojiGadne(vector<int> v, bool a)
{
	vector<int> v1,v2;
	if(a==true)
	{
		for(int i = 0 ; i < v.size() ; i++)
		{
			if(Opak(Ternarni_zapis(v[i]))==true) v1.push_back(v[i]);
		}
		vector<int> v3;
		v3=IzbaciDuple(v1);
		return v3;
	}
	if(a==false)
	{
		for(int i = 0 ; i < v.size() ; i++)
		{
			if(Odvratan(Ternarni_zapis(v[i]))==true) v2.push_back(v[i]);
		}
		
		vector<int> v4;
		v4=IzbaciDuple(v2);
		return v4;
	}
	return v;
}
int main ()
{
	vector<int> v,v1,v2;
	int x;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i = 0 ; i < 100000 ; i++)
	{
		cin>>x;
		if(x==0) break;
		v.push_back(x);
	}
	v1=IzdvojiGadne(v, true);
	if(v1.size()==0) cout<<"Opaki: 0"<<endl;
	else {
	cout<<"Opaki: ";
	for(int x : v1) cout<<x<<" ";
	cout<<endl;
	}
	v2=IzdvojiGadne(v, false);
	if(v2.size()==0) cout<<"Odvratni: 0";
	else {
	cout<<"Odvratni: ";
	for(int x : v2) cout<<x<<" ";
	cout<<endl;
	}
	return 0;
}