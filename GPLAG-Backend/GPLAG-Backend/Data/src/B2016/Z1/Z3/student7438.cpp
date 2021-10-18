/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::vector;
vector<vector<double>> RastuciPodnizovi(vector<double> a)
{
	vector<vector<double>> rastuci;
	vector<double> temp;
	vector<double> prazan;
	if(a.size()<=1)
	return rastuci;
	for(int i=0;i<a.size()-1;i++)
	{   int j(0);
		while(i<a.size()-1 && (a.at(i)<=a.at(i+1)))    /*Dok je niz rastuci clanove stavlja u temp vektor*/
		{
			temp.push_back(a.at(i));
			i++;
			j++;
		}
		temp.push_back(a.at(i));
		if(j>0)
		rastuci.push_back(temp);
		temp=prazan;
	}
	return rastuci;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> a)
{
	vector<vector<double>> opadajuci;
	vector<double> temp;
	vector<double> prazan;
	if(a.size()<=1)
	return opadajuci;
	for(int i=0;i<a.size()-1;i++)
	{   int j(0);
		while(i<a.size()-1 && (a.at(i)>=a.at(i+1)))  /*Dok je niz opadajuci clanove stavlja u temp vektor*/
		{
			temp.push_back(a.at(i));
			i++;
			j++;
		}
		temp.push_back(a.at(i));
		if(j>0)
		opadajuci.push_back(temp);
		temp=prazan;
	}
	return opadajuci;
}
	
int main ()
{
	double x;
	int n;
	vector<double> a;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0;i<RastuciPodnizovi(a).size();i++)
	{
		for(int j=0;j<RastuciPodnizovi(a).at(i).size();j++)
		{
			cout<<RastuciPodnizovi(a).at(i).at(j)<<" ";
		}
		cout<<"\n";
	}
	cout<<"Maksimalni opadajuci podnizovi: \n";
	for(int i=0;i<OpadajuciPodnizovi(a).size();i++)
	{
		for(int j=0;j<OpadajuciPodnizovi(a).at(i).size();j++)
		{
			cout<<OpadajuciPodnizovi(a).at(i).at(j)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}