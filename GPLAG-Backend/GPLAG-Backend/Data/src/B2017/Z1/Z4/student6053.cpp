
#include <iostream>
#include <string>
#include <vector>

std::string PretvoriPolPal(std::string s, std::string s1)
{
          int ds1=s1.length();
          std::string rez;
   
   
          std::string s2;
          s2=s1.substr(0,ds1/2);
          
          std::string s2ok;
          for(int i = s2.size(); i >= 0; i--) {
          	s2ok =s2ok + s2[i];
          }
   
          if (ds1%2==0) {
          	 s2 = s2 + s2ok;
          }
          else
          {  int pos = ds1/2;
          	 s2 = s2 + s1[pos] + s2ok;
          }
          
          for (int i=0; i<=s.length();){
          	if(s.substr(i,ds1)==s1) {
          		rez = rez + s2;
          		i = i + ds1;
          	}
          	else {
          		rez = rez + s[i];
          		i++;
          	}
          	
          }
          return rez;
}

std::string PretvoriPal(std::string s, std::string s1)
{
          int ds1=s1.length();
          std::string rez;
          
          
          std::string s1ok;
          for(int i = ds1 - 1; i >= 0; i--) {
          	s1ok = s1ok + s1[i] ;
          }
          
          for (int i=0; i<=s.length();){
          	if(s.substr(i,ds1)==s1) {
          		rez = rez + s1  + s1ok;
          		i = i + ds1;
          	}
          	else {
          		rez = rez + s[i];
          		i++;
          	}
          	
          }
          return rez;
}

std::string NapraviPalindrom(std::string str1, std::vector<std::string> v)
{
	std::string rez1(str1);
	for(int i=0;i<v.size();i++){
		rez1=PretvoriPal(rez1,v.at(i));
		
	}
	return rez1;
} 




std::string NapraviPoluPalindrom(std::string str1, std::vector<std::string> v)
{
	std::string rez1(str1);
	for(int i=0;i<v.size();i++){
		rez1=PretvoriPolPal(rez1,v.at(i));
		
	}
	return rez1;
}


int main ()
{
	//std::string str("Mujos jede pitu jede Mujos hgg");
	
	//std::string sstr("jede");
	//std::vector<std::string> vek{"Mujos","dario","sulju","pitulll"};
	
	std::string recenica;
	

	std::string fraza;
	std::vector<std::string> vek;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::cout<<"Unesite fraze: ";
	
	while(1){
		std::getline(std::cin,fraza);
		
		if(!fraza.length()){
			break;
		}
		vek.push_back(fraza);
	} 
	
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(recenica,vek)<<std::endl;
	
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(recenica,vek);
	
	return 0;
}