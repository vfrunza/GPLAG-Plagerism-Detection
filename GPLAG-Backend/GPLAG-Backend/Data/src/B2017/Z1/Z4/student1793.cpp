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
#include<vector>

using namespace std;

bool slovo(char z)
{
	return z>='a'&&z<='z'||z>='A'&&z<='Z';
}

string IzvrniString(string recenica)
{
	int j = recenica.size() - 1;
	for(int i=0; i<j; i++) {
		char temp = recenica[i];
		recenica[i] = recenica[j];
		recenica[j] = temp;
		j--;
	}

	return recenica;
}

string poluIzvrniString(string recenica)
{
	int j = recenica.size() - 1;
	for(int i=0; i<j; i++) {
		recenica[j] = recenica[i];
		j--;
	}

	return recenica;
}


string NapraviPalindrom(string recenica, vector<string>rijeci)
{

	for(int i=0; i<rijeci.size(); i++) {
		string rijec = rijeci[i];
		for (int j = 0; j <= int(recenica.size())-int(rijec.size()); j++) {
			if(recenica.substr(j,rijec.size())==rijec &&
			        (j==0 || !slovo(recenica[j-1]))&&
			        (j==recenica.size()-1 || !slovo(recenica[j+rijec.size()]))
			  ) {
				recenica = recenica.substr(0, j+rijec.size())+IzvrniString(rijec)+recenica.substr(j+rijec.size(), recenica.size()-(j+rijec.size()));
			}
		}


	}

	return recenica;
}

string NapraviPoluPalindrom(string recenica, vector<string>rijeci)
{
	for(int i=0; i<rijeci.size(); i++) {
		string rijec = rijeci[i];

		for (int j = 0; j <= int(recenica.size())-int(rijec.size()); j++) {
			if(recenica.substr(j,rijec.size())==rijec &&
			        (j==0 || !slovo(recenica[j-1]))&&
			        (j==recenica.size()-1 || !slovo(recenica[j+rijec.size()]))
			  ) {
				recenica = recenica.substr(0, j)+poluIzvrniString(rijec)+recenica.substr(j+rijec.size(), recenica.size()-(j+rijec.size()));
			}
		}


	}
	return recenica;
}


int main ()
{
	string recenica;
	vector<string> fraze;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";

	string rijec;
	do {
		getline(cin,rijec);
		if(rijec.size()==0)break;
		fraze.push_back(rijec);
	} while(true);


	cout<<"Recenica nakon Palindrom transformacije: ";
	string palindrom = NapraviPalindrom(recenica,fraze);
	cout<<palindrom<<endl;

	cout<<"Recenica nakon PoluPalindrom transformacije: ";
	string poluPalindrom = NapraviPoluPalindrom(recenica,fraze);
	cout<<poluPalindrom<<endl;

	return 0;
}