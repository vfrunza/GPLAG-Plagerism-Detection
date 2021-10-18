#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>
using namespace std;
typedef vector<vector<double>> mat;

mat obrlati(mat m, bool t)
{
	mat nova;
	nova.resize(m.size());
	for(int i=0; i<m.size(); i++) nova[i].resize(m[i].size());
	if(t)
	{
		for(int i=0; i<nova.size(); i++)
		{
			int p=m[i].size()-1;
			for(int j=0; j<nova[i].size(); j++)
			{
				nova[i][j]=m[i][p];
				p--;
			}
		}
	}
	else {
		int p=m.size()-1;
		for(int i=0; i<nova.size(); i++)
		{
			for(int j=0; j<nova[i].size(); j++)
			{
				nova[i][j]=m[p][j];
			}
			p--;
		}
	}
	return nova;
}
mat OgledaloMatrica(mat m)
{
	for(int i=0; i<m.size(); i++) if(m[i].size()!=m[0].size()) throw domain_error("Matrica nije korektna");
	mat m1=obrlati(m,true), m2=obrlati(m,false), m3=obrlati(obrlati(m,true),false);
	mat nova1;
	nova1.resize(m.size());
	for(int i=0; i<m.size(); i++) nova1[i].resize(3*m[i].size());
	for(int i=0; i<m.size(); i++)
	{
		for(int j=0; j<m[i].size(); j++)
		{
			nova1[i][j]=m3[i][j];
			nova1[i][j+2*m[i].size()]=m3[i][j];
			nova1[i][j+m[i].size()]=m2[i][j];
		}
	}
	mat nova2;
	nova2.resize(m.size());
	for(int i=0; i<m.size(); i++) nova2[i].resize(3*m[i].size());
	for(int i=0; i<m.size(); i++)
	{
		for(int j=0; j<m[i].size(); j++)
		{
			nova2[i][j]=m1[i][j];
			nova2[i][j+2*m[i].size()]=m1[i][j];
			nova2[i][j+m[i].size()]=m[i][j];
		}
	}
	mat nova;
	for(int i=0; i<nova1.size(); i++)
	{
		vector<double> novi;
		for(int j=0; j<nova1[i].size(); j++) novi.push_back(nova1[i][j]);
		nova.push_back(novi);
	}
	for(int i=0; i<nova2.size(); i++)
	{
		vector<double> novi;
		for(int j=0; j<nova2[i].size(); j++) novi.push_back(nova2[i][j]);
		nova.push_back(novi);
	}
	for(int i=0; i<nova1.size(); i++)
	{
		vector<double> novi;
		for(int j=0; j<nova1[i].size(); j++) novi.push_back(nova1[i][j]);
		nova.push_back(novi);
	}
	return nova;
}
int main ()
{
	try
	{
		mat m;
		cout<<"Unesite dimenzije matrice (m n): ";
		int a, b;
		cin>>a>>b;
		if(a<0|| b<0) throw domain_error("Dimenzije matrice moraju biti nenegativne!");
		m.resize(a);
		for(int i=0; i<m.size(); i++) m[i].resize(b);
		cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m.size(); i++)
			for(int j=0; j<m[i].size(); j++)
				cin>>m[i][j];
		m=OgledaloMatrica(m);
		cout<<endl<<"Rezultantna matrica: "<<endl;
		for(int i=0; i<m.size(); i++)
		{
			for(int j=0; j<m[i].size(); j++)
			{
				cout<<setw(4)<<right<<m[i][j];
			} cout<<endl;
		}
	} catch(domain_error nj)
	{
		cout<<nj.what();
	}
	return 0;
}