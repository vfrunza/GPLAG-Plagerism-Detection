/*B 2016/2017, Zadaća 1, Zadatak 4 zadnji
	
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

std::string PigLatin (std::string s){
	s=s.substr(1, s.size()-1)+s.at(0)+"ay";
	return s;
}
std::string SvePigLatin (std::string s){
	int i(0);
	std::string novi;
	while(i<s.size()){
		while(i<s.size() && (s.at(i)<'A' || (s.at(i)>'Z' && s.at(i)<'a') || s.at(i)>'z')){
			if(i==s.size()-1) break;
			novi.push_back(s.at(i));
			i++;
		}
		std::string fraza;
		while(i<s.size() && ((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z'))){
			fraza.push_back(s.at(i));
			i++;
			if(i==s.size()-1) break;
		}
		novi+=PigLatin(fraza);
	}
	return novi;
}
std::string Obrni (std::string s){
	for (int i(0); i<s.size()/2; i++){
		char temp;
		temp=s.at(i);
		s.at(i)=s.at(s.size()-1-i);
		s.at(s.size()-1-i)=temp;
	}
	return s;
}
std::string ObrniFraze (std::string s, std::vector<std::string>fraze){
	for(int j(0); j<fraze.size(); j++){
		int i(0);
		while(i<s.size()){
			while(i<s.size() && (s.at(i)<'A' || (s.at(i)>'Z' && s.at(i)<'a') || s.at(i)>'z')){
				i++;
				if(i==s.size()-1) break;
			}
			if(s.substr(i, fraze[j].size())==fraze.at(j)){
				s = s.substr(0, i) + Obrni(fraze.at(j)) + s.substr((fraze[j].size()+i), s.size()-fraze[j].size()-i);
			}
			i++;
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> fraze){
	//prvo radim provjeru fraza, i ako ima viserjecna fraza, ili nesto sto ne pripada americkom alfabetu, izbacuje odmah gresku
	for(int i(0); i<fraze.size(); i++){
		for(int j(0); j<fraze[i].size(); j++){
			if(fraze[i].at(j)<'A' || (fraze[i].at(j)>'Z' && fraze[i].at(j)<'a') || fraze[i].at(j)>'z') throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	if(fraze.size()==0){
		s=SvePigLatin(s);
		return s;
	}
	
	int i(0);
	while(i<s.size()){
		while(i<s.size() && (s.at(i)<'A' || (s.at(i)>'Z' && s.at(i)<'a') || s.at(i)>'z')){
			i++;
			if(i==s.size()-1) break;
		}
		
		for(int j(0); j<fraze.size(); j++){
			if( (s.substr(i, fraze[j].size())==fraze.at(j))){
				s=s.substr(0, i)+ PigLatin(fraze.at(j))+s.substr((fraze[j].size()+i), s.size()-fraze[j].size()-i);
			}
		}
		while(i<s.size() && ((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z'))){
			i++;
		}
	}
	return s;
}


int main(){
		std::vector<std::string> v;
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	
	for(;;){
		std::string temp;
		std::getline(std::cin, temp);
		if(temp.size()==0) break;
		v.push_back(temp);
	}
	
    
	
	try{

	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s, v)<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s, v)<<std::endl;
}
catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what()<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s, v)<<std::endl;
}
    return 0;
}
