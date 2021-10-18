/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>

int PotencijalniKrivci(char **&c, std::vector<std::string> v)
{ int br=0;
	char **nizpok=nullptr;
	try {
		nizpok=nullptr;
		nizpok=new char *[v.size()];
		for(int i=0; i<v.size(); i++) nizpok[i]=nullptr;
			for(int i=0; i<v.size(); i++) {
				std::string s=v[i];
				nizpok[i]=new char[v[i].size()+1];
				for(int j=0; j<v[i].size(); j++) nizpok[i][j]=s[j];
				nizpok[i][s.size()]='\0'; br++;
			} 

	} catch(std::bad_alloc) {
		for(int i=0; i<v.size(); i++) delete[] nizpok[i];
		delete[] nizpok;
		throw;
	}
	c=nizpok;
	return br;
}

int OdbaciOptuzbu(char **&c, int n, std::string s)
{ bool a=false;
if(s.size()==0) return n;
/*	for(int i=0; i<n; i++) { 
		for(int j=0; j<s.size(); j++) {
	  if(j==s.size()) a=true; else if(s[j]==c[i][j]) continue; } }
		 // bilo prije: while(s[j]==c[i][j]) j++; */
		 for(int i=0; i<n; i++) { if(c[i]==s) a=true; }
		 if(a==false) {
		throw std::domain_error ("Osoba sa imenom " + s + " nije bila optuzena");
	}

	/* NE VALJA: for(int i=0; i<n; i++) {
		for(int j=0; j<s.size();) {
			while(s[j]==c[i][j]) j++;
			if(j==s.size()) {
				delete[] c[i];
				c[i]=nullptr;
				n--;
			} else break;
		}
	} */
	
	for(int i=0; i<n; i++) { if(c[i]==s) { delete[] c[i]; c[i]=nullptr; } }
	return n;
}

int DodajOptuzbu(char ** &c, int n, std::string s) {
	if(s.size()==0) return n;
	char *novi=nullptr;
	try{ 
		novi=new char[s.size()+1];
		for(int i=0; i<s.size(); i++) novi[i]=s[i];
		//bilo novi[s.size()+1]='\0';
		novi[s.size()]='\0';
		for(int i=0; i<n; i++) { if(c[i]==nullptr) { c[i]=novi;
		break; } if(i==n) { char **c2=nullptr;
		try {
			for(int i=0; i<n+1; i++) c2[i]=nullptr;
			for(int i=0; i<n; i++) c2[i]=c[i];
			c2[n]=novi;
			novi=nullptr;
			for(int i=0; i<n; i++) delete[] c[i];
			delete[] c;
			c=c2; n++; return n;
		} catch(std::bad_alloc) {
			for(int i=0; i<n; i++) delete[] c2[i];
			//dodao delete[] c2; !!!
			delete[] c2;
		throw ("Error"); }
		}
	}
}
catch(std::bad_alloc) { delete[] novi; throw;  }
return n; }

void IzlistajOptuzbu(char **c, int n) {
	int i=0; while(i<n) { if(c[i]!=nullptr) std::cout<<c[i]<<std::endl; i++; } 
}



int main ()
{   char **potencijalni;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n; std::cin>>n; // broj potencijalnih krivaca=n 
	std::cin.ignore(1000, '\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> v;
	v.resize(n);
	for(int i=0; i<v.size(); i++) {
		// bilo ovo: std::getline(std::cin, v[i]);
		std::cin>>v[i];
	}
	try { n=PotencijalniKrivci(potencijalni, v);
int x; for(;;) { 	
std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
 std::cin>>x;  std::cin.ignore(1000, '\n');
 if(x==0) break;
if(x==1) {  std::string dodaj; std::cout<<"Unesite ime novog optuzenog: ";
std::getline(std::cin, dodaj); std::cout<<std::endl; n=DodajOptuzbu(potencijalni, n ,dodaj); }
if(x==2) {  std::string odbaci; std::cout<<"Unesite ime koje zelite izbaciti: "; 
std::getline(std::cin, odbaci); std::cout<<std::endl; try { n=OdbaciOptuzbu(potencijalni, n, odbaci); }
catch(std::domain_error msg)  { std::cout<<msg.what(); } }
if(x==3) { 	IzlistajOptuzbu(potencijalni, n);	}
} }
catch(...) {
	for(int i=0; i<n; i++) delete[] potencijalni[i];
	delete[] potencijalni;
}


//copy-paste maina iz autotesta radi provjere
/*
char **nizPotencijalnih;
 std::vector<std::string> imena = {"Fudo", "Pero", "Meho", "Fata", "Bajro", "Luca", "Jovo"};
 int n = PotencijalniKrivci( nizPotencijalnih, imena);
 int m = OdbaciOptuzbu(nizPotencijalnih, n, "Fata");
 std::cout << m << std::endl;
 */
	return 0;
}