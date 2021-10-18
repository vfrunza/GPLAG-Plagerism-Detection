/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

void UnistiMatricu(char **mat, int br_redova){
	if(!mat) return;
	for(int i=0; i<br_redova; i++) delete [] mat[i];
	delete[] mat;
}

int PotencijalniKrivci (char **&p, std::vector<std::string> s){
	
	try{
		p=new char* [int(s.size())];
		    for(int i(0); i<int(s.size()); i++) p[i]=nullptr;
		try{
			
			for(int i(0); i<int(s.size()); i++) {
				p[i]=new char [int(s.at(i).size())+1];
			}
			for(int i(0); i<int(s.size()); i++) std::strcpy(p[i], s[i].c_str());
			
		}
		catch(...){
			for(int i(0); i<int(s.size()); i++) delete[] p[i];
			delete[] p;
			p=nullptr;
			throw std::bad_alloc();
		}
		
	}
	catch(...){
		
			delete[] p;
			p=nullptr;
		
		throw std::bad_alloc();
	}
	
	return int(s.size());
}

int OdbaciOptuzbu (char**&p, int vel, std::string ime){
	
	bool nemapojave(true);
	for(int i(0); i<vel; i++){
		
		while(p[i]==nullptr)	{
			i++;
			if(i>=vel) break;
		}
		
		if(i>=vel) break;
		std::string pomocni;
		
		if( std::string(p[i])==ime) {
			nemapojave=false;
			delete[] p[i];
			p[i]=nullptr;
			break;
		}
	}
	std::string s("Osoba sa imenom "+ime+" nije bila optuzena");
	if(nemapojave) throw std::domain_error (s);
	
	int brojac(0);
	for(int i(0); i<vel; i++){
		if(p[i]==nullptr) brojac++;
	}
	if(brojac<=10) return vel;
	
	char **a(new char*[vel-brojac]);
	try{
		
		for(int  i(0); i<vel-brojac; i++) a[i]=nullptr;
		try{
			for(int i(0), k(0); i<vel-brojac; i++, k++){
				while(p[k]==nullptr) k++;
				a[i]=p[i];
			}
		}
		catch(...){
			for(int i(0); i<vel-brojac; i++ ) delete [] a[i];
			delete[] a;
			return vel;
		}
		for(int i(0); i<vel; i++){
			p[i]=nullptr;
		}
		UnistiMatricu(p,vel);
		p=a;
		return vel-brojac;
	}
	
	catch(...){
		delete[] a;
		return vel;
	}
	return vel;
}

int DodajOptuzbu (char **&p, int vel, std::string ime){
	char *niz(nullptr);
	try{
		niz=new char[int(ime.size())+1];
		std::strcpy(niz,ime.c_str());
	}
	catch(...){
		delete[] niz;
		throw std::bad_alloc();
	}
	
	for(int i(0); i<vel; i++){
		if(p[i]==nullptr){
			p[i]=niz;
			return vel;
		}
	}
	char **a(nullptr);
	try{
		a=new char* [vel+1];
		try{
			for(int i(0); i<vel+1; i++) a[i]=nullptr;
			for(int i(0); i<vel+1; i++){
				if(i<vel) {
					a[i]=p[i];
				}
				else {
					a[i]=niz;
					
				}
			}
		
			p=a;
		}
		catch(...){
			
			delete[] a;
			a=nullptr;
			delete[] niz;
			niz=nullptr;
			throw std::bad_alloc();
		
		}
	}
	catch(...){
		delete[] a; delete [] niz;
		throw std::bad_alloc();
	}
	
	
	
	return vel+1;
	
}

void IzlistajOptuzbu(char **p, int vel){
	for(int i(0); i<vel; i++){
		while(p[i]==nullptr) {
			i++; if(i>=vel) break;
		}
		if(i>=vel) break;
		
		std::cout<<p[i]<<std::endl;
	}
}

int main ()
{
	
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int vel ;
	std::cin>>vel;
	std::cin.ignore(1000,'\n');
	
	std::cout<<std::endl<<"Unesite potencijalne krivce: ";
	std::vector<std::string> s;
	for(int i(0); i<vel; i++){
		std::string pomocni;
		std::getline(std::cin,pomocni);
		s.push_back(pomocni);
	}
	
	char **mat(nullptr);
	
	try{
		std::cout<<std::endl;
		
			
		vel=PotencijalniKrivci(mat,s);
		
		
		for(;;){
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
			int opcija;
			std::cin>>opcija;
			std::cin.ignore(1000,'\n');
			if(opcija==0) break;
			if(opcija==1){
				std::cout<<std::endl<<"Unesite ime novog optuzenog: ";
				std::string ime;
				std::getline(std::cin, ime);
				vel=DodajOptuzbu(mat,vel,ime);
				std::cout<<std::endl;
				
			}
			if(opcija==2){
				std::cout<<std::endl<<"Unesite ime koje zelite izbaciti: ";
				std::string ime;
				std::getline(std::cin, ime);
				vel=OdbaciOptuzbu(mat, vel, ime);
				std::cout<<std::endl;
				
			}
			if(opcija==3){
				std::cout<<std::endl;
				IzlistajOptuzbu(mat,vel);
			}
			
		}
		UnistiMatricu(mat,vel);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
		UnistiMatricu(mat,vel);
	}
	catch(...){
		std::cout<<"Problemi sa memorijom";
		UnistiMatricu(mat,vel);
	}
	
	
	
	return 0;
}