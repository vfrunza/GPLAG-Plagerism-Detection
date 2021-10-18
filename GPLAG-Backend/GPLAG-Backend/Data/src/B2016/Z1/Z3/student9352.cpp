/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<double>> Matrica; 


Matrica RastuciPodnizovi(const vector<double> &v)
{
	Matrica podniz;
	bool TrebaPocetiNovi{false};
	
	vector<double> priv;
	
	for(int i=1;i<v.size();i++)
	{
		vector<double> pomocni;
		while( i<v.size() && v[i]>=v[i-1])
		{
			if(!TrebaPocetiNovi)
			{
				TrebaPocetiNovi=true;
				pomocni.push_back(v[i-1]);
			}
			pomocni.push_back(v[i]);
			i++;
		}
		if(i==v.size() || (v[i]<v[i-1] && TrebaPocetiNovi) )
		{
			TrebaPocetiNovi=false;
			priv=pomocni;
			podniz.push_back(priv);
			pomocni.clear();
		}
	}
	for(auto vi=podniz.begin(); vi!=podniz.end(); )
	{
		if(vi->size()==1 || vi->size()==0)  vi=podniz.erase(vi);
		else ++vi;
	}
	return podniz;
}

Matrica OpadajuciPodnizovi(const vector<double> &v)
{
	Matrica podniz;
	bool TrebaPocetiNovi{false};
	
	vector<double> priv;
	
	for(unsigned int i=1;i<v.size();i++)
	{
		vector<double> pomocni;
		while(i<v.size() && v[i]  <=v[i-1])
		{
			if(!TrebaPocetiNovi)
			{
				TrebaPocetiNovi=true;
				pomocni.push_back(v[i-1]);
			}
			pomocni.push_back(v[i]);
			i++;
		}
		if( i==v.size()  || (v[i]>v[i-1] && TrebaPocetiNovi))
		{
			TrebaPocetiNovi=false;
			priv=pomocni;
			podniz.push_back(priv);
			pomocni.clear();
		}
	}
	for(auto vi=podniz.begin(); vi!=podniz.end(); )
	{
		if(vi->size()==1  || vi->size()==0) vi=podniz.erase(vi);
		else ++vi;
	}
	return podniz;
}



int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> v;
	for(int i=0;i<n;i++)
	{
		double broj;
		cin>>broj;
		v.push_back(broj);
	}
	
	
	Matrica ra_podniz=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	
	for(unsigned int i=0;i<ra_podniz.size();i++)
	{
		for(unsigned int j=0;j<ra_podniz[i].size();j++)
		{
			cout<<ra_podniz[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	Matrica op_podniz=OpadajuciPodnizovi(v);
	for(unsigned int i=0;i<op_podniz.size();i++)
	{
		for(unsigned int j=0;j<op_podniz[i].size();j++)
		{
			cout<<op_podniz[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}