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

using namespace std;



vector<vector<double>> RastuciPodnizovi(vector<double> v)
{
	vector<vector<double>> mat;
		v.resize(v.size()+1);
	vector<double>temp;
	double pret=v[0];
	
	for(int i=1;i<v.size();i++)	
	{   
		temp.push_back(pret);
		
		if(v[i]<pret || i==v.size()-1)
		{   
			if(temp.size()>1) mat.push_back(temp); 
			temp.resize(0);
		}
		
		pret=v[i];
	}
	
	return mat;
}


vector<vector<double>> OpadajuciPodnizovi(vector<double> v)
{
		vector<vector<double>> mat;
		v.resize(v.size()+1);
	vector<double>temp;
	double pret=v[0];
	
	for(int i=1;i<v.size();i++)	
	{   
		temp.push_back(pret);
		
		if(v[i]>pret || i==v.size()-1)
		{   
			if(temp.size()>1) mat.push_back(temp); 
			temp.resize(0);
		}
		
		pret=v[i];
	}

	return mat;
}
 

int main ()
{
	int n;
	
	
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;vector<double>v1(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v1.size(); i++) 
			cin>>v1[i];
	
	vector<vector<double>> mat=RastuciPodnizovi(v1);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}

	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	
	mat=OpadajuciPodnizovi(v1);
	
	
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	
	
	
	
	
	
	return 0;
}