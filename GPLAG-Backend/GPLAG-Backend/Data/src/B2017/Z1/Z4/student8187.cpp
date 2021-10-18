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
#include <vector>
#include <string>

using namespace std;

string NapraviPalindrom(string recenica, vector<string> fraze)
{
	string pomocni,s1;
	int j(0),brojac(0);
	for(int i=0; i<fraze.size(); i++) {
		j=0;
		brojac=0;
		while(j<recenica.size()) {
			for(int k=0; k<fraze.at(i).size(); k++) {
				s1+=recenica.at(j);
				if(recenica.at(j)==fraze.at(i).at(k)) {

					j++;
					brojac++;
					if(brojac==fraze.at(i).size()) {

						for(int l=fraze.at(i).size()-1; l>=0; l--) {
							s1+=fraze.at(i).at(l);
						}
					}
				}
			}

		}

	}


	return recenica;
}



int main ()
{
	string s;
	string s1,rez;
	vector<string> fraze;
	cout<<"Unesite recenicu: ";
	cin>>s;
	cout<<"Unesite fraze: ";
	int brojac(0);
	do {
		brojac=0;
		getline(cin,s1);
		if(s1.length()==0  )brojac++;
		if(brojac==1) break;
		else
			fraze.push_back(s1);
		s1=string("");
	} while(1);

	rez=NapraviPalindrom(s,fraze);
	cout<<"Recenica nakon Palindrom transformacije: "<<rez;
	return 0;
}