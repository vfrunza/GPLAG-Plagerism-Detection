#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string> rijeci){
	std::string pom;
	bool uslov;
	for(int i = 0; i < rijeci.size(); i++){
		pom = rijeci[i];
		for(int j = 0; j < recenica.length(); j++){
			if(recenica[j] == pom[0]){
				uslov = true;
				for(int k = 0; k < pom.length(); k++){
					if(recenica[j+k] != pom[k]) {
						uslov = false;
						break;
					}
				}
				if(uslov){
					for(int k = 0; k < pom.length(); k++) recenica[j+k] = pom[pom.length()-1-k];
				}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci){
	std::string pom;
	for(int i = 0; i < rijeci.size(); i++){
		pom = rijeci[i];
		for(int j = 0; j < pom.length(); j++){
			if(!((pom[j]>='a' && pom[j]<='z') || (pom[j]>='A' && pom[j]<='Z'))){
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	if(rijeci.size() == 0){
		for(int i = 0; i < recenica.length(); i++){
			std::string rijec;
			if(((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z'))){
				while(recenica[i]!=' '){
					rijec.push_back(recenica[i]);
					i++;
					if(i==recenica.length()) break;
				}
				rijeci.push_back(rijec);
			}
		}
	}
	bool uslov;
	for(int i = 0; i < rijeci.size(); i++){
		pom = rijeci[i];
		for(int j = 0; j < recenica.length(); j++){
			if(recenica[j] == pom[0] && (j==0 || recenica[j-1]==' ')){
				uslov = true;
				for(int k = 0; k < pom.length(); k++){
					if(recenica[j+k] != pom[k]) {
						uslov = false;
						break;
					}
				}
				if((j+pom.length()<recenica.length()) && recenica[j+pom.length()] != ' ') uslov = false;
				if(uslov){
					for(int k = 1; k < pom.length(); k++) recenica[j+k-1] = pom[k];
					recenica[j+pom.length()-1] = pom[0];
					recenica.insert(recenica.begin()+j+pom.length(),'a');
					recenica.insert(recenica.begin()+j+pom.length()+1,'y');
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string> v;
	std::string pom;
	std::cout << "Unesite fraze: ";
	while(true){
		std::getline(std::cin,pom);
		if(pom.length() == 0) break;
		v.push_back(pom);
	}
	try{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,v);
	}
	catch(std::domain_error izuzetak){
			std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout << std::endl << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,v);
	return 0;
}