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
bool DaLiJeSlovo(char a){
	//funkcija radi isto kao i funkcija isalpha, jer ne znam da li smijem isalpha koristiti
	if((a>=65 && a<=90)||(a>=97 && a<=122)) return true;
	return false;
}
std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze){
	std::string povratni(recenica);
	for(int k=0;k<fraze.size();k++){
		for(int i=0;i<povratni.length();i++){
		
				if(povratni.length()-i>=fraze.at(k).length() && povratni.at(i)==fraze.at(k).at(0) && povratni.substr(i, fraze.at(k).length())==fraze.at(k) && (i==0 || !DaLiJeSlovo(povratni.at(i-1))) && (i+fraze.at(k).length()==povratni.length() || !DaLiJeSlovo(povratni.at(i+fraze.at(k).length())))){
				for(int j=0;j<fraze.at(k).length();j++){
					povratni.insert(povratni.begin() + i + fraze.at(k).length(), fraze.at(k).at(j));
					
				}
				i=i+fraze.at(k).length()*2-1;
			}
		}
	}
	return povratni;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze){
	std::string povratni(recenica);
	for(int k=0;k<fraze.size();k++){
		for(int i=0;i<povratni.length();i++){
		
				if(povratni.length()-i>=fraze.at(k).length() && povratni.at(i)==fraze.at(k).at(0) && povratni.substr(i, fraze.at(k).length())==fraze.at(k) && (i==0 || !DaLiJeSlovo(povratni.at(i-1))) && (i+fraze.at(k).length()==povratni.length() || !DaLiJeSlovo(povratni.at(i+fraze.at(k).length())))){
				int dokleUbacivati(fraze.at(k).length()/2);
				if(fraze.at(k).length()%2!=0) dokleUbacivati++;
				for(int j=0;j<fraze.at(k).length()/2;j++) povratni.erase(povratni.begin() + i + dokleUbacivati);
				for(int l=0;l<fraze.at(k).length()/2;l++) povratni.insert(povratni.begin() + i + dokleUbacivati, fraze.at(k).at(l));
				i=i+fraze.at(k).length()-1;
			}
		}
	}
	return povratni;
}
int main ()
{
	/*
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;

	while(1){
		std::string unos;
		std::getline(std::cin, unos);
		if(unos.length()!=0) fraze.push_back(unos);
		if(unos.length()==0)break;
	}	
	

	

	std::cout<<"Recenica nakon Palindrom transformacije: ";

	
	std::string novi(NapraviPalindrom(recenica, fraze));
	std::string drugaFunkcija(NapraviPoluPalindrom(recenica, fraze));
	std::cout<<novi<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<drugaFunkcija;
*/

   //AT15 (neaktivni) - prazni stringovi
    try
    {
        std::string s{"'   Svaka     elementarna    funkcija    je    neprekidna   gdje  je   definisana   '"};
        std::cout <<  NapraviPalindrom (s, {"je"}) << std::endl;
        std::cout <<  NapraviPalindrom (s, {"je     ", "", "   Svaka"}) << std::endl;
        std::cout <<  NapraviPoluPalindrom (s, {"je"}) << std::endl;
        std::cout <<  NapraviPoluPalindrom (s, {"je     ", "", "   Svaka"});
    }
    catch(std::exception e)
    {
        std::cout << "Izuzetak: " << e.what();
    }

	return 0;
}

// ja sam armin
// 012345678901