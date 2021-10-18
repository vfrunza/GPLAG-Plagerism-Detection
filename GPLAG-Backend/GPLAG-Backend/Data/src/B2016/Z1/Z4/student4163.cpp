/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

std::string obrni(std::string s){
	std::string obrnuti;
	for(int i=s.size()-1;i>=0;i--){
		obrnuti.push_back(s[i]);
	}
	return obrnuti;
}

std::string ObrniFraze(std::string s, std::vector<std::string>v){
	if(s.size()==0) return "";
	for(int i=0;i<v.size();i++){
		for(int j=0;j<(s.size()-v[i].size()+1);j++){
			if(s.substr(j,v[i].size())==v[i]){
				std::string pom="";
				pom+=s.substr(0,j)+obrni(s.substr(j,v[i].size()))+s.substr(j+v[i].size(),s.size()-j-v[i].size());
				s=pom;
			}
		}
	}
	return s;
}

std::string PigLatin(std::string rijec){
	std::string nova;
	
	for(int i=1;i<rijec.size();i++){
		nova.push_back(rijec[i]);
	}
	   nova=nova+rijec[0];
	  nova=nova+"ay";
	return nova;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>v){
	if(s.size()==0) return "";
	if(v.size()==0){
		for(int i=0;i<s.size();i++){
			if(toupper(s[i])<'A' || toupper(s[i])>'Z') continue;
			for(int j=0;j<s.size()-i;j++){
				if(toupper(s[i])>'A' && toupper(s[i])<'Z') continue;
				v.push_back(s.substr(i,j));
			}
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(toupper(v[i][j])<'A' || toupper(v[i][j])>'Z') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<(s.size()-v[i].size()+1);j++){
			if(s.substr(j,v[i].size())==v[i]){
				std::string pom="";
				pom+=s.substr(0,j)+PigLatin(s.substr(j,v[i].size()))+s.substr(j+v[i].size(),s.size()-j-v[i].size());
				s=pom;
			}
		}
	}
	return s;
}

int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::cin>>std::ws;
	std::getline(std::cin, recenica);
	std::vector<std::string>vektor;

	std::cout<<"Unesite fraze: ";
    std::string s;
    do{
	//	std::cin>>std::ws;
		std::getline(std::cin, s);
		if(s!="") vektor.push_back(s);
    }while(s!="");
    try{
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::string bla;
	bla=IzmijeniUPigLatin(recenica, vektor);
	for(int i=0;i<bla.size();i++){
		std::cout<<bla[i];
	}
    }catch(std::domain_error izuzetak){
    	
    	std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string nesto;
	nesto=ObrniFraze(recenica, vektor);
	for(int i=0;i<nesto.size();i++){
		std::cout<<nesto[i];
	}
	return 0;
}