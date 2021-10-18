#include <iostream>
#include <vector>
#include <string>

std::string ObrniFraze(std::string Recenica,std::string rijec){
	std::string s,prazanstring;
	for(int i(0);i<Recenica.length();i++){
		while(Recenica[i]!=' ')
			s[i]=Recenica[i];
		if(s==rijec){
		 int j(0),k(i);
	while(j<k){
		std::swap(Recenica[j],Recenica[k]);
		j++;
		k--;
	}
		}
		
		
	}
	return Recenica;
}


int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string Recenica;
	std::getline(std::cin,Recenica);
	std::cout<<"Unesite spisak rijeci: ";
	std::string Spisak;
	std::getline(std::cin,Spisak);
	std::cout<<Recenica<<std::endl<<Spisak;
	std::string NovaRecenica(ObrniFraze(Recenica,Spisak));
	std::cout<<std::endl<<NovaRecenica;
	return 0;
}