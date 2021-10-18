/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>

int PotencijalniKrivci(char **&pok, std::vector<std::string> v){
	int j;
	int duzina(0);
	pok=nullptr;
	try{
	pok=new char*[v.size()];
	for(int i=0; i<v.size(); i++){
	pok[i]=nullptr;	
	pok[i]=new char[v[i].size()+1];
	duzina++;
	for(j=0; j<v[i].size(); j++){
		pok[i][j]=v[i][j];
	}
	pok[i][j]='\0';
	}
	return duzina;
	}
	catch(std::bad_alloc){
		for(int i=0; i<v.size(); i++)
		delete[] pok[i];
		delete[] pok;
	}
	return duzina;
}

int OdbaciOptuzbu(char **&pok, int velicina, std::string s){
	char *q(*pok);
	for(int i=0; i<velicina; i++){
		for(int j=0; j<s.length(); j++)
			if(*pok[i]==s[j]){
				char *p2(pok[i]);
				while(*p2!='\0' && j!=s.length()){
					if(*p2!=s[j])
					break;
					p2++;
					j++;
			}
			if(*p2=='\0' && j==s.length()){
			}
	}
}

return velicina;
}

int DodajOptuzbu(char **&pok, int velicina, std::string s){
	try{
	char *p(new char[s.length()+1]);
	for(int i=0; i<s.length(); i++)
		p[i]=s[i];
		p[s.length()]='\0';
		for(int i=0; i<velicina; i++)
			if(pok[i]==nullptr){
				pok[i]=p;
				return velicina;
			}
			velicina+=1;
		 char *d(new char[velicina]);
		char *m(d);
		int b;
		for(b=0; b<velicina; b++)
			d[b]=*pok[b];
			pok[b]=p;
		pok[b]=m;
	}
	catch(std::bad_alloc){
		return velicina;
	}
	return velicina;
}
void IzlistajOptuzbu(char **pok, int velicina){
	for(int i=0; i<velicina; i++){
		if(pok[i]!=nullptr){
			std::cout << pok[i];
			std::cout << std::endl;
	}
	
}
}	

int main ()
{
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> s(n);
	std::cout << std::endl << "Unesite potencijalne krivce: ";
	for(int i=0; i<n; i++)
	std::getline(std::cin, s[i]);
	char** pok;
		int k;
		int velicina(PotencijalniKrivci(pok, s));
	do {
	std::cout << std::endl << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";

	std::cin >> k;
	if(k==1){
		std::cout <<std::endl << "Unesite ime novog optuzenog: ";
		std::string x;
		std::getline(std::cin, x);
		velicina=DodajOptuzbu(pok, velicina, x);
		
	}
	if(k==2){
		std::cout <<std::endl << "Unesite ime koje zelite izbaciti: ";
		std::string x;
		std::getline(std::cin, x);
		velicina=OdbaciOptuzbu(pok, velicina, x );
	}
	if(k==3){
		IzlistajOptuzbu(pok, velicina);
	}
	}while(k!=0);
	return 0;
}