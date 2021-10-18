//B 2017/2018, Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>
#include <string>

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> spisak){
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			int k=0;
			if(j==0 || recenica.at(j-1) == ' ')
			while(k<spisak.at(i).size() && j+k<recenica.size() && recenica.at(j+k) == spisak.at(i).at(k)){
				
				k++;
			}
			if(k==spisak.at(i).size() && (j+k==recenica.size() || (recenica.at(j+k)<'A' || (recenica.at(j+k)>'Z' && recenica.at(j+k)<'a') || recenica.at(j+k)>'z'))){
				for(int z=k-1; z>=0; z--)	{
					recenica.insert(recenica.begin()+j+k, spisak.at(i).at(z));
					j++;
				}
				j+=k;
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> spisak){
	for(int i=0; i<spisak.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			int k=0;
			if(j==0 || recenica.at(j-1) == ' ')
			while(k<spisak.at(i).size() && j+k<recenica.size() && recenica.at(j+k) == spisak.at(i).at(k)){
				
				k++;
			}
			if(k==spisak.at(i).size() && (j+k==recenica.size() ||(recenica.at(j+k)<'A' || (recenica.at(j+k)>'Z' && recenica.at(j+k)<'a') || recenica.at(j+k)>'z'))){
				for(int z=0; z<(k)/2; z++)	{
					recenica.erase(recenica.begin()+j+(k+1)/2);
				}
				for(int z=(k)/2-1; z>=0; z--)	{
					recenica.insert(recenica.begin()+j+(k+1)/2, spisak.at(i).at(z));
					j++;
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;){
		std::string s;
		char znak;
		znak = std::cin.get();
		if(znak=='\n')break;
		while(znak!='\n'){
			s.push_back(znak);
			znak = std::cin.get();
		}
		fraze.push_back(s);
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout << NapraviPoluPalindrom(recenica, fraze) << std::endl;
	
	return 0;
}