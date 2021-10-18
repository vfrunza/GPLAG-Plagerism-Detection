/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <new>
#include <cstring>
#include <string>
#include <vector>
#include <stdexcept>

int PotencijalniKrivci (char** &p, const std::vector<std::string> &s){
	int brojac(0);
	char ** pok(nullptr);
	
	try{
		pok=new char* [s.size()];
		for(int i=0; i<s.size(); i++) pok[i]=nullptr;
		
		for(int i=0; i<s.size(); i++){
			pok[i]= new char [s[i].length()+1];
		}
		for(int i=0; i<s.size(); i++){
			std::strcpy(pok[i], s[i].c_str());
			pok[i][s[i].length()] = '\0';
			brojac++;
		}
		p=pok;
		pok=nullptr;
	}
	catch(std::bad_alloc){
		for (int i=0; i<s.size(); i++) delete [] pok[i];
		delete [] pok;
		//brojac=0;
		pok=nullptr;
		p=nullptr;
		throw;
	}
	return brojac;
	
}

int OdbaciOptuzbu (char** &p, int vel, std::string ime){
	int br(0), indeks(0);
	bool postoji(false);
	
	for (int i=0; i<vel; i++){
		if (p[i]==nullptr) br++;
		else if ( ime==std::string(p[i]) ) { postoji=true; indeks=i; break; }
	}
	if (!postoji){
		std::string iz;
		iz="Osoba sa imenom "+ime+" nije bila optuzena";
		throw std::domain_error(iz);
	}
	delete [] p[indeks];
	p[indeks]=nullptr , br++;
	if(br>10){
		char** novi(nullptr);
		novi=new char* [vel-br];
		int ind(0);
		for(int i=0; i<vel; i++){
			if ( p[i] ){
				novi[ind]=p[i];
				p[i]=nullptr;
				ind++;
			}
		}
		delete [] p;
		p=nullptr;
		p=novi;
		vel-=br;
	}
	
	return vel;
	
}

int DodajOptuzbu (char** &p, int vel, std::string ime){
	int nova_vel=vel;
	char* niz_ime(nullptr);

	try{
		niz_ime=new char [ime.length()+1];
		for(int i=0; i<ime.length(); i++) niz_ime[i]=ime[i];
		niz_ime[ime.length()]='\0';
		//std::cout<<"Doslo"<<std::string(niz_ime)<<std::endl;
		//std::strcpy (niz_ime, ime.c_str());
		//niz_ime[ime.length()+1]='\0';
	}
	catch (std::bad_alloc){
		delete [] niz_ime;
		niz_ime=nullptr;
		throw;
	}
	
	bool ima_slobodno(false);
	//int indeks(0);
	for(int i=0; i<vel; i++) {
		if(!p[i]) {
			//indeks=i;
			ima_slobodno=true;
			p[i]=niz_ime;
			niz_ime=nullptr;
			break;
		}
	}
	/*
	if(ima_slobodno){
		p[indeks]=niz_ime;
		niz_ime=nullptr;
	}*/
	if(!ima_slobodno){
		nova_vel=vel+1;
		char** niz(nullptr);
		try{
			niz=new char* [nova_vel];
			//for(int i=0; i<nova_vel; i++) niz[i]=nullptr;
			for(int i=0; i<vel; i++) niz[i]=p[i];
			niz[vel]=niz_ime; //OVDJE JE BILO niz[nova_vel]
			niz_ime=nullptr;
			for(int i=0; i<vel; i++) p[i]=nullptr;
			delete [] p;
			//p=nullptr;
			p=niz;
		
			//for(int i=0; i<nova_vel; i++) niz[i]=nullptr;
			//delete [] niz; 
			niz=nullptr;
			
		}
		catch(std::bad_alloc){
			delete [] niz; //d
			throw;
			//std::cout<<"doslo,..:/"<<std::endl;
		}
	}
	
	return nova_vel;
}

void IzlistajOptuzbu (char** p, int vel){
	for(int i=0; i<vel; i++){
		if(p[i]) std::cout<<std::string(p[i])<<std::endl;
	}
}


int main ()
{

	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int krivaca;
	std::cin>>krivaca;
	std::cin.ignore(100,'\n');
	std::vector<std::string> v;
	v.resize(krivaca);
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for (int i=0; i<krivaca; i++){
		std::getline(std::cin, v[i]);
		//std::cin.ignore(100,'\n');
	}
	//std::cin.ignore(100,'\n');
	char** lista(nullptr);
	int rez(0);
	try{
		rez=PotencijalniKrivci(lista, v);
		
		for(;;){
			int unos;
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			std::cin>>unos;
			std::cin.ignore(100000, '\n');
			if (unos==1){
				std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
				
				std::string ime;
				std::getline(std::cin, ime);
				rez=DodajOptuzbu(lista, rez, ime);
			}
			else if(unos==2){
				std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
				std::string ime;
				std::getline(std::cin, ime);
				try{
					rez=OdbaciOptuzbu(lista, rez, ime);
				}
				catch(std::domain_error iz){
					std::cout<<iz.what()<<std::endl;
				}
			}
			else if(unos==3){
				IzlistajOptuzbu(lista, rez);
			}
			else if(unos==0) {
				for(int i=0; i<rez; i++) delete [] lista[i];
				delete [] lista;
				lista=nullptr;
				break;
			}
		}
	}
	catch(std::bad_alloc){
		for(int i=0; i<rez; i++) delete [] lista[i];
		delete [] lista;
		lista=nullptr;
		rez=0;
		
	}
	
	
	
	
	/*
	
	std::vector<std::string> pokusaj {"kisa", "suncejeifwjf ", "   skks$%s"};
	char** d;
	int b(0);
	try {
		b=PotencijalniKrivci(d, pokusaj);
		//std::cout<<"Broj stringova je: "<<b<<std::endl;
		
		std::cout<<"Stringovi su: "<<std::endl;
		for(int i=0; i<b; i++) std::cout<<std::string(d[i])<<std::endl;
		
		b=DodajOptuzbu(d,b, "Perem");
		b=DodajOptuzbu(d,b, " dmd 3554");
		
		IzlistajOptuzbu(d,b);
		
		for(int i=0; i<b; i++) delete [] d[i];
		delete [] d;
	}
	catch (std::bad_alloc) {
		std::cout<<"Losee"<<std::endl;
		for(int i=0; i<b; i++) delete [] d[i];
		delete [] d;
	}
	*/
	return 0;
}