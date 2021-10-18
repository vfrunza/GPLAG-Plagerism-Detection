
#include <iostream>
#include<string>
#include<vector> 
using namespace std;


string ObrniString(string s){
	string l;
	for(int i=s.size()-1;i>=0;i--){
	
		l.push_back(s.at(i));
	}
	return l;
}
//s.substr(j+v.at(i).size(),1)

string NapraviPalindrom(string s,vector<string>V ){
	
	for(int i=0;i<V.size();i++){
		for(int j=0;j<s.size();j++){
			if(V.at(i)==s.substr(j,V.at(i).size()))
				if(j>=s.size()-V.at(i).size()||( !(toupper(s.substr(j+V.at(i).size(),1).at(0))>='A' && toupper(s.substr(j+V.at(i).size(),1).at(0))<='Z') ))
			 		{s=s.substr(0,j+V.at(i).size())+ObrniString(V.at(i)) + s.substr(j+V.at(i).size(),s.size()-j-V.at(i).size()); }
		}
		
	}
	return s;
}

string NapraviPoluPalindrom(string s,vector<string>V ){
	
	for(int i=0;i<V.size();i++){
		for(int j=0;j<s.size();j++){
			int pom=V.at(i).size();
			if(pom%2==0 && V.at(i)==s.substr(j,V.at(i).size()) && (j>=s.size()-V.at(i).size()||( !(toupper(s.substr(j+V.at(i).size(),1).at(0))>='A' && toupper(s.substr(j+V.at(i).size(),1).at(0))<='Z') )))
				{s=s.substr(0,(j+pom/2))+ ObrniString(V.at(i).substr(0,pom/2))+ s.substr(j+V.at(i).size(),s.size()-j-pom);	}
			else if(pom%2!=0 && V.at(i)==s.substr(j,V.at(i).size()) && (j>=s.size()-V.at(i).size()||( !(toupper(s.substr(j+V.at(i).size(),1).at(0))>='A' && toupper(s.substr(j+V.at(i).size(),1).at(0))<='Z') )))
				s=s.substr(0,(j+pom/2+1))+ ObrniString(V.at(i).substr(0,pom/2))+ s.substr(j+V.at(i).size(),s.size()-j-pom);
		}
		
	}
	return s;
}


int main ()
{
cout<<"Unesite recenicu: ";	
string s; getline(cin,s);
vector<string> v;
cout<<"Unesite fraze: ";
while(1){
	string pom;
	getline(cin,pom);
	if(pom.size()==0) break;
	v.push_back(pom);
}


cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,v)<<endl;
cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);


	return 0;
}