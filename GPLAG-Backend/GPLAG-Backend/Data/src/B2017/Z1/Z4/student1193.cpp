#include <iostream>
#include <string>
#include <vector>

std::string Palindrom(std::string s) {
	char pomocna;
	for(int i=0;i<s.size()/2;i++) {
		pomocna=s.at(i);
		s.at(i)=s.at(s.size()-1-i);
		s.at(s.size()-1-i)=pomocna;
		if(i==s.length()-1-i) break;
	}
	return s;
}
std::string PoluPalindrom (std::string s) {
	std::string s1=Palindrom(s); 
	if(s.length()%2==0) {
	int n=s1.length()/2;
	std::string temp, pomocna;
	pomocna=s.substr(0, s.length()/2);
	temp=pomocna+s1.substr(n,s1.length());
	return temp;
	}
	else {
	int n=s1.length()/2+1;
	std::string temp,pomocna;
	pomocna=s.substr(0,s.length()/2+1);
	temp=pomocna+s1.substr(n,s1.length());
	return temp;
		
	}
}
std::string NapraviPalindrom (std::string s, std::vector<std::string> v) {
	std::string temp;
	 
	for(int i=0;i<s.length();i++) {
		for(int j=0;j<v.size();j++) {
			if(s.at(i)==v[j][0]) {
				temp=s.substr(i, v.at(j).size());
			
			} 
			
			if(temp==v.at(j) /*&& temp.length()==br*/) {
			
				temp=Palindrom(temp);
				s.resize(temp.size()+s.size()+v.at(j).size());
			s.insert(i+v.at(j).size(),temp);
			}
			
		}
		
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v) {
std::string temp;
for(int i=0;i<s.length();i++) {
	for(int j=0;j<v.size();j++) {
		if(s.at(i)==v.at(j)[0]) {
			temp=s.substr(i,v.at(j).length());
			
			if(temp==v.at(j)) {
				for(int k=i;k<s.length();k++) {
					if(s.at(k)==' ' || s.at(k)=='\n') break;
					else {
						s.erase(s.begin()+k);
					
					}
				}
				temp=PoluPalindrom(temp);
				s.insert(i,temp);
			}
		}
	}
	
}
return s;
}

int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	do {
		std::string rijeci;
		std::getline(std::cin,rijeci);
		fraze.push_back(rijeci);
		if(rijeci.length()==0 ) break;
	} while(std::cin.peek()!='\n');
	
	
	if(fraze.size()==0) {
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<recenica;
	std::cout<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
     std::cout<<recenica;
	}
	else {
	std::string s1, s2;
	s1=NapraviPalindrom(recenica,fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<s1;
	std::cout<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	s2=NapraviPoluPalindrom(recenica,fraze);
	std::cout<<s2;
		
	} 
	return 0;
}





