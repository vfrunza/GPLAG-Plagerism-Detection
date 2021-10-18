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
using namespace std;

string ObrniFraze(string s, vector<string> v)
{
	string v1;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if(s.substr(j,v[i].size())==v[i])
			{
				v1=v[i];
				for(int k=v[i].size()-1;k>=0;k--)
				{
					s[j]=v1[k]; j++;
				}
			}
		}
	}
	return s;
} 

string IzmijeniUPigLatin(string s, vector<string> v)
{
	
	string v1;
	for(int i=0;i<v.size();i++)
	{
		v1=v[i];
		for(int k=0;k<v[i].size();k++)
		{
			if(v1[k]<'A' || v1[k]>'z') throw domain_error("Nekorektan izbor rijeci");
		} 
		for(int j=0;j<s.length();j++)
		{
			if(s.substr(j,v[i].size())==v[i])
			{
				s=s.substr(0,j)+s.substr(j+1,v[i].size()-1)+s[j]+"ay"+s.substr(j+v[i].size(),s.length()); //-(j+v[i].size()));
				j++; 
				
			}
		}
	}
	return s;
}

int main ()
{
	string s,fraze;
	vector<string> v;
	cout<<"Unesite recenicu: "<<endl;
	getline(cin,s);
	cout<<"Unesite fraze: "<<endl;
	do {
		getline(cin,fraze);
		v.push_back(fraze);
	} while(fraze!=""); 
/*	string s{"moje ime je semina"};
	vector<string> v(2);
	for(int i=0;i<v.size();i++)
	getline(cin,v[i]); */
	s=IzmijeniUPigLatin(s,v);
	cout<<s;
	return 0; 
}