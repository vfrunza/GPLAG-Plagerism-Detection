#include <iostream>
#include <vector>

int main () {
	
	std::string recenica;
	std::vector<std::string> fraze;
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::cout<<"Unesite fraze: ";
	fraze.resize(1);
	int i{-1};
	do {
		i++;
		std::cin>>fraze[i];
		fraze.resize(fraze.size()+1);
	} while(fraze[i].size()!=0);
	
	
	return 0;
}