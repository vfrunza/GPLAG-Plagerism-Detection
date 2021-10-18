#include <iostream>
#include <string>
#include <vector>

std::string NapraviPalindrom (std::string string, std::vector<std::string> fraze)
{
	int m;
	int k=0;
	for (int i=0; i<int(fraze.size()); i++) {
		for (int j=0; j<string.size(); j++) {
			if (fraze.at(i).at(0)==string.at(j) && j>0 && ((string.at(j-1)>='A' && string.at(j-1)<='Z') || (string.at(j-1)>='a' && string.at(j-1)<='z'))) continue;
			if (fraze.at(i).at(0)==string.at(j)) {
				if (fraze.at(i).size()>1)
					k=1;
				if (j+1<string.size()) j++;
				while (fraze.at(i).at(k)==string.at(j) && k<fraze.at(i).size() && j<string.size()) {
					k++;
					j++;
					if (j==string.size() && k<fraze.at(i).size()) break;
					if (k==fraze.at(i).size() && j<string.size() && ((string.at(j)>='A' && string.at(j)<='Z') || (string.at(j)>='a' && string.at(j)<='z'))) break;
					if (k==fraze.at(i).size()) {
						for(int z=0; z<int(fraze.at(i).size()); z++) {
							string.insert(string.begin()+j, fraze.at(i).at(z));
							m=z;
						}
						j+=fraze.at(i).length();
						if (m==int(fraze.at(i).size())-1) break;
					}
				}
			}
		}
	}
	return string;
}

std::string NapraviPoluPalindrom (std::string string, std::vector<std::string> fraze)
{
	int m;
	int k=0;
	for (int i=0; i<int(fraze.size()); i++) {
		for (int j=0; j<string.size(); j++) {
			if (fraze.at(i).at(0)==string.at(j) && j>0 && ((string.at(j-1)>='A' && string.at(j-1)<='Z') || (string.at(j-1)>='a' && string.at(j-1)<='z'))) continue;
			if (fraze.at(i).at(0)==string.at(j)) {
				if (fraze.at(i).size()>1)
					k=1;
				if (j+1<string.size()) j++;
				while (fraze.at(i).at(k)==string.at(j) && k<fraze.at(i).size() && j<string.size()) {
					k++;
					j++;
					if (j==string.size() && k<fraze.at(i).size()) break;
					if (k==fraze.at(i).size() && j<string.size() && ((string.at(j)>='A' && string.at(j)<='Z') || (string.at(j)>='a' && string.at(j)<='z'))) break;
					if (k==fraze.at(i).size()) {
						if(j<=int(string.length())) j--;
						j+=1-fraze.at(i).length()/2;
						for(int z=int(fraze.at(i).length())/2-1; z>=0; z--) {
							string.at(j)=fraze.at(i).at(z);
							m=z;
							if(j<int(string.length())-1) j++;
						}
						if (m==0) break;
					}
				}
			}
		}
	}
	return string;
}


int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	while (1) {
		std::string fraza;
		for(;;) {
			char c(std::cin.get());
			if (c=='\n') break;
			fraza.push_back(c);
		}
		if (fraza.size()==0) break;
		fraze.push_back(fraza);
	}
	if (fraze.size()==0) {
		std::cout<<"Recenica nakon Palindrom transformacije: ";
		std::cout<<recenica<<std::endl;
		std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
		std::cout<<recenica;
		return 0;
	} else {
		std::cout<<"Recenica nakon Palindrom transformacije: ";
		std::string palindrom;
		palindrom=NapraviPalindrom(recenica,fraze);
		std::cout<<palindrom<<std::endl;
		std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
		std::string polupalindrom;
		polupalindrom=NapraviPoluPalindrom(recenica,fraze);
		std::cout<<polupalindrom;
		return 0;
	}
}