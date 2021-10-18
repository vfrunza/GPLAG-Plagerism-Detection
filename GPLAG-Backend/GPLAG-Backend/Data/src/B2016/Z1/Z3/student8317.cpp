/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>>RastuciPodnizovi(vector<double> realni)
{
	vector<vector<double>>rezultat;
	vector<double> rastuci;
	
	 for(int i=0;i<realni.size()-1;i++)
	 {
	 	if(realni[i]<=realni[i+1])
	 	{
	 		while((i+1)<realni.size() &&(realni[i]<=realni[i+1]))
	 		{
	 			rastuci.push_back(realni[i]);
	 			i++;
	 		}
	 		rastuci.push_back(realni[i]);
	 	}
	 	
	 	if(rastuci.size()>1)
	 	{
	 	rezultat.push_back(rastuci);
	 	}
	 	rastuci.resize(0);
	 }
	return rezultat;
}


vector<vector<double>> OpadajuciPodnizovi(vector<double> realni)
{
	vector<vector<double>>rezultat;
	vector<double> opadajuci;
	
	 for(int i=0;i<realni.size()-1;i++)
	 {
	 	if(realni[i]>=realni[i+1])
	 	{
	 		while((i+1)<realni.size() && realni[i]>=realni[i+1])
	 		{
	 			opadajuci.push_back(realni[i]);
	 			if((i+1)>=realni.size())
	 			{
	 				continue;
	 			}
	 			i++;
	 		}
	 		opadajuci.push_back(realni[i]);
	 	}
	 	
	 	if(opadajuci.size()>1)
	 	{
	 	rezultat.push_back(opadajuci);
	 	}
	 	opadajuci.resize(0);
	 }
	return rezultat;
}


int main ()
{
	
	vector<double> brojevi;
	
	int n;
	int elemenat;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	
for(int i=0;i<n;i++)
{
	cin>>elemenat;
	brojevi.push_back(elemenat);
}

	vector<vector<double>> a=RastuciPodnizovi(brojevi);
	vector<vector<double>> v=OpadajuciPodnizovi(brojevi);
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;

	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}