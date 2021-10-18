#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	
	for(auto fraza : fraze)
		for(int i=0;i+((int)fraza.size()-1)<(int)recenica.size();i++)
			if(recenica.substr(i,fraza.size())==fraza)
				for(int pocetak=i, kraj=i+fraza.size()-1;pocetak<=kraj;pocetak++,kraj--){
					char temp{recenica[pocetak]};
					recenica[pocetak]=recenica[kraj];
					recenica[kraj]=temp;
				}
	return recenica;
}

bool Isalpha(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return true;
	return false;
}

bool Alfabet(std::string rijec){
	for(int i=0;i<(int)rijec.size();i++)
		if(!Isalpha(rijec[i]))
			return false;
	if(!rijec.size())return false;
	return true;
}

std::string PigLatin(std::string fraza){
	fraza.push_back(fraza[0]);
	fraza.push_back('a');
	fraza.push_back('y');
	for(int i=0;i+1<(int)fraza.size();i++)
		fraza[i]=fraza[i+1];
	fraza.resize((int)fraza.size()-1);
	return fraza;
}

int KrajRijeci(std::string recenica, int pocetak_rijeci){
	int kraj{pocetak_rijeci};
	while(kraj<recenica.size() && Isalpha(recenica[kraj]))
		kraj++;
	return kraj-pocetak_rijeci;
}

std::string IzmijeniCitavuRecenicu(std::string recenica){
	for(int i=0;i<(int)recenica.size();i++){
		if(Isalpha(recenica[i]) && (i-1<0 || !Isalpha(recenica[i-1]))){
			int kraj{KrajRijeci(recenica,i)};
			if(i+kraj==(int)recenica.size() || !Isalpha(recenica[i+kraj])){
				std::string fraza=PigLatin(recenica.substr(i,kraj));
				recenica.erase(i,kraj);
				recenica.insert(i,fraza);
			}
		}		
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> fraze){
	
	for(auto fraza : fraze){
		
		if(!Alfabet(fraza)) throw std::domain_error("Nekorektan izbor rijeci");
		
		for(int i=0;i+((int)fraza.size()-1)<(int)recenica.size();i++)
			if(recenica.substr(i,fraza.size())==fraza && (i-1<0 || !Isalpha(recenica[i-1])) && ((i+(int)fraza.size())==recenica.size() || !Isalpha(recenica[i+(int)fraza.size()]))){
				recenica.erase(i,fraza.size());
				recenica.insert(i,PigLatin(fraza));
				i+=(int)fraza.size()+2;
			}
	}
	
	if(fraze.size()==0)
		recenica=IzmijeniCitavuRecenicu(recenica);
	
	return recenica;
}

int main (){
	
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;

	while(std::cin.peek()!='\n'){
		std::string fraza;
		std::getline(std::cin, fraza);
		fraze.push_back(fraza);
	}
	try{
	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, fraze)<<"\n";
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<"\n";}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze);
	
	return 0;
}