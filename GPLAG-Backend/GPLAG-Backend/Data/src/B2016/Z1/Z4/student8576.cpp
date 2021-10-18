#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v) {
	for(int i=0; i<v.size(); i++) {
		int vel=v[i].length();
			for(int j=0; j<s.length(); j++) {
				if(s.substr(j,vel)==v[i]) {
					int k=j+vel-1;
					while(j<k) {
						char tmp=s[j];
						s[j]=s[k];
						s[k]=tmp;
						j++;
						k--;
					}
				}
			}
		}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v) {
	for(int i=0; i<v.size(); i++) {
		int vel=v[i].length();
		char tmp;
		for(int j=0; j<s.length(); j++) {
			if(s.substr(j,vel)==v[i]) {
				tmp=s[j];
				for(int k=0; k<vel; k++) {
					s[j]=s[j+1];
					j++;
				}
				j--;
				s[j]=tmp;
				j++;
		
			s.resize(s.length()+2);
			for(int m=s.length()-1; m>j; m--) 
				s[m]=s[m-2];
				
				s[j]='a';
				s[j+1]='y';
			}
		}
	}
	return s;
}

int main ()
{
	try{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	
	std::cout << "Unesite fraze: ";
	std::string rijec;
	for(;;) {
		std::getline(std::cin, rijec);
		if(rijec.length()==0) break;
		v.push_back(rijec);
		
	}

	std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,v) << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v) << std::endl;
	return 0;
	}
	catch(std::domain_error izuzetak)
    {
        std::cout << "Izuzetak: Nekorektan izbor rijeci" << izuzetak.what();
    }
}