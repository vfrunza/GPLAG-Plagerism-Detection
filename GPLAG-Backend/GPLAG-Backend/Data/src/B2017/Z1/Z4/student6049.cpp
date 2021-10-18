#include<iostream>
#include<vector>
#include<string>
int PronadjiFrazu(std::string recenica, std::string fraza) {
	int i(0);
	for(int j(0); j<recenica.size(); j++) {
		int pocetak(j);
		std::string pomocna;
		if(recenica.at(j)==fraza.at(i)) {
			while(recenica.at(j)==fraza.at(i)) {
				pomocna.push_back(recenica.at(j));
				j++;
				i++;
				if(i==fraza.size()) break;
				if(j==recenica.size()) return -1;
			}
			while(j<recenica.size()) { 
				if((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a' && recenica.at(j)<='z')) pomocna.push_back(recenica.at(j));
				else break;
				j++;
			}
		    if(pomocna==fraza) return pocetak;
		}
		i=0;
	}
	return -1;
}
std::string NapraviPalindrom(std::string recenica, std::vector<std::string> v) {
	for(int i(0); i<v.size(); i++) {
		std::string rijec(v.at(i));
		int ima;
		do {
			ima=PronadjiFrazu(recenica,rijec);
			if(ima!=-1) {
				int j(ima),vel(rijec.size());
				for(int k(rijec.size()-1); k>=0; k--) {
					recenica.insert(recenica.begin()+j+vel,rijec.at(k));
					j++;
				}
			}
		} while (ima!=-1);
	}
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> v) {
	for(int i(0); i<v.size(); i++) {
		std::string rijec(v.at(i));
		int ima;
		do {
			ima=PronadjiFrazu(recenica,rijec);
			if(ima!=-1) {
				int j(ima),vel(rijec.size()/2),sredina(rijec.size()/2);
				if(rijec.size()%2==0) sredina--;
				for(int k(sredina); k>=0; k--) {
					recenica.at(j+vel)=rijec.at(k);
					j++;
				}
			}
		} while (ima!=-1);
	}
	return recenica;
}

int main () {
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	std::string s;
	for(;;) {
		std::getline(std::cin,s);
		if(s.size()!=0) v.push_back(s);
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,v)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,v);
	return 0;
}