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
#include <algorithm>
using namespace std;

string Sastavi(vector<string>rijeci)
{
	string recenica;
	for(int i=0; i<rijeci.size(); i++)
		recenica+=rijeci.at(i);
	recenica.erase(recenica.begin()+recenica.length()-1);
	return recenica;
}

string ObrniRijec(string a)
{
	char tmp;
	for(int i=0; i<a.size()/2; i++) {
		tmp=a.at(i);
		a.at(i)=a.at(a.length()-i-1);
		a.at(a.length()-i-1)=tmp;
	}
	return a;
}

string NapraviPalindrom(string s,vector<string>fraze)
{
	string s1;
	vector<string>obrni;
	for(int i=0; i<fraze.size(); i++) {
		s1=ObrniRijec(fraze.at(i));
		obrni.push_back(s1);
	}
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if((s.substr(j,fraze.at(i).length())==fraze.at(i)) && ((j+fraze.at(i).length()==s.length())
			        || (s.at(j+fraze.at(i).length())==' ')
			        || (s.at(j+fraze.at(i).length())=='.') || (s.at(j+fraze.at(i).length())==','))
			        && (j==0 || s.at(j-1)==' ' || s.at(j-1)=='.' || s.at(j-1)==',')) {
				s.insert(j+fraze.at(i).length(),obrni.at(i));
			}
		}
	}
	return s;
}

string NapraviPoluPalindrom(string s,vector<string>fraze)
{
	string s2;
	vector<string>obrni2;
	for(int i=0; i<fraze.size(); i++) {
		s2=ObrniRijec(fraze.at(i));
		obrni2.push_back(s2);
	}
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(s.substr(j,fraze.at(i).length())==fraze.at(i)
			        && ((j+fraze.at(i).length()==s.length())
			            || (s.at(j+fraze.at(i).length())==' ')
			            || (s.at(j+fraze.at(i).length())=='.') || (s.at(j+fraze.at(i).length())==','))
			        && (j==0 || s.at(j-1)==' ' || s.at(j-1)=='.' || s.at(j-1)==',')) {
				string druga_pol=obrni2.at(i).substr(obrni2.at(i).length()/2,obrni2.at(i).length()/2+1);
				s.insert(j+(fraze.at(i).length()/2),druga_pol);
				if(fraze.at(i).length()%2!=0) {
					s.erase(j+fraze.at(i).length(),fraze.at(i).length()/2+1);
				} else {
					s.erase(j+fraze.at(i).length(),fraze.at(i).length()/2);
				}
			}
		}
	}
	return s;
}


int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	vector<string>v;
	cout<<"Unesite fraze: ";
	while(true) {
		string fraze;
		getline(cin,fraze);
		if(fraze=="") break;
		v.push_back(fraze);
	}

	string s=NapraviPalindrom(recenica,v);
	cout<<"Recenica nakon Palindrom transformacije: ";
	for(int i=0; i<s.length(); i++) {
		cout<<s.at(i);
	}
	cout<<endl;
	string s2=NapraviPoluPalindrom(recenica,v);
	cout<<"Recenica nakon PoluPalindrom transformacije: ";
	for(int i=0; i<s2.length(); i++) {
		cout<<s2.at(i);
	}
	return 0;
}