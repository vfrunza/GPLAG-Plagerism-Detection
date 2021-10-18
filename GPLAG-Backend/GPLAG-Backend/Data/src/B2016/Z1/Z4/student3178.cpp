#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


std::string PigLatinuj(std::string rijec)
{
	std::string pigLatinovana;

	for(int i=1; i<rijec.length(); i++) {
		pigLatinovana.push_back(rijec.at(i));
	}

	pigLatinovana += rijec[0];
	pigLatinovana += "ay";
	return pigLatinovana;
}

bool DaLiJeSlovo(char slovo){
	return !(slovo<'A' || (slovo>'Z' && slovo<'a') || slovo>'z');
}

std::string IzmijeniUPigLatinSve(std::string recenica)
{
 
	for(int i {0}; i<recenica.size(); i++) {
		std::string rijec{};
		
		while( i < recenica.size() && !DaLiJeSlovo(recenica.at(i))) 
			i++;
	

		while( i < recenica.size() && DaLiJeSlovo(recenica.at(i))) 
			rijec.push_back(recenica.at(i++));
		
		
		if(i < recenica.size())
			recenica = recenica.substr(0, i- rijec.size()) + PigLatinuj(rijec) + recenica.substr(i);
			i+=2;
			}
	
	return recenica;
}




std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{

	if(v.size()==0) {
		return IzmijeniUPigLatinSve(s);
	}


	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).length(); j++) {
			if( (v.at(i)[j] < 'A') || (v.at(i)[j] > 'Z'  && v.at(i)[j] < 'a') ||  (v.at(i)[j] > 'z')) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}

	std::string rijec;
	std::string pigLatinovana;
	std::string finalni=s;
	for(int i=0; i<v.size(); i++) { //za vektor stringova, uzima pravu rec ili frazu koja je string
		for(int j=0; j<finalni.length(); j++) { 	//krece od pocetka recenice
			int brojac {0};
			for(int m=0; m<v.at(i).length(); m++) {
				if( v.at(i)[m] != finalni[j]) {
					break;
				}
				brojac++;
				//if( (j== (v.at(i).length() - 1) && v.at(i).length() == brojac && finalni.at(j+1) == ' ')  || (finalni[j-v.at(i).length()] == ' '  && v.at(i).length() == brojac && finalni.at(j+1) == ' ')  ||   (v.at(i).length() == brojac && finalni.at(j+1) == '\n' ) ) { //iz nekog razloga ovde nece da ti uzme u obzir poslednju rijec i fraze
				//if( (j<finalni.length()) && ((finalni.at(j) <= 'A') || ((finalni.at(j) >= 'Z') && (finalni.at(j) <= 'a')) || (finalni.at(j) >= 'z'))){
			 if((v.at(i).length() == brojac && finalni.at(j+1) == ' ') || (v.at(i).length() == brojac && finalni.at(j+1) == '\n' )) {
			//	if((v.at(i).length() == brojac) && ((finalni.at(j+1) < 'A') || ((finalni.at(j+1) > 'Z') && (finalni.at(j+1) < 'a')) || (finalni.at(j+1) > 'z'))) {
			// if( ((j-(v.at(i).length()-1))==0  && finalni.at(j+1) == ' ') || (v.at(i).length() == brojac && finalni.at(j+1) == '\n') || ((j-(v.at(i).length()-2)) == ' ' && v.at(i).length() == brojac && finalni.at(j+1) == ' ')){
		//	if( ( (v.at(i).length() == brojac) && (j < finalni.size()) && !DaLiJeSlovo(finalni.at(j+1)) ) || (   (j < finalni.size()) && (v.at(i).length() == brojac) && !DaLiJeSlovo(finalni.at(j+1)) && !DaLiJeSlovo(finalni.at(j-v.at(i).length()))) || (  (j < finalni.size()) && (v.at(i).length() == brojac) && !DaLiJeSlovo(finalni.at(j+1)) &&  !DaLiJeSlovo(finalni.at(j-v.at(i).length())) ) ) {
			rijec  = finalni.substr((j - (v.at(i).length()-1) ), v.at(i).length() );
					//imam rijec sada treba da je izvrnem
					pigLatinovana = PigLatinuj(rijec);
					finalni = finalni.substr(0, (j - (v.at(i).length()-1))) + pigLatinovana + finalni.substr(j+1, (finalni.length()-j));
				}
				j++;
			}
		}
	}
	return finalni;
}




