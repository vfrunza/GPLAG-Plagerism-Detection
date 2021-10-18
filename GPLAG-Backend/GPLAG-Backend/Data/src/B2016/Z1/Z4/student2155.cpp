#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
bool DaLiJeSlovo(char s){
	return ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'));
}
bool ValidanSpisak(std::vector<std::string> s){
	
	for(auto x : s){
		for(auto y : x){
			if(!DaLiJeSlovo(y)) return false;
		}
	}
	
	return true;
}
std::string ObrniFraze(std::string recenica,std::vector<std::string> s){

	for(auto fraza : s){
		for(int i(0);i < recenica.length();i++){
			
			if(fraza.length() && i + fraza.length() <= recenica.length() && (recenica.substr(i,fraza.length()) == fraza)){
				int tmp(i);
				for(int j(fraza.length()-1);j >= 0;j--){
					recenica[i] = fraza[j];
					i++;
				}
				i = tmp;
				
			}
			
		}
	}

	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> spisak_rijeci){
	std::string piglatin;
	int i(0);
	if(!ValidanSpisak(spisak_rijeci)){
		throw std::domain_error("Nekorektan izbor rijeci");
	}
	if(!spisak_rijeci.size() || (spisak_rijeci.size() == 1 && !spisak_rijeci[0].size())){
		while(i < recenica.length()){
			while(i < recenica.length() && !DaLiJeSlovo(recenica[i])){
				piglatin.push_back(recenica[i]);
				i++;
			}
			if(DaLiJeSlovo(recenica[i])){
				int tmp(i);
				i++;
			
				while(i < recenica.length() && DaLiJeSlovo(recenica[i])){
				piglatin.push_back(recenica[i]);
				i++;
				}
				piglatin.push_back(recenica[tmp]);
				piglatin.push_back('a');
				piglatin.push_back('y');
			}else piglatin.push_back(recenica[i++]);
		}
		return piglatin;
	}
	while(i < recenica.length()){
		while(i < recenica.length() && !DaLiJeSlovo(recenica[i])){
			piglatin.push_back(recenica[i]);
			i++;
		}
		for(auto fraza : spisak_rijeci){
			if(fraza.length() && (i+fraza.length()==recenica.length() || (i+fraza.length() < recenica.length() && !DaLiJeSlovo(recenica[i+fraza.length()]))) && fraza==recenica.substr(i,fraza.length())){
			int tmp(i);
			i++;
			
			while(i < tmp + fraza.length()){
				piglatin.push_back(recenica[i]);
				i++;
			}
			piglatin.push_back(recenica[tmp]);
			piglatin+="ay";
			break;
			}
		
		}
		while(i < recenica.length() && DaLiJeSlovo(recenica[i])){
			piglatin.push_back(recenica[i++]);
		}
	}
		
	
	
	
	return piglatin;
}
int main ()
{
std::string s;
std::string x;
std::vector<std::string> vektor;
std::cout << "Unesite recenicu: ";
std::getline(std::cin,s);
std::cout << "Unesite fraze: ";
for(;;){
	
	std::getline(std::cin,x);
	vektor.push_back(x);
	if(std::cin.peek() == '\n') break;
	
}
try{
	auto s1(IzmijeniUPigLatin(s,vektor));
	std::cout << "Recenica nakon PigLatin transformacije: " << s1;
}
catch(std::domain_error izuzetak){
	std::cout << "Izuzetak: " << izuzetak.what();
}
	std::cout << "\nRecenica nakon obrtanja fraza: " << ObrniFraze(s,vektor);

	return 0;
}