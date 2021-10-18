/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> vstr){
	bool a;
	for(int i(0); i<vstr.size(); i++){
		for(int j(0); j<s.length(); j++){
			if(vstr[i][0] == s[j]){
				a=true;
				for(int k(0); k<vstr[i].length(); k++){
					if(j+k > s.length()){
						a=false;
						break;
					}
					if(vstr[i][k] != s[j+k]){
						a=false;
						break;
					} 
				}
				
				if(a == true){
					for(int k=vstr[i].length()-1; k>=0; k--){
						s[j]=vstr[i][k];
						j++;
					}
				}
			}
		}
	}
	return s;
}

std:: string IzmijeniUPigLatin(std:: string s, std::vector<std::string> vstr){
	for(int i(0); i<vstr.size(); i++){
		for(int j(0); j<vstr[i].length(); j++){
			if(vstr[i][j]<65 || vstr[i][j]>122 ||(vstr[i][j]>90 && vstr[i][j]<97)) throw std::domain_error("Nekorektan izbor rijeci");
		}
		
	}
	
	bool a;
	for(int i(0); i<vstr.size(); i++){
		for(int j(0); j<s.length(); j++){
			if(vstr[i][0] == s[j]){
				a=true;
				for(int k(0); k<vstr[i].length(); k++){
					if(j+k > s.length()){
						a=false;
						break;
					}
					if(vstr[i][k] != s[j+k]){
						a=false;
						break;
					} 
				}
				
				if(a == true){
					char pomocna=vstr[i][0];
					for(int k(1); k<vstr[i].length(); k++){
						s[j]=vstr[i][k];
						j++;
					}
					s[j]=pomocna;
					j++;
					s.insert(j, "ay");
					j+=2;
				}
			}
		}
	}
	return s;
}


int main ()
{

	std::string str, pomocniS;
	std::string str1, str2;
	std::vector<std::string> vekstr;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, str);
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::getline(std::cin, pomocniS);
		if(pomocniS.length() == 0) break;
		vekstr.push_back(pomocniS);
	}
	
	str1=ObrniFraze(str, vekstr);
try{
	str2=IzmijeniUPigLatin(str, vekstr);

	std::cout<<"Recenica nakon PigLatin transformacije: "<<str2;
}catch(std::domain_error e){
	std::cout<<"Izuzetak: "<<e.what();
}	

	std::cout<<"\nRecenica nakon obrtanja fraza: "<<str1;
	return 0;
}