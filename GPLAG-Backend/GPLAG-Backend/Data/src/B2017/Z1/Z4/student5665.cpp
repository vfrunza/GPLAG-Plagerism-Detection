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

typedef std::string String;

int Podstring (String s1, String s2, int start) {
	
	for (int i=start; i<s1.length(); i++) {
		int j=i;
		int k=0;
		while (j<s1.length() && k<s2.length() && s1.at(j)==s2.at(k)) {
				k++; j++;
			// Smatra se da je prekid rijeci bilo koji znak koji nije slovo, odnosno pocetak ili kraj stringa (u uslovu su granice slova po ASCII vrijednostima).
			if (k==s2.length()-1 && ((i-1<0 && ((s1.at(i+k+1)>=0 && s1.at(i+k+1)<'A') || (s1.at(i+k+1)>'Z' && s1.at(i+k+1)<'a') || s1.at(i+k+1)>'z')) || 
			(i+k+1>=s1.length() && ((s1.at(i-1)>=0 && s1.at(i-1)<'A') || (s1.at(i-1)>'Z' && s1.at(i-1)<'a') || s1.at(i+k+1)>'z')) || (s1.at(i-1)==' ' && 
			((s1.at(i+k+1)>=0 && s1.at(i+k+1)<'A') || (s1.at(i+k+1)>'Z' && s1.at(i+k+1)<'a') || s1.at(i+k+1)>'z'))))
				return i+k+1;
		}
	}
	
	return start;
}


String Obrni (String s) {
	
	String obrnut;
	
	for (int i=s.length()-1; i>=0; i--)
		obrnut.push_back(s.at(i));

	return obrnut;
}


String ObrniPola (String s) {
	
	String poluobrnut;
	
	for (int i=0; i<int(s.length()/2); i++)
		poluobrnut.push_back(s.at(i));

	poluobrnut=Obrni(poluobrnut);
	
	return poluobrnut;
}


String NapraviPalindrom (String recenica, std::vector<String> fraze) {
	
	int pozicija, prethodna;
	
	for (int i=0; i<fraze.size(); i++) {
		pozicija=0; prethodna=0;
		do {
			prethodna=pozicija;
			pozicija=Podstring(recenica, fraze.at(i), pozicija);
			
			if (pozicija>0 && prethodna!=pozicija) {
				String rijec=Obrni(fraze.at(i));
				recenica.insert(pozicija, rijec);
			}
			
		} while (prethodna!=pozicija && pozicija<recenica.length());
	}
	
	return recenica;
}


String NapraviPoluPalindrom (String recenica, std::vector<String> fraze) {
	
	int pozicija, prethodna;
	
	for (int i=0; i<fraze.size(); i++) {
		pozicija=0; prethodna=0;
		do {
			prethodna=pozicija;
			pozicija=Podstring(recenica, fraze.at(i), pozicija);
			
			if (pozicija>0 && prethodna!=pozicija) {
				String rijec=ObrniPola(fraze.at(i));
				int srednjapozicija=pozicija-(int(fraze.at(i).length()/2));
				int k(0);
				for (int j=srednjapozicija; j<pozicija && k<rijec.length(); j++, k++)
					recenica.at(j)=rijec.at(k);
			}
			
		} while (prethodna!=pozicija && pozicija<recenica.length());
	}
	
	return recenica;
	
}
int main ()
{
	String recenica;
	std::vector<String> fraze;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	
	std::cout << "Unesite fraze: ";
	
	for (;;) {
		String unos;
		std::getline(std::cin, unos);
		if (unos.length()==0) break;
		fraze.push_back(unos);
	}
	

	String palindromi=NapraviPalindrom(recenica, fraze);
	String polupalindromi=NapraviPoluPalindrom(recenica, fraze);
	
	std::cout << "Recenica nakon Palindrom transformacije: " << palindromi << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << polupalindromi << std::endl;
	
	return 0;
}