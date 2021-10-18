/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<cstring>
bool poredi(char *s1,std::string s2){
	int i(0);
	while(*s1!=0 && i<s2.length()){
		if(*s1!=s2[i]) return false;
		i++;s1++;
	}
	if(*s1!=0) return false;
	if(i<s2.length()) return false;
	return true;
}
int PotencijalniKrivci(char** &znak,std::vector<std::string>stringovi){
	char**niz(nullptr);
	try{
		niz=new char*[stringovi.size()]{};
	}
	catch(...){
		delete[] niz;
		throw std::bad_alloc();
	}
	int brojac(0);
	try{
		int a,b;
		for(a=0;a<stringovi.size();a++){
			niz[a]=new char[stringovi[a].length()+1]{};
			for(b=0;b<stringovi[a].length();b++){
				niz[a][b]=stringovi[a][b];
			}
			niz[a][b]=0;
			brojac++;
		}
	}
	catch(...){
		for(int i=0;i<stringovi.size();i++) delete[] niz[i];
		delete[] niz;
		throw std::bad_alloc();
	}
	znak=niz;
	return brojac;
}
int OdbaciOptuzbu(char**&znak,int velicina,std::string ime){
	bool x(false);
	for(int i=0;i<velicina;i++){
		if(poredi(znak[i],ime)){
			delete[] znak[i];
			znak[i]=nullptr;
			x=true;
		}
	}
	if(x==false) throw std::domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
	int brojac(0);
	for(int i=0;i<velicina;i++){
		if(znak[i]==nullptr) brojac++;
	}
	char**novi(nullptr);
	try{
		if(brojac>10){
			novi=new char*[velicina-brojac]{};
			int k(0);
			for(int i=0;i<velicina;i++){
				if(znak[i]!=nullptr){
					novi[k]=znak[i];
					k++;
				}
			}
			for(int i=0;i<velicina;i++)delete[] znak[i];
			delete[] znak;
			znak=novi;
			velicina=velicina-brojac;
		}
	}
	catch(...){
		delete[] novi;
	}
	return velicina;
}
int DodajOptuzbu(char**&znak,int velicina,std::string ime){
	char*rijec(nullptr);
	try{
		rijec=new char[ime.length()+1]{};
	}
	catch(...){
		delete[]rijec;
		throw std::bad_alloc();
	}
	for(int i=0;i<ime.length();i++){
			rijec[i]=ime[i];
	}
	bool ima(false);
	for(int j=0;j<velicina;j++){
		if(znak[j]==nullptr){
			ima=true;
			znak[j]=new char[ime.length()+1]{};
			std::strcpy(znak[j],rijec);
			break;
		}
	}
	if(ima==false){
		char**niz(nullptr);
		try{
			niz=new char*[velicina+1]{};
		}
		catch(...){
			delete[]niz;
			throw std::bad_alloc();
		}
		int i;
		for(i=0;i<velicina;i++){
			int brojac(0);
			char*a=znak[i];
			while(*a++!=0) brojac++;
			niz[i]=new char[brojac+1]{};
			std::strcpy(niz[i],znak[i]);
		}
		niz[i]=rijec;
		for(i=0;i<velicina;i++)delete[] znak[i];
		delete[] znak;
		znak=niz;
		velicina++;
	}
	return velicina;
}
void IzlistajOptuzbu(char**znak,int velicina){
	for(int i=0;i<velicina;i++){
		if (znak[i]!=nullptr){
			 std::cout<<znak[i];
			 std::cout<<std::endl;
		}
	}
}
int main (){
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int n;
	std::cin>>n;
	std::vector<std::string> krivci(n);
	std::string temp;
	std::cout<<"Unesite potencijalne krivce: \n";
	for(int i=0;i<n;i++){
		std::cin>>krivci[i];
	}
	char**spisak(nullptr);
	int velicina(PotencijalniKrivci(spisak,krivci));
	int meni;
	do{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		std::cin>>meni;
		switch(meni){
			case 1:{ std::cout<<"Unesite ime novog optuzenog: \n";
			std::string optuzeni;
			std::cin>>optuzeni;
			velicina=DodajOptuzbu(spisak,velicina,optuzeni);
			break; }
			case 2:{ std::cout<<"Unesite ime koje zelite izbaciti: \n";
			std::string izbaci;
			std::cin>>izbaci;
			velicina=OdbaciOptuzbu(spisak,velicina,izbaci);
			break; }
			case 3: IzlistajOptuzbu(spisak,velicina);
		}
	}
	while(meni!=0);
	for(int i=0;i<velicina;i++) delete[]spisak [i];
	delete[] spisak;
	return 0;
}