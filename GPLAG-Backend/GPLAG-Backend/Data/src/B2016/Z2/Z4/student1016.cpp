/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci (char**&a, std::vector<std::string> imena)
{
	try {
		a=new char*[imena.size()];
		for(int i = 0; i < imena.size(); i++) a[i] = nullptr;
		try {
			for(int i = 0; i < imena.size(); i++) {
				a[i] = new char[imena[i].size()+1];
			}
		} catch(...) {
			for(int i = 0; i < imena.size(); i++) delete[] a[i];
			delete[] a;
			throw;
		}
	} catch(...) {
		throw;
	}
	for(int i=0; i<imena.size(); i++) {
		for(int j=0; j<imena[i].size(); j++) {
			a[i][j]=imena[i][j];
		}
		a[i][imena[i].size()]='\0';
	}
	return int(imena.size());
}

int OdbaciOptuzbu (char**& a, int broj_pok, std::string s)
{
	int i;
	for( i=0; i<broj_pok; i++) {
		char* p(a[i]);
		while(*p!='\0') p++;
		int j;
		for(j=0; j<s.length(); j++) {
			if(j>p-a[i]) break;
			if(a[i][j]!=s[j]) break;
		}
		if(j==s.length()) {
			delete[] a[i];
			a[i]=nullptr;
			break;
		}
	}
	if(i==broj_pok) throw std::domain_error ("Osoba sa imenom "+s+" nije bila optuzena");
	int brojac_za_null(0);
	for(int i=0; i<broj_pok; i++) {
		if(a[i]==nullptr) brojac_za_null++;
	}
	if(brojac_za_null<=10) return broj_pok;
	char** b;
	try {
		b=new char*[broj_pok-brojac_za_null];
		for(int i = 0; i < broj_pok-brojac_za_null; i++) b[i] = nullptr;
		try {
			int x(0), y(0);
			while(x<broj_pok) {
				if(a[x]==nullptr) {
					x++;
					continue;
				}
				char*p=a[x];
				while(*p!='\0') {
					p++;
				}
				p++; //da bi se prekopirao i \0
				b[y]= new char[p-a[x]];
				b[y]=a[x];
				y++;
				x++;
			}
			for(int i=0; i<broj_pok; i++) delete[] a[i];
			delete[] a;
			a=b;

		} catch(...) {
			for(int i = 0; i <broj_pok-brojac_za_null; i++) delete[] b[i];
			delete[] b;
			throw;
		}
	} catch(...) {
		//ne treba nista da se desi
	}
	return broj_pok-brojac_za_null;
}

int DodajOptuzbu (char**& a, int broj_pok, std::string s)
{
	char* p;
	try {
		p=new char[s.length()+1];
		for(int i=0; i<s.length(); i++) {
			p[i]=s[i];
		}
		p[s.length()]='\0';
	} catch(...) {
		throw;
	}
	int i;
	for(i=0; i<broj_pok; i++) {
		if(a[i]==nullptr) break;
	}
	if(i!=broj_pok) {
		a[i]=p;
		return broj_pok;
	} else {
		char** b;
		try {
			b=new char*[broj_pok+1];
			for(int j=0; j<broj_pok+1; j++) b[j]=nullptr;
			try {
				char* q;
				for(int i=0; i<broj_pok; i++) {
					q=a[i];
					while(*q!='\0') q++;
					q++; // za \0
					b[i]=new char[q-a[i]];
					for(int j=0; j<q-a[i]; j++) {
						b[i][j]=a[i][j];
					}
				}
				b[broj_pok]=p;
				char**c(a);
				a=b;
				for(int i=0; i<broj_pok; i++) delete[] c[i];
				delete[] c;
			} catch(...) {
				for(int i = 0; i <broj_pok+1; i++) delete[] b[i];
				delete[] b;
				throw;
			}
		} catch(...) {
			throw;
		}
	}
	return broj_pok+1;
}

void IzlistajOptuzbu(char** a, int broj_pok)
{
	for(int i=0; i<broj_pok; i++) {
		if(a[i]==nullptr) continue;
		std::cout << a[i]<<std::endl;
	}
}

using std::cin;
using std::cout;

int main ()
{
	cout << "Koliko potencijalnih krivaca zelite unijeti?"<< std::endl;
	int n;
	cin >> n;
	cin.ignore(10000, '\n');
	cout << "Unesite potencijalne krivce: "<< std::endl;
	std::vector<std::string> imena;
	std::string s;
	for(int i=0; i<n; i++) {
		std::getline(std::cin, s);
		imena.push_back(s);
	}
	char** a;
	try {
		n=PotencijalniKrivci(a, imena);
	} catch(...) {
		return 0;
	}
	for(;;) {
		int x;
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<< std::endl;
		cin >> x;
		cin.ignore(10000, '\n');
		if(x==0) break;
		else if(x==1) {
			cout << "Unesite ime novog optuzenog: "<< std::endl;
			std::getline(std::cin, s);
			n=DodajOptuzbu(a, n, s);
		} else if(x==2) {
			cout << "Unesite ime koje zelite izbaciti: "<< std::endl;
			std::getline(std::cin,s);
			n=OdbaciOptuzbu(a, n, s);
		} else if(x==3) {
			IzlistajOptuzbu(a, n);
		}
	}

	for(int i=0; i<n; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}