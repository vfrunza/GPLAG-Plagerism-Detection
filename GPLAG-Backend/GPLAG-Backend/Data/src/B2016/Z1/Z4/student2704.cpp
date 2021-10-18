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

std::string ObrniFraze(std::string recenica, std::vector<std::string>vektrostring){
	
	std::string string=recenica;
	std::vector<std::string>fraze=vektrostring;
	
	for(int i=0; i<fraze.length(); i++){
		std::string fraza=fraze.at(i);
		for(int j=0; j<string.length(); j++){
			if(fraza.at(i)==recenica.substr(j,j+fraza.at(i).size()){
				std::string obrnutafraza;
				int l=0;
				for(int k=fraza.length(); k>0; k--){
					obrnutafraza.at(l)=fraza.at(k);
					l++;
				}
			}
		}
	}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string>vektorstring){
	
	std::string piglatin=recenica;
	std::vector<std::string>fraze=vektorstring;
	
	
	
	for(int i=0; i<vektor.size(); i++){
			char slovo=vektor.at(i).at(0);
			(vektor.at(i).erase(vektor.at(i).begin());
			vektor=vektor.at(i)+temp+"ay";
	}
}


int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::vector<std::string>fraze;
	std::string fraza;
	char znak;
	
	std::cout << "Unesite fraze: ";
	
	while((znak=std::cin.get())!='\n'){
		std::getline(std::cin,fraza);
		fraza=znak+fraza;
		fraze.push_back(fraza);
	}
	
	
//	recenica=IzmijeniUPigLatin(recenica,fraza);
	std::cout << "Recenica nakon PigLatin transformacije: ";
	
//	recenica=ObrniFraze(recenica,fraze);
	std::cout << "Recenica nakon obrtanja fraza: ";

	
	return 0;
}