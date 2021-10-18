/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>

std::string NapraviPalindrom(std::string recenica , std::vector<std::string> fraze){
	for(int i(0);i<fraze.size();i++){
		for(int j(0);j<recenica.size();j++){
			if(fraze.at(i).at(0)==recenica[j]){
				bool Ubaciti(true);
				int duzinafraze(0);
				for(int k(j);k<recenica.size();k++){
					if(recenica.at(k)!=' ')duzinafraze++;
					else break;
				}
				if(duzinafraze>fraze.at(i).size()) Ubaciti=false;
				else{
					for(int k(0);k<fraze.at(i).size();k++){
						if(j+fraze.at(i).size()>recenica.size()) { Ubaciti=false; break; }
						if(fraze.at(i).at(k)!=recenica.at(j+k)) { Ubaciti=false; break; }
					}
				}
				if(Ubaciti){
					std::string uvrnutafraza;
					for(int l=fraze.at(i).size()-1;l>=0;l--){
						uvrnutafraza.push_back(fraze.at(i).at(l));
					}
					recenica.insert(j+fraze.at(i).size(),uvrnutafraza);
					j=j+fraze.at(i).size()-1;
				}
			}
			
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze){
	for(int i(0);i<fraze.size();i++){
		for(int j(0);j<recenica.size();j++){
			if(fraze.at(i).at(0)==recenica[j]){
				bool Ubaciti(true);
				
				int duzinafraze(0);
				for(int k(j);k<recenica.size();k++){
					if(recenica.at(k)!=' ')duzinafraze++;
					else break;
				}
				if(duzinafraze>fraze.at(i).size()) Ubaciti=false;
				else {
					for(int k(0);k<fraze.at(i).size();k++){
						if(j+fraze.at(i).size()>recenica.size()) { Ubaciti=false; break; }
						if(fraze.at(i).at(k)!=recenica.at(j+k)) { Ubaciti=false; break; }
					}
				}
				if(Ubaciti){
					if(fraze.at(i).size()%2==1){
						for(int l(j+fraze.at(i).size()/2+1);l<j+fraze.at(i).size();l++){
							recenica.at(l)=recenica.at(2*j+fraze.at(i).size()-l-1);
						}
					}
					else {
						for(int l(j+fraze.at(i).size()/2);l<j+fraze.at(i).size();l++){
							recenica.at(l)=recenica.at(2*j+fraze.at(i).size()-l-1);
						}
					}
				}
			}
			
		}
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	while(1){
		std::getline(std::cin, fraza);
		if(fraza=="\0") break;
		fraze.push_back(fraza);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::string novarecenica(NapraviPalindrom(recenica,fraze));
	std::cout<<novarecenica<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	novarecenica=NapraviPoluPalindrom(recenica,fraze);
	std::cout<<novarecenica;
	return 0;
}