#include <iostream>
#include <string>
#include <vector>

std::string okreniString(std::string ulazniString) {
	std::string izlazniString = "";
	for(int i = ulazniString.size() - 1; i >= 0; i--) {
		izlazniString += ulazniString.at(i);
	}
	return izlazniString;
}
std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vektorStringova) {
	int index = 0;
	std::string povratniString = "";
	while(index < recenica.size()) {
		bool nadjen = false;
		for(int i = 0; i < vektorStringova.size(); i++) {
			if(!(index + vektorStringova.at(i).size() > recenica.size())) {
				if(recenica.substr(index, vektorStringova.at(i).size()) == vektorStringova.at(i)) {
					if(recenica.size() == vektorStringova.at(i).size()) {
						povratniString += vektorStringova.at(i) + okreniString(vektorStringova.at(i));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					} else if((index == 0) && (recenica[vektorStringova[i].size()] == ' ' || recenica[vektorStringova[i].size()] == ',' || recenica[vektorStringova[i].size()] == '.')) {
						povratniString += vektorStringova.at(i) + okreniString(vektorStringova.at(i));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					} else if((index + vektorStringova.at(i).size() == recenica.size()) && (recenica[index - 1] == ' ' || recenica[index - 1] == '.' || recenica[index - 1] == ',')) {
						povratniString += vektorStringova.at(i) + okreniString(vektorStringova.at(i));
						index = recenica.size();
						nadjen = true;
					} else if ((recenica[index - 1] == ' ' || recenica[index - 1] == '.' || recenica[index - 1] == ',') && (recenica[index + vektorStringova.at(i).size()] == ' ' || recenica[index + vektorStringova.at(i).size()] == '.' || recenica[index + vektorStringova.at(i).size()] == ',')){
						povratniString += vektorStringova.at(i) + okreniString(vektorStringova.at(i));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					}
				}
			}
		}
		if(!nadjen) {
			povratniString += recenica.at(index++);
		} 
	}
	return povratniString;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vektorStringova) {
	int index = 0;
	std::string povratniString = "";
	while(index < recenica.size()) {
		bool nadjen = false;
		for(int i = 0; i < vektorStringova.size(); i++) {
			if(!(index + vektorStringova.at(i).size() > recenica.size())) {
				if(recenica.substr(index, vektorStringova.at(i).size()) == vektorStringova.at(i)) {
					if(recenica.size() == vektorStringova.at(i).size()) {
						povratniString += vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2 + vektorStringova.at(i).size()%2) + okreniString(vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					} else if((index == 0) && (recenica[vektorStringova[i].size()] == ' ' || recenica[vektorStringova[i].size()] == ',' || recenica[vektorStringova[i].size()] == '.')) {
						povratniString += vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2 + vektorStringova.at(i).size()%2) + okreniString(vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					} else if((index + vektorStringova.at(i).size() == recenica.size()) && (recenica[index - 1] == ' ' || recenica[index - 1] == '.' || recenica[index - 1] == ',')) {
						povratniString += vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2 + vektorStringova.at(i).size()%2) + okreniString(vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2));
						index = recenica.size();
						nadjen = true;
					} else if ((recenica[index - 1] == ' ' || recenica[index - 1] == '.' || recenica[index - 1] == ',') && (recenica[index + vektorStringova.at(i).size()] == ' ' || recenica[index + vektorStringova.at(i).size()] == '.' || recenica[index + vektorStringova.at(i).size()] == ',')){
						povratniString += vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2 + vektorStringova.at(i).size()%2) + okreniString(vektorStringova.at(i).substr(0, vektorStringova.at(i).size()/2));
						index = index + vektorStringova.at(i).size();
						nadjen = true;
					}
				}
			}
		}
		if(!nadjen) {
			povratniString += recenica.at(index++);
		} 
	} 
	return povratniString;
}

int main ()
{
	std::string recenica; 
	std::vector<std::string> fraze;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::cout << "Unesite fraze: ";
	while(std::cin.peek() != '\n'){
		std::string fraza;
		std::getline(std::cin,fraza);
		fraze.push_back(fraza);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica,fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica,fraze) ;
	return 0;
}