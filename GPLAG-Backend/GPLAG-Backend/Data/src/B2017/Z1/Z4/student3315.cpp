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

bool slovo(char s){
	if(s>='A'&&s<='Z'||s>='a'&&s<='z') return true;
	return false;
}


std::string NapraviPalindrom(std::string recenica1, std::vector<std::string> fraze){
	std::string recenica(recenica1);
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<recenica.length();j++){
			if(fraze.at(i)==recenica.substr(j,fraze.at(i).length())){
				if(j+fraze.at(i).length()==recenica.length())recenica.push_back(' ');
				if(!slovo(recenica.at(j+fraze.at(i).length())))
					for(int k=fraze.at(i).length()-1;k>=0;k--){
						std::string s;
						s=fraze.at(i).at(k);
						recenica.insert(j+fraze.at(i).length(),s);
						j++;
					}
					j+=fraze.at(i).length()-1;
				
			}
		}
	}
	return recenica;
}



std::string NapraviPoluPalindrom(std::string recenica1, std::vector<std::string> fraze){
	std::string recenica(recenica1);
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<recenica.length();j++){
			if(fraze.at(i)==recenica.substr(j,fraze.at(i).length())){
				if(j+fraze.at(i).length()!=recenica.length()){
					if(!slovo(recenica.at(j+fraze.at(i).length()))){
						int pomjeraj((fraze.at(i).length())/2);
						j+=pomjeraj;
						int k=1;
						if(fraze.at(i).length()%2!=0)k++,j++;
						for(;k<=pomjeraj*2;k+=2){
							recenica.at(j)=recenica.at(j-k);
							j++;
						}
						j--;
					}
				}else{
					int pomjeraj((fraze.at(i).length())/2);
						j+=pomjeraj;
						int k=1;
						if(fraze.at(i).length()%2!=0)k++,j++;
						for(;k<=pomjeraj*2;k+=2){
							recenica.at(j)=recenica.at(j-k);
							j++;
						}
						j--;
				}
			}
		}
	}
	return recenica;
}
int main (){
	std::string s;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	int brojac(1);
	while(1){
		v.resize(brojac);
		std::getline(std::cin,v.at(brojac-1));
		if(v.at(brojac-1)==""){
			v.resize(brojac-1);
			break;
		}
		brojac++;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,v);
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);
	return 0;
}