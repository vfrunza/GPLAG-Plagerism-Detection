
#include <iostream>
#include<string>
#include<vector>



std::string  Palindrom (std::string s1)
{
	std::string s2;
	for(int i=s1.length()-1; i>=0; i--) s2.push_back(s1.at(i));

	return s2;
}

std::string Polupalindrom(std::string s)
{
	for(int i=0; i<s.length()/2; i++) {
		s.at(s.length()-1-i)=s.at(i);

	}
	return s;
}

std::string NapraviPalindrom(std::string s1, std::vector<std::string> v)
{

	s1 = s1 + " ";
std::string s2;
std::string p;
	for(int i=0; i<v.size(); i++) {

		for(int s=0; s<s1.length(); s++) {

		
			
			p = s1.substr(s, v.at(i).length());
			
			
			if(p==v.at(i) && ((s1.at(s+v.at(i).length()) <'A' || s1.at(s+v.at(i).length())>'Z'))&& (s1.at(s+v.at(i).length())<'a' || s1.at(s+v.at(i).length())>'z')) {
				s2 = s1.substr(0, s + v.at(i).length());
				s2 += Palindrom(v.at(i));
				s2 += s1.substr(s + v.at(i).length(), s1.length());
			}
			
			else continue;

			s1 = s2;
          }
}


	 s1=s1.substr(0,s1.length()-1);
	 return s1;
}


std::string NapraviPoluPalindrom(std::string s1, std::vector<std::string> v)
{

	s1 = s1 + " ";
	std::string s2;
	std::string p;
	
	for(int i=0;i<v.size();i++){
		
		for(int s=0;s<s1.length();s++){
		
	
	
	p=s1.substr(s,v.at(i).length());
	
	if(p==v.at(i)  && ((s1.at(s+v.at(i).length())<'A' || s1.at(s+v.at(i).length())>'Z') )&& (s1.at(s+v.at(i).length())<'a' || s1.at(s+v.at(i).length())>'z')) {
		s2=s1.substr(0,s);
		s2+=Polupalindrom(v.at(i));
		s2+=s1.substr(s+v.at(i).length(),s1.length());
		
		
		
	}
	else continue;
	s1=s2; 
		}
}

 s1=s1.substr(0,s1.length()-1); 
 return s1;
}

int main ()
{

std::vector<std::string>v;
std::string recenica;
std::string vstringa;

std::cout<<"Unesite recenicu: ";
std::getline(std::cin,recenica);

std::cout<<"Unesite fraze: ";

for(;;){
	
	std::getline(std::cin,vstringa);
	if(vstringa=="") break;
	if(vstringa!="")
	v.push_back(vstringa);
}

std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,v);
std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,v);



	return 0;
}