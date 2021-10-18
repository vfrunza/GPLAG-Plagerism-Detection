#include <iostream>
#include <string>
#include <vector>


int NadjiFrazu (std::string recenica, std::string fraze, int n=0) {
	int brojac(0),rezultat(-1);
	if(n >= recenica.length()) return rezultat; //
	for(int i=n; i<recenica.length(); i++) {
    
 
		if(recenica.at(i)==fraze.at(brojac)) {
			if(brojac==0 && i!=0 && isalpha(recenica.at(i-1))) {
			   brojac=0;
			   continue;
			}
			   if(brojac==0)
				rezultat=i;
			brojac++;
		
			if(brojac == fraze.length()) {
				if(i!=recenica.length()-1 && isalpha(recenica.at(i+1))) {
					brojac=0;
					continue;
				}
				return rezultat;
			}

		} else {
			brojac=0;
		}

	}
	return -1;
}


std::string ObrniString(std::string fraze) {
	std::string novi("");
	for(int i=fraze.length()-1; i>=0; i--) {

		novi+=fraze.at(i);
	}
	return novi;
}



std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze) {

	for(auto x : fraze) {
		std::string s1, s2;

		int n = NadjiFrazu(recenica, x, 0); //nalazi mjesto gdje zavrsava nadjena fraza

		while(true) {

			if(n < 0) break; //naravno, ukoliko je to mjesto <0 nema ga
			s1=recenica.substr(0, n+x.length());
			s2=recenica.substr(n+x.length(), recenica.length());

			recenica = s1 + ObrniString(x) + s2;
			n = NadjiFrazu(recenica,x, n+x.length());
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze) {
	for(auto x : fraze) {
		std::string s1, s2,s3,pom;
		int n = NadjiFrazu(recenica, x, 0);

		while(true) {
			if(n < 0) break;

			if(x.length()%2==0) {
				s1=recenica.substr(0, n+x.length()/2);
			} else s1=recenica.substr(0, (n+x.length()/2)+1);


			if(x.length()%2==0) {
				s2=recenica.substr(n+ x.length(), recenica.length());
			} else s2=recenica.substr((n+x.length()), recenica.length());


			pom=ObrniString(x);
			if(pom.length()%2==0) {
				s3=pom.substr(pom.length()/2, pom.length());
			} else s3=pom.substr((pom.length()/2)+1, pom.length());


			recenica = s1 + s3 + s2;
			n = NadjiFrazu(recenica, x, n+x.length());

		}
	}
	return recenica;
}



int main () {

	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin, recenica);



	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze ;
	std::string fraza;


	while(1) {
		char prvi;
		prvi=std::cin.peek();
		if(prvi=='\n')
			break;
		std::getline(std::cin, fraza);
		fraze.push_back(fraza);
	}


	std::string Palindrom;
	Palindrom = NapraviPalindrom(recenica,fraze);

	std::string PoluPalindrom;
	PoluPalindrom = NapraviPoluPalindrom(recenica,fraze);


	std::cout << "Recenica nakon Palindrom transformacije: " << Palindrom <<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << PoluPalindrom;

	/*std::string recenica {"danas je lijep i suncan dan"};
	std::vector<std::string> fraze {"lijep","dan"};
	std::cout << NapraviPoluPalindrom(recenica,fraze);*/

	return 0;
}
