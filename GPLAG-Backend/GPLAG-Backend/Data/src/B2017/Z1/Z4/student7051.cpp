#include <iostream>
#include <string>
#include <vector>
std::string NapraviPalindrom(std::string s, std::vector<std::string> v)
{
	for (int j=0; j<v.size(); j++) {
		int brojac(0);
		for (int i=0; i<s.length()-1; i++) {
			std::string rijec(v.at(j));
			if (s[i]==rijec.at(brojac)){
				while (s[i]==rijec.at(brojac) && brojac<=v.size() ){
					brojac++;
					i++;
				}
				
				
			}
		}
	}
	return s;
}

int main ()
{
	std::string s{"dan danas dan Dan dan danas"};
std::vector<std::string> v{"dan"};

std::cout << NapraviPalindrom(s,v) << std::endl;

	return 0;
}