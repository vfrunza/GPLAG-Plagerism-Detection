/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

// Prve cetiri funkcije su pomocne funkcije

// Provjerava da li se znakovi vektora stringova nalaze u engleskom alfabetu

bool TestAlfabet(std :: string rijec){
	for(int i(0); i<rijec.length(); i++){
		if(rijec[i]<'A' || rijec[i]>'z') return false;
	}
	
	return true;
}

// Obrce poslanu rijec, zbog preglednosti glavne funkije.
// Koristila sam referencu da uzme u obziz upravo onu poslanu rijec, a ne njenu kopiju.

void Obrni(std :: string &rijec){
	char pomocni;
	for (int i(0); i<((int)rijec.length())/2; i++){
		pomocni=rijec[i];
		rijec[i]=rijec[rijec.length()-1-i];
		rijec[rijec.length()-1-i]=pomocni;
	}
	
}

// Sluzi da izdvojim substring iz recenice. 
// p-pocetak (od koje pozicije izdvaja znak)
// k-kraj (koliko znako uzima u obzir nakon znaka 'p')

std :: string IzdvojiRijec(std :: string recenica, int n){
	int razmak(1), broj_rijeci(0), i(0), p(0), k(0);
	
	//Bez specijalnih slucajeva sad
	
	while(i<recenica.length()-1){
		if(recenica[i]==' ') razmak=1;
		else if(razmak==1){
			razmak=0;
			broj_rijeci++;
		}
		
		if(broj_rijeci==n){
			p=i;
			break;
		}
		
		i++;
	}
	
	int b=p; //Neka varijabla, koja cuva vrijednost 'p' kako bih je mogla implementirati u funkciju substringa
	
	while(recenica[b]!=' ' && b<recenica.length()){
		k++;
		b++;
	}
	
	return recenica.substr(p,k);
}

int brojRijeci(std :: string recenica){
	int razmak(1), broj_rijeci(0), i(0);
	while(i<recenica.length()-1){
		if(recenica[i]==' ') razmak=1;
		else if(razmak==1){
			razmak=0;
			broj_rijeci++;
		}
		
		i++;
	}
	
	return broj_rijeci;
}

/* char pomocni;
	for (int i(0); i<((int)rijec.length())/2; i++){
		pomocni=rijec[i];
		rijec[i]=rijec[rijec.length()-1-i];
		rijec[rijec.length()-1-i]=pomocni;
		*/
std :: vector<std :: string>  ObrniFraze(std :: string recenica, std :: vector<std :: string> rijeci){
	int br_rj=brojRijeci(recenica);
	std :: vector<std :: string> razbijString;
	int d=rijeci.size()-1000;
	
	for(int i(0); i<rijeci.size(); i++){
		if(TestAlfabet(rijeci[i])==false) throw std :: domain_error ("Nekorektan izbor rijeci");
		}
	
	for(int i(0); i<br_rj; i++){
		razbijString.push_back(IzdvojiRijec(recenica,i+1));
	}
	
	char pomocni;
	for(int i(0); i<br_rj; i++){
		for(int j(0); j<=d; j++){
			if(rijeci[j]==razbijString[i]){
				for(int k(0); k<rijeci[j].length()/2; k++){
			} Obrni(razbijString[i]);
				
		}
	}
	
	return razbijString;
	
} 

std :: vector<std :: string>  IzmijeniUPigLatin(std :: string recenica, std :: vector<std :: string> rijeci){
	int br_rj=brojRijeci(recenica);
	std :: vector<std :: string> razbijString;
	
	for(int i(0); i<br_rj; i++){
		razbijString.push_back(IzdvojiRijec(recenica,i+1));
	}
	
	int d=rijeci.size()-1000;
	
	if(d==0){
		for(int i(0); i<br_rj; i++){
			std :: string pomocni=razbijString[i];
			pomocni=pomocni.substr(1,pomocni.length()-1)+pomocni[0]+"ay";
			razbijString[i]=pomocni;
			
		}
	
	} 
	
	
	for(int i(0); i<br_rj; i++){
		for(int j(0); j<=d; j++){
			if(rijeci[j]==razbijString[i]){
				std :: string pomocni=razbijString[i];
				pomocni=pomocni.substr(1, pomocni.length()-1) + pomocni[0] + "ay";
				razbijString[i]=pomocni;
				}
			}
			
		}
	
	return razbijString;
	
}

int main (){
	try {
		std :: string recenica;
		std :: cout << "Unesite recenicu: ";
		std :: getline(std :: cin, recenica);
		
		std :: cout << "Unesite fraze: ";
		std :: vector<std :: string> rijeci(1000);
		
		int j(0);
		while(std :: cin.peek()!='\n' ){
			std :: getline(std :: cin, rijeci[j]);
			rijeci.push_back(rijeci[j]);
			j++;
		}
		
		if(recenica.length()==0) return 0;
		
		std :: vector<std :: string> PiglatinRecenica=IzmijeniUPigLatin(recenica, rijeci);
		std :: vector<std :: string> ObrnutaRecenica=ObrniFraze(recenica, rijeci);
		
		std :: cout << "Recenica nakon PigLatin transformacije: ";
		
		for(int i(0); i<PiglatinRecenica.size(); i++){
			std :: cout << PiglatinRecenica[i]<< " "; 
		}
		
		std :: cout << "\nRecenica nakon obrtanja fraza: ";
		
		for(int i(0); i<ObrnutaRecenica.size(); i++){
			std :: cout << ObrnutaRecenica[i]<< " "; 
		}
		
	}
	catch(std :: domain_error IZUZETAK){
		std :: cout << IZUZETAK.what()<< std :: endl;
		
	}
	
	return 0;
}