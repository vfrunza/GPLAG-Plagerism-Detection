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


std::string ObrniFraze(std::string s, std::vector<std::string> fraze) {

	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			for(int k=0; k<s.length()-j; k++) {
				if(fraze[i]==s.substr(j,k)) {
					int pocetni=j;
					int krajnji=j+k-1;
					while(pocetni<krajnji) {
						char pom=s[pocetni];
						s[pocetni]=s[krajnji];
						s[krajnji]=pom;
						pocetni++;
						krajnji--;
					
					}
			
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> fraze) {

	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			for(int k=0; k<s.length()-j; k++) {
				if(fraze[i]==s.substr(j,k)) {
					int pocetni=j;
					int krajnji=j+k-1;
					std::string prvo_slovo;
					prvo_slovo=s.substr(pocetni,1);
					s.erase(s.begin()+pocetni);
					krajnji--;
					s.insert(krajnji+1, prvo_slovo);
					s.insert(krajnji+2, "a");
					s.insert(krajnji+3, "y");
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
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	 for(;;) { 
	if(std::cin.peek()=='\n') break; 
	else {
	std::string rijec;
	std::getline(std::cin, rijec);
	fraze.push_back(rijec); }
	}
	

	std::string piglatin=IzmijeniUPigLatin(recenica,fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<piglatin<<std::endl; 
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze);


	return 0;
}