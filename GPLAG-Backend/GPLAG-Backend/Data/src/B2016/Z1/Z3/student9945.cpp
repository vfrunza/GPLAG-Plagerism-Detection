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
vector<vector<double> > RastuciPodnizovi(vector<double> v)
{
	vector<vector<double> > m;
	int br;
	int di, k(0);
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]<=v[i+1])
		{
			m.resize(m.size()+1);
			br=0;di=i;
			while(v[i]<=v[i+1] && i<v.size()-1) { br++; i++; if(i==v.size()-1 || i==v.size()) break;}
			for(int j=di;j<=di+br;j++) m[k].push_back(v[j]);
			k++;
		}
	}
	return m;
}
vector<vector<double> > OpadajuciPodnizovi(vector<double> v)
{
	vector<vector<double> > m;
	int br;
	int di, k(0);
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]>=v[i+1])
		{
			m.resize(m.size()+1);
			br=0; di=i;
			while(v[i]>=v[i+1] && i<v.size()-1) { br++; i++;if(i==v.size()-1 || i==v.size()) break;}
			for( int j=di;j<=di+br;j++) m[k].push_back(v[j]);
			k++;
		}
	}
	return m;
}
int main ()
{
	int n;
	vector<vector<double> > m;
	vector<double> v;
	cout<<"Unesite broj elemenata vektora: ";
	double q;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		cin>> q;
		v.push_back(q);
	}
	m=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			cout<<m[i][j];
			if(j!=m[i].size()-1) cout<<" ";
		} 
		cout<<endl;
	}
	m=OpadajuciPodnizovi(v);
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			cout<<m[i][j];
			if(j!=m[i].size()-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}