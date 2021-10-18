#include <iostream>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> v)
{
	int velicina=0;
	Matrica mat;
	std::vector<double> novi1;
	for (int i=0; i<v.size()-1; i++)
	{
		novi1.clear();
		
		if (v[i]<=v[i+1])
		{
		while (v[i]<=v[i+1]) 
		{
			novi1.push_back(v[i]); i++;
			if (i==v.size()-1) break;
		}
		novi1.push_back(v[i]);
		if (velicina < novi1.size()) velicina=novi1.size();
		}
		velicina=mat.size();
		if (novi1.size()!=0) { 
		mat.push_back(novi1); }
	}
	
	
	return mat;
}

Matrica OpadajuciPodnizovi (std::vector<double> v)
{
	int velicina=0;
	Matrica mat;
	std::vector<double> novi2;
	for (int i=0; i<v.size()-1; i++)
	{
		novi2.clear();
	
		if (v[i]>=v[i+1])
		{
		while (v[i]>=v[i+1]) 
		{
			novi2.push_back(v[i]); i++;
			if (i==v.size()-1) break;
		}
		novi2.push_back(v[i]);
		if (velicina < novi2.size()) velicina=novi2.size();
		}
		velicina=mat.size();
		if (novi2.size()!=0) {
		mat.push_back(novi2); }
}

	return mat;
}


int main ()
{
	Matrica m;
	double n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	std::vector<double> v(n);
	cout << "Unesite elemente vektora: ";
	for (int i=0; i<v.size(); i++)
	{
		cin >> v[i];
	}

	cout << "Maksimalni rastuci podnizovi: " << endl;
	
	m=RastuciPodnizovi(v);
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << m[i][j] << " ";
	
		}
		cout << endl;

	}
	m=OpadajuciPodnizovi(v);
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