std::string Izvrni(std::string rijec_ili_fraza)
{
	std::string izvrnuta;
	for(int i=rijec_ili_fraza.length()-1; i>=0; i--) {
		izvrnuta.push_back(rijec_ili_fraza.at(i));
	}
	return izvrnuta;
}

std::string ObrniFraze(std::string s, std::vector<std::string> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).length(); j++) {
			if( (v.at(i).at(j) < ' ') || ((v.at(i).at(j) > ' ') && (v.at(i).at(j) < 'A')) || ((v.at(i).at(j) > 'Z')  && (v.at(i).at(j) < 'a')) ||  (v.at(i).at(j) > 'z')) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}

	std::string rijec_ili_fraza;
	std::string izvrnuta;
	std::string finalni=s;
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<finalni.length(); j++) {
			int brojac {0};
			for(int m=0; m<v.at(i).length(); m++) {
				if( v.at(i)[m] != finalni[j]) {
					break;
				}
				brojac++; // && finalni[j+1] == ' ') || (v.at(i).length() == brojac && finalni[j+1] == '\n'
				if((v.at(i).length() == brojac )) {
					rijec_ili_fraza  = finalni.substr((j - (v.at(i).length()-1) ), v.at(i).length() );
					//imam rijec sada treba da je izvrnem
					izvrnuta = Izvrni(rijec_ili_fraza);
					finalni = finalni.substr(0, (j - (v.at(i).length()-1))) + izvrnuta + finalni.substr(j+1, (finalni.length()-j));
				}
				j++;
			}
		}
	}
	return finalni;
}



int main ()
{

	char recenica[200];
	char fraza[50];
	std::vector<std::string> v;

	std::cout << "Unesite recenicu: ";
	std::cin.getline(recenica, sizeof recenica);

	std::cout << "Unesite fraze: ";

	while(!std::cin || std::cin.peek() != '\n') {
		std::cin.getline(fraza, sizeof fraza);
		v.push_back(fraza);
	}


	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, v) << std::endl;

	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}


	try {
		std::cout << "Recenica nakon obrtanja fraza: " <<  ObrniFraze(recenica,v) << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}

	return 0;
}

