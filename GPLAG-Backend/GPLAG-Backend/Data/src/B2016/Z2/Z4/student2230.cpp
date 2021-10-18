#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>

int PotencijalniKrivci(char **&znak, std::vector<std::string> vektor){
	int n=vektor.size();
	int brojac(0);
	try{
		char **niz(new char*[n]);
		for(int i(0);i<n;i++){
			niz[i]=nullptr;
		}
		try{
			for(int i(0);i<n;i++){
				int m=vektor[i].size();
				niz[i]=new char[m+1];
				for(int j(0);j<m;j++){
				niz[i][j]=vektor[i][j];
			}
			niz[i][m]='\0';
			brojac++;
			}
			znak=niz;
		}
			catch(std::bad_alloc){
				for(int i(0);i<n;i++) delete[] niz[i];
				delete[] niz;
				throw;
			}
		}
		catch(std::bad_alloc){
			std::cout<<"Problemi sa memorijom!\n";
		}
		return brojac;
}
int  OdbaciOptuzbu(char **&znak,int &velicina_niza,std::string ime_osobe){
//	int velicina_imena=ime_osobe.length();
	int brojacobrisanih(0);
	bool a(false);
	int mjesto;
	
	for(int i(0);i<velicina_niza;i++){
	std::string ime;
		int k(0);
		while(znak[i][k]!='\0') {
			ime+=znak[i][k];
			k++;
		}
		if(ime==ime_osobe){ a=true; mjesto=i; break;}
		ime.clear();
	}
		if(a==true){
			delete[] znak[mjesto];
			brojacobrisanih++;
			znak[mjesto]=nullptr;
		}
		if(a==false){
			std::string izuzetni="Osoba sa imenom "+ime_osobe+" nije pronadjena";
			throw std::domain_error(izuzetni);
		}
	int brojitelj(0);
	for(int i(0);i<velicina_niza;i++){
		if(znak[i]==nullptr) brojitelj++;	
	}
	if(brojitelj<=10) return velicina_niza;
	else{
		int velicinanovog=velicina_niza-brojacobrisanih-brojitelj;
		try{
		char **noviniz=new char*[velicinanovog];
		for(int i(0);i<velicina_niza;i++){
			if(znak[i]!=nullptr){
				noviniz[i]=znak[i];
			}
		}
		delete [] znak;
		znak=noviniz;
		velicina_niza=velicinanovog;
		return velicinanovog;
	}
	catch(...){}
}
return velicina_niza;
}
int DodajOptuzbu (char **&znak,int &velicina_niza,std::string ime_osobe){
	int velicina_imena=ime_osobe.length();
	bool a(false);
	int etotu;
	//try{
	/*char *novinizz=new char[velicina_imena+1];
	for(int i(0);i<velicina_imena;i++){
		novinizz[i]=ime_osobe[i];
	}
	novinizz[velicina_imena]='\0';*/
	for(int i(0);i<velicina_niza;i++){
		if(znak[i]==nullptr){
			a=true;
			etotu=i;
			break;
		}
	}
	if(a==true){
		try{
		znak[etotu]=new char [velicina_imena+1];
		for(int i(0);i<velicina_imena;i++) {
			znak[etotu][i]=ime_osobe[i];}
			znak[etotu][velicina_imena]='\0';
		return velicina_niza;}
		catch(std::bad_alloc){
			znak[etotu]=nullptr;
			throw;
		}
	}
	else if(a==false){
		//char **znakovni=nullptr;
		try{
			char **znakovni=new char*[velicina_niza+1];
			for(int i(0);i<velicina_niza;i++){
				znakovni[i]=znak[i];
			}
			try{
			znakovni[velicina_niza]=new char[velicina_imena+1];
			for(int i(0);i<velicina_imena;i++){
				znakovni[velicina_niza][i]=ime_osobe[i];
			}
			znakovni[velicina_niza][velicina_imena]='\0';
			
			delete[] znak;
			//znak=new char*[velicina_niza+1];
			znak=znakovni;
			/*for(int i(0);i<velicina_niza+1;i++){
				znak[i]=znakovni[i];
			}
			delete [] znakovni;*/
			
			velicina_niza=velicina_niza+1;
			return velicina_niza+1;
			}
			catch(...){
			delete[] znakovni[velicina_niza];
			delete[] znakovni;
			throw;
			}
		}
		catch(...){throw;}
}
return velicina_niza;
}
void IzlistajOptuzbu(char **znak,int velicina_niza){
	for(int i(0);i<velicina_niza;i++){
		if(znak[i]==nullptr) continue;
		else std::cout<<znak[i]<<std::endl;
	}
}

/*void dealociraj(char **mat,int n){
	for(int i(0);i<n;i++) delete[] mat[i];
	delete[] mat;
}*/

int main ()
{
	int krimosi;
	int m;
	int opcija;
	std::vector<std::string> krivci;
	char **nizPotencijalnih;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin>>krimosi;
	std::string krivac;
	std::cout<<"Unesite potencijalne krivce: ";
	for(int i(0);i<krimosi;i++){
		std::cin>>std::ws;
		std::getline(std::cin,krivac);
		krivci.push_back(krivac);
	}
	int vel=PotencijalniKrivci(nizPotencijalnih,krivci);
	
	for(;;){
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	std::cin>>opcija;
	if(opcija==0) return 0;
	else if(opcija==1){
		std::string ime;
		std::cout<<"Unesite ime novog optuzenog: " << std::endl;
		std::cin>>std::ws;
		std::getline(std::cin,ime);
		try{
		m=DodajOptuzbu(nizPotencijalnih,vel,ime);}
		catch(...){
			std::cout<<"Neuspjela alokacija"<<std::endl;
		}
	}
	else if(opcija==2){
		std::string ime;
		std::cout<<"Unesite ime koje zelite izbaciti: ";
		std::cin>>std::ws;
		std::getline(std::cin,ime);
		try{
		m=OdbaciOptuzbu(nizPotencijalnih,vel,ime);}
		catch(std::domain_error izuzetak){
			std::cout<<"Osoba sa imenom "<<izuzetak.what()<<" nije bila optuzena"<<std::endl;	
			
		}
	}
	else if(opcija==3){
		IzlistajOptuzbu(nizPotencijalnih,vel);
	}
}}
