#include <iostream>
#include <string>
#include <vector>

bool jeLiSlovo(char c)
{
	if((c>='A' && c<='Z') || (c>='A' && c<='Z'))return false;
	return true;
}

std::string izvrni(std::string fraza)
{
	std::string rijec;
	for(int i=fraza.length()-1; i>=0; i--) {
		rijec.push_back(fraza.at(i));
	}
	return rijec;
}

std::string NapraviPalindrom(std::string s,std::vector<std::string> spisak)
{
	for(int i(0); i<spisak.size(); i++) {
		for(int j(0); j<s.length(); j++) {
			if(spisak.at(i).at(0)==s.at(j)) {
				if(j==0) {
						if(spisak.at(i)==s.substr(j,spisak.at(i).length())  && jeLiSlovo(s.at(j+spisak.at(j+1).size()))) {
							std::string word=izvrni(spisak.at(i));
							s.insert(j+spisak.at(i).length(),word);
						}
				} else if(jeLiSlovo(s.at(j-1))  && j==s.length()-spisak.at(i).size()) {
					std::string word=izvrni(spisak.at(i));
					s.insert(j+spisak.at(i).length(),word);
				}
				else if(spisak.at(i)==s.substr(j,spisak.at(i).length()) &&  jeLiSlovo(s.at(j-1))  && jeLiSlovo(s.at(j+spisak.at(i).size()+1))) {
					std::string word=izvrni(spisak.at(i));
					s.insert(j+spisak.at(i).length(),word);
				}
			}

		}
	}
	return s;
}

std::string izvrniPola(std::string rijec){
	
}

std::string NapraviPoluPalindrom(std::string s,std::vector<std::string> fraze){
for(int i(0); i<spisak.size(); i++) {
		for(int j(0); j<s.length(); j++) {
			if(spisak.at(i).at(0)==s.at(j)) {
				if(j==0) {
						if(spisak.at(i)==s.substr(j,spisak.at(i).length())  && jeLiSlovo(s.at(j+spisak.at(j+1).size()))) {
							std::string word=izvrni(spisak.at(i));
							s.insert(j+spisak.at(i).length(),word);
						}
				} else if(jeLiSlovo(s.at(j-1))  && j==s.length()-spisak.at(i).size()) {
					std::string word=izvrni(spisak.at(i));
					s.insert(j+spisak.at(i).length(),word);
				}
				else if(spisak.at(i)==s.substr(j,spisak.at(i).length()) &&  jeLiSlovo(s.at(j-1))  && jeLiSlovo(s.at(j+spisak.at(i).size()+1))) {
					std::string word=izvrni(spisak.at(i));
					s.insert(j+spisak.at(i).length(),word);
				}
			}

		}
	}
	return s;
}



int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::vector<std::string> zbirkaFraza;
	std::cout<<"Unesite fraze: ";
	int counter(0);
	for(;;) {
		std::string uzorak;
		std::getline(std::cin,uzorak);
		zbirkaFraza.push_back(uzorak);
		if(zbirkaFraza.at(counter).size()==0) {
			zbirkaFraza.erase(zbirkaFraza.begin()+counter+1);
			break;
		}
		counter++;
	}
	std::string Palindrom,halfPalindrom;
	Palindrom=NapraviPalindrom(recenica,zbirkaFraza);
	halfPalindrom=NapraviPolupalindrom(recenica,zbirkaFraza);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<Palindrom<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<halfPalindrom<<std::endl;
	return 0;
}