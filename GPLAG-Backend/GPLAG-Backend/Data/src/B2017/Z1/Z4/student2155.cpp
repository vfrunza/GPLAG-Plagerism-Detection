#include <iostream>
#include <string>
#include <vector>

bool DaLiJeSlovo (char c){
	if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
	return false;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string>v)
{
	int temp=0;
	int brojac=0;
	for(int j=0; j<v.size(); j++) {
		for(int i=0; i<s.length(); i++) {
			for(int k=0; k<v.at(j).length(); k++) {
				if(k<v.at(j).length() && i<s.length() && v.at(j).at(k)==s.at(i)) {
					temp=i;
					brojac=0;
					while(i<s.length() && k<v.at(j).length() && v.at(j).at(k)==s.at(i)) {
						k++;
						i++;
						++brojac;
					}
					i--;
					k--;
				}
				if((temp==0 || s.at(temp-1)==' ' || DaLiJeSlovo(s.at(temp-1))==false) && (i==s.length()-1 || s.at(i+1)==' ' || DaLiJeSlovo(s.at(i+1))==false) && brojac==v.at(j).size()) {
					for(int l=0; l<v.at(j).length(); l++) {
						s.insert(s.begin()+i+1,v.at(j).at(l));
					}
				}
			}
		}
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string>v)
{
	int brojac(0);
	int temp(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			for(int k=0; k<v.at(i).length(); k++) {

				if(k<v.at(i).length() && j<s.length() && v.at(i).at(k)==s.at(j)) {
					temp=j;
					brojac=0;
					while(j<s.length() && k<v.at(i).length() &&v.at(i).at(k)==s.at(j)) {
						k++;
						j++;
						brojac++;
					}
					j--;
					k--;
					if((temp==0 || s.at(temp-1)==' ' || DaLiJeSlovo(s.at(temp-1))==false) && (j==s.length()-1 || s.at(j+1)==' '  || DaLiJeSlovo(s.at(j+1))==false) && (brojac==v.at(i).length())) {
						for(int l=0; l<v.at(i).length(); l++) {
							s.at(temp+v.at(i).length()-1-l)=s.at(temp+l);
						}
					}
		
				}
			}
		}
	}
	return s;
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string>fraze;
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::string s;
		std::getline(std::cin,s);
		if(s.length()==0) break;
		fraze.push_back(s);
	}
	std::string string1;
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	string1=NapraviPalindrom(recenica,fraze);
	std::cout<<string1<<std::endl;

	std::string string2;
	string2=NapraviPoluPalindrom(recenica,fraze);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<string2;
	return 0;
}