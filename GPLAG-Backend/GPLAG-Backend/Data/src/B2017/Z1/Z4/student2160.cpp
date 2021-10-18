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
#include <cmath>

bool NijeSlovo(std::string s,int a){
	if((a>= 'a' && a<='z') || (a>='A' && a<='Z'))
	return false;
    return true;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	std::vector<std::string> pomocni;
	  for(auto x : v){
	  	for(int i=0; i<s.length(); i++){
	  		for(int j=0; j<=s.length()-i; j++){
	  			if(s.substr(i,j)==x) {
	  				 int a=i;
	  			     int c=a;
	  			     int b=i+j-1;
	  			     while(a<b){
	  			     	char tmp=s.at(a);
	  			     	s.at(a)=s.at(b);
	  			     	s.at(b)=tmp;
	  			     	a++;
	  			     	b--;
	  			     }
					s.insert(c,x);
	  			   
	  			}
	  		}
	  	}
	 }
	return s;
}

std::string NapraviPoluPalindrom(std:: string s, std::vector<std::string> v){
	 	for(auto x :v){
	 		for(int i=0; i<s.length(); i++){
	 			for(int j=0; j<=s.length()-i; j++){
	 				if(s.substr(i,j) == x){
	 					int a=i;
	 					int b=i+j-1;
	 					while(a<b){
	 						s.at(b)=s.at(a);
	 						a++;
	 						b--;
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
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	while(true){
		std::string x;
		std::getline(std::cin, x);
		if(!(x.length()==0)){
			
		v.push_back(x);
	}
	else break;
}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::string m;;
    m= NapraviPalindrom(s,v);
	std::cout<<m;
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::string p;
	p=NapraviPoluPalindrom(s,v);
	std::cout<<p;
	return 0;
}