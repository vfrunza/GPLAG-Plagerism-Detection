#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void JednaPoJedna(std::string &recenica, std::string rijec){
	
	int indeks_slova(0);
	
	for(int i(0); i < recenica.length(); i++){
		indeks_slova= 0;
		
		if(recenica[i] == rijec[0]){
			int indeks(i);
			while(recenica[i] == rijec[indeks_slova] && i < recenica.length() && indeks_slova < rijec.length()){
				i++;
				indeks_slova++;
			}
			if(indeks_slova == rijec.length()){
				
				int temp(indeks_slova);
				
				for(int k(indeks); k < indeks +indeks_slova; k++){
					recenica[k] = rijec[temp - 1];
					temp--;
				}
				i--;
			}
		}
	}
}

void Pigli(std::string &recenica, std::string rijec){
	int indeks_slova(0);
	int k(0);
	
	for(int i(0); i < rijec.size() ; i++){
		if( !((rijec[i] >= 'A' && rijec[i] <= 'Z') || (rijec[i] >= 'a' && rijec[i] <= 'z'))) throw std::domain_error("Nekorektan izbor rijeci");
	}
	
	for(int i(0); i < recenica.length()+1; i++){
		indeks_slova = 0;
		
		if(recenica[i] == rijec[0] && ( i == 0 || i == recenica.length() || recenica[i - 1] == ' ' )){
			int indeks(i);
			while(recenica[i] == rijec[indeks_slova]){
				i++;
				indeks_slova++;
			}
			if(indeks_slova == rijec.length()){
				
				char Zapamti_me(recenica[indeks]);
				
				for(k = indeks; k < indeks + indeks_slova - 1; k++){
					recenica[k] = recenica[k+1];
				}
				recenica[k] = Zapamti_me;
				
				recenica = recenica.substr(0, indeks + rijec.size()) + "ay" + recenica.substr(indeks + rijec.size(), recenica.length());
			}
		}
	}
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> frazice){
	
	for(int i(0); i < frazice.size(); i++){
		JednaPoJedna(recenica, frazice.at(i));
	}
	
	std::string Nova_recenica(recenica);
	
	return Nova_recenica;
	
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> frazice){
	
	std::vector<std::string> prazan;
	
	if(frazice != prazan){
		for(int i(0); i < frazice.size(); i++)
		Pigli(recenica, frazice.at(i));
	}
	
	else if(frazice.size()  == prazan.size()){
		
		if(recenica.size() == 0)throw std::domain_error("Nekorektan izbor rijeci");
		std::string rijec;
		std::string prazan2;
		std::vector<std::string> nove_fraze;
		
		for(int i(0); i < recenica.length(); i++){
			rijec = prazan2;
			if((recenica[i] >= 'A' && recenica[i] <='Z') || (recenica[i] >= 'a' && recenica[i] <= 'z')){
				while( i < recenica.length() && ((recenica[i] >= 'A' && recenica[i] <= 'Z') || (recenica[i] >= 'a' && recenica[i] <='z') )){
					rijec.push_back(recenica[i]);
					i++;
				}
				nove_fraze.push_back(rijec);
			}
		}
		
		for(int i(0); i < nove_fraze.size(); i++){
			Pigli(recenica, nove_fraze.at(i));
		}
	}
	
	std::string Nova_recenica(recenica);
	return Nova_recenica;
}
int main(){
	
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);

	std::cout <<"Unesite fraze: ";
	
	std::string prazan;
	std::vector<std::string> fraze;
	std::string fraza;
	
	for(;;){
		std::getline(std::cin, fraza);
		if(fraza == prazan)break;
		fraze.push_back(fraza);
	}
	
	std::vector<std::string> prazan2;
	
	try{
		std::string Nova(IzmijeniUPigLatin(recenica, fraze));
		std::cout << "Recenica nakon PigLatin transformacije: " << Nova << std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " <<  izuzetak.what() << std::endl;
	}
		std::string Nova2(ObrniFraze(recenica, fraze));
		std::cout << "Recenica nakon obrtanja fraza: " << Nova2 << std::endl;
	
	return 0;
	
}