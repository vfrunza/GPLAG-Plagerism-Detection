/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include<limits>
using namespace std;

typedef vector<vector<double>> Matrica;
Matrica RastuciPodnizovi(vector<double>v) {
	Matrica Mat;
	vector<double> pom;
	v.resize(v.size()+1);
	v[v.size()-1]=numeric_limits<double>::min();
	
	for(int i=0;i<v.size()-1;i++) 
	{
if(v[i]<=v[i+1]) 
{
	pom.push_back(v[i]); 
	
}
	else if(v[i]>v[i+1]) 
	{
		
		pom.push_back(v[i]);
	if(pom.size()>1) Mat.push_back(pom);
	pom.resize(0); }
		
	}
	return Mat;
}
Matrica OpadajuciPodnizovi(vector<double> v) {
	
	Matrica Mat;
	vector<double> pom;
	v.resize(v.size()+1);
	v[v.size()-1]=numeric_limits<double>::max();
	
	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i]>=v[i+1]) 
		{
			pom.push_back(v[i]);
		}
		else if(v[i]<v[i+1]) 
		{
			pom.push_back(v[i]);
		if(pom.size()>1) Mat.push_back(pom);
		pom.resize(0); 
		}
	}
	return Mat;
}
int main() 
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
vector<double>v(n);
cout<<"Unesite elemente vektora: ";
for(int i=0; i<n; i++) {
	cin>>v[i]; 
}
cout<<"Maksimalni rastuci podnizovi: "<<endl;
Matrica Mat=RastuciPodnizovi(v);
for(int i=0; i<Mat.size(); i++) {
	for(int j=0; j<Mat[i].size(); j++)
	cout<<Mat[i][j] << " ";
	cout<<endl; 
}
cout<<"Maksimalni opadajuci podnizovi: "<<endl;
Matrica Mat1=OpadajuciPodnizovi(v);
for(int i=0; i<Mat1.size(); i++) {
	for(int j=0; j<Mat1[i].size(); j++)
cout<<Mat1[i][j]<<" ";
cout<<endl; 
}
return 0; 
}


	
	