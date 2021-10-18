#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v)
{
	Matrica rastuci;
	unsigned long long k=0,i=0;
	bool bio_niz=false;
	while(i<v.size())
	{
		while(i<v.size()-1 and v[i]<=v[i+1])
		{
			rastuci.resize(k+1);
			bio_niz=true;
			rastuci[k].push_back(v[i]);
			i++;
			if(i==v.size()-1)
				break;
		}
		if(i<v.size() and bio_niz)
		{
			rastuci[k].push_back(v[i]);
			k++;
			i++;
		}
		if(!bio_niz)
			i++;
		if(i>=v.size())
			break;
		bio_niz=false;
	}
	return rastuci;
}
Matrica OpadajuciPodnizovi(vector<double> v)
{
	Matrica opadajuci;
	unsigned long long k=0,i=0;
	bool bio_niz=false;
	while(i<v.size())
	{
		while(i<v.size()-1  and v[i]>=v[i+1])
		{
			opadajuci.resize(k+1);
			bio_niz=true;
			opadajuci[k].push_back(v[i]);
			i++;
			if(i==v.size()-1)
				break;
		}
		if(i<v.size() and bio_niz)
		{
			opadajuci[k].push_back(v[i]);
			k++;
			i++;
		}
		if(!bio_niz)
			i++;
		if(i>=v.size())
			break;
		bio_niz=false;
	}
	return opadajuci;
}

int main ()
{
	Matrica mat;
	vector <double> vek;
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		double x(0);
		cin>>x;
		vek.push_back(x);
	}
	mat=RastuciPodnizovi(vek);
	cout<<"Maksimalni rastuci podnizovi: ";
	cout<<"\n";
	for(vector<double> v:mat)
	{
		for(double y:v)
			cout<<y<<" ";
		cout<<"\n";
	}
	mat.resize(0);
	mat=OpadajuciPodnizovi(vek);
	cout<<"Maksimalni opadajuci podnizovi: ";
	cout<<"\n";
	for(vector<double> v:mat)
	{
		for(double y:v)
			cout<<y<<" ";
		cout<<"\n";
	}
	return 0;
}