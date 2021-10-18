#include<iostream>
#include<vector>
#include<string>
using namespace std;
string ObrniFraze(string s,vector<string> v){
	for(int i=0;i<v.size();i++){
		int pt,kt;
			
			for(int j=0;j<s.size();j++){
				pt=j;
				kt=j+v[i].size();
				string pom=s.substr(j,v[i].size());
			bool ima=false;
				if(pom==v[i])
				ima=true;
			
			if(ima){
				kt--;
				while(pt<kt){
					char pom=s[pt];
					s[pt]=s[kt];
					s[kt]=pom;
					pt++;
					kt--;
				}
				}
			}
	}
	return s;
	}

string IzmijeniUPigLatin(string s,vector<string> v){
	for(int i=0;i<s.size();i++){
			if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')){
			int pt=i;
			while((i<s.size()) && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) i++;
			int kt=i;
			string pom=s.substr(pt,kt-pt);
			bool ima=false;
			for(int j=0;j<v.size();j++){
				if(pom==v[j])
				ima=true;
			}
			if(ima){
				s=s.substr(0,pt)+s.substr(pt+1,kt-pt-1)+s[pt]+"ay"+s.substr(kt,s.size()-kt);
				i+=2;
			}
		
	}
}
return s;
}
int main ()
{
	
	string recenica;
	vector<string> Fraze;
	string rijec;
	string s;
	string v;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	for(;;) {
	getline(cin,rijec);
	Fraze.push_back(rijec);
	//if(rijec.size()==0)break;
	if(cin.peek()=='\n') break;
	Fraze.push_back(rijec);
	}
	s=IzmijeniUPigLatin(recenica,Fraze);
	cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0;i<s.length();i++){
		cout<<s[i];
	}
	v=ObrniFraze(recenica,Fraze);
	cout<<endl<<"Recenica nakon obrtanja fraza: ";
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	
	return 0;
}