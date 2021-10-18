/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: string;

string Sastavi(vector<string>rijeci)
{
	string recenica="";
	for(int i=0; i<rijeci.size(); i++)
	{
		recenica+=rijeci[i]+" ";
	}
	recenica.erase(recenica.begin()+recenica.length()-1);
	return recenica;
}

string ObrniFraze(string recenica, vector<string>fraze)
{
	string pomocna_rijec;
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<recenica.length(); j++)
		{
			if(recenica.substr(j,fraze[i].length())==fraze[i])
			{
				pomocna_rijec=recenica.substr(j, fraze[i].length());
				for(int k=0; k<pomocna_rijec.length()/2; k++)
				{
					char temp = pomocna_rijec[k];
					pomocna_rijec[k]=pomocna_rijec[pomocna_rijec.length()-k-1];
					pomocna_rijec[pomocna_rijec.length()-k-1]=temp;
				}
				int pomocna_j=j;
				for(int l=0; l<pomocna_rijec.length(); l++)
				{
					recenica[j]=pomocna_rijec[l];
					j++;
				}
				j=pomocna_j;
			}
		}
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica, vector<string>fraze)
{
	vector<string>rijeci;
	string random="";
	for(int i=0; i<recenica.length(); i++)
	{
		if(recenica[i]!=' ') random+=recenica[i];
		else rijeci.push_back(random), random="";
	}
	rijeci.push_back(random);
	
	
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<fraze[i].length(); j++)
		{
			if(!((fraze[i][j]>='a' && fraze[i][j]<='z') || (fraze[i][j]>='A' && fraze[i][j]<='Z'))) 
			throw std:: domain_error("Nekorektan izbor rijeci");
		}
	}
	
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<rijeci.size(); j++)
		{
			if(rijeci[j]==fraze[i])
			{
				rijeci[j]=rijeci[j].substr(1,rijeci[j].length()-1)+rijeci[j][0]+"ay";
			}
		}
	}
	
	if(fraze.size()==0)
	{
		for(int i=0; i<rijeci.size(); i++)
			rijeci[i]=rijeci[i].substr(1,rijeci[i].length()-1)+rijeci[i][0]+"ay";
	}
	recenica=Sastavi(rijeci);
	return recenica;
}

int main ()
{
	
	cout<<"Unesite recenicu: ";
	string recenica;
	std::getline(cin, recenica);
	cout<<"Unesite fraze: ";
	vector<string>fraze;
	while(true)
	{
		string pocetna_rijec;
		std:: getline(cin, pocetna_rijec);
		if(pocetna_rijec=="") break;
		fraze.push_back(pocetna_rijec);
	}
	
	try
	{
		cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, fraze)<<endl;
	}
	
	
	catch(std:: domain_error izuzetak)
	{
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	
	
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze)<<endl;
	
	return 0;
}