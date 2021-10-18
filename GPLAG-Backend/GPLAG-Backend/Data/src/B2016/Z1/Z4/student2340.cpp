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
#include <stdexcept>

bool StringSamoSlova (std::string s){
	for(int i=0; i<s.length(); i++)
		if(s[i] < 'A' || s[i]>'z')
			return false;
	return true;
}

std::string FunkcijazaObrni(std::string s,std::string rijec){
	int i(0), j(0);
	std::string recenica(s);
		while(i<recenica.length()){
			j=0;
			while(recenica[i]==rijec[j]){
			i++;
			j++;
				if(j==rijec.length()-1 && recenica[i]==rijec[j]){
					int poz=i-rijec.length()+1;
						for(int p=0; p<rijec.length(); p++){
						recenica[poz+p]=rijec[rijec.length()-1-p];
						}
					}
			}
			i++;
		}
	return recenica;
}
	
	

std::string ObrniFraze(std::string s,std::vector<std::string> rijeci){
	std::string novarecenica(s);
	
		for(std::string rijec : rijeci){
			novarecenica=FunkcijazaObrni(novarecenica,rijec);
		}
	return novarecenica;
}

std::string FunkcijazaPig(std::string s,std::string rijec){
	int i(0), j(0);
	std::string novarijec(rijec+rijec[0]+"ay");
	std::string recenica(s);
		while(i<recenica.length()){
			j=0;
			while(recenica[i]==rijec[j]){
			i++;
			j++;
				if(j==rijec.length()-1 && recenica[i+1]== ' '){
				int poz=i-rijec.length()+1;
				recenica.insert(poz+rijec.length(), "   ");
				
						for(int p=0; p<novarijec.length(); p++){
						recenica[poz+p]=novarijec[p+1];
						} 
						
					}
			}
			i++;
		}
	return recenica;
}

std::string IzmijeniPigLatin (std::string s,std::vector<std::string> rijeci){
	std::string novarecenica(s);
	
		for(std::string rijec : rijeci){
			if(!(StringSamoSlova)) {
				throw std::domain_error ("Nekorektan izbor rijeci.");}
		novarecenica=FunkcijazaPig(novarecenica,rijec);
		}
	return novarecenica;
}


int main ()
{	std::vector<std::string> vektorrijeci;
	std::string recenica;
	std::string rijec;
	
		std::cout<<"Unesite recenicu: ";
		std::getline(std::cin,recenica);

		std::cout<<"Unesite fraze: ";
		
	while(std::getline(std::cin,rijec)){
			if(rijec == "") break;
		vektorrijeci.push_back(rijec);
	} 
	
	try{
	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniPigLatin(recenica, vektorrijeci);
	
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	
	try{
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, vektorrijeci);
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	
	return 0;
}