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
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

std::string obrnuto (std::string s){
	std::string a{""};
	for (int i=s.size()-1; i>=0; i--) 
	a.push_back(s.at(i));
	return a;
}

std::string PoluPalindrom (std::string s){
	std::string a;
	for (int i=0; i<(s.size()/2); i++) a.push_back(s.at(i));
	if (s.size()%2!=0) for (int j=(s.size()/2); j>=0; j--) a.push_back(s.at(j));
	else for( int i=(s.size()/2)-1; i>=0; i--) a.push_back(s.at(i));
	return a;
}


std::string NapraviPalindrom (std::string s, std::vector<std::string> v){
	int j=0;
	for (int i=0; i<s.length(); i++){
		if (v.size()!=0){
		std::string b (s.substr(i,v.at(j).size()));
		if (b==v.at(j)){
		if (i==0 && i+v.at(i).size()==s.length()) s=s+obrnuto(v.at(j));	
		else if (i+v.at(j).size()==s.length()){
				if(s.at(i-1)==' '){
					s.insert (i+v.at(j).size(), obrnuto(v.at(j)));
					i+=v.at(j).size();
				}
			} else if((s.at(i+v.at(j).size())==' ' ||  s.at(i+v.at(j).size())==',' || s.at(i+v.at(j).size())=='.') && i==0){
					s.insert (i+v.at(j).size(), obrnuto(v.at(j)));
					i+=v.at(j).size();
			} else if ((s.at(i+v.at(j).size())==' ' || s.at(i+v.at(j).size())==',' || s.at(i+v.at(j).size())=='.') && s.at(i-1)==' '){
					s.insert (i+v.at(j).size(), obrnuto(v.at(j)));
					i+=v.at(j).size();
			}
		}
		if(i==s.length()-1 && j<v.size()-1) {
			i=0;
			j++;
		}
		}
	}
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v){
	int j=0;

	for (int i=0; i<s.length(); i++){
		if (v.size()!=0){
		std::string b (s.substr(i,v.at(j).size()));
		if (b==v.at(j)){
			if (i==0 && i+v.at(i).size()==s.length()){
				s.erase (i,v.at(j).size());
				s.insert (i,PoluPalindrom(v.at(j)));
			} 
			 else if (i+v.at(j).size()==s.length()){
				if((s.at(i-1)==' ') || (!(s.at(i+v.at(j).size())>='a' && s.at(i+v.at(j).size())<='z') || !(s.at(i+v.at(j).size())>='A' && s.at(i+v.at(j).size())<='Z'))  && (!(s.at(i-1)>='a' && s.at(i-1)<='z') || !(s.at(i-1)>='A' && s.at(i-1)<='Z'))){
					s.erase (i,v.at(j).size());
					s.insert (i, PoluPalindrom(v.at(j)));
				}
			} else if(( (((s.at(i+v.at(j).size())<='A') ||  (s.at(i+v.at(j).size())>='Z'))) && ( s.at(i+v.at(j).size())<='a' ||  s.at(i+v.at(j).size())>='z')) && i==0){
					s.erase (i,v.at(j).size());
					s.insert (i, PoluPalindrom(v.at(j)));
			} else if (!((s.at(i+v.at(j).size())>='a' && s.at(i+v.at(j).size())<='z') || (s.at(i+v.at(j).size())>='A' && s.at(i+v.at(j).size())<='Z'))  && (!(s.at(i-1)>='a' && s.at(i-1)<='z') || !(s.at(i-1)>='A' && s.at(i-1)<='Z')) ){
					s.erase (i,v.at(j).size());
					s.insert (i, PoluPalindrom(v.at(j)));
			}
		}
		if(i==s.length()-1 && j<v.size()-1) {
			i=0;
			j++;
		}
		}
	}
	return s;
}

int main ()
{
	std::string s;
	std::vector<std::string> v;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	
	while(1){
		std::string a;
		std::getline(std::cin, a);
		if (a=="") break;
		v.push_back(a);
	}
	
	if (s.size()!=0 && (v.size()!=0 || v.size()==0)){
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s,v) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s,v);
	}	
	return 0;
}