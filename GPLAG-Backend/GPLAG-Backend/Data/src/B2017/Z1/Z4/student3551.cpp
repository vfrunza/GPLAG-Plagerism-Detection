/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/


/*

	recenica:               danas je lijep i suncan dan
	fraze:                  danas
						    lijep
						    dan
						    
	NapraviPalindrom:       danassanad je lijeppejil i suncan dannad
	string promjene:        xxxxxxxxxx    xxxxxxxxxx          xxxxxx
	
	NapraviPoluPalindrom:   danad je lijil i suncan dad
	string promjene:        xxxxx    xxxxx          xxx
	
	string promjene govori gdje ne smijem vrsiti transformaciju u stringu (tamo gdje je 'x')
	jer je tu neka prethodna fraza pravila transformaciju
	
	ako se u nekom dijelu stringa nije vrsila transformacija pisati ce ' '
	u stringu promjene
*/

#include <iostream>
#include <vector>
#include <string>
std::string NaopakString(std::string s){
	std::string nova_rijec;
	for(int i=s.length()-1; i>=0; i--)
		nova_rijec.push_back(s.at(i));
	return nova_rijec;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string> vek){
	std::string promjene(s.length(), ' ');
	
	for(auto x: vek){
		
		int duzina_recenice (s.length());
		int duzina_fraze(x.length());
		std::string fraza_naopako(NaopakString(x));
		
		for(int i=0; i<=duzina_recenice-duzina_fraze; i++){
			
			if(s.substr(i, duzina_fraze) == x && promjene.at(i)!='x' ) { //ako je dio stringa jednak frazi i ako se taj dio stringa nije modifikovao
				for(int j=0; j<fraza_naopako.length(); j++){ 
					s.insert(s.begin()+i+duzina_fraze+j, fraza_naopako.at(j));
					promjene.insert(promjene.begin()+i+duzina_fraze+j, 'x');
				}
				for(int j=0; j<fraza_naopako.length(); j++)
					promjene.at(i+j) = 'x';
				i=0;
				duzina_recenice = s.length();
				duzina_fraze = x.length();
			}
			}
	}   			
	//std::cout << std::endl << s << std::endl << promjene;
	return s;
}

std::string NaopakPoluString(std::string s){
	std::string nova_rijec;
	int pocetak;
	if(s.length()%2==0) pocetak = s.length()/2;
	else pocetak = s.length()/2+1;
	for (int i=0; i<s.length()-pocetak; i++)
		nova_rijec.push_back(s.at(i));
	for(int i=pocetak-1; i>=0; i--)
		nova_rijec.push_back(s.at(i));
	return nova_rijec;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> vek){
	std::string promjene(s.length(), ' ');
	for(auto x: vek){
		int duzina_recenice (s.length());
		int duzina_fraze(x.length());
		
		std::string fraza_naopako(NaopakPoluString(x));
		
		for(int i=0; i<=duzina_recenice-duzina_fraze; i++)
			if(s.substr(i, duzina_fraze) == x && promjene.at(i)!='x') {
				for(int j=0; j<duzina_fraze; j++){
					s.at(i+j) =  fraza_naopako.at(j);
					promjene.at(i+j) = 'x';
				}
			}
	}
	
	return s;
}



int main ()
{
	std::string recenica,f;
	std::vector<std::string>fraze;
	
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	
	
	std::getline(std::cin, f);
	while(f != "") {
		fraze.push_back(f);
		std::getline(std::cin, f);
		
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";	
	std::string k;
	k= NapraviPalindrom(recenica, fraze);
	std::cout << k;
	
	std::cout << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	k = NapraviPoluPalindrom(recenica,fraze);
	std::cout << k;
	
	return 0;
}