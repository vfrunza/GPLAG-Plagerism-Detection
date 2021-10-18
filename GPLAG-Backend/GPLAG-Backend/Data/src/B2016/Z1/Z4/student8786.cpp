#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<cctype>
using namespace std;

string okreni(string s)
{
	string pom;
	for(int i=s.size()-1; i>=0; i--) pom+=s[i];
	return pom;
}

string ObrniFraze(string s, vector<string> v)
{
	int a=0;
	while(a!=v.size())
	{
		for(int i=0; i<s.size(); i++)
		{
			if(s.substr(i, v[a].size())==v[a])
			{
			   s=s.substr(0,i)+okreni(v[a])+s.substr(i+v[a].size(),s.size()-i);
			   
			} 
		}
		a++;
	}
	return s;
}

bool dalijeslovo(char sl)
{
	if(toupper(sl)>='A' && toupper(sl)<='Z') return true;
	return false;
}

string pig(string s)
{
	string pom;
	int k=1;
	while(k!=s.size())
	{
		pom+=s[k];
		k++;
	}
	pom+=s[0];
	pom+="ay";
	return pom;
}

string IzmijeniUPigLatin(string s, vector<string>v)
{
   
   for(int i=0; i<v.size();i++)
   {
   	for(int j=0; j<v[i].size();j++)
   	if(toupper(v[i][j])<'A' || toupper(v[i][j])>'Z') throw domain_error("Nekorektan izbor rijeci");
   }
   if(v.size()==0)
   {
   	string p;
   	for(int i=0; i<s.size(); i++)
   	{
   		if(!dalijeslovo(s[i]))
   		{
   			string l;
   			while(i!=s.size() && !dalijeslovo(s[i])) {l+=s[i]; i++;}
   			p+=l;
   		}
   		string z;
   		if(dalijeslovo(s[i]))
   		{
   			while(dalijeslovo(s[i])) { z+=s[i]; i++;}
   			z=pig(z);
   			p+=z;
   			i--;
   		}
   	}
   	return p;
   }
   int ind=0;
   while(ind != v.size())
   {
   	for(int i=0; i<s.size(); i++)
   	{
   		if(s.substr(i,v[ind].size())==v[ind] && (i==0 || s[i-1]==' '))
   		{
   			if(i==0 || s[i-1]==' ')
   			{
   				if(i+v[ind].size()==s.size() || !dalijeslovo(s[i+v[ind].size()]))
   				{
   					s=s.substr(0,i)+v[ind].substr(1,v[ind].size()-1)+s[i]+"ay"+s.substr(i+v[ind].size(),s.size()-i);
   				}
   			}
   		}
   	}
   	ind++;
   }
  return s;
}

int main ()
{
		cout<<"Unesite recenicu: ";
		string s; getline(cin,s);
		vector<string>v;
		cout<<"Unesite fraze: ";
		for(;;) 
		{
			string pom;
			getline(cin, pom);
			if(pom.size()==0) break;
			else v.push_back(pom);
		}
		try{
		//string nest = IzmijeniUPigLatin(s,v);
		cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v);
		}catch(domain_error izuzetak) { cout<<"Izuzetak: "<<izuzetak.what(); }
		cout<<endl;
		cout<<"Recenica nakon obrtanja fraza: ";
		cout<<ObrniFraze(s,v);
	return 0;
}