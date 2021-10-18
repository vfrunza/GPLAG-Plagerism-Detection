/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string> 
#include <sstream>
using namespace std;

void ObrniFraze (std::string pomocna_recenica, std::vector<string> pomocni_vektor){
	string temp;
	string temp2;
	for (int i = 0; i < pomocni_vektor.size(); i++){
		temp2 = temp = pomocni_vektor[i];
		if (pomocna_recenica.find(temp2) != string::npos){
			std::reverse(temp.begin(), temp.end());
			std::cout << temp << " , ";
			pomocna_recenica.replace(pomocna_recenica.find(temp2), sizeof (pomocni_vektor.size()), temp);
			temp.clear();
			temp2.clear();
		}
	}
	std::cout << pomocna_recenica << std::endl;
}

void IzmijeniUPiglatin (std::string pomocna_recenica2, std::vector<string> pomocni_vektor2){
	std::string itemp;
	std::string itemp2;
	for (int i = 0; i < pomocni_vektor2.size(); i++){
		std::vector<string> nasa_slova{"č", "ć", "đ", "š", "ž"} ;
		for(int j = 0; j < nasa_slova.size(); j++){
			std::string a = pomocni_vektor2[i];
			std::string b = nasa_slova[j];
			if (a.find(b) == string::npos)
				throw domain_error ("Nekorektan izbor rijeci");
			}
			itemp2 = itemp = pomocni_vektor2[i];
			if (pomocna_recenica2.find(itemp2) != string::npos){
				char ch = itemp.front();
				itemp.erase(0,1);
				itemp += ch;
				itemp += "ay";
				pomocna_recenica2.replace(pomocna_recenica2.find(itemp2), sizeof(pomocni_vektor2.size()), itemp);
				itemp.clear();
				itemp2.clear();

			}
		}
		std::cout << pomocna_recenica2 << std::endl;
	}




int main ()
{
	std::cout << "Unesite recenicu: " << std::endl;
	string recenica1;
	getline(std::cin, recenica1);
	string recenica2 = recenica1;
	std::vector<string> rijeci ;
	std::cout << "Unesite rijeci (zavrsi sa 0): " << std::endl;
	string n;
	while (n != "0" ){
		getline(std::cin, n);
		rijeci.push_back(n);
	}
	ObrniFraze(recenica1, rijeci);
	IzmijeniUPiglatin(recenica2, rijeci);
	return 0;
}