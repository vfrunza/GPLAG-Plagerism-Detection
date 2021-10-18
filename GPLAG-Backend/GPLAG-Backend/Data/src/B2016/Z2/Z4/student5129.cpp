/*B 16/17, Zadaća 2, Zadatak 4 */
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

int PotencijalniKrivci(char **(&p), vector<string> spisak){
	// int duzinaNiza = spisak[i].size() + 1;
	
	// Niz pokazivaca koji ce kasnije sadrzati pokazivace na nizove charova
	char** nizpok = nullptr;
	// Pocetak od nizpok, koji je potrebno smjestiti u prvi parametar funkcije
	char** pocetak(nizpok);
	// Pravimo niz pokazivaca
	try{
	    nizpok = new char* [spisak.size()];
	} catch(...){
	    delete[] nizpok;
	    throw;
	}
	
	// Dinamicki alociran niz charova 
	try{
	    for(int i=0; i<spisak.size(); i++){
	        
	        // Privremeni pokazivac na dinamicki alociranu memoriju
	        char* temp = new char[spisak[i].size()+1];
	        // Ubacivanje imena u dinamicki alociran niz karaktera
	        for(int j=0; j<spisak[i].size(); j++){
	            *temp++=spisak[i][j];
	        }
	        // Postavljanje NUL granicnika na kraj niza karaktera
	        *temp='\0';
	        
	        // Stavljanje ovog niza karaktera 
	        *nizpok++=
	    }
	    
	} catch(...){
	    
	}
}

int OdbaciOptuzbu(char **(&p), int vel, string ime){
	
}

int DodajOptuzbu(char **(&p), int vel, string ime){
	
}

void IzlistajOptuzbu(char **p, int vel){
	
}


int main (){
	return 0;
}