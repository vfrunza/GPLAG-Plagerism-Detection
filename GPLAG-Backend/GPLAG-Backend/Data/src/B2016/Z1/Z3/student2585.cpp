/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: endl;

typedef std:: vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std:: vector<double> niz)
{
	Matrica rastuca;
	std:: vector<double>vrste;
	int i(0);
	while(i<niz.size()-1) {
		while(i<niz.size()-1 && niz[i]<=niz[i+1]) {
			vrste.push_back(niz[i]);
			i++;
		}
		vrste.push_back(niz[i]);
		if(vrste.size()>1) rastuca.push_back(vrste);
		vrste.resize(0);
		i++;
	}
	return rastuca;
}

Matrica OpadajuciPodnizovi (std:: vector<double> niz)
{
	Matrica opadajuca;
	std::vector<double>vrste;
	int i(0);
	while(i<niz.size()-1) {
		while(i<niz.size()-1 && niz[i]>=niz[i+1]){
			vrste.push_back(niz[i]);
			i++;
		}
		vrste.push_back(niz[i]);
		if(vrste.size()>1) opadajuca.push_back(vrste);
		vrste.resize(0);
		i++;
	}
	return opadajuca;
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n(0);
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	std:: vector<double>niz(n);
	for(int i=0; i<n; i++)
	{
		cin>>niz[i];
	}
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	Matrica rastuca=RastuciPodnizovi(niz);
	for(int i=0; i<rastuca.size(); i++)
	{
		for(int j=0; j<rastuca[i].size(); j++)
		{
			cout<<rastuca[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	Matrica opadajuca=OpadajuciPodnizovi(niz);
	for(int i=0; i<opadajuca.size(); i++)
	{
		for(int j=0; j<opadajuca[i].size(); j++)
		{
		cout<<opadajuca[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}



