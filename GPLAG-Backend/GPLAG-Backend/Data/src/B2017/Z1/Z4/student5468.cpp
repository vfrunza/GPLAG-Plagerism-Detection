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

typedef std::string String;
typedef std::vector<String> Vektor;

String Preokreni(String s){
	String p;
	for(int i=s.size()-1; i>=0; i--)
	p.push_back(s.at(i));
	return p;
}

String PoluPreokreni(String s){
	String p;
	for(int i=s.size()/2-1; i>=0; i--)
	p.push_back(s.at(i));
	return p;
}

bool Provjera(String s1, String s2, int pozicija){
	int i;
	for(i=0; i<s2.size(); i++){
	if(s1.at(i+pozicija)!=s2.at(i)) return false;
	if(i+pozicija==s1.size()-1 && i!=s2.size()-1) return false; 
	}
	if(i+pozicija==s1.size() || s1.at(i+pozicija)<'A' || s1.at(i+pozicija)>'z') return true;
	return false;
}

String NapraviPalindrom(String recenica, Vektor rijeci){
	for(int i=0; i<rijeci.size(); i++){
		String naopak=Preokreni(rijeci.at(i));
		for(int j=0; j<recenica.size(); j++){
			if(recenica.at(j)==naopak.at(naopak.size()-1) && (j==0 || recenica.at(j-1)<'A' || recenica.at(j-1)>'z')){
				if(Provjera(recenica, rijeci.at(i), j)){
					j=j+naopak.size();
					if(j==recenica.size()){
					for(int h=0; h<naopak.size(); h++)	
					recenica.push_back(naopak.at(h));
					break;
					}
					recenica=recenica.substr(0, j)+naopak+recenica.substr(j, recenica.size());
					j=j+naopak.size();
				}
					
			}
		}
			
	}
	return recenica;
}
	
String NapraviPoluPalindrom(String recenica, Vektor rijeci){
	for(int i=0; i<rijeci.size(); i++){
		String naopak=PoluPreokreni(rijeci.at(i));
		for(int j=0; j<recenica.size(); j++){
			if(naopak.size()==0) break;
			if(recenica.at(j)==naopak.at(naopak.size()-1) && (j==0 || recenica.at(j-1)<'A' || recenica.at(j-1)>'z')){
				if(Provjera(recenica, rijeci.at(i), j)){
					if(rijeci.at(i).size()%2==0) j=j+naopak.size();
					else j=j+naopak.size()+1;
					recenica=recenica.substr(0, j)+naopak+recenica.substr(j+naopak.size(), recenica.size());
					j=j+naopak.size();
				}
					
			}
		}
			
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	String recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	Vektor v;
	String fraza;
	do{
	  std::getline(std::cin, fraza);
	  if(fraza.size()!=0) v.push_back(fraza);
	}while(fraza.size()!=0);
	String p1(NapraviPalindrom(recenica, v)), p2(NapraviPoluPalindrom(recenica, v));
	std::cout << "Recenica nakon Palindrom transformacije: " << p1 << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << p2;
	
	return 0;
}

