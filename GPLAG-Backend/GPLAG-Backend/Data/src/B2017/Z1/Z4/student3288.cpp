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
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
int paran(int x)
{
	if(x%2==0) return 1;
	else return 0;
}
int pozicija(string s, string r, int j)
{
	bool neslovo(true);
	string rijec;
	if(s.length()<r.length()) return 0;
	for(int i=j; i<=s.length()-r.length(); i++) {
		if(!(s[i]>='a'&& s[i]<='z' || s[i]>='A'&& s[i]<='Z')) neslovo=true;
		else if(neslovo) {
			neslovo=false;
			rijec=s.substr(i,r.length());
			if(rijec==r && (i+r.length()==s.length() || !(s[i+r.length()]>='a'&& s[i+r.length()]<='z' || s[i+r.length()]>='A'&& s[i+r.length()]<='Z'))) return i+r.length();
		}
	}
	return 0;
}
string rijecnaopako(string r)
{
	string rij;
	for(int i=r.length()-1; i>=0; i--) {
		rij.push_back(r[i]);
	}
	return rij;
}
string palindrom(string s, string r)
{
	if(!s.length()) return "";
	int poz=pozicija(s,r,0);
	while(poz) {
		string za_ubaciti=rijecnaopako(r);
		s.resize(s.length()+r.length());
		for(int i=s.length()-1; i>=poz+r.length(); i--) {
			s[i]=s[i-r.length()];
		}
		for(int i=poz; i<poz+r.length(); i++) {
			s[i]=za_ubaciti[i-poz];
		}
		poz=pozicija(s,r,poz);
	}
	return s;
}
string NapraviPalindrom(string s, vector<string> v)
{
	for(int i=0; i<v.size(); i++) {
		s=palindrom(s,v.at(i));
	}
	return s;
}
string polupalindrom(string s, string r)
{
	if(paran(r.length())) {
		int poz=pozicija(s,r,0)-r.length()/2;
		while(poz>0) {
			string za_ubaciti=rijecnaopako(r);
			for(int i=poz; i<poz+r.length()/2; i++) {
				s[i]=za_ubaciti[r.length()/2+i-poz];
			}
			poz=pozicija(s,r,poz)-r.length()/2;;
		}
	} else {
		int poz=pozicija(s,r,0)-(r.length()+1)/2;
		while(poz>0) {
			string za_ubaciti=rijecnaopako(r);
			for(int i=poz+1; i<=poz+(r.length()-1)/2; i++) {
				s[i]=za_ubaciti[(r.length()+1)/2+i-poz-1];
			}
			poz=pozicija(s,r,poz)-(r.length()+1)/2;
		}
	}
	return s;
}
string NapraviPoluPalindrom(string s, vector<string> v)
{
	for(int i=0; i<v.size(); i++) {
		s=polupalindrom(s,v.at(i));
	}
	return s;
}
int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	vector<string> v;
	string rijec;
	getline(cin,rijec);
	do {
		v.push_back(rijec);
		getline(cin,rijec);
	} while(rijec.length());
	cout<<"Recenica nakon Palindrom transformacije: ";
	cout<<NapraviPalindrom(recenica,v)<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: ";
	cout<<NapraviPoluPalindrom(recenica,v);
	return 0;
}