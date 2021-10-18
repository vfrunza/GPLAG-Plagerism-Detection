#include <iostream>
#include <string>
#include <vector>

std::string Obrni(std::string s){
	std::string obrnut;
	for(int i(s.length()-1);i>=0;i--)
		obrnut.push_back(s.at(i));
	return obrnut;
}

std::string NapraviPalindrom(std::string Recenica,std::vector<std::string> Rijeci){
	for(int i(0);i<Rijeci.size();i++){
		std::string rijec(Rijeci.at(i));
		std::string ObrnutaRijec(Obrni(rijec));
		char znak(' ');
		char znak2(' ');
		Recenica.push_back(znak);
		for(int j(0);j<Recenica.length()-1;j++){
			if(rijec.length()+j<Recenica.length()){
				znak=Recenica.at(rijec.length()+j);
				if(j>0)
				znak2=Recenica.at(j-1);
			}
			std::string Podstring(Recenica.substr(j,rijec.size()));
			if(rijec==Podstring&&((znak<'A'||znak>'Z')&&(znak<'a'||znak>'z'))&&((znak2<'A'||znak2>'Z')&&(znak2<'a'||znak2>'z'))){
				Recenica.insert(j+rijec.size(),ObrnutaRijec);
				j=j+2*rijec.size();
			}
		}
	}
	Recenica.resize(Recenica.length());
	return Recenica;
}

std::string NapraviPoluPalindrom(std::string Recenica,std::vector<std::string> Rijeci){
	for(int i(0);i<Rijeci.size();i++){
		std::string rijec(Rijeci.at(i));
		char znak(' ');
		Recenica.push_back(znak);
		for(int j(0);j<Recenica.length()-1;j++){
			if(rijec.length()+j<Recenica.length())
				znak=Recenica.at(rijec.length()+j);
			std::string Podstring(Recenica.substr(j,rijec.size()));
			if(rijec==Podstring&&((znak<'A'||znak>'Z')&&(znak<'a'||znak>'z'))){
				int brojac(1);
				for(int k(j);k<j+rijec.length()/2;k++){
					Recenica.at(k+rijec.length()-brojac-(k-j))=rijec.at(k-j+brojac-1-(k-j));
					brojac++;
				}
				j=j+rijec.size();
			}
		}
	}
	Recenica.resize(Recenica.length());
	return Recenica;
}

int main ()
{	
	std::string Recenica,rijec;
	std::vector<std::string> Rijeci;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,Recenica);
	std::cout<<"Unesite fraze: ";
	while(1){
	std::getline(std::cin,rijec);
		if(rijec.length()==0)
			break;
		Rijeci.push_back(rijec);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::string Recenica2(Recenica);
	Recenica=NapraviPalindrom(Recenica,Rijeci);
	std::cout<<Recenica<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	Recenica2=NapraviPoluPalindrom(Recenica2,Rijeci);
	std::cout<<Recenica2;
	return 0;
}