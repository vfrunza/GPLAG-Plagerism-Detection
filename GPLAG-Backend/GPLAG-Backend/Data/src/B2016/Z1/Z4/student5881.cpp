#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iomanip>

std::string IspisiUPigLatin(std::string s){
	std::string PigLatinska=s;
	PigLatinska.push_back(s[0]);
	PigLatinska.push_back('a');
	PigLatinska.push_back('y');
	PigLatinska=PigLatinska.substr(1,PigLatinska.size());
	return PigLatinska;
}

std::string Obrni(std::string s){
	std::string obrnuta;
	for(int i=s.length()-1; i>=0; i--){
		obrnuta.push_back(s[i]);
	}
	return obrnuta;
}

bool KontrolaRijeci(std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].length(); j++){
			if(!((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z') || v[i][j]==' ')) return true;
		}
	}
	return false;
}

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	if(KontrolaRijeci(v)) throw std::domain_error("Nekorektan izbor rijeci");
	for(int i=0; i<v.size(); i++){
		std::string pomocni(v[i]);
		int k(0);
		for(int j=0; j<s.length(); j++){
			if(pomocni[k]==s[j]){
				k++;
				if(k==pomocni.length()){
					int kraj(j);
					auto obrnuto(Obrni(pomocni));
					int p(0);
					for(int h=kraj-pomocni.length()+1; h<=kraj; h++){
						s[h]=obrnuto[p];
						p++;
					}
					k=0;
				}
			}
			else k=0;
		}
	}
	return s;
}

bool ViseRijeci(std::string s){
	for(int i=1; i<s.length()-1; i++){
		if(((s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='A' && s[i-1]<='Z')) && s[i]==' ' && ((s[i+1]>='a' && s[i+1]<='z') || (s[i+1]>='A' && s[i+1]<='Z'))) return true;
	}
	return false;
}

bool Dupla(std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		if(ViseRijeci(v[i])) return true;
	}
	return false;
}

bool Podstring(std::string s, int kraj, int duzina){
	if(kraj+1 <= s.length()){
		if((s[kraj+1]>='a' && s[kraj+1]<='z') || (s[kraj+1]>='A'  && s[kraj+1]<='Z')) return true;
	}
	if(kraj-duzina>=0){
		if((s[kraj-duzina]>='a' && s[kraj-duzina]<='z') || (s[kraj-duzina]>='A'  && s[kraj-duzina]<='Z')) return true;
	}
	return false;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	if(KontrolaRijeci(v)) throw std::domain_error("Nekorektan izbor rijeci");
	if(Dupla(v)) throw std::domain_error("Nekorektan izbor rijeci");
	for(int i=0; i<v.size(); i++){
		std::string pomocni(v[i]);
		int k(0);
		for(int j=0; j<s.length(); j++){
			if(pomocni[k]==s[j]){
				k++;
				if(k==pomocni.length()){
					int kraj(j);
					if(Podstring(s,kraj,pomocni.length())){k=0;continue;}
					auto pigl(IspisiUPigLatin(pomocni));
					s.resize(s.length()+2);
					for(int m=s.length(); m>kraj; m--) s[m]=s[m-1];
					for(int m=s.length(); m>kraj; m--) s[m]=s[m-1];
					int p(0);
					for(int h=kraj-pomocni.length()+1; h<=kraj+2; h++){
						s[h]=pigl[p];
						p++;
					}
					k=0;
				}
			}
			else k=0;
		}
	}
	return s;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	for(;;){
		std::getline(std::cin, fraza);
		if(fraza.length()!=0) fraze.push_back(fraza);
		if(std::cin.peek()=='\n') break;
	}
	try{
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze) << std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	try{
		std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
	}
	catch(std::domain_error izuzetak){
		std::cout <<  "Izuzetak: " << izuzetak.what() <<std::endl;
	}
	return 0;
}