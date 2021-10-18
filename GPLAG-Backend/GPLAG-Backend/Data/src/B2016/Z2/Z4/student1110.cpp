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

int PotencijalniKrivci(char** &niz, std::vector<std::string> imena){
	int brojac(0), i;
	try{
		niz=new char *[imena.size()];
		try{
			for(i=0; i<imena.size(); i++){
				niz[i]=new char[imena[i].length()+1]; //+1 za nul granicnik
				brojac++;
				for(int j=0; j<imena[i].size(); j++){
					niz[i][j]=imena[i][j];
					if(j==imena[i].size()-1)niz[i][j+1]='\0';
				}	
			}
		}
		catch(std::bad_alloc){
			for(int j=0; j<i; j++) delete[] niz[j];
			delete[] niz;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}
	/*for(int i=0; i<imena.size(); i++){ //ispis ovih alociranih nizova charova
		for(int j=0; j<imena[i].size()+1; j++){
			std::cout << "---_" << niz[i][j] << "_---";
		}
		std::cout << "\n"; */
	//} 
    //std::cout << "Imena.size()= " << imena.size() << " __ brojac=" << brojac << "\n"; //
	return brojac;
}

int OdbaciOptuzbu(char** &niz, int n, std::string ime){
	int BrojNulPok(0);
	bool ImaTeOsobeNaSpisku(false);
	for(int i(0); i<n; i++){
		bool DaLiJeIstiString(true);
		int j(0);
		if(niz[i]==nullptr){
			BrojNulPok++;
			continue;
		}
	//	if(std::strlen(niz[i])!=ime[i].size())DaLiJeIstiString=false;
		while(DaLiJeIstiString){ // mozda ovo ka treba break zavinso kao je rijec neka kraca duza onda nekad ode iza nul granicnika jedne jer tek prekida na nul granicniku druge
			if(niz[i][j]!=ime[j]){
				DaLiJeIstiString=false;
				break;
			}
			j++;
			if(niz[i][j]=='\0' || j==ime.length()){ // DODO 29.4. malo pred istek roka ovo malo popravio da radi kako treba
				if((niz[i][j]=='\0' && j!=ime.length()) || (niz[i][j]!='\0' && j==ime.length()))DaLiJeIstiString=false;
				break;
			}
		}
		if(DaLiJeIstiString) {
			ImaTeOsobeNaSpisku=true;
			delete[] niz[i];
			niz[i]=nullptr;
			BrojNulPok++;
			break;
		}
	}
	if(!ImaTeOsobeNaSpisku)throw std::domain_error("Osoba sa imenom " + ime + " nije bila optuzena"); 
	if(BrojNulPok>10){
		int br(0);
		try{
			char** novi_niz(new char *[n-BrojNulPok]);
			try{
				for(int i=0; i<n; i++){
					if(niz[i]!=nullptr){
						novi_niz[br]=new char[std::strlen(niz[i]+1)];
	
						for(int j=0; j<strlen(niz[i]); j++){
							novi_niz[br][j]=niz[i][j];
							if(j==strlen(niz[i])-1)novi_niz[br][j+1]='\0';
						} 
				
						br++;
					}
				}
				for(int i=0; i<n; i++)if(niz[i]!=nullptr) delete[] niz[i]; // brisem staro ovo
				delete[] niz;
				niz=novi_niz;
				return br;
			}
			catch(std::bad_alloc){
				for(int i=0; i<br; i++) delete[] novi_niz[i];
				delete[] novi_niz;	
				throw;
			}
		}
		catch(std::bad_alloc){
			return n;
		}
	}
	
	return n;
}

int DodajOptuzbu(char** &niz, int n, std::string ime){
	
	char* pok;
	try{
		pok=new char[ime.length()+1];
	}
	catch(std::bad_alloc){
		throw;
	}
	for(int i=0; i<ime.length(); i++){
		pok[i]=ime[i];
		if(i==ime.length()-1)pok[i+1]='\0';
	}
	for(int i=0; i<n; i++){
		if(niz[i]==nullptr){
			niz[i]=pok;
			return n;
		}
	}
		
	try{
		char** novi_niz(new char*[n+1]);
		int i;
		try{
			for(i=0; i<n; i++){
			/*	novi_niz[i]=new char[std::strlen(niz[i])+1];
				for(int j=0; j<strlen(niz[i]); j++){
					novi_niz[i][j]=niz[i][j];
					if(j==strlen(niz[i])-1)novi_niz[i][j+1]='\0';
				} */
				novi_niz[i]=niz[i];
			}
			novi_niz[n]=pok;

			//for(int j=0; i<n; j++)delete[] niz[j];
			delete[] niz;
			niz=novi_niz;
			return n+1;
		}
		catch(std::bad_alloc){
			for(int j=0; j<i; j++)delete[] novi_niz[j];
			delete[] novi_niz;
			throw;
		}
	}
	catch(std::bad_alloc){
		delete[] pok;
		throw;
	}
	
}

void IzlistajOptuzbu(char** niz, int n){
	for(int i=0; i<n; i++){
		if(niz[i]!=nullptr)std::cout << niz[i] << std::endl;
	}
}

int main ()
{
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> imena;
	std::cout << "Unesite potencijalne krivce: \n";
	for(int i(0); i<n; i++){
		std::string ime;
		std::getline(std::cin, ime);
		imena.push_back(ime);
	}
	/*for(int i(0); i<imena.size(); i++){ //ispis unesenih stringova
		std::cout << imena[i] << " ";
	}*/
	char** niz;

/*	int broj(PotencijalniKrivci(niz, imena));
	//std::cout << broj; //provjera
	int broj2(OdbaciOptuzbu(niz, n, "Faris"));
	std::cout << "--_" << broj2;*/
	
	int duzina(PotencijalniKrivci(niz, imena));
	for(;;){
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		int x;
		std::cin >> x;
		if(x==1){
			std::cout << "Unesite ime novog optuzenog: \n";
			std::string novi_optuzeni;
			std::cin.ignore(10000, '\n');
			std::getline(std::cin, novi_optuzeni);
			duzina=DodajOptuzbu(niz, duzina, novi_optuzeni);
		}
		else if(x==2){
			std::cout << "Unesite ime koje zelite izbaciti: \n";
			std::string za_izbacit;
			std::cin.ignore(10000, '\n');
			std::getline(std::cin, za_izbacit);
			try{
				duzina=OdbaciOptuzbu(niz, duzina, za_izbacit);
			}
			catch(const std::domain_error& e){      // DODO 29.4. pred istek roka
				std::cout << e.what() << std::endl;
			}
		}
		else if(x==3){
			IzlistajOptuzbu(niz, duzina);
		}
		else if(x==0)break;
		
	}
	//std::cout << "duzina: " << duzina;
	for(int i=0; i<duzina; i++)if(niz[i]!=nullptr)delete[] niz[i];
	delete[] niz;
	
	return 0;
}