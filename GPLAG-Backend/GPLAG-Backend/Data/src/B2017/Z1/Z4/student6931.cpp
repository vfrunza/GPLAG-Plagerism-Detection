#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> vektor;

std::string Izvrni(std::string s) {
	int duzina(s.length());
	std::string povratni;
	povratni.resize(duzina);
	int j(0);
	for(int i=s.length()-1; i>=0; i--) {
		povratni.at(j)=s.at(i);
		j++;
	}
	return povratni;
}

int NadjiString(std::string glavni, std::string nalaz) {
	bool flag(false);
	int pin(-1);
	for(int i=0; i<glavni.length(); i++) {
		if(glavni.at(i)==nalaz.at(0)) {
			for(int j=i; j<i+nalaz.length(); j++) {
				if(glavni.at(j)!=nalaz.at(j-i)) {
					flag=false;
					break;
				}
				else flag=true; 
			}
		}
		if(flag) {
			pin=i+nalaz.length();
			break;
		}
	}
	return pin;
}

std::string NapraviPalindrom(std::string s, vektor v) {
	std::string povratni(s);
	int n;
	for(int i=0; i<v.size(); i++) {
		n=NadjiString(s, v.at(i));
		if(n!=(-1)) {
			povratni.insert(n, Izvrni(v.at(i)));
		}
	}
	return povratni;
}

std::string NapraviPoluPalindrom(std::string s, vektor v) {
	std::string povratni(s);
	int n;
	for(int i=0; i<v.size(); i++) {
		n=NadjiString(s, v.at(i));
		if(n!=(-1)) {
			n-=v.at(i).length()/2;
			n=static_cast<unsigned int>(n);
			size_t t((v.at(i).length())/2);
			v.at(i).erase(v.at(i).begin(), t);
			povratni.erase(n, v.at(i).length()/2);
			povratni.insert(n, v.at(i));
		}
	}
	return povratni;
}


int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica, '\n');
	std::cin.ignore(100);
	vektor moj;
	std::cout<<"Unesite fraze: ";
	std::string pomocni;
	do {
		std::getline(std::cin, pomocni, '\n');
		std::cin.ignore(100);
		if(pomocni==std::string{'\n'}) break;
		moj.push_back(pomocni);
	} while(pomocni!=std::string{'\n'});
	pomocni=recenica;
	recenica=NapraviPalindrom(recenica, moj);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<recenica<<std::endl;
	pomocni=NapraviPoluPalindrom(pomocni, moj);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<pomocni<<std::endl;
	return 0;
}