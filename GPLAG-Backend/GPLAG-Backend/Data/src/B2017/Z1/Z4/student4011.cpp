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

bool jeLiNeslovo(char a){
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
		return false;
	return true;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> fraze){
	
	if(s.size()==0) 
		return s;
	
	for(int i=0 ; i<fraze.size() ; i++){
		
		for(int j=0;j<s.size();j++){
			if(s.size()-j>=fraze.at(i).size()){
				if(s.substr(j,fraze.at(i).size())==fraze.at(i)){
					int pocetakRijeci = j;
					int krajRijeci = j + fraze.at(i).size()-1;
					if((pocetakRijeci==0 || jeLiNeslovo(s.at(pocetakRijeci-1)))&&(krajRijeci==s.size()-1||jeLiNeslovo(s.at(krajRijeci+1)))){
						for(int k=0;k<fraze.at(i).size()/2;k++){
							s.at(krajRijeci)=s.at(pocetakRijeci);
							pocetakRijeci++;
							krajRijeci--;
						}
					}
				}
			}
		}
	}
	
	return s;}
	
std::string NapraviPalindrom(std::string s, std::vector<std::string> fraze) {
	
	if(s.size()==0)
		{return s;}
		
		for(int i=0;i<fraze.size();i++){
			
			for(int j=0;j<s.size();j++){
			if(s.size()-j>=fraze.at(i).size()){
				if(s.substr(j,fraze.at(i).size())==fraze.at(i)){
					int pocetakRijeci = j;
					int krajRijeci = j + fraze.at(i).size()-1;
					if((pocetakRijeci==0 || jeLiNeslovo(s.at(pocetakRijeci-1)))&&(krajRijeci==s.size()-1||jeLiNeslovo(s.at(krajRijeci+1)))){
						for(int k=0;k<fraze.at(i).size();k++){
							s.insert(s.begin()+krajRijeci+1,s.at(pocetakRijeci));
							pocetakRijeci++;
							
						}
					}
				}
			}
		}
			
		}
	
	return s;
}
	
	

int main ()
{
	
	std::string s;
	std::vector<std::string> fraze;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	while(std::cin.peek()!='\n'){
		
		std::string tmp;
		std::getline(std::cin,tmp);
		fraze.push_back(tmp);
	}
	
	
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(s,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(s,fraze);
	
	
	
}