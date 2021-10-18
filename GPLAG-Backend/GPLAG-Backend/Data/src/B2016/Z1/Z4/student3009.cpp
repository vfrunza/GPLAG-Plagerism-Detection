/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>

std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze) {
	std::string recenica_2(recenica);
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (recenica.substr(j, fraze[i].length())==fraze[i]) {
				//std::cout << fraze[i] << std::endl;
				/*int kraj (j+fraze[i].length());
				std::cout << "kraj: " << kraj << std::endl;
				for (int k=j; k<=kraj; k++) {
					recenica_2[k]=recenica[kraj-k];
					std::cout << "k: " << k << std::endl;
					std::cout << recenica[kraj-k] << std::endl;
				}*/
				std::string rijec(fraze[i]);
				for (int k=j; k<=rijec.length(); k++) {
					recenica_2[k]=rijec[rijec.length()-k-1+j];
				}
				j+=fraze[i].length();
			}
		}
		std::cout << recenica_2 << std::endl;
	}
	return recenica_2;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	getline(std::cin, recenica);
	//std::cout << recenica;
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string s;
	while (1) {
		getline(std::cin, s);
		fraze.push_back(s);
		if (std::cin.peek()=='\n') break;
	}
	/*for (int i=0; i<fraze.size(); i++) {
		std::cout << fraze[i] << std::endl;
	}*/ 
	std::cout << "Recenica nakon PigLatin transformacije: "<< std::endl;;
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
	//std::string s1(ObrniFraze(recenica, fraze));
	return 0;
}