#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string Obrcemrijec(std::string recenica1,std::string rijec1){
	
	std::string recenica=recenica1;
	std::string rijec=rijec1;
	int m=rijec.length();
	int r=recenica.length();
	
	for(int i(0);i<r-m+1;i++){
		if(recenica.substr(i,m)==rijec){
			std::string tmp=recenica.substr(i,m);
			int x=tmp.length();
			for(int j(0);j<x/2;j++){
				char t2=tmp[j];
				tmp[j]=tmp[x-j-1];
				tmp[x-j-1]=t2;
			}
			int pos=i;
			for(int j(0);j<x;j++){
				recenica[i]=tmp[j];
				i++;
			}
			i=pos;
		}
	}
	return recenica;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> rijeci){
	for(int i(0);i<rijeci.size();i++){
		recenica=Obrcemrijec(recenica,rijeci[i]);
	}
	return recenica;
}
std::string Rijecupig(std::string rijec1){
	//std::string recenica=recenica1;
	if(rijec1.size()==0) return rijec1;
	std::string rijec=rijec1;
	int m=rijec.length();
//	for(int i(0);i<recenica.length()-m+1;i++){
	std::string s=rijec.substr(1,m-1)+rijec.substr(0,1)+"ay";
	
	return s;
	
}
std::string Izmjenialmaljepigalatina(std::string recenica, std::string rijec){
	int m=rijec.length();
	for(int i(0);i<recenica.length()-1;i++){
		if(recenica.substr(i,m)==rijec){
			if(i!=0 && (i+m)!=recenica.length()){
			if(recenica.substr(i-1,1)==" " && recenica.substr(i+m,1)==" "){
			std::string pom=Rijecupig(rijec);
			recenica=recenica.substr(0,i)+pom+recenica.substr(i+rijec.length(),recenica.length()-i-rijec.length());
		}}
		
		else if (i==0 && i+m!=recenica.length() ){
			std::string pom=Rijecupig(rijec);
			recenica=pom+recenica.substr(i+rijec.length(),recenica.length()-i-rijec.length());
		}
		else if(i!=0 && i+m==recenica.length()){
			std::string pom=Rijecupig(rijec);
			recenica=pom+recenica.substr(0,i);
		}
		else if(i==0 && i+m==recenica.length()){
			std::string pom=Rijecupig(rijec);
			recenica=pom;
		}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci){
	for(int i(0);i<rijeci.size();i++){
		std::string rec=rijeci[i];
		for(int j(0);j<rec.length();j++){
			
			if(rec[j]==' ') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(rijeci.size()==0){
		int duzinarijec(0);
		std::string novarecenica;
		for(int i(0);i<recenica.length();i++){
			duzinarijec++;
			if(recenica[i]==' ' || i==recenica.length()-1){
				std::string jednarijec=recenica.substr(i+1-duzinarijec,duzinarijec-1);
				duzinarijec=0;
				jednarijec=Rijecupig(jednarijec);
				novarecenica=novarecenica+jednarijec+" ";
			}
		}
		novarecenica.resize(novarecenica.length()-1);
		return novarecenica;
	}
	else{
	for(int i(0);i<rijeci.size();i++){
			recenica=Izmjenialmaljepigalatina(recenica,rijeci[i]);
		}
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::string fraza;
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	while(true){
		std::getline(std::cin,fraza);
		if(fraza.length()!=0){ 
		fraze.push_back(fraza);}
		for(int i(0);i<fraza.size();i++){
			if(!((fraza[i]<='Z' && fraza[i]>='A') || (fraza[i]>='a' && fraza[i]<='z') || fraza[i]==' ')) throw std::domain_error ("Nekorektan izbor rijeci");
		}
		if(std::cin.peek()=='\n') break;
	}
	try {
	std::string pomocni=IzmijeniUPigLatin(recenica,fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<pomocni<<std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what() << std::endl;
	}
	
	
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze);

return 0;
}