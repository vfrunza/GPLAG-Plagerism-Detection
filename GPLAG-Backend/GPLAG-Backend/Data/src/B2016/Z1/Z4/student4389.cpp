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

bool Abeceda(char slovo){
	if((slovo>='a' && slovo<='z') || (slovo>='A' && slovo<='Z')) return true;
	else return false;
}

void ProvjeraStringa(std::vector<std::string> tekst)
{
	for(int i = 0; i<tekst.size(); i++){
		for(int j = 0; j<tekst.at(i).length(); j++){
			if(!((tekst.at(i).at(j)>='A' && tekst.at(i).at(j)<='Z') || (tekst.at(i).at(j)>='a' && tekst.at(i).at(j)<='z'))) throw std::domain_error("Nekorektan izbor riječi");
		}
	}
}

void Obrni(std::string &txt, int a, int b)
{
	char temp;
	for(int i=0; i<b/2; i++){
		temp = txt.at(i+a);
		txt.at(i+a) = txt.at(a+b-i-1);
		txt.at(a+b-i-1) = temp;
	}
}

std::string ObrniFraze(std::string tekst, std::vector<std::string> fraze)
{
	std::string txt(tekst);
	for(int i = 0; i<fraze.size(); i++){
		for(int j = 0; j<txt.length(); j++){
			if(txt.compare(j, fraze.at(i).length(), fraze.at(i)) == 0){
				Obrni(txt, j, fraze.at(i).length());
			}
		}
	}
	return txt;
}

void IzmijeniRijec(std::string &tekst, int a, int b)
{
	char temp;
	temp=tekst.at(a);
	for(int i=0; i<b-1; i++){
		tekst.at(i+a) = tekst.at(i+a+1);
		if(i==b-2) tekst.at(i+a+1) = temp;
	}
}

std::string IzmijeniUPigLatin(std::string txt, std::vector<std::string> fraze)
{
	ProvjeraStringa(fraze);
	if(fraze.size())
	{
		for(int i = 0; i<fraze.size(); i++){
			for(int j = 0; j<txt.length(); j++){
				if(txt.compare(j, fraze.at(i).length(), fraze.at(i)) == 0){
					if(Abeceda(txt.at(j-1))==false && Abeceda(txt.at(j+fraze.at(i).length()))==false)
					{
						IzmijeniRijec(txt, j, fraze.at(i).length());
						txt.insert(j+fraze.at(i).length(), "ay");
					}
				}
			}
		}
	}
	return txt;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string txt;
	std::getline(std::cin, txt);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string temp;
	do{
		std::getline(std::cin, temp);
		if(!temp.empty()) fraze.push_back(temp);
	}while(!temp.empty());
	try{
		std::string pig(IzmijeniUPigLatin(txt, fraze));
		std::cout << "Recenica nakon PigLatin transformacije: " << pig << std::endl;
	}catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what()<<std::endl;
	}
		std::string obr(ObrniFraze(txt, fraze));
		std::cout << "Recenica nakon obrtanja fraza: " << obr << std::endl;
	return 0;
}