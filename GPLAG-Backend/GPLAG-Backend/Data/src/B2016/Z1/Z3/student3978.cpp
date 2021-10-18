/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<vector <double>> RastuciPodnizovi(vector<double> v)
{
	vector<vector <double>> m;
	
	int i(0);

	
	while(i<v.size())
	{
		vector<double> vrste;
		
		
		if(i!=v.size()-1 && v[i]<=v[i+1]){
		while(i!=v.size()-1 && v[i]<=v[i+1])
		{
			vrste.push_back(v[i]);
			
			i++;
			
			if((i+1)<=v.size()-1 && v[i]>v[i+1] && v[i]>=v[i-1]) vrste.push_back(v[i]);
			
			if(i==v.size()-1 && v[i]>=v[i-1])
			{
				vrste.push_back(v[i]);
				break;
			}
		}
		
		
		m.push_back(vrste);
		}
		else i++;
		
	
	}
	
	
	
	
	return m; 
}

vector<vector <double>> OpadajuciPodnizovi(vector<double> v)
{
	vector<vector <double>> m;
	int i(0);
	
	while(i!=v.size())
	{
		vector<double> vrste;
		if(i!=v.size()-1 && v[i]>=v[i+1]) {
		while(i!=v.size()-1 && v[i]>=v[i+1])
		{
			vrste.push_back(v[i]);
			i++;
			
			if((i+1)<=v.size()-1 && v[i]<v[i+1] && v[i]<=v[i-1]) vrste.push_back(v[i]);
			
			if(i==v.size()-1 && v[i]<=v[i-1])
			{
				vrste.push_back(v[i]);
				break;
			}
			
		}
		
		m.push_back(vrste);
		}
		
		else i++;
		
	}
	
	return m;
}

int main ()
{
	int broj;
	cout << "Unesite broj elemenata vektora: ";
	cin >> broj;
	
	vector<double> v;
	cout << "Unesite elemente vektora: ";
	double element;
	for(int br=0; br<broj; br++)
	{
		cin>> element;
		v.push_back(element);
		if(br==broj) break;
	}

	
	vector<vector <double>> rastuci=RastuciPodnizovi(v);
	
	cout << "Maksimalni rastuci podnizovi: " << endl;
	for(int i=0; i<rastuci.size(); i++)
	{
		for(int j=0; j<rastuci[i].size(); j++)
		cout << rastuci[i][j] << " ";
		cout << endl;
	}
	
	vector<vector <double>> opadajuci=OpadajuciPodnizovi(v);
	
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	for(int i=0; i<opadajuci.size(); i++)
	{
		for(int j=0; j<opadajuci[i].size(); j++)
		{
			cout << opadajuci[i][j] << " ";
		}
		
		cout << endl;
	}
	
	
	return 0;
}