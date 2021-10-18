#include<iostream>
#include<vector>
#include<deque>
using namespace std;
typedef vector<vector<double>> mat;

mat obrnimatricu(mat m)
{
	mat pom;
	vector<double> zblj;
	for(int i=m.size()-1; i>=0; i--)
	{
		zblj.resize(0);
		for(int j=0; j<m[i].size(); j++)
		{
			zblj.push_back(m[i][j]);
		}
		pom.push_back(zblj);
	}
	return pom;
}

mat OpadajuciPodnizovi(vector<double> niz)
{
	mat r;
	for(int i=niz.size()-1; i>0; i--)
	{
		if(niz.size()==0) break;
		deque<double> v;
		if(niz[i]<=niz[i-1])
		{
			v.push_front(niz[i]);
			i--;
			while(i>0 && niz[i]<=niz[i-1]) {v.push_front(niz[i]); i--;}
			v.push_front(niz[i]);
		}
		if(v.size()!=0)
		{
			vector<double> d;
			d.resize(v.size());
			for(int i=0; i<v.size(); i++) d[i]=v[i];
			r.push_back(d);
		}
	}
	r=obrnimatricu(r);
	return r;
}

mat RastuciPodnizovi(vector<double> niz)
{
	mat r;
	for(int i=niz.size()-1; i>0; i--)
	{
		if(niz.size()==0) break;
		deque<double> v;
		bool bla=false;
		if(niz[i]>=niz[i-1])
		{
			v.push_front(niz[i]);
			i--;
			while(i>0 && niz[i]>=niz[i-1]) {v.push_front(niz[i]); i--;}
			v.push_front(niz[i]);
		}
		if(v.size()!=0)
		{
			vector<double> d;
			d.resize(v.size());
			for(int i=0; i<v.size(); i++) d[i]=v[i];
			r.push_back(d);
		}
	}
	r=obrnimatricu(r);
	return r;
}

int main ()
{
	vector<double> niz;
	cout<<"Unesite broj elemenata vektora: ";
	int k;
	cin>>k;
	niz.resize(k);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<niz.size(); i++) cin>>niz[i];
	mat opadaju = OpadajuciPodnizovi(niz), rastu = RastuciPodnizovi(niz);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<rastu.size(); i++)
	{
		for(int j=0; j<rastu[i].size(); j++)
		{
			cout<<rastu[i][j]<<" ";
		} cout<<endl;
	}
	cout<<endl<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<opadaju.size(); i++)
	{
		for(int j=0; j<opadaju[i].size(); j++)
		{
			cout<<opadaju[i][j]<<" ";
		} cout<<endl;
	}
	return 0;
}