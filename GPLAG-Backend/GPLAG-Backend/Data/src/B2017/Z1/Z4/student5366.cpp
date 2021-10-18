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
#include <cmath>

typedef std::vector<std::string> VS ;


std ::string NapraviPalindrom(std::string s1,VS fraze){
	for(std::string s:fraze){
		for (int i = 0; i <s1.length(); i++) {
			if(s.at(0)==s1.at(i)){
				bool ubaci (true);
				if	(i+s.length()>s1.length())
					continue;
				for (int k = 0; k < s.length(); k++) {
					if(s.at(k)!=s1.at(i+k)){
						ubaci=false;
						break;
					}
				}
				if(!ubaci)
					continue;
				if( i+s.length()<s1.length())
					if(s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z' || s1.at(i+s.length())>='a' && s1.at(i+s.length()<='z'))
						ubaci=false;
				if(i>0)
					if(s1.at(i-1)>='A'&& s1.at(i-1)<='Z'|| s1.at(i-1)>='a' && s1.at(i-1)<='z')
						ubaci=false;
				if(ubaci){
					if(i+s.length()<s1.length()-1){
					i+=s.length();
					for (int j=s.length()-1; j >-1;j--) {
						s1.insert(s1.begin()+i,s.at(j));
						i++;
					}
					}else{ 
						for (int j = s.length()-1; j > -1; j--) {
							s1.push_back(s.at(j));
						}
						i+=s.length();
					}
				}
			}
		
		}
	}
	return s1;
}
std::string NapraviPoluPalindrom(std::string s1,VS fraze ){
	for (std::string s:fraze){
		for (int i = 0; i < s1.length(); i++) {
			if(s.at(0)==s1.at(i)){
				bool ubaci (true);
				
				if(i+s.length()>s1.length())
					continue;
				for (int j = 0; j < s.length(); j++) {
					if(s.at(j)!=s1.at(i+j)){
						ubaci=false;
						break;
					}
				}
				if(!ubaci)
					continue;
				if(i+s.length()<s1.length())
					if(s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z' || s1.at(i+s.length())>='a'&& s1.at(i+s.length())<='z') 
						ubaci=false;
				if(i>0) 
					if(s1.at(i-1)>='A' && s1.at(i-1)<='Z' ||s1.at(i-1)>='a' && s1.at(i-1)<='z')
						ubaci=false;
				if(ubaci){
					i+=ceil(s.length()/2.0);
					for (int k=s.length()/2-1; k >-1 ; k--) {
						s1.at(i)=s.at(k);
						i++;
					}
				}
			}
				
				
		}
	}
		
	return s1;	
}


int main ()
{ 
	std::cout<<"Unesite recenicu: ";
	std::string recenica,s;
	VS fraze;
	getline(std::cin,recenica);
	std::string a(recenica);
	std::cout << "Unesite fraze: " ;
	while (std::getline(std::cin,s),s.length()!=0) {
		fraze.push_back(s);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " <<NapraviPalindrom(recenica,fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica,fraze) <<std::endl;
	return 0;
}