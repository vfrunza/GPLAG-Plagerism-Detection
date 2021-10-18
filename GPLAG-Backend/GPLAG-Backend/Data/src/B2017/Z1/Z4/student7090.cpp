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

std::string NapraviPalindrom (std::string s, std::vector<std::string> vs)
{
	std::string s2, s3=s;
	std::vector<std::string> vs2(vs.size());

	//okrece stringove u vektoru
	for(int i=0; i<vs.size(); i++) {
		for(int j=vs.at(i).size()-1; j>=0; j--) {
			vs2.at(i).push_back(vs.at(i).at(j));
		}
	}

	//trazi iste rijeci u stringu
	for(int i=0; i<vs.size(); i++) {
		int br(0);
		while(br<s.size()) {
			if(s.at(br)==vs.at(i).at(0)) {
				std::string rijec;
				int br2(0);
				while(br+br2<s.size() && br2<vs.at(i).size()) {
					rijec.push_back(s.at(br+br2));
					br2++;
				}
				//pravi palindrom
				if(rijec==vs.at(i)) {
					if(br==s.size()-1) break;
					int ss=s.size();
					s2=s.substr(0, br+br2)+vs2.at(i)+s.substr(br+br2, ss);
					s=s2;
					br+=br2;
				}
			}
			br++;
		}
	}
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> vs)
{
	std::vector<std::string> vs2(vs.size()), vs3(vs.size());
	std::string s2;

	//polovi stringove u vektoru
	for(int i=0; i<vs.size(); i++) {
		if(vs.at(i).size()%2==0) {
			for(int j=0; j<=(vs.at(i).size()/2)-1; j++) {
				vs2.at(i).push_back(vs.at(i).at(j));
			}
		} else {
			for(int j=0; j<=(vs.at(i).size()/2); j++) {
				vs2.at(i).push_back(vs.at(i).at(j));
			}
		}
	}
	//okrece stringove u vektoru
	for(int i=0; i<vs2.size(); i++) {
		for(int j=vs2.at(i).size()-1; j>=0; j--) {
			vs3.at(i).push_back(vs2.at(i).at(j));
		}
	}


	//trazi iste rijeci u stringu
	for(int i=0; i<vs.size(); i++) {
		int br(0);
		while(br<s.size()) {
			if(s.at(br)==vs.at(i).at(0)) {
				std::string rijec;
				int br2(0);
				while(br+br2<s.size() && br2<vs.at(i).size()) {
					rijec.push_back(s.at(br+br2));
					br2++;
				}
				//pravi polupalindrom
				if(rijec==vs.at(i)) {
					if(br2<vs.at(i).size()) break;
					int sss(s.size()), ss(br+(vs.at(i).size()/2));
					s2=s.substr(0, ss)+vs3.at(i)+s.substr(br+br2, sss);
					s=s2;
					br+=br2;
				}
			}
			br++;
		}
	}
	return s;
}

int main ()
{
	std::string s,s1,s2,s3;
	std::vector<std::string> vs;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::getline(std::cin, s1);
		if(s1.size()==0) break;
		else vs.push_back(s1);
	}
	try {
		std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s, vs)<<std::endl;
		std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s, vs)<<std::endl;
	} catch(...) {
		std::cout<<"izuzetak"<<std::endl;
	}
	return 0;
}