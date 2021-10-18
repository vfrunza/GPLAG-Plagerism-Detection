
#include <iostream>
#include <vector>
#include <string>

bool provjera(char s){
	if((s>='A' && s<='Z') || (s>='a' && s<='z')) return false;
	return true;
}

void pronadji_dodaj(std::string &recenica, std::string rijec){
	int i(0),duzina(rijec.length());
	while(i<recenica.length()){
		
		if(i+duzina-1<recenica.length() && recenica.substr(i,duzina)==rijec && (i==0 || provjera(recenica.at(i-1))) && (i+duzina==recenica.length() || provjera(recenica.at(i+duzina)))){
			int j;
			i+=duzina;
			for(j=duzina-1;j>=0;j--){
				recenica.insert(recenica.begin()+i,rijec.at(j));
				i++;
			}
		i--;	
		}
	i++;	
	}
}

std:: string NapraviPalindrom(std::string recenica, std:: vector<std::string> rijeci){
	
	for(int i=0;i<rijeci.size();i++){
		pronadji_dodaj(recenica,rijeci.at(i));
	}
	return recenica;
}

void pronadj_polu(std::string &recenica, std::string rijec){
	int i(0), duzina(rijec.length());
	while(i<recenica.length()){
		if(i+duzina-1<recenica.length() && recenica.substr(i,duzina)==rijec && (i==0 || provjera(recenica.at(i-1))) && (i+duzina==recenica.length() || provjera(recenica.at(i+duzina)))){
			if(duzina%2!=0) {
				i+=(duzina/2)+1;}
			else i+=duzina/2;
			for(int j=duzina/2-1;j>=0;j--){
				recenica.at(i)=rijec.at(j);
				i++;
			}
			i--;
		}
		
	i++;	
	}
	
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> rijeci){
	for(int i=0;i<rijeci.size();i++){
		pronadj_polu(recenica,rijeci.at(i));
	}
	return recenica;
}


int main ()
{
	std::string recenica;
	std:: vector<std::string> rijeci;
	std:: string red;
	
	std:: cout<<"Unesite recenicu: ";
	std:: getline(std::cin, recenica);
	std:: cout<<"Unesite fraze: ";
	do{
		
		std:: getline(std::cin, red);
		if(red.size()) rijeci.push_back(red);
		
	} while(red.size());
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, rijeci)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,rijeci);
	return 0;
}