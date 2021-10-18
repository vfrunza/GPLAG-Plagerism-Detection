#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
std::string ObrniFraze(std::string s,std::vector<std::string>v)
{
	int pocetak(0),brojac(0);
	std::vector<int>indexi;
	for(int i=0; i<v.size(); i++) {
		brojac=0;
		for(int j=0; j<s.size(); j++) {
			brojac=0;
			if(v[i][0]==s[j]) {
				pocetak=j;
			}
			while(v[i][brojac]==s[j] && brojac <=v[i].size() && j<s.size()) {
				if(brojac==v[i].size()-1) {
					indexi.push_back(pocetak);
					indexi.push_back(brojac);
				}
				brojac++;
				j++;
			}
			brojac++;
		}
	}
	
	for(int i=0; i<indexi.size(); i+=2) {
		auto itpocetak(s.begin()+indexi[i]);
		auto itkraj(itpocetak+indexi[i+1]+1);
		std::reverse(itpocetak,itkraj);
	}
	for(int i=0;i<s.size();i++)std::cout<<s;
	return s;
}
std::string PigLatin(std::string s){
	char c = s[0];
	for(int i=0; i<s.size(); i++)s[i]=s[i+1];
	s[s.size()-1]=c;
	s+="ay";
	//std::cout<< s <<std::endl;
	return s;
}
std::string IzmijeniUPigLatin (std::string s,std::vector<std::string>v)
{
	for(int i=0; i<v.size();i++)
		for(int j=0; j<v[i].size();j++){
			if(v[i][j]<65)throw std::domain_error("Nekorektan izbor riječi");
			if(v[i][j]>90 && v[i][j]<97)throw std::domain_error("Nekorektan izbor riječi");
			if(v[i][j]>122)throw std::domain_error("Nekorektan izbor riječi");
		}
	std::string pomocni;
	int pocetak(0),brojac(0);
	std::vector<int>indexi;
	for(int i=0; i<v.size(); i++) {
		brojac=0;
		for(int j=0; j<s.size(); j++) {
			brojac=0;
			if(v[i][0]==s[j]) {
				pocetak=j;
			}
			while(v[i][brojac]==s[j] && brojac <=v[i].size() && j<s.size()) {
				if(brojac==v[i].size()-1) {
					indexi.push_back(pocetak);
					indexi.push_back(brojac);
				}
				brojac++;
				j++;
			}
			brojac++;
		}
	}
	std::string s2=s;
	int p(indexi[0]);
	for(int i=0; i<indexi.size(); i+=2) {
		pomocni.resize(indexi[i+1]+1);
		auto itpocetak(s2.begin()+indexi[i]);
		if(i!=0)p=indexi[i]+i;
		auto itkraj(itpocetak+indexi[i+1]+1);
		std::copy(itpocetak,itkraj,pomocni.begin());
		s.erase(p,indexi[i+1]+1);
		s.insert(p,PigLatin(pomocni));
	}
	
	return s;
}
int main ()
{
	
		std::string s,s1;
		std::vector<std::string>v;
	try{
		std::cout<<"Unesite recenicu: ";
		std::getline(std::cin,s);
		std::cout<<"Unesite fraze: ";
		while(std::getline(std::cin,s1),int(s1.size()!=0))	v.push_back(s1);
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v)<<std::endl;
	}catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
		s1=ObrniFraze(s,v);
		std::cout<<"Recenica nakon obrtanja fraza: ";
		std::cout << s1 << std::endl;

	
	return 0;
}