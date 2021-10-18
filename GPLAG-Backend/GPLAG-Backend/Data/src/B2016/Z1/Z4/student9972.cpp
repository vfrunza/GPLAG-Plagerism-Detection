#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

string  ObrnutaFraza(string s,int a,int b)
{
	string s1=s;
	int n=b-1;
	for(int i=a; i<b;i++){
	char a=s1[i];
	s1[i]=s1[b-1];
	s1[b-1]=a;
	b--;
	}
	b=n;
return s1;
}

int  JeLiIsti(string s, string s1,int a)
{ int i,n=0;
	for(i=a;i<s1.length()+a ;i++){
	if(s[i]!=s1[n] || n>s1.length())return 0;
	else 
	n++;
	}
	return i;
}
int  JeLiIsti2(string s, string s1,int a)
{ int i,n=0;
	for(i=a;(toupper(s[i])>='A' && toupper(s[i])<='Z');i++){
	if(s[i]==s1[n] && n<s1.length())n++;
	else 
	return 0;
	}
	if(s1.size()!=i-a)return 0;
	return i;
}

string   ObrniFraze(string s, vector<string>s1)
{
	int n=0;
	string p,p1=s;;
		for(int i=0;i<s1.size();i++){
		string s2=s1[i];
		for(int j=0;j<p1.size();j++){
		if(p1[j]==s2[0] )
		{ 
			n=JeLiIsti(p1,s2,j);
			if(n!=0)
			p1=ObrnutaFraza(p1,j,n);
			}
		}

	}
	return p1;
}
void ObrnutaRijec(string &s1,int a,int b)
{

	for(int i=a;i<b-1;i++){
	char f=s1[i];
	s1[i]=s1[i+1];
	s1[i+1]=f;
	}
	s1=s1.substr(0,b)+"ay"+s1.substr(b,s1.length());
}
string IzmijeniUPigLatin(string s, vector<string>s1)
{
	int n=0,f=0,g=s1.size();
	string p,p1=s;
	if(g==0)
	{
		for(int i=0;i<p1.size();i++){
		if((toupper(p1[i])>='A' && toupper(p1[i])<='Z')&&(i==0 || toupper(p1[i-1])<'A' || toupper(p1[i-1])>'Z')){f=i;
		while(toupper(p1[i])>='A' && toupper(p1[i])<='Z'){i++;}
		if(toupper(p1[i])<'A' || toupper(p1[i])>'Z')ObrnutaRijec(p1,f,i); 
			}
		}
	}

		for(int i=0;i<s1.size();i++){
		string s2=s1[i];
		for(int j=0;j<p1.size();j++){
		for(int k=0;k<s2.length();k++){
				if(toupper(s2[k])<'A' || toupper(s2[k])>'Z'){throw domain_error("Nekorektan izbor rijeci"); return 0;}}
		if(p1[j]==s2[0] &&(j==0 || toupper(p1[j-1])<'A' || toupper(p1[j-1])>'Z'))
		{


			n=JeLiIsti2(p1,s2,j);
			if(n!=0)
			ObrnutaRijec(p1,j,n);
			}
		}

	}
	return p1;
}

int main ()
{ 
	string s,s2;
	vector<string> s1;
	cout<<"Unesite recenicu: ";
	getline(cin, s);
	cout<<"Unesite fraze: ";
	while(1)
	{
		string c;
		getline(cin,c);
		if(c.size()==0)break;
		s1.push_back(c);
	}
	try
	{
    s2=IzmijeniUPigLatin(s,s1);
	cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0;i<s2.length();i++)
	cout<<s2[i];
	
}
catch(domain_error Izuzetak){
	cout<<"Izuzetak: "<<Izuzetak.what();
}
	cout<<endl<<"Recenica nakon obrtanja fraza: ";
	s2=ObrniFraze(s,s1);
	for(int i=0;i<s2.length();i++)
	cout<<s2[i];

	return 0;
}
