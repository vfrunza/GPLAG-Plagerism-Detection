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

void obrniString(std::string &s){
	std::string novi = s;
	int vel = novi.size() -1;
	int i = 0;
	while(vel >= 0){
		s.at(i++) = novi.at(vel--);
	}
}

void dodajURecenicuObrnutiDrugi(std::string &s, std::string d, int pocetak, bool polu){
	
	std::string novi;
	
	if(!polu){
		obrniString(d);
		
		if(pocetak < s.size()){
			novi = s.substr(0,pocetak);
			novi+= d;
			novi+=s.substr(pocetak, s.size() - pocetak);
		}
		else {
			
			novi = s+d;
		}
	}
	else{
		if(pocetak < s.size()-1){
			novi = s.substr(0,pocetak); //std::cout << novi << std::endl;
			std::string tmp = d.substr(0, d.size()/2); //std::cout << tmp << std::endl;
			obrniString(tmp); //std::cout << tmp << std::endl;
			novi+= tmp; //std::cout << novi << std::endl;
			novi+= s.substr(pocetak+d.size()/2, s.size()); //std::cout << s.substr(pocetak+d.size()/2, s.size()) << std::endl;
		}
		else{
			novi = s.substr(0,s.size()-d.size()/2) + d.substr(0,d.size()/2);
			
		}
	}
	s = novi;
	
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	
	if(s.empty()) {s =""; return s;}
	for(int i = 0; i < v.size(); i++){
		if(s.size() < v.at(i).size()) continue;
		for(int j = 0; j < s.size() - v.at(i).size() +1; j++){
			if(j+v.at(i).size()+1 >= s.size() || s.at(j+v.at(i).size()) == ' ' || s.at(j+v.at(i).size()) == ',' || s.at(j+v.at(i).size()) == '.')
			if(s.substr(j,v.at(i).size()) == v.at(i)) dodajURecenicuObrnutiDrugi(s, v.at(i), j+v.at(i).size(), false);
		}
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){

	if(s.empty()){s=""; return s;}
	for(int i = 0; i < v.size(); i++){
		if(s.size() < v.at(i).size()) continue;
		for(int j = 0; j < s.size() - v.at(i).size() +1; j++){
			int vel = 0;
			if(v.at(i).size()%2 == 0) vel = v.at(i).size()/2;
			else vel = v.at(i).size()/2 +1;
			if(j+v.at(i).size() + 1 >= s.size() || s.at(j+v.at(i).size()) == ' ' || s.at(j+v.at(i).size()) == ',' || s.at(j+v.at(i).size()) == '.') 
			if(s.substr(j, v.at(i).size()) == v.at(i)) dodajURecenicuObrnutiDrugi(s, v.at(i), j+vel, true);
		}
	}
	return s;
}
int main ()
{
	std::string recenica; 
	std::vector<std::string> fraze;
	try{
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
	}
	catch(...){
		std::cout << "hjdsj";
	}
	return 0;
}