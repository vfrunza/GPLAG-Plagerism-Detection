/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;

vector<vector<double>> RastuciPodnizovi (vector<double> v) {
	vector<vector<double>> sviR(0);
	vector<double> jedanR(0);
	vector<double> novi(0);
	int i=0;
	for(i=0; i<v.size()-1; i++)
	{
		jedanR=novi;
		double *poc1=&v[i];
		
		while (i<v.size()-1 && v[i]<=v[i+1])
		{
			i++;
		}
		double *poc2=&v[i];
		while (poc1<=poc2) 
		{
			jedanR.push_back(*poc1++);
		}
		if(jedanR.size()==0 || jedanR.size()==1)
			continue;
		sviR.push_back(jedanR);
		if(i==v.size())break;
		i--;
	}
	
	return sviR;
}

vector<vector<double>> OpadajuciPodnizovi (vector<double> v) {
	vector<vector<double>> sviR(0);
	vector<double> jedanR(0);
	vector<double> novi(0);
	for(int i=0; i<v.size()-1; i++)
	{
		jedanR=novi;
		double *poc1=&v[i];
		while (i<v.size()-1 && v[i]>=v[i+1])
			i++;
		double *poc2=&v[i];
		while (poc1<=poc2) 
		{
			jedanR.push_back(*poc1++);
		}
		if(jedanR.size()==0 || jedanR.size()==1)
			continue;
		sviR.push_back(jedanR);
		
	}
	
	return sviR;
}

/*
vector<vector<double>> RastuciPodnizovi (vector<double> v) {
	vector<vector<double>> sviR(0);
	vector<double> jedanR(0);
	vector<double> novi(0);
	for(int i=0; i<v.size()-1; i++) {
		
			jedanR=novi;
		if (  v[i]<=v[i+1]) {
			while (i<v.size() && v[i]<=v[i+1] ) {
				jedanR.push_back(v[i]);
				i++;
			}
			if(i==v.size()-1 && v[i]>=v[i-1])
				jedanR.push_back(v[i]);
		}
		if(jedanR.size()==0)
			continue;
		sviR.push_back(jedanR);
	}
return sviR;
}

vector<vector<double>> OpadajuciPodnizovi (vector<double> v) {
	vector<double> jedanR(0);
	vector<double> novi(0);
	vector<vector<double>> sviR(0);
	for(int i=0; i<v.size()-1; i++) {
		jedanR=novi;
		if (v[i]>=v[i+1]) {
			while (i<v.size() && v[i]>=v[i+1]) {
				jedanR.push_back(v[i]);
				i++;
			}
			if(i==v.size()-1 && v[i]<=v[i-1])
				jedanR.push_back(v[i]);
		}
		if(jedanR.size()==0)
			continue;
		sviR.push_back(jedanR);
	}
return sviR;
}*/

int main ()
{
	
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cin.clear();
	cin.ignore(10000,'\n');
	vector<double> v(0);
	cout<<"Unesite elemente vektora: ";
	int x;
	for (int i=0; i<n; i++) {
		cin>>x;
		v.push_back(x);
	}
	std::vector<std::vector<double>> max=RastuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<max.size(); i++)
	{
		for(int j=0; j<max[i].size(); j++)
			cout<<max[i][j]<<" ";
		std::cout<< std::endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (vector<double> red: OpadajuciPodnizovi(v)) {
		for (double x: red)	cout<<x<<" ";
		cout<<std::endl;
	}
	return 0;
}