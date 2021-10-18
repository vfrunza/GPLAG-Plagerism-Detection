#include <iostream>
#include <string>
#include <vector>
 std:: string NapraviPalindrom(std:: string recenica,std::vector<std::string> rijeci){
	for (int i = 0; i < rijeci.size(); i++) {
		std::string s=rijeci.at(i);
		int razmak=1;
		int k=0;
		while (k<recenica.length()) {
			char a=recenica.at(k);
			if(a<'A'||a>'Z'&&a<'a'||a>'z'){
				razmak=1;
			}else if(razmak==1){
				razmak=0;
				bool poklapanje (false);
					if(a==s.at(0))
						poklapanje=true;
				if(poklapanje){
					int m=0;
					while((k+m<recenica.length())&&(m<s.length())&&recenica.at(k+m)==s.at(m)) m++;
					if((m==s.length())&&((k+m==recenica.length())||( recenica.at(k+m) < 'A' || recenica.at(k+m) >'Z' && recenica.at(k+m)<'a' || recenica.at(k+m)>'z')))
						poklapanje=true;
					else
						poklapanje=false;
					if(poklapanje){
						for (int j = 0; j <s.length() ; j++) 
							recenica.insert(recenica.begin()+k+m,s.at(j));
						k+=2*s.length()-1;
					}
				}
			}
			k++;
		}
	}	
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string> rijeci){
	for (int i = 0; i < rijeci.size(); i++) {
		std::string s (rijeci.at(i));
		int razmak=1;
		int k (0);
		while (k<recenica.length()) {
			char a (recenica.at(k));
			if(a<'A'||a>'Z'&&a<'a'||a>'z'){
				razmak=1;
			}else if(razmak==1){
				razmak=0;
				bool poklapanje (false);
				if(a==s.at(0))
					poklapanje=true;
				if(poklapanje){
					int m (0);
					while ((k+m<recenica.length())&&(m<s.length())&&recenica.at(k+m)==s.at(m))m++;
					if(m==s.length()&&(k+m==recenica.length()||( recenica.at(k+m) < 'A' || recenica.at(k+m) >'Z' && recenica.at(k+m)<'a' || recenica.at(k+m)>'z')))
						poklapanje=true;
					else
						poklapanje=false;
					if(poklapanje){
						for (int j = 0; j < s.length()/2; j++) {
							recenica.at(k+m-1-j)=s.at(j);
						}
						k+=m/2-1;
					}
				}
			}
			k++;
		}
	}
	
	
	
	return recenica;
}

int main ()
{	std::string a,b;
	std::cout << "Unesite recenicu: " ;
	std::getline(std::cin,a);
	std::vector<std::string> c ;
	std::cout << "Unesite fraze: " ;
	while (std::getline(std::cin,b),b.length()!=0) {
		c.push_back(b);
	}
	std::cout <<"Recenica nakon Palindrom transformacije: " << NapraviPalindrom(a,c) << std::endl;
	std::cout <<"Recenica nakon PoluPalindrom transformacije: "<< NapraviPoluPalindrom(a,c) << std::endl;
	return 0;
}