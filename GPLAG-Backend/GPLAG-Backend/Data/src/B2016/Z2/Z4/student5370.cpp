/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>

int PotencijalniKrivci(char **&pokazivac,std::vector<std::string> kontenjer){
	if (kontenjer.size()==0)
		return 0;                       //MOžda treba baciti grešku za 0
	char **pok{nullptr};
	try{
		pok=new char*[(int)kontenjer.size()]{nullptr};
	}
	catch(...){
		throw std::bad_alloc();
	}
	int i;
	try{
		for(i=0; i<(int)kontenjer.size(); i++){
			pok[i]=new char[kontenjer[i].length()+1];
			std::strcpy(pok[i], kontenjer[i].c_str());
		}
	}
	catch(...){
		for(int j=0; j<i; j++)
			delete[] pok[i];
		delete[] pok; //***Dodao sam []
		throw std::bad_alloc();
	}
	pokazivac=pok;
	return i;
}

int OdbaciOptuzbu(char **&pokazivac, int velicina, std::string NijeKrivac){
	bool izuzetak{true};
	for(int i=0; i<velicina; i++)
		if(std::string(pokazivac[i])==NijeKrivac){
			izuzetak=false;
			delete[] pokazivac[i];
			pokazivac[i]=nullptr;
		}
		
	if(izuzetak)
		throw std::domain_error("Osoba sa imenom "+ NijeKrivac +" nije bila optuzena");
	
	int brojac{0},br{0};
	for(int i=0; i<velicina; i++){
		if(pokazivac[i])
			brojac++;
		else
			br++;
	}
	if(br<=10) //ovdje možda treba samo <
		return velicina;
	
	char **pok{nullptr};
	try{
		pok=new char*[brojac]{nullptr};
	}
	catch(...){
		return velicina;
	}
	int i{0},j{0};
	try{
		for(int i=0; i<brojac; i++){
			while(!pokazivac[j])
				j++;
			pok[i]=new char[std::strlen(pokazivac[j])+1];
			std::strcpy(pok[i], pokazivac[j]);
			j++;
		}
		for(i=0;i<velicina;i++)
			delete[] pokazivac[i];
		delete[] pokazivac; //** DOdao sam []
		pokazivac=pok;
		return brojac;
	}
	catch(...){
		for(j=0;j<i;j++)
			delete[] pok[j];
		delete pok;
		return velicina;
	}
}

int DodajOptuzbu (char **&pokazivac, int velicina, std::string Krivac){
	char **spasi=pokazivac;
	int spasi1=velicina;
	try{
		char *p{nullptr};
		p=new char[Krivac.length()+1];
		std::strcpy(p,Krivac.c_str());
		bool prekidac{true};
		for(int i=0; i<velicina; i++)
			if(!pokazivac[i]){
				prekidac=false;
				pokazivac[i]=p;
				break;
			}
		if(prekidac){
			char **pok{nullptr};
			try{
				pok=new char*[velicina+1]{nullptr};}
			catch(...){
				throw std::bad_alloc();}
			int i;
			for(i=0; i<velicina; i++)
				pok[i]=pokazivac[i];
			pok[i]=p;
			delete[] pokazivac;
			pokazivac=pok;
			return velicina+1;
		}
		else
			return velicina;
	}
	catch(...){
		pokazivac=spasi;
		velicina=spasi1;
		throw std::bad_alloc();
	}
}
void IzlistajOptuzbu(char **&pokazivac, int velicina){
	for(int i=0; i<velicina; i++)
		if(pokazivac[i])
			std::cout<<pokazivac[i]<<"\n";
}

int main ()
{
	int p;
	std::vector<std::string> a;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin>>p; //ŠTA AKO JE P<0 ili P==0
	if(p!=0){
	std::cout<<"\nUnesite potencijalne krivce: \n";
	std::cin>>std::ws;
	a.resize(p);//može baciti izuzetak, a treba vidjeti gdje hvatati izuzetke i šta sa njima, kao i gdje \n
	for(int i=0;i<p;i++)
		std::getline(std::cin,a[i]);}
	char **t{nullptr};
	p=PotencijalniKrivci(t,a);
	while(1){
		std::string z;
		int n;
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		std::cin>>n;
		if(n==0)
			break;
		else if(n==1){
			std::cout<<"Unesite ime novog optuzenog: \n";
			std::cin>>std::ws;
			std::getline(std::cin,z);
			p=DodajOptuzbu(t,p,z);
		}
		else if(n==2){
			std::cout<<"Unesite ime koje zelite izbaciti: \n";
			std::cin>>std::ws;
			std::getline(std::cin,z);
			try{
				p=OdbaciOptuzbu(t,p,z);}
			catch(std::domain_error iz){
				std::cout<<iz.what();}
		}
		else if(n==3)
			IzlistajOptuzbu(t,p);
	}
	for(int i=0; i<p; i++)
		delete[] t[i];
	delete[] t;
	return 0;
}