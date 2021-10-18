/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <new>
#include <stdexcept>
#include <iomanip>


int PotencijalniKrivci(char **&znak, std::vector<std::string> v){
	
	
	int br_red = v.size();	
	
	//mozda treba proci kroz vektor v i naci one elemente koji nisu prazni !

	char **a = nullptr;
	try{
		//dinamicki alociramo nizove pokazivaca koji ce pokazivati na 
	
	a = new char*[br_red];
	for(int i=0;i<v.size();i++)a[i] = nullptr;
	
	
	try{
		//dinamicki alociramo nizove znakova
		for(int i=0;i<v.size();i++){
			a[i] = new char[v[i].size() +1];//ovo +1 je za nul granicnik!
			
		}
		
		//sada u te nizove znakova prepisujemo elemente vektora stringova !
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				a[i][j] = v[i][j];
			}
			a[i][v[i].size()] = '\0';
		}
		
		znak = a;
		return br_red;
		
	}catch(...){
		
		for(int i=0;i<br_red;i++)delete [] a[i];    //DA LI TREBAM BRISATI AKO JE STALO ALOCIRANJE ??
		delete [] a;
		throw;
	}
		
	}catch(...){
       //ovdje provjeriti 
		throw std::bad_alloc();
	}
	
	return br_red;
	
}




int OdbaciOptuzbu(char **&znak,int vel_niza,std::string s){
	
	//s je ime koje treba izbrisati iz evidencije potencijjalinh krivaca
	std::string temp;
	int indeks = -1;
	
	for(int i=0;i<vel_niza;i++){
		temp = s[i];
		
		if(znak[i] != nullptr && znak[i] == s){
			indeks = i;
			break;
		}
	}
	
	//ako je indeks ostao -1 znaci da osobe nema u nizu !
	if(indeks == -1){
		temp ="Osoba sa imenom " + s + " nije bila optuzena";
		throw std::domain_error(temp);
	}
	
	//ovdje smo ako je pronadjena osoba !
	//brisemo osobbu postavljamo pokazivac na nullptr
	
	delete[] znak[indeks];
	znak[indeks] = nullptr;
	
	//sada prebrojimo koliko je dosada osoba izbrisano tj kolko ima nullpokazivaca
	int broj_nulpok = 0;
	for(int i=0;i<vel_niza;i++){
		if(znak[i] == nullptr)broj_nulpok++;
	}
	
	if(broj_nulpok<=10)return vel_niza;
	
	//ako ima vise od 10 obrisanih vrsimo novu alokaciju nizova !
	
	int broj_novih = vel_niza-broj_nulpok;
	
	char **a = nullptr;
	
		
		try{
			
			//pokusavamo alocirati novi niz
			a = new char*[broj_novih];
			for(int i=0;i<broj_novih;i++)a[i] = nullptr;
			
			//sada alociramo novi niz pokazivaca !
			int h = 0;
			for(int i=0;i<vel_niza;i++){
				if(znak[i] != nullptr){a[h] = znak[i];h++;}
			}
			
		
			
			//ako je sve u redu obrisemo stari pokazivac na pokzivace i dodijelimo mu novu vrijednost
			delete [] znak;                                    
			znak = a;
			return broj_novih;
	
		}catch(...){
			
			return 0;
		}
		
		
		
		return vel_niza;
	
	
}



int DodajOptuzbu(char **&znak,int vel_niza,std::string s){
	
	//s je osoba koju treba dodati u niz !
	
		char *niz =  nullptr;
		
	try{
		niz = new char[s.length() +1];   //ovo +1 je za nul granicnik !   //provjeriti OVDJE MOZDA uopste ne treba +1
		//ukoliko je alokacija uspjela nastavaljmo
		
		//iskopiramo ime u ovaj niz !
		for(int i=0;i<s.length();i++)niz[i] = s[i];
		niz[s.length()] = '\0';
		
	}catch(...){
		throw std::bad_alloc();
	}
	
	
		//na prvo mjesto sa nullptr u nizu pokazivaca znak upisujemo nas novi niz
		for(int i=0;i<vel_niza;i++){
			if(znak[i] == nullptr){
				
				znak[i] = niz;
				return vel_niza;  //vel niza pokazivaca ostala je ista samo smo prepisali preko nul grancinka!
			}
		}
		
		//ukoliko nije nadjen niti jedan nullptr u nizu pokazivaca znak radimo sljedece
		char **a = nullptr;
		try{
			a = new char*[vel_niza+1];
			int nova_vel = vel_niza +1;
			
			for(int i=0;i<nova_vel;i++)a[i] = nullptr;
				
				for(int i=0;i<vel_niza;i++){
					a[i] = znak[i];
				}
				a[vel_niza] = niz;
				
				//brisemo stari niz pokazivaca pazeci da ne obrisemo glavni pokazivac i vracamo novu vel niza
			
				delete [] znak;
				znak = a;
				return nova_vel;
		
			
		}catch(...){
			delete [] niz;
			throw std::bad_alloc();
		}
		return vel_niza;

}



void IzlistajOptuzbu(char **znak,int vel_niza){
	
	for(int i=0;i<vel_niza;i++){
	
		if(znak[i] != nullptr){
		std::cout<<znak[i];
		std::cout<<std::endl;}
	}
	
	
}




int main ()
{
	
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin>>n;
	std::cout<<"\nUnesite potencijalne krivce: ";
	
	
	char **nizPotencijalnih;
	std::vector<std::string>v(n);
	for(int i=0;i<n;i++){
		std::cin>>v[i];
	}	
	
	try{
	int broj_krivaca = PotencijalniKrivci(nizPotencijalnih,v);
	
	int unos;
	
	std::cout<<std::endl;
	do{
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	std::cin>>unos;
	
	
	if(unos == 1){
		std::cout<<"\nUnesite ime novog optuzenog: ";
		std::cout<<std::endl;
		try{
			std::string s;
			std::cin>>s;
			broj_krivaca = DodajOptuzbu(nizPotencijalnih,broj_krivaca,s);
			
		}catch(std::bad_alloc temp){
			return 0;
		}
	}else if(unos==2){
		std::cout<<"\nUnesite ime koje zelite izbaciti: ";
		std::string s;
		std::cin>>s;
		std::cout<<std::endl;
		
		try{
		broj_krivaca = OdbaciOptuzbu(nizPotencijalnih,broj_krivaca,s);
		}catch(std::domain_error temp){
			std::cout<<temp.what()<<std::endl;
		}
	}else if(unos==3){
		std::cout<<std::endl;
		IzlistajOptuzbu(nizPotencijalnih,broj_krivaca);
		
	}

	}while(unos != 0);
	
	//ako sve uspije !
		
	for(int i=0;i<broj_krivaca;i++){
	delete [] nizPotencijalnih[i];
	}
	
	delete []nizPotencijalnih;
	
	}catch(std::bad_alloc temp){
		return 0;
	}
	
	return 0;
}





































































































































