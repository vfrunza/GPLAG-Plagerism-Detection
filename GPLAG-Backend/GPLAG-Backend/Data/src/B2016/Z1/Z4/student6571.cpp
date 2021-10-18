/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
std::string ObrniFraze(std::string recenica, std::vector<std::string> popisrijeci){
	std::string rijec;
	int duzina;
	
	for(int i=0; i<popisrijeci.size(); i++){
		for(int j=0; j<recenica.length(); j++){
			if(popisrijeci[i]==recenica.substr(j,popisrijeci[i].size())){
				rijec=popisrijeci[i];
				std::reverse(rijec.begin(), rijec.end());
				duzina = rijec.length();
				recenica.replace(j, duzina, rijec);
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> popisrijeci){
	
	std::string nr[300];
	std::string pr;
	std::string nnr;
	std::vector<std::string> v;
		std::string rijec;
	std::string prvoslovo;
	std::string novarijec;
	std::string rijeciustring;
	std::string rijecc;
	std::string znak;
	int duzina;
	int brojac=0;
	if(popisrijeci.size()==0){
		
		for(int i=0; i<recenica.length(); i++){
			if(recenica[i]!=' ') {
				nr[brojac] += recenica[i];
			}
			else{
				brojac++;
			}
		}
		
		for(int i=0; i<=brojac; i++){
			for(int j=0; j<recenica.length(); j++){
				if(nr[i]==recenica.substr(j,nr[i].size())){
					rijec=nr[i];
					
					for(int i=0; i<rijec.length(); i++){
						if(i==0) prvoslovo=rijec[0];
						
						else{
							if((rijec[i]>='A'&&rijec[i]<='Z')||(rijec[i]>='a'&&rijec[i]<='z')){
								novarijec += rijec[i];
							}
							else{
								znak += rijec[i];
							}
						}
					}
					novarijec += prvoslovo;
					novarijec += "ay";
					if(znak.length()>0) novarijec += znak;
					duzina = rijec.length();
					znak.resize(0);
					recenica.replace(j, duzina, novarijec);
				}
				novarijec.resize(0);
			}
		}
		return recenica;
		
	}
	
	
	

	std::string r;
	for(int i=0; i<popisrijeci.size(); i++){
		r=popisrijeci[i];
		for(int j=0; j<r.length(); j++){
			if(!((r[j]>='A'&&r[j]<='Z')||(r[j]>='a'&&r[j]<='z'))){
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			}
		}
	}

	

	for(int i=0; i<popisrijeci.size(); i++){
		for(int j=0; j<recenica.length(); j++){
			if(popisrijeci[i]==recenica.substr(j, popisrijeci[i].size())){
				rijec=popisrijeci[i];
				
				for(int i=0; i<rijec.length(); i++){
					if(i==0) prvoslovo=rijec[0];
					
					else{
						if((rijec[i]>='A'&&rijec[i]<='Z')||(rijec[i]>='a'&&rijec[i]<='z')){
						novarijec += rijec[i];}
						else{
							znak += rijec[i];
						}
					}
				}
				novarijec += prvoslovo;
				novarijec += "ay";
				if(znak.length()>0) novarijec += znak;
				duzina = rijec.length();
				recenica.replace(j, duzina, novarijec);
				znak.resize(0);
			}
			novarijec.resize(0);
		}
	}
	return recenica;
}



int main(){
	std::string rijeci;
	std::string recenica;
	std::vector<std::string> popisrijeci;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	while(std::getline(std::cin, rijeci)){
		if(rijeci.size()==0) break;
		
		popisrijeci.push_back(rijeci);
	}
	try{
	std::string o(IzmijeniUPigLatin(recenica, popisrijeci));
	std::cout<<"Recenica nakon PigLatin transformacije: "<<o<<std::endl;
	

} 
catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what()<<std::endl;
}
std::string k(ObrniFraze(recenica, popisrijeci));
	std::cout<<"Recenica nakon obrtanja fraza: "<<k;
	return 0;
	
}