/*#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


std::string PigLatinuj(std::string rijec)
{
	std::string pigLatinovana;

	for(int i=1; i<rijec.length(); i++) {
		pigLatinovana.push_back(rijec.at(i));
	}

	pigLatinovana += rijec[0];
	pigLatinovana += "ay";
	return pigLatinovana;
}


std::string IzmijeniUPigLatinSve(std::string recenica)
{
 std::string finalni=recenica;
 
	for(int i {0}; i<finalni.size(); i++) {
		std::string rijec;

		while( i < finalni.size()) {
			if( (finalni.at(i) >= 'A' && finalni.at(i) <= 'Z') || (finalni.at(i) >= 'a' && finalni.at(i) <= 'z'))
				break;
			i++;
		}

		while( i < finalni.size()) {
			if((finalni.at(i) <= 'A') || ((finalni.at(i) >= 'Z') && (finalni.at(i) <= 'a')) || (finalni.at(i) >= 'z'))
				break;
			rijec.push_back(finalni.at(i));
			i++;
		}

	
			finalni = finalni.substr(0, i- rijec.size()) + PigLatinuj(rijec)+ finalni.substr(i,finalni.size() );

	}
	return finalni;
}




std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{

	if(v.size()==0) {
		std::string finalni1=s;
		finalni1=IzmijeniUPigLatinSve(s);
		return finalni1;
	}


	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).length(); j++) {
			if( (v.at(i)[j] < 'A') || (v.at(i)[j] > 'Z'  && v.at(i)[j] < 'a') ||  (v.at(i)[j] > 'z')) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}

	std::string rijec;
	std::string pigLatinovana;
	std::string finalni=s;
	for(int i=0; i<v.size(); i++) { //za vektor stringova, uzima pravu rec ili frazu koja je string
		for(int j=0; j<finalni.length(); j++) { 	//krece od pocetka recenice
			int brojac {0};
			for(int m=0; m<v.at(i).length(); m++) {
				if( v.at(i)[m] != finalni[j]) {
					break;
				}
				brojac++;
				//if( (j== (v.at(i).length() - 1) && v.at(i).length() == brojac && finalni.at(j+1) == ' ')  || (finalni[j-v.at(i).length()] == ' '  && v.at(i).length() == brojac && finalni.at(j+1) == ' ')  ||   (v.at(i).length() == brojac && finalni.at(j+1) == '\n' ) ) { //iz nekog razloga ovde nece da ti uzme u obzir poslednju rijec i fraze
				if((v.at(i).length() == brojac && finalni.at(j+1) == ' ') || (v.at(i).length() == brojac && finalni.at(j+1) == '\n' )) {
					rijec  = finalni.substr((j - (v.at(i).length()-1) ), v.at(i).length() );
					//imam rijec sada treba da je izvrnem
					pigLatinovana = PigLatinuj(rijec);
					finalni = finalni.substr(0, (j - (v.at(i).length()-1))) + pigLatinovana + finalni.substr(j+1, (finalni.length()-j));
				}
				j++;
			}
		}
	}
	return finalni;
}

//}





std::string Izvrni(std::string rijec_ili_fraza)
{
	std::string izvrnuta;
	for(int i=rijec_ili_fraza.length()-1; i>=0; i--) {
		izvrnuta.push_back(rijec_ili_fraza.at(i));
	}
	return izvrnuta;
}



std::string ObrniFraze(std::string s, std::vector<std::string> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).length(); j++) {
			if( (v.at(i).at(j) < ' ') || ((v.at(i).at(j) > ' ') && (v.at(i).at(j) < 'A')) || ((v.at(i).at(j) > 'Z')  && (v.at(i).at(j) < 'a')) ||  (v.at(i).at(j) > 'z')) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}

	std::string rijec_ili_fraza;
	std::string izvrnuta;
	std::string finalni=s;
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<finalni.length(); j++) {
			int brojac {0};
			for(int m=0; m<v.at(i).length(); m++) {
				if( v.at(i)[m] != finalni[j]) {
					break;
				}
				brojac++; // && finalni[j+1] == ' ') || (v.at(i).length() == brojac && finalni[j+1] == '\n'
				if((v.at(i).length() == brojac )) {
					rijec_ili_fraza  = finalni.substr((j - (v.at(i).length()-1) ), v.at(i).length() );
					//imam rijec sada treba da je izvrnem
					izvrnuta = Izvrni(rijec_ili_fraza);
					finalni = finalni.substr(0, (j - (v.at(i).length()-1))) + izvrnuta + finalni.substr(j+1, (finalni.length()-j));
				}
				j++;
			}
		}
	}
	return finalni;
}



//int main(){

//	std::cout << IzmijeniUPigLatinSve("Danas je lijep i suncan dan");
//}
int main ()
{

	char recenica[200];
	char fraza[50];
	std::vector<std::string> v;

	std::cout << "Unesite recenicu: ";
	std::cin.getline(recenica, sizeof recenica);

	std::cout << "Unesite fraze: ";

	while(!std::cin || std::cin.peek() != '\n') {
		std::cin.getline(fraza, sizeof fraza);
		v.push_back(fraza);
	}


	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, v) << std::endl;

	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}


	try {
		std::cout << "Recenica nakon obrtanja fraza: " <<  ObrniFraze(recenica,v) << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}

	return 0;
}

*/