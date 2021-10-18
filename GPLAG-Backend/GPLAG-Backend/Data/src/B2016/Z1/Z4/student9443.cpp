/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	for(std::string i:fraze){
		int j{0}, k{0};
		while(j < recenica.length() && k < i.length()){
			if(recenica.at(j) == i.at(k)){
				k++;
				if(k==i.length()){
					k--;
					int g{k}, h{j-k};
					while(h<=j && g>=0){
						recenica.at(h)=i.at(g);
						g--;
						h++;
					}
				}
			}
			else k=0;
			j++;
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci){
	for(std::string i:rijeci){
		for(int j{0}; j<i.length(); j++){
			if(i.at(j)<'A' || ( i.at(j) > 'Z' && i.at(j) < 'a') || i.at(j) > 'z' ) throw std::domain_error("Nekorektan izbor rijeci");
		}
		for(int j{0}; j<recenica.length(); j++){
			int k{0};
			if(i.at(k)==recenica.at(j) && (j==0 || recenica.at(j-1)==' ')){
				while(j<recenica.length() && k<i.length()){
					if(i.at(k)==recenica.at(j)) k++;
					  j++;
					
				}
				if(k==i.length() && (j==recenica.length() || recenica.at(j)==' ')){
					recenica.insert(recenica.begin() + j, recenica.at(j-k));
					recenica.erase(recenica.begin() + j-k);
					recenica.insert(recenica.begin() + j, 'a');
					recenica.insert(recenica.begin() + j+1, 'y');
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
	for(;;){
		std::string rijec;
		std::getline(std::cin, rijec);
		if(rijec.length()==0) break;
		fraze.push_back(rijec);
	}
	std::string ispis;
	try{
	  ispis=IzmijeniUPigLatin(recenica, fraze);
	  std::cout << "Recenica nakon PigLatin transformacije: " << ispis;
	  std::cout << std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	ispis=ObrniFraze(recenica, fraze);
	std::cout << "Recenica nakon obrtanja fraza: " << ispis;
	return 0;
}