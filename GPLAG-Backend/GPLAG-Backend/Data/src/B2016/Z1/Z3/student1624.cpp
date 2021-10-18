#include <iostream>
#include <vector>
using namespace::std;

vector<vector<double>> RastuciPodnizovi(vector<double> a)
{
	vector<vector<double>> podnizovi;
	for(int i = 1; i < a.size()-1; i++)
	{
		vector<double> temp;
		bool ima(false);
		while(a[i] >= a[i-1])
		{
			temp.push_back(a[i-1]);
			ima = true;
			i++;
			if(i == a.size())
				break;
		}
		if(ima)
        {
			temp.push_back(a[i-1]);
            podnizovi.push_back(temp);
        }
	}
	return podnizovi;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> a)
{
	vector<vector<double>> podnizovi;
	for(int i = 1; i < a.size(); i++)
	{
		vector<double> temp;
		bool ima(false);
		while(a[i] <= a[i-1])
		{
			temp.push_back(a[i-1]);
			ima = true;
			i++;
			if(i == a.size())
				break;
		}
		if(ima)
        {
			temp.push_back(a[i-1]);
		podnizovi.push_back(temp);
        }
	}
	return podnizovi;
}
int main()
{
	int vel;
	cout << "Unesite broj elemenata vektora: ";
	cin >> vel;
	if (vel == 0)
		return 0;
	vector<double> niz(vel);
	cout << "Unesite elemente vektora: ";
	for(int i = 0; i < niz.size();i++)
	{
		cin >> niz[i];
	}
	cout << "Maksimalni rastuci podnizovi: " << endl;
	vector<vector<double>> rast = RastuciPodnizovi(niz);
	for(auto a:rast)
	{
		for(auto z:a)
            cout << z << " ";
        cout << endl;
	}
	cout << "Maksimalni opadajuci podnizovi: " << endl;
		vector<vector<double>> op = OpadajuciPodnizovi(niz);
	for(auto a:op)
	{
		for(auto z:a)
            cout << z << " ";
        cout << endl;
	}
	return 0;
}