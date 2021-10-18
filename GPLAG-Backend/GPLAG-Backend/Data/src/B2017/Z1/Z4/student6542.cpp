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

std::string Obrnut(std::string s){
	std::string Palindrom;
	for(int i=s.size()-1; i>=0; i--){
		Palindrom.push_back(s.at(i));
	}
	return Palindrom;
}
std::string NapraviPalindrom(std::string s,std::vector<std::string> vektor){
	
	std::string rijeci;
	std::string palindrom;
	int duzina;
	
	for(int i=0;i<vektor.size();i++){
		duzina=vektor.at(i).size();
		rijeci.resize(0);
		
		for(int j=0;j<s.size();j++){
			if(s.size()-j<duzina) break;
			if(vektor.at(i).at(0)==s.at(j) && vektor.at(i).at(duzina-1)==s.at(j+duzina-1)){
				if((j==0 || !((s.at(j-1)>='a') && (s.at(j-1)<='z')) || ((s.at(j-1)>='A') || (s.at(j-1)<='Z'))) && ((j+duzina-1)==s.size()-1 || !((s.at(j+duzina)>='a') && (s.at(j+duzina)<='z')) || ((s.at(j+duzina)>='A') && (s.at(j+duzina)<='Z')))) {
					 rijeci=s.substr(j,duzina);
					if(rijeci==vektor.at(i)){
						palindrom=Obrnut(rijeci);
						for(int k=palindrom.size()-1;k>=0;k--){
							s.insert(s.begin()+(j+duzina),palindrom.at(k));
						}
					}
				}
			} 
		}
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s,std::vector<std::string> vektor){
	std::string rijeci;
	std::string palindrom;
	int duzina;
	for(int i=0;i<vektor.size();i++){
		duzina=vektor.at(i).size();
		rijeci.resize(0);
		
		for(int j=0;j<s.size();j++){
			duzina=vektor.at(i).size();
			if(s.size()-j<duzina) break;
			if((j==0 || !((s.at(j-1)>='a') && (s.at(j-1)<='z')) || ((s.at(j-1)>='A') || (s.at(j-1)<='Z'))) && ((j+duzina-1)==s.size()-1 || !((s.at(j+duzina)>='a') && (s.at(j+duzina)<='z')) || ((s.at(j+duzina)>='A') && (s.at(j+duzina)<='Z')))){ 
				if(vektor.at(i).at(0)==s.at(j) && vektor.at(i).at(duzina-1)==s.at(j+duzina-1)){
					rijeci=s.substr(j,duzina);
					if(rijeci==vektor.at(i)){
						if(duzina%2==0){
							duzina=duzina/2;
					 		rijeci.resize(duzina);
					 		palindrom=Obrnut(rijeci);
						}
						else {	
							duzina=(duzina/2)+1;
							rijeci.resize(duzina);
							palindrom=Obrnut(rijeci);
							palindrom.erase(palindrom.begin()+0);
						}
						std::string ubaci;
						ubaci=rijeci+palindrom;
						for(int k=0;k<ubaci.size();k++){
							s.erase(s.begin()+j);
						
						}
						for(int k=0;k<ubaci.size();k++){
							s.insert(s.begin()+j,ubaci.at(k));
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
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::vector<std::string> vektor;
	std::string rijeci;
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin,rijeci);
		if(rijeci.size()!=0)vektor.push_back(rijeci);
		else break;
	}while(rijeci.size()!=0);

	std::string palindrom1;
	std::string palindrom2;
	
	palindrom1=NapraviPalindrom(s,vektor);
	palindrom2=NapraviPoluPalindrom(s,vektor);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	if(palindrom1.size()>0) std::cout<<palindrom1<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	if(palindrom2.size()>0) std::cout<<palindrom2;
	
	
	
	return 0;
}