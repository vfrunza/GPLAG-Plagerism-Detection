/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string>

bool jel_slovo(char s)
{
	return ('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z');
}


int NadjiPodstring (std::string Recenica, std::string Rijec, int Odakle) {
	
	int Pocetak = -1;
	
	for (int i = Odakle; i < Recenica.size(); i++) {
		
		if (Rijec.at(0) == Recenica.at(i)) {
    	  	Pocetak = i;
    		i++;
    		for (int j = 1; j < Rijec.size() && i < Recenica.size(); j++) {
	    		if (Rijec.at(j) != Recenica.at(i)) break;
    			i++;
    		}
     		if (i - Pocetak == Rijec.size()) return Pocetak;
	    	Pocetak = -1;
    	}
    }
    return Pocetak;
}


std::string NapraviPoluPalindrom (std::string Recenica, std::vector<std::string> NizRijeci) {
	
	if (NizRijeci.size() == 0) return Recenica;
	int naso = 0;
	for (int i = 0; i < NizRijeci.size(); i++) {
		auto Rijec = NizRijeci.at(i);
		
		naso = NadjiPodstring(Recenica, Rijec, naso);
		if (naso != -1) {
			if (naso == 0 && !jel_slovo(Recenica.at(naso + Rijec.size())) ) {
				int poc = naso;
				int pisi = naso + Rijec.size() - 1;
				
				for (; pisi > poc; --pisi, ++poc) {
					Recenica.at(pisi) = Recenica.at(poc);
				}
			}
			
			else if (naso + Rijec.size() == Recenica.size() && !jel_slovo(Recenica.at(naso - 1))) {
				int poc = naso;
				int pisi = naso + Rijec.size() - 1;
				
				for (; pisi > poc; --pisi, ++poc) {
					Recenica.at(pisi) = Recenica.at(poc);
				}
			}
			
			else if (naso != 0 && naso + Rijec.size() != Recenica.size() && !jel_slovo(Recenica.at(naso - 1)) && !jel_slovo(Recenica.at(naso + Rijec.size()))) {
				int poc = naso;
				int pisi = naso + Rijec.size() - 1;
				
				for (; pisi > poc; --pisi, ++poc) {
					Recenica.at(pisi) = Recenica.at(poc);
				}
			}
			else {
				naso += Rijec.size();
			}
			--i;
		}
		else naso = 0;
	}
	return Recenica;
}


 std::string IzvrniString (std::string Naopaka) {
    
    int i(0);
    int j(Naopaka.size()-1);
    
     while(i<j) {
         
        char Pomocna = Naopaka.at(i);
        Naopaka.at(i) = Naopaka.at(j);
        Naopaka.at(j) = Pomocna;
        
        j--;
        i++;
    }
  	return Naopaka;
} 

std::string NapraviPalindrom (std::string Recenica, std::vector<std::string> NizRijeci) {
	
	if (NizRijeci.size() == 0) return Recenica;
	int naso = 0;
	for (int i = 0; i < NizRijeci.size(); i++) {
		auto Rijec = NizRijeci.at(i);
		naso = NadjiPodstring(Recenica, Rijec, naso);
		if (naso != -1) {
			if (naso == 0 && !jel_slovo(Recenica.at(naso + Rijec.size())) ) {
				
				auto nopaka_rijec = IzvrniString(Rijec);
				
				auto str = std::string(Recenica.begin(), Recenica.begin() + naso + Rijec.size()) + 
							nopaka_rijec + std::string(Recenica.begin() + naso + Rijec.size(), Recenica.end());
				
				Recenica = std::move(str);
				naso += Rijec.size() - 1;
			}
			
			else if (naso + Rijec.size() == Recenica.size() && !jel_slovo(Recenica.at(naso - 1)))  {
				auto nopaka_rijec = IzvrniString(Rijec);
				
				auto str = std::string(Recenica.begin(), Recenica.begin() + naso + Rijec.size()) + 
							nopaka_rijec + std::string(Recenica.begin() + naso + Rijec.size(), Recenica.end());
				
				Recenica = std::move(str);
				naso += Rijec.size() - 1;
			}
			
			else if (naso != 0 && naso + Rijec.size() != Recenica.size() && !jel_slovo(Recenica.at(naso - 1)) && !jel_slovo(Recenica.at(naso + Rijec.size()))) {
				auto nopaka_rijec = IzvrniString(Rijec);
				
				auto str = std::string(Recenica.begin(), Recenica.begin() + naso + Rijec.size()) + 
							nopaka_rijec + std::string(Recenica.begin() + naso + Rijec.size(), Recenica.end());
				
				Recenica = std::move(str);
				naso += Rijec.size() - 1;
			}
			else {
				naso += Rijec.size();
			}
			--i;
		}
		else naso = 0;
	}
	return Recenica;
}

int main ()
{
	
	std::string Sentence;
	std::vector<std::string> Fraze;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, Sentence);
	std::cout << "Unesite fraze: ";
	
	while(true) {
		std::string Input;
		std::getline(std::cin, Input);
		
		if(Input.size() == 0)
			break;
			
		Fraze.push_back(Input);
	}
	
 	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(Sentence,Fraze) << "\n";
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(Sentence,Fraze);
	return 0;
}