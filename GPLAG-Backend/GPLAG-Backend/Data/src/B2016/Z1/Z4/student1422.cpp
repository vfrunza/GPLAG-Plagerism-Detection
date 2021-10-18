#include <iostream>
#include <vector>
#include <stdexcept>

typedef std::vector<std::string> Vektor;

//Obrce rijec
std::string ObrniRijec(std::string rijec){
	int i(int(rijec.length())-1),j(0);
	std::string pom;
	while(i>=0){
		pom.insert(pom.begin()+j,rijec[i]);
		i--;
		j++;
	}
	return pom;
}

std::string ObrniFraze(std::string recenica, Vektor popis){
	for(int i=0;i<int(popis.size());i++){
		int j(0);
		while(j<int(recenica.length())){
			std::string pom(recenica.substr(j,int(popis[i].length())));
			if(popis[i]==pom){
				recenica.erase(j,int(popis[i].length()));
				recenica.insert(j,ObrniRijec(popis[i]));
				j=0;
			}
			else j++;
		}
	}
	return recenica;
}

std::string UPigLatin(std::string rijec){
	int i(0);
	std::string pom;
	while(i<rijec.length()){
		if(i==0){
		pom=rijec.substr(0,1);
		rijec.erase(rijec.begin()+i);
		}
		i++;
	}
	return rijec+pom+"ay";
}

//provjerava treba li izbaciti izuzetak
bool EngleskiAlfabet(std::string rijec){
	int i(0);
	while(i<rijec.length()){
		if((rijec[i]>='a' && rijec[i]<='z')||(rijec[i]>='A' && rijec[i]<='Z'))
			i++;
		else return false;
	}
	return true;
}

bool IsAlpha(char slovo){
	if((slovo>='a' && slovo<='z')||(slovo>='A' && slovo<='Z'))
	return true;
	return false;
}

std::string IzmijeniUPigLatin(std::string recenica, Vektor popis){
	
	for(int i=0;i<int(popis.size());i++)
	if(!EngleskiAlfabet(popis[i]))	throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
	

	//ako je vektor prazan:
	if(int(popis.size())==0){
		int i(0),pocetak(0),kraj(0);
		while(i<=int(recenica.length())){
			if(i==int(recenica.length())-1 || recenica[i]==' ' || !(((recenica[i]>='a') && recenica[i]<='z')||(recenica[i]>='A' && recenica[i]<='Z'))){
				kraj=i;
				if(i==int(recenica.length())-1) kraj++;
				std::string pom(recenica.substr(pocetak,kraj-pocetak));
				recenica.erase(pocetak,kraj-pocetak);
				recenica.insert(pocetak,UPigLatin(pom));
				pocetak=pocetak+int(UPigLatin(pom).length())+1;
				i=pocetak;
			}
			else i++;
		}
		return recenica;
	}
	
	for(int i=0;i<int(popis.size());i++){
		int j(0);
		while(j<int(recenica.length())){
			std::string pom(recenica.substr(j,int(popis[i].length())));
			if(popis[i]==pom && (j==0 || !IsAlpha(recenica[j-1])) && (j+popis[i].length()==recenica.size() || !IsAlpha(recenica[popis[i].size()+j]))){
				recenica.erase(j,int(popis[i].length()));
				recenica.insert(j,UPigLatin(popis[i]));
				j=0;
			}
			else j++;
		}
	}
	return recenica;
}

int main (){
    std::string rec,s;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,rec);
    Vektor v;
    std::cout<<"Unesite fraze: ";
    do{
    	std::getline(std::cin,s);
    	if(s!="") v.push_back(s);
    }while(s!="");
    try{
    std::string pom(IzmijeniUPigLatin(rec,v));
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    std::cout<<pom;
    } 
    catch(std::domain_error izuzetak) {
    	std::cout<<izuzetak.what();
    }
    std::cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
    std::cout<<ObrniFraze(rec,v);
	return 0;
}