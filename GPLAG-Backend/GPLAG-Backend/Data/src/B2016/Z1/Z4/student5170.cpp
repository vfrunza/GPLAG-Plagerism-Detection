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
typedef std::vector<std::string> vektor;

std::string ObrniFraze (std::string recenica, vektor fraze)
{
	char pomocni;
	int b(0), k(0);
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length()-fraze[i].length()+1; j++) {
			if (fraze[i][0]==recenica[j]) {
				for (k=0; k<fraze[i].length(); k++)
					if (fraze[i][k]!=recenica[j+k]) break;
				if (k==fraze[i].length()) {
					b=0;
					for (int l=j; l<j+k/2; l++) {
						pomocni=recenica[l];
						recenica[l]=recenica[j+k-b-1];
						recenica[j+k-b-1]=pomocni;
						b++;
					}
					j=j+k;
				}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, vektor fraze)
{
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<fraze[i].length(); j++) {
			if (fraze[i][j]<'A' || (fraze[i][j]>'Z' && fraze[i][j]<'a') || fraze[i][j]>'z') throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
		}
	}
	int b(0),k(0),l;
	char pomocni;
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length()-fraze[i].length()+1; j++) {
			if (fraze[i][0]==recenica[j]) {
				for (k=0; k<fraze[i].length(); k++)
					if (fraze[i][k]!=recenica[j+k]) break;
				if (k==fraze[i].length() && recenica[j+k]==' ' && (recenica[j-1]==' ' || j==0)) {
					b=0;
					for (l=j; l<j+k-1; l++) {
						pomocni=recenica[l];
						recenica[l]=recenica[l+1];
						recenica[l+1]=pomocni;
						b++;
					}
					recenica.insert(recenica.begin()+l+1, 'y');
					recenica.insert(recenica.begin()+l+1, 'a');
					j=j+k;
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica, fraze;
	std::getline(std::cin, recenica);
	vektor vek;
	int n(0);
	std::cout << "Unesite fraze: ";
	do {
		std::getline(std::cin, fraze);
		if (fraze.size()==0) break;
		n++;
		vek.resize(n);
		vek[n-1]=fraze;
	} while (fraze[0]!='\n');
	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, vek) << std::endl;
	} catch (std::domain_error tekst) {
		std::cout << tekst.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, vek) << std::endl;
	return 0;
}