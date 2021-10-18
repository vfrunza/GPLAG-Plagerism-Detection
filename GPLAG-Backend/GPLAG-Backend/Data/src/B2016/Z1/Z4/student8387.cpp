#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
int BrojRijeci(std::string s){
	int neslovo=1, broj_rijeci=0;
	for(int i=0;i<s.size();i++){
		if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
			neslovo = 1;
		else if (neslovo == 1) {
			neslovo = 0;
			broj_rijeci++;
		}
	}
	return broj_rijeci;
}
std::string LatinPig(std::string s){
	std::string p1;
	p1=s.substr(1,s.size()-1)+s[0]+"ay";
	return p1;
}
std::string Obrni(std::string s){
	std::string p1;
	for(int i=s.size()-1;i>=0;i--)
		p1+=s[i];
	return p1;
}
std::string ObrniFraze(std::string s,std::vector<std::string> v){
	int a(0);
	std::string p1=s;
	while(a<v.size()){
		for(int i=0;i<p1.size();i++){
			if(v[a]==p1.substr(i,v[a].size())){
				p1=p1.substr(0,i)+Obrni(v[a])+p1.substr(i+v[a].size(),p1.size()-i-v[a].size());
			}
		}
		a++;
	}
	return p1;
}
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	
	int a(0);
	std::string p1=s;
	while(a<v.size()){
		if(BrojRijeci(v[a])>1)throw std::domain_error("Nekorektan izbor rijeci");
		for(int i=0;i<p1.size();i++){
			if(v[a]==p1.substr(i,v[a].size())){
				p1=p1.substr(0,i)+LatinPig(v[a])+p1.substr(i+v[a].size(),p1.size()-i-v[a].size());
			}
		}
		a++;
	}
	return p1;
}
int main (){
	std::string Recenica;
    std::string Fraza;
    std::vector<std::string> a;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,Recenica);
    std::cout<<"Unesite fraze: ";
    while(1>0){
        std::getline(std::cin,Fraza);
        if(Fraza!="") a.push_back(Fraza);
        else break;
    }
    try{
    	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(Recenica,a)<<std::endl;
    }
    catch(std::domain_error izuzetak){
    	std::cout<<"Izuzetak: "<<izuzetak.what()<< std::endl;
    }
    std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(Recenica,a);
	return 0;
}