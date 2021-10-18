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
std::string ObrniString(std::string s){
	int x; x=s.length()-1;
	char p;
	for(int i=0;i<s.length()/2;i++){
		p=s.at(i);
		s.at(i)=s.at(x);
		s.at(x)=p;
		x--;
	}
	return s;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	std::string s2;
	int x,y(0),k(0);
	for(int i=0;i<v.size();i++){
		s2=v.at(i);
		x=s.find(s2,y);
		if(x!=-1){
			if(x==0 && x+s2.length()==s.length()) k=1;
			else if(x==0 && (s.at(x+s2.length())==' ' || s.at(x+s2.length())==',')) k=1;
			if(x>0){
				if(s.at(x-1)==' ' && x+s2.length()==s.length()) k=1;
				else if(s.at(x-1)==' ' && (s.at(x+s2.length())==' ' || s.at(x+s2.length())==',')) k=1;
			}
			if(k==1){
			s2=ObrniString(s2);
			s.insert(x+s2.length(),s2); }
			y=x+1; i--;
		}else{ y=0; }
		s2.resize(0);k=0;
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
	std::string s2;
	int x,y,z,q(0),k(0);
	for(int i=0;i<v.size();i++){
		s2=v.at(i);
		x=s.find(s2,q);
		if(x!=-1){
			if(x==0 && x+s2.length()==s.length()) k=1;
			else if(x==0 && (s.at(x+s2.length())==' ' || s.at(x+s2.length())==',')) k=1;
			if(x>0){
				if(s.at(x-1)==' ' && x+s2.length()==s.length()) k=1;
				else if(s.at(x-1)==' ' && (s.at(x+s2.length())==' ' || s.at(x+s2.length())==',')) k=1;
			}
			if(k==1){
			z=s2.length();
			y=s2.length()/2;
			s2.resize(y);
			s2=ObrniString(s2);
			s.erase(x+(z-y),s2.length());
			s.insert(x+(z-y),s2); }
			q=x+1; i--;
		}else{ q=0; }
		s2.resize(0);k=0;
	}
	return s;
}
int main (){
	std::string s,s2;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::getline(std::cin, s2);
	while(s2.empty()==false){
		v.push_back(s2);
		s2.resize(0);
		std::getline(std::cin, s2);
	} s2.resize(0);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	s2=NapraviPalindrom(s,v);
	std::cout<<s2<<std::endl; s2.resize(0);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	s2=NapraviPoluPalindrom(s,v);
	std::cout<<s2;
	return 0;
}