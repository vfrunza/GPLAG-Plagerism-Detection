/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;

string ObrniFraze(string s,vector<string> v){
	for(int i=0;i<v.size();i++){
		string s1=v.at(i);
		for(int j=0;j<s.length();j++){
			int k(0);
			while(j<s.length() && k<s1.length() && s1.at(k)==s.at(j)){
				j++;
				k++;
			}
			if(k==s1.length()){
				for(int l=s1.length()-1;l>=0;l--){
					s.at(j-l-1)=s1.at(l);
				}
				j--;
			}
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s,vector<string> v1){
	vector<string> v=std::move(v1);
	for(int i=0;i<v.size();i++){
		string s1=v.at(i);
		for(int j=0;j<s1.length();j++){
			if((s1.at(j)<'A' || s1.at(j)>'Z') && (s1.at(j)<'a' || s1.at(j)>'z')){
				throw domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	if(v.size()==0){
		for(int i=0;i<s.length();i++){
			string s2;
			while(i<s.length() && ((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z'))){
				s2.push_back(s[i]);
				i++;
			}
			v.push_back(s2);
			s2.resize(0);
		}
	}
	for(int i=0;i<v.size();i++){
		string s1=v[i];
		for(int j=0;j<s.length();j++){
			int k(0);
			int pocetak(j);
			while(j<s.length() && ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))){
				j++;
				k++;
			}
			if(k==s1.length() && s1.length()>0){
				bool slovo=true;
				for(int l=k-1;l>=0;l--){
					if(s1.at(l)!=s.at(pocetak+l)){
						slovo=false;
						break;
					}
				}
				if(slovo){
					s.at(j-1)=s1.at(0);
					for(int k=1;k<s1.length();k++){
						s.at(j-k-1)=s1.at(s1.length()-k);
					}
					s.resize(s.length()+2);
					for(int k=s.length()-1;k>j;k--){
						s.at(k)=s.at(k-2);
					}
					s.at(j)='a';
					s.at(j+1)='y';
				}
			}
		}
	}
	return s;
}
int main ()
{
	string s;
	cout<<"Unesite recenicu: ";
	std::getline(cin,s);
	vector<string> v;
	string s1;
	cout<<"Unesite fraze: ";
	do{
		std::getline(cin,s1);
		if(s1.length()==0){
			break;
		}
		v.push_back(s1);
	}
	while(s1.length()!=0);
	try{
		string s3(IzmijeniUPigLatin(s,v));
		cout<<"Recenica nakon PigLatin transformacije: "<<s3<<endl;
	}
	catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	string s2(ObrniFraze(s,v));
	cout<<"Recenica nakon obrtanja fraza: "<<s2;
	return 0;
}