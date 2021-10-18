#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>

using namespace std;

string zarotiraj(string s) {
	for(int i=0;i<s.length()/2;i++) {
		char temp=s[s.length()-1-i];
		s[s.length()-1-i]=s[i];
		s[i]=temp;
	}
	return s;
}

string ObrniFraze(string s, vector<string> v) {
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<s.length();j++) {
			if(s.substr(j, v[i].size())==v[i]) 
				{
					string s1;
					s1+=s.substr(0, j);
					s1+=zarotiraj(v[i]);
					s1+=s.substr(j+v[i].size(),s.length()-j);
					s=s1;
				}
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s, vector<string> v) {
	for(int i=0;i<v.size();i++)
		for(int j=0;j<v[i].size();j++)
			if(toupper(v[i][j])<'A' || toupper(v[i][j])>'Z')
				throw domain_error("Nekorektan izbor riječi");
	bool udje=false;
	for(int i=0;i<v.size();i++){ 
		udje=true;
		for(int j=0;j<s.length();j++) 
			if(s.substr(j, v[i].size())==v[i] && (j==0 || s[j-1]==' ') && (j+v[i].size()==s.length() || s[j+v[i].size()]==' '))
					s=s.substr(0, j)+v[i].substr(1, v[i].size()-1)+v[i][0]+"ay"+s.substr(j+v[i].size(),s.length()-j);
	}
	if(!udje)
	{
		string s1;
		for(int i=0; i<s.size(); i++)
		{
			if(toupper(s[i])>='A' && toupper(s[i])<='Z')
			{
				string pom;
				while(toupper(s[i])>='A' && toupper(s[i])<='Z')
				{
					pom+=s[i];
					i++;
				}
				s1+=(pom.substr(1,pom.size()-1)+pom[0]+"ay");
				i--;
			} else s1+=s[i];
		}
		return s1;
	}
	return s;	
}

int main ()
{
		string s;
		cout<<"Unesite recenicu: ";
		getline(cin,s);
		vector<string> v;
		cout<<"Unesite fraze: ";
		while(1)
		{
			string s1;
			getline(cin,s1);
			if(s1.size()==0) break;
			else v.push_back(s1);
		}
		try
		{
			cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v)<<endl;
		}catch(domain_error e) {
		cout<<"Izuzetak: "<<e.what();
	    }
		string s2=ObrniFraze(s,v);
		cout<<"Recenica nakon obrtanja fraza: "<<s2;
	return 0;
}