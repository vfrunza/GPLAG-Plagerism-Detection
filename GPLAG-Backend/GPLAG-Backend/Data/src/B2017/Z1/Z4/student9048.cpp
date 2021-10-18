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
typedef std::vector<std::string> Vektor;
typedef std::string String;

int KolikoRijeci(String s)
{
	bool razmak(true);
	int brojac(0);
	for(int i(0); i < s.size(); i++) {
		if(s.at(i) == ' ') razmak = true;
		else if(razmak == true) {
			brojac++;
			razmak = false;
		}
	}
	return brojac;
}

String OkreniString(String s1)
{
	String vrati(s1);
	char temp(0);
	for(int i(0); i < vrati.size()/2; i++) {
		temp = vrati.at(i);
		vrati.at(i) = vrati.at(vrati.length()-1-i);
		vrati.at(vrati.length()-1-i) = temp;
	}
	return vrati;
}

Vektor Odvoji(String s)
{
	Vektor upisi;
	String temp;
	for(int i(0); i < s.size(); i++) {
		if( s.at(i) != ' ') temp+=s.at(i);
		if(s.at(i) == ' ' || i == s.size()-1) {
			upisi.push_back(temp);
			temp.clear();
		}
	}
	return upisi;
}

void Ubaci(String s1, String s2)
{
	for(int i(0); i < s2.size(); i++) {
		s1.push_back(s2.at(i));
	}
}

String NapraviPalindrom(String s, Vektor v)
{
	String poredi;
	Vektor odvojene;
	String za_ubacit;
	int poz(0);
	for(int i(0); i < v.size(); i++) {
		if(KolikoRijeci(v.at(i)) > 1) {
			odvojene = Odvoji(v.at(i));
			for(int j(0); j < odvojene.size(); j++) {
				for(int k(0); k < s.size(); k++) {
					if(s.at(k) != ' ') poredi+=s.at(k);
					if(s.at(k) == ' ' || k == s.size()-1) {
						if(poredi == odvojene.at(j)) {
							Ubaci(za_ubacit, poredi);
							if(j != odvojene.size()-1) za_ubacit+= ' ';
							poredi.clear();
							poz = k;
							break;
						}
					}
					if(za_ubacit == v.at(i)) {
						std::cout << " " << za_ubacit;
						String okrenuti;
						okrenuti = OkreniString(za_ubacit);
						s.insert(k, okrenuti);
						break;
					}
					//if(poredi == odvojene.at(j)) break;
				}
			}
			//za_ubacit.clear();
		} else {
			String poredi;
			for(int k(0); k < s.size(); k++) {
				if(s.at(k) != ' ') poredi+=s.at(k);
				if(s.at(k) == ' ' || k == s.length()-1) {
					for(int j(0); j < v.size(); j++) {
						if(poredi == v.at(j)) {
							String ubaci;
							if(k == s.length()-1) s.resize(s.length()+1);
							ubaci= OkreniString(v.at(j));
							s.insert(k, ubaci);
							break;
						}
					}
					poredi.clear();
				}
			}
		}
	}
	String vrati;
	vrati = s;
	return vrati;
}

/* OVA ZA SVAKI SLUCAJ
String NapraviPalindrom(String s, Vektor v)
{
	String poredi;
	for(int i(0); i < s.size(); i++){
		if(s.at(i) != ' ') poredi+=s.at(i);
		if(s.at(i) == ' ' || i == s.length()-1){
			for(int j(0); j < v.size(); j++){
				if(poredi == v.at(j)){
					String ubaci;
					if(i == s.length()-1) s.resize(s.length()+1);
					ubaci= OkreniString(v.at(j));
					s.insert(i, ubaci);
					break;
				}
			}
			poredi.clear();
		}
	}
	String vrati;
	vrati = s;
	return vrati;
}
*/
int main ()
{

	String recenica, fraza;
	Vektor v1;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	for( ;;) {
		std::getline(std::cin, fraza);
		if(!fraza.empty()) v1.push_back(fraza);
		if(std::cin.peek() == '\n') break;
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, v1);
	std::cout << std::endl << "Recenica nakon PoluPalindrom transformacije: ";

	return 0;
}