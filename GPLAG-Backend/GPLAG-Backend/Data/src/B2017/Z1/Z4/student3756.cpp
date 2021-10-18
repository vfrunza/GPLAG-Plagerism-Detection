/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/



#include <iostream>
#include <string> 
#include <vector> 
int ImaLiRijeci(std::string recenica, std::string rijec){
	int i(0);
	while(i < recenica.size()){
		int j(0); 
		while(j < rijec.size() && i < recenica.size() && recenica.at(i) == rijec.at(j)){
			if(j == rijec.size()-1 && (i == recenica.size()-1 || (recenica.at(i+1) < 'A' || recenica.at(i+1) > 'Z' && recenica.at(i+1) < 'a' || recenica.at(i+1) > 'z'))) return i;  
			if(j == rijec.size()-1) break; 
			i++; 
			j++; 
		}
	if(i < recenica.size())	i++; 
	}
	return -1; 
}

std::string DajRijecNaopako(std::string rijec){
	std::string okrenuta; 
	for(int i = rijec.size()-1; i >= 0; i--){
		okrenuta.push_back(rijec.at(i)); 
	}
	return okrenuta; 
}


std::string PoluPal(std::string rijec){
	std::string novi; 
	novi.resize(rijec.size());
	int j(rijec.size()-1); 
	for(int i = 0; i <= rijec.size()/2; i++){
		
		novi.at(i) = rijec.at(i); 
		novi.at(j) = rijec.at(i); 
		j--; 
		if(j==i) break;
	}
	
	return novi; 
}


std::string NapraviPalindrom (std::string recenica, std::vector<std::string> spisak){
	for(int i = 0; i < spisak.size(); i++){
			int k(ImaLiRijeci(recenica, spisak.at(i))); 
			while (k != -1) {
			k = ImaLiRijeci(recenica, spisak.at(i)); 
			if(k == -1) break; 
		
			int velicina(recenica.size()-1); 
			recenica = recenica.substr(0, k+1) +  DajRijecNaopako(spisak.at(i)) + recenica.substr(k+1, velicina); 
	}
	}
	return recenica; 
} 



std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> spisak){
	for(int i = 0; i < spisak.size(); i++){
		int k(ImaLiRijeci(recenica, spisak.at(i)));
		while(k != -1){
		
		 	k = ImaLiRijeci(recenica, spisak.at(i)); 
		
		if(k == -1) break; 
		
		int velicina(recenica.size()-1); 
		std::string polupalindrom(PoluPal(spisak.at(i))); 
		recenica = recenica.substr(0, k+1-polupalindrom.size()) + polupalindrom + recenica.substr(k+1, velicina); 
		}	
	}
	return recenica; 
}




int main(){
	std::cout << "Unesite recenicu: "; 
	std::string recenica; 
	std::getline(std::cin, recenica); 
	std::cout << "Unesite fraze: "; 
	std::string rijec; 
	std::vector<std::string> spisak; 
	int i(0); 
	
	while(true){
		
		std::getline(std::cin, rijec); 
		if(rijec.size() == 0) break; 
		spisak.push_back(rijec);
		i++; 
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, spisak) << std::endl; 
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, spisak) << std::endl; 
	
	return 0; 
}


