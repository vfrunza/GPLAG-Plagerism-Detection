/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::vector;
using std::string;

string IzmijeniUPigLatin (string recenica, vector<string> fraze) {
	if (fraze.size()==0) {
		for (int i=0; i<recenica.length(); i++) {
			if (i==0 || !((recenica[i-1]>='A' && recenica[i-1]<='Z') || (recenica[i-1]>='a' && recenica[i-1]<='z'))) {
				int br(0);
				while (i<recenica.length() && ((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) {
					br++;
					i++;
				}
				if (br!=0) {
					char c(recenica[i-br]);
					for (int j=i-br; j<i-1; j++)
						recenica[j]=recenica[j+1];
					recenica[i-1]=c;
					recenica.resize(recenica.length()+2);
					for (int j=recenica.length()-1; j>=i+2; j--)
						recenica[j]=recenica[j-2];
					recenica[i]='a';
					recenica[i+1]='y';
				}
			}
		}
		return recenica;
	}
	
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<fraze[i].length(); j++)
			if (!((fraze[i][j]>='A' && fraze[i][j]<='Z') || (fraze[i][j]>='a' && fraze[i][j]<='z'))) throw std::domain_error("Nekorektan izbor rijeci");
	}
	
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			if (j==0 || !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z'))) {
				int pom(0);
				for (int k=0; k<fraze[i].length(); k++) {
					if (j>=recenica.length() || fraze[i][k]!=recenica[j])
						break;
					j++;
					pom=k;
				}
				if (pom==(fraze[i].length()-1) && (!((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z')) || j==recenica.length())) {
					char c(recenica[j-fraze[i].length()]);
					for (int k=j-fraze[i].length(); k<j-1; k++)
						recenica[k]=recenica[k+1];
					recenica[j-1]=c;
					recenica.resize(recenica.length()+2);
					for (int k=recenica.length()-1; k>=j+2; k--)
						recenica[k]=recenica[k-2];
					recenica[j]='a';
					recenica[j+1]='y';
				}
			}
		}
	}
	return recenica;
}

string ObrniFraze (string recenica, vector<string> fraze) {
	for (int i=0; i<fraze.size(); i++) {
		for (int j=0; j<recenica.length(); j++) {
			int pom(0);
			for (int k=0; k<fraze[i].length(); k++) {
				pom=k;
				if (j>=recenica.length() || fraze[i][k]!=recenica[j])
					break;
				j++;
			}
			if (pom==(fraze[i].length()-1)) {
				char c;
				for (int k=j-fraze[i].length(); k<(j-fraze[i].length())+fraze[i].length()/2; k++) {
					for (int l=0; l<fraze[i].length()/2; l++) {
						c=recenica[k];
						recenica[k]=recenica[j-l-1];
						recenica[j-l-1]=c;
						k++;
					}
				}
			}
			if (pom!=0)
				j--;
		}
	}
	return recenica;
}

int main ()
{
	string recenica, pomocni;
	vector<string> fraze;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	for (;;) {
		std::getline(std::cin, pomocni);
		if (pomocni.size()==0)
			break;
		fraze.push_back(pomocni);
	}
	try {
	std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze) << std::endl;
	}
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
	return 0;
}