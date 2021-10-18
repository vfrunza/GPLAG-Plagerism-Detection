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
#include <cstring>
#include <stdexcept>
using std::cout;
using std::cin;
using std::vector;
using std::string;
string Obrni(string fraza)
{
	string obrnuta(fraza.size(),' ');
	for(int i=0;i<fraza.size();i++)
	{
		obrnuta[i]=fraza[(fraza.size()-1)-i];
	}
	return obrnuta;
}
string Izmijeni(string fraza)
{
	string pom((fraza.size()),' ');
//	string slog{"ay"};
	for(int i=1;i<fraza.size();i++)
	{
		pom[i-1]=fraza[i];
	}
	pom[pom.size()-1]=fraza[0];
//	pom[pom.size()-2]=slog[0];
//	pom[pom.size()-1]=slog[1];
	return pom;
}
string ObrniFraze(string recenica,vector<string> vekfraza)
{
	string modifikovana(recenica.size(),' ');
	for(int k=0;k<modifikovana.size();k++)
	modifikovana[k]=recenica[k];
//	if(modifikovana.size()==1)
//	return modifikovana; //ako je jedno slovo u recenici, bez obzira na fraze, uvijek ce biti vracena ista recenica
	for(int i=0;i<vekfraza.size();i++)
	{
		for(int j=0;j<recenica.size();j++)
		{
			string obrnuta;
			if(vekfraza[i]==recenica.substr(j,vekfraza[i].size()) && j<(recenica.size()+1-vekfraza[i].size()))
			{
				obrnuta=Obrni(vekfraza[i]);
				int z(j);
				for(int k=0;k<obrnuta.size();k++)
				{
					modifikovana[z]=obrnuta[k];
					recenica[z]=obrnuta[k];
					z++;
				}
			}
		}
	}
	return modifikovana;
}
string IzmijeniUPigLatin(string recenica,vector<string> vekfraza)
{
   if(vekfraza.size()==0)
    {
        string zavrsna(recenica.size(),' ');
    	vector<string> rijeci;
    	for(int i=0;i<recenica.size();i++)
    	{
    		string pom;
    	//	int brojslova(0);
    		while((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z'))
    		{
    		pom.push_back(recenica[i]);
    	//	brojslova++;
    		if(i<recenica.size()-1)
    		i++;
    		else
    		break;
    		}
    		if(pom.size()!=0)
    		rijeci.push_back(pom);
    	}
    	for(int i=0;i<zavrsna.size();i++)
    	zavrsna[i]=recenica[i];
    	for(int i=0;i<rijeci.size();i++)
    	{
    		for(int j=0;j<zavrsna.size();j++)
    		{
 
    			if(rijeci[i]==zavrsna.substr(j,rijeci[i].size()) && j<(zavrsna.size()+1-rijeci[i].size()))
    			{
    			if(!((zavrsna[j-1]>='a' && zavrsna[j-1]<='z') || (zavrsna[j-1]>='A' && zavrsna[j-1]<='Z')) && !((zavrsna[j+rijeci[i].size()]>='a' && zavrsna[j+rijeci[i].size()]<='z') || (zavrsna[j+rijeci[i].size()]>='A' && zavrsna[j+rijeci[i].size()]<='Z')))
    			{
    				string transfromisana;
    				transfromisana=Izmijeni(rijeci[i]);
    				for(int k=0;k<transfromisana.size();k++)
    				{
    					zavrsna[j]=transfromisana[k];
    					recenica[j]=transfromisana[k];
    					j++;
    				}
    				zavrsna.insert(zavrsna.begin()+j,'a');
    				zavrsna.insert(zavrsna.begin()+j+1,'y');
    			}
    			}
    		}
    	}
    	return zavrsna;
    }
	for(int i=0;i<vekfraza.size();i++)
	{
		for(int j=0;j<vekfraza[i].size();j++)
		{
			if(!((vekfraza[i][j]>='a' && vekfraza[i][j]<='z') || (vekfraza[i][j]>='A' && vekfraza[i][j]<='Z')))
			throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	string zavrsna(recenica.size(),' ');
	for(int i=0;i<zavrsna.size();i++)
	zavrsna[i]=recenica[i];
	for(int i=0;i<vekfraza.size();i++)
	{
		for(int j=0;j<zavrsna.size();j++)
		{
			string transfromisana;
			if(vekfraza[i]==zavrsna.substr(j,vekfraza[i].size()) && j<(zavrsna.size()+1-vekfraza[i].size()))
			{
			if(zavrsna.size()==vekfraza[i].size() || ((!((zavrsna[j-1]>='a' && zavrsna[j-1]<='z') || (zavrsna[j-1]>='A' && zavrsna[j-1]<='Z')) && !((zavrsna[j+vekfraza[i].size()]>='a' && zavrsna[j+vekfraza[i].size()]<='z') || (zavrsna[j+vekfraza[i].size()]>='A' && zavrsna[j+vekfraza[i].size()]<='Z')))))
			{	transfromisana=Izmijeni(vekfraza[i]);
				for(int k=0;k<transfromisana.size();k++)
				{
					zavrsna[j]=transfromisana[k];
					j++;
				}
				zavrsna.insert(zavrsna.begin()+j,'a');
				zavrsna.insert(zavrsna.begin()+j+1,'y');
			}
			}
		}
	}
	return zavrsna;
}
int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	std::getline(std::cin,recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze(0);
	for(;;)
	{
	    string pom;
		std::getline(std::cin,pom);
		if(pom.size()==0) break;
		fraze.push_back(pom);
	//	if(cin.peek()=='\n') break;
	}
	string recenica1;
	try
	{
		recenica1=IzmijeniUPigLatin(recenica,fraze);
		cout<<"Recenica nakon PigLatin transformacije: ";
	    cout<<recenica1;
	}
	catch(std::domain_error izuzetak)
	{
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
	recenica=ObrniFraze(recenica,fraze);
	cout<<recenica;
	return 0;
}