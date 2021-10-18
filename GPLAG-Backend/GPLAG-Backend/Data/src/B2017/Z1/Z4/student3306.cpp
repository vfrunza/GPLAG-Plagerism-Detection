/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string> 

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

string ObrniRijec (string s1)
{
	string s;
	for (int i=s1.length()-1; i>=0; i--)
	{
		s.push_back(s1.at(i));
	}
	return s;
}

string NapraviPalindrom (string s, vector<string> v)
{
	
    string ss;
    
	int l,j;

	for (int i=0; i<v.size(); i++)
	{
		l=0;
		
		j=0;
		for (int p=l; p<s.length(); p++)
		{
			
			l=p;
			if (j<v[i].size() && v.at(i).at(j)==s.at(p)) 
			{
			j++;	
			}
			else 
			{
			j=0;
			}
			if (j==v[i].size())
	     	{
			string s1,s2,s3;
			s1=s.substr(0,l+1);
			s2=s.substr(l+1,s.length()-l-1);
			int k;
			k=s.length()-s2.length()-v[i].size();
			s3=s.substr(k, v[i].size());
			string s4;
			s4=ObrniRijec(s3);
			s=s1+s4+s2;
			
		    j=0;
		    l=l+1;
			}
			
		}
		
	}
    return s;
}

string NapraviPoluPalindrom (string s, vector<string> v)
{
	int l,j;
	
	for (int i=0; i<v.size(); i++)
	{
		l=0;
		j=0;
		for (int p=l; p<s.length(); p++)
		{
			l=p;
			if (j<v[i].size() && v.at(i).at(j)==s.at(p))
			j++;
			else 
			j=0;
			
			if (j==v[i].size())
			{
				int k,ostatak;
				string s1;
				ostatak=v[i].size()/2;
				k=l-ostatak;
				s1=s.substr(0,k+1);
				string s2;
				s2=s.substr(l+1,s.length()-l-1);
				string s3;
				int var;
				var=l-v[i].size()+1;
				s3=s.substr(var, ostatak);
				string s4;
				s4=ObrniRijec(s3);
				s=s1+s4+s2;
				j=0;
				l++;
			}
			
		}
	}
	return s;
}

int main ()
{
	cout<<"Unesite recenicu: ";
	string s;
	getline (cin,s);

	cout<<"Unesite fraze: ";
	vector <string> vs;
	string s1;
	
	do
	{
		getline (cin, s1);
		if (s1.size()==0)
		break;	
		vs.push_back(s1);
		
	}
	
	while (s1.size()!=0);   
	string s2,s3;
	s2=NapraviPalindrom(s,vs);
	cout<<"Recenica nakon Palindrom transformacije: "<<s2;
	
	s3=NapraviPoluPalindrom(s,vs);
	cout<<endl<<"Recenica nakon PoluPalindrom transformacije: "<<s3;
	
	
	
	
	return 0;
}