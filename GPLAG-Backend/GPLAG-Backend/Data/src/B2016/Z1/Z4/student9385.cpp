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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

string PrebaciUString(vector<string> recenica)
{
	string s="";
	for(int i=0; i<recenica.size(); i++) {
		s+=recenica[i];
		s+=" ";
	}

	return s;
}

void Transformisi(string &s)
{
	string novi;
	for(int i=0; i<s.size(); i++) {
		if(i!=0) {
			novi+=s[i];
		}
	}
	novi+=s[0];
	novi+="ay";

	s=novi;
}

vector<string> Promijeni(string s)
{
	vector<string> v;

	for(int i=0; i<s.size(); i++) {
		string novi;
		if(i<s.size() && s[i]!=' ') {
			while(i<s.size() && s[i]!=' ') {
				novi+=s[i];
				i++;
				if(i==s.size()) break;
			}

			v.push_back(novi);
		}

	}

	return v;
}

string IzmijeniUPigLatin(string s, vector<string> v)
{
	vector<string> recenica=Promijeni(s);
	string rezultat;
	
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<v[i].size();j++) {
			if(!((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z'))) throw std::domain_error("Nekorektan izbor rijeci");
			break;
		}
	}

	if(v.size()==0) {
		for(int i=0; i<recenica.size(); i++) {
			Transformisi(recenica[i]);
		}
	}

	else {
		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<recenica.size(); j++) {
				if(v[i]==recenica[j]) {
					Transformisi(recenica[j]);
				}
			}
		}
	}

	rezultat=PrebaciUString(recenica);
	return rezultat;
}

string IzvrniString(string &s)
{
	for(int i=0; i<s.size()/2; i++) {
		char temp=s[i];
		s[i]=s[s.size()-1-i];
		s[s.size()-1-i]=temp;
	}

	return s;
}

string ObrniFraze(string s, vector<string> v)
{
	for(int i=0; i<v.size(); i++) { // prolazak kroz redove vektora
		for(int j=0; j<v[i].size(); j++) { //kroz kolone reda vektora
			for(int k=0; k<s.size(); k++) { //prolazak kroz string
				string novi; //resetovanje vrijednosti
				if(j+1<v[i].size() && v[i][j]==s[k] && v[i][j+1]==s[k+1]) {
					int pocetak=k; //pamtimo pocetak
					novi+=s[k];
					while(j+1<v[i].size() && v[i][j]==s[k] && v[i][j+1]==s[k+1]) {
						novi+=s[k+1];
						j++;
						k++;
					}

					int kraj=k; //pamtimo kraj rijeci koju okrecemo
					if(novi==v[i]) {  
						novi=IzvrniString(novi);
					}

					int m=0;
					while(pocetak<=kraj) {
						s[pocetak]=novi[m];
						pocetak++;
						m++;
					}
					j--;
					k--;
				}
			}
		}
	}


	return s;
}


int main ()
{
	string recenica;
	string fraza;
	vector<string> v;

	cout<<"Unesite recenicu: ";
	getline(cin,recenica);


	cout<<"Unesite fraze: ";
	do {
		std::getline(cin,fraza);
		if(fraza=="") break;
		v.push_back(fraza);
	}  while(fraza!=""); 

	try {
		cout<<"Recenica nakon PigLatin transformacije: ";
		string novi1=IzmijeniUPigLatin(recenica,v);
		cout<<novi1;
		cout<<endl;
	} catch(std::domain_error viska) {
		cout<<"Izuzetak: "<<viska.what();
		cout<<endl;
	}

	cout<<"Recenica nakon obrtanja fraza: ";
	string novi=ObrniFraze(recenica,v);
	cout<<novi;



return 0;
}