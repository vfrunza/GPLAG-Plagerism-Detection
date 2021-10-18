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

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

bool NijeSlovo(char c)
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z') )return false;
	return true;
}

string PigLatin(string rijec)
{
	rijec.push_back(rijec[0]);
	for(int i=0; i<rijec.size()-1; i++)
		rijec[i]=rijec[i+1];
	rijec[rijec.size()-1]='a';
	rijec.push_back('y');
	return rijec;
}

string ObrniFraze(string recenica, vector<string> fraze)
{
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<=recenica.size()-fraze[i].size(); j++)
		{
			if(fraze[i]==recenica.substr(j, fraze[i].size()))
			{
				
				char pomocni;
				int l(0);
				for(int k=j; k<j+fraze[i].size()/2; k++)
				{
					pomocni=recenica[k];
					recenica[k]=recenica[j+fraze[i].size()-1-l];
					recenica[j+fraze[i].size()-1-l]=pomocni;
					l++;
				}
				j+=fraze[i].size();
			}
		}
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica, vector<string> rijeci)
{
	for(int i=0; i<rijeci.size(); i++)
		for(int j=0; j<rijeci[i].size(); j++)
			if(rijeci[i][j]<'A' || (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z')throw std::domain_error("Nekorektan izbor rijeci");
			
	if(rijeci.size()==0)
	{
		for(int i=0; i<recenica.size(); i++)
		{
			if((NijeSlovo(recenica[i-1]) || i==0) && !NijeSlovo(recenica[i]))
			{
				int j=i;
				string pomocni;
				while(!NijeSlovo(recenica[j]) && j!=recenica.size())
				{
					pomocni.push_back(recenica[j]);
					j++;
				}	
				recenica=recenica.substr(0, i)+PigLatin(pomocni)+recenica.substr(j, recenica.size()-j);
			}
		}
	}
			
	for(int i=0; i<rijeci.size(); i++)
	{
		for(int j=0; j<=recenica.size()-rijeci[i].size(); j++)
		{
			if(rijeci[i]==recenica.substr(j, rijeci[i].size()) && (recenica[j-1]==' ' || j==0) && (recenica[j+rijeci[i].size()]==' ' || j+rijeci[i].size()==recenica.size()))
			{
				recenica=recenica.substr(0, j)+PigLatin(rijeci[i])+recenica.substr(j+rijeci[i].size(), recenica.size()-j-rijeci[i].size());
				j+=rijeci[i].size();
			}
		}
	}
	return recenica;
}


int main ()
{
	string recenica;
	vector<string> rijeci_fraze;
	string pomocni;
	cout<<"Unesite recenicu: ";
	getline(cin, recenica);
	cout<<"Unesite fraze: ";
	for(;;)
	{
		getline(cin, pomocni);
		if(pomocni=="")break;
		rijeci_fraze.push_back(pomocni);
	}
	try
	{
	string recenica1(IzmijeniUPigLatin(recenica, rijeci_fraze));
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<recenica1<<endl;
	}
	catch(std::domain_error izuzetak)
	{
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	string recenica2(ObrniFraze(recenica, rijeci_fraze));
	cout<<"Recenica nakon obrtanja fraza: ";
	cout<<recenica2;
	
	
	return 0;
}