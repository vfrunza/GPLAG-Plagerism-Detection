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
#include <vector>
#include <string>

std::string palindrom(std::string s){
	std::string p;
	for(int i=s.length()-1;i>=0;i--)
	p.push_back(s.at(i));
	return p;
}

std::string Napravi_Palindrom(std::string s,std::vector<std::string>vec){
	std::vector<std::string>polupalindrom_vec;
	for(int i=0;i<vec.size();i++){
		polupalindrom_vec.push_back(palindrom(vec.at(i)));
	}
	
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<s.size();j++){
			if((s.substr(j,vec.at(i).size())==vec.at(i))){
				std::string tmp(polupalindrom_vec.at(i));
				for(int k=0;k<tmp.size();k++){
					s.insert(s.begin()+j+vec.at(i).size()+k,tmp.at(k));
				}
				
				
			}
		}
	}
	return s;
}
	
std::string Napravi_PoluPalindrom(std::string s, std::vector<std::string>vec){
	std::vector<std::string>polupalindrom_vec;
	
	for(int i=0;i<vec.size();i++) polupalindrom_vec.push_back(palindrom(vec.at(i)));
	
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<s.size();j++){
			if((s.substr(j,vec.at(i).size())==vec.at(i))){
				if((vec.at(i).length())%2==0){
					int duzina(0);
					duzina=((vec.at(i).size()))/2;
					j=j+duzina;
					std::string pom(polupalindrom_vec.at(i));
					for(int k=duzina;k<pom.size();k++){
						if(k==pom.size() && j!=' ') break;
						else{
						s.at(j)=pom.at(k);
						j++;
						}
					}
				}
				if(vec.at(i).length()%2!=0){
					int duzina(0);
					duzina=(vec.at(i).size()-1)/2;
					j=j+duzina;
					std::string pom(polupalindrom_vec.at(i));
					for(int k=duzina;k<pom.size();k++){
						s.at(j)=pom.at(k);
						j++;
					}
				}
			}
		}
	}
	return s;
}

int main ()
{ 
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::vector<std::string>vec;
	std::cout<<"Unesite fraze: ";
	std::string fraza;
	for(;;){
		std::getline(std::cin,fraza);
		if(fraza!="") vec.push_back(fraza);
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<Napravi_Palindrom(s,vec);
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<Napravi_PoluPalindrom(s,vec);

	return 0;
}