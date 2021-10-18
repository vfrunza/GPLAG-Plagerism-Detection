#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<cstring>
using namespace std;

string ObrniFraze(string s, vector<string> v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<s.size(); j++)
		{
			if(s.substr(j,v[i].size())==v[i])
			{
				int poc=j, kr=j+v[i].size();
				string pom;
			    int ind=0;
			    while(poc!=kr)
			    {
			    	pom.resize(pom.size()+1);
			    	pom[ind]=s[poc];
			    	ind++;
			    	poc++;
			    }
			    ind=pom.size()-1;
			    for(int k=0; k<pom.size()/2; k++)
			    {
			    	char temp=pom[k];
			    	pom[k]=pom[ind];
			    	pom[ind]=temp;
			    	ind--;
			    }
			    s=s.substr(0,j)+pom+s.substr(j+v[i].size(), s.size()-j);
			}
		}
	}
	return s;
}

bool pocetak(int n)
{
	return n==0;
}

bool dobarispred(string s, int j)
{
	return (toupper(s[j])<'A' || toupper(s[j])>'Z');
}

bool kraj(int n, string s1, string s2)
{
	return n+s1.size()==s2.size();
}

bool dobariza(string s, int n)
{
	if(toupper(s[n])<'A' || toupper(s[n])>'Z') return true;
	return false;
}

string IzmijeniUPigLatin(string s, vector<string> niz)
{
	for(int i=0; i<niz.size(); i++)
	{
		for(int j=0; j<niz[i].size(); j++)
		{
			if(toupper(niz[i][j])<'A' || toupper(niz[i][j])>'Z') throw domain_error("Nekorektan izbor rijeci");
		}
	}
	string rez;
	bool jes=false;
	if(niz.size()==0) jes=true;
	if(!jes){
	for(int i=0; i<niz.size(); i++)
	{
		jes=true;
		for(int j=0; j<s.size(); j++)
		{
			if(s.substr(j,niz[i].size())==niz[i] && (pocetak(j)||dobarispred(s,j-1)) && (kraj(j,niz[i],s)||dobariza(s,j+niz[i].size())))
			{
				int poc=j, kr=j+niz[i].size(), blj=j;
				poc++;
				string pom;
				while(poc!=kr)
				{
					pom.push_back(s[poc]);
					poc++;
				}
				s=s.substr(0,j)+pom+s[blj]+"ay"+s.substr(j+niz[i].size(), s.size()-j);
				rez=s;
			}
		}
	}
	}
	else
	{
		for(int i=0; i<s.size(); i++)
		{
			if(toupper(s[i])<'A' || toupper(s[i])>'Z') rez+=s[i];
			if(toupper(s[i])>='A' && toupper(s[i])<='Z')
			{
				string mla;
				while(toupper(s[i])>='A' && toupper(s[i])<='Z') {mla+=s[i]; i++;}
			    if(mla.size()>1) rez+=mla.substr(1,mla.size()-1);
				rez+=mla[0];
				rez+="ay";
				i--;
			}
		}
	}
	return rez;
}

int main ()
{
	string s;
	cout<<"Unesite recenicu: ";
	getline(cin,s);
	vector<string> niz;
	int ind=0;
	cout<<"Unesite fraze: ";
	while(112358==112358)
	{
		string zblj;
		getline(cin,zblj);
		if(zblj.size()!=0)
		{
			niz.resize(niz.size()+1);
			niz[ind]=zblj;
			ind++;
		} else break;
	}
	try{
	cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,niz);
	} catch(domain_error izuz) { cout<<"Izuzetak: "<<izuz.what();}
	cout<<endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,niz);
	return 0;
}