/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<string>
#include<iostream>
#include <vector>
using namespace std;

bool DaLiJeRazmak(char znak)
{
	return isspace(znak);
}
bool DaLiNijeRazmak(char znak)
{
	return !isspace(znak);
}
bool DaLiSuIsti(string prva, string druga)
{
		if(prva.length()!=druga.length()) return false;
	for(int i=0;i<prva.length();i++)
	{
	
		if(prva[i]!=druga[i]) return false;
	}
	return true; }


vector<string>RastaviRecenicuNaRijeci(const string &MojString)
{
	vector<string> Rijeci;
 typedef string::const_iterator it;
 it i=MojString.pocetak();
 while(i!=MojString.end())
 {
 	i=find_if(i, MojString.kraj(), DaLiNijeRazmak);
 	it j=find_if(i, MojString.kraj(), DaLiJeRazmak);
 	if(i!=MojString.end())
 	Rijeci.push_back(string(i,j));
 	i=j;
 }
 return Rijeci;
	
}
string ObrniFraze(string MojString, vector<string> Rijeci)
{
	vector<string> RijeciRecenice=RastaviRecenicuNaRijeci(MojString);
	for(int i=0;i<RijeciRecenice.size();i++)
	{
		for(int j=0;j<Rijeci.size();j++)
		{
			if(DaLiSuIsti(RijeciRecenice[i], Rijeci[j]))
			{
				RijeciRecenice[i].reverse(RijeciRecenice[i].begin(), RijeciRecenice[i].end());
			}
		}
	}
	string Recenica;
	for(int i=0;i<RijeciRecenice.size();i++)
	{
		
		Recenica+=RijeciRecenice[i]+' ';
	}
	return Recenica;
}
int main ()
{
	return 0;
}