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
using std::vector;
using std::endl;

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v)
{
	Matrica M;
	if (v.size()==0) return Matrica(0, vector<double>(0));
	int j(1);
	int i(0);
	int br_redova(1);
	vector<double> pomocni;
	while (j<v.size())
	{
		M.resize(br_redova);
		if (v[i]<=v[j]) pomocni.push_back(v[i]);
		if (j==v.size()-1 and v[i]<=v[j]) 
		{
			pomocni.push_back(v[j]);
			if (pomocni.size()!=1) M.push_back(pomocni);
		}
		else if (v[i]>=v[j] and i!=0 and v[i-1]<v[i])
		{
			pomocni.push_back(v[i]);
			M.push_back(pomocni);
			br_redova++;
			pomocni.resize(0);
		}
		else if (v[i]>=v[j] and i!=0 and v[i-1]<=v[i] and j==v.size()-1)
		{
			pomocni.push_back(v[i]);
			M.push_back(pomocni);
			br_redova++;
			pomocni.resize(0);
		}
		i++;
		j++;
	}
	return M;
}

Matrica OpadajuciPodnizovi(vector<double> v)
{
	Matrica M;
	if (v.size()==0) return Matrica(0, vector<double>(0));
	int j(1);
	int i(0);
	int br_redova(1);
	vector<double> pomocni;
	while (j<v.size())
	{
		M.resize(br_redova);
		if (v[i]>=v[j]) pomocni.push_back(v[i]);
		if (j==v.size()-1 and v[i]>=v[j]) 
		{
			pomocni.push_back(v[j]);
			M.push_back(pomocni);
		}
		else if (v[i]<=v[j] and i!=0 and v[i-1]>=v[i])
		{
			pomocni.push_back(v[i]);
			M.push_back(pomocni);
			br_redova++;
			pomocni.resize(0);
		}
		else if (j==v.size()-1 and i!=0 and v[i-1]>=v[i] and v[i]<=v[j]) 
		{
			pomocni.push_back(v[i]);
			M.push_back(pomocni);
			br_redova++;
			pomocni.resize(0);
		}
		i++;
		j++;
	}
	return M;
}

int main ()
{
	int n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	vector<double> v(n);
	cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++)
		cin >> v[i];
	auto rastuci_podnizovi=RastuciPodnizovi(v);
	auto opadajuci_podnizovi=OpadajuciPodnizovi(v);
	cout << "Maksimalni rastuci podnizovi: ";
	for (int i=0; i<rastuci_podnizovi.size(); i++)
	{
		for (int j=0; j<rastuci_podnizovi[i].size(); j++)
		{
			cout << rastuci_podnizovi[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Maksimalni opadajuci podnizovi: ";
	for (int i=0; i<opadajuci_podnizovi.size(); i++)
	{
		for (int j=0; j<opadajuci_podnizovi[i].size(); j++)
		{
			cout << opadajuci_podnizovi[i][j] << " ";
		}
		cout << endl;
	} 
	return 0;
}