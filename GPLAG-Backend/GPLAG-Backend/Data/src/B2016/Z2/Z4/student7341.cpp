/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <string>
#include <vector> 


int PotencijalniKrivci (char**& znakovi, std::vector<std::string> vektor){
     
	int brojac(0);
	try {
		znakovi=new char* [vektor.size()];
		for(int i=0; i<vektor.size(); i++) znakovi[i]=nullptr;
		try {
			int j=0;
			while(j<vektor.size()){
				znakovi[j]= new char[vektor[j].size()+1];
				brojac++;
				j++;
			} 
			for(int i=0; i<vektor.size(); i++){
				for(int j=0; j<=vektor[i].length(); j++){
					if(j=vektor[i].length()) znakovi[i][j]='\0';
					else znakovi[i][j]=vektor[i][j];
				}
			}
		}  catch(...) {
			for(int i=0; i<brojac; i++) delete[] znakovi[i];
			
			throw;
			}
	}	
		catch(...){
			delete[] znakovi;
			throw;
		}
		
return vektor.size();
			
}

int OdbaciOptuzbu( char**& znakovi, int velicina, std::string osoba){
	int brojac(0);
	for(int i=0; i<velicina; i++){
		int j(0);
		while(znakovi[i][j]!='\0' && j<osoba.length()){
			if(znakovi [i][j]!=osoba[j]) break;
			j++;
		}
		if(j=int(osoba.length())){
			delete[] znakovi[i];
			znakovi[i]==nullptr;
			brojac++;
		}
	}
	char **pomocni=znakovi;
	char **skraceni;
	if(brojac>10){
		
		*skraceni=new char[velicina-brojac];
		for(int j=0; j<velicina; j++){
			int brojslova(0);
		    if(pomocni[j]!=nullptr){
				  while(*pomocni[j]!='\0') {
				  	pomocni[j]++;
				  	brojslova++;
				}
			    *skraceni=new char[brojslova];
			    for(int i=0; i<brojslova;i++){
			    	skraceni[j][i]=pomocni[j][i];
			    }
			}
		}
		return (velicina-brojac);
	}
	
return velicina;
}

int DodajOptuzbu ( char **& znakovi, int velicina, std::string ime){
	char *nizime= new char[ime.length()+1];
	
	for(int i=0; i<=ime.length(); i++) {
		if(i==ime.length()) nizime[i]='\0';
		else nizime[i]=ime[i];
	}
	
	char ** pomocni=znakovi;
	 //ako ima neki nulptr
	 int i(0);
	 while (i<velicina){
	    if (pomocni[i]==nullptr){
	    	pomocni[i]=nizime;
	    	return velicina;
	 	}
	 	i++;
	 }
	  
	  //ako nema nullptr
	  char ** najnovijiniz;
	  if(i==velicina){
	  	najnovijiniz= new char*[velicina+1];
	  	for(int i=0; i<velicina+1;i++){
	  	    if(i==velicina) najnovijiniz[i]=nizime; 
	        else {
	        	int brojslova(0);
	  			int j(0);
	  			while(pomocni[i][j]!='\0'){
	  				brojslova++;
	  				j++;
	  			}
	  			najnovijiniz[i]=new char [brojslova+1];
	  			for(int k=0; k<=brojslova; k++){
	  			najnovijiniz[i][k]=pomocni[i][k];
	  			}
	  		}
	    }
	    
	    return velicina+1;
	}
}

void IzlistajOptuzbu (char **znakovi,int velicina){
	for(int i=0; i<velicina; i++){ 
		if(znakovi[i]==nullptr) continue;
		int j(0);
		while(znakovi[i][j]!='\0'){
			std::cout<< znakovi[i][j];
			j++;
		}
		std::cout<<std::endl;
	}


}
int main (){
	char **matrica;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?";
	int n;
	std::cin>>n;
	std::cin.ignore(1000,'\n');
	std::cout<<"Unesite potencijalne krivce: ";
	std::vector<std::string>krivci;

	for(int i=0; i<n; i++){
		std::string osoba;
		std::getline(std::cin, osoba);
		krivci.push_back(osoba);
	}	
	int velicina(PotencijalniKrivci(matrica,krivci));
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";	
	int naredba;
	std::cin>>naredba;
	std::cin.ignore(1000,'\n');
	while(naredba!=0){
	if(naredba==1){
		std::string novi_optuzeni;
		std::cout<<"Unesite ime novog optuzenog: ";
		std::getline(std::cin,novi_optuzeni);
		velicina=DodajOptuzbu(matrica, velicina, novi_optuzeni);
	}
	if(naredba==2){
		std::string izbaci_ovog;
		std::cout<<"Unesite ime koje zelite izbaciti: ";
		std::getline(std::cin,izbaci_ovog);
		velicina=OdbaciOptuzbu(matrica, velicina, izbaci_ovog);
	}
	if(naredba==3){
		IzlistajOptuzbu(matrica, velicina);
	}
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";	
	std::cin>>naredba;
	std::cin.ignore(10000,'\n');
	}
	
	
	return 0;
}
		