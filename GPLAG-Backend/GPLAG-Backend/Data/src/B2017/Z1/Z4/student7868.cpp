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
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>
using namespace std;



bool nijeslovo(string s){
	return !(toupper(s.at(0))>='A' && toupper(s.at(0))<='Z');	
}

string NapraviPalindrom(string s, vector<string> v) {
	for(int i=0; i<v.size(); i++) {
		string s1;
		for(int k=v.at(i).length()-1; k>=0; k--) s1.push_back(v.at(i).at(k));
		for(int j=0; j<s.length(); j++) {
			//string sl=s.substr(j+v.at(i).size(),1);
			if(v.at(i)==s.substr(j,v.at(i).size()) && (j>=s.size()-v.at(i).size()||( nijeslovo(s.substr(j+v.at(i).size(),1)))))
					{
						//cout<<s.substr(j+v.at(i).size(),1)<<endl;
						s=s.substr(0,j)+v.at(i)+s1+s.substr(j+v.at(i).size(),s.size());
						//cout<<s<<endl;
					}
		}
	}
	return s;
}

string NapraviPoluPalindrom(string s, vector<string> v) {
	for(int i=0; i<v.size(); i++) {
		string s1;
		for(int k=(v.at(i).length()/2)-1; k>=0; k--) s1.push_back(v.at(i).at(k));
		for(int j=0; j<s.length(); j++) {
			if(v.at(i)==s.substr(j,v.at(i).size()) && (j>=s.size()-v.at(i).size()||(j!=s.size()-v.at(i).size() && nijeslovo(s.substr(j+v.at(i).size(),1))))){
				if(v.at(i).length()%2==0) s=s.substr(0,j)+ v.at(i).substr(0,v.at(i).length()/2)+ s1+s.substr(j+v.at(i).length(),s.length()-j-v.at(i).size());
				else s=s.substr(0,j)+ v.at(i).substr(0,1+v.at(i).length()/2)+ s1+s.substr(j+v.at(i).length(),s.length()-j-v.at(i).size());
				
			}
		}
	}
	return s;
}

int main ()
{
	string s;
	vector<string> v;
	cout<<"Unesite recenicu: ";
	getline(cin,s);
	cout<<"Unesite fraze: ";
	for(;;) {
		string temp;
		getline(cin,temp);
		if(temp.length()!=0) v.push_back(temp);
		else break;
	}
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,v)<<endl<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);
	
	return 0;
}