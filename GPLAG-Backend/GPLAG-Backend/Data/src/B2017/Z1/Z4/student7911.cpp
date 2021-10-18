#include <iostream>
#include <vector>
#include <string>


std::string Obrni(std::string s){
	std::string novi;
	if(s.size()==1)
		return s;
	for(int i = s.length()-1; i >= 0; i--){
		novi.push_back(s.at(i));
	}
	return novi;
}


std::string NapraviPalindrom(std::string s, std::vector<std::string> rijec){
	s.push_back(' ');
	for(int i = 0; i<rijec.size(); i++){
		for(int j = 1; j<s.length()-1; j++){
			int k(1);
			if( k<rijec.at(i).length() && s.at(j) == rijec.at(i).at(k) && s.at(j-1) ==rijec.at(i).at(k-1)){
				int brojac(0);
				while(j<s.length()&& k<rijec.at(i).length() && s.at(j) == rijec.at(i).at(k)){ 
					j++; k++; brojac++;
 							}
			 if( k==rijec.at(i).length()&&((s.at(j)<'A'||s.at(j)>'Z')&&(s.at(j)<'a'||s.at(j)>'z'))) s.insert(j,Obrni(rijec.at(i)));
			}
		}
	}
	s.resize(s.length());
	return s;
}


std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> rijec) {
	s.push_back(' ');
	for(int i = 0; i < rijec.size(); i++) {
		for(int j = 1; j < s.length(); j++) {
			int k(1);
			while(k < rijec.at(i).length() && j < s.length() && rijec.at(i).at(k) == s.at(j) && rijec.at(i).at(k-1) == s.at(j-1)) {
				k++; j++;
			}
			if(k== rijec.at(i).length()&&((s.at(j)<'A'||s.at(j)>'Z')&&(s.at(j)<'a'||s.at(j)>'z'))) {
				int brojac = j-k;
				int brojac2 = j-1;
				while(brojac <= brojac2) {
					s.at(brojac2) = s.at(brojac);
					brojac2--; brojac++;
				}
			}
		}
	}
	
	
	s.resize(s.length());
	return s;
}



int main ()
{
	std::string s,fraza;
	std::vector<std::string> rijec;

	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	for(;;){
	std::getline(std::cin,fraza);
	if(fraza.length() == 0)  break;
	rijec.push_back(fraza);
	}
	std::string novi = s;
	s = NapraviPalindrom(s,rijec);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	for(int i = 0; i<s.length(); i++){
		std::cout << s.at(i);
	}
	std::cout<<std::endl;
	s= NapraviPoluPalindrom(novi,rijec);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	for(int i = 0; i<novi.length(); i++){
		std::cout << s.at(i);
	}
	return 0;
}
