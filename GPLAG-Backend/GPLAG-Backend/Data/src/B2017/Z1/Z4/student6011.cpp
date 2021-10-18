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
#include <cctype>

std::string NapraviPalindrom(std::string s, std::vector<std::string> vs){
	for(auto s1:vs){
		for(int i=0; i<s.length(); i++){
			int index=s.find(s1, i);
			if(index==std::string::npos) break;
			
			if(index==0 && index + s1.length()!=s.length()){
				if(isalpha(s.at(index + s1.length()))) continue;
			}
			
			if(index!=0 && index + s1.length()==s.length()){
				if(isalpha(s.at(index - 1))) continue;
			}
			
			if(index!=0 && index +s1.length()!=s.length()){
				if(isalpha(s.at(index + s1.length())) || isalpha(s.at(index - 1))) continue;
			}
            
			int k=0;
			for(int j=s1.length()-1; j>=0; j--){
				s.insert(index+s1.length()+k,1,s1.at(j));
				k++;
			}
			
			i+=index + 2*s1.length() -1;
			}
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> vs){
	for(auto s1:vs){
		for(int i=0; i<s.length(); i++){
			int index=s.find(s1, i);
			if(index==std::string::npos) break;
		
	    	if(index==0 && index + s1.length()!=s.length()){
				if(isalpha(s.at(index + s1.length()))) continue;
			}
			
			if(index!=0 && index + s1.length()==s.length()){
				if(isalpha(s.at(index - 1))) continue;
			}
			
			if(index!=0 && index +s1.length()!=s.length()){
				if(isalpha(s.at(index + s1.length())) || isalpha(s.at(index - 1))) continue;
			}
			
		
			int k=0;
			for(int j=s1.length()/2 - 1 + s1.length()%2; j>=0; j--){
				s.at(index+s1.length()/2 +k)=s1.at(j);
				k++;
			}
			
			i+=index + s1.length()-1;
			}
	}
	return s;
}

int main ()
{
	std::string s;
	std::vector<std::string> vs;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	while(1){
		std::string fraza;
		std::getline(std::cin,fraza);
		if(fraza=="") break;
		vs.push_back(fraza);
	}
	
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s, vs);
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s, vs);
	
	
	return 0;
}