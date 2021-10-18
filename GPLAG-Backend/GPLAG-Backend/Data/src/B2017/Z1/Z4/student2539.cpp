#include <iostream>
#include <string>
#include <vector>

bool DaLiJeSlovo(char c){
	return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a');
}

int PronadjiRijec(std::string recenica, std::string rijec, int pocetak){
	for(int i = pocetak; i < recenica.length(); i++){
		if(recenica.at(i) == rijec.at(0)){
			if(recenica.substr(i,rijec.length()) == rijec) {
				bool prije(false), poslije(false);
				int broj = i+rijec.length();
				if(broj == recenica.length()) poslije = true;
				else if(broj < recenica.length()){
					if(!(DaLiJeSlovo(recenica.at(broj)))) poslije = true;	
				}
				if(i != 0) prije = !(DaLiJeSlovo(recenica.at(i-1)));
				else prije = true;
				if(prije && poslije) return i;
			}
		}
	}
	return -1;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> rijeci){
	for(int i = 0; i < rijeci.size(); i++){
		std::string rijec = rijeci.at(i);
		int poz = PronadjiRijec(recenica,rijec,0);
		while(poz != -1){
			int ostatak, nesto;
			nesto = poz + rijec.length();
			ostatak = recenica.length() - rijec.length() - poz;
			std::string pom;
			for(int j = 0; j < rijec.length(); j++){
				pom.push_back(rijec.at(rijec.length() - j - 1));
			}
			recenica = recenica.substr(0, poz) + rijec + pom + recenica.substr(nesto,ostatak);
			poz = PronadjiRijec(recenica,rijec,nesto);
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> rijeci){
	for(int i = 0; i < rijeci.size(); i++){
		std::string rijec = rijeci.at(i);
		std::string neka = rijec;
		int poz = PronadjiRijec(recenica,rijec,0);
		while(poz != -1){
			int ostatak, nesto;
			nesto = poz + rijec.length();
			ostatak = recenica.length() - rijec.length() - poz;
			std::string pom;
			for(int j = 0; j < rijec.length(); j++){
				pom.push_back(rijec.at(rijec.length() - j - 1));
			}
			neka = neka.substr(0,rijec.length()/2);
			pom = pom.substr(pom.length()/2 ,pom.length()/2 + 1);
			recenica = recenica.substr(0, poz) + neka + pom + recenica.substr(nesto,ostatak);
			poz = PronadjiRijec(recenica,rijec,nesto);
		}
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> rijeci;
	while(1){
		char slovo;
		std::string rijec;
		while(1){
			slovo=std::cin.get();
			if(slovo == '\n') break;
			rijec.push_back(slovo);
		}
		if(slovo == '\n' && rijec.length() == 0) break;
		rijeci.push_back(rijec);
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << NapraviPalindrom(recenica,rijeci)<< std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout <<  NapraviPoluPalindrom(recenica,rijeci)<< std::endl;
	return 0;
}


