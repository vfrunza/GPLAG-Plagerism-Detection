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

int PotencijalniKrivci (char **&niz, std::vector<std::string> imena){
	int br(0);
	try{
		niz=new char*[imena.size()];
		//int br(0);
		try{
	   		while(br<imena.size()) {
	   		niz[br]=new char[imena[br].size()+1]; 
	   		std::strcpy(niz[br],imena[br].c_str());
	        br++;
	   		}
		}	
		catch(std::bad_alloc){
			for(int i=0;i<br;i++) delete[] niz[i];
			delete[] niz;
			throw;
		}
	}
	catch(...){
		throw;
	}
	return br;
}

int OdbaciOptuzbu(char **&niz, int br, std::string ime){
	bool postoji=false;
	int broj(0);
	for(int i=0;i<br;i++){
		if(niz[i]!=nullptr){
			if(std::strcmp(niz[i],ime.c_str())==0) {
				postoji=true;
				delete[] niz[i];
				niz[i]=nullptr;
				broj++;
			}
		}
	}
	if(postoji==false) throw std::domain_error("Osoba sa imenom nije bila optuzena");
	int novavel=br;
	int j(0);
	char** novi=nullptr;
	if(broj>10){
		novavel=br-broj;
	  //  char** novi;
		try{
			novi=new char*[novavel];
			try{
				for(int i=0;i<br;i++){
					if(niz[i]!=nullptr) {
						novi[j]=new char[std::strlen(niz[i])+1];
						std::strcpy(novi[j],niz[i]); 
						j++;
					}
				}
			}
	    	catch(std::bad_alloc){
	    		for(int i=0;i<novavel;i++) delete[] novi[j];
	    		delete[] novi;
	    		return br;                //ako ne uspije vraca pocetnu velicinu
	    	}
		}
		catch(...){
	    	return br;
	    	}
	}
/*	for(int i=0;i<br;i++)
		delete[] niz[i];
		delete[] niz;
		niz=novi;*/

	return novavel;
}

int DodajOptuzbu(char **&niz, int br, std::string ime){
	char* novi=new char[ime.size()+1];
	bool postojinul=false;
	std::strcpy(novi,ime.c_str());
	for(int i=0;i<br;i++){
		if(niz[i]==nullptr) {
			postojinul=true;              
			niz[i]=novi;
			break;
		}
	}
	if(postojinul==false){
	 char** novi2;
	   try{
		 novi2=new char*[br+1];
	   	 for(int i=0;i<br;i++){
	   	 	try{
	   		 novi2[i]=new char[std::strlen(niz[i])+1];
	   	     std::strcpy(novi2[i],niz[i]);
	   	 	}
	   	 	catch(...){
	   	 		for(int i=0;i<br;i++) delete[] novi2[i];
	   	 		delete[] novi2;
	   	 	}
	   	 }
	   	novi2[br]=novi;
	   	for(int i=0;i<br;i++) delete[] niz[i];
	   	delete[] niz;
	   	niz=novi2;
	   }
	   catch(std::bad_alloc){
	   	for(int i=0;i<br;i++) delete[] novi2[i];
	   	delete[] novi2;
	   	delete[] novi;
	   	throw;
	   }
	}
	
    int novavel=br+1;
    return novavel;
}


void IzlistajOptuzbu(char **niz, int br){
	for(int i=0;i<br;i++){
		if(niz[i]!=nullptr) std::cout<<niz[i]<<std::endl;
	}
}

int main ()
{   std::cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<std::endl;
    int n;
    char** niz;
    std::cin>>n;
    std::cout<<"Unesite potencijalne krivce:"<<std::endl;
    std::cin.ignore(1000,'\n');
    std::string ime;
    std::vector<std::string> imena;
    for(int i=0;i<n;i++){
    	std::getline(std::cin,ime);
    	imena.push_back(ime);
    }
    int br=PotencijalniKrivci(niz,imena);
    int x=1;
    do{
    	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
    	std::cin>>x;
    	if(x==1){
    		std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
    		std::cin.ignore(1000,'\n');
    		std::getline(std::cin,ime);
            try{
    		br=DodajOptuzbu(niz,br,ime);
            }
            catch(std::domain_error izuzetak){
            	std::cout<<izuzetak.what()<<std::endl;
            }
    	}
    	if(x==2){
    		std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
    		std::cin.ignore(1000,'\n');
    		std::getline(std::cin,ime);
    		br=OdbaciOptuzbu(niz,br,ime);
    	}
    	if(x==3){
    	  IzlistajOptuzbu(niz,br);	
    	}
    	
    } while(x!=0);
	return 0;
}