#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> dajt(int h)
{
	if(h<0) h=-h;
	vector<int> pom;
	while(h!=0)
	{
		pom.push_back(h%3);
		h/=3;
	}
	return pom;
}
int tester(vector<int> k)
{
	int kecevi=0, dvice=0, nule=0;
	int a=0;
	while(a!=k.size())
	{
		if(k[a]==0) nule++;
		if(k[a]==1) kecevi++;
		if(k[a]==2) dvice++;
		a++;
	}
	if(nule%2==0 && kecevi%2==0 && dvice%2==0) {
		nule=1;
		kecevi=0;
		dvice=0;
	}
	else if((nule%2!=0 || nule==0)&&(kecevi%2!=0 || kecevi==0)&&(dvice%2!=0 || dvice==0))
	{
		nule=1;
		kecevi=1;
		dvice=0;
	}
	else 
	{
		nule=1;
		kecevi=1;
		dvice=1;
	}
	return nule+kecevi+dvice;
}
vector<int> IzdvojiGadne(vector<int> niz, bool vr)
{
	int a=0, b, c;
	if(niz.size()!=0)
	{
		while(a!=niz.size())
		{
			b=a+1;
			while(b!=niz.size())
			{
				if(niz[a]==niz[b])
				{
					c=b;
					while(c!=niz.size()-1) {niz[c]=niz[c+1]; c++;}
					niz.resize(niz.size()-1);
					b--;
				}
				b++;
			}
			a++;
		}
	}
	deque<vector<int> > tv;
	a=0;
	for(int i=0; i<niz.size(); i++)
	{
		tv.resize(tv.size()+1);
		tv[a]=dajt(niz[i]);
		a++;
	}
	vector<int> r;
	a=0;
	if(vr==1)
	{
		for(int i=0; i<tv.size(); i++)
		{
			if(tester(tv[i])==1)
			{
				r.resize(r.size()+1);
				r[a]=niz[i];
				a++;
			}
		}
	}
	if(vr==0)
	{
		for(int i=0; i<tv.size(); i++)
		{
			if(tester(tv[i])==2)
			{
				r.resize(r.size()+1);
				r[a]=niz[i];
				a++;
			}
		}
	}
	return r;
}
int main ()
{
	vector<int> niz;
	int a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		cin>>a;
		if(a==0) break;
		else{
			niz.push_back(a);
		}
	}
	vector<int> pom1=IzdvojiGadne(niz, true);
	vector<int> pom2=IzdvojiGadne(niz, false);
	cout<<"Opaki: ";
	for(int i=0; i<pom1.size(); i++) cout<<pom1[i]<<" ";
	cout<<endl<<"Odvratni: ";
	for(int i=0; i<pom2.size(); i++) cout<<pom2[i]<<" ";
	return 0;
}