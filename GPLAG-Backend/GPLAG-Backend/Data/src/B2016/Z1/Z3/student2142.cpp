/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool JesuLiJednaki(double x, double y, double Eps=1e-10)
{
	return fabs(x-y)<=Eps*(fabs (x)+fabs(y));
}

vector<vector<double> >RastuciPodnizovi(vector<double> v)
{
	vector<vector<double> > rastuci;
	int br=-1;
	for(int i=0; i<v.size()-1; i++)
	{
		int j;
		if(v[i]<=v[i+1] || JesuLiJednaki(v[i], v[i+1]))
		{
			br++;
			rastuci.push_back(vector<double>(0));
			for(j=i; j<v.size()-1; j++)
			{
				rastuci[br].push_back(v[j]);
				if(v[j]>v[j+1] && !JesuLiJednaki(v[j], v[j+1]))break;
			}
			if(j==v.size()-1 && (v[j-1]<=v[j] || JesuLiJednaki(v[j-1], v[j])))rastuci[br].push_back(v[j]);
			i=j;
		}
	}
	return rastuci;
}

vector<vector<double> >OpadajuciPodnizovi(vector<double> v)
{
	vector<vector<double> > opadajuci;
	int br=-1;
	for(int i=0; i<v.size()-1; i++)
	{
		int j;
		if(v[i]>=v[i+1] || JesuLiJednaki(v[i], v[i+1]))
		{
			br++;
			opadajuci.push_back(vector<double>(0));
			for(j=i; j<v.size()-1; j++)
			{
				opadajuci[br].push_back(v[j]);
				if(v[j]<v[j+1] && !JesuLiJednaki(v[j], v[j+1]))break;
			}
			if(j==v.size()-1 && (v[j-1]>=v[j] || JesuLiJednaki(v[j-1], v[j])))opadajuci[br].push_back(v[j]);
			i=j;
		}
	}
	return opadajuci;
}

int main ()
{
	int broj_elemenata;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>broj_elemenata;
	vector<double> v(broj_elemenata);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	vector<vector<double> > rastuci(RastuciPodnizovi(v));
	vector<vector<double> > opadajuci(OpadajuciPodnizovi(v));
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<rastuci.size(); i++)
	{
		for(int j=0; j<rastuci[i].size(); j++)
			cout<<rastuci[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<opadajuci.size(); i++)
	{
		for(int j=0; j<opadajuci[i].size(); j++)
			cout<<opadajuci[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}