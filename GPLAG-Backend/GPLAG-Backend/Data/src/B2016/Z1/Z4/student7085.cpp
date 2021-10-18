#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

typedef std:: vector<std::string> vekstring;

std::string ObrniRijec(std::string a)
{
	std::string b;
	for(int i=a.size()-1; i>=0; i--) b+=a[i];
	return b;
}

bool DaLiJeSlovo(vekstring v)
{
	for(std::string i:v) {
		for(int j:i) {
			if(toupper(j)<'A' || toupper(j)>'Z') return false;
		}
	}
	return true;
}

std:: string ObrniFraze( std:: string s, vekstring v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(s.substr(j,v[i].size())== v[i] ) {
				s=s.substr(0,j)+ObrniRijec(v[i])+s.substr(j+v[i].size(),s.size()-j-v[i].size());
			}
		}
	}
	return s;
}

std:: string ObrniLatin(std:: string s)
{
	s=s.substr(1,s.length()-1)+s[0]+"ay";
	return s;
}
bool slovo(char a)
{
	if(toupper(a)>='A' && toupper(a)<='Z') return true;
	return false;
}
std:: string IzmijeniUPigLatin(std:: string s, vekstring v)
{
	if(DaLiJeSlovo(v)==false) throw std:: domain_error("Nekorektan izbor rijeci");
	if(v.size()==0) {
		std::string pomocni;
		int poceo;
		for(int j=0; j<s.length();) {
			while(!slovo(s[j])) {
				pomocni.push_back(s[j]);
				j++;
			}
			while(slovo(s[j])) {
				if(((slovo(s[j]))  && j==0 ) || ((slovo(s[j])) && !slovo(s[j-1])))
					poceo=j;

				if((slovo(s[j])) && ((!slovo(s[j+1])) || j==s.length()-1))
					pomocni+=ObrniLatin(s.substr(poceo,j+1-poceo));
				j++;
			}
		}
		return pomocni;
	}

	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(s.substr(j,v[i].size())== v[i] && (j==0 || !slovo(s[j-1])) && (j+v[i].size()==s.length() || !slovo(s[j+v[i].size()])))
				s=s.substr(0,j)+ObrniLatin(v[i])+s.substr(j+v[i].size(),s.size()-j-v[i].size());

		}
	}
	return s;

}

int main ()
{
	std:: string s,s1,s2,a;
	vekstring v;
	std:: cout<< "Unesite recenicu: ";
	std:: getline(std::cin,s);
	std:: cout<< "Unesite fraze: ";
	while(1==1) {
		std::getline(std::cin,a);
		if(a.length()==0)break;
		v.push_back(a);
	}

	try {
		s1=IzmijeniUPigLatin(s,v);
		std:: cout<< "Recenica nakon PigLatin transformacije: ";
		std::cout<< s1;
	} catch(std:: domain_error e) {
		std::cout<< "Izuzetak: "<< e.what()<<std::endl;
	}


	s2=ObrniFraze(s,v);
	std:: cout<< "\nRecenica nakon obrtanja fraza: ";
	std:: cout<<s2;


	return 0;
}