/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze (std::string s, std::vector<std::string> v)
{

	for(int i(0); i<v.size(); i++) {
		std::string	s1(v.at(i));
		for(int j(0); j<s.length(); j++) {
			if(s1==s.substr(j, s1.length())) {
				int k;
				for (k=0; k<s1.length(); k++) {
					s.at(k+j)=s1.at(s1.length()-1-k);
					if(k==s1.length()-1) break;
				}
				j=k;

			}
			if(j==s.length()-1) break;

		}
		if(i==v.size()-1) break;
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{

	for(int i(0); i<v.size(); i++) {
		std::string s1(v.at(i));
		int j(0);
		while(j<s1.length()) {
			if(!((s1.at(j)>='A' && s1.at(j)<='Z') || (s1.at(j)>='a' && s1.at(j)<='z')))
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			j++;
		}
	}

	for(int i(0); i<v.size(); i++) {
		std::string	s1(v.at(i));
		for(int j(0); j<s.length(); j++) {
			if(s1==s.substr(j, s1.length())) {
				if(j!=0 && s.at(j-1)!=' ') continue;
				s.resize(s.length()+2);
				for(int k(j); k<j+s1.length()-1; k++) {
					std::swap(s.at(k),s.at(k+1));
					if(k==j+s1.length()-2) break;
				}
				for(int k(s.length()-1); k>=j+s1.length(); k--) {
					if(s.length()-j-s1.length()>2)
						std::swap(s.at(k), s.at(k-2));
					if(k==j+s1.length()+2) break;
				}
				s.at(j+s1.length())='a';
				s.at(j+s1.length()+1)='y';
				j=j+s1.length();
			}
			if(j==s.length()-1) break;
		}
		if(i==v.size()-1) break;

	}

	if(v.size()==0) {
		for(int i(0); i<s.length(); i++) {
			int j(i);
			while(s.at(j)!=' ') {
				j++;
				if(s.at(j)==' ' || j==s.length()-1) break;
			}

			s.resize(s.length()+2);
			for(int k(i); k<j; k++) {
				std::swap(s.at(k),s.at(k+1));
				if(k==j-2) break;
			}
			for(int k(s.length()-1); k>=j+2; k--) {
				if(j==s.length()-3) break;
				std::swap(s.at(k), s.at(k-2));

			}
			s.at(j)='a';
			s.at(j+1)='y';
			i=j+2;
			if(i==s.length()-1) break;
		}

	}

	return s;

}

int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> rijeci;
	std::cout<<"Unesite fraze: ";

	while(std::cin.peek()!='\n') {
		std::string fraza;
		std::getline(std::cin, fraza);
		rijeci.push_back(fraza);
		
	}
	
	try {
	    std::string s1(IzmijeniUPigLatin(recenica, rijeci));
	    std::cout<<"Recenica nakon PigLatin transformacije: "<<s1;

	}
		
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
		
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, rijeci);
	return 0;
}