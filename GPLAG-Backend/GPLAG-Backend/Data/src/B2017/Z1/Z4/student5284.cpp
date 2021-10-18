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
#include<string>
#include <vector> 

using namespace std;

string Obrni(string s)
{
	string pom;
	for(int i=s.size()-1;i>=0;i--)
		pom.push_back(s.at(i));
		
	return pom;
}

bool JelSlovo(string s)
{
	return (s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z');	
}

string NapraviPalindrom(string s,vector<string>v)
{
	    
		for(int i=0;i<v.size();i++)
		{
			
				for(int j=0;j<s.size();j++)
				{   
					
					if(v.at(i)==s.substr(j,v.at(i).size()) && (!JelSlovo(s.substr(j+v.at(i).size(),1))))
					{
						s=s.substr(0,j)+s.substr(j,v.at(i).size())+Obrni(v.at(i))+s.substr(j+v.at(i).size(),s.size());
					}
					
				}
			
		}
		
		return s;
}


string NapraviPoluPalindrom(string s,vector<string>v)
{
	
		for(int i=0;i<v.size();i++)
		{
			
				for(int j=0;j<s.size();j++)
				{   
					
					if(v.at(i)==s.substr(j,v.at(i).size())&& (!JelSlovo(s.substr(j+v.at(i).size(),1))))
					{
						s=s.substr(0,j)+s.substr(j,(v.at(i).size()+1)/2)+Obrni(s.substr(j,v.at(i).size()/2))+s.substr(j+v.at(i).size(),s.size());
					}
					
				}
			
		}
		
		return s;
}

int main ()
{ 
   cout <<"Unesite recenicu: ";
   string a,b;
   string s;
   vector<string>s1;
   getline(cin, s);
   
   
   cout<<"Unesite fraze: ";
	for(int i=0; i<10000; i++) {
		string s;
		getline(cin,s);
		if(s.size()==0) 
			break;
		else s1.push_back(s);
	}
	
	
	cout<<"Recenica nakon Palindrom transformacije: ";
	a=NapraviPalindrom(s,s1);
	cout<<a<<endl;
	
	cout<<"Recenica nakon PoluPalindrom transformacije: ";
	b=NapraviPoluPalindrom(s,s1);
	cout<<b;
/*
	string s="Danas je lijep i suncan dan";
	vector<string> v={ "danas", "lijep", "suncan" ,"meso od sira"};
	
	s=NapraviPalindrom(s,v);
 	cout<<s<<endl;
 	s=NapraviPoluPalindrom(s,v);
 	cout<<s;

	*/
	return 0;
}