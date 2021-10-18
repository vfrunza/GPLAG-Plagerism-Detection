#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::string RijecPolindrom (std::string s)
{
	std::string novi;

	for (int i(s.length()-1); i>=0; i--) {
		novi.push_back(s.at(i));
	}
	return novi;

}

std::string RijecPolupolindrom (std::string s)
{
	std::string novi;
	if (s.length()%2==0) {
		for (int i(0); i<(s.length()/2); i++) novi.push_back(s.at(i));
		for (int i(s.length()/2-1); i>=0; i--) novi.push_back(s.at(i));

	}

	if (s.length()%2!=0) {
		for (int i(0); i<=(s.length()/2); i++) novi.push_back(s.at(i));
		for (int i((s.length()/2-1)); i>=0; i--) novi.push_back(s.at(i));
	}
	return novi;
}

std::string NapraviPalindrom (std::string s, std::vector<std::string> v)
{
	if (s.length()==1 || s.length()==0) return "";
	s.push_back(' ');
	for(int i(0); i<v.size(); i++) {
		for (int j(0); j<s.length(); j++) {
			if (j==0 && j+v.at(i).size()<s.length()) {
				if ((v.at(i)==s.substr(j,v.at(i).size())) && (s.at(j+v.at(i).size())<'A' || s.at(j+v.at(i).size())>'Z') && (s.at(j+v.at(i).size())<'a' || s.at(j+v.at(i).size())>'z')) {

					s.insert(j+v.at(i).size(), RijecPolindrom(v.at(i)));
					j +=v.at(i).size();
				}
			} else if (j==s.length()-1) {
				if ((v.at(i))==s.substr(j-v.at(i).size(),v.at(i).size() ) && (s.at(j-v.at(i).size())<'A' || s.at(j-v.at(i).size())>'Z') && (s.at(j-v.at(i).size())<'a' || s.at(j-v.at(i).size()>'z'))) {
					s.insert(j-v.at(i).size(), RijecPolindrom(v.at(i)));
					std::cout << s.substr(j-v.at(i).size(),v.at(i).size() ) << std::endl;
				}
			} else if (j+v.at(i).size()<s.length()) {

				if ((v.at(i)==s.substr(j,v.at(i).size())) && (s.at(j+v.at(i).size())<'A' || (s.at(j+v.at(i).size())>'Z' && s.at(j+v.at(i).size())<'a') || s.at(j+v.at(i).size())>'z' || j+v.at(i).size()==s.length() )) {
					s.insert(j+v.at(i).size(), RijecPolindrom(v.at(i)));
					j +=v.at(i).size();

				}

			}

		}
	}
	s.erase(s.length()-1);
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v)
{
	if (s.length()==1 || s.length()==0) return "";
	s.push_back(' ');
	for (int i(0); i<v.size	(); i++) {
		for (int j(0); j<s.length(); j++) {
			if (j==0 && j+v.at(i).size()<s.length()) {
				if ((v.at(i)==s.substr(j,v.at(i).size())) && (s.at(j+v.at(i).size())<'A'  || (s.at(j+v.at(i).size())>'Z' && s.at(j+v.at(i).size()) <'a')  ||  s.at(j+v.at(i).size())>'z' )) {
					s.insert(j, RijecPolupolindrom(v.at(i)));
					s.erase(j+RijecPolupolindrom(v.at(i)).size(), v.at(i).size());
					j += RijecPolupolindrom(v.at(i)).size();
				}
			} else if (j==s.length()-1) {
				if ((v.at(i))==s.substr(j-v.at(i).size(), v.at(i).size())  && (s.at(j-v.at(i).size())<'A' || (s.at(j-v.at(i).size())>'Z' && s.at(j-v.at(i).size()<'a')) || s.at(j-v.at(i).size())>'z' )) {
				
					s.insert(j-RijecPolupolindrom(v.at(i)).size(), RijecPolupolindrom(v.at(i)));
					s.erase(j-RijecPolupolindrom(v.at(i)).size(), v.at(i).size());
					j+=RijecPolupolindrom(v.at(i)).size();
				}
			} else if (j+v.at(i).size()<s.length()) {
				if ((v.at(i)==s.substr(j, v.at(i).size())) && ((s.at(j+v.at(i).size()) <'A' || (s.at(j+v.at(i).size())>'Z' && s.at(j+v.at(i).size())<'a') || s.at(j+v.at(i).size())>'z' || j+v.at(i).size()==s.length())) && (s.at(j-1)<'A' || (s.at(j-1)>'Z' && s.at(j-1)<'a') || s.at(j-1)>'z' )) {
					s.insert(j, RijecPolupolindrom(v.at(i)));
					s.erase(j+RijecPolupolindrom(v.at(i)).size(), v.at(i).size());
					j+=RijecPolupolindrom(v.at(i)).size();
				}
			}
		}
	}
	s.erase(s.length()-1);
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline (std::cin, s);

	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for (;;) {
		std::string fraza;
		std::getline (std::cin, fraza);
		if(fraza=="") break;
		else fraze.push_back(fraza);
	}
	std::cout<< "Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s, fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<< NapraviPoluPalindrom(s,fraze)<<std::endl;
	return 0;
}