/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int PotencijalniKrivci(char **&niz, std::vector<string> imena) {
	int n = 0;
	char *tmpstringova;
	char **tmpnizova;
	try {
		tmpnizova = new char*[imena.size()];
		try {
			for (int i = 0; i < imena.size(); i++) {
				try{
					tmpstringova = new char[imena.at(i).size()+1];
				
				for(int j=0; j<=imena.at(i).size(); j++) {
					if(j==imena.at(i).size()) {
						tmpstringova[j]='\0';
						break;
					}
				tmpstringova[j]=imena.at(i).at(j);
				tmpnizova[i]= tmpstringova;
				}
				n++;
				tmpstringova=nullptr;
				}catch(...){
					delete[] tmpstringova;
					throw ;
				}
			}
		} catch(...) {
			for (int i = 0; i < n; i++) {
				delete[] tmpnizova[i];
				delete[] tmpnizova;
				throw;
			}
		}
	} catch(...) {
		cout<<"alokacija niza pokazivaca nije uspjela";
	}
	niz = tmpnizova;

	return n;
}
int OdbaciOptuzbu(char **&niz, int size, string ime) {
	unsigned int broj_nullptr = 0;
	for (int i = 0; i < size; i++) {
		bool jest = true;
		for(int j=0; j<ime.size() && niz[i][j]!='\0'; j++) {
			if((niz[i][j]=='\0' && j<ime.size()-1) || (ime[j]!=niz[i][j])) {
				jest = false;
				break;
			}
			if(niz[i][j]!='\0' && j==ime.size()-1) {
				if(niz[i][j+1]!='\0')jest = false;
			}
		}
		if(jest) {
			delete[] niz[i];
			niz[i]=nullptr;
		}
		if(niz[i]==nullptr)broj_nullptr++;
	}
	if(broj_nullptr>=10) {
		try {
			int c=0;
			char **tmp = new char*[size-broj_nullptr+1];
			for (int i = 0; i < size; i++) {
				if(niz[i]!=nullptr)tmp[c++]=niz[i];
			}
			niz=tmp;
			size-=broj_nullptr;

		} catch(...) {
			//nope
		}
	}
	if(!broj_nullptr)throw std::domain_error("Osoba sa imenom "+ ime+ " nije bila optuzena");
	return size;
}
int DodajOptuzbu(char **&niz,int size, string ime) {
	bool nije_dodata = true;
	for (int i = 0; i < size; i++) {
		if(niz[i]==nullptr) {
			nije_dodata = false;
			try {
				char *tmp = new char[ime.size()+1];
				for(int j=0; j<ime.size(); j++) {
					tmp[j]=ime[j];
				}
				tmp[ime.size()]='\0';
				niz[i]=tmp;
			} catch(...) {
				return size;
			}
			break;
		}
	}
	if(nije_dodata) {
		char **tmp2 ;
		try {
			tmp2 = new char*[size+1];
		} catch (...) {
			delete[] tmp2;
			throw std::bad_alloc();
			return size;
		}
		
		for (int i = 0; i < size; i++) {
			tmp2[i]=niz[i];
			niz[i]=nullptr;
		}
		delete[] niz;
		bool good = false;
			try {
				tmp2[size] = new char[ime.size()+1];
				good=true;
			} catch(...) {
				delete[] tmp2[size];
				throw;
			}
		if(good){
			for(int j=0; j<ime.size(); j++) {
					tmp2[size][j]=ime[j];
				}
				tmp2[size][ime.size()]='\0';
				niz = tmp2;
				size++;
		}

	}
	return size;
}
void IzlistajOptuzbu(char **niz,int n) {
	if(n<0)return;
	for (int i = 0; i < n; i++) {
		if(niz[i]!=nullptr)
		cout<<niz[i]<<endl;
	}
}
int main () {
	char **nizPotencijalnih;
	std::vector<string> optuzeni;
	int n;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	cin>>n;
	if(n<0) {
		cout<<"Pogresan unos!";
		return 0;
	}
	cout<<"Unesite potencijalne krivce: \n";
	for (int i = 0; i < n; i++) {
		string a;
		if(cin.peek()=='\n')cin.ignore(1);
		std::getline(cin,a,'\n');
		optuzeni.push_back(a);
	}
	n=PotencijalniKrivci(nizPotencijalnih,optuzeni);
	while (true) {
		
				string b;
				int a;
		try {
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			cin>>a;
			cin.get();
			if(!a)break;
			else if(a==1) {
				cout<<"Unesite ime novog optuzenog: \n";
				string unos;
				while (cin.peek()=='\n') {cin.get();}
				while (cin.peek()!='\n') {
					unos.push_back(cin.get());
				}
				n=DodajOptuzbu(nizPotencijalnih,n,unos);
			} else if(a==2) {
				cout<<"Unesite ime koje zelite izbaciti: \n";
				string unos;
				while (cin.peek()=='\n') {cin.get();}
				while (cin.peek()!='\n') {
					unos.push_back(cin.get());
				}
				n=OdbaciOptuzbu(nizPotencijalnih,n,unos);
			} else if(a==3) {
				IzlistajOptuzbu(nizPotencijalnih,n);
			}
		} catch(std::domain_error e) {
			std::cout << e.what() << std::endl;
		} catch(...) {
			break;
		}

	}
	for (int i = 0; i < n; i++) {
		delete[] nizPotencijalnih[i];
		nizPotencijalnih[i]=nullptr;
	}
	delete[] nizPotencijalnih;
	return 0;
}