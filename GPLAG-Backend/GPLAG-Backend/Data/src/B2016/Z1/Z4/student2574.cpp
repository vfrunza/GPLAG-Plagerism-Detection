/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

bool jel_slovo (char slovo_recenica) {
	if ((slovo_recenica>='a' && slovo_recenica<='z') || (slovo_recenica>='A' && slovo_recenica<='Z'))
		return true;
	return false;	
}
std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze) {
	std::string pomocni(recenica);
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<pomocni.length(); j++) {
			if (pomocni.compare(j, fraze.at(i).length(), fraze.at(i)) == 0) {
				for (int f=0; f<fraze.at(i).length(); f++) {
					auto pomoc3(pomocni.at(j+f));
					pomocni.at(j+f) = pomocni.at(j+fraze.at(i).length()-f-1);
					pomocni.at(j+fraze.at(i).length()-f-1) = pomoc3;
				}
			}
		}
	}
	return pomocni;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> fraze) {
	for (int i=0; i<fraze.size(); i++) { //size jer je VEKTOR
		for (int j=0; j<fraze.at(i).length(); j++) { //length jer je vektor STRINGOVA
			if ((fraze.at(i).at(j)<'A' || (fraze.at(i).at(j)>'Z' && fraze.at(i).at(j)<'a')) || ((fraze.at(i).at(j)>'Z' && fraze.at(i).at(j)<'a') || fraze.at(i).at(j)>'z')) 
				throw std::domain_error ("Nekorektan izbor riječi");
		}
	}
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (recenica.compare(j, fraze.at(i).length(), fraze.at(i)) == 0) {
				if (jel_slovo(recenica.at(j))==false && jel_slovo(recenica.at(j+fraze.at(i).length()))==false) {
					auto pomoc2 (recenica.at(j)); 						//Obrni riječi sa petljom
					for (int k=0; k<fraze.at(i).length()-1; k++) {
						recenica.at(k+j) = recenica.at(k+j+1);
						if (k==fraze.at(i).length()-2) 
							recenica.at(k+j+1) = pomoc2;
					}
					recenica.insert(j+fraze.at(i).length(),"ay");
				} 
			}
		}
	}
	return recenica;	
} 

int main () {
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string pomoc;
	for (;;) {
		std::getline(std::cin,pomoc);
		if (pomoc.size())
			fraze.push_back(pomoc);
		if (pomoc.size()==0)
			break;
	}
	try {
		auto vraca_pig (IzmijeniUPigLatin(recenica,fraze));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<vraca_pig<<std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze)<<std::endl;
	return 0;
}