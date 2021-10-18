/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using std::cout;
using std::cin;
using std::string;
using std::vector;
string ObrniString(string s)    /*Obrtanje fraze*/
{
	string s1;
	for(int i=0; i<s.length(); i++) {
		s1.push_back(s[s.length()-1-i]);
	}
	return s1;
}
string ObrniFraze(string s,vector<string> a)
{
	int i(0);
	if(s.size()==0)
		return s;
	while(i<a.size()) {
		for(int j=0; j<s.length()-a[i].length()+1; j++) {
			if(s.substr(j,a[i].length())==a[i]) {
				string b(s.substr(j,a[i].length()));
				s.erase(j,a[i].length());
				s.insert(j,ObrniString(b));
			}
		}
		i++;
	}
	return s;
}
string RijecUPigLatin(string s)    /*Pretvaranje rijeci u PigLatin*/
{
	char znak(s[0]);
	s.erase(0,1);
	s.push_back(znak);
	s.push_back('a');
	s.push_back('y');
	return s;
}
string IzmijeniUPigLatin(string s,vector<string> a)
{
	/*Provjeravanje korektnosti fraze*/
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++) {
			if(!((a[i][j]>='a' && a[i][j]<='z') || (a[i][j]>='A' && a[i][j]<='Z')))
				throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	int i(0);
	if(s.size()==0)
		return s;
	if(a.size()==0) {
		for(int j=0; j<s.size(); j++) {
			while(!((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))) {
				if(j!=s.size()-1)
					j++;
				else
					return s;
			}
			if(s[j]!=s.size()) {
				string b;
				int k(j);
				while(((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) && j!=s.size()) {
					b.push_back(s[j]);
					j++;
				}
				s.erase(k,j-k);
				s.insert(k,RijecUPigLatin(b));
				b.clear();
				j+=2;
			}
		}
		return s;
	}

	while(i<a.size()) {
		for(int j=0; j<s.size(); j++) {
			while(!((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))) {
				if(j!=s.size()-1)
					j++;
				else
					goto krajfraze;
			}
			if(s[j]!=s.size()) {
				string b;
				int k(j);
				while(((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) && j!=s.size()) {
					b.push_back(s[j]);
					j++;
				}
				if(b==a[i]) {
					s.erase(k,j-k);
					s.insert(k,RijecUPigLatin(b));
					b.clear();
					j+=2;
				}
			}
		}
krajfraze:
		i++;
	}
	return s;
}
int main ()
{
	string s;
	vector<string> a;
	cout<<"Unesite recenicu: ";
	std::getline(cin,s);
	cout<<"Unesite fraze: ";
	string b;
	while(true) {
		std::getline(cin,b);
		if(b.size()>0)
			a.push_back(b);
		else
			break;
	}
	try {
		cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,a)<<"\n";
	} catch(std::domain_error izuzetak) {
		cout<<"Izuzetak: "<<izuzetak.what()<<"\n";
	}
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,a)<<"\n";
	return 0;
}






