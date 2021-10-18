#include <iostream>
#include <string>


int main ()
{
	std::string s1;
	std::string s2;
	std::cout << "Unesite string: ";
	std::getline(std::cin,s1);
	std:: cout << std:: endl;
	s2=s1;
	std::string::reverse_iterator i;
	for(i=s1.rbegin();i!=s1.rend();++i){
		s2.push_back(*i);
	}
	

	std:: cout << s2 << std:: endl;
	return 0;
}