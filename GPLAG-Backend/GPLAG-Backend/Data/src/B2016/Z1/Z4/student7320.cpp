/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream> 
#include <vector>
#include <string>
#include <stdexcept>

#define pb push_back
std::string ObrniString(std::string x) {
	std::string ret{""};
	for (int i = x.length() - 1; i >= 0; i--) ret.pb(x.at(i));
	return ret;
}
bool slovo(char c) {
	return (c != ' ');
	//return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool slovo2(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
std::string ObrniFraze(std::string ulazni, std::vector<std::string> rijeci) {
	if (rijeci.size() == 0) return ulazni;
	for (int i = 0; i < rijeci.size(); i++) {
		
		std::string TrenutnaRijec = rijeci.at(i);
		if (TrenutnaRijec.length() == 0) continue; // ako ne prodje obrisi ovo
		std::vector<int> MoguciIndeksi;
		
		for (int j = 0; j < ulazni.length(); j++) {
			
			std::string podstring = ulazni.substr(j, rijeci.at(i).length());
			//std::cout << podstring << "\n";
			if (podstring == rijeci.at(i)) {
				std::string obrnuti = ObrniString(podstring);
				int kkk = 0;
				for (int k = j; k < j + podstring.length(); k++)
					ulazni[k] = obrnuti[kkk++];
				if (podstring.length() != 1) j--;
			}
		}
		
	}
	return ulazni;
}
std::string OdradiKonverziju(std::string rijec) {
	std::string ret{""};
	for (int i = 1; i < rijec.length(); i++) ret.pb(rijec[i]);
	ret.pb(rijec[0]);
	ret += ("ay");
	return ret;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci) {
	
	for (auto checkam : rijeci) {
		for (int i = 0; i < checkam.length(); i++) {
			if (!slovo2(checkam[i])) {
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	std::vector<std::string> izdvojene;
	std::vector<int> indeksi;
	std::string Temporarni{""}, pretvoren;
	for (int i = 0; i < recenica.length(); i++) {
		if (slovo2(recenica[i])) Temporarni.pb(recenica[i]);
		else {
			if (Temporarni.length()) {
				
				if (rijeci.size() != 0) {
					for (int j = 0; j < rijeci.size(); j++) {
						if (Temporarni == rijeci.at(j)) {
							int poc_ind = i - Temporarni.length();
							pretvoren = OdradiKonverziju(Temporarni);
							recenica.insert(poc_ind, pretvoren);
							recenica.erase(poc_ind + pretvoren.length(), pretvoren.length() - 2);
							i--;
						}
					}
				}
				else {
					//std::cout << "USO " << Temporarni << "\n";
					int poc_ind = i - Temporarni.length();
					pretvoren = OdradiKonverziju(Temporarni);
					recenica.insert(poc_ind, pretvoren);
					recenica.erase(poc_ind + pretvoren.length(), pretvoren.length() - 2);
					i++;
				}
				//izdvojene.pb(Temporarni);
				//indeksi.pb(i - Temporarni.length());
			}
			Temporarni.clear();
		}
	}
	if (Temporarni.length()) {
		if (rijeci.size() != 0) {
			for (int j = 0; j < rijeci.size(); j++) {
				if (Temporarni == rijeci.at(j)) {
					int poc_ind = recenica.length() - Temporarni.length();
					pretvoren = OdradiKonverziju(Temporarni);
					recenica.insert(poc_ind, pretvoren);
					recenica.erase(poc_ind + pretvoren.length(), pretvoren.length() - 2);
				}
			}
		}
		else {
			int poc_ind = recenica.length() - Temporarni.length();
			pretvoren = OdradiKonverziju(Temporarni);
			recenica.insert(poc_ind, pretvoren);
			recenica.erase(poc_ind + pretvoren.length(), pretvoren.length() - 2);
		}
	}
	/*
	std::vector<std::string> izdvojeneKonverzija = izdvojene;
	
	if (rijeci.size() == 0) {
		//std::cout << "U IFU SAM!";
		for (int i = 0; i < izdvojene.size(); i++) {
			int startInd = indeksi[i];
			izdvojeneKonverzija[i] = OdradiKonverziju(izdvojene[i]);
			recenica.insert(startInd, izdvojeneKonverzija[i]);
			recenica.erase(startInd + izdvojeneKonverzija[i].length(), izdvojene[i].length());
			for (int x = i; x < indeksi.size(); x++) indeksi[x] += 2;
		}
	}
	
	else {
	for (int i = 0; i < izdvojene.size(); i++) {
		for (int j = 0; j < rijeci.size(); j++) {
			
			if (izdvojene[i] == rijeci[j]) {
				int startInd = indeksi[i];
				izdvojeneKonverzija[i] = OdradiKonverziju(izdvojene[i]);
				recenica.insert(startInd, izdvojeneKonverzija[i]);
				recenica.erase(startInd + izdvojeneKonverzija[i].length(), izdvojene[i].length());
				for (int x = i; x < indeksi.size(); x++) indeksi[x] += 2;
			}
		}
	}
	}*/
	return recenica;
}
int main1() {
	 try
    {
        std::string s{"adoado ado adoadoado ado ado ado adoadoado adnan"};
        s = "";
        std::cout << "JEDNO : " << ObrniFraze (s, {}) << std::endl; //"elementarna", "je", "gdje", "prekidna"}) << std::endl;
        std::cout << "DRUGO : " << IzmijeniUPigLatin (s, {}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
    // Svaka anratnemele funkcija ej neandikerp gdej ej definisana.
	// Svaka lementarnaeay funkcija ejay neprekidna djegay ejay definisana.
	return 0;
}
int main() {
	std::cout << "Unesite recenicu: ";
	std::string recenica, fraza, RECENICA;
	std::vector<std::string> fraze;
	getline(std::cin, recenica);
	RECENICA = recenica;
	
	std::cout << "Unesite fraze: ";
	while (1) {
		getline(std::cin, fraza);
		fraze.pb(fraza);
		if (std::cin.peek() == '\n') break;
	}
	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze);
	}
	catch(std::domain_error smece) {
		std::cout << "Izuzetak: " << smece.what();
	}
	std::cout << "\nRecenica nakon obrtanja fraza: " << ObrniFraze(RECENICA, fraze);
	return 0;
}
int main2 ()
{
	std::string ulaz = "Izasla je prva zadaca iz /-+  predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta";
	std::vector<std::string> vect, vect2;
	vect.pb("zadaca"); vect.pb("Tehnike programiranja"); vect.pb("drugih predmeta"); vect.pb("meso od sira");
	std::cout << ObrniFraze(ulaz, vect) << std::endl;
	vect2.pb("zadaca"); vect2.pb("Tehnike"); vect2.pb("programiranja");
	std::cout << IzmijeniUPigLatin(ulaz, vect2);
	return 0;
}