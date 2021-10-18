#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string>Pretvorba(std::string s) {
	std::vector<std::string>v;
    v.push_back(" ");
	for (int i=0; i<s.size(); i++) {
    if (s[i]==' ') v.push_back(" ");
    else v[v.size()-1]=v[v.size()-1]+s[i];
	}
  return v;	
}
std::string ObrnutaPretvorba(std::vector<std::string>v) {
	std::string s;
	for (int i=0; i<v.size(); i++) {
		s+=v[i];
		s+=" ";
	}
	return s;
}
std::string ObrniFraze (std::string s, std::vector<std::string>v) {
	std::vector<std::string>vs; vs=Pretvorba(s); 
	for (int i=0; i<vs.size(); i++) {
		for (int j=0; j<v.size(); j++) {
			
			if (vs[i][0]==' ') {
				for (int k=0; k<vs[i].size()-1; k++)
				vs[i][k]=vs[i][k+1];
				vs[i].resize(vs[i].size()-1);
			}
			int m=0;
			while (i<vs[i].size() && vs[i][m]==' ') m++;  
			std::string str1=vs[i].substr(m,vs[i].size()); 
			int duz=vs[i].size()-m;
			if (str1==v[j]) { 
				std::string str; str=str1;
				for(int k=0; k<str.size()/2; k++) {
					char temp=char(str[k]);
					str[k]=str[str.size()-k-1]; 
					str[str.size()-k-1]=temp;
				}
				std::string s2;
				if (duz>=1) {     //dodano
					s2[0]=' ';
					for (int n=0; n<duz; n++) s2[n]=s2[n]+' ';
					s2+=str;
				}
				vs[i]=s2;
			}
		}
	}
	std::string s1;
	s1=ObrnutaPretvorba(vs);
	return s1;
}
std::string IzmijeniUPigLatin (std::string s, std::vector<std::string>v) {
	std::vector<std::string> vs;
	vs=Pretvorba(s);
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v[i].size(); j++) {
			if(!((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z'))) {
				throw std::domain_error("Nekorektan izbor rijeci");
			} 
		}
	}
	for (int i=0; i<vs.size(); i++) {
		for (int j=0; j<v.size(); j++) {
			if (vs[i][0]==' ') {
				for (int k=0; k<vs[i].size()-1; k++)
				vs[i][k]=vs[i][k+1];
				vs[i].resize(vs[i].size()-1);
			}
			if (vs[i]==v[j]) {
				std::string str;
				str=vs[i];
				str=vs[i].substr(1,vs[i].size()-1)+vs[i].substr(0,1)+"ay";
				vs[i]=str;
			}
		}
	} 
	std::string s1;
	s1=ObrnutaPretvorba(vs);
	return s1;
}
int main () {
	
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::vector<std::string>v;
	std::cout<<"Unesite fraze: ";
	std:: string s;
	
	while (1) {
		std::getline(std::cin, s);
		if (s=="") break;
		v.push_back(s);
}

	std::string s1;
	s1=ObrniFraze(recenica,v);
	std::string s2;
	try{
	s2=IzmijeniUPigLatin(recenica,v);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<s2<<std::endl;
	}
	catch (std::domain_error izuzetak) {
	std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
}

	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<s1;

	return 0;
}