x/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>


std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze){
	
	for(int i=0; i<fraze.size(); i++){
		
	}
	
	return recenica;
}

std::string PigLatin (std::string str, std::vector<std::string> rijeci){
	
	return str;
}

int main ()
{	
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::string temp;
	std::vector<std::string> vek;
	std::cout << "Unesite fraze: ";
	for(;;){
		std::getline(std::cin, temp);
		if(temp.size() == 0) break;
		vek.push_back(temp);
	}
	for(int i=0; i<vek.size(); i++){
		std::cout<<vek[i];
	}
	/*
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::string pig_string;
	pig_string = PigLatin(recenica, vek);
	std::cout << pig_string;
	
	std::cout << std::endl;
	std::string obrni_string;
	obrni_string = ObrniFraze(recenica,vek);
	std::cout << "Recenica nakon obrtanja fraza: ";
	std::cout << obrni_string;
	*/
	return 0;
}