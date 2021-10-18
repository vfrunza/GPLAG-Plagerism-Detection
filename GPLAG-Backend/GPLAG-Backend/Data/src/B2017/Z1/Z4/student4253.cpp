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
#include<string>
#include<vector>
std::string NapraviPalindrom(std::string recenica,std::vector<std::string>rijeci){
	for(int i=0; i<rijeci.size();i++){
		for(int j(0); j<recenica.length();j++){
			for(int k(0);k<rijeci.at(i).length();k++){
				if(k == 0 && (j==0 || recenica.at(j-1)==' ') && recenica.at(j) == rijeci.at(i).at(k)){
					while(j<recenica.length()&& k<rijeci.at(i).length()&& recenica.at(j)==rijeci.at(i).at(k)){
					j++;
					k++;
					}
			if(k==rijeci.at(i).length()){
				if((j==recenica.length())||!((recenica.at(j)>='a' && recenica.at(j)<='z') || (recenica.at(j)>='A' && recenica.at(j)<='Z'))){
					for(int l(0);l<rijeci.at(i).length();l++){
						recenica.insert(recenica.begin()+j,rijeci.at(i).at(l));
					}
				}
			}
				}
					
					
				}
				
				

				
			}
		}
		return recenica;
	}
	std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string>rijeci){
		for(int i(0); i<rijeci.size();i++){
			for(int j(0);j<recenica.length();j++){
				for(int k(0);k<rijeci.at(i).length();k++){
					if (k == 0 && (j == 0 || recenica.at(j - 1) == ' ') && recenica.at(j)==rijeci.at(i).at(k)) {
						while(j<recenica.length() &&k<rijeci.at(i).length() && recenica.at(j)==rijeci.at(i).at(k)){
							j++;
							k++;
						}
						if(k==rijeci.at(i).length()){
							if(j==recenica.length() || !((recenica.at(j)>='a' && recenica.at(j)<='z') || (recenica.at(j)>='A' && recenica.at(j)<='Z'))){
								int pomocna(j); // zapamtim do kojeg sam slova stigla
								pomocna--;
								for(int l(0);l<rijeci.at(i).length()/2;l++){
									recenica.at(pomocna)=rijeci.at(i).at(l);
									pomocna--;
								}
							}
							
						}
						
					}
					
				}
			}
		}
		return recenica;
	}
	
	
int main ()
{	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::vector<std::string> fraze; 
	std::cout<<"Unesite fraze: ";
	while(1){
	std::string fraza;
	std::getline(std::cin, fraza);
	if(fraza.length()!=0) fraze.push_back(fraza);
	else break;
	}
	std::string palindrom, polupalindrom;
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	palindrom=NapraviPalindrom(s, fraze);
	std::cout << palindrom << std::endl;
	polupalindrom=NapraviPoluPalindrom(s, fraze);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout << polupalindrom;
	return 0;
}