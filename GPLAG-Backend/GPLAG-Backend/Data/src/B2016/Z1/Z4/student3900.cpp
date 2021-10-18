/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

string ObrniFraze(string s, vector<string>v){
	
	string s1;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			s1=s.substr(j, v[i].size());
			if(s1==v[i]){
				int p;
				for(int l=j, k=j+v[i].size()-1; l<k; l++,k--){
					p=s[l];
					s[l]=s[k];
					s[k]=p;
				}
			}
		}
	}
	return s;
	
}
string IzmijeniUPigLatin(string s, vector<string>v){
	string s1;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			s1=s.substr(j, v[i].size());
			if(s1==v[i]){
				
				s=s.substr(0,j)+s.substr(j+1, v[i].size()-1)+s[j]+"ay"+s.substr(j+v[i].size(), s.length()-(j+v[i].size()));
				
			}
		}
	}
	return s;
	
}

int main ()
{
	
	cout<<"Unesite recenicu: ";
	string s;
	getline(cin, s);
	int n;
	cout<<"Unesite fraze: ";
	string s2;
	vector<string>v;
	char znak;
	int a=3;
	for(;;){
		getline(cin,s2);
		if(s2.size()==0) break; 
		else v.push_back(s2);
	}
	
	//cin.ignore(1000,'\n');
	string s4=ObrniFraze(s,v);

	string s3=IzmijeniUPigLatin(s,v);
	cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0; i<s3.length(); i++){
		cout<<s3[i];
	}
	cout<<endl<<"Recenica nakon obrtanja fraza: ";
	for(int i=0; i<s4.length(); i++){
		cout<<s4[i];
	}
	
	return 0;
}