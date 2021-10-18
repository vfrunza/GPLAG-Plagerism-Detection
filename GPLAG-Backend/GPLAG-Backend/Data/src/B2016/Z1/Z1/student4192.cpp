#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> ternarni(int n)
{
	vector<int>v;
	int temp=n;
	if(temp<0) temp=fabs(temp);
	while(temp!=0) {
		int cifra=temp%3;
		v.push_back(cifra);
		temp/=3;
	}
	return v;
}
bool opaki(int n)
{
	vector<int>v=ternarni(n);
	vector<int>v1(10,0);
	for(int i=0; i<v.size(); i++)
		v1[v[i]]++;
	for(int i=0; i<v1.size(); i++) {
		if(v1[i]==0) continue;
		if(v1[i]%2!=0) return false;
	}
	return true;
}
bool odvratni(int n)
{
	vector<int>v=ternarni(n);
	vector<int>v1(10,0);
	for(int i=0; i<v.size(); i++)
		v1[v[i]]++;
	for(int i=0; i<v1.size(); i++) {
		if(v1[i]==0) continue;
		if(v1[i]%2==0) return false;
	}
	return true;
}
vector<int> IzdvojiGadne(vector<int>v,bool a)
{
	vector<int>v1;
	if(a==true)
	{for(int i=0; i<v.size(); i++)
		{
			if(opaki(v[i])) v1.push_back(v[i]);
			
		}
	}
	else
	{
		for(int i=0;i<v.size();i++)
		{
			if(odvratni(v[i])) v1.push_back(v[i]);
		}
	}

	for(int i=0; i<v1.size(); i++) {
		for(int j=i+1; j<v1.size(); j++) {
			if(v1[i]==v1[j]) {
				for(int k=j; k<v1.size()-1; k++)
					v1[k]=v1[k+1];
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
	cout<<"Unesite brojeve (0 za prekid unosa):";
    
	vector<int>v;
	for(;;)
	{
		cin>>n;
		if(n==0) break;
		v.push_back(n);
	}
	vector<int>v1=IzdvojiGadne(v,true);
	cout<<" Opaki: ";
	for(int i=0;i<v1.size();i++)
	cout<<v1[i]<<" ";
	cout<<endl<<"Odvratni: ";
	v1=IzdvojiGadne(v,false);
	for(int i=0;i<v1.size();i++)
	cout<<v1[i]<<" ";
	







	return 0;
}