//B 2016/2017, Zadaća 1, Zadatak 3
	
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

// Funkcija RastuciPodnizovi odredjuje i vraca rastuce 
// podnizove u vektoru
vector<vector<double>> RastuciPodnizovi(vector<double> v)
{
	vector<vector<double>> rastuci;
	vector<double> podniz;
	bool veci(false);
	
	for(int i=1; i<v.size(); i++)
	{
		vector<double> prazni;
		
		if(v[i]>=v[i-1]) 
		{
			podniz.push_back(v[i-1]);
			if(i==v.size()-1) 
			{
				podniz.push_back(v[i]);
				rastuci.push_back(podniz);
			}
			veci=true;
		}
		else 
		{
			if(veci) 
			{
				podniz.push_back(v[i-1]);
				rastuci.push_back(podniz);
				podniz=prazni;
			}
			veci=false;
		}
	}
	return rastuci;
}
// Funkcija OpadajuciPodnizovi odredjuje i vraca opadajuce 
// podnizove u vektoru
vector<vector<double>> OpadajuciPodnizovi(vector<double> v)
{
	vector<vector<double>> opadajuci;
	vector<double> podniz;
	bool manji(false);
	
	for(int i=1; i<v.size(); i++)
	{
		vector<double> prazni;
		
		if(v[i]<=v[i-1]) 
		{
			podniz.push_back(v[i-1]);
			if(i==v.size()-1) 
			{
				podniz.push_back(v[i]);
				opadajuci.push_back(podniz);
			}
			manji=true;
		}
		else 
		{
			if(manji) 
			{
				podniz.push_back(v[i-1]);
				opadajuci.push_back(podniz);
				podniz=prazni;
			}
			manji=false;
		}
	}
	return opadajuci;
}

int main ()
{
	int n;
	
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	
	vector<double> v(n);
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	vector<vector<double>> rast(RastuciPodnizovi(v));
	vector<vector<double>> opad(OpadajuciPodnizovi(v));
	
	if(rast.size()>0)
	{
		cout << "Maksimalni rastuci podnizovi: " << endl;
		for(int i=0; i<rast.size(); i++)
		{
			for(int j=0; j<rast[i].size(); j++)
			{
				cout << rast[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	if(opad.size()>0)
	{
		cout << "Maksimalni opadajuci podnizovi: " << endl;
		for(int i=0; i<opad.size(); i++)
		{
			for(int j=0; j<opad[i].size(); j++)
			{
				cout << opad[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
