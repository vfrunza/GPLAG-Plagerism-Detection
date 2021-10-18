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
#include <string>
#include <vector>

std::string IzvrniString(std::string s)
{
	int duz(s.size()), i(s.size()-1);

	while(i>=0) {
		s.push_back(s[i]);
		i--;
	}

	s.erase(0,duz);

	return s;
}

std::string IzvrniStringPola(std::string s)
{
	s.erase(s.size()-1,1);
	int duz(s.size()), i(s.size()-1);
	
	while(i>=0) {
		s.push_back(s[i]);
		i--;
	}

	s.erase(0,duz);

	return s;
}

std::string Prepolovistring(std::string s)
{
	int duz(s.size()/2);

	s.erase(s.size()-duz,duz);

	return s;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> v)
{
	std::vector<std::string> v_obrnuti(v.size());         //Pravimo novi vektor koji ce sadrzavati obrnute stringove;
	for(int i=0; i<v_obrnuti.size(); i++) {
		v_obrnuti.at(i)=IzvrniString(v.at(i));
	}

	std::string pom(s);
	for(int i=0; i<v.size(); i++) {                 //Provjeravamo da li se rijeci iz vektora nalaze u stringu i ako se nalaze ubacijemo onu iz v_obrnuti
		std::string rijec(v.at(i));
		for(int j=0; j<pom.size(); j++) {
			while(pom.at(j)==' ') j++;
			int k(0);
			while(k<rijec.size() && j<pom.size() && pom.at(j)==rijec.at(k)) {
				j++;
				k++;
			}
			if(k==rijec.size() && (pom.at(j)==' ' || pom.at(j)=='.' || pom.at(j)==',' || j==pom.size())) {
				pom.insert(j,v_obrnuti.at(i));
				j+=v_obrnuti.at(i).size()-1;
			}
		}
	}

	return pom;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v)
{
	std::vector<std::string> v_pola_obrni(v.size());         //Pravimo novi vektor koji ce sadrzavati obrnute prepolovljene stringove;
	for(int i=0; i<v_pola_obrni.size(); i++) {
		if(v.at(i).size()%2==0) {
			v_pola_obrni.at(i)=Prepolovistring(v.at(i));
			v_pola_obrni.at(i)=IzvrniString(v_pola_obrni.at(i));
		} else {
			v_pola_obrni.at(i)=Prepolovistring(v.at(i));
			v_pola_obrni.at(i)=IzvrniStringPola(v_pola_obrni.at(i));
		}
	}
	
	
	std::string pom(s);
	for(int i=0; i<v.size(); i++) {
		std::string rijec(v.at(i));
		for(int j=0; j<pom.size(); j++) {
			while(pom.at(j)==' ') j++;
			int k(0);
			while(k<rijec.size() && j<pom.size() && pom.at(j)==rijec.at(k)) {
				j++;
				k++;
			}
			if(k==rijec.size() && (pom.at(j)==' ' || pom.at(j)=='.' || pom.at(j)==',' || j==pom.size())) {
				pom.erase(j-v.at(i).size()/2,v.at(i).size()/2);
				pom.insert(,v_pola_obrni.at(i));
				j+=v.at(i).size()-1;
			}
		}
	}

	return pom;
}

int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);

	std::vector<std::string> v;
	std::string pom;
	std::cout << "Unesite fraze: ";
	while(true) {
		std::getline(std::cin,pom);
		if(pom.size()==0) break;
		else v.push_back(pom);
	}

	
	try {
		std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s,v) << std::endl;
		std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s,v) << std::endl;
	} catch(...) {
		std::cout << "izuzetak" << std::endl;
	}

	return 0;
}


