/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>

std::string ObrniRijec(std::string x){
	std::string pom;
	for(int i=x.length()-1; i>=0; i--){
		pom+=x[i];
	}
	return pom;
}

std::string NapraviPig(std::string x){
	std::string npom;
	
	for(int i=1; i<x.length(); i++){
		npom+=x[i];
	}
	std::cout<<npom<<std::endl;
	npom=npom+x[0]+"ay";
	return npom;
}
std::string ObrniFraze(std::string s, std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			std::string pomocni=s.substr(j,v[i].size());
			if(pomocni==v[i]){
				s=s.substr(0,j)+ObrniRijec(pomocni)+s.substr(j+pomocni.size(),s.size()-j-pomocni.size());
			}
			
		}
	}
	return s;
}

std::string IzmijeniUPinLatin (std::string s, std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		
		for(int j=0; j<s.length(); j++){
		
			std::string pomocni=v[i];
			pomocni=NapraviPig(pomocni);
			std::cout<<pomocni;
			if(pomocni==v[i]){
				//std::cout<<"------->"<<NapraviPig(pomocni);
				s=s.substr(0,j)+pomocni+s.substr(j+pomocni.size(), s.size()-j-pomocni.size()-1);
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
	std::vector<std::string> y;
	std::cout<<"Unesite fraze: ";
	std::string pom;
	do{
		std::getline(std::cin, pom);
		y.push_back(pom);
	}while(pom.size()!=0);
	std::string a=ObrniFraze(s, y);
	std::cout<<a<<std::endl;
	std::string b=IzmijeniUPinLatin(s, y);
	std::cout<<b;
	return 0;
}