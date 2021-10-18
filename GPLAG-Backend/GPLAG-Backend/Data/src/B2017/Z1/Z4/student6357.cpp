#include <iostream>
#include <vector>
#include <string>
using namespace std;
string NapraviPalindrom(string s, vector<string> v)
{
	for(int i=0; i<v.size(); i++) {
		string rijec(v.at(i));
		for(int j=0; j<s.length(); j++) {
			if(rijec.size()==0) break;
			if(s.at(j)==rijec.at(0)) {
				int brojac(0),kraj(j);
				bool razliciti=false;
				while(kraj!=s.length() && brojac!=rijec.length()) {
					if(s.at(kraj)!=rijec.at(brojac)) {
						razliciti=true;
						break;
					}
					kraj++;
					brojac++;
				}
				if(brojac==rijec.size() && razliciti==false && ((kraj!=s.size() && !((s.at(kraj)>='a' && s.at(kraj)<='z') || (s.at(kraj)>='A' && s.at(kraj)<='Z'))) || kraj==s.size())) {
					string RijecNaopako;
					RijecNaopako.resize(0);
					for(int l=rijec.length()-1; l>=0; l--)
						RijecNaopako.push_back(rijec.at(l));
					s=s.substr(0,kraj)+RijecNaopako+s.substr(kraj,s.length());
					j=kraj+RijecNaopako.length();
				}
			}
		}
	}
	return s;
}
string NapraviPoluPalindrom(string s, vector<string>v)
{

	for(int i=0; i<v.size(); i++) {
		string rijec(v.at(i));
		for(int j=0; j<s.length(); j++) {
			if(rijec.size()==0) break;
			if(s.at(j)==rijec.at(0)) {
				int brojac(0),pocetak(j),kraj(j);
				bool razliciti(false);
				while(kraj!=s.length() && brojac!=rijec.length()) {
					if(s.at(kraj)!=rijec.at(brojac)) {
						razliciti=true;
						break;
					}
					kraj++;
					brojac++;
				}
				if(brojac==rijec.length() && razliciti==false && ((kraj!=s.size() && !((s.at(kraj)>='a' && s.at(kraj)<='z') || (s.at(kraj)>='A' && s.at(kraj)<='Z'))) || kraj==s.size())) {
					string RijecNaopako;
					RijecNaopako.resize(0);
					for(int l=rijec.length()/2-1; l>=0; l--)
						RijecNaopako.push_back(rijec.at(l));
					if(rijec.size()%2!=0)
						s=s.substr(0,pocetak+rijec.length()/2+1)+RijecNaopako+s.substr(pocetak+rijec.length(),s.length());
					else s=s.substr(0,pocetak+rijec.length()/2)+RijecNaopako+s.substr(pocetak+rijec.length(),s.length());
					j=pocetak+RijecNaopako.length();
				}
			}
		}
	}
	return s;
}
int main ()
{
	cout<<"Unesite recenicu: ";
	string s;
	getline(cin,s);
	cout<<"Unesite fraze: ";
	string rijeci;
	vector<string> v;
	for(;;) {
		getline(cin,rijeci);
		v.push_back(rijeci);
		if(char(cin.peek())=='\n')
			break;
	}
	cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,v);
	cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);
	return 0;
}