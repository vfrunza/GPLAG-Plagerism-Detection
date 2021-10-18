/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

string ObrniFraze(string recenica,vector<string>rijeci)
{
	for(int i=0; i<rijeci.size(); i++) {
		string rijec=rijeci[i];
		int duzina=rijec.length();
		int pocetak=0;

		while(pocetak<recenica.size()-duzina+1) {
			if(recenica.substr(pocetak,duzina)==rijec) {
				int k=pocetak;
				for(int j=rijec.length()-1; j>=0; j--) {
					recenica[k]=rijec[j];
					k++;
				}
			}
			pocetak++;
		}
	}
	return recenica;
}

string Pig(string rijec)
{
	string nova=rijec.substr(1,rijec.size()-1);

	nova+=rijec[0];
	nova+="ay";
	return nova;
}

bool JeLiSlovo(char slovo)
{
	if((slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z') || slovo==' ') return true;
	return false;
}
bool provjeraVektora(string rijec)
{
	for(int i=0; i<rijec.length(); i++)
		if(!JeLiSlovo(rijec[i])) return false;

	return true;
}

string IzmijeniUPigLatin(string recenica,vector<string>rijeci)
{
	int pr=0;
	for(int i=0; i<rijeci.size(); i++)
		if(!provjeraVektora(rijeci[i])) throw domain_error ("Nekorektan izbor rijeci");
	for(int i=0; i<rijeci.size(); i++) {
		string rijec=rijeci[i];
		int duzina = rijec.length();
		int pocetak=0;
        
        
		while(pocetak<recenica.length()-duzina+1) {
			if(recenica.substr(pocetak,duzina)==rijec) {
				string novi="";
				string n=Pig(rijec);
				for(int j=0; j<recenica.length(); j++) {
					if(j==pocetak) {
						for(int k=0; k<n.length(); k++) {
							novi+=n[k];
						}
						j+=duzina-1;
					} else novi+=recenica[j];
				}
				recenica=novi;

			}
			pocetak++;
		}
	}
	string novi="";
	if(rijeci.size()==0) {
		pr=1;
		int i=0;
		while(recenica[i]==' ') {
			novi+=recenica[i];
			i++;
		}

		int poc=i;
		for(; i<recenica.size(); i++) {
			if(recenica[i]==' ') {
				int duzina=i-poc;
				cout<<recenica.substr(poc,duzina)<<endl;
				novi+=recenica.substr(poc,duzina);

				i+=duzina;

				while(recenica[i]==' ') {
					novi+=recenica[i];
					i++;
				}

				poc=i;
			} else novi+=recenica[i];
		}
	}
	if(pr==1) recenica=novi;
	return recenica;
}


int main ()
{
	try {
		int i=0;;
		string recenica;
		cout<<"Unesite recenicu: ";
		getline(cin,recenica);
		vector<string>rijeci;
		cout<<"Unesite fraze: ";
		cin>>ws;
		for(;;) {
			rijeci.resize(i+1);
			getline(cin,rijeci[i]);
			int c=cin.peek();
			if(c=='\n') break;
			i++;
		}
		string a;
		string b;
		a=IzmijeniUPigLatin(recenica,rijeci);
		b=ObrniFraze(recenica,rijeci);
		cout<<"Recenica nakon PigLatin transformacije: ";
		for(int i=0; i<a.size(); i++) {
			cout<<a[i];
		}
		cout<<endl<<"Recenica nakon obrtanja fraza: ";
		for(int i=0; i<b.size(); i++) {
			cout<<b[i];
		}
	} catch(domain_error izuzetak) {
		cout<<izuzetak.what();
	}
	return 0;
}