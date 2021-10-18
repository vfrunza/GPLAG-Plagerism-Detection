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

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double>niz)
{
	vector<vector<double>> rastuci;
	vector<double>temp;
	int count;
	
	if (niz.size()==0)
	{
		return rastuci;
	}
	
	for (unsigned int i=0; i<niz.size()-1; i++)
	{
		if (niz[i]<=niz[i+1])
		{
			count=0;
			for (unsigned int j=i; j<niz.size()-1; j++)
			{
				if (niz[j]<=niz[j+1])
				{
					temp.push_back(niz[j]);
					i=j;
					count++;
				}
				
				else
				{
					temp.push_back(niz[j]);
					i=j;
					count=0;
					break;
				}
				i=j;
			}
			
			if (count>0 && i+1==niz.size()-1)
			{
				temp.push_back(niz[i+1]);
			}
			rastuci.push_back(temp);
			temp.clear();
		}
	}
	
	
	return rastuci;
}


vector<vector<double>> OpadajuciPodnizovi(vector<double>niz)
{
	vector<vector<double>> opadajuci;
	vector<double>temp;
	int count;
	
	if (niz.size()==0)
	{
		return opadajuci;
	}

	for (unsigned int i=0; i<niz.size()-1; i++)
	{
		if (niz[i]>=niz[i+1])
		{
			count=0;
			for (unsigned int j=i; j<niz.size()-1; j++)
			{
				if (niz[j]>=niz[j+1])
				{
					temp.push_back(niz[j]);
					i=j;
					count++;
				}
				
				else
				{
					temp.push_back(niz[j]);
					i=j;
					count=0;
					break;
				}
				i=j;
			}
			
			if (count>0 && i+1==niz.size()-1)
			{
				temp.push_back(niz[i+1]);
			}
			opadajuci.push_back(temp);
			temp.clear();
		}
	}
	return opadajuci;
}

int main ()
{
	int n,temp;
	vector<double> niz,kopija;
	vector<vector<double>>rastuci, opadajuci;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++)
	{
		cin>>temp;
		niz.push_back(temp);
	}
	kopija=niz;
	
	rastuci=RastuciPodnizovi(niz);
	
	cout<<"Maksimalni rastuci podnizovi: ";
	cout<<endl;
	for (int j=0; j<rastuci.size(); j++)
	{
		for (int k=0; k<rastuci[j].size(); k++)
		{
			cout<<rastuci[j][k]<<" ";
		}
		cout<<endl;
	}
	

	opadajuci=OpadajuciPodnizovi(kopija);
	
	cout<<"Maksimalni opadajuci podnizovi: ";
	cout<<endl;
	for (int b=0; b<opadajuci.size(); b++)
	{
		for (int a=0; a<opadajuci[b].size(); a++)
		{
			cout<<opadajuci[b][a]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}