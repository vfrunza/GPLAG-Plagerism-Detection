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

std::string NapraviPalindrom(std::string s, std::vector<std::string> v) {
	for(std::string s1 : v) {
		int i(0), j(0);
		while(i<s.length() && j<s1.length()) {
			if(s.at(i)==s1.at(j)) {
				i++;
				j++;
			}
			else {
				i++;
				j=0;
			}
		
		if(j==s1.length()) {
			std::string s2;
			bool pocetak(true);
			bool kraj(true);
			if(i!=s.length() && ((s.at(i+1)>='a' && s.at(i+1)<='z') || (s.at(i+1)>='A' && s.at(i+1)<='Z')) && s.at(i)!=' ') kraj=false;
			if((i-j)!=0 && ((s.at(i-j-1)>='a' && s.at(i-j-1)<='z') || (s.at(i-j-1)>='A' && s.at(i-j-1)<='Z')) && s.at(i)!=' ') pocetak=false;
			if(kraj==true && pocetak==true) {
			for(int i=s1.length()-1; i>=0; i--) s2.push_back(s1.at(i));
			s = s.substr(0, i) + s2 + s.substr(i, s.length()-i);
			}
			j=0;
		}
		}
		
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v) {
	for(std::string s1 : v) {
		int i(0), j(0);
		while(i<s.length() && j<s1.length()) {
			if(s.at(i)==s1.at(j)) {
				i++;
				j++;
			}
			else {
				i++;
				j=0;
		}
		
		if(j==s1.length()) {
			std::string s2;
			bool pocetak(true);
			bool kraj(true);
			if(i!=s.length() && ((s.at(i+1)>='a' && s.at(i+1)<='z') || (s.at(i+1)>='A' && s.at(i+1)<='Z')) && s.at(i)!=' ') kraj=false;
			if((i-j)!=0 && ((s.at(i-j-1)>='a' && s.at(i-j-1)<='z') || (s.at(i-j-1)>='A' && s.at(i-j-1)<='Z')) && s.at(i)!=' ') pocetak=false;
			if(pocetak==true && kraj==true) {
			for(int i=s1.length()/2-1; i>=0; i--) s2.push_back(s1.at(i));
			s = s.substr(0, i-s1.length()/2) + s2 + s.substr(i, s.length()-1);
			}
			
			j=0;
		}
		}
		
	}
	return s;
}




int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	std::string s;
	while(std::cin.peek()!='\n') {
		std::cin>>s;
		v.push_back(s);
		std::cin.ignore(10000, '\n');
	}
	std::string s1(NapraviPalindrom(recenica,v));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<s1<<std::endl;
	std::string s2(NapraviPoluPalindrom(recenica,v));
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<s2;
	std::cout<<std::endl;

	
	
	return 0;
}