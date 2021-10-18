#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;

typedef std::vector<string> Vektor;

string ObrniFraze(string recenica, Vektor rijeci){
	for(string abc : rijeci){
		int br(0);
		for(int i = 0; i < recenica.size(); i++){
//				if(abc[br] < ' ' || abc[br] > 126 || recenica[i] < ' ' || recenica[i] > 126) throw std::domain_error("Nekorektan izbor rijeci");
				if(abc[br] == recenica[i]){	
					if(br == abc.size() - 1){
						for(int j = i - br; j <= i; j++){
							recenica[j] = abc[br];
							br--;
						}
						br = 0;
					}
					br++;
				}
				else br = 0;
			}
			
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica, Vektor rijeci){
	if(rijeci.size() == 0){
		bool rijec(false);
		int brojac(0);
		for(int i = 0; i < recenica.size(); i++){
			if(!rijec/* == false */ && ((recenica[i] >= 'A' && recenica[i] <= 'Z') || (recenica[i] >= 'a' && recenica[i] <= 'z')))
				rijec = true;
			if(rijec) brojac++;
			if((i == recenica.size() - 1 || ((recenica[i+1] < 'A' || recenica[i+1] > 'z') || (recenica[i+1] < 'a' && recenica[i+1] > 'Z'))) && rijec){
				recenica = recenica.substr(0, i - brojac + 1) + recenica.substr(i - brojac + 2, brojac - 1) + recenica[i - brojac + 1] + "ay" + recenica.substr(i + 1, recenica.size() - i);
				rijec = false;
				brojac = 0;
				i+=2;
			}
			
		}
	}
	for(string abc : rijeci){
		int br(0);
		bool razliciti(true);
		for(int i = 0; i < recenica.size(); i++){
				if(i < abc.size() && ((abc[i] < 'A' || abc[i] > 'z') || (abc[i] < 'a' && abc[i] >'Z'))) throw std::domain_error("Nekorektan izbor rijeci");
				if(i == 0) razliciti = false;
				if(i < recenica.size() - 1 && i > 0 && br < abc.size() - 1  && ((recenica[i] < 'A' || recenica[i] > 'z') || (recenica[i] < 'a' && recenica[i] > 'Z')) && ((recenica[i+1] >= 'A' && recenica[i+1] <= 'Z') || (recenica[i+1] >= 'a' && recenica[i+1] <= 'z')))
					razliciti = false;
				else{
					if(abc[br] == recenica[i] && razliciti == false){
						if(br == abc.size() - 1){
							if(i == recenica.size() - 1 || (((recenica[i] >= 'A' && recenica[i] <= 'Z') || (recenica[i] >= 'a' && recenica[i] <= 'z')) && ((recenica[i+1] < 'A' || recenica[i+1] > 'z') || (recenica[i+1] < 'a' && recenica[i+1] > 'Z'))))
							recenica = recenica.substr(0, i - abc.size() + 1) + recenica.substr(i - br + 1, br) +  recenica[i - br] + "ay" + recenica.substr(i + 1, recenica.size() - i);
							br = 0;
							i+=2;
						}
						br++;
					}
					else {
						br = 0;
						razliciti = true;
					}
				}
			}
	}
	return recenica;
}
int main ()
{
	try{
		Vektor rijeci;
		string recenica;
		cout << "Unesite recenicu: ";
		std::getline(cin, recenica);
		cout << "Unesite fraze: ";
		string fraze;
		while(std::getline(cin, fraze)){
			if(fraze.size() == 0)
				break;
			rijeci.push_back(fraze);
		}
		cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, rijeci) << std::endl;
		cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, rijeci);
	}
	
	catch(std::domain_error izuzetak){
		cout << "Izuzetak: " << izuzetak.what();
	}
	return 0;
}